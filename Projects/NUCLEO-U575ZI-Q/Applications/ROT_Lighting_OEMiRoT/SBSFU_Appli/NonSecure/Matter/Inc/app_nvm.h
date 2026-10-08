/**
  ******************************************************************************
  * @file    app_nvm.h
  * @author  MCD Application Team
  * @brief   Header for app_nvm.c – NVM middleware for Matter keys
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

#ifndef APP_NVM_H
#define APP_NVM_H

/* Includes ------------------------------------------------------------------*/
#include "stm32u5xx_hal.h"

#ifdef __cplusplus
extern "C" {
#endif


    

/* Exported types ------------------------------------------------------------*/

/**
  * @brief  NVM middleware status codes.
  */
typedef enum
{
  NVM_OK = 0,
  NVM_PARAM_ERROR,
  NVM_WRITE_FAILED,
  NVM_READ_FAILED,
  NVM_DELETE_FAILED,
  NVM_KEY_NOT_FOUND,
  NVM_BLOCK_SIZE_OVERFLOW,
  NVM_BUFFER_TOO_SMALL,
  NVM_ERROR_BLOCK_ALIGN,
  NVM_SIZE_FULL
} NVM_StatusTypeDef;

/**
  * @brief  NVM sector identifiers.
  *         Typically distinguish Matter and OpenThread regions.
  */
typedef enum
{
  SECTOR_DEFAULT = 0,
  SECTOR_WIFI,
  SECTOR_MATTER
} NVM_Sector;

/* Exported functions --------------------------------------------------------*/

/**
  * @brief  Initialize NVM middleware and load NVM content to RAM.
  * @param  None
  * @retval NVM_OK on success, or error code.
  */
NVM_StatusTypeDef NVM_Initialize(void);

/**
  * @brief  Dump RAM NVM image to Flash (erase + write).
  *         Erase is started; write is done in callback.
  * @param  None
  * @retval NVM_OK on successful request.
  */
NVM_StatusTypeDef NVM_Dump(void);

/**
  * @brief  Check if a key exists in the selected NVM sector.
  * @param  pKeyName Key name string.
  * @param  sector   Sector identifier (matter / ot).
  * @retval NVM_OK if key exists, NVM_KEY_NOT_FOUND or error code.
  */
NVM_StatusTypeDef NVM_GetKeyExists(const char *pKeyName, NVM_Sector sector);

/**
  * @brief  Retrieve the value of a key from the selected NVM sector.
  * @param  pKeyValue  Output buffer for key value.
  * @param  pKeyName   Key name string.
  * @param  keySize    Size of the output buffer.
  * @param  pReadSize  Pointer to store actual read size (may be NULL).
  * @param  sector     Sector identifier (matter / ot).
  * @retval NVM_OK on success, NVM_KEY_NOT_FOUND, or error code.
  */
NVM_StatusTypeDef NVM_GetKeyValue(void *pKeyValue,
                                  const char *pKeyName,
                                  uint32_t keySize,
                                  size_t *pReadSize,
                                  NVM_Sector sector);

/**
  * @brief  Set or update a key value in the selected NVM sector.
  *         If key exists, it is replaced; otherwise, it is appended.
  * @param  pKeyValue Pointer to key value.
  * @param  pKeyName  Pointer to key name string.
  * @param  keySize   Size of key value.
  * @param  sector    Sector identifier (matter / ot).
  * @retval NVM_OK on success or error code.
  */
NVM_StatusTypeDef NVM_SetKeyValue(const char *pKeyValue,
                                  const char *pKeyName,
                                  uint32_t keySize,
                                  NVM_Sector sector);

/**
  * @brief  Delete a key from the selected NVM sector.
  * @param  pKeyName Key name string.
  * @param  sector   Sector identifier (matter / ot).
  * @retval NVM_OK on success, NVM_KEY_NOT_FOUND or error code.
  */
NVM_StatusTypeDef NVM_DeleteKey(const char *pKeyName, NVM_Sector sector);

/**
  * @brief  Reset NVM content to factory settings by erasing NVM region.
  *         System reset is performed in the erase callback.
  * @param  None
  * @retval None
  */
void NVM_ResetFactory(void);

#ifdef __cplusplus
}
#endif

#endif /* APP_NVM_H */
