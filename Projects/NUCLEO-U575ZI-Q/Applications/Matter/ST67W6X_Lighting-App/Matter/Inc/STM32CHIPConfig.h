/*
 *
 *    Copyright (c) 2020 Project CHIP Authors
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

#ifndef STM32CHIPCONFIG_H
#define STM32CHIPCONFIG_H

// ==================== Platform Adaptations ====================

#define STM32_DEVICE_VENDOR_NAME                            "STMicroelectronics"
#define STM32_DEVICE_PRODUCT_NAME                           "STM32U5 Demo Matter over wifi"
#define STM32_DEVICE_SOFTWARE_VERSION_STRING                "1.5.0"
#define STM32_DEVICE_SOFTWARE_VERSION                       1

#define STM32_TEST_SERIAL_NUMBER                            "TEST_SN"
#define STM32_DEVICE_TYPE                                   0x0101 /* Dimmable Light */

#define STM32_CHIP_TASK_STACK_SIZE      (10 * 1024)
#define STM32_CHIP_TASK_PRIORITY        30
#define STM32_CHIP_MAX_EVENT_QUEUE_SIZE 25

        /* Test Setup (PASE) Configuration */
#define STM32_ENABLE_TEST_SETUP_PARAMS                      1 /* WARNING : SHOULD NEVER BE ENABLED IN PRODUCTION BUILDS */
#define CHIP_DEVICE_CONFIG_USE_TEST_SETUP_DISCRIMINATOR     0xF00

        /* Thread */
#define STM32_ENABLE_THREAD            0
#define STM32_ENABLE_THREAD_SRP_CLIENT 0
#define STM32_ENABLE_THREAD_DNS_CLIENT 0

        /* Wi-Fi */
#define STM32_ENABLE_WIFI_AP 0
#define STM32_ENABLE_WIFI_STATION 1
#define STM32_ENABLE_WIFI (STM32_ENABLE_WIFI_AP | STM32_ENABLE_WIFI_STATION)
#define STM32_WIFI_STATION_RECONNECT_INTERVAL 5000
#define STM32_MAX_SCAN_NETWORKS_RESULTS 10
#define STM32_WIFI_SCAN_COMPLETION_TIMEOUT 10000
#define STM32_WIFI_CONNECTIVITY_TIMEOUT 30000
#define STM32_WIFI_AP_SSID_PREFIX "MATTER-"
#define STM32_WIFI_AP_CHANNEL 1
#define STM32_WIFI_AP_MAX_STATIONS 4
#define STM32_WIFI_AP_BEACON_INTERVAL 100
#define STM32_WIFI_AP_IDLE_TIMEOUT 120000
#define STM32_ENABLE_WIFI_TELEMETRY 0

        /* BLE Commissioning and divers */
#define STM32_ENABLE_CHIPOBLE 1
#define STM32_ENABLE_EXTENDED_DISCOVERY 0
#define STM32_ENABLE_COMMISSIONABLE_DEVICE_TYPE 0
#define STM32_BLE_DEVICE_NAME_PREFIX "MATTER-"
#define STM32_BLE_FAST_ADVERTISING_INTERVAL_MIN 32
#define STM32_BLE_FAST_ADVERTISING_INTERVAL_MAX 96
#define STM32_BLE_SLOW_ADVERTISING_INTERVAL_MIN 240
#define STM32_BLE_SLOW_ADVERTISING_INTERVAL_MAX 1920

#define STM32_CHIPOBLE_SINGLE_CONNECTION 1
#define STM32_CHIPOBLE_DISABLE_ADVERTISING_WHEN_PROVISIONED 0
#define STM32_ENABLE_CHIP_TIME_SERVICE_TIME_SYNC 0
#define STM32_CHIP_TIME_SERVICE_ENDPOINT_ID 0x18B4300200000005ULL
#define STM32_DEFAULT_TIME_SYNC_INTERVAL 180
#define STM32_TIME_SYNC_TIMEOUT 10000
#define STM32_SERVICE_PROVISIONING_ENDPOINT_ID 0x18B4300200000010ULL
#define STM32_SERVICE_PROVISIONING_CONNECTIVITY_TIMEOUT 10000
#define STM32_SERVICE_PROVISIONING_REQUEST_TIMEOUT 10000
#define STM32_ENABLE_TRAIT_MANAGER 0
#define STM32_ENABLE_THREAD_TELEMETRY 0
#define STM32_ENABLE_THREAD_TELEMETRY_FULL 0
#define STM32_EVENT_LOGGING_CRIT_BUFFER_SIZE 4096
#define STM32_EVENT_LOGGING_PROD_BUFFER_SIZE 2048
#define STM32_EVENT_LOGGING_INFO_BUFFER_SIZE 1024
#define STM32_EVENT_LOGGING_DEBUG_BUFFER_SIZE 1024
#define STM32_LOG_PROVISIONING_HASH 1
#define STM32_CHIP_FACTORY_NAMESPACE_PARTITION_LABEL "nvs"
#define STM32_CHIP_CONFIG_NAMESPACE_PARTITION_LABEL "nvs"
#define STM32_CHIP_COUNTERS_NAMESPACE_PARTITION_LABEL "nvs"
#define STM32_ENABLE_DEVICE_INSTANCE_INFO_PROVIDER 0

/* ICD Server */
#define STM32_ENABLE_ICD_SERVER 0

/* Credentials */
#define STM32_CURRENT_TIME_NOT_IMPLEMENTED 1

/* ACL Extensions */
#define STM32_ENABLE_ACL_EXTENSIONS 1

#define STM32_STORE_MAX_KEY_SIZE 30

#define STM32_RENDEZVOUS_MODE 8

#define STM32_SECURITY_TEST_MODE 0
#define STM32_DEBUG_CERT_VALIDATION 0

#define CHIP_CONFIG_PERSIST_SUBSCRIPTIONS 1
#define CHIP_CONFIG_SUBSCRIPTION_TIMEOUT_RESUMPTION 1

/**
 * CHIP_DEVICE_CONFIG_DEVICE_VENDOR_ID
 *
 * 0xFFF1: Test vendor
 */
#define CHIP_DEVICE_CONFIG_DEVICE_VENDOR_ID 0xFFF1

/**
 * CHIP_DEVICE_CONFIG_DEVICE_PRODUCT_ID
 *
 * 0x8004: example lighting app
 */
#define CHIP_DEVICE_CONFIG_DEVICE_PRODUCT_ID 0x8004

/**
 * CHIP_DEVICE_CONFIG_DEVICE_HARDWARE_VERSION
 *
 * The hardware version number assigned to device or product by the device vendor.  This
 * number is scoped to the device product id, and typically corresponds to a revision of the
 * physical device, a change to its packaging, and/or a change to its marketing presentation.
 * This value is generally *not* incremented for device software versions.
 */
#define CHIP_DEVICE_CONFIG_DEVICE_HARDWARE_VERSION 1

#endif /* STM32CHIPCONFIG_H */
