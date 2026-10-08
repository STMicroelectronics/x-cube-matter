/**
  ******************************************************************************
  * @file    app_entry.h
  * @author  GPM Application Team
  * @brief   Header for app_entry.c
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __APP_ENTRY_H
#define __APP_ENTRY_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include "app_config.h"
/* Exported constants --------------------------------------------------------*/
#define HOST_APP_VERSION_MAIN   0   /*!< [31:24] main version */
#define HOST_APP_VERSION_SUB1   9   /*!< [23:16] sub1 version */
#define HOST_APP_VERSION_SUB2   0   /*!< [15:8]  sub2 version */

#define HOST_APP_MAIN_SHIFT     24  /*!< main version shift */
#define HOST_APP_SUB1_SHIFT     16  /*!< sub1 version shift */
#define HOST_APP_SUB2_SHIFT     8   /*!< sub2 version shift */

#define APP_NAME "Lighting-app"
/* Version */
#define X_CUBE_MATTER_VERSION "v1.6.0"
#define PRODUCT_NAME "Dimmable Light"
#define VENDOR_NAME "STMicroelectronics"
#define MATTER_SDK_VERSION "1.5.0.1"
#define SOFTWARE_VERSION_KEY "softwareid"

/** Application version 32bits formatted */
#define HOST_APP_VERSION        ((HOST_APP_VERSION_MAIN  << HOST_APP_MAIN_SHIFT)\
                                 |(HOST_APP_VERSION_SUB1 << HOST_APP_SUB1_SHIFT)\
                                 |(HOST_APP_VERSION_SUB2 << HOST_APP_SUB2_SHIFT))

/* Functions prototypes -------------------------------------------------------*/
/**
  * @brief  Main application
  */
void app_init(void);

/**
  * @brief  Send BLE notification for Wi-Fi scan characteristic
  */
void BLE_Send_Wifi_Scan_Report_Notification(void);

/**
  * @brief  Send BLE notification for Wi-Fi monitoring characteristic
  */
void BLE_Send_Wifi_Monitoring_Notification(void);

/**
  * @brief  Retrieve boot reason
  */
uint8_t APPE_GetBootReason();

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __APP_ENTRY_H */
