/*
 *
 *    Copyright (c) 2021 Project CHIP Authors
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

#include <lib/support/CodeUtils.h>
#include <lib/support/SafeInt.h>
#include <platform/CHIPDeviceLayer.h>
#include <platform/stm32/stm32u5/NetworkCommissioningWiFiDriver.h>
#include <platform/stm32/stm32u5/STM32Config.h>

#include <limits>

using namespace ::chip;
using namespace ::chip::DeviceLayer::Internal;

namespace chip {
namespace DeviceLayer {
namespace NetworkCommissioning {


namespace {
NetworkCommissioning::WiFiScanResponse *sScanResult;
Stm32ScanResponseIterator<NetworkCommissioning::WiFiScanResponse> mScanResponseIter(
        sScanResult);
} // namespace

#define BUGFIX_SCAN_NETWORK  1
#if (BUGFIX_SCAN_NETWORK == 1)
static W6X_WiFi_Scan_Opts_t Opts_bugfix = {0};
static uint8_t Scan_With_SSID_bugfix = 0;
#endif

CHIP_ERROR Stm32WiFiDriver::Init(
        NetworkStatusChangeCallback *networkStatusChangeCallback) {
    CHIP_ERROR err;
    size_t ssidLen = 0;
    size_t credentialsLen = 0;
    mpScanCallback = nullptr;
    mpConnectCallback = nullptr;
    mpStatusChangeCallback = networkStatusChangeCallback;

    // If reading fails, wifi is not provisioned, no need to go further.
    err = STM32Config::ReadConfigValueStr(STM32Config::kConfigKey_WiFiSSID,
            mSavedNetwork.ssid, sizeof(mSavedNetwork.ssid), ssidLen);
    VerifyOrReturnError(err == CHIP_NO_ERROR, CHIP_NO_ERROR);

    err = STM32Config::ReadConfigValueStr(STM32Config::kConfigKey_WiFiPSK,
            mSavedNetwork.credentials, sizeof(mSavedNetwork.credentials),
            credentialsLen);
    VerifyOrReturnError(err == CHIP_NO_ERROR, CHIP_NO_ERROR);

    mSavedNetwork.credentialsLen = credentialsLen;
    mSavedNetwork.ssidLen = ssidLen;
    mStagingNetwork = mSavedNetwork;

    ConnectWiFiNetwork(mSavedNetwork.ssid, ssidLen, mSavedNetwork.credentials,
            credentialsLen);


    return err;
}

CHIP_ERROR Stm32WiFiDriver::CommitConfiguration() {
    ReturnErrorOnFailure(
            STM32Config::WriteConfigValueStr(STM32Config::kConfigKey_WiFiSSID,
                    mStagingNetwork.ssid));
    ReturnErrorOnFailure(
            STM32Config::WriteConfigValueStr(STM32Config::kConfigKey_WiFiPSK,
                    mStagingNetwork.credentials));

    mSavedNetwork = mStagingNetwork;
    return CHIP_NO_ERROR;
}

CHIP_ERROR Stm32WiFiDriver::RevertConfiguration() {
    mStagingNetwork = mSavedNetwork;
    return CHIP_NO_ERROR;
}

bool Stm32WiFiDriver::NetworkMatch(const WiFiNetwork &network,
        ByteSpan networkId) {
    return ((networkId.size() == network.ssidLen)
            && (memcmp(networkId.data(), network.ssid, network.ssidLen) == 0));
}

Status Stm32WiFiDriver::AddOrUpdateNetwork(ByteSpan ssid, ByteSpan credentials,
        MutableCharSpan &outDebugText, uint8_t &outNetworkIndex) {
    outDebugText.reduce_size(0);
    outNetworkIndex = 0;
    VerifyOrReturnError(
            (mStagingNetwork.ssidLen == 0) || (NetworkMatch(mStagingNetwork, ssid)),
            Status::kBoundsExceeded);
    VerifyOrReturnError(
            credentials.size() <= sizeof(mStagingNetwork.credentials),
            Status::kOutOfRange);
    VerifyOrReturnError(ssid.size() <= sizeof(mStagingNetwork.ssid),
            Status::kOutOfRange);

    memset(mStagingNetwork.credentials, 0, sizeof(mStagingNetwork.credentials));
    memcpy(mStagingNetwork.credentials, credentials.data(), credentials.size());
    mStagingNetwork.credentialsLen =
            static_cast<decltype(mStagingNetwork.credentialsLen)>(credentials.size());

    memset(mStagingNetwork.ssid, 0, sizeof(mStagingNetwork.ssid));
    memcpy(mStagingNetwork.ssid, ssid.data(), ssid.size());
    mStagingNetwork.ssidLen =
            static_cast<decltype(mStagingNetwork.ssidLen)>(ssid.size());

    return Status::kSuccess;
}

Status Stm32WiFiDriver::RemoveNetwork(ByteSpan networkId,
        MutableCharSpan &outDebugText, uint8_t &outNetworkIndex) {
    outDebugText.reduce_size(0);
    outNetworkIndex = 0;
    VerifyOrReturnError(NetworkMatch(mStagingNetwork, networkId),
            Status::kNetworkIDNotFound);

    // Use empty ssid for representing invalid network
    mStagingNetwork.ssidLen = 0;
    return Status::kSuccess;
}

Status Stm32WiFiDriver::ReorderNetwork(ByteSpan networkId, uint8_t index,
        MutableCharSpan &outDebugText) {
    outDebugText.reduce_size(0);
    // Only one network is supported for now
    VerifyOrReturnError(index == 0, Status::kOutOfRange);
    VerifyOrReturnError(NetworkMatch(mStagingNetwork, networkId),
            Status::kNetworkIDNotFound);
    return Status::kSuccess;
}

CHIP_ERROR Stm32WiFiDriver::ConnectWiFiNetwork(const char *ssid,
        uint8_t ssidLen, const char *key, uint8_t keyLen) {

    if (ConnectivityMgr().IsWiFiStationProvisioned()) {
        ChipLogProgress(DeviceLayer, "Disconecting for current wifi");
        if (W6X_WiFi_Disconnect(1) != W6X_STATUS_OK) {
            //return CHIP_ERROR_INTERNAL;
        }
    }
    ReturnErrorOnFailure(
            ConnectivityMgr().SetWiFiStationMode(
                    ConnectivityManager::kWiFiStationMode_Disabled));

    // Set the wifi configuration
    W6X_WiFi_Connect_Opts_t APP_ConnectOpts = { 0 }; /*!< Wi-Fi connect options */

    VerifyOrReturnError(ssidLen <= W6X_WIFI_MAX_SSID_SIZE,
            CHIP_ERROR_BUFFER_TOO_SMALL);
    memcpy(APP_ConnectOpts.SSID, ssid, ssidLen);

    VerifyOrReturnError(keyLen <= W6X_WIFI_MAX_PASSWORD_SIZE,
            CHIP_ERROR_BUFFER_TOO_SMALL);
    memcpy(APP_ConnectOpts.Password, key, keyLen);

    if (W6X_WiFi_Connect(&APP_ConnectOpts) != W6X_STATUS_OK) {
        return CHIP_ERROR_INTERNAL;
    }

    ReturnErrorOnFailure(
            ConnectivityMgr().SetWiFiStationMode(
                    ConnectivityManager::kWiFiStationMode_Disabled));
    ReturnErrorOnFailure(
            ConnectivityMgr().SetWiFiStationMode(
                    ConnectivityManager::kWiFiStationMode_Enabled));
    return CHIP_NO_ERROR;
}

// TODO: Re-write implementation with proper driver based callback
void Stm32WiFiDriver::UpdateNetworkingStatus() {

}


void Stm32WiFiDriver::ConnectNetwork(ByteSpan networkId,
        ConnectCallback *callback) {
    CHIP_ERROR err = CHIP_NO_ERROR;
    Status networkingStatus = Status::kUnknownError;

    VerifyOrExit(NetworkMatch(mStagingNetwork, networkId), networkingStatus =
            Status::kNetworkIDNotFound);
    VerifyOrExit(mpConnectCallback == nullptr, networkingStatus =
            Status::kUnknownError);

    err = ConnectWiFiNetwork(mStagingNetwork.ssid, mStagingNetwork.ssidLen,
            mStagingNetwork.credentials, mStagingNetwork.credentialsLen);
    if (err == CHIP_NO_ERROR) {
        mpConnectCallback = callback;
        networkingStatus = Status::kSuccess;
    }

    exit:
    if (networkingStatus != Status::kSuccess) {
        ChipLogError(NetworkProvisioning,
                "Failed to connect to WiFi network:%s", chip::ErrorStr(err));
        mpConnectCallback = nullptr;
        callback->OnResult(networkingStatus, CharSpan(), 0);
    }
}

void Stm32WiFiDriver::OnConnectWiFiNetwork() {

    CommitConfiguration();
    if (mpConnectCallback) {
        mpConnectCallback->OnResult(Status::kSuccess, CharSpan(), 0);
        mpConnectCallback = nullptr;
    }
}

chip::BitFlags<WiFiSecurity> Stm32WiFiDriver::ConvertSecuritytype(W6X_WiFi_SecurityType_e security)
{
    chip::BitFlags<WiFiSecurity> securityType;
    switch (security)
    {
        case W6X_WIFI_SECURITY_OPEN:
        securityType.Set(WiFiSecurity::kUnencrypted);
        break;
        case W6X_WIFI_SECURITY_WEP:
        securityType.Set(WiFiSecurity::kWep);
        break;
        case W6X_WIFI_SECURITY_WPA_PSK:
        securityType.Set(WiFiSecurity::kWpaPersonal);
        break;
        case W6X_WIFI_SECURITY_WPA2_PSK:
        securityType.Set(WiFiSecurity::kWpa2Personal);
        break;
        case W6X_WIFI_SECURITY_WPA_WPA2_PSK:
        securityType.Set(WiFiSecurity::kWpaPersonal);
        securityType.Set(WiFiSecurity::kWpa2Personal);
        break;
        case W6X_WIFI_SECURITY_WPA_ENT:
        securityType.Set(WiFiSecurity::kWpaPersonal);
        break;
        case W6X_WIFI_SECURITY_WPA3_SAE:
        securityType.Set(WiFiSecurity::kWpa3Personal);
        break;
        case W6X_WIFI_SECURITY_WPA2_WPA3_SAE:
        securityType.Set(WiFiSecurity::kWpa2Personal);
        securityType.Set(WiFiSecurity::kWpa3Personal);
        break;
        case W6X_WIFI_SECURITY_UNKNOWN:
        default:
        securityType.Set(WiFiSecurity::kUnencrypted);
        break;
    }

    return securityType;
}

bool Stm32WiFiDriver::StartScanWiFiNetworks(ByteSpan ssid) {
    W6X_Status_t ret;
    W6X_WiFi_Scan_Opts_t Opts = {0};

    ChipLogProgress(DeviceLayer, "Start Scan WiFi Networks");
    if (!ssid.empty()) // ssid is given, only scan this network
    {
#if (BUGFIX_SCAN_NETWORK == 1)
    	memcpy(Opts_bugfix.SSID, ssid.data(), ssid.size());
    	Scan_With_SSID_bugfix = 1;
#endif
        memcpy(Opts.SSID, ssid.data(), ssid.size());
        ret = W6X_WiFi_Scan(&Opts, OnScanWiFiNetworkDone);
    }
    else // scan all networks
    {
        ret = W6X_WiFi_Scan(&Opts, OnScanWiFiNetworkDone);
#if (BUGFIX_SCAN_NETWORK == 1)
    	Scan_With_SSID_bugfix = 0;
#endif
    }

    return ((ret != W6X_STATUS_OK) ? false : true);
}

void Stm32WiFiDriver::OnScanWiFiNetworkDone(int32_t status, W6X_WiFi_Scan_Result_t *entry)
{
    ChipLogProgress(DeviceLayer, "OnScanWiFiNetworkDone");
    if (entry->Count == 0)
    {
        if (GetInstance().mpScanCallback != nullptr)
        {
            if (mScanResponseIter.Count() == 0)
            {
                // if there is no network found, return kNetworkNotFound
                DeviceLayer::SystemLayer().ScheduleLambda([]() {
                    GetInstance().mpScanCallback->OnFinished(NetworkCommissioning::Status::kNetworkNotFound, CharSpan(), nullptr);
                    GetInstance().mpScanCallback = nullptr;
                });
            }
            else
            {
                DeviceLayer::SystemLayer().ScheduleLambda([]() {
                    GetInstance().mpScanCallback->OnFinished(NetworkCommissioning::Status::kSuccess, CharSpan(), &mScanResponseIter);
                    GetInstance().mpScanCallback = nullptr;
                });
            }
        }
    }
    else
    {
        NetworkCommissioning::WiFiScanResponse scanResponse = {};

        for (uint32_t count = 0U; count < entry->Count; count++)
        {
#if (BUGFIX_SCAN_NETWORK == 1)
        	if(Scan_With_SSID_bugfix == 1){
        		ChipLogProgress(DeviceLayer, "Start Scan WiFi Networks should be 1 entry : %d",entry->Count);
        		if(memcmp(Opts_bugfix.SSID,entry->AP[count].SSID,scanResponse.ssidLen) == 0){
                    scanResponse.security.Set(GetInstance().ConvertSecuritytype(entry->AP[count].Security));
                    scanResponse.ssidLen = strnlen((const char *)entry->AP[count].SSID, DeviceLayer::Internal::kMaxWiFiSSIDLength);
                    memcpy(scanResponse.ssid, entry->AP[count].SSID, scanResponse.ssidLen);
                    memcpy(scanResponse.bssid, entry->AP[count].MAC, sizeof(scanResponse.bssid));
                    scanResponse.channel  = (uint16_t)entry->AP[count].Channel;
                    scanResponse.wiFiBand = chip::DeviceLayer::NetworkCommissioning::WiFiBand::k2g4;
                    scanResponse.rssi     = entry->AP[count].RSSI;

                    mScanResponseIter.Add(&scanResponse);
        			break;
        		}
        	}else {
                scanResponse.security.Set(GetInstance().ConvertSecuritytype(entry->AP[count].Security));
                scanResponse.ssidLen = strnlen((const char *)entry->AP[count].SSID, DeviceLayer::Internal::kMaxWiFiSSIDLength);
                memcpy(scanResponse.ssid, entry->AP[count].SSID, scanResponse.ssidLen);
                memcpy(scanResponse.bssid, entry->AP[count].MAC, sizeof(scanResponse.bssid));
                scanResponse.channel  = (uint16_t)entry->AP[count].Channel;
                scanResponse.wiFiBand = chip::DeviceLayer::NetworkCommissioning::WiFiBand::k2g4;
                scanResponse.rssi     = entry->AP[count].RSSI;

                mScanResponseIter.Add(&scanResponse);

        	}
#else
            scanResponse.security.Set(GetInstance().ConvertSecuritytype(entry->AP[count].Security));
            scanResponse.ssidLen = strnlen((const char *)entry->AP[count].SSID, DeviceLayer::Internal::kMaxWiFiSSIDLength);
            memcpy(scanResponse.ssid, entry->AP[count].SSID, scanResponse.ssidLen);
            memcpy(scanResponse.bssid, entry->AP[count].MAC, sizeof(scanResponse.bssid));
            scanResponse.channel  = (uint16_t)entry->AP[count].Channel;
            scanResponse.wiFiBand = chip::DeviceLayer::NetworkCommissioning::WiFiBand::k2g4;
            scanResponse.rssi     = entry->AP[count].RSSI;

            mScanResponseIter.Add(&scanResponse);
#endif
        }
        DeviceLayer::SystemLayer().ScheduleLambda([]() {
            GetInstance().mpScanCallback->OnFinished(NetworkCommissioning::Status::kSuccess, CharSpan(), &mScanResponseIter);
            GetInstance().mpScanCallback = nullptr;
        });
    }
}

void Stm32WiFiDriver::ScanNetworks(ByteSpan ssid, WiFiDriver::ScanCallback *callback)
{
    if (callback != nullptr) {
        mpScanCallback = callback;
        if (!StartScanWiFiNetworks(ssid)) {
            ChipLogError(DeviceLayer, "ScanWiFiNetworks failed to start");
            mpScanCallback = nullptr;
            callback->OnFinished(Status::kUnknownError, CharSpan(), nullptr);
        }
    }
}

CHIP_ERROR GetConnectedNetwork(Network &network) {
    W6X_WiFi_StaStateType_e State;
    W6X_WiFi_Connect_t ConnectData;

    network.networkIDLen = 0;
    network.connected    = false;
    if (W6X_WiFi_Station_GetState(&State, &ConnectData) != W6X_STATUS_OK){
        return CHIP_ERROR_UNINITIALIZED;
    }
    if (!((State == W6X_WIFI_STATE_STA_CONNECTED) || (State == W6X_WIFI_STATE_STA_GOT_IP))) {
        return CHIP_ERROR_NOT_CONNECTED;
    }
    network.connected = true;
    uint8_t length    = strnlen((const char *)ConnectData.SSID, W6X_WIFI_MAX_SSID_SIZE);
    VerifyOrReturnError(length < sizeof(network.networkID), CHIP_ERROR_BUFFER_TOO_SMALL);
    memcpy(network.networkID, ConnectData.SSID, length);
    network.networkIDLen = length;

    return CHIP_NO_ERROR;
}

size_t Stm32WiFiDriver::WiFiNetworkIterator::Count() {
    return mDriver->mStagingNetwork.ssidLen == 0 ? 0 : 1;
}

bool Stm32WiFiDriver::WiFiNetworkIterator::Next(Network &item) {
    if (mExhausted || mDriver->mStagingNetwork.ssidLen == 0) {
        return false;
    }
    memcpy(item.networkID, mDriver->mStagingNetwork.ssid,
            mDriver->mStagingNetwork.ssidLen);
    item.networkIDLen = mDriver->mStagingNetwork.ssidLen;
    item.connected = false;
    mExhausted = true;

    Network connectedNetwork;
    CHIP_ERROR err = GetConnectedNetwork(connectedNetwork);
    if (err == CHIP_NO_ERROR) {
        if (connectedNetwork.networkIDLen == item.networkIDLen
                && memcmp(connectedNetwork.networkID, item.networkID,
                        item.networkIDLen) == 0) {
            item.connected = true;
        }
    }
    return true;
}

uint32_t Stm32WiFiDriver::GetSupportedWiFiBandsMask() const
{
    uint32_t bands = static_cast<uint32_t>(1UL << chip::to_underlying(WiFiBandEnum::k2g4));
    return bands;
}

} // namespace NetworkCommissioning
} // namespace DeviceLayer
} // namespace chip
