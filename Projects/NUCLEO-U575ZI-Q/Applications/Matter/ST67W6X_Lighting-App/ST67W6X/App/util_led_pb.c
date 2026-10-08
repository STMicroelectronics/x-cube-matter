/**
  ******************************************************************************
  * @file    util_led_pb.c
  * @author  GPM Application Team
  * @brief   Implements Led and PushButton services
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
#include "util_led_pb.h"
#include "main.h"
#include "stm32u5xx_hal.h"
#include "stm32u5xx_hal_gpio.h"
#include "stm32u5xx_ll_gpio.h"

/* Private variables ---------------------------------------------------------*/
static __IO uint8_t button_flags = 0;

static int8_t BlinkBgTask_Enable[BLINKTASK_NB] = {BBR_LOOPDELAY, BBR_LOOPDELAY};
static int32_t  BlinkBgTask_DutyCYcleMs[BLINKTASK_NB] = {500, 500};
static Led_TypeDef BlinkBgTask_Led[BLINKTASK_NB] = {LED1, LED2};

static GPIO_TypeDef  *LED_PORT[LED_NB] = {LED_GREEN_GPIO_Port, LED_BLUE_GPIO_Port, LED_RED_GPIO_Port};

static const uint16_t LED_PIN[LED_NB] = {LED_GREEN_Pin, LED_BLUE_Pin, LED_RED_Pin};

/* Private function prototypes -----------------------------------------------*/
static void Button_ISR(void);

/* Functions Definition ------------------------------------------------------*/
/**
  * @brief  EXTI line detection callback.
  * @param  GPIO_Pin: Specifies the port pin connected to corresponding EXTI line.
  * @retval None
  */
void Button_Falling_Callback(void)
{
  Button_ISR();
}

/**
  * @brief Update button ISR status
  */
static void Button_ISR(void)
{
  button_flags++;
}

/**
  * @brief Waiting for button to be pushed
  */
uint8_t Button_WaitForPush(uint32_t delay)
{
  uint32_t time_out = HAL_GetTick() + delay;

  do
  {
    if (button_flags > 1)
    {
      HAL_Delay(100);
      button_flags = 0;
      return BP_MULTIPLE_PUSH;
    }

    if (button_flags == 1)
    {
      HAL_Delay(100);
      button_flags = 0;
      return BP_SINGLE_PUSH;
    }
  } while (HAL_GetTick() < time_out);

  return BP_NOT_PUSHED;
}

/**
  * @brief Waiting for button to be pushed
  */
uint8_t Button_WaitForMultiPush(uint32_t delay)
{
  HAL_Delay(delay);
  if (button_flags > 1)
  {
    button_flags = 0;
    return BP_MULTIPLE_PUSH;
  }

  if (button_flags == 1)
  {
    button_flags = 0;
    return BP_SINGLE_PUSH;
  }
  return BP_NOT_PUSHED;
}

/**
  * @brief Set LED state
  */
void Led_SetState(bool on, Led_TypeDef Led)
{
  if (on == true)
  {
    LL_GPIO_SetOutputPin(LED_PORT[Led], LED_PIN[Led]);
  }
  else
  {
    LL_GPIO_ResetOutputPin(LED_PORT[Led], LED_PIN[Led]);
  }
}

/**
  * @brief Blink LED for 'count' cycles of 'period' period and 'duty' ON duration.
  * duty < 0 tells to start with an OFF state.
  */
void Led_Blink_N_Times(int32_t period, int32_t duty, int32_t count, Led_TypeDef Led)
{
  if ((duty > 0) && (period >= duty))
  {
    /*  Shape:   ____
                  on |_off__ */
    do
    {
      Led_SetState(true, Led);
      osDelay(duty);
      Led_SetState(false, Led);
      osDelay(period - duty);
    } while (count--);
  }
  if ((duty < 0) && (period >= -duty))
  {
    /*  Shape:         ____
                __off_| on   */
    do
    {
      Led_SetState(false, Led);
      osDelay(period + duty);
      Led_SetState(true, Led);
      osDelay(-duty);
    } while (count--);
  }
}

/* ===================================================== */
/* Generic BackGround Led Blinking typically on OS tasks */
/* ===================================================== */

void Led_BlinkBackgroundRoutine_Control(int32_t BlinkRoutine, int8_t Enable, int32_t DutyCycle_ms, Led_TypeDef Led)
{
  BlinkBgTask_Enable[BlinkRoutine] = Enable;
  BlinkBgTask_DutyCYcleMs[BlinkRoutine] = DutyCycle_ms;
  BlinkBgTask_Led[BlinkRoutine] = Led;
}

void Led_BlinkBackgroundRoutine0_Run(int32_t LoopDelayMs)
{
  if (BlinkBgTask_Enable[BBR0] == BBR_ENABLE)
  {
    LL_GPIO_TogglePin(LED_PORT[BlinkBgTask_Led[BBR0]], LED_PIN[BlinkBgTask_Led[BBR0]]);
    osDelay(BlinkBgTask_DutyCYcleMs[BBR0]);
  }
  else if (BlinkBgTask_Enable[BBR0] == BBR_DISABLE)
  {
    LL_GPIO_ResetOutputPin(LED_PORT[BlinkBgTask_Led[BBR0]], LED_PIN[BlinkBgTask_Led[BBR0]]);
    BlinkBgTask_Enable[BBR0] = BBR_LOOPDELAY;
  }
  else
  {
    osDelay(LoopDelayMs);
  }
}

void Led_BlinkBackgroundRoutine1_Run(int32_t LoopDelayMs)
{
  if (BlinkBgTask_Enable[BBR1] == BBR_ENABLE)
  {
    LL_GPIO_TogglePin(LED_PORT[BlinkBgTask_Led[BBR1]], LED_PIN[BlinkBgTask_Led[BBR1]]);
    osDelay(BlinkBgTask_DutyCYcleMs[BBR1]);
  }
  else if (BlinkBgTask_Enable[BBR1] == BBR_DISABLE)
  {
    LL_GPIO_ResetOutputPin(LED_PORT[BlinkBgTask_Led[BBR1]], LED_PIN[BlinkBgTask_Led[BBR1]]);
    BlinkBgTask_Enable[BBR1] = BBR_LOOPDELAY;
  }
  else
  {
    osDelay(LoopDelayMs);
  }
}
