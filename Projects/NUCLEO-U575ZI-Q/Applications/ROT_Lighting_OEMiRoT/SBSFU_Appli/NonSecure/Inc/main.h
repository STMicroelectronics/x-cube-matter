/**
  ******************************************************************************
  * @file    main.h
  * @author  MCD Application Team
  * @brief   This file contains definitions for main application file.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef MAIN_H
#define MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32u5xx_hal.h"
#include "com.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#define SPI_CLK_Pin GPIO_PIN_5
#define SPI_CLK_GPIO_Port GPIOA
#define SPI_MISO_Pin GPIO_PIN_6
#define SPI_MISO_GPIO_Port GPIOA
#define SPI_MOSI_Pin GPIO_PIN_7
#define SPI_MOSI_GPIO_Port GPIOA
#define USER_BUTTON_Pin_QPC GPIO_PIN_12
#define USER_BUTTON_GPIO_Port_QPC GPIOF
#define USER_BUTTON_EXTI_IRQn_QPC EXTI12_IRQn
#define BOOT_Pin GPIO_PIN_9
#define BOOT_GPIO_Port GPIOE
#define CHIP_EN_Pin GPIO_PIN_11
#define CHIP_EN_GPIO_Port GPIOE
#define SPI_RDY_Pin GPIO_PIN_13
#define SPI_RDY_GPIO_Port GPIOE
#define SPI_RDY_EXTI_IRQn EXTI13_IRQn
#define SPI_CS_Pin GPIO_PIN_14
#define SPI_CS_GPIO_Port GPIOD
#define LED_RED_Pin GPIO_PIN_2
#define LED_RED_GPIO_Port GPIOG
#define LED_GREEN_Pin GPIO_PIN_7
#define LED_GREEN_GPIO_Port GPIOC
#define USART1_TX_Pin GPIO_PIN_9
#define USART1_TX_GPIO_Port GPIOA
#define USART1_RX_Pin GPIO_PIN_10
#define USART1_RX_GPIO_Port GPIOA
#define LED_BLUE_Pin GPIO_PIN_7
#define LED_BLUE_GPIO_Port GPIOB
/* Exported macros -----------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
void Error_Handler(void);
/* Exported variables --------------------------------------------------------*/
extern volatile uint32_t TestNumber;
#endif /* MAIN_H */
