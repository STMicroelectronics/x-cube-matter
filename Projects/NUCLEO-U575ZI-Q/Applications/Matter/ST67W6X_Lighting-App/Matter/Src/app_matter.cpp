/**
 ******************************************************************************
 * @file    app_matter.c
 * @author  GPM Application Team
 * @brief   Implements services to init matter stack and transfer data to matter
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "AppTask.h"
#include "app_matter.h"
#include "STM32FreeRtosHooks.h"
#include "main.h"
#include "stm32_factorydata.h"
#include "app_config.h"
#include "logging.h"

#define BUTTON_THREAD_NAME           "ButtonProcess"
#define BUTTON_THREAD_STACK_DEPTH    (1024)
#define BUTTON_THREAD_PRIORITY       (24)

/* Private variables ---------------------------------------------------------*/
WifiStatusCallback WifiStatusCb = NULL;

BLEReceiveCallback BLEReceiveCb = NULL;
BLETXCharCCCDWriteCallback BLETXCharCCCDWriteCb = NULL;
BLEConnectionCallback BLEConnectionCb = NULL;
BLEDisconnectionCallback BLEDisconnectionCb = NULL;
BLEDAckCallback BLEAckCb = NULL;

/* Callback function to handle Button action */
static ButtonCallback ButtonCb = NULL;
static TaskHandle_t sButtonTaskHandle = NULL;
static void ButtonProcessTask(void *p_argument);

void app_matter_wifi_status_Callback(WifiStatusCallback aCallback) {
	WifiStatusCb = aCallback;
}

void APP_MATTER_BLE_Set_Receive_Callback(BLEReceiveCallback aCallback) {
	BLEReceiveCb = aCallback;
}

void APP_MATTER_BLE_Set_TXCharCCCDWrite_Callback(
		BLETXCharCCCDWriteCallback aCallback) {
	BLETXCharCCCDWriteCb = aCallback;
}

void APP_MATTER_BLE_Set_Connection_Callback(BLEConnectionCallback aCallback) {
	BLEConnectionCb = aCallback;
}

void APP_MATTER_BLE_Set_Disconnection_Callback(
		BLEDisconnectionCallback aCallback) {
	BLEDisconnectionCb = aCallback;
}

void APP_MATTER_BLE_Set_Ack_After_Indicate_Callback(BLEDAckCallback aCallback) {
	BLEAckCb = aCallback;
}

/* Functions Definition ------------------------------------------------------*/

void app_matter_init(void) {

	//init mutex for mbedtls
	freertos_mbedtls_init();

	xTaskCreate(ButtonProcessTask, BUTTON_THREAD_NAME,
	BUTTON_THREAD_STACK_DEPTH, NULL, BUTTON_THREAD_PRIORITY,
			&sButtonTaskHandle);

	//start matter stack
	GetAppTask().Start();

}

void ButtonSetCallback(ButtonCallback aCallback) {
	ButtonCb = aCallback;
}

void app_matter_notification_wifi(MATTER_STM_Opcode_evt_t pNotification) {

	if (WifiStatusCb != NULL) {
		WifiStatusCb(&pNotification);
	}
}

uint8_t app_matter_FillAdvData(uint8_t *ble_AdvData) {
	char hexStr[5];
	uint8_t byte_inversion[4] = { 2, 3, 0, 1 };
	uint16_t setupDiscriminator = 0;
	uint16_t vendorId = 0;
	uint16_t productId = 0;
	uint8_t err_module = 0;

#if (CONFIG_STM32_FACTORY_DATA_ENABLE == 1)
			 FACTORYDATA_StatusTypeDef err = DATAFACTORY_OK;
			 uint32_t tlvDataLength = 0;

			 err = FACTORYDATA_GetValue(TAG_ID_SETUP_DISCRIMINATOR, (uint8_t *) &setupDiscriminator,
					                    sizeof(setupDiscriminator), &tlvDataLength);

			 if (err != DATAFACTORY_OK )
			 {
				 err_module = 1;
				 LogInfo("Failed to get from Factory Data Discriminator.\n");
			 }

			 err = FACTORYDATA_GetValue(TAG_ID_VENDOR_ID, (uint8_t *) &vendorId,
			 					                    sizeof(vendorId), &tlvDataLength);
			 if (err != DATAFACTORY_OK )
			 {
				 err_module = 1;
				 LogInfo("Failed to get from Factory Data VendorId.\n");
			 }


			 err = FACTORYDATA_GetValue(TAG_ID_PRODUCT_ID, (uint8_t *) &productId,
			 					                    sizeof(productId), &tlvDataLength);
			 if (err != DATAFACTORY_OK )
			 {
				 err_module = 1;
				 LogInfo("Failed to get from Factory Data ProductId.\n");
			 }

			 if (err_module != 0){
				 return err_module;
			 }

#else
	setupDiscriminator = CHIP_DEVICE_CONFIG_USE_TEST_SETUP_DISCRIMINATOR;
	vendorId = CHIP_DEVICE_CONFIG_DEVICE_VENDOR_ID;
	productId = CHIP_DEVICE_CONFIG_DEVICE_PRODUCT_ID;

#endif /* CONFIG_STM32_FACTORY_DATA_ENABLE */

	snprintf(hexStr, sizeof(hexStr), "%04X", setupDiscriminator & 0xFFF); // Masque sur 12 bits
	for (int i = 0; i < 4; i++) {
		ble_AdvData[16 + i] = hexStr[byte_inversion[i]];
	}
	snprintf(hexStr, sizeof(hexStr), "%04X", vendorId);
	for (int i = 0; i < 4; i++) {
		ble_AdvData[20 + i] = hexStr[byte_inversion[i]];
	}
	snprintf(hexStr, sizeof(hexStr), "%04X", productId);
	for (int i = 0; i < 4; i++) {
		ble_AdvData[24 + i] = hexStr[byte_inversion[i]];
	}

	return err_module;
}

void app_matter_notification_ble(MATTER_App_Notification_evt_t *pNotification) {
	/* USER CODE BEGIN APP_MATTER_Notification */
	BLE_Matter_TXCharCCCD message;
	/* USER CODE END APP_MATTER_Notification */
	switch (pNotification->Evt_Opcode) {
	/* USER CODE BEGIN APP_MATTER_Notification */
	/* USER CODE END APP_MATTER_Notification */

	case MATTER_STM_CONN_HANDLE_EVT:
		/* USER CODE BEGIN PEER_CONN_HANDLE_EVT */
		if (BLEConnectionCb != NULL) {
			BLEConnectionCb();
		}
		/* USER CODE END PEER_CONN_HANDLE_EVT */
		break;

	case MATTER_STM_DISCON_HANDLE_EVT:
		/* USER CODE BEGIN PEER_DISCON_HANDLE_EVT */
		if (BLEDisconnectionCb != NULL) {
			BLEDisconnectionCb(&pNotification->ConnectionHandle);
		}
		/* USER CODE END PEER_DISCON_HANDLE_EVT */
		break;

	case MATTER_STM_ACK_INDICATE_EVT:
		/* USER CODE BEGIN PEER_DISCON_HANDLE_EVT */
		if (BLEAckCb != NULL) {
			BLEAckCb(&pNotification->ConnectionHandle);
		}
		/* USER CODE END PEER_DISCON_HANDLE_EVT */
		break;

	case MATTER_STM_INDICATE_ENABLED_EVT:
		/* USER CODE BEGIN P2PS_STM__NOTIFY_ENABLED_EVT */
		if (BLETXCharCCCDWriteCb != NULL) {
			message.connid = pNotification->ConnectionHandle;
			message.notif = 1;
			BLETXCharCCCDWriteCb(&message);
		}
		/* USER CODE END P2PS_STM__NOTIFY_ENABLED_EVT */
		break;

	case MATTER_STM_INDICATE_DISABLED_EVT:
		/* USER CODE BEGIN P2PS_STM_NOTIFY_DISABLED_EVT */
		if (BLETXCharCCCDWriteCb != NULL) {
			message.connid = pNotification->ConnectionHandle;
			message.notif = 0;
			BLETXCharCCCDWriteCb(&message);
		}
		/* USER CODE END P2PS_STM_NOTIFY_DISABLED_EVT */
		break;

	case MATTER_STM_WRITE_EVT:
		;
		BLE_Matter_RX Message;
		if (BLEReceiveCb != NULL) {
			Message.Length = pNotification->DataTransfered.Length;
			Message.Payload = pNotification->DataTransfered.pPayload;
			Message.connid = pNotification->ConnectionHandle;
			BLEReceiveCb(&Message); //call matter callback
		}
		/* USER CODE BEGIN MATTER_STM_WRITE_EVT */

		/* USER CODE END MATTER_STM_WRITE_EVT */
		break;

	default:
		/* USER CODE BEGIN APP_MATTER_Notification */

		/* USER CODE END APP_MATTER_Notification */
		break;
	}
	/* USER CODE BEGIN APP_MATTER_Notification */

	/* USER CODE END APP_MATTER_Notification */
	return;
}

void app_matter_pushbutton_event(void) {

	if (sButtonTaskHandle != NULL) {
		portBASE_TYPE xHigherPriorityTaskWoken = pdFALSE;
		vTaskNotifyGiveFromISR(sButtonTaskHandle, &xHigherPriorityTaskWoken);
		portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
	}

}

/* Private Functions Definition ----------------------------------------------*/

static void ButtonProcessTask(void *p_argument) {
	(void) (p_argument);
	uint8_t ButtonUserState = 0;

	for (;;) {
		ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
		{
			//
			if (ButtonCb != NULL) {
				ButtonState_t Message;
				Message.State = (ButtonUserState == true) ? 1 : 0;
				ButtonCb(&Message); /* callback to handle button */
			}
		}
	}
}
