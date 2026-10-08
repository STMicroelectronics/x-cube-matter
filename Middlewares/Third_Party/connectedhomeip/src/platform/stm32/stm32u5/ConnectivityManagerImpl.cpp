/*
 *
 *    Copyright (c) 2020 Project CHIP Authors
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

/* this file behaves like a config.h, comes first */
#include <platform/internal/CHIPDeviceLayerInternal.h>

#include <lib/support/CodeUtils.h>
#include <lib/support/logging/CHIPLogging.h>
#include <platform/ConnectivityManager.h>
#include <platform/internal/BLEManager.h>
#include <platform/stm32/stm32u5/NetworkCommissioningWiFiDriver.h>

#include <lwip/dns.h>
#include <lwip/ip_addr.h>
#include <lwip/nd6.h>
#include <lwip/netif.h>

#include <platform/internal/GenericConnectivityManagerImpl_UDP.ipp>
#include "w6x_api.h"
#include "w6x_types.h"

#if INET_CONFIG_ENABLE_TCP_ENDPOINT
#include <platform/internal/GenericConnectivityManagerImpl_TCP.ipp>
#endif // INET_CONFIG_ENABLE_TCP_ENDPOINT

#if CHIP_DEVICE_CONFIG_ENABLE_CHIPOBLE
#include <platform/internal/GenericConnectivityManagerImpl_BLE.ipp>
#endif // CHIP_DEVICE_CONFIG_ENABLE_CHIPOBLE

#include "CHIPDevicePlatformConfig.h"

using namespace ::chip;
using namespace ::chip::Inet;
using namespace ::chip::System;
using namespace ::chip::DeviceLayer::Internal;

namespace chip {
namespace DeviceLayer {

ConnectivityManagerImpl ConnectivityManagerImpl::sInstance;
static bool WifiStatusCon = false;

CHIP_ERROR ConnectivityManagerImpl::_Init() {
    CHIP_ERROR err = CHIP_NO_ERROR;
    // Queue work items to bootstrap the AP and station state machines once the Chip event loop is running.
    mWiFiStationMode = kWiFiStationMode_Disabled;
    mWiFiStationState = kWiFiStationState_NotConnected;
    mLastStationConnectFailTime = System::Clock::kZero;
    mWiFiStationReconnectInterval = System::Clock::Milliseconds32(
            CHIP_DEVICE_CONFIG_WIFI_STATION_RECONNECT_INTERVAL);
    mFlags.ClearAll();

    app_matter_wifi_status_Callback (HandleWifiStatus);

    PlatformMgr().ScheduleWork(DriveStationState, 0);

    return err;
}

void ConnectivityManagerImpl::HandleWifiStatus(
        MATTER_STM_Opcode_evt_t *aMessage) {

    if (*aMessage == MATTER_STM_IPV6_CHANGE) {
        ChipLogProgress(DeviceLayer, "IPv6 address available on Ethernet interface: ");
        ChipDeviceEvent event;
        event.Type = DeviceEventType::kInterfaceIpAddressChanged;
        event.InterfaceIpAddressChanged.Type =
                InterfaceIpChangeType::kIpV6_Assigned;
        PlatformMgr().PostEventOrDie(&event);

    } else {
        if (*aMessage == MATTER_STM_CONN_HANDLE_EVT) {
            ChipLogProgress(DeviceLayer, "WIFI_EVENT_CONNECTED");
            WifiStatusCon = true;
        } else {
            WifiStatusCon = false;
            ChipLogProgress(DeviceLayer, "WIFI_EVENT_DISCONNECTED");
        }

        PlatformMgr().ScheduleWork(DriveStationState, 0);
    }
}

void ConnectivityManagerImpl::_OnPlatformEvent(const ChipDeviceEvent *event) {
    // Forward the event to the generic base classes as needed.
}

ConnectivityManager::WiFiStationMode ConnectivityManagerImpl::_GetWiFiStationMode(void) {
    mWiFiStationMode = kWiFiStationMode_Enabled;
    return mWiFiStationMode;
}

bool ConnectivityManagerImpl::_IsWiFiStationProvisioned(void) {
    W6X_WiFi_StaStateType_e State;
    W6X_WiFi_Connect_t ConnectData;
    bool status = false;

    if (W6X_WiFi_Station_GetState(&State, &ConnectData) == W6X_STATUS_OK) {
        if ((State == W6X_WIFI_STATE_STA_CONNECTED) || (State == W6X_WIFI_STATE_STA_GOT_IP)) {
        	status = true;
        }
    }

    return status;
}

bool ConnectivityManagerImpl::_IsWiFiStationEnabled(void) {
    // We support only station mode
    return true;
}

CHIP_ERROR ConnectivityManagerImpl::_SetWiFiStationMode(
        ConnectivityManager::WiFiStationMode val) {
	PlatformMgr().ScheduleWork(DriveStationState, 0);
   // DeviceLayer::SystemLayer().ScheduleWork(DriveStationState, NULL);

    if (mWiFiStationMode != val) {
        ChipLogProgress(DeviceLayer, "WiFi station mode change: %s -> %s",
                WiFiStationModeToStr(mWiFiStationMode),
                WiFiStationModeToStr(val));
    }

    mWiFiStationMode = val;

    return CHIP_NO_ERROR;
}

CHIP_ERROR ConnectivityManagerImpl::_SetWiFiStationReconnectInterval(
        System::Clock::Timeout val) {
    mWiFiStationReconnectInterval = val;
    return CHIP_NO_ERROR;
}

void ConnectivityManagerImpl::_ClearWiFiStationProvision(void) {
    if (mWiFiStationMode != kWiFiStationMode_ApplicationControlled) {
        W6X_WiFi_Disconnect(1);

        PlatformMgr().ScheduleWork(DriveStationState, 0);
    }
}

CHIP_ERROR ConnectivityManagerImpl::_GetAndLogWifiStatsCounters(void) {
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

void ConnectivityManagerImpl::_OnWiFiScanDone() {
    // CHIP_ERROR_NOT_IMPLEMENTED
}

void ConnectivityManagerImpl::_OnWiFiStationProvisionChange() {
    // Schedule a call to the DriveStationState method to adjust the station state as needed.
    ChipLogProgress(DeviceLayer, "_ON WIFI PROVISION CHANGE");
    PlatformMgr().ScheduleWork(DriveStationState, 0);
}

// == == == == == == == == == == ConnectivityManager Private Methods == == == == == == == == == ==

void ConnectivityManagerImpl::DriveStationState() {
    // Refresh the current station mode.
    GetWiFiStationMode();

    // If the station interface is currently connected ...
    if (WifiStatusCon) {
        // Advance the station state to Connected if it was previously NotConnected or
        // a previously initiated connect attempt succeeded.
        if ((mWiFiStationState == kWiFiStationState_NotConnected)
            || (mWiFiStationState == kWiFiStationState_Connecting_Succeeded)) {
            ChangeWiFiStationState (kWiFiStationState_Connected);
            ChipLogProgress(DeviceLayer, "WiFi station interface connected");
            mLastStationConnectFailTime = System::Clock::kZero;
            OnStationConnected();
        }
    }
    // Otherwise the station interface is NOT connected to an AP, so...
    else {
        System::Clock::Timestamp now =
                System::SystemClock().GetMonotonicTimestamp();

        // Advance the station state to NotConnected if it was previously Connected or Disconnecting,
        // or if a previous initiated connect attempt failed.
        if ((mWiFiStationState == kWiFiStationState_Connected)
            || (mWiFiStationState == kWiFiStationState_Disconnecting)
            || (mWiFiStationState == kWiFiStationState_Connecting_Failed)) {
            WiFiStationState prevState = mWiFiStationState;
            ChangeWiFiStationState (kWiFiStationState_NotConnected);
            if (prevState != kWiFiStationState_Connecting_Failed) {
                ChipLogProgress(DeviceLayer, "WiFi station interface disconnected");
                mLastStationConnectFailTime = System::Clock::kZero;
                OnStationDisconnected();
            } else {
                mLastStationConnectFailTime = now;
            }
        }

        // If the WiFi station interface is now enabled and provisioned (and by implication,
        // not presently under application control), AND the system is not in the process of
        // scanning, then...
        if ((mWiFiStationMode == kWiFiStationMode_Enabled)
            && IsWiFiStationProvisioned()) {
            // Initiate a connection to the AP if we haven't done so before, or if enough
            // time has passed since the last attempt.
            if ((mLastStationConnectFailTime == System::Clock::kZero)
                || (now >= (mLastStationConnectFailTime + mWiFiStationReconnectInterval))) {
                if (mWiFiStationState != kWiFiStationState_Connecting) {
                    ChipLogProgress(DeviceLayer,
                            "We lost wifi credentials in the host side");
                    ChangeWiFiStationState(kWiFiStationState_Disconnecting);
                }
            }

            // Otherwise arrange another connection attempt at a suitable point in the future.
            else {
                System::Clock::Timestamp timeToNextConnect =
                        (mLastStationConnectFailTime + mWiFiStationReconnectInterval) - now;

                ChipLogProgress(DeviceLayer,
                        "Next WiFi station reconnect in %" PRIu32 " ms",
                        System::Clock::Milliseconds32(timeToNextConnect).count());
                // TODO add retry mecanism
//                ReturnOnFailure(
//                        DeviceLayer::SystemLayer().StartTimer(timeToNextConnect, DriveStationState, NULL));
            }
        }
    }

    ChipLogProgress(DeviceLayer, "Done driving station state, nothing else to do...");
    // Kick-off any pending network scan that might have been deferred due to the activity
    // of the WiFi station.
}

void ConnectivityManagerImpl::OnStationConnected() {
    NetworkCommissioning::Stm32WiFiDriver::GetInstance().OnConnectWiFiNetwork();

    UpdateInternetConnectivityState();
    // Alert other components of the new state.
    ChipDeviceEvent event;
    event.Type = DeviceEventType::kWiFiConnectivityChange;
    event.WiFiConnectivityChange.Result = kConnectivity_Established;
    (void) PlatformMgr().PostEvent(&event);
}

void ConnectivityManagerImpl::OnStationDisconnected() {
    UpdateInternetConnectivityState();
    // Alert other components of the new state.
    ChipDeviceEvent event;
    event.Type = DeviceEventType::kWiFiConnectivityChange;
    event.WiFiConnectivityChange.Result = kConnectivity_Lost;
    (void) PlatformMgr().PostEvent(&event);
}

void ConnectivityManagerImpl::DriveStationState(intptr_t arg) {
    sInstance.DriveStationState();
}

void ConnectivityManagerImpl::ChangeWiFiStationState(WiFiStationState newState) {
    if (mWiFiStationState != newState) {
        ChipLogProgress(DeviceLayer, "WiFi station state change: %s -> %s",
                WiFiStationStateToStr(mWiFiStationState),
                WiFiStationStateToStr(newState));
        mWiFiStationState = newState;
        NetworkCommissioning::Stm32WiFiDriver::GetInstance().UpdateNetworkingStatus();
    }
}

void ConnectivityManagerImpl::UpdateInternetConnectivityState(void) {
    bool haveIPv4Conn = false;
    bool haveIPv6Conn = false;
    bool hadIPv4Conn = mFlags.Has(ConnectivityFlags::kHaveIPv4InternetConnectivity);
    bool hadIPv6Conn = mFlags.Has(ConnectivityFlags::kHaveIPv6InternetConnectivity);
    IPAddress addr;
    W6X_WiFi_StaStateType_e State;
    W6X_WiFi_Connect_t ConnectData;

    // If the WiFi station is currently in the connected state...
    if (mWiFiStationState == kWiFiStationState_Connected) {
        if (W6X_WiFi_Station_GetState(&State, &ConnectData) == W6X_STATUS_OK) {
            if ((State == W6X_WIFI_STATE_STA_CONNECTED) || (State == W6X_WIFI_STATE_STA_GOT_IP)) {
                haveIPv6Conn = true;
            }
        }
    }

    // If the internet connectivity state has changed...
    if ((haveIPv4Conn != hadIPv4Conn) || (haveIPv6Conn != hadIPv6Conn)) {
        // Update the current state.
        mFlags.Set(
                ConnectivityFlags::kHaveIPv4InternetConnectivity, haveIPv4Conn).Set(
                ConnectivityFlags::kHaveIPv6InternetConnectivity, haveIPv6Conn);

        // Alert other components of the state change.
        ChipDeviceEvent event;
        event.Type = DeviceEventType::kInternetConnectivityChange;
        event.InternetConnectivityChange.IPv4 = GetConnectivityChange(hadIPv4Conn, haveIPv4Conn);
        event.InternetConnectivityChange.IPv6 = GetConnectivityChange(hadIPv6Conn, haveIPv6Conn);
        event.InternetConnectivityChange.ipAddress = addr;

        if (haveIPv4Conn != hadIPv4Conn) {
            ChipLogProgress(DeviceLayer, "%s Internet connectivity %s", "IPv4",
                                        (haveIPv4Conn) ? "ESTABLISHED" : "LOST");
        }

        if (haveIPv6Conn != hadIPv6Conn) {
            ChipLogProgress(DeviceLayer, "%s Internet connectivity %s", "IPv6",
                                        (haveIPv6Conn) ? "ESTABLISHED" : "LOST");
        }
        (void) PlatformMgr().PostEvent(&event);
    }
}

} // namespace DeviceLayer
} // namespace chip
