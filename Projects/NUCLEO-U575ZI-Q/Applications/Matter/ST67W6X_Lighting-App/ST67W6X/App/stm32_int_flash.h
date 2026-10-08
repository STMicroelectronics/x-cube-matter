/**
  ******************************************************************************
  * @file    stm32_int_flash.c
  * @author  GPM Application Team
  * @brief   Implements flash services based of the hal driver, header file
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
#ifndef __STM32_INT_FLASH_H_
#define __STM32_INT_FLASH_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Includes ------------------------------------------------------------------*/
#include "stm32u575xx.h"
#include "stm32u5xx_hal.h"


HAL_StatusTypeDef FLASH_Init(void);

/**
  * @brief  This function writes a data buffer in flash (data are 32-bit aligned).
  * @note   After writing data buffer, the flash content is checked.
  * @retval HAL_OK if success, an error code otherwise..
  */
HAL_StatusTypeDef FLASH_Write(void *pDestination, const void *pSource,
                                        uint32_t uLength);

/**
  * @brief  This function does an erase of n (depends on Length) pages in user flash area
  * @param  pStart: Start of user flash area
  * @param  uLength: number of bytes.
  * @retval HAL_OK if success, an error code otherwise..
  */
HAL_StatusTypeDef FLASH_Erase(void *pStart, uint32_t uLength);

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/



/* Exported functions --------------------------------------------------------*/


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __STM32_INT_FLASH_H_ */
