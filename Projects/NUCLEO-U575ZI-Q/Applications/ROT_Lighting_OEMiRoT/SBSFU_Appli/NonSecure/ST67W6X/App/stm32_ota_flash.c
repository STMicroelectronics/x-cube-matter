/**
 ******************************************************************************
 * @file    stm32_ota_flash.c
 * @author  GPM Application Team
 * @brief   Implements ota services for stm32
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

/* Includes ------------------------------------------------------------------*/
#include "stm32_ota_flash.h"
#include "stm32_int_flash.h"
#include "string.h"

/* OEMiROT Magic value */
static uint32_t MagicTrailerValue[] = { 0xf395c277, 0x7fefd260, 0x0f505235,
		0x8079b62c, };

#define TEMPBUF_SIZE 16
#define TEMPBUF_PADDING 0xFF
static uint8_t tempBUF[TEMPBUF_SIZE];
static uint32_t extra_bits = 0; // Number of valid bytes currently in tempBUF
static uint32_t BytesWrite = 0; // Total number of bytes written
static uint32_t DestAddress  = 0; // Current flash write address (local to this module)

void STM_OTA_FLASH_Init(void) {
	extra_bits = 0;
	memset(tempBUF, TEMPBUF_PADDING, TEMPBUF_SIZE);
	BytesWrite = 0;
	DestAddress = SLOT_DWL_A_START;
}

/**
 * @brief  Write a data chunk to internal flash with 128-bit alignment.
 *         Data is buffered so that FLASH_Write is always called with
 *         lengths that are multiples of 16 bytes.
 * @param  pSrcBuffer: Pointer to source data in RAM.
 * @param  Length:     Chunk size in bytes.
 * @retval STM_OTA_StatusTypeDef
 */
STM_OTA_StatusTypeDef STM_OTA_FLASH_WriteChunk(uint8_t *pSrcBuffer, uint32_t Length) {

	STM_OTA_StatusTypeDef err = STM_OTA_FLASH_OK;
	HAL_StatusTypeDef hall_err = HAL_OK;

	if ((pSrcBuffer == NULL) || (Length == 0)) {
		return STM_OTA_FLASH_INVALID_PARAM;
	}

	 // If we already have some bytes in tempBUF, try to complete it to 16 bytes
	if ((extra_bits > 0) && (extra_bits + Length >= TEMPBUF_SIZE)) {
		//flush last 128 bits
		memcpy(tempBUF + extra_bits, pSrcBuffer, (TEMPBUF_SIZE - extra_bits));
		hall_err = FLASH_Write((void*) (DestAddress), tempBUF,
				sizeof(tempBUF));
		if (hall_err != HAL_OK) {
			return STM_OTA_FLASH_WRITE_FAILED;
		}
		DestAddress += TEMPBUF_SIZE;
		Length -= (TEMPBUF_SIZE - extra_bits);
		BytesWrite += sizeof(tempBUF);
		pSrcBuffer += (TEMPBUF_SIZE - extra_bits);
		extra_bits = 0;

	}
	// internal flash requirement : destination address is 128 bits aligned
	// calculate maximum number of 128-bit blocks and remaining bytes from received data buffer
	uint32_t nb_blocks = (Length) / TEMPBUF_SIZE;
	uint32_t rem = Length % TEMPBUF_SIZE;
	hall_err = FLASH_Write((void*) (DestAddress), pSrcBuffer,
			nb_blocks * TEMPBUF_SIZE);
	if (hall_err != HAL_OK) {
		return STM_OTA_FLASH_WRITE_FAILED;
	}
	DestAddress += nb_blocks * TEMPBUF_SIZE;
	BytesWrite += nb_blocks * TEMPBUF_SIZE;

	 // Store remaining bytes (<16) into tempBUF for the next call
	if (rem > 0) {
		 // tempBUF is empty: start a new partial block //
		if (extra_bits == 0) {
			memcpy(tempBUF, (pSrcBuffer + (nb_blocks * 16)), rem);
			extra_bits = rem;
		} else {
			// tempBUF is not empty
			if (rem + extra_bits <= TEMPBUF_SIZE) {
				memcpy(tempBUF + extra_bits, (pSrcBuffer + (nb_blocks * 16)),
						rem);
				extra_bits += rem;
			} else {
				err = STM_OTA_FLASH_WRITE_FAILED;
			}
		}
	}
	return err;
}


/**
 * @brief  Flush the last partial 16-byte block at the end of OTA transfer.
 *         The remaining bytes are padded with TEMPBUF_PADDING and written
 *         as a full 16-byte block.
 * @retval STM_OTA_StatusTypeDef
 */
STM_OTA_StatusTypeDef STM_OTA_FLASH_FlushLastBlock(void)
{
    HAL_StatusTypeDef hall_err;

    // Nothing pending in tempBUF
    if (extra_bits == 0U) {
        return STM_OTA_FLASH_OK;
    }

    // Pad remaining bytes with TEMPBUF_PADDING (0xFF) up to 16 bytes
    memset(tempBUF+ extra_bits, TEMPBUF_PADDING, TEMPBUF_SIZE - extra_bits);

    hall_err = FLASH_Write((void *)DestAddress, tempBUF, TEMPBUF_SIZE);
    if (hall_err != HAL_OK) {
        return STM_OTA_FLASH_WRITE_FAILED;
    }

    DestAddress += TEMPBUF_SIZE;
    BytesWrite  += extra_bits;
    extra_bits   = 0;

    return STM_OTA_FLASH_OK;
}

/**
 * @brief magic trailer in internal flash
 */
STM_OTA_StatusTypeDef STM_OTA_FLASH_WriteMagicTrailer(void) {

	uint32_t MagicAddress = SLOT_DWL_A_END - sizeof(MagicTrailerValue) + 1;
	HAL_StatusTypeDef error;
	STM_OTA_StatusTypeDef err = STM_OTA_FLASH_OK;

	error = FLASH_Write((void *)MagicAddress, MagicTrailerValue,
			sizeof(MagicTrailerValue));
	if (error != HAL_OK) {
		err = STM_OTA_FLASH_WRITE_FAILED;
	}
	return err;
}

/**
 * @brief return the number of bytes write in flash
 */
uint32_t STM_OTA_FLASH_GetWritedBlock(void) {
	return BytesWrite;
}
