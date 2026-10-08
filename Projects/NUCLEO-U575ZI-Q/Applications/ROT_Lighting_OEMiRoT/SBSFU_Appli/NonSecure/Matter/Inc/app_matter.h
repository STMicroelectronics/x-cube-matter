/**
  ******************************************************************************
  * @file    app_matter.h
  * @author  GPM Application Team
  * @brief   Header for app_matter.c
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __APP_MATTER_H
#define __APP_MATTER_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Includes ------------------------------------------------------------------*/
#include <stdbool.h>
#include <stdint.h>

/* Exported types ------------------------------------------------------------*/

typedef enum {
	MATTER_STM_CONN_HANDLE_EVT,
	MATTER_STM_DISCON_HANDLE_EVT,
	MATTER_STM_ACK_INDICATE_EVT,
	MATTER_STM_INDICATE_ENABLED_EVT,
	MATTER_STM_INDICATE_DISABLED_EVT,
	MATTER_STM_READ_EVT,
	MATTER_STM_WRITE_EVT,
	MATTER_STM_IPV6_CHANGE,
	MATTER_STM_BOOT_REQUEST_EVT,
} MATTER_STM_Opcode_evt_t;

typedef struct {
	uint8_t *pPayload;
	uint8_t Length;
} MATTER_STM_Data_t;

typedef struct {
	MATTER_STM_Opcode_evt_t Evt_Opcode;
	MATTER_STM_Data_t DataTransfered;
	uint16_t ConnectionHandle;
	uint8_t ServiceInstance;
} MATTER_App_Notification_evt_t;

typedef struct
{
  uint8_t Button; /* BUTTON_USER */
  bool State; /* 0: released - 1: pressed */
} ButtonState_t;

typedef struct {
	uint8_t *Payload;
	uint16_t Length;
	uint16_t connid;
} BLE_Matter_RX;

typedef struct {
	uint16_t connid;
	uint8_t notif;
} BLE_Matter_TXCharCCCD;

typedef void (*BLEReceiveCallback)(BLE_Matter_RX *aMessage);
typedef void (*BLETXCharCCCDWriteCallback)(BLE_Matter_TXCharCCCD *aMessage);
typedef void (*BLEConnectionCallback)(void);
typedef void (*BLEDisconnectionCallback)(uint16_t *connid);
typedef void (*BLEDAckCallback)(uint16_t *connid);

typedef void (*ButtonCallback)(ButtonState_t *ptMessage);
typedef void (*WifiStatusCallback)(MATTER_STM_Opcode_evt_t *aMessage);

/* Functions prototypes -------------------------------------------------------*/
/**
  * @brief  launch init matter stack
  */
void app_matter_init(void);

void ButtonSetCallback(ButtonCallback aCallback);

void app_matter_wifi_status_Callback(WifiStatusCallback aCallback);

void app_matter_notification_wifi(MATTER_STM_Opcode_evt_t pNotification);

void app_matter_notification_ble(MATTER_App_Notification_evt_t *pNotification);

uint8_t app_matter_FillAdvData(uint8_t *ble_AdvData);

void APP_MATTER_BLE_Set_Connection_Callback(BLEConnectionCallback aCallback);
void APP_MATTER_BLE_Set_Disconnection_Callback(BLEDisconnectionCallback aCallback);
void APP_MATTER_BLE_Set_Receive_Callback(BLEReceiveCallback aCallback);
void APP_MATTER_BLE_Set_TXCharCCCDWrite_Callback(BLETXCharCCCDWriteCallback aCallback);
void APP_MATTER_BLE_Set_Ack_After_Indicate_Callback(BLEDAckCallback aCallback);

void app_matter_pushbutton_event(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __APP_MATTER_H */
