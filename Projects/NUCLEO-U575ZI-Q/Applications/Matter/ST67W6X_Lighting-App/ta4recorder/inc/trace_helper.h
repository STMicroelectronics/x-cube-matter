/**
  ******************************************************************************
  * @file    trace_helper.h
  * @author  GPM Application Team
  * @brief   declaration of the helper functions to control the trace.
  *          This file declare the public API used by the trace subsystem and it
  *          defines the trace macro used to instrument the code.
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
#ifndef APPLICATION_USER_CORE_TRACE_HELPER_H_
#define APPLICATION_USER_CORE_TRACE_HELPER_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Includes ------------------------------------------------------------------*/
#include "trace_cfg.h"
#include <stdbool.h>

/* Trace macro definition */
/**************************/

/* File: Middlewares\ST\ST67W6X_Network_Driver\Utils\Logging\tx_uart_drv.c */

#ifndef TRACE_LOG_TH_DID_RECEIVE_TX_DATA
/**
  * Called in the thread control loop of the low level driver of the logging component when data are received or
  * the timeout is expired. When (bytes > 0) new data have been received
  */
#define TRACE_LOG_TH_DID_RECEIVE_TX_DATA(bytes)
#endif /* TRACE_LOG_TH_DID_RECEIVE_TX_DATA */

/* File: Middlewares\ST\ST67W6X_Network_Driver\Utils\Logging\tx_uart_drv.c,
 *       Middlewares\ST\ST67W6X_Network_Driver\Utils\Logging\tx_itm_drv.c
 */

#ifndef TRACE_LOG_TH_DID_RECEIVE_MSG
/**
  * Called in the thread control loop of the low level driver of the logging component when a new log message is received or
  * the timeout is expired. When (bytes > 0) new data have been received
  */
#define TRACE_LOG_TH_DID_RECEIVE_MSG(bytes)
#endif /* TRACE_LOG_TH_DID_RECEIVE_MSG */

/* File: Middlewares\ST\ST67W6X_Network_Driver\Utils\Logging\tx_uart_drv.c,
 *       Middlewares\ST\ST67W6X_Network_Driver\Utils\Shell\shell_freertos_tx_uart_driver.c
 */

#ifndef TRACE_APP_UART1_IRQ_BEGIN
/**
  * Called at the beginning of the UART1 ISR.
  */
#define TRACE_APP_UART1_IRQ_BEGIN()
#endif /* TRACE_APP_UART1_IRQ_BEGIN */

#ifndef TRACE_APP_UART1_IRQ_END
/**
  * Called at the end of the UART1 ISR.
  */
#define TRACE_APP_UART1_IRQ_END()
#endif /* TRACE_APP_UART1_IRQ_END */

/* Public API declaration */
/**************************/

/**
 * Start the trace.
 *
 * @return true if the trace starts with success, false otherwise.
 */
bool trace_start(void);

bool trace_start_imp(void);

/**
 * Initialize the resource used by the application for the trace. Must be called before the trace_start().
 *
 * @return true if the trace is initialized with success, false otherwise.
 */
bool trace_init(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* APPLICATION_USER_CORE_TRACE_HELPER_H_ */
