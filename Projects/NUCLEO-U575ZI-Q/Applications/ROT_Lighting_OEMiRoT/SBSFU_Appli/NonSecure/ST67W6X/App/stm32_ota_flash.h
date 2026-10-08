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
#ifndef __STM32_OTA_FLASH_H_
#define __STM32_OTA_FLASH_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Includes ------------------------------------------------------------------*/
#include "region_defs.h"
#include <stdint.h>

/* SLOT A - Secure and non secure application slot for U5 */
#define SLOT_DWL_A_START            (SECONDARY_PARTITION_START)
#define SLOT_DWL_A_START_PTR        ((uint32_t * const)SECONDARY_PARTITION_START)
#define SLOT_DWL_A_SIZE             (SECONDARY_PARTITION_SIZE)
#define SLOT_DWL_A_END              (SLOT_DWL_A_START + SLOT_DWL_A_SIZE - 1U)

/* Exported types ------------------------------------------------------------*/
typedef enum {
    STM_OTA_FLASH_OK,
    STM_OTA_FLASH_INIT_FAILED,
    STM_OTA_FLASH_WRITE_FAILED,
    STM_OTA_FLASH_READ_FAILED,
    STM_OTA_FLASH_DELETE_FAILED,
    STM_OTA_FLASH_INVALID_PARAM,
    STM_OTA_FLASH_SIZE_FULL
} STM_OTA_StatusTypeDef;
/* Exported constants --------------------------------------------------------*/

void STM_OTA_FLASH_Init(void);

/* Exported functions --------------------------------------------------------*/

/**
 * @brief  Write a data chunk to internal flash with 128-bit alignment.
 *         Data is buffered so that FLASH_Write is always called with
 *         lengths that are multiples of 16 bytes.
 * @param  pSrcBuffer: Pointer to source data in RAM.
 * @param  Length:     Chunk size in bytes.
 * @retval STM_OTA_StatusTypeDef
 */
STM_OTA_StatusTypeDef STM_OTA_FLASH_WriteChunk(uint8_t *pSrcBuffer, uint32_t Length);

/**
 * @brief  Flush the last partial 16-byte block at the end of OTA transfer.
 *         The remaining bytes are padded with TEMPBUF_PADDING and written
 *         as a full 16-byte block.
 * @retval STM_OTA_StatusTypeDef
 */
STM_OTA_StatusTypeDef STM_OTA_FLASH_FlushLastBlock(void);

/**
 * @brief magic trailer in internal flash
 */
STM_OTA_StatusTypeDef STM_OTA_FLASH_WriteMagicTrailer(void);

/**
 * @brief return the number of bytes write in flash
 */
uint32_t STM_OTA_FLASH_GetWritedBlock(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __STM32_OTA_FLASH_H_ */
