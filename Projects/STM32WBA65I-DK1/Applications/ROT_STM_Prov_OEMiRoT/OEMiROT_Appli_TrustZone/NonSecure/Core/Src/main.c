/**
 ******************************************************************************
 * @file    MbedTLS_HW_ALT/Encrypted_ITS_KeyImport/Src/main.c
 * @author  MCD Application Team
 * @brief   This example provides a short description of how to use
 *          PSA Encryptes ITS alternative implementation to store AES-CBC key
 *          in encrypted storage and use the encrypted key to perform AES-CBC
 *          Encryption and dycreption operation.
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
#include <string.h>
#include <stdio.h>
#include "main.h"
#include "stm32_factorydata.h"

/* Global variables ----------------------------------------------------------*/
/* Private typedef --------------------------------s---------------------------*/
/* Private defines -----------------------------------------------------------*/
#define UART_MSG_SIZE 16
#define START_PROVISIONING "\nStart_provisioning\n"
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart1;

/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void PeriphCommonClock_Config(void);
static void MX_USART1_UART_Init(void);
/* Functions Definition ------------------------------------------------------*/

/**
 * @brief  Main program
 * @param  None
 * @retval None
 */
int main(void) {
	uint8_t error = 0;
	HAL_StatusTypeDef status = 0;
	uint8_t msg[UART_MSG_SIZE];
	uint8_t msg_receive[UART_MSG_SIZE];
	/* USER CODE BEGIN 1 */
	HAL_MPU_Disable();
	/* USER CODE END 1 */

	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();
	/* DeInitialize RCC to allow PLL reconfiguration when configuring system clock */
	HAL_RCC_DeInit();
	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();

	/* Configure the peripherals common clocks */
	PeriphCommonClock_Config();

	MX_USART1_UART_Init();
	status = HAL_UART_Receive(&huart1, msg_receive, 5, 0xFFFF);
	if (status != HAL_OK) {
		Error_Handler();
	}
	status = HAL_UART_Transmit(&huart1, (uint8_t*) START_PROVISIONING,
			sizeof(START_PROVISIONING), 0xFFFF);
	if (status != HAL_OK) {
		Error_Handler();
	}
	error = FACTORYDATA_Write();
	snprintf((char*) msg, sizeof(msg), "finish:%03u\n", error);
	while (1) {

		status = HAL_UART_Transmit(&huart1, msg, UART_MSG_SIZE, 0xFFFF);
		if (status != HAL_OK) {
			Error_Handler();
		}
		HAL_Delay(3000);
	}
}

/**
 * @brief USART1 Initialization Function
 * @param None
 * @retval None
 */
void MX_USART1_UART_Init(void) {

	/* USER CODE BEGIN USART1_Init 0 */

	/* USER CODE END USART1_Init 0 */

	/* USER CODE BEGIN USART1_Init 1 */

	/* USER CODE END USART1_Init 1 */
	huart1.Instance = USART1;
	huart1.Init.BaudRate = 115200;
	huart1.Init.WordLength = UART_WORDLENGTH_8B;
	huart1.Init.StopBits = UART_STOPBITS_1;
	huart1.Init.Parity = UART_PARITY_NONE;
	huart1.Init.Mode = UART_MODE_TX_RX;
	huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart1.Init.OverSampling = UART_OVERSAMPLING_16;
	huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
	huart1.Init.ClockPrescaler = UART_PRESCALER_DIV1;
	huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
	if (HAL_UART_Init(&huart1) != HAL_OK) {
		Error_Handler();
	}
	if (HAL_UARTEx_SetTxFifoThreshold(&huart1, UART_TXFIFO_THRESHOLD_1_8)
			!= HAL_OK) {
		Error_Handler();
	}
	if (HAL_UARTEx_SetRxFifoThreshold(&huart1, UART_RXFIFO_THRESHOLD_1_8)
			!= HAL_OK) {
		Error_Handler();
	}
	if (HAL_UARTEx_DisableFifoMode(&huart1) != HAL_OK) {
		Error_Handler();
	}

}

/**
 * @brief System Clock Configuration
 * @retval None
 */
static void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/** Supply configuration update enable
	 */
	HAL_PWREx_ConfigSupply(PWR_SMPS_SUPPLY);

	/** Configure the main internal regulator output voltage
	 */
	/* MATTER BEGIN */
	if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1)
			!= HAL_OK) {
		Error_Handler();
	}

	/** Configure LSE Drive Capability
	 */
	HAL_PWR_EnableBkUpAccess();
	__HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_MEDIUMLOW);

	/** Initializes the CPU, AHB and APB busses clocks
	 */

	/* Init PLL here instead of using the scm config  so that PLL is up faster
	 * config will be saved anyway by scm_init
	 */

	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI
			| RCC_OSCILLATORTYPE_HSE | RCC_OSCILLATORTYPE_LSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.HSEDiv = RCC_HSE_DIV1;
	RCC_OscInitStruct.LSEState = RCC_LSE_ON;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	/* 100MHz PLL config */
	RCC_OscInitStruct.PLL1.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL1.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL1.PLLM = 4;
	RCC_OscInitStruct.PLL1.PLLN = 25;
	RCC_OscInitStruct.PLL1.PLLP = 2;
	RCC_OscInitStruct.PLL1.PLLQ = 2;
	RCC_OscInitStruct.PLL1.PLLR = 2;
	RCC_OscInitStruct.PLL1.PLLFractional = 0;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/** Initializes the CPU, AHB and APB busses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2 | RCC_CLOCKTYPE_PCLK7
			| RCC_CLOCKTYPE_HCLK5;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
	RCC_ClkInitStruct.APB7CLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.AHB5_PLL1_CLKDivider = RCC_SYSCLK_PLL1_DIV4;/*should not be >32MHz*/
	RCC_ClkInitStruct.AHB5_HSEHSI_CLKDivider = RCC_SYSCLK_HSEHSI_DIV1;
	/* MATTER END */

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK) {
		Error_Handler();
	}

	/* Select SysTick source clock */
	HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_LSE);

	/* Re-Initialize Tick with new clock source */
	if (HAL_InitTick(TICK_INT_PRIORITY) != HAL_OK) {
		Error_Handler();
	}
}

/**
 * @brief Peripherals Common Clock Configuration
 * @retval None
 */
static void PeriphCommonClock_Config(void) {
	RCC_PeriphCLKInitTypeDef PeriphClkInit = { 0 };

	/** Initializes the peripherals clock
	 */
	PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_RADIOST;
	PeriphClkInit.RadioSlpTimClockSelection = RCC_RADIOSTCLKSOURCE_LSE;

	if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK) {
		Error_Handler();
	}
}


/**
 * @brief  This function is executed in case of error occurrence
 * @param  None
 * @retval None
 */
void Error_Handler(void) {
	/* User may add here some code to deal with this error */
	/* Toggle LD5 @2Hz to notify error condition */
	while (1) {
		BSP_LED_Toggle(LD5);
		HAL_Delay(250);
	}
}

#ifdef USE_FULL_ASSERT

/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line) {
	/* User can add his own implementation to report the file name and line number,
	 ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

	/* Infinite loop */
	while (1) {
	}
}
#endif /* USE_FULL_ASSERT */
