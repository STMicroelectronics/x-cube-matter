/**
  ******************************************************************************
  * @file    trace_cfg.h
  * @author  GPM Application Team
  * @brief   Trace macros definition
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
#ifndef USER_TRACEALYZER4RECORDER_INCLUDE_TRACE_CFG_H_
#define USER_TRACEALYZER4RECORDER_INCLUDE_TRACE_CFG_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Exported constants --------------------------------------------------------*/
#if (SYS_DBG_ENABLE_TA4 >= 1)
#include "trace_cfg_ta4_freertos.h"
#else
/* disable the trace */
#define TRACE_LOG_TH_DID_RECEIVE_TX_DATA(bytes)
#define TRACE_LOG_TH_DID_RECEIVE_MSG(bytes)
#define TRACE_APP_UART1_IRQ_BEGIN()
#define TRACE_APP_UART1_IRQ_END()
#endif /* SYS_DBG_ENABLE_TA4 >= 1 */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* USER_TRACEALYZER4RECORDER_INCLUDE_TRACE_CFG_H_ */
