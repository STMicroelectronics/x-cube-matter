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
	/* HAL Init */
	HAL_Init();

	/* Configure the System clock */
	SystemClock_Config();
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
 * @brief  System Clock Configuration
 *         The system Clock is configured as follows :
 *            System Clock source            = PLL (HSE)
 *            SYSCLK(Hz)                     = 100000000
 *            HCLK(Hz)                       = 100000000
 *            AHB Prescaler                  = 1
 *            AHB5 Prescaler                 = 4
 *            APB1 Prescaler                 = 1
 *            APB2 Prescaler                 = 1
 *            APB7 Prescaler                 = 1
 *            HSE Frequency(Hz)              = 32000000
 *            PLL_M                          = 2
 *            PLL_N                          = 25
 *            PLL_P                          = 4
 *            PLL_Q                          = 4
 *            PLL_R                          = 4
 *            Flash Latency(WS)              = 3
 *            Voltage range                  = 1
 * @retval None
 */
void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	__HAL_RCC_PWR_CLK_ENABLE();
	/** At reset, the regulator is the LDO, in range 2
	 Need to move to range 1 to reach 100 MHz
	 */
	if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1)
			!= HAL_OK) {
		/* Initialization error */
		Error_Handler();
	}

	/** Activate PLL with HSE as source
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.HSEDiv = RCC_HSE_DIV1;
	RCC_OscInitStruct.PLL1.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL1.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL1.PLLFractional = 0U;
	RCC_OscInitStruct.PLL1.PLLM = 2U;
	RCC_OscInitStruct.PLL1.PLLN = 25U; /* VCO = HSE/M * N = 32 / 2 * 25 = 400 MHz */
	RCC_OscInitStruct.PLL1.PLLR = 4U; /* PLLSYS = 400 MHz / 4 = 100 MHz */
	RCC_OscInitStruct.PLL1.PLLP = 4U;
	RCC_OscInitStruct.PLL1.PLLQ = 4U;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		/* Initialization error */
		Error_Handler();
	}

	/** Select PLL as system clock source and configure the HCLK, PCLK1, PCLK2 and PCLK7
	 clocks dividers */
	RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2 | RCC_CLOCKTYPE_PCLK7
			| RCC_CLOCKTYPE_HCLK5);
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.APB7CLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.AHB5_PLL1_CLKDivider = RCC_SYSCLK_PLL1_DIV4;
	RCC_ClkInitStruct.AHB5_HSEHSI_CLKDivider = RCC_SYSCLK_HSEHSI_DIV1;
	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK) {
		/* Initialization error */
		Error_Handler();
	}

	/** Deactivate HSI
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		/* Initialization error */
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
