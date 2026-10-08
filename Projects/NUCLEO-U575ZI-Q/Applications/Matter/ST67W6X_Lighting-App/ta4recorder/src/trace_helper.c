/**
  ******************************************************************************
  * @file    trace_helper.c
  * @author  GPM Application Team
  * @brief   helper functions implementation to control the trace
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

#if (SYS_DBG_ENABLE_TA4>=1)
/* Includes ------------------------------------------------------------------*/
#include "trace_helper.h"

/* Private variables ---------------------------------------------------------*/
static bool sTraceIsStarted = false;

/* Private function declaration ----------------------------------------------*/

__weak bool trace_start_imp(void)
{
  return false;
}

/* Functions Definition ------------------------------------------------------*/
bool trace_start(void)
{
  if (!sTraceIsStarted)
  {
    sTraceIsStarted =  trace_start_imp();
  }

  return sTraceIsStarted;
}

__weak bool trace_init(void)
{
  return true;
}

#endif /* (SYS_DBG_ENABLE_TA4>=1) */
