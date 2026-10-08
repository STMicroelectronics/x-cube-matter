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

/**
 *    @file
 *          Provides an implementation of the DiagnosticDataProvider object
 *          for STM32 platforms.
 */

#include <platform/internal/CHIPDeviceLayerInternal.h>

#include <platform/DiagnosticDataProvider.h>
#include <lib/support/CHIPMemString.h>
#include "DiagnosticDataProviderImpl.h"

#include "FreeRTOS.h"

#if CHIP_DEVICE_CONFIG_ENABLE_WIFI
#include "w6x_api.h"
#include "w6x_types.h"
#endif // CHIP_DEVICE_CONFIG_ENABLE_WIFI

using namespace chip::app::Clusters::GeneralDiagnostics;

namespace {

InterfaceTypeEnum GetInterfaceType(const char * if_desc)
{
    InterfaceTypeEnum ret;

    if (strncmp(if_desc, "AR", strnlen(if_desc, 2)) == 0) {
        ret = InterfaceTypeEnum::kEthernet;
    }
    // add here analysis for thread or wifi
    else {
        ret = InterfaceTypeEnum::kUnspecified;
        ChipLogError(DeviceLayer, "Failed to get interface type");
    }

    return ret;
}

} // namespace

namespace chip {
namespace DeviceLayer {

DiagnosticDataProviderImpl & DiagnosticDataProviderImpl::GetDefaultInstance()
{
    static DiagnosticDataProviderImpl sInstance;
    return sInstance;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetCurrentHeapFree(uint64_t & currentHeapFree)
{
    size_t freeHeapSize = xPortGetFreeHeapSize();
    currentHeapFree     = static_cast<uint64_t>(freeHeapSize);
    return CHIP_NO_ERROR;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetCurrentHeapUsed(uint64_t & currentHeapUsed)
{
    // Calculate the Heap used = Total heap - Free heap
    int64_t heapUsed = (configTOTAL_HEAP_SIZE - xPortGetFreeHeapSize());

    // Something went wrong, this should not happen
    VerifyOrReturnError(heapUsed >= 0, CHIP_ERROR_INVALID_INTEGER_VALUE);
    currentHeapUsed = static_cast<uint64_t>(heapUsed);
    return CHIP_NO_ERROR;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetCurrentHeapHighWatermark(uint64_t & currentHeapHighWatermark)
{
    // Calculate the  highest heap used
    int64_t highestHeapUsageRecorded = (configTOTAL_HEAP_SIZE - xPortGetMinimumEverFreeHeapSize());

    // Something went wrong, this should not happen
    VerifyOrReturnError(highestHeapUsageRecorded >= 0, CHIP_ERROR_INVALID_INTEGER_VALUE);
    currentHeapHighWatermark = static_cast<uint64_t>(highestHeapUsageRecorded);
    return CHIP_NO_ERROR;
}

CHIP_ERROR DiagnosticDataProviderImpl::ResetWatermarks()
{
    // If implemented, the server SHALL set the value of the CurrentHeapHighWatermark attribute to the
    // value of the CurrentHeapUsed.

    // overide with non-op, no way to write CurrentHeapHighWatermark provided by portable.h
    return CHIP_NO_ERROR;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetRebootCount(uint16_t & rebootCount)
{
    uint32_t count = 0U;
    CHIP_ERROR err = ConfigurationMgr().GetRebootCount(count);

    if (err == CHIP_NO_ERROR)
    {
        VerifyOrReturnError(count <= UINT16_MAX, CHIP_ERROR_INVALID_INTEGER_VALUE);
        rebootCount = static_cast<uint16_t>(count);
    }

    return err;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetUpTime(uint64_t & upTime)
{
    CHIP_ERROR err = CHIP_ERROR_INVALID_TIME;
    System::Clock::Timestamp currentTime = System::SystemClock().GetMonotonicTimestamp();
    System::Clock::Timestamp startTime   = PlatformMgrImpl().GetStartTime();

    if (currentTime >= startTime)
    {
        upTime = std::chrono::duration_cast<System::Clock::Seconds64>(currentTime - startTime).count();
        err = CHIP_NO_ERROR;
    }

    return err;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetTotalOperationalHours(uint32_t & totalOperationalHours)
{
    return ConfigurationMgr().GetTotalOperationalHours(totalOperationalHours);
}

CHIP_ERROR DiagnosticDataProviderImpl::GetBootReason(BootReasonType & bootReason)
{
    uint32_t reason = 0U;
    CHIP_ERROR err = ConfigurationMgr().GetBootReason(reason);

    if (err == CHIP_NO_ERROR)
    {
        VerifyOrReturnError(reason <= UINT8_MAX, CHIP_ERROR_INVALID_INTEGER_VALUE);
        bootReason = static_cast<BootReasonType>(reason);
    }

    return err;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetNetworkInterfaces(NetworkInterface ** netifpp)
{
    NetworkInterface * head = NULL;

    for (Inet::InterfaceIterator interfaceIterator; interfaceIterator.HasCurrent(); interfaceIterator.Next())
    {
        uint8_t addressSize;
        uint8_t ipv6AddressesCount = 0;
        Inet::InterfaceType interfaceType = Inet::InterfaceType::Unknown;
        // Assuming IPv6-only support
        Inet::InterfaceAddressIterator interfaceAddressIterator;
        CHIP_ERROR err;
        NetworkInterface * ifp = new NetworkInterface();

        interfaceIterator.GetInterfaceName(ifp->Name, Inet::InterfaceId::kMaxIfNameLength);
        ifp->name = CharSpan::fromCharString(ifp->Name);
        ifp->isOperational = true;
        err = interfaceIterator.GetInterfaceType(interfaceType);
        if (err == CHIP_NO_ERROR || err == CHIP_ERROR_NOT_IMPLEMENTED)
        {
            switch (interfaceType)
            {
            case Inet::InterfaceType::WiFi:
                ifp->type = InterfaceTypeEnum::kWiFi;
                break;
            case Inet::InterfaceType::Ethernet:
                ifp->type = InterfaceTypeEnum::kEthernet;
                break;
            case Inet::InterfaceType::Cellular:
                ifp->type = InterfaceTypeEnum::kCellular;
                break;
            case Inet::InterfaceType::Thread:
                ifp->type = InterfaceTypeEnum::kThread;
                break;
            case Inet::InterfaceType::Unknown:
                ifp->type = GetInterfaceType(ifp->Name);
                break;
            default:
                ifp->type = InterfaceTypeEnum::kUnspecified;
                break;
            }
        }
        else
        {
            ifp->type = InterfaceTypeEnum::kUnspecified;
            ChipLogError(DeviceLayer, "Failed to get interface type");
        }

        ifp->offPremiseServicesReachableIPv4.SetNull();
        ifp->offPremiseServicesReachableIPv6.SetNull();

        if (interfaceIterator.GetHardwareAddress(ifp->MacAddress, addressSize, sizeof(ifp->MacAddress)) == CHIP_NO_ERROR)
        {
            ifp->hardwareAddress = ByteSpan(ifp->MacAddress, addressSize);
        }
        else
        {
            ChipLogError(DeviceLayer, "Failed to get network hardware address");
        }

        while (interfaceAddressIterator.HasCurrent() && ipv6AddressesCount < kMaxIPv6AddrCount)
        {
            if (interfaceAddressIterator.GetInterfaceId() == interfaceIterator.GetInterfaceId())
            {
                chip::Inet::IPAddress ipv6Address;
                if (interfaceAddressIterator.GetAddress(ipv6Address) == CHIP_NO_ERROR)
                {
                    memcpy(ifp->Ipv6AddressesBuffer[ipv6AddressesCount], ipv6Address.Addr, kMaxIPv6AddrSize);
                    ifp->Ipv6AddressSpans[ipv6AddressesCount] = ByteSpan(ifp->Ipv6AddressesBuffer[ipv6AddressesCount]);
                    ipv6AddressesCount++;
                }
            }
            interfaceAddressIterator.Next();
        }

        ifp->IPv6Addresses = chip::app::DataModel::List<chip::ByteSpan>(ifp->Ipv6AddressSpans, ipv6AddressesCount);
        ifp->Next = head;
        head = ifp;
    }
    *netifpp = head;

    return CHIP_NO_ERROR;
}

void DiagnosticDataProviderImpl::ReleaseNetworkInterfaces(NetworkInterface * netifp)
{
    while (netifp)
    {
        NetworkInterface * del = netifp;
        netifp = netifp->Next;
        delete del;
    }
}

#if CHIP_DEVICE_CONFIG_ENABLE_WIFI
using namespace chip::app::Clusters::WiFiNetworkDiagnostics;

CHIP_ERROR DiagnosticDataProviderImpl::GetWiFiBssId(MutableByteSpan & value)
{
    CHIP_ERROR err;
    constexpr size_t bssIdSize = 6;
    W6X_WiFi_StaStateType_e state;
    W6X_WiFi_Connect_t connectData = { 0U };

    VerifyOrReturnError(value.size() >= bssIdSize, CHIP_ERROR_BUFFER_TOO_SMALL);

    if (W6X_WiFi_Station_GetState(&state, &connectData) == W6X_STATUS_OK) {
        memcpy(value.data(), connectData.MAC, sizeof(connectData.MAC));
        value.reduce_size(bssIdSize);
        err = CHIP_NO_ERROR;
    }
    else {
        err = CHIP_ERROR_UNINITIALIZED;
    }

    return err;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetWiFiSecurityType(app::Clusters::WiFiNetworkDiagnostics::SecurityTypeEnum & securityType)
{
    CHIP_ERROR err = CHIP_ERROR_UNINITIALIZED;
    W6X_WiFi_StaStateType_e state;
    W6X_WiFi_Connect_t connectData = { 0U };

    if (W6X_WiFi_Station_GetState(&state, &connectData) == W6X_STATUS_OK) {
        if (!((state == W6X_WIFI_STATE_STA_CONNECTED) || (state == W6X_WIFI_STATE_STA_GOT_IP))) {
            err = CHIP_ERROR_NOT_CONNECTED;
        } else {
            err = CHIP_NO_ERROR;
            switch(connectData.Security) {
              case W6X_WIFI_SECURITY_OPEN: /* Wi-Fi is open */
                  securityType = SecurityTypeEnum::kNone;
                  break;
              case W6X_WIFI_SECURITY_WEP: /* Wired Equivalent Privacy option for Wi-Fi security. */
                  securityType = SecurityTypeEnum::kWep;
                  break;
              case W6X_WIFI_SECURITY_WPA_PSK: /* Wi-Fi Protected Access */
                  securityType = SecurityTypeEnum::kWpa;
                  break;
              case W6X_WIFI_SECURITY_WPA2_PSK: /* Wi-Fi Protected Access 2 */
                  securityType = SecurityTypeEnum::kWpa2;
                  break;
              case W6X_WIFI_SECURITY_WPA_WPA2_PSK: /* Wi-Fi Protected Access with both modes */
                  securityType = SecurityTypeEnum::kWpa2;
                  break;
              case W6X_WIFI_SECURITY_WPA_ENT: /* Wi-Fi Protected Access */
                  securityType = SecurityTypeEnum::kWpa;
                  break;
              case W6X_WIFI_SECURITY_WPA3_SAE: /* Wi-Fi Protected Access 3 */
                  securityType = SecurityTypeEnum::kWpa3;
                  break;
              case W6X_WIFI_SECURITY_WPA2_WPA3_SAE: /* Wi-Fi Protected Access with both modes */
                  securityType = SecurityTypeEnum::kWpa3;
                  break;
              case W6X_WIFI_SECURITY_UNKNOWN: /* Other modes */
                  securityType = SecurityTypeEnum::kUnspecified;
                  break;
              default:
                  securityType = SecurityTypeEnum::kUnspecified;
                  break;
            }
        }
    }

    return err;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetWiFiVersion(app::Clusters::WiFiNetworkDiagnostics::WiFiVersionEnum & wifiVersion)
{
    CHIP_ERROR err = CHIP_ERROR_UNINITIALIZED;
    W6X_WiFi_StaStateType_e state;
    W6X_WiFi_Connect_t connectData = { 0U };

    if (W6X_WiFi_Station_GetState(&state, &connectData) == W6X_STATUS_OK) {
        if (!((state == W6X_WIFI_STATE_STA_CONNECTED) || (state == W6X_WIFI_STATE_STA_GOT_IP))) {
            err = CHIP_ERROR_NOT_CONNECTED;
        } else {
            err = CHIP_NO_ERROR;
            switch(connectData.Protocol) {
              case W6X_WIFI_PROTOCOL_UNKNOWN:
                  ChipLogError(DeviceLayer, "Unknown Wi-Fi version detected");
                  wifiVersion = WiFiVersionEnum::kA; /* Unknown return value not possible */
                  break;
              case W6X_WIFI_PROTOCOL_11B:
                  wifiVersion = WiFiVersionEnum::kB;
                  break;
              case W6X_WIFI_PROTOCOL_11G:
                  wifiVersion = WiFiVersionEnum::kG;
                  break;
              case W6X_WIFI_PROTOCOL_11N:
                  wifiVersion = WiFiVersionEnum::kN;
                  break;
              case W6X_WIFI_PROTOCOL_11AX:
                  wifiVersion = WiFiVersionEnum::kAx;
                  break;
              default:
                  ChipLogError(DeviceLayer, "Unsupported Wi-Fi version detected");
                  wifiVersion = WiFiVersionEnum::kA; /* Unknown return value not possible */
                  break;
            }
        }
    }

    return err;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetWiFiChannelNumber(uint16_t & channelNumber)
{
    CHIP_ERROR err = CHIP_ERROR_UNINITIALIZED;
    W6X_WiFi_StaStateType_e state;
    W6X_WiFi_Connect_t connectData = { 0U };

    if (W6X_WiFi_Station_GetState(&state, &connectData) == W6X_STATUS_OK) {
        if (!((state == W6X_WIFI_STATE_STA_CONNECTED) || (state == W6X_WIFI_STATE_STA_GOT_IP))) {
            err = CHIP_ERROR_NOT_CONNECTED;
        } else {
            err = CHIP_NO_ERROR;
            channelNumber = connectData.Channel;
        }
    }

    return err;
 }

CHIP_ERROR DiagnosticDataProviderImpl::GetWiFiRssi(int8_t & rssi)
{
    CHIP_ERROR err = CHIP_ERROR_UNINITIALIZED;
    W6X_WiFi_StaStateType_e state;
    W6X_WiFi_Connect_t connectData = { 0U };

    if (W6X_WiFi_Station_GetState(&state, &connectData) == W6X_STATUS_OK) {
        if (!((state == W6X_WIFI_STATE_STA_CONNECTED) || (state == W6X_WIFI_STATE_STA_GOT_IP))) {
            err = CHIP_ERROR_NOT_CONNECTED;
        } else {
            err = CHIP_NO_ERROR;
            rssi = connectData.Rssi;
        }
    }

    return err;
}
#endif // CHIP_DEVICE_CONFIG_ENABLE_WIFI

DiagnosticDataProvider & GetDiagnosticDataProviderImpl()
{
    return DiagnosticDataProviderImpl::GetDefaultInstance();
}

} // namespace DeviceLayer
} // namespace chip
