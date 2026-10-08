/**
  ******************************************************************************
  * @file    trace_cfg_ta4_freertos.c
  * @author  GPM Application Team
  * @brief   TA4 user event definition.
  *          This file define the user event objects used in the implementation of the
  *          the trace macro for Percepio Tracealyzer v4.10.x for FreeRTOS.
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
#include "trace_cfg_ta4_freertos.h"
#include "trace_helper.h"

#if (SYS_DBG_ENABLE_TA4>=1)

traceString drv_ta4Event;
traceString app_ta4Event;
traceString log_ta4Event;
TraceISRHandle_t ISRSuart1Handle = 0;

bool trace_start_imp(void)
{
  bool res = false;
  traceResult trace_res = xTraceEnable(TRC_START);
  res = (trace_res == TRC_SUCCESS);

  return res;
}

bool trace_init(void)
{
  bool res = true;

  drv_ta4Event = xTraceRegisterString("DRV_EVT");
  app_ta4Event = xTraceRegisterString("APP_EVT");
  log_ta4Event = xTraceRegisterString("LOG_EVT");
  xTraceISRRegister("ISR_UART1", 7, &ISRSuart1Handle);

  return res;
}

#endif /* (SYS_DBG_ENABLE_TA4>=1) */

