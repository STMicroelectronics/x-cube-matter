/**
 ******************************************************************************
 * @file    app_entry.c
 * @author  GPM Application Team
 * @brief   app_entry program body
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

/* Includes ------------------------------------------------------------------*/

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

/* Application */
#include "main.h"
#include "app_entry.h"
#include "app_config.h"

#include "utilities_conf.h"
#include "stm32_lpm.h"
#include "util_led_pb.h"
#include "stm32_int_flash.h"
#include "app_nvm.h"
#include "w6x_api.h"
#include "common_parser.h" /* Common Parser functions */
#include "logging.h"
#include "shell.h"
#include "util_mem_perf.h"
#include "util_task_perf.h"
#include "LwIP.h"
#include "app_freertos.h"
#include "queue.h"
#include "event_groups.h"
#include "app_matter.h"
#include "spi_iface.h" /* SPI falling/rising_callback */
#if (SYS_DBG_ENABLE_TA4 >= 1)
#include "trace_helper.h"
#endif /* SYS_DBG_ENABLE_TA4 */

#if (LOW_POWER_MODE == LOW_POWER_STDBY_ENABLE)
#error "low power standby mode not supported"
#endif /* LOW_POWER_MODE */

/* Global variables ----------------------------------------------------------*/
extern UART_HandleTypeDef huart1;

/* Private typedef -----------------------------------------------------------*/
typedef struct {
	uint8_t SSID_len; /*!< Service Set Identifier length */
	uint8_t Channel; /*!< Wi-Fi channel */
	int16_t RSSI; /*!< Signal strength of Wi-Fi spot */
	uint32_t Security; /*!< Security of Wi-Fi spot */
	uint8_t SSID[W6X_WIFI_MAX_SSID_SIZE + 1]; /*!< Service Set Identifier value. Wi-Fi spot name */
} APP_AP_t;

typedef struct {
	uint8_t service_idx; /*!< Service index */
	uint8_t charac_idx; /*!< Characteristic index */
	uint8_t notification_status[2]; /*!< Notification status */
	uint8_t indication_status[2]; /*!< Indication status */
	uint32_t PassKey; /*!< BLE Security passkey */
	uint32_t available_data_length; /*!< Length of the available data */
	W6X_Ble_Device_t remote_ble_device; /*!< BLE Remote device */
} APP_Ble_Data_t;

typedef struct {
	uint8_t service_index; /*!< Service index */
	uint8_t char_index; /*!< Characteristic index */
	const char *service_uuid; /*!< Service UUID */
	uint8_t char_property; /*!< Characteristic property */
	uint8_t char_permission; /*!< Characteristic permission */
	const char *desc; /*!< Characteristic description */
} APP_Ble_Char_t;

typedef struct {
	char *version; /*!< Version of the application */
	char *name; /*!< Name of the application */
} APP_Info_t;

uint8_t m_Boot_Reason = 0;

/* Private defines -----------------------------------------------------------*/
#define WIFI_COMMISSIONING_SERVICE_INDEX         0U           /*!< BLE Wi-Fi Commissioning Service index */

#define WIFI_CONTROL_CHAR_INDEX                  0U           /*!< BLE Service index */

#define WIFI_CONFIGURE_CHAR_INDEX                1U           /*!< BLE Wi-Fi Control Characteristic index */

#define WIFI_AP_LIST_CHAR_INDEX                  2U           /*!< BLE Wi-Fi Configure Characteristic index */

#define WIFI_MONITORING_CHAR_INDEX               3U           /*!< BLE Wi-Fi Monitoring Characteristic index */


#define MATTER_COMMISSIONING_SERVICE_UUID  "FFF6"
#define MATTER_RX_CHAR_UUID                "18EE2EF5263D4559959F4F9C429F9D11"
#define MATTER_TX_CHAR_UUID                "18EE2EF5263D4559959F4F9C429F9D12"


#define CONTROL_ACTION_START_SCAN                0x1
#define CONTROL_ACTION_CONNECT                   0x3
#define CONTROL_ACTION_DISCONNECT                0x4
#define CONTROL_ACTION_PING                      0x5

#define CONFIGURE_TYPE_SSID                      0x1
#define CONFIGURE_TYPE_PWD                       0x2
#define CONFIGURE_TYPE_SECURITY_FLAG             0x5

#define MONITORING_TYPE_CONNECTING               0x3
#define MONITORING_TYPE_CONNECTION_DONE          0x4
#define MONITORING_TYPE_PING_RESPONSE            0x5
#define MONITORING_TYPE_ERROR                    0x6

#define MONITORING_DATA_CONNECTION_TIMEOUT       0x1

#define WIFI_SCAN_TIMEOUT                        10000 /*!< Delay before to declare the scan in failure */

#define WIFI_PING_COUNT                          4     /*!< Number of ping requests to send */
#define WIFI_PING_SIZE                           64    /*!< Size of the ping request */
#define WIFI_PING_INTERVAL                       1000  /*!< Time interval between two ping requests */
#define WIFI_PING_PERCENT                        100   /*!< Percent convert number */

/* Private macros ------------------------------------------------------------*/
/** Stringify version */
#define XSTR(x) #x

/** Macro to stringify version */
#define MSTR(x) XSTR(x)

/** Application version */
#define HOST_APP_VERSION_STR      \
  MSTR(HOST_APP_VERSION_MAIN) "." \
  MSTR(HOST_APP_VERSION_SUB1) "." \
  MSTR(HOST_APP_VERSION_SUB2)

/* Private variables ---------------------------------------------------------*/
#if (LOG_OUTPUT_MODE == LOG_OUTPUT_UART)
xTaskHandle LogOutputTaskHandle = NULL;
#endif /* LOG_OUTPUT_MODE */

QueueHandle_t xLogQueue = NULL;

uint8_t a_APP_AvailableData[247] = { 0 }; /*!< Available data buffer */

uint8_t a_APP_WifiCommUpdateCharData[247] = { 0 }; /*!< Wi-Fi Commissioning update characteristic data */

W6X_WiFi_Scan_Opts_t APP_Opts = { 0 }; /*!< Wi-Fi scan options */

W6X_WiFi_Connect_Opts_t APP_ConnectOpts = { 0 }; /*!< Wi-Fi connect options */

uint8_t size_of_WifiCommUpdateCharData; /*!< Size of Wi-Fi Commissioning update characteristic data */

W6X_WiFi_Scan_Result_t app_scan_results = { 0 }; /*!< Wi-Fi scan results */

MATTER_App_Notification_evt_t handleNotification;

/* Advertising Data */
/* ADV for matter */
/* Byte 8 to 13 to be overwritten with default or Factory Data value */
/* Byte 8-9  : Discriminator */
/* Byte 10-11: VendorID      */
/* Byte 12-13: ProductID     */
char a_AdvData[30] = { '0', '2', '0', '1', '0', '6', '0', 'B', '1', '6', 'F',
		'6', 'F', 'F', '0', '0', '0', '0', '0', 'F', 'F', '1', 'F', 'F', '0',
		'4', '8', '0', '0', '0', };

/** BLE parameters */
APP_Ble_Data_t app_ble_params = {
/* Initialize remote device struct */
//  .remote_ble_device.RSSI = 0,
//  .remote_ble_device.IsConnected = 0,
//  .remote_ble_device.conn_handle = 0,
//  .remote_ble_device.DeviceName = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//  .remote_ble_device.BDAddr = {0, 0, 0, 0, 0, 0},
		.service_idx = 0, /* Initialize service index to 0 */
		.charac_idx = 0, /* Initialize characteristic index to 0 */
		.notification_status = { 0, 0 }, /* Initialize notification status array to {0, 0} */
		.indication_status = { 0, 0 }, /* Initialize indication status array to {0, 0} */
		.available_data_length = 0, /* Initialize available data length to 0 */
};

/** BLE characteristics */
static const APP_Ble_Char_t app_ble_char[] =
		{ { .service_index = WIFI_COMMISSIONING_SERVICE_INDEX, .char_index =
				WIFI_CONTROL_CHAR_INDEX, .service_uuid = MATTER_RX_CHAR_UUID,
				.char_property = W6X_BLE_CHAR_PROP_WRITE_WITH_RESP,
				.char_permission = W6X_BLE_CHAR_PERM_WRITE, .desc =
						"RX Characteristic" }, { .service_index =
				WIFI_COMMISSIONING_SERVICE_INDEX, .char_index =
				WIFI_CONFIGURE_CHAR_INDEX, .service_uuid = MATTER_TX_CHAR_UUID,
				.char_property = W6X_BLE_CHAR_PROP_INDICATE, .char_permission =
						W6X_BLE_CHAR_PERM_WRITE, .desc =
						"notification Characteristic" } };

/** Application information */
static const APP_Info_t app_info = { .version = HOST_APP_VERSION_STR, .name =
		"ST67W6X matter over Wifi" };

/* Private function prototypes -----------------------------------------------*/
/**
 * @brief Wi-Fi event callback
 * @param event_id: Event ID
 * @param event_args: Event arguments
 */
static void APP_wifi_cb(W6X_event_id_t event_id, void *event_args);

/**
 * @brief Network event callback
 * @param event_id: Event ID
 * @param event_args: Event arguments
 */
static void APP_net_cb(W6X_event_id_t event_id, void *event_args);

/**
 * @brief MQTT event callback
 * @param event_id: Event ID
 * @param event_args: Event arguments
 */
static void APP_mqtt_cb(W6X_event_id_t event_id, void *event_args);

/**
 * @brief BLE event callback
 * @param event_id: Event ID
 * @param event_args: Event arguments
 */
static void APP_ble_cb(W6X_event_id_t event_id, void *event_args);

/**
  * @brief  W6X error callback
  * @param  ret_w6x: W6X status
  * @param  func_name: function name
  */
static void APP_error_cb(W6X_Status_t ret_w6x, char const *func_name);

/**
 * @brief Initialize the low power manager
 */
static void LowPowerManagerInit(void);

/**
 * @brief Log output to redirect print on user defined output
 * @param message: Message to log
 */
static void LogOutput(const char *message);

/**
 * @brief Initialize the logging and shell
 */
static void LogShellInit(void);

static void APPE_SetBootReason(void);

/* Functions Definition ------------------------------------------------------*/
void app_init(void) {
	int32_t ret = 0;
	char ble_device_name[W6X_BLE_DEVICE_NAME_SIZE];

	LowPowerManagerInit();

	/* Initialize the logging and shell utilities on UART instance */
	LogShellInit();

	// flash management init
	FLASH_Init();
	// init nvm
	NVM_Initialize();

	APPE_SetBootReason();

	LogInfo("#### Welcome to %s Application #####\n", app_info.name);
	LogInfo("**********************************************************\n");
	LogInfo("PRODUCT NAME : " PRODUCT_NAME "\n"  );
	LogInfo("VENDOR NAME : " VENDOR_NAME "\n" );
	LogInfo("HARDWARE : NUCLEO-U575ZI-Q\n" );
	LogInfo("SOFTWARE : X-CUBE-MATTER release revision " X_CUBE_MATTER_VERSION "\n" );
	LogInfo("Embedded SW components :\n");
	LogInfo("- Matter SDK version : " MATTER_SDK_VERSION "\n" );
	LogInfo("**********************************************************\n");

	/* Register the application callback to received events from ST67W6X Driver */
	  W6X_App_Cb_t App_cb = {0};
	  App_cb.APP_wifi_cb = APP_wifi_cb;
	  App_cb.APP_net_cb = APP_net_cb;
	  App_cb.APP_ble_cb = APP_ble_cb;
	  App_cb.APP_mqtt_cb = APP_mqtt_cb;
	  App_cb.APP_error_cb = APP_error_cb;
	  W6X_RegisterAppCb(&App_cb);

	/* Initialize the ST67W6X Driver */
	ret = W6X_Init();
	if (ret) {
		LogError("failed to initialize ST67W6X Driver, %ld", ret);
		Error_Handler();
	}

#if (SYS_DBG_ENABLE_TA4 >= 1)
  trace_start();
#endif /* SYS_DBG_ENABLE_TA4 */

	/* Initialize the ST67W6X Wi-Fi module */
	ret = W6X_WiFi_Init();
	if (ret) {
		LogError("failed to initialize ST67W6X Wi-Fi component, %ld", ret);
		Error_Handler();
	}
	LogInfo("Wi-Fi init is done");

	MX_LWIP_Init();
	/* Initialize the ST67W6X BLE module */
	ret = W6X_Ble_Init(W6X_BLE_MODE_SERVER, a_APP_AvailableData,
			sizeof(a_APP_AvailableData) - 1);
	if (ret) {
		LogError("failed to initialize ST67W6X BLE component, %d", ret);
		Error_Handler();
	}

	sprintf(ble_device_name, "ST67W6X_Matter");
	ret = W6X_Ble_SetDeviceName(ble_device_name);
	if (ret) {
		LogError("failed to set device name, %d", ret);
		Error_Handler();
	}

	/* Configure the ST67W6X BLE module
	 * - Set the Tx power to 0 (minimal)
	 * - Set the Bluetooth Device Address
	 * - Set the Advertising data
	 */
	ret = W6X_Ble_SetTxPower(0);
	if (ret) {
		LogError("failed to set TX power, %d", ret);
		Error_Handler();
	}

	ret = app_matter_FillAdvData((uint8_t *)a_AdvData);
	if (ret) {
		LogError("failed to retrieve Adv Data from factory data,stay on init value");
	}

	ret = W6X_Ble_SetAdvData((const char*) a_AdvData);
	if (ret) {
		LogError("failed to set ADV data, %d", ret);
		Error_Handler();
	}
	LogInfo("BLE configuration is done\n");

	/* Create the BLE Commissioning Service */
	LogInfo("BLE Commissioning Service Creation\n");
	ret = W6X_Ble_CreateService(WIFI_COMMISSIONING_SERVICE_INDEX,
			MATTER_COMMISSIONING_SERVICE_UUID, W6X_BLE_UUID_TYPE_16);
	if (ret) {
		LogError("failed to Create service, %d", ret);
		Error_Handler();
	}

	/* Create the BLE Characteristics */
	for (uint8_t i = 0; i < sizeof(app_ble_char) / sizeof(APP_Ble_Char_t);
			i++) {
		ret = W6X_Ble_CreateCharacteristic(app_ble_char[i].service_index,
				app_ble_char[i].char_index, app_ble_char[i].service_uuid, 2,
				app_ble_char[i].char_property, app_ble_char[i].char_permission);

		if (ret != 0) {
			LogError("failed to create %s, %d", app_ble_char[i].desc, ret);
			Error_Handler();
		}
		LogInfo("- %s created", app_ble_char[i].desc);
	}

	/* Register the BLE Characteristics */
	ret = W6X_Ble_RegisterCharacteristics();

	if (ret != 0) {
		LogError("failed to Register characteristics, %d", ret);
		Error_Handler();
	}
	LogInfo("- BLE services and charac registered\n");
	LogInfo("BLE service and charac creation is done\n");

	// Init matter stack
	app_matter_init();
}

void BLE_Send_Wifi_Scan_Report_Notification(void) {
	int32_t ret;
	uint32_t SentDatalen = 0;

	LogInfo("BLE Send Notification");
	ret = W6X_Ble_ServerSendNotification(WIFI_COMMISSIONING_SERVICE_INDEX,
			WIFI_AP_LIST_CHAR_INDEX, a_APP_WifiCommUpdateCharData,
			size_of_WifiCommUpdateCharData, &SentDatalen, 6000);

	if (ret) {
		LogError("Send Notification FAILED: %d", ret);
	}
	return;
}

void BLE_Send_Wifi_Monitoring_Notification(void) {
	int32_t ret;
	uint32_t SentDatalen = 0;

	LogInfo("BLE Send Notification");
	ret = W6X_Ble_ServerSendNotification(WIFI_COMMISSIONING_SERVICE_INDEX,
			WIFI_MONITORING_CHAR_INDEX, a_APP_WifiCommUpdateCharData,
			size_of_WifiCommUpdateCharData, &SentDatalen, 6000);

	if (ret) {
		LogError("Send Notification FAILED: %d", SentDatalen);
	}
	return;
}

void HAL_GPIO_EXTI_Callback(uint16_t pin);
void HAL_GPIO_EXTI_Rising_Callback(uint16_t pin);
void HAL_GPIO_EXTI_Falling_Callback(uint16_t pin);

void HAL_GPIO_EXTI_Callback(uint16_t pin)
{
  /* USER CODE BEGIN HAL_GPIO_EXTI_Callback_1 */

  /* USER CODE END HAL_GPIO_EXTI_Callback_1 */
  /* Callback when data is available in Network CoProcessor to enable SPI Clock */
  if (pin == SPI_RDY_Pin)
  {
    if (HAL_GPIO_ReadPin(SPI_RDY_GPIO_Port, SPI_RDY_Pin) == GPIO_PIN_SET)
    {
      HAL_GPIO_EXTI_Rising_Callback(pin);
    }
    else
    {
      HAL_GPIO_EXTI_Falling_Callback(pin);
    }
  }
  /* USER CODE BEGIN HAL_GPIO_EXTI_Callback_End */

  /* USER CODE END HAL_GPIO_EXTI_Callback_End */
}

void HAL_GPIO_EXTI_Rising_Callback(uint16_t pin)
{
  /* USER CODE BEGIN EXTI_Rising_Callback_1 */

  /* USER CODE END EXTI_Rising_Callback_1 */
  /* Callback when data is available in Network CoProcessor to enable SPI Clock */
  if (pin == SPI_RDY_Pin)
  {
    spi_on_txn_data_ready();
  }
  /* USER CODE BEGIN EXTI_Rising_Callback_End */

  /* USER CODE END EXTI_Rising_Callback_End */
}

void HAL_GPIO_EXTI_Falling_Callback(uint16_t pin)
{
  /* USER CODE BEGIN EXTI_Falling_Callback_1 */

  /* USER CODE END EXTI_Falling_Callback_1 */
  /* Callback when data is available in Network CoProcessor to enable SPI Clock */
  if (pin == SPI_RDY_Pin)
  {
    spi_on_header_ack();
  }
  else if (pin == USER_BUTTON_Pin_QPC)
  {
	  app_matter_pushbutton_event();
  }
  /* USER CODE BEGIN EXTI_Falling_Callback_End */

  /* USER CODE END EXTI_Falling_Callback_End */
}

#if (LOG_OUTPUT_MODE == LOG_OUTPUT_UART)
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart) {
	BaseType_t higher_priority_tas_woken = pdFALSE;

	(void) vTaskNotifyGiveIndexedFromISR(LogOutputTaskHandle, 1,
			&higher_priority_tas_woken);

	portYIELD_FROM_ISR(higher_priority_tas_woken);
}
#endif /* LOG_OUTPUT_MODE */

/* Private Functions Definition ----------------------------------------------*/
static void APP_wifi_cb(W6X_event_id_t event_id, void *event_args) {

	switch (event_id) {
	case W6X_WIFI_EVT_CONNECTED_ID:
    LogInfo("Connected to an Access Point");
		app_matter_notification_wifi(MATTER_STM_CONN_HANDLE_EVT);
		break;
	case W6X_WIFI_EVT_DISCONNECTED_ID:
		LogInfo("Station disconnected from Access Point");
		app_matter_notification_wifi(MATTER_STM_DISCON_HANDLE_EVT);
		break;

	case W6X_WIFI_EVT_REASON_ID:
		LogInfo("Reason: %s", W6X_WiFi_ReasonToStr(event_args));
		break;

	default:
		break;
	}
}

static void APP_net_cb(W6X_event_id_t event_id, void *event_args) {

}

static void APP_mqtt_cb(W6X_event_id_t event_id, void *event_args) {

}

static void APP_ble_cb(W6X_event_id_t event_id, void *event_args) {
	W6X_Ble_CbParamData_t *p_param_ble_data = (W6X_Ble_CbParamData_t*) event_args;
	switch (event_id) {
	case W6X_BLE_EVT_CONNECTED_ID:
		LogInfo(" -> BLE CONNECTED: Conn_Handle: %d",
				p_param_ble_data->remote_ble_device.conn_handle);

		/* Fill remote device structure */
		app_ble_params.remote_ble_device.conn_handle =
				p_param_ble_data->remote_ble_device.conn_handle;
		app_ble_params.remote_ble_device.IsConnected =
				p_param_ble_data->remote_ble_device.IsConnected;

		memcpy(app_ble_params.remote_ble_device.BDAddr,
				p_param_ble_data->remote_ble_device.BDAddr,
				sizeof(app_ble_params.remote_ble_device.BDAddr));
		memcpy(app_ble_params.remote_ble_device.DeviceName,
				p_param_ble_data->remote_ble_device.DeviceName,
				sizeof(app_ble_params.remote_ble_device.DeviceName));
		memcpy(app_ble_params.remote_ble_device.ManufacturerData,
				p_param_ble_data->remote_ble_device.ManufacturerData,
				sizeof(app_ble_params.remote_ble_device.ManufacturerData));

		handleNotification.Evt_Opcode = MATTER_STM_CONN_HANDLE_EVT;
		handleNotification.ConnectionHandle =
				p_param_ble_data->remote_ble_device.conn_handle;
		app_matter_notification_ble(&handleNotification);
		break;

	case W6X_BLE_EVT_CONNECTION_PARAM_ID:
		LogInfo(" -> BLE CONNECTION PARAM UPDATE");
		break;

	case W6X_BLE_EVT_DISCONNECTED_ID:
		LogInfo(" -> BLE DISCONNECTED.");

		/* Reinitialize remote device struct */
		app_ble_params.remote_ble_device.RSSI = 0;
		app_ble_params.remote_ble_device.IsConnected = 0;
		app_ble_params.remote_ble_device.conn_handle = 0xff;
		memset(app_ble_params.remote_ble_device.DeviceName, 0,
				sizeof(app_ble_params.remote_ble_device.DeviceName));
		memset(app_ble_params.remote_ble_device.BDAddr, 0,
				sizeof(app_ble_params.remote_ble_device.BDAddr));
		memset(app_ble_params.remote_ble_device.ManufacturerData, 0,
				sizeof(app_ble_params.remote_ble_device.ManufacturerData));

		handleNotification.Evt_Opcode = MATTER_STM_DISCON_HANDLE_EVT;
		handleNotification.ConnectionHandle =
				p_param_ble_data->remote_ble_device.conn_handle;
		app_matter_notification_ble(&handleNotification);
		break;

	case W6X_BLE_EVT_INDICATION_STATUS_ENABLED_ID:
		LogInfo(" -> BLE INDICATION ENABLED [Service: %d, Charac: %d].",
				p_param_ble_data->service_idx, p_param_ble_data->charac_idx);
		handleNotification.Evt_Opcode = MATTER_STM_INDICATE_ENABLED_EVT;
		handleNotification.ConnectionHandle =
				p_param_ble_data->remote_ble_device.conn_handle;
		app_matter_notification_ble(&handleNotification);
		break;

	case W6X_BLE_EVT_INDICATION_STATUS_DISABLED_ID:
		LogInfo(" -> BLE INDICATION DISABLED [Service: %d, Charac: %d].",
				p_param_ble_data->service_idx, p_param_ble_data->charac_idx);
		handleNotification.Evt_Opcode = MATTER_STM_INDICATE_DISABLED_EVT;
		handleNotification.ConnectionHandle =
				p_param_ble_data->remote_ble_device.conn_handle;
		app_matter_notification_ble(&handleNotification);
		break;

	case W6X_BLE_EVT_INDICATION_ACK_ID:
		handleNotification.Evt_Opcode = MATTER_STM_ACK_INDICATE_EVT;
		handleNotification.ConnectionHandle = 0; /* TODO */
		app_matter_notification_ble(&handleNotification);
		break;

	case W6X_BLE_EVT_NOTIFICATION_STATUS_ENABLED_ID:
		LogInfo(" -> BLE NOTIFICATION ENABLED [Service: %d, Charac: %d].",
				p_param_ble_data->service_idx, p_param_ble_data->charac_idx);
		break;

	case W6X_BLE_EVT_NOTIFICATION_STATUS_DISABLED_ID:
		LogInfo(" -> BLE NOTIFICATION DISABLED [Service: %d, Charac: %d].",
				p_param_ble_data->service_idx, p_param_ble_data->charac_idx);
		break;

	case W6X_BLE_EVT_NOTIFICATION_DATA_ID:
		LogInfo(" -> BLE NOTIFICATION.");
		break;

	case W6X_BLE_EVT_WRITE_ID:
		app_ble_params.remote_ble_device.conn_handle =
				p_param_ble_data->remote_ble_device.conn_handle;
		app_ble_params.service_idx = p_param_ble_data->service_idx;
		app_ble_params.charac_idx = p_param_ble_data->charac_idx;
		app_ble_params.available_data_length =
				p_param_ble_data->available_data_length;

		handleNotification.Evt_Opcode = MATTER_STM_WRITE_EVT;
		handleNotification.DataTransfered.Length =
				p_param_ble_data->available_data_length;
		handleNotification.DataTransfered.pPayload = a_APP_AvailableData;
		handleNotification.ConnectionHandle =
				p_param_ble_data->remote_ble_device.conn_handle;
		if (handleNotification.DataTransfered.Length == 0) {
			/* Exit the function because of bad packet  */
			break;
		}
		app_matter_notification_ble(&handleNotification);
		break;

	case W6X_BLE_EVT_READ_ID:
		break;

	case W6X_BLE_EVT_PASSKEY_CONFIRM_ID:
		app_ble_params.PassKey = p_param_ble_data->PassKey;

		LogInfo(" -> BLE PassKey received = %d", app_ble_params.PassKey);
		break;

	default:
		break;
	}
}

static void APP_error_cb(W6X_Status_t ret_w6x, char const *func_name)
{
  /* USER CODE BEGIN APP_error_cb_1 */

  /* USER CODE END APP_error_cb_1 */
  LogError("[%s] in %s API\n", W6X_StatusToStr(ret_w6x), func_name);
  /* USER CODE BEGIN APP_error_cb_2 */

  /* USER CODE END APP_error_cb_2 */
}


static void APPE_SetBootReason(void) {

	if (__HAL_RCC_GET_FLAG(RCC_FLAG_LPWRRST) != RESET) {
		/* RESET_CAUSE_LOW_POWER_RESET */
		m_Boot_Reason = 0x00;
	} else if (__HAL_RCC_GET_FLAG(RCC_FLAG_WWDGRST) != RESET) {
		/* RESET_CAUSE_WINDOW_WATCHDOG_RESET */
		m_Boot_Reason = 0x03;
	} else if (__HAL_RCC_GET_FLAG(RCC_FLAG_BORRST)!= RESET) {
		/* Brown-out reset BootReason Type */
		m_Boot_Reason = 0x02;
	} else if (__HAL_RCC_GET_FLAG(RCC_FLAG_IWDGRST) != RESET) {
		/* RESET_CAUSE_INDEPENDENT_WATCHDOG_RESET */
		m_Boot_Reason = 0x03;
	} else if (__HAL_RCC_GET_FLAG(RCC_FLAG_SFTRST) != RESET) {
		/* This reset is induced by calling NVIC_SystemReset() */
#if (OTA_SUPPORT == 1)
		size_t SizeRead = 0;
		uint8_t error_nvm = 0;
		uint8_t SoftwareVersion[sizeof(X_CUBE_MATTER_VERSION)];
		//retrieve software version to test if a OTA was made
		error_nvm = NVM_GetKeyValue(SoftwareVersion, SOFTWARE_VERSION_KEY,
				sizeof(SoftwareVersion), &SizeRead, SECTOR_MATTER);
		if (error_nvm == 0) {
			if (memcmp(SoftwareVersion, X_CUBE_MATTER_VERSION,
					sizeof(SoftwareVersion)) == 0) {
				m_Boot_Reason = 0x06;
			} else {
				// store new software version
				NVM_SetKeyValue((char*) X_CUBE_MATTER_VERSION,
						(char*) SOFTWARE_VERSION_KEY,
						sizeof(X_CUBE_MATTER_VERSION), SECTOR_MATTER);
				m_Boot_Reason = 0x05;
			}
		} else {
			m_Boot_Reason = 0x06;
		}

#else
				/*  RESET_CAUSE_SOFTWARE_RESET */
				m_Boot_Reason = 0x06;
#endif
	} else if (__HAL_RCC_GET_FLAG(RCC_FLAG_PINRST) != RESET) {
		/* RESET_CAUSE_EXTERNAL_RESET_PIN_RESET */
		m_Boot_Reason = 0x01;
	} else {
		/* RESET_CAUSE_UNKNOWN */
		m_Boot_Reason = 0x00;
	}
	LogInfo("Boot_Reason: %d\n", m_Boot_Reason);
	/* Clear RCC reset flags after determining the boot reason type */
	__HAL_RCC_CLEAR_RESET_FLAGS();
}

uint8_t APPE_GetBootReason() {
	return m_Boot_Reason;
}

static void LowPowerManagerInit(void) {
	/* Init low power manager */
	UTIL_LPM_Init();

#if ((LOW_POWER_MODE != LOW_POWER_DISABLE) && (DEBUGGER_ENABLED == 1))
  HAL_DBGMCU_EnableDBGStopMode();
  HAL_DBGMCU_EnableDBGStandbyMode();
#else
	HAL_DBGMCU_DisableDBGStopMode();
	HAL_DBGMCU_DisableDBGStandbyMode();
#endif /* DEBUGGER_ENABLED */

#if (LOW_POWER_MODE < LOW_POWER_STDBY_ENABLE)
	/* Disable Stand-by mode */
	UTIL_LPM_SetOffMode((1 << CFG_LPM_APPLI_ID), UTIL_LPM_DISABLE);
#endif /* LOW_POWER_MODE */
#if (LOW_POWER_MODE < LOW_POWER_STOP_ENABLE)
	/* Disable Stop Mode */
	UTIL_LPM_SetStopMode((1 << CFG_LPM_APPLI_ID), UTIL_LPM_DISABLE);
#endif /* LOW_POWER_MODE */
}

static void LogOutput(const char *message) {
#if (LOG_OUTPUT_MODE == LOG_OUTPUT_PRINTF) /* direct printf via putchar */
  /* Transmit if bytes available to transmit */
  printf("%s", message);

#elif (LOG_OUTPUT_MODE == LOG_OUTPUT_UART) /* UART in interrupt mode */
	HAL_StatusTypeDef hal_status = HAL_OK;

	(void) xTaskNotifyStateClearIndexed(NULL, 1);

	LogOutputTaskHandle = xTaskGetCurrentTaskHandle();

	DisableSuppressTicksAndSleep(1 << CFG_LPM_LOG_ID);

	hal_status = HAL_UART_Transmit_IT(&huart1, (uint8_t*) message,
			(uint16_t) strlen(message));
	/* configASSERT( xHalStatus == HAL_OK ); */

	if (hal_status == HAL_OK) {
		/* Wait for completion event (should be within 1 or 2 ms) */
		(void) ulTaskNotifyTakeIndexed(1, pdTRUE, portMAX_DELAY);
	}
	EnableSuppressTicksAndSleep(1 << CFG_LPM_LOG_ID);

#elif (LOG_OUTPUT_MODE == LOG_OUTPUT_ITM) /* ITM */
  /* Transmit if bytes available to transmit */
  for (int32_t i = 0; i < strlen(message); i++)
  {
    ITM_SendChar(message[i]);
  }
#endif /* LOG_OUTPUT_MODE */
}

static void LogShellInit(void) {
	xLogQueue = (QueueHandle_t) vLoggingInit(LogOutput);

#if (LOG_OUTPUT_MODE == LOG_OUTPUT_ITM)
    shell_freertos_init(NULL);
	(void)xLogQueue;
#else
	shell_freertos_init(xLogQueue);
#endif /* LOG_OUTPUT_MODE */
}

