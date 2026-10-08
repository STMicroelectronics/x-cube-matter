/**
 ******************************************************************************
 * @file    stm32_int_flash.c
 * @author  GPM Application Team
 * @brief   Implements flash services based of the hal driver
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
#include "stm32_int_flash.h"
#include "main.h"
#include "stm32u5xx_hal_flash.h"
#include "stm32u5xx_hal_flash_ex.h"
#include "FreeRTOS.h"
#include "semphr.h"

#define NB_PAGE_SECTOR_PER_ERASE  (1U)  /* Nb page erased per erase */
/* Private function prototypes -----------------------------------------------*/
static HAL_StatusTypeDef FLASH_If_Init(void);
static uint32_t GetPage(uint32_t uAddr);

SemaphoreHandle_t xFlashsemaphore;
/* Functions Definition ------------------------------------------------------*/

/**
 * @brief  Gets the page of a given address
 * @param  uAddr: Address of the FLASH Memory
 * @retval The page of a given address
 */
static uint32_t GetPage(uint32_t uAddr) {
	uint32_t page = 0U;

	if (uAddr < (FLASH_BASE_NS + (FLASH_BANK_SIZE))) {
		/* Bank 1 */
		page = (uAddr - FLASH_BASE_NS) / FLASH_PAGE_SIZE;
	} else {
		/* Bank 2 */
		page = (uAddr - (FLASH_BASE_NS + (FLASH_BANK_SIZE))) / FLASH_PAGE_SIZE;
	}

	return page;
}

/**
 * @brief  Unlocks Flash for write access
 * @param  None
 * @retval HAL Status.
 */
static HAL_StatusTypeDef FLASH_If_Init(void) {
	HAL_StatusTypeDef ret = HAL_ERROR;

	/* Unlock the Program memory */
	if (HAL_FLASH_Unlock() == HAL_OK) {

		/* Clear all FLASH flags */
		__HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_ALL_ERRORS);
		/* Unlock the Program memory */
		if (HAL_FLASH_Lock() == HAL_OK) {
			ret = HAL_OK;
		}
#ifdef FLASH_IF_DBG
    else
    {
      FLASH_IF_TRACE("[FLASH_IF] Lock failure\r\n");
    }
#endif /* FLASH_IF_DBG */
	}
#ifdef FLASH_IF_DBG
  else
  {
    FLASH_IF_TRACE("[FLASH_IF] Unlock failure\r\n");
  }
#endif /* FLASH_IF_DBG */
	return ret;
}

HAL_StatusTypeDef FLASH_Init(void) {
	HAL_StatusTypeDef e_ret_status = HAL_OK;
	/* Attempt to create a semaphore. */
	xFlashsemaphore = xSemaphoreCreateBinary();

	if (xFlashsemaphore == NULL) {
		e_ret_status = HAL_ERROR;
		Error_Handler();
		/* There was insufficient FreeRTOS heap available for the semaphore to
		 be created successfully. */
	}
	xSemaphoreGive(xFlashsemaphore);

	return e_ret_status;
}

/**
 * @brief  This function does an erase of n (depends on Length) pages in user flash area
 * @param  pStart: Start of user flash area
 * @param  uLength: number of bytes.
 * @retval HAL_OK if success, an error code otherwise..
 */
HAL_StatusTypeDef FLASH_Erase(void *pStart, uint32_t uLength) {
	uint32_t page_error = 0U;
	uint32_t uStart = (uint32_t) pStart;
	FLASH_EraseInitTypeDef EraseInitStruct;
	HAL_StatusTypeDef e_ret_status = HAL_ERROR;
	uint32_t first_page = 0U;
	uint32_t nb_pages = 0U;
	uint32_t chunk_nb_pages;

	if (xSemaphoreTake(xFlashsemaphore, portMAX_DELAY) == pdTRUE) {
		/* Initialize Flash */
		e_ret_status = FLASH_If_Init();
		/* Unlock the Flash to enable the flash control register access *************/
		HAL_FLASH_Unlock();

		if (e_ret_status == HAL_OK) {
			/* Unlock the Flash to enable the flash control register access *************/
			if (HAL_FLASH_Unlock() == HAL_OK) {
				first_page = GetPage(uStart);
				/* Get the number of pages to erase from 1st page */
				nb_pages = GetPage(uStart + uLength - 1U) - first_page + 1U;
				EraseInitStruct.TypeErase = FLASH_TYPEERASE_PAGES;
				EraseInitStruct.Banks =
						((uStart - FLASH_BASE) >= FLASH_BANK_SIZE) ?
								FLASH_BANK_2 : FLASH_BANK_1; //1U + (uStart-FLASH_BASE)/FLASH_BANK_SIZE;//(((uStart-FLASH_BASE) >= FLASH_BANK_SIZE) ? 2 : 1);

				/* Erase flash per NB_PAGE_SECTOR_PER_ERASE to avoid watch-dog */
				do {
					chunk_nb_pages =
							(nb_pages >= NB_PAGE_SECTOR_PER_ERASE) ?
									NB_PAGE_SECTOR_PER_ERASE : nb_pages;
					EraseInitStruct.Page = first_page;
					EraseInitStruct.NbPages = chunk_nb_pages;
					first_page += chunk_nb_pages;
					nb_pages -= chunk_nb_pages;
					if (HAL_FLASHEx_Erase(&EraseInitStruct, &page_error)
							!= HAL_OK) {
						HAL_FLASH_GetError();
						e_ret_status = HAL_ERROR;
					}
				} while (nb_pages > 0);

				/* Lock the Flash to disable the flash control register access (recommended
				 to protect the FLASH memory against possible unwanted operation) *********/
				HAL_FLASH_Lock();

			} else {
				e_ret_status = HAL_ERROR;
			}
		}
		xSemaphoreGive(xFlashsemaphore);
	}
	return e_ret_status;
}

/**
 * @brief  This function writes a data buffer in flash (data are 32-bit aligned).
 * @note   After writing data buffer, the flash content is checked.
 * @retval HAL_OK if success, an error code otherwise..
 */
HAL_StatusTypeDef FLASH_Write(void *pDestination, const void *pSource,
		uint32_t uLength) {
	HAL_StatusTypeDef e_ret_status = HAL_ERROR;
	uint32_t i = 0U;
	uint32_t pdata = (uint32_t) pSource;

	if (xSemaphoreTake(xFlashsemaphore, portMAX_DELAY) == pdTRUE) {
		/* Initialize Flash */
		e_ret_status = FLASH_If_Init();

		if (e_ret_status == HAL_OK) {
			/* Unlock the Flash to enable the flash control register access *************/
			if (HAL_FLASH_Unlock() != HAL_OK) {
				return HAL_ERROR;

			} else {
				/* DataLength must be a multiple of 64 bit */
				for (i = 0U; i < uLength; i += 16U) {
					/* Device voltage range supposed to be [2.7V to 3.6V], the operation will
					 be done by word */
					if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_QUADWORD,
							(uint32_t) pDestination, (uint32_t) (pdata + i))
							== HAL_OK) {
						/* Check the written value */
						if (*(uint64_t*) pDestination
								!= *(uint64_t*) (pdata + i)) {
							/* Flash content doesn't match SRAM content */
							e_ret_status = HAL_ERROR;
							break;
						}
						/* Increment FLASH Destination address */
						pDestination = (void*) ((uint32_t) pDestination + 16U);
					} else {
						/* Error occurred while writing data in Flash memory */
						e_ret_status = HAL_ERROR;
						break;
					}
				}
				/* Lock the Flash to disable the flash control register access (recommended
				 to protect the FLASH memory against possible unwanted operation) *********/
				HAL_FLASH_Lock();
			}
		}
		xSemaphoreGive(xFlashsemaphore);
	}
	return e_ret_status;
}
