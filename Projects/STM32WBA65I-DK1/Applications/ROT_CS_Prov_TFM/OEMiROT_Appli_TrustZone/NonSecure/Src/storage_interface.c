/**
  ******************************************************************************
  * @file    storage_interface.c
  * @author  MCD Application Team
  * @brief   Implementation of storage interface
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
#include "storage_interface.h"
#include "string.h"
#include <stdio.h>

#define FLASH_BANK_SIZE 0x100000
/* Uncomment the line below if you want some debug logs */
#define FLASH_IF_DBG
#ifdef FLASH_IF_DBG
#define FLASH_IF_TRACE printf
#else
#define FLASH_IF_TRACE(...)
#endif /* FLASH_IF_DBG */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/


/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
static uint32_t GetPage(uint32_t uAddr);
static HAL_StatusTypeDef FLASH_If_Init(void);
/* Functions Definition ------------------------------------------------------*/

/**
  * @brief  Gets the page of a given address
  * @param  uAddr: Address of the FLASH Memory
  * @retval The page of a given address
  */
static uint32_t GetPage(uint32_t uAddr)
{
  uint32_t page = 0U;

  if (uAddr < (FLASH_BASE_NS + (FLASH_BANK_SIZE)))
  {
    /* Bank 1 */
    page = (uAddr - FLASH_BASE_NS) / FLASH_PAGE_SIZE;
  }
  else
  {
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
static HAL_StatusTypeDef FLASH_If_Init(void)
{
  HAL_StatusTypeDef ret = HAL_ERROR;

  /* Unlock the Program memory */
  if (HAL_FLASH_Unlock() == HAL_OK)
  {

    /* Clear all FLASH flags */
    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_ALL_ERRORS);
    /* Unlock the Program memory */
    if (HAL_FLASH_Lock() == HAL_OK)
    {
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

uint32_t page_error = 0U;
uint32_t uStart ;
FLASH_EraseInitTypeDef EraseInitStruct;
HAL_StatusTypeDef e_ret_status = HAL_ERROR;
uint32_t first_page = 0U;
uint32_t nb_pages = 0U;
uint32_t chunk_nb_pages;

/**
  * @brief  This function does an erase of n (depends on Length) pages in user flash area
  * @param  pStart: Start of user flash area
  * @param  uLength: number of bytes.
  * @retval HAL_OK if success, an error code otherwise..
  */
HAL_StatusTypeDef FLASH_If_Erase_Size(void *pStart, uint32_t uLength)
{

	uStart =  (uint32_t)pStart;
  /* Initialize Flash */
  e_ret_status = FLASH_If_Init();
  /* Unlock the Flash to enable the flash control register access *************/
  HAL_FLASH_Unlock();
  e_ret_status = HAL_OK;
  if (e_ret_status == HAL_OK)
  {
    /* Unlock the Flash to enable the flash control register access *************/
    if (HAL_FLASH_Unlock() == HAL_OK)
    {
      first_page = GetPage(uStart);
      /* Get the number of pages to erase from 1st page */
      nb_pages = GetPage(uStart + uLength - 1U) - first_page + 1U;
      EraseInitStruct.TypeErase   = FLASH_TYPEERASE_PAGES;
      EraseInitStruct.Banks = ((uStart-FLASH_BASE_NS) >= FLASH_BANK_SIZE) ? FLASH_BANK_2 : FLASH_BANK_1;//1U + (uStart-FLASH_BASE_NS)/FLASH_BANK_SIZE;//(((uStart-FLASH_BASE_NS) >= FLASH_BANK_SIZE) ? 2 : 1);

      /* Erase flash per NB_PAGE_SECTOR_PER_ERASE to avoid watch-dog */
      do
      {
        chunk_nb_pages = (nb_pages >= NB_PAGE_SECTOR_PER_ERASE) ? NB_PAGE_SECTOR_PER_ERASE : nb_pages;
        EraseInitStruct.Page = first_page;
        EraseInitStruct.NbPages = chunk_nb_pages;
        first_page += chunk_nb_pages;
        nb_pages -= chunk_nb_pages;
        if (HAL_FLASHEx_Erase(&EraseInitStruct, &page_error) != HAL_OK)
        {
          HAL_FLASH_GetError();
          e_ret_status = HAL_ERROR;
        }
      } while (nb_pages > 0);

      /* Lock the Flash to disable the flash control register access (recommended
      to protect the FLASH memory against possible unwanted operation) *********/
      HAL_FLASH_Lock();

    }
    else
    {
      e_ret_status = HAL_ERROR;
    }
  }

  return e_ret_status;
}

/**
  * @brief  This function writes a data buffer in flash (data are 32-bit aligned).
  * @note   After writing data buffer, the flash content is checked.
  * @retval HAL_OK if success, an error code otherwise..
  */
HAL_StatusTypeDef FLASH_If_Write(void *pDestination, const void *pSource, uint32_t uLength)
{
  HAL_StatusTypeDef e_ret_status = HAL_ERROR;
  uint32_t i = 0U;
  uint32_t pdata = (uint32_t)pSource;

  /* Initialize Flash */
  e_ret_status = FLASH_If_Init();

  if (e_ret_status == HAL_OK)
  {
    /* Unlock the Flash to enable the flash control register access *************/
    if (HAL_FLASH_Unlock() != HAL_OK)
    {
      return HAL_ERROR;

    }
    else
    {
      /* DataLength must be a multiple of 64 bit */
      for (i = 0U; i < uLength; i += 16U)
      {
        /* Device voltage range supposed to be [2.7V to 3.6V], the operation will
        be done by word */
        if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_QUADWORD, (uint32_t)pDestination,  (uint32_t)(pdata+i))
            == HAL_OK)
        {
          /* Check the written value */
          if (*(uint64_t *)pDestination != *(uint64_t *)(pdata + i))
          {
            /* Flash content doesn't match SRAM content */
            e_ret_status = HAL_ERROR;
            break;
          }
          /* Increment FLASH Destination address */
          pDestination = (void *)((uint32_t)pDestination + 16U);
        }
        else
        {
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
  return e_ret_status;
}
