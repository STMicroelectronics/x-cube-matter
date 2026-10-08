/**
  ******************************************************************************
  * @file    util_led_pb.h
  * @author  GPM Application Team
  * @brief   Header for Led and PushButton services functions.
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
#ifndef __UTIL_LED_PB_H_
#define __UTIL_LED_PB_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include "cmsis_os2.h"

/* Exported types ------------------------------------------------------------*/
typedef enum
{
  BP_NOT_PUSHED = 0,
  BP_SINGLE_PUSH,
  BP_MULTIPLE_PUSH
} ButtonPush_TypeDef;

typedef enum
{
  LED1 = 0,
  LED2 = 1,
  LED3 = 2,
  /* Color led aliases */
  LED_GREEN  = LED1,
  LED_BLUE   = LED2,
  LED_RED    = LED3,
} Led_TypeDef;

typedef enum
{
  BBR0 = 0,
  BBR1 = 1
} Gpio_BlinkBackgroundRoutine_TypeDef;

/* Exported constants --------------------------------------------------------*/

#define LED_NB         3
#define BLINKTASK_NB   2

#define BBR_DISABLE    0
#define BBR_ENABLE     1
#define BBR_LOOPDELAY  2

#define OS_DELAY_MS 1000

/* Exported functions --------------------------------------------------------*/

void Button_Falling_Callback(void);

/**
  * Button_WaitForPush - Wait for button to be pushed
  *
  * @param timeout: to exit if no one pushes the button.
  *
  */
uint8_t Button_WaitForPush(uint32_t timeout);

/**
  * Button_WaitForPush - Wait for button to be pushed quickly several consecutive times
  *
  * @param timeout: to exit if no one pushes the button.
  *
  */
uint8_t Button_WaitForMultiPush(uint32_t timeout);

/**
  * Led_SetState - Wait for button to be pushed quickly several consecutive times
  *
  * @param on: 1 to set it, 0 to reset it.
  * @param Led: Led number.
  *
  */
void Led_SetState(bool on, Led_TypeDef Led);

/**
  * Led_Blink_N_Times - Runs a limited period (N times) do indicate something happened.
  *
  * @param period: is the time interval (frequency) of the blinking.
  * @param duty:   0 followed by 1, or 1 followed by 0
  * @param count:  number of blinking.
  * @param Led: Led number.
  *
  */
void Led_Blink_N_Times(int32_t period, int32_t duty, int32_t count, Led_TypeDef Led);

/* Generic BackGround Led Blinking on FreeRTOS task */
/**
  * Led_BlinkBackgroundRoutine_Control - It sets the values used by the Led_BlinkBackgroundTask_Run().
  *
  * @param BlinkRoutine: Routine which has to blink
  * @param Enable:   1 Blinking enabled, 0 blinking disabled
  * @param DutyCycle_ms:  determines the blinking frequency
  * @param Led: Led number.
  *
  */
void Led_BlinkBackgroundRoutine_Control(int32_t BlinkRoutine, int8_t Enable, int32_t DutyCycle_ms, Led_TypeDef Led);

/**
  * Led_BlinkBackgroundRoutine0_Run - Function called by a task to toggle a led blinking or a delay.
  *
  * @param LoopDelayMs: Delay in case The Blinking is Off
  * @note Current WLAN applications call this in the StartUserTask, user can change.
  *
  */
void Led_BlinkBackgroundRoutine0_Run(int32_t LoopDelayMs);

/**
  * Led_BlinkBackgroundRoutine1_Run - Function called by a task to toggle a led blinking or a delay.
  *
  * @param LoopDelayMs: Delay in case The Blinking is Off
  * @note User should create a dedicated task for Routine1.
  *
  */
void Led_BlinkBackgroundRoutine1_Run(int32_t LoopDelayMs);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __UTIL_LED_PB_H_ */
