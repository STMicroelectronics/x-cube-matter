/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    app_freertos.c
  * @author  GPM Application Team
  * @brief   Code for freertos applications
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
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "app_freertos.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include "app_entry.h"
#include "app_config.h"
#include "utilities_conf.h"
#include "stm32_lpm.h"
#if (SYS_DBG_ENABLE_TA4 >= 1)
#include "trace_helper.h"
#endif  /* SYS_DBG_ENABLE_TA4 */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define configTICK_RATE_HZ_1MS                  1000

#ifndef configSYSTICK_CLOCK_HZ
/** Override the default SysTick clock rate */
#define configSYSTICK_CLOCK_HZ                  ( configCPU_CLOCK_HZ )

/** Ensure the SysTick is clocked at the same frequency as the core. */
#define portNVIC_SYSTICK_CLK_BIT                ( 1UL << 2UL )

#else
/** The way the SysTick is clocked is not modified in case it is not the same as the core. */
#define portNVIC_SYSTICK_CLK_BIT                ( 0 )

#endif /* configSYSTICK_CLOCK_HZ */

/* Constants required to manipulate the core.  Registers first... */
#define portNVIC_SYSTICK_CTRL_REG               ( * ( ( volatile uint32_t * ) 0xe000e010 ) )
#define portNVIC_SYSTICK_LOAD_REG               ( * ( ( volatile uint32_t * ) 0xe000e014 ) )
#define portNVIC_SYSTICK_CURRENT_VALUE_REG      ( * ( ( volatile uint32_t * ) 0xe000e018 ) )
#define portNVIC_SYSTICK_INT_BIT                ( 1UL << 1UL )
#define portNVIC_SYSTICK_ENABLE_BIT             ( 1UL << 0UL )

#define LPTIM_IDLE                              LPTIM1
#define LPTIM_IDLE_IRQn                         LPTIM1_IRQn

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
#if (LOW_POWER_MODE != LOW_POWER_DISABLE)
extern LPTIM_HandleTypeDef hlptim1;
static volatile uint16_t old_32k = 0;
static volatile uint16_t new_32k = 0;
static uint32_t ulTimerCountsForOneTick;
#endif /* LOW_POWER_MODE */

/* USER CODE END Variables */
/* Definitions for defaultTsk */
osThreadId_t defaultTskHandle;
const osThreadAttr_t defaultTsk_attributes = {
  .name = "defaultTsk",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 512 * 4
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
#if (LOW_POWER_MODE != LOW_POWER_DISABLE)
/**
  * @brief  start a timer for ms_to_sleep ms
  * @retval none
  */
static void LpTimer_StartIT(uint32_t ms_to_sleep);

/**
  * @brief  get_counter_value
  * @retval the counter
  */
static uint32_t LpTimer_GetCounter(void);

/**
  * @brief  stop a timer interrupt
  * @retval none
  */
static void LpTimer_StopIT(void);

/**
  * @brief  Get elapsed time
  * @param sysTickRem in SysTick
  * @retval value in milliseconds
  */
static uint32_t LpTimer_GetElapsedTime(uint32_t *sysTickRem);

/**
  * @brief  Convert time in ms to RTOS ticks
  * @param  value in milliseconds
  * @retval value in RTOS tick
  */
static uint32_t app_freertos_ms_to_tick(uint32_t ms);

/**
  * @brief  Convert time in RTOS ticks to ms
  * @param  value in RTOS tick
  * @retval value in milliseconds
  */
static uint32_t app_freertos_tick_to_ms(uint32_t tick);
#endif /* LOW_POWER_MODE */

/* USER CODE END FunctionPrototypes */

/* USER CODE BEGIN 5 */
void vApplicationMallocFailedHook(void)
{
   /* vApplicationMallocFailedHook() will only be called if
   configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h. It is a hook
   function that will get called if a call to pvPortMalloc() fails.
   pvPortMalloc() is called internally by the kernel whenever a task, queue,
   timer or semaphore is created. It is also called by various parts of the
   demo application. If heap_1.c or heap_2.c are used, then the size of the
   heap available to pvPortMalloc() is defined by configTOTAL_HEAP_SIZE in
   FreeRTOSConfig.h, and the xPortGetFreeHeapSize() API function can be used
   to query the size of free heap space that remains (although it does not
   provide information on how the remaining heap might be fragmented). */
  printf("Malloc failed ...\n");
}
/* USER CODE END 5 */

/* USER CODE BEGIN 2 */
void vApplicationIdleHook(void)
{
   /* vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set
   to 1 in FreeRTOSConfig.h. It will be called on each iteration of the idle
   task. It is essential that code added to this hook function never attempts
   to block in any way (for example, call xQueueReceive() with a block time
   specified, or call vTaskDelay()). If the application makes use of the
   vTaskDelete() API function (as this demo application does) then it is also
   important that vApplicationIdleHook() is permitted to return to its calling
   function, because it is the responsibility of the idle task to clean up
   memory allocated by the kernel to any task that has since been deleted. */
  /*
  size_t freeHeapSize = 0;
  size_t freeHeapSizeMin = 0;

  freeHeapSize = xPortGetFreeHeapSize();
  freeHeapSizeMin = xPortGetMinimumEverFreeHeapSize();
  */
}
/* USER CODE END 2 */

/* USER CODE BEGIN 4 */
void vApplicationStackOverflowHook(xTaskHandle xTask, char *pcTaskName)
{
   /* Run time stack overflow checking is performed if
   configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2. This hook function is
   called if a stack overflow is detected. */
  printf("Task %s stack overflow...\n", pcTaskName);
}
/* USER CODE END 4 */

/* USER CODE BEGIN 1 */
/* Functions needed when configGENERATE_RUN_TIME_STATS is on */
__weak void configureTimerForRunTimeStats(void)
{

}

__weak unsigned long getRunTimeCounterValue(void)
{
  return 0;
}

static uint32_t DisableSuppressTicksAndSleepBm;

void DisableSuppressTicksAndSleep(uint32_t bitmask)
{
  UTILS_ENTER_CRITICAL_SECTION();

  DisableSuppressTicksAndSleepBm |= bitmask;

  UTILS_EXIT_CRITICAL_SECTION();
}

void EnableSuppressTicksAndSleep(uint32_t bitmask)
{
  UTILS_ENTER_CRITICAL_SECTION();

  DisableSuppressTicksAndSleepBm  &= (~bitmask);

  UTILS_EXIT_CRITICAL_SECTION();
}

#if (LOW_POWER_MODE != LOW_POWER_DISABLE)
void vPortSetupTimerInterrupt(void);
void vPortSetupTimerInterrupt(void)
{
  /*Initialize DisableSuppressTicksAndSleepBm to 0*/
  DisableSuppressTicksAndSleepBm = 0 ;
  /* Calculate the constants required to configure the tick interrupt. */
  ulTimerCountsForOneTick = (configSYSTICK_CLOCK_HZ / configTICK_RATE_HZ);

  /* Stop and clear the SysTick. */
  portNVIC_SYSTICK_CTRL_REG = 0UL;
  portNVIC_SYSTICK_CURRENT_VALUE_REG = 0UL;

  /* Configure SysTick to interrupt at the requested rate. */
  portNVIC_SYSTICK_LOAD_REG = (configSYSTICK_CLOCK_HZ / configTICK_RATE_HZ) - 1UL;
  portNVIC_SYSTICK_CTRL_REG = (portNVIC_SYSTICK_CLK_BIT | portNVIC_SYSTICK_INT_BIT | portNVIC_SYSTICK_ENABLE_BIT);

  /* Start LPTIM counter*/
  LL_LPTIM_Enable(LPTIM_IDLE);
  LL_LPTIM_SetAutoReload(LPTIM_IDLE, 0xFFFF);
  while (LL_LPTIM_IsActiveFlag_ARROK(LPTIM_IDLE) != 1);
  LL_LPTIM_StartCounter(LPTIM_IDLE, LL_LPTIM_OPERATING_MODE_CONTINUOUS);
}
#endif /* LOW_POWER_MODE */

/* USER CODE END 1 */

/* USER CODE BEGIN VPORT_SUPPORT_TICKS_AND_SLEEP */
__weak void vPortSuppressTicksAndSleep(TickType_t xExpectedIdleTime)
{
#if (LOW_POWER_MODE != LOW_POWER_DISABLE)
  /* If low power is not used, do not stop the SysTick and continue execution */

  if (DisableSuppressTicksAndSleepBm == 0)
  {
    /**
      * Although this is not documented as such, when xExpectedIdleTime = 0xFFFFFFFF = (~0),
      * it likely means the system may enter low power for ever ( from a FreeRTOS point of view ).
      * Otherwise, for a FreeRTOS tick set to 1ms, that would mean it is requested to wakeup in 8 years from now.
      * When the system may enter low power mode for ever, FreeRTOS is not really interested to maintain a
      * systick count and when the system exits from low power mode, there is no need to update the count with
      * the time spent in low power mode
      */
    uint32_t ulCompleteTickPeriods;
    int32_t curSysTickValue = portNVIC_SYSTICK_CURRENT_VALUE_REG;

    /* Stop the SysTick  to avoid the interrupt to occur while in the critical section.
      * Otherwise, this will prevent the device to enter low power mode
      * At this time, an update of the systick will not be considered
      *
      */
    portNVIC_SYSTICK_CTRL_REG &= ~portNVIC_SYSTICK_ENABLE_BIT;

    /* Enter a critical section but don't use the taskENTER_CRITICAL()
          method as that will mask interrupts that should exit sleep mode. */
    __disable_irq();
    __DSB();
    __ISB();

    /* If a context switch is pending or a task is waiting for the scheduler
          to be unsuspended then abandon the low power entry. */
    if (eTaskConfirmSleepModeStatus() == eAbortSleep)
    {
      /* Restart SysTick. */
      portNVIC_SYSTICK_CTRL_REG |= portNVIC_SYSTICK_ENABLE_BIT;

      /* Re-enable interrupts - see comments above __disable_interrupt()
                  call above. */
      __enable_irq();
    }
    else
    {
      if (xExpectedIdleTime != (~0))
      {
        /* Remove one tick to wake up before the event occurs */
        xExpectedIdleTime -= 1;
        /* Start the low power timer */
        LpTimer_StartIT(app_freertos_tick_to_ms(xExpectedIdleTime));
      }

      /* Enter low power mode */
      UTIL_LPM_EnterLowPower();

      if (xExpectedIdleTime != (~0))
      {
        /**
          * Get the number of FreeRTOS ticks that has been suppressed
          * In the current implementation, this shall be kept in critical section
          * so that the timer returns the correct elapsed time
          */
        uint32_t sysTickRem = 0;

        ulCompleteTickPeriods = app_freertos_ms_to_tick(LpTimer_GetElapsedTime(&sysTickRem));

        curSysTickValue -= sysTickRem;

        if (curSysTickValue < 0)
        {
          ulCompleteTickPeriods++;
          curSysTickValue += ulTimerCountsForOneTick;
        }

        vTaskStepTick(ulCompleteTickPeriods);
        LpTimer_StopIT();
      }

      /* Restart SysTick */
      /* the 3 raws below are to force the systick counter to portNVIC_SYSTICK_CURRENT_VALUE_REG = curSysTickValue; */
      portNVIC_SYSTICK_LOAD_REG = curSysTickValue;
      portNVIC_SYSTICK_CURRENT_VALUE_REG = 0;
      portNVIC_SYSTICK_CTRL_REG |= portNVIC_SYSTICK_ENABLE_BIT;
      /*update the load reg back to ulTimerCountsForOneTick*/
      portNVIC_SYSTICK_LOAD_REG = ulTimerCountsForOneTick - 1UL;

      /* Exit with interrupts enabled. */
      __enable_irq();
    }
  }
#endif /* LOW_POWER_MODE */
}
/* USER CODE END VPORT_SUPPORT_TICKS_AND_SLEEP */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
#if (SYS_DBG_ENABLE_TA4 >= 1)
  /*Initialise the trace recorder library*/
  xTraceInitialize();
  trace_init();
#endif  /* SYS_DBG_ENABLE_TA4 */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */
  /* creation of defaultTsk */
  defaultTskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTsk_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}
/* USER CODE BEGIN Header_StartDefaultTask */
/**
* @brief Function implementing the defaultTsk thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN defaultTsk */
  app_init();
  vTaskDelete( defaultTskHandle );
  /* Infinite loop */
  for (;;)
  {
    osDelay(1000);
  }
  /* USER CODE END defaultTsk */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
#if (LOW_POWER_MODE != LOW_POWER_DISABLE)
static void LpTimer_StartIT(uint32_t ms_to_sleep)
{
  uint16_t timeout = (uint16_t)((ms_to_sleep << 15) / 1000);

  old_32k = LpTimer_GetCounter();

  timeout += old_32k; /*intentional wrap*/
  /* account for 2 32k period delay of LL_LPTIM_OC_SetCompareCH1 +1 for*/
  timeout -= 3; /*intentional wrap*/

  if (timeout > UINT16_MAX - 10)
  {
    timeout = UINT16_MAX - 10;
  }

  LL_LPTIM_ClearFlag_CMP1OK(LPTIM_IDLE);
  LL_LPTIM_OC_SetCompareCH1(LPTIM_IDLE, timeout);
  /* Wait Compare Value is set*/
  while (LL_LPTIM_IsActiveFlag_CMP1OK(LPTIM_IDLE) != 1);

  LL_LPTIM_ClearFlag_DIEROK(LPTIM_IDLE);
  LL_LPTIM_EnableIT_CC1(LPTIM_IDLE);
  /* Wait for the completion of the write operation to the LPTIM_DIER register */
  while (LL_LPTIM_IsActiveFlag_DIEROK(LPTIM_IDLE) != 1);

  HAL_NVIC_EnableIRQ(LPTIM_IDLE_IRQn);
}

static void LpTimer_StopIT(void)
{
  LL_LPTIM_ClearFlag_DIEROK(LPTIM_IDLE);
  /* Disable CC1 IT*/
  LL_LPTIM_DisableIT_CC1(LPTIM_IDLE);
  /* Wait Interrupt is reset*/
  while (LL_LPTIM_IsActiveFlag_DIEROK(LPTIM_IDLE) != 1)

    /* clear Active Flag if set*/
    if (LL_LPTIM_IsActiveFlag_CC1(LPTIM_IDLE) == 1)
    {
      LL_LPTIM_ClearFLAG_CC1(LPTIM_IDLE);
    }
  /* wait flag is cleared*/
  /* Clear  NVIC pending LTPIM1 IRQ*/
  HAL_NVIC_ClearPendingIRQ(LPTIM_IDLE_IRQn);

  if (HAL_NVIC_GetPendingIRQ(LPTIM_IDLE_IRQn))
  {
    while (1);
  }
}

/* in ms*/
static uint32_t LpTimer_GetElapsedTime(uint32_t *sysTickRem)
{
  new_32k = LpTimer_GetCounter();

  uint32_t elapsed32k = (uint16_t)(new_32k - old_32k);
  uint32_t elapsedms = (elapsed32k * 1000) >> 15;
  uint32_t remainder = elapsed32k * 1000 - (elapsedms << 15);
  remainder = (remainder * ulTimerCountsForOneTick) >> 15;

  *sysTickRem = remainder;

  return elapsedms;
}

static uint32_t LpTimer_GetCounter(void)
{
  uint32_t cnt = 0;
  /*Read until 2 consecutive identical read */
  do
  {
    cnt =  LL_LPTIM_GetCounter(LPTIM_IDLE);
  } while (cnt != LL_LPTIM_GetCounter(LPTIM_IDLE));

  return cnt;
}

void HAL_LPTIM_CompareMatchCallback(LPTIM_HandleTypeDef *hlptim)
{
  if (hlptim == &hlptim1)
  {
    /* Nothing to do*/
  }
}

static uint32_t app_freertos_ms_to_tick(uint32_t ms)
{
  uint32_t tick = ms;
  if (configTICK_RATE_HZ != configTICK_RATE_HZ_1MS)
  {
    tick = (uint32_t)((((uint64_t)(ms)) * configTICK_RATE_HZ) / configTICK_RATE_HZ_1MS);
  }
  return tick;
}

static uint32_t app_freertos_tick_to_ms(uint32_t tick)
{
  uint32_t ms = tick;
  if (configTICK_RATE_HZ != configTICK_RATE_HZ_1MS)
  {
    ms = (uint32_t)((((uint64_t)(tick)) * configTICK_RATE_HZ_1MS) / configTICK_RATE_HZ);
  }
  return ms;
}
#endif /* LOW_POWER_MODE */
/* USER CODE END Application */

