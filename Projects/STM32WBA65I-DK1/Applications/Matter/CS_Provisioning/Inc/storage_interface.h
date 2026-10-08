/**
  ******************************************************************************
  * @file    storage_interface.h
  * @author  MCD Application Team
  * @brief   Header for storage_interface.c module
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STORAGE_INTERFACE_H
#define STORAGE_INTERFACE_H

/* Includes ------------------------------------------------------------------*/
#include "stm32wbaxx.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Device Attestation PSA key ID */
#define FLASH_IF_MIN_WRITE_LEN    (8U)     /* Flash programming by 64 bits */
#define NB_PAGE_SECTOR_PER_ERASE  (1U)  /* Nb page erased per erase */


/* Exported functions ------------------------------------------------------- */
HAL_StatusTypeDef FLASH_If_Write(void *pDestination, const void *pSource, uint32_t uLength);

HAL_StatusTypeDef FLASH_If_Erase_Size(void *pStart, uint32_t uLength);

#endif  /* STORAGE_INTERFACE_H */

