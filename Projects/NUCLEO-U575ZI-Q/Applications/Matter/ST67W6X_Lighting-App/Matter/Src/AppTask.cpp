/*
 *
 *    Copyright (c) 2022 Project CHIP Authors
 *    All rights reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#include "AppTask.h"
#include "IdentifierEffect.h"
#include "main.h"
#include <app/clusters/network-commissioning/network-commissioning.h>
#include <app/server/Dnssd.h>
#include <app/server/Server.h>

#include "FreeRTOS.h"
#include "task.h"
#include "portable.h"
#include <credentials/DeviceAttestationCredsProvider.h>

#include <setup_payload/OnboardingCodesUtil.h>
#include <setup_payload/QRCodeSetupPayloadGenerator.h>
#include <setup_payload/SetupPayload.h>
#include <app/clusters/network-commissioning/network-commissioning.h>
#include <data-model-providers/codegen/Instance.h>

#include <app/TestEventTriggerDelegate.h>
#include <app/clusters/software-diagnostics-server/SoftwareDiagnosticsTestEventTriggerHandler.h>
#if (CHIP_DEVICE_CONFIG_ENABLE_WIFI == 1)
#include <app/clusters/wifi-network-diagnostics-server/WiFiDiagnosticsTestEventTriggerHandler.h>
#endif /* (CHIP_DEVICE_CONFIG_ENABLE_WIFI == 1) */

#include "DeviceInfoProviderImpl.h"
#include "FactoryDataProvider.h"
#include "STM32FreeRtosHooks.h"
#include "NetworkCommissioningWiFiDriver.h"

#include <lib/dnssd/MinimalMdnsServer.h>

#include "app_nvm.h"
#include "w6x_api.h"
#include "lwip.h"

#define TIMER_DEFAULT_TIMEOUT         (1000)     // in ms: timer default timeout

#define APPTASK_THREAD_NAME           "AppTask"
#define APPTASK_THREAD_STACK_DEPTH    (1024*6)
#define APPTASK_THREAD_PRIORITY       (24)
#define APPTASK_EVENT_QUEUE_SIZE      (10)

TimerHandle_t sUserButtonTimeoutTimer;
TaskHandle_t sAppTaskHandle;
static QueueHandle_t sAppTaskEventQueue;

AppTask AppTask::sAppTask;

static uint8_t UserButtonStateCpt = 0;

using namespace ::chip;
using namespace ::chip::DeviceLayer;
using namespace ::chip::Platform;

chip::DeviceLayer::DeviceInfoProviderImpl gExampleDeviceInfoProvider;
chip::DeviceLayer::FactoryDataProvider mFactoryDataProvider;
app::Clusters::NetworkCommissioning::Instance sWiFiNetworkCommissioningInstance(
		0 /* Endpoint Id */,
		&(NetworkCommissioning::Stm32WiFiDriver::GetInstance()));

CHIP_ERROR AppTask::Init(AppDelegate *sAppDelegate) {
	CHIP_ERROR err = CHIP_NO_ERROR;

	// Create FreeRTOS resources
	// Create Timer for Push button timeouts.
	sUserButtonTimeoutTimer = xTimerCreate("UserButtonTimer", // Just a text name, not used by the RTOS kernel
			pdMS_TO_TICKS(TIMER_DEFAULT_TIMEOUT), // == default timer period (mS)
			false, // no timer reload (==one-shot)
			(void*) this, // init timer id
			TimerUserButtonEventHandler); // timer callback handler

	ButtonSetCallback(ButtonEventHandler);

	sAppTaskEventQueue = xQueueCreate(APPTASK_EVENT_QUEUE_SIZE,
			sizeof(AppEvent));
	// Check resources creation
	if ((sUserButtonTimeoutTimer == NULL)
			|| (sAppTaskEventQueue == NULL)) {
		err = CHIP_ERROR_NO_MEMORY;
	}

    if (err == CHIP_NO_ERROR) {
        err = IdentifierEffect_Init();
    }

	if (err == CHIP_NO_ERROR) {
		// Continue with Matter initialization
		ReturnErrorOnFailure(Platform::MemoryInit());

		// Initialize the CHIP stack.
		ReturnErrorOnFailure(PlatformMgr().InitChipStack());

		// Register a function to receive events from the CHIP device layer.  Note that calls to
		// this function will happen on the CHIP event loop thread, not AppTask thread
		PlatformMgr().AddEventHandler(MatterEventHandler, 0);

		err = LightingMgr().Init();
		if (err != CHIP_NO_ERROR) {
			return err;
		}

		// Initialization ZCL Data Model and CHIP AppServer
	    static chip::CommonCaseDeviceServerInitParams initParams;
	    (void) initParams.InitializeStaticResourcesBeforeServerInit();
	    initParams.dataModelProvider = chip::app::CodegenDataModelProviderInstance(initParams.persistentStorageDelegate);
	    ReturnErrorOnFailure(mFactoryDataProvider.Init());
	    SetDeviceInstanceInfoProvider(&mFactoryDataProvider);
	    SetCommissionableDataProvider(&mFactoryDataProvider);
	    SetDeviceAttestationCredentialsProvider(&mFactoryDataProvider);

        // Manage TestEventTrigger
        static SimpleTestEventTriggerDelegate sTestEventTriggerDelegate{};
        static uint8_t sTestEventTriggerEnableKey[TestEventTriggerDelegate::kEnableKeyLength] = { 0 };
        // Read EnableKey from the factory data.
        MutableByteSpan enableKey(sTestEventTriggerEnableKey);
        err = mFactoryDataProvider.GetEnableKey(enableKey);
        if (err != CHIP_NO_ERROR)
        {
            ChipLogError(DeviceLayer, "mFactoryDataProvider.GetEnableKey() failed!");
            memset(sTestEventTriggerEnableKey, 0, sizeof(sTestEventTriggerEnableKey));
        }
        VerifyOrDie(sTestEventTriggerDelegate.Init(ByteSpan(sTestEventTriggerEnableKey)) == CHIP_NO_ERROR);
        static SoftwareDiagnosticsTestEventTriggerHandler sSoftwareDiagnosticsTestEventTriggerHandler;
        sTestEventTriggerDelegate.AddHandler(&sSoftwareDiagnosticsTestEventTriggerHandler);
#if (CHIP_DEVICE_CONFIG_ENABLE_WIFI == 1)
        static WiFiDiagnosticsTestEventTriggerHandler sWiFiDiagnosticsTestEventTriggerHandler;
        sTestEventTriggerDelegate.AddHandler(&sWiFiDiagnosticsTestEventTriggerHandler);
#endif /* (CHIP_DEVICE_CONFIG_ENABLE_WIFI == 1) */
        initParams.testEventTriggerDelegate = &sTestEventTriggerDelegate;

	    if (sAppDelegate != nullptr) {
			initParams.appDelegate = sAppDelegate;
		}
		chip::DeviceLayer::SetDeviceInfoProvider(&gExampleDeviceInfoProvider);
		chip::Server::GetInstance().Init(initParams);

		gExampleDeviceInfoProvider.SetStorageDelegate(
				&Server::GetInstance().GetPersistentStorage());
		
		chip::DeviceLayer::ConfigurationMgr().LogDeviceConfig();

		sWiFiNetworkCommissioningInstance.Init();

		// Open commissioning after boot if no fabric was available
		if (chip::Server::GetInstance().GetFabricTable().FabricCount() == 0) {
			ConnectivityMgr().SetBLEAdvertisingEnabled(true);
			PrintOnboardingCodes(
					chip::RendezvousInformationFlags(
							chip::RendezvousInformationFlag::kBLE));
			// Enable BLE advertisements
			chip::Server::GetInstance().GetCommissioningWindowManager().OpenBasicCommissioningWindow();

		}
		// Start a task to run the CHIP Device event loop.
		err = PlatformMgr().StartEventLoopTask();
		if (err != CHIP_NO_ERROR) {
			err = CHIP_ERROR_NO_MEMORY;
		}
	}

	return err;
}

CHIP_ERROR AppTask::Start(void) {
	CHIP_ERROR err = CHIP_NO_ERROR;
	;

	// Create AppTask.
	xTaskCreate(AppTaskMain, APPTASK_THREAD_NAME, APPTASK_THREAD_STACK_DEPTH,
	NULL, APPTASK_THREAD_PRIORITY, &sAppTaskHandle);
	if (sAppTaskHandle == NULL) {
		err = CHIP_ERROR_NO_MEMORY;
	}

	return err;
}

void AppTask::AppTaskMain(void *pvParameter) {
	AppEvent event;
	BaseType_t eventReceived;

	CHIP_ERROR err = sAppTask.Init();

	if (err != CHIP_NO_ERROR) {
		ChipLogError(NotSpecified, "Matter init failed");
		Error_Handler();
	}
	while (true) {
		eventReceived = xQueueReceive(sAppTaskEventQueue, &event,
		portMAX_DELAY);
		while (eventReceived == pdTRUE) {
			sAppTask.DispatchEvent(&event);
			eventReceived = xQueueReceive(sAppTaskEventQueue, &event, 0);
		}
	}
}

void AppTask::PostEvent(const AppEvent *aEvent) {
	if (sAppTaskEventQueue != NULL) {
		if (!xQueueSend(sAppTaskEventQueue, aEvent, 1)) {
			ChipLogError(NotSpecified,
					"Failed to post event to AppTask event queue");
		}
	} else {
		ChipLogError(NotSpecified, "Event Queue is NULL should never happen");
	}
}

void AppTask::DispatchEvent(AppEvent *aEvent) {
	if (aEvent->Handler) {
		aEvent->Handler(aEvent);
	} else {
		ChipLogError(NotSpecified,
				"Event received with no handler. Dropping event.");
	}
}

void AppTask::TimerUserButtonEventHandler(TimerHandle_t xTimer) {
	// else xTimerStop ?
	if (UserButtonStateCpt >= 2) {
		AppEvent event;
		event.Type = AppEvent::kEventType_Timer;
		event.Handler = UpdateEventHandler;
		sAppTask.mFunction = kFunction_FactoryReset;
		sAppTask.PostEvent(&event);
	} else {
		AppEvent event;
		event.Type = AppEvent::kEventType_Timer;
		event.Handler = UpdateEventHandler;
		sAppTask.mFunction = kFunction_SaveNvm;
		sAppTask.PostEvent(&event);
	}
	UserButtonStateCpt = 0;
}

void AppTask::ButtonHandler(AppEvent *aEvent) {
	if (aEvent->Type == AppEvent::kEventType_Button) {
		if (xTimerIsTimerActive(sUserButtonTimeoutTimer) == 0) {
			xTimerStart(sUserButtonTimeoutTimer, 0);
			UserButtonStateCpt = 1;
		} else {
			UserButtonStateCpt++;
		}
	}
}

void AppTask::ButtonEventHandler(ButtonState_t *Button) {
	AppEvent button_event = { };
	button_event.Type = AppEvent::kEventType_Button;
	button_event.ButtonEvent.ButtonIdx = Button->Button;
	button_event.ButtonEvent.Action = Button->State;
	button_event.Handler = ButtonHandler;
	sAppTask.PostEvent(&button_event);
}

void AppTask::UpdateEventHandler(AppEvent *aEvent) {
	if (sAppTask.mFunction == kFunction_SaveNvm) {
		NVM_StatusTypeDef nvmStatus;
		nvmStatus = NVM_Dump();
		ChipLogProgress(DeviceLayer, "NVM %s",
				(nvmStatus == NVM_OK) ? "saved" : "NOT saved !!!");
	} else if (sAppTask.mFunction == kFunction_FactoryReset) {
		ChipLogProgress(DeviceLayer, "FACTORY RESET");
		//delete wifi credential inside qualcomm
		W6X_WiFi_Disconnect(1);
		NVM_ResetFactory();
	} else {
		ChipLogProgress(DeviceLayer, "AppTask: Unknown Event received !!!");
	}
}


void AppTask::MatterEventHandler(const ChipDeviceEvent *event, intptr_t arg) {
	switch (event->Type) {
	case DeviceEventType::kInternetConnectivityChange:
		break;

	case DeviceEventType::kCHIPoBLEConnectionEstablished:
		ChipLogProgress(DeviceLayer, "CHIPoBLE connection established")
		;
		break;

	case DeviceEventType::kCHIPoBLEConnectionClosed:
		ChipLogProgress(DeviceLayer, "CHIPoBLE disconnected")
		;
		break;

	case DeviceEventType::kCommissioningComplete: {
		NVM_StatusTypeDef nvmStatus;
		ChipLogProgress(DeviceLayer, "Commissioning complete");
		nvmStatus = NVM_Dump();
		ChipLogProgress(DeviceLayer, "NVM %s",
				(nvmStatus == NVM_OK) ? "Saved" : "NOT Saved !!!");
		break;
	}

	case DeviceEventType::kInterfaceIpAddressChanged:
		if (event->InterfaceIpAddressChanged.Type
				== InterfaceIpChangeType::kIpV6_Assigned) {
			ChipLogProgress(DeviceLayer,
					"IPV6 address change notify the server");
 			chip::app::DnssdServer::Instance().StartServer();
		}
		break;
	}
}

