typedef enum
{
  Reset_IRQn = -15,
  NonMaskableInt_IRQn = -14,
  HardFault_IRQn = -13,
  MemoryManagement_IRQn = -12,
  BusFault_IRQn = -11,
  UsageFault_IRQn = -10,
  SecureFault_IRQn = -9,
  SVCall_IRQn = -5,
  DebugMonitor_IRQn = -4,
  PendSV_IRQn = -2,
  SysTick_IRQn = -1,
  WWDG_IRQn = 0,
  PVD_PVM_IRQn = 1,
  RTC_IRQn = 2,
  RTC_S_IRQn = 3,
  TAMP_IRQn = 4,
  RAMCFG_IRQn = 5,
  FLASH_IRQn = 6,
  FLASH_S_IRQn = 7,
  GTZC_IRQn = 8,
  RCC_IRQn = 9,
  RCC_S_IRQn = 10,
  EXTI0_IRQn = 11,
  EXTI1_IRQn = 12,
  EXTI2_IRQn = 13,
  EXTI3_IRQn = 14,
  EXTI4_IRQn = 15,
  EXTI5_IRQn = 16,
  EXTI6_IRQn = 17,
  EXTI7_IRQn = 18,
  EXTI8_IRQn = 19,
  EXTI9_IRQn = 20,
  EXTI10_IRQn = 21,
  EXTI11_IRQn = 22,
  EXTI12_IRQn = 23,
  EXTI13_IRQn = 24,
  EXTI14_IRQn = 25,
  EXTI15_IRQn = 26,
  IWDG_IRQn = 27,
  GPDMA1_Channel0_IRQn = 29,
  GPDMA1_Channel1_IRQn = 30,
  GPDMA1_Channel2_IRQn = 31,
  GPDMA1_Channel3_IRQn = 32,
  GPDMA1_Channel4_IRQn = 33,
  GPDMA1_Channel5_IRQn = 34,
  GPDMA1_Channel6_IRQn = 35,
  GPDMA1_Channel7_IRQn = 36,
  ADC1_IRQn = 37,
  DAC1_IRQn = 38,
  FDCAN1_IT0_IRQn = 39,
  FDCAN1_IT1_IRQn = 40,
  TIM1_BRK_IRQn = 41,
  TIM1_UP_IRQn = 42,
  TIM1_TRG_COM_IRQn = 43,
  TIM1_CC_IRQn = 44,
  TIM2_IRQn = 45,
  TIM3_IRQn = 46,
  TIM4_IRQn = 47,
  TIM5_IRQn = 48,
  TIM6_IRQn = 49,
  TIM7_IRQn = 50,
  TIM8_BRK_IRQn = 51,
  TIM8_UP_IRQn = 52,
  TIM8_TRG_COM_IRQn = 53,
  TIM8_CC_IRQn = 54,
  I2C1_EV_IRQn = 55,
  I2C1_ER_IRQn = 56,
  I2C2_EV_IRQn = 57,
  I2C2_ER_IRQn = 58,
  SPI1_IRQn = 59,
  SPI2_IRQn = 60,
  USART1_IRQn = 61,
  USART2_IRQn = 62,
  USART3_IRQn = 63,
  UART4_IRQn = 64,
  UART5_IRQn = 65,
  LPUART1_IRQn = 66,
  LPTIM1_IRQn = 67,
  LPTIM2_IRQn = 68,
  TIM15_IRQn = 69,
  TIM16_IRQn = 70,
  TIM17_IRQn = 71,
  COMP_IRQn = 72,
  OTG_FS_IRQn = 73,
  CRS_IRQn = 74,
  FMC_IRQn = 75,
  OCTOSPI1_IRQn = 76,
  PWR_S3WU_IRQn = 77,
  SDMMC1_IRQn = 78,
  SDMMC2_IRQn = 79,
  GPDMA1_Channel8_IRQn = 80,
  GPDMA1_Channel9_IRQn = 81,
  GPDMA1_Channel10_IRQn = 82,
  GPDMA1_Channel11_IRQn = 83,
  GPDMA1_Channel12_IRQn = 84,
  GPDMA1_Channel13_IRQn = 85,
  GPDMA1_Channel14_IRQn = 86,
  GPDMA1_Channel15_IRQn = 87,
  I2C3_EV_IRQn = 88,
  I2C3_ER_IRQn = 89,
  SAI1_IRQn = 90,
  SAI2_IRQn = 91,
  TSC_IRQn = 92,
  RNG_IRQn = 94,
  FPU_IRQn = 95,
  HASH_IRQn = 96,
  LPTIM3_IRQn = 98,
  SPI3_IRQn = 99,
  I2C4_ER_IRQn = 100,
  I2C4_EV_IRQn = 101,
  MDF1_FLT0_IRQn = 102,
  MDF1_FLT1_IRQn = 103,
  MDF1_FLT2_IRQn = 104,
  MDF1_FLT3_IRQn = 105,
  UCPD1_IRQn = 106,
  ICACHE_IRQn = 107,
  LPTIM4_IRQn = 110,
  DCACHE1_IRQn = 111,
  ADF1_IRQn = 112,
  ADC4_IRQn = 113,
  LPDMA1_Channel0_IRQn = 114,
  LPDMA1_Channel1_IRQn = 115,
  LPDMA1_Channel2_IRQn = 116,
  LPDMA1_Channel3_IRQn = 117,
  DMA2D_IRQn = 118,
  DCMI_PSSI_IRQn = 119,
  OCTOSPI2_IRQn = 120,
  MDF1_FLT4_IRQn = 121,
  MDF1_FLT5_IRQn = 122,
  CORDIC_IRQn = 123,
  FMAC_IRQn = 124,
  LSECSSD_IRQn = 125,
} IRQn_Type;
#pragma GCC diagnostic ignored "-Wpedantic"
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef short int __int16_t;
typedef short unsigned int __uint16_t;
typedef long int __int32_t;
typedef long unsigned int __uint32_t;
typedef long long int __int64_t;
typedef long long unsigned int __uint64_t;
typedef signed char __int_least8_t;
typedef unsigned char __uint_least8_t;
typedef short int __int_least16_t;
typedef short unsigned int __uint_least16_t;
typedef long int __int_least32_t;
typedef long unsigned int __uint_least32_t;
typedef long long int __int_least64_t;
typedef long long unsigned int __uint_least64_t;
typedef long long int __intmax_t;
typedef long long unsigned int __uintmax_t;
typedef int __intptr_t;
typedef unsigned int __uintptr_t;
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
typedef __int8_t int8_t ;
typedef __uint8_t uint8_t ;
typedef __int16_t int16_t ;
typedef __uint16_t uint16_t ;
typedef __int32_t int32_t ;
typedef __uint32_t uint32_t ;
typedef __int64_t int64_t ;
typedef __uint64_t uint64_t ;
typedef __intmax_t intmax_t;
typedef __uintmax_t uintmax_t;
typedef __intptr_t intptr_t;
typedef __uintptr_t uintptr_t;
typedef __int_least8_t int_least8_t;
typedef __uint_least8_t uint_least8_t;
typedef __int_least16_t int_least16_t;
typedef __uint_least16_t uint_least16_t;
typedef __int_least32_t int_least32_t;
typedef __uint_least32_t uint_least32_t;
typedef __int_least64_t int_least64_t;
typedef __uint_least64_t uint_least64_t;
  typedef int int_fast8_t;
  typedef unsigned int uint_fast8_t;
  typedef int int_fast16_t;
  typedef unsigned int uint_fast16_t;
  typedef int int_fast32_t;
  typedef unsigned int uint_fast32_t;
  typedef long long int int_fast64_t;
  typedef long long unsigned int uint_fast64_t;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpacked"
#pragma GCC diagnostic ignored "-Wattributes"
  struct __attribute__((packed)) T_UINT32 { uint32_t v; };
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpacked"
#pragma GCC diagnostic ignored "-Wattributes"
  struct __attribute__((packed, aligned(1))) T_UINT16_WRITE { uint16_t v; };
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpacked"
#pragma GCC diagnostic ignored "-Wattributes"
  struct __attribute__((packed, aligned(1))) T_UINT16_READ { uint16_t v; };
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpacked"
#pragma GCC diagnostic ignored "-Wattributes"
  struct __attribute__((packed, aligned(1))) T_UINT32_WRITE { uint32_t v; };
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpacked"
#pragma GCC diagnostic ignored "-Wattributes"
  struct __attribute__((packed, aligned(1))) T_UINT32_READ { uint32_t v; };
#pragma GCC diagnostic pop
__attribute__((always_inline)) static inline __attribute__((__noreturn__)) void __cmsis_start(void)
{
  extern void _start(void) __attribute__((__noreturn__));
  typedef struct {
    uint32_t const* src;
    uint32_t* dest;
    uint32_t wlen;
  } __copy_table_t;
  typedef struct {
    uint32_t* dest;
    uint32_t wlen;
  } __zero_table_t;
  extern const __copy_table_t __copy_table_start__;
  extern const __copy_table_t __copy_table_end__;
  extern const __zero_table_t __zero_table_start__;
  extern const __zero_table_t __zero_table_end__;
  for (__copy_table_t const* pTable = &__copy_table_start__; pTable < &__copy_table_end__; ++pTable) {
    for(uint32_t i=0u; i<pTable->wlen; ++i) {
      pTable->dest[i] = pTable->src[i];
    }
  }
  for (__zero_table_t const* pTable = &__zero_table_start__; pTable < &__zero_table_end__; ++pTable) {
    for(uint32_t i=0u; i<pTable->wlen; ++i) {
      pTable->dest[i] = 0u;
    }
  }
  _start();
}
__attribute__((always_inline)) static inline void __ISB(void)
{
  __asm volatile ("isb 0xF":::"memory");
}
__attribute__((always_inline)) static inline void __DSB(void)
{
  __asm volatile ("dsb 0xF":::"memory");
}
__attribute__((always_inline)) static inline void __DMB(void)
{
  __asm volatile ("dmb 0xF":::"memory");
}
__attribute__((always_inline)) static inline uint32_t __REV(uint32_t value)
{
  return __builtin_bswap32(value);
}
__attribute__((always_inline)) static inline uint32_t __REV16(uint32_t value)
{
  uint32_t result;
  __asm ("rev16 %0, %1" : "=r" (result) : "r" (value) );
  return result;
}
__attribute__((always_inline)) static inline int16_t __REVSH(int16_t value)
{
  return (int16_t)__builtin_bswap16(value);
}
__attribute__((always_inline)) static inline uint32_t __ROR(uint32_t op1, uint32_t op2)
{
  op2 %= 32U;
  if (op2 == 0U)
  {
    return op1;
  }
  return (op1 >> op2) | (op1 << (32U - op2));
}
__attribute__((always_inline)) static inline uint32_t __RBIT(uint32_t value)
{
  uint32_t result;
  uint32_t s = (4U * 8U) - 1U;
  result = value;
  for (value >>= 1U; value != 0U; value >>= 1U)
  {
    result <<= 1U;
    result |= value & 1U;
    s--;
  }
  result <<= s;
  return result;
}
__attribute__((always_inline)) static inline uint8_t __CLZ(uint32_t value)
{
  if (value == 0U)
  {
    return 32U;
  }
  return __builtin_clz(value);
}
__attribute__((always_inline)) static inline int32_t __SSAT(int32_t val, uint32_t sat)
{
  if ((sat >= 1U) && (sat <= 32U))
  {
    const int32_t max = (int32_t)((1U << (sat - 1U)) - 1U);
    const int32_t min = -1 - max ;
    if (val > max)
    {
      return max;
    }
    else if (val < min)
    {
      return min;
    }
  }
  return val;
}
__attribute__((always_inline)) static inline uint32_t __USAT(int32_t val, uint32_t sat)
{
  if (sat <= 31U)
  {
    const uint32_t max = ((1U << sat) - 1U);
    if (val > (int32_t)max)
    {
      return max;
    }
    else if (val < 0)
    {
      return 0U;
    }
  }
  return (uint32_t)val;
}
__attribute__((always_inline)) static inline void __enable_irq(void)
{
  __asm volatile ("cpsie i" : : : "memory");
}
__attribute__((always_inline)) static inline void __disable_irq(void)
{
  __asm volatile ("cpsid i" : : : "memory");
}
__attribute__((always_inline)) static inline uint32_t __get_CONTROL(void)
{
  uint32_t result;
  __asm volatile ("MRS %0, control" : "=r" (result) );
  return(result);
}
__attribute__((always_inline)) static inline void __set_CONTROL(uint32_t control)
{
  __asm volatile ("MSR control, %0" : : "r" (control) : "memory");
  __ISB();
}
__attribute__((always_inline)) static inline uint32_t __get_IPSR(void)
{
  uint32_t result;
  __asm volatile ("MRS %0, ipsr" : "=r" (result) );
  return(result);
}
__attribute__((always_inline)) static inline uint32_t __get_APSR(void)
{
  uint32_t result;
  __asm volatile ("MRS %0, apsr" : "=r" (result) );
  return(result);
}
__attribute__((always_inline)) static inline uint32_t __get_xPSR(void)
{
  uint32_t result;
  __asm volatile ("MRS %0, xpsr" : "=r" (result) );
  return(result);
}
__attribute__((always_inline)) static inline uint32_t __get_PSP(void)
{
  uint32_t result;
  __asm volatile ("MRS %0, psp" : "=r" (result) );
  return(result);
}
__attribute__((always_inline)) static inline void __set_PSP(uint32_t topOfProcStack)
{
  __asm volatile ("MSR psp, %0" : : "r" (topOfProcStack) : );
}
__attribute__((always_inline)) static inline uint32_t __get_MSP(void)
{
  uint32_t result;
  __asm volatile ("MRS %0, msp" : "=r" (result) );
  return(result);
}
__attribute__((always_inline)) static inline void __set_MSP(uint32_t topOfMainStack)
{
  __asm volatile ("MSR msp, %0" : : "r" (topOfMainStack) : );
}
__attribute__((always_inline)) static inline uint32_t __get_PRIMASK(void)
{
  uint32_t result;
  __asm volatile ("MRS %0, primask" : "=r" (result) );
  return(result);
}
__attribute__((always_inline)) static inline void __set_PRIMASK(uint32_t priMask)
{
  __asm volatile ("MSR primask, %0" : : "r" (priMask) : "memory");
}
__attribute__((always_inline)) static inline uint32_t __get_FPSCR(void)
{
  return(0U);
}
__attribute__((always_inline)) static inline void __set_FPSCR(uint32_t fpscr)
{
  (void)fpscr;
}
#pragma GCC diagnostic pop
typedef union
{
  struct
  {
    uint32_t _reserved0:16;
    uint32_t GE:4;
    uint32_t _reserved1:7;
    uint32_t Q:1;
    uint32_t V:1;
    uint32_t C:1;
    uint32_t Z:1;
    uint32_t N:1;
  } b;
  uint32_t w;
} APSR_Type;
typedef union
{
  struct
  {
    uint32_t ISR:9;
    uint32_t _reserved0:23;
  } b;
  uint32_t w;
} IPSR_Type;
typedef union
{
  struct
  {
    uint32_t ISR:9;
    uint32_t _reserved0:7;
    uint32_t GE:4;
    uint32_t _reserved1:4;
    uint32_t T:1;
    uint32_t IT:2;
    uint32_t Q:1;
    uint32_t V:1;
    uint32_t C:1;
    uint32_t Z:1;
    uint32_t N:1;
  } b;
  uint32_t w;
} xPSR_Type;
typedef union
{
  struct
  {
    uint32_t nPRIV:1;
    uint32_t SPSEL:1;
    uint32_t FPCA:1;
    uint32_t SFPA:1;
    uint32_t _reserved1:28;
  } b;
  uint32_t w;
} CONTROL_Type;
typedef struct
{
  volatile uint32_t ISER[16U];
        uint32_t RESERVED0[16U];
  volatile uint32_t ICER[16U];
        uint32_t RSERVED1[16U];
  volatile uint32_t ISPR[16U];
        uint32_t RESERVED2[16U];
  volatile uint32_t ICPR[16U];
        uint32_t RESERVED3[16U];
  volatile uint32_t IABR[16U];
        uint32_t RESERVED4[16U];
  volatile uint32_t ITNS[16U];
        uint32_t RESERVED5[16U];
  volatile uint8_t IPR[496U];
        uint32_t RESERVED6[580U];
  volatile uint32_t STIR;
} NVIC_Type;
typedef struct
{
  volatile const uint32_t CPUID;
  volatile uint32_t ICSR;
  volatile uint32_t VTOR;
  volatile uint32_t AIRCR;
  volatile uint32_t SCR;
  volatile uint32_t CCR;
  volatile uint8_t SHPR[12U];
  volatile uint32_t SHCSR;
  volatile uint32_t CFSR;
  volatile uint32_t HFSR;
  volatile uint32_t DFSR;
  volatile uint32_t MMFAR;
  volatile uint32_t BFAR;
  volatile uint32_t AFSR;
  volatile const uint32_t ID_PFR[2U];
  volatile const uint32_t ID_DFR;
  volatile const uint32_t ID_AFR;
  volatile const uint32_t ID_MMFR[4U];
  volatile const uint32_t ID_ISAR[6U];
  volatile const uint32_t CLIDR;
  volatile const uint32_t CTR;
  volatile const uint32_t CCSIDR;
  volatile uint32_t CSSELR;
  volatile uint32_t CPACR;
  volatile uint32_t NSACR;
        uint32_t RESERVED7[21U];
  volatile uint32_t SFSR;
  volatile uint32_t SFAR;
        uint32_t RESERVED3[69U];
  volatile uint32_t STIR;
        uint32_t RESERVED4[15U];
  volatile const uint32_t MVFR0;
  volatile const uint32_t MVFR1;
  volatile const uint32_t MVFR2;
        uint32_t RESERVED5[1U];
  volatile uint32_t ICIALLU;
        uint32_t RESERVED6[1U];
  volatile uint32_t ICIMVAU;
  volatile uint32_t DCIMVAC;
  volatile uint32_t DCISW;
  volatile uint32_t DCCMVAU;
  volatile uint32_t DCCMVAC;
  volatile uint32_t DCCSW;
  volatile uint32_t DCCIMVAC;
  volatile uint32_t DCCISW;
  volatile uint32_t BPIALL;
} SCB_Type;
typedef struct
{
        uint32_t RESERVED0[1U];
  volatile const uint32_t ICTR;
  volatile uint32_t ACTLR;
  volatile uint32_t CPPWR;
} SCnSCB_Type;
typedef struct
{
  volatile uint32_t CTRL;
  volatile uint32_t LOAD;
  volatile uint32_t VAL;
  volatile const uint32_t CALIB;
} SysTick_Type;
typedef struct
{
  volatile union
  {
    volatile uint8_t u8;
    volatile uint16_t u16;
    volatile uint32_t u32;
  } PORT [32U];
        uint32_t RESERVED0[864U];
  volatile uint32_t TER;
        uint32_t RESERVED1[15U];
  volatile uint32_t TPR;
        uint32_t RESERVED2[15U];
  volatile uint32_t TCR;
        uint32_t RESERVED3[32U];
        uint32_t RESERVED4[43U];
  volatile uint32_t LAR;
  volatile const uint32_t LSR;
        uint32_t RESERVED5[1U];
  volatile const uint32_t DEVARCH;
        uint32_t RESERVED6[4U];
  volatile const uint32_t PID4;
  volatile const uint32_t PID5;
  volatile const uint32_t PID6;
  volatile const uint32_t PID7;
  volatile const uint32_t PID0;
  volatile const uint32_t PID1;
  volatile const uint32_t PID2;
  volatile const uint32_t PID3;
  volatile const uint32_t CID0;
  volatile const uint32_t CID1;
  volatile const uint32_t CID2;
  volatile const uint32_t CID3;
} ITM_Type;
typedef struct
{
  volatile uint32_t CTRL;
  volatile uint32_t CYCCNT;
  volatile uint32_t CPICNT;
  volatile uint32_t EXCCNT;
  volatile uint32_t SLEEPCNT;
  volatile uint32_t LSUCNT;
  volatile uint32_t FOLDCNT;
  volatile const uint32_t PCSR;
  volatile uint32_t COMP0;
        uint32_t RESERVED1[1U];
  volatile uint32_t FUNCTION0;
        uint32_t RESERVED2[1U];
  volatile uint32_t COMP1;
        uint32_t RESERVED3[1U];
  volatile uint32_t FUNCTION1;
        uint32_t RESERVED4[1U];
  volatile uint32_t COMP2;
        uint32_t RESERVED5[1U];
  volatile uint32_t FUNCTION2;
        uint32_t RESERVED6[1U];
  volatile uint32_t COMP3;
        uint32_t RESERVED7[1U];
  volatile uint32_t FUNCTION3;
        uint32_t RESERVED8[1U];
  volatile uint32_t COMP4;
        uint32_t RESERVED9[1U];
  volatile uint32_t FUNCTION4;
        uint32_t RESERVED10[1U];
  volatile uint32_t COMP5;
        uint32_t RESERVED11[1U];
  volatile uint32_t FUNCTION5;
        uint32_t RESERVED12[1U];
  volatile uint32_t COMP6;
        uint32_t RESERVED13[1U];
  volatile uint32_t FUNCTION6;
        uint32_t RESERVED14[1U];
  volatile uint32_t COMP7;
        uint32_t RESERVED15[1U];
  volatile uint32_t FUNCTION7;
        uint32_t RESERVED16[1U];
  volatile uint32_t COMP8;
        uint32_t RESERVED17[1U];
  volatile uint32_t FUNCTION8;
        uint32_t RESERVED18[1U];
  volatile uint32_t COMP9;
        uint32_t RESERVED19[1U];
  volatile uint32_t FUNCTION9;
        uint32_t RESERVED20[1U];
  volatile uint32_t COMP10;
        uint32_t RESERVED21[1U];
  volatile uint32_t FUNCTION10;
        uint32_t RESERVED22[1U];
  volatile uint32_t COMP11;
        uint32_t RESERVED23[1U];
  volatile uint32_t FUNCTION11;
        uint32_t RESERVED24[1U];
  volatile uint32_t COMP12;
        uint32_t RESERVED25[1U];
  volatile uint32_t FUNCTION12;
        uint32_t RESERVED26[1U];
  volatile uint32_t COMP13;
        uint32_t RESERVED27[1U];
  volatile uint32_t FUNCTION13;
        uint32_t RESERVED28[1U];
  volatile uint32_t COMP14;
        uint32_t RESERVED29[1U];
  volatile uint32_t FUNCTION14;
        uint32_t RESERVED30[1U];
  volatile uint32_t COMP15;
        uint32_t RESERVED31[1U];
  volatile uint32_t FUNCTION15;
        uint32_t RESERVED32[934U];
  volatile const uint32_t LSR;
        uint32_t RESERVED33[1U];
  volatile const uint32_t DEVARCH;
} DWT_Type;
typedef struct
{
  volatile const uint32_t SSPSR;
  volatile uint32_t CSPSR;
        uint32_t RESERVED0[2U];
  volatile uint32_t ACPR;
        uint32_t RESERVED1[55U];
  volatile uint32_t SPPR;
        uint32_t RESERVED2[131U];
  volatile const uint32_t FFSR;
  volatile uint32_t FFCR;
  volatile uint32_t PSCR;
        uint32_t RESERVED3[759U];
  volatile const uint32_t TRIGGER;
  volatile const uint32_t ITFTTD0;
  volatile uint32_t ITATBCTR2;
        uint32_t RESERVED4[1U];
  volatile const uint32_t ITATBCTR0;
  volatile const uint32_t ITFTTD1;
  volatile uint32_t ITCTRL;
        uint32_t RESERVED5[39U];
  volatile uint32_t CLAIMSET;
  volatile uint32_t CLAIMCLR;
        uint32_t RESERVED7[8U];
  volatile const uint32_t DEVID;
  volatile const uint32_t DEVTYPE;
} TPI_Type;
typedef struct
{
  volatile const uint32_t TYPE;
  volatile uint32_t CTRL;
  volatile uint32_t RNR;
  volatile uint32_t RBAR;
  volatile uint32_t RLAR;
  volatile uint32_t RBAR_A1;
  volatile uint32_t RLAR_A1;
  volatile uint32_t RBAR_A2;
  volatile uint32_t RLAR_A2;
  volatile uint32_t RBAR_A3;
  volatile uint32_t RLAR_A3;
        uint32_t RESERVED0[1];
  union {
  volatile uint32_t MAIR[2];
  struct {
  volatile uint32_t MAIR0;
  volatile uint32_t MAIR1;
  };
  };
} MPU_Type;
typedef struct
{
        uint32_t RESERVED0[1U];
  volatile uint32_t FPCCR;
  volatile uint32_t FPCAR;
  volatile uint32_t FPDSCR;
  volatile const uint32_t MVFR0;
  volatile const uint32_t MVFR1;
  volatile const uint32_t MVFR2;
} FPU_Type;
typedef struct
{
  volatile uint32_t DHCSR;
  volatile uint32_t DCRSR;
  volatile uint32_t DCRDR;
  volatile uint32_t DEMCR;
        uint32_t RESERVED0[1U];
  volatile uint32_t DAUTHCTRL;
  volatile uint32_t DSCSR;
} CoreDebug_Type;
typedef struct
{
  volatile uint32_t DHCSR;
  volatile uint32_t DCRSR;
  volatile uint32_t DCRDR;
  volatile uint32_t DEMCR;
        uint32_t RESERVED0[1U];
  volatile uint32_t DAUTHCTRL;
  volatile uint32_t DSCSR;
} DCB_Type;
typedef struct
{
  volatile uint32_t DLAR;
  volatile const uint32_t DLSR;
  volatile const uint32_t DAUTHSTATUS;
  volatile const uint32_t DDEVARCH;
  volatile const uint32_t DDEVTYPE;
} DIB_Type;
static inline void __NVIC_SetPriorityGrouping(uint32_t PriorityGroup)
{
  uint32_t reg_value;
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);
  reg_value = ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR;
  reg_value &= ~((uint32_t)((0xFFFFUL << 16U) | (7UL << 8U)));
  reg_value = (reg_value |
                ((uint32_t)0x5FAUL << 16U) |
                (PriorityGroupTmp << 8U) );
  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR = reg_value;
}
static inline uint32_t __NVIC_GetPriorityGrouping(void)
{
  return ((uint32_t)((((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR & (7UL << 8U)) >> 8U));
}
static inline void __NVIC_EnableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    __asm volatile("":::"memory");
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[(((uint32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
    __asm volatile("":::"memory");
  }
}
static inline uint32_t __NVIC_GetEnableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[(((uint32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}
static inline void __NVIC_DisableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICER[(((uint32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
    __DSB();
    __ISB();
  }
}
static inline uint32_t __NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[(((uint32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}
static inline void __NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[(((uint32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
  }
}
static inline void __NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICPR[(((uint32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
  }
}
static inline uint32_t __NVIC_GetActive(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IABR[(((uint32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}
static inline void __NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IPR[((uint32_t)IRQn)] = (uint8_t)((priority << (8U - 4U)) & (uint32_t)0xFFUL);
  }
  else
  {
    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHPR[(((uint32_t)IRQn) & 0xFUL)-4UL] = (uint8_t)((priority << (8U - 4U)) & (uint32_t)0xFFUL);
  }
}
static inline uint32_t __NVIC_GetPriority(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return(((uint32_t)((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IPR[((uint32_t)IRQn)] >> (8U - 4U)));
  }
  else
  {
    return(((uint32_t)((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHPR[(((uint32_t)IRQn) & 0xFUL)-4UL] >> (8U - 4U)));
  }
}
static inline uint32_t NVIC_EncodePriority (uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;
  PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(4U)) ? (uint32_t)(4U) : (uint32_t)(7UL - PriorityGroupTmp);
  SubPriorityBits = ((PriorityGroupTmp + (uint32_t)(4U)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(4U));
  return (
           ((PreemptPriority & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL)) << SubPriorityBits) |
           ((SubPriority & (uint32_t)((1UL << (SubPriorityBits )) - 1UL)))
         );
}
static inline void NVIC_DecodePriority (uint32_t Priority, uint32_t PriorityGroup, uint32_t* const pPreemptPriority, uint32_t* const pSubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;
  PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(4U)) ? (uint32_t)(4U) : (uint32_t)(7UL - PriorityGroupTmp);
  SubPriorityBits = ((PriorityGroupTmp + (uint32_t)(4U)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(4U));
  *pPreemptPriority = (Priority >> SubPriorityBits) & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL);
  *pSubPriority = (Priority ) & (uint32_t)((1UL << (SubPriorityBits )) - 1UL);
}
static inline void __NVIC_SetVector(IRQn_Type IRQn, uint32_t vector)
{
  uint32_t *vectors = (uint32_t *)((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->VTOR;
  vectors[(int32_t)IRQn + 16] = vector;
  __DSB();
}
static inline uint32_t __NVIC_GetVector(IRQn_Type IRQn)
{
  uint32_t *vectors = (uint32_t *)((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->VTOR;
  return vectors[(int32_t)IRQn + 16];
}
__attribute__((__noreturn__)) static inline void __NVIC_SystemReset(void)
{
  __DSB();
  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR = (uint32_t)((0x5FAUL << 16U) |
                           (((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR & (7UL << 8U)) |
                            (1UL << 2U) );
  __DSB();
  for(;;)
  {
    __asm volatile ("nop");
  }
}
typedef struct {
  uint32_t RBAR;
  uint32_t RLAR;
} ARM_MPU_Region_t;
static inline void ARM_MPU_Enable(uint32_t MPU_Control)
{
  __DMB();
  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->CTRL = MPU_Control | (1UL );
  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHCSR |= (1UL << 16U);
  __DSB();
  __ISB();
}
static inline void ARM_MPU_Disable(void)
{
  __DMB();
  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHCSR &= ~(1UL << 16U);
  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->CTRL &= ~(1UL );
  __DSB();
  __ISB();
}
static inline void ARM_MPU_SetMemAttrEx(MPU_Type* mpu, uint8_t idx, uint8_t attr)
{
  const uint8_t reg = idx / 4U;
  const uint32_t pos = ((idx % 4U) * 8U);
  const uint32_t mask = 0xFFU << pos;
  if (reg >= (sizeof(mpu->MAIR) / sizeof(mpu->MAIR[0]))) {
    return;
  }
  mpu->MAIR[reg] = ((mpu->MAIR[reg] & ~mask) | ((attr << pos) & mask));
}
static inline void ARM_MPU_SetMemAttr(uint8_t idx, uint8_t attr)
{
  ARM_MPU_SetMemAttrEx(((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) ), idx, attr);
}
static inline void ARM_MPU_ClrRegionEx(MPU_Type* mpu, uint32_t rnr)
{
  mpu->RNR = rnr;
  mpu->RLAR = 0U;
}
static inline void ARM_MPU_ClrRegion(uint32_t rnr)
{
  ARM_MPU_ClrRegionEx(((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) ), rnr);
}
static inline void ARM_MPU_SetRegionEx(MPU_Type* mpu, uint32_t rnr, uint32_t rbar, uint32_t rlar)
{
  mpu->RNR = rnr;
  mpu->RBAR = rbar;
  mpu->RLAR = rlar;
}
static inline void ARM_MPU_SetRegion(uint32_t rnr, uint32_t rbar, uint32_t rlar)
{
  ARM_MPU_SetRegionEx(((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) ), rnr, rbar, rlar);
}
static inline void ARM_MPU_OrderedMemcpy(volatile uint32_t* dst, const uint32_t* __restrict src, uint32_t len)
{
  uint32_t i;
  for (i = 0U; i < len; ++i)
  {
    dst[i] = src[i];
  }
}
static inline void ARM_MPU_LoadEx(MPU_Type* mpu, uint32_t rnr, ARM_MPU_Region_t const* table, uint32_t cnt)
{
  const uint32_t rowWordSize = sizeof(ARM_MPU_Region_t)/4U;
  if (cnt == 1U) {
    mpu->RNR = rnr;
    ARM_MPU_OrderedMemcpy(&(mpu->RBAR), &(table->RBAR), rowWordSize);
  } else {
    uint32_t rnrBase = rnr & ~(4U -1U);
    uint32_t rnrOffset = rnr % 4U;
    mpu->RNR = rnrBase;
    while ((rnrOffset + cnt) > 4U) {
      uint32_t c = 4U - rnrOffset;
      ARM_MPU_OrderedMemcpy(&(mpu->RBAR)+(rnrOffset*2U), &(table->RBAR), c*rowWordSize);
      table += c;
      cnt -= c;
      rnrOffset = 0U;
      rnrBase += 4U;
      mpu->RNR = rnrBase;
    }
    ARM_MPU_OrderedMemcpy(&(mpu->RBAR)+(rnrOffset*2U), &(table->RBAR), cnt*rowWordSize);
  }
}
static inline void ARM_MPU_Load(uint32_t rnr, ARM_MPU_Region_t const* table, uint32_t cnt)
{
  ARM_MPU_LoadEx(((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) ), rnr, table, cnt);
}
static inline uint32_t SCB_GetFPUType(void)
{
  uint32_t mvfr0;
  mvfr0 = ((FPU_Type *) ((0xE000E000UL) + 0x0F30UL) )->MVFR0;
  if ((mvfr0 & ((0xFUL << 4U) | (0xFUL << 8U))) == 0x220U)
  {
    return 2U;
  }
  else if ((mvfr0 & ((0xFUL << 4U) | (0xFUL << 8U))) == 0x020U)
  {
    return 1U;
  }
  else
  {
    return 0U;
  }
}
static inline void DCB_SetAuthCtrl(uint32_t value)
{
    __DSB();
    __ISB();
    ((DCB_Type *) (0xE000EDF0UL) )->DAUTHCTRL = value;
    __DSB();
    __ISB();
}
static inline uint32_t DCB_GetAuthCtrl(void)
{
    return (((DCB_Type *) (0xE000EDF0UL) )->DAUTHCTRL);
}
static inline uint32_t DIB_GetAuthStatus(void)
{
    return (((DIB_Type *) (0xE000EFB0UL) )->DAUTHSTATUS);
}
static inline uint32_t SysTick_Config(uint32_t ticks)
{
  if ((ticks - 1UL) > (0xFFFFFFUL ))
  {
    return (1UL);
  }
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->LOAD = (uint32_t)(ticks - 1UL);
  __NVIC_SetPriority (SysTick_IRQn, (1UL << 4U) - 1UL);
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->VAL = 0UL;
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL = (1UL << 2U) |
                   (1UL << 1U) |
                   (1UL );
  return (0UL);
}
extern volatile int32_t ITM_RxBuffer;
static inline uint32_t ITM_SendChar (uint32_t ch)
{
  if (((((ITM_Type *) (0xE0000000UL) )->TCR & (1UL )) != 0UL) &&
      ((((ITM_Type *) (0xE0000000UL) )->TER & 1UL ) != 0UL) )
  {
    while (((ITM_Type *) (0xE0000000UL) )->PORT[0U].u32 == 0UL)
    {
      __asm volatile ("nop");
    }
    ((ITM_Type *) (0xE0000000UL) )->PORT[0U].u8 = (uint8_t)ch;
  }
  return (ch);
}
static inline int32_t ITM_ReceiveChar (void)
{
  int32_t ch = -1;
  if (ITM_RxBuffer != ((int32_t)0x5AA55AA5U))
  {
    ch = ITM_RxBuffer;
    ITM_RxBuffer = ((int32_t)0x5AA55AA5U);
  }
  return (ch);
}
static inline int32_t ITM_CheckChar (void)
{
  if (ITM_RxBuffer == ((int32_t)0x5AA55AA5U))
  {
    return (0);
  }
  else
  {
    return (1);
  }
}
extern uint32_t SystemCoreClock;
extern const uint8_t AHBPrescTable[16];
extern const uint8_t APBPrescTable[8];
extern const uint32_t MSIRangeTable[16];
extern void SystemInit (void);
extern void SystemCoreClockUpdate (void);
extern uint32_t SECURE_SystemCoreClockUpdate(void);
typedef struct
{
  volatile uint32_t DR;
  volatile uint32_t IDR;
  volatile uint32_t CR;
       uint32_t RESERVED2;
  volatile uint32_t INIT;
  volatile uint32_t POL;
       uint32_t RESERVED3[246];
  volatile uint32_t HWCFGR;
  volatile uint32_t VERR;
  volatile uint32_t PIDR;
  volatile uint32_t SIDR;
} CRC_TypeDef;
typedef struct
{
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t OAR1;
  volatile uint32_t OAR2;
  volatile uint32_t TIMINGR;
  volatile uint32_t TIMEOUTR;
  volatile uint32_t ISR;
  volatile uint32_t ICR;
  volatile uint32_t PECR;
  volatile uint32_t RXDR;
  volatile uint32_t TXDR;
  volatile uint32_t AUTOCR;
} I2C_TypeDef;
typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t SWTRIGR;
  volatile uint32_t DHR12R1;
  volatile uint32_t DHR12L1;
  volatile uint32_t DHR8R1;
  volatile uint32_t DHR12R2;
  volatile uint32_t DHR12L2;
  volatile uint32_t DHR8R2;
  volatile uint32_t DHR12RD;
  volatile uint32_t DHR12LD;
  volatile uint32_t DHR8RD;
  volatile uint32_t DOR1;
  volatile uint32_t DOR2;
  volatile uint32_t SR;
  volatile uint32_t CCR;
  volatile uint32_t MCR;
  volatile uint32_t SHSR1;
  volatile uint32_t SHSR2;
  volatile uint32_t SHHR;
  volatile uint32_t SHRR;
  volatile uint32_t RESERVED[1];
  volatile uint32_t AUTOCR;
} DAC_TypeDef;
typedef struct
{
volatile uint32_t CR;
volatile uint32_t CFGR;
volatile uint32_t ISR;
volatile uint32_t ICR;
} CRS_TypeDef;
typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t DIN;
  volatile uint32_t STR;
  volatile uint32_t HR[5];
  volatile uint32_t IMR;
  volatile uint32_t SR;
       uint32_t RESERVED[52];
  volatile uint32_t CSR[54];
} HASH_TypeDef;
typedef struct
{
  volatile uint32_t HR[8];
} HASH_DIGEST_TypeDef;
typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t SR;
  volatile uint32_t DR;
  volatile uint32_t NSCR;
  volatile uint32_t HTCR;
} RNG_TypeDef;
typedef struct
{
  volatile uint32_t IDCODE;
  volatile uint32_t CR;
  volatile uint32_t APB1FZR1;
  volatile uint32_t APB1FZR2;
  volatile uint32_t APB2FZR;
  volatile uint32_t APB3FZR;
       uint32_t RESERVED1[2];
  volatile uint32_t AHB1FZR;
       uint32_t RESERVED2;
  volatile uint32_t AHB3FZR;
} DBGMCU_TypeDef;
typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t SR;
  volatile uint32_t RISR;
  volatile uint32_t IER;
  volatile uint32_t MISR;
  volatile uint32_t ICR;
  volatile uint32_t ESCR;
  volatile uint32_t ESUR;
  volatile uint32_t CWSTRTR;
  volatile uint32_t CWSIZER;
  volatile uint32_t DR;
} DCMI_TypeDef;
typedef struct
{
  volatile uint32_t SECCFGR;
  volatile uint32_t PRIVCFGR;
  volatile uint32_t RCFGLOCKR;
  volatile uint32_t MISR;
  volatile uint32_t SMISR;
} DMA_TypeDef;
typedef struct
{
  volatile uint32_t CLBAR;
       uint32_t RESERVED1[2];
  volatile uint32_t CFCR;
  volatile uint32_t CSR;
  volatile uint32_t CCR;
       uint32_t RESERVED2[10];
  volatile uint32_t CTR1;
  volatile uint32_t CTR2;
  volatile uint32_t CBR1;
  volatile uint32_t CSAR;
  volatile uint32_t CDAR;
  volatile uint32_t CTR3;
  volatile uint32_t CBR2;
       uint32_t RESERVED3[8];
  volatile uint32_t CLLR;
} DMA_Channel_TypeDef;
typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t ISR;
  volatile uint32_t IFCR;
  volatile uint32_t FGMAR;
  volatile uint32_t FGOR;
  volatile uint32_t BGMAR;
  volatile uint32_t BGOR;
  volatile uint32_t FGPFCCR;
  volatile uint32_t FGCOLR;
  volatile uint32_t BGPFCCR;
  volatile uint32_t BGCOLR;
  volatile uint32_t FGCMAR;
  volatile uint32_t BGCMAR;
  volatile uint32_t OPFCCR;
  volatile uint32_t OCOLR;
  volatile uint32_t OMAR;
  volatile uint32_t OOR;
  volatile uint32_t NLR;
  volatile uint32_t LWR;
  volatile uint32_t AMTCR;
  uint32_t RESERVED[236];
  volatile uint32_t FGCLUT[256];
  volatile uint32_t BGCLUT[256];
} DMA2D_TypeDef;
typedef struct
{
  volatile uint32_t RTSR1;
  volatile uint32_t FTSR1;
  volatile uint32_t SWIER1;
  volatile uint32_t RPR1;
  volatile uint32_t FPR1;
  volatile uint32_t SECCFGR1;
  volatile uint32_t PRIVCFGR1;
       uint32_t RESERVED1[17];
  volatile uint32_t EXTICR[4];
  volatile uint32_t LOCKR;
       uint32_t RESERVED2[3];
  volatile uint32_t IMR1;
  volatile uint32_t EMR1;
} EXTI_TypeDef;
typedef struct
{
  volatile uint32_t ACR;
       uint32_t RESERVED1;
  volatile uint32_t NSKEYR;
  volatile uint32_t SECKEYR;
  volatile uint32_t OPTKEYR;
  volatile uint32_t RESERVED2;
  volatile uint32_t PDKEY1R;
  volatile uint32_t PDKEY2R;
  volatile uint32_t NSSR;
  volatile uint32_t SECSR;
  volatile uint32_t NSCR;
  volatile uint32_t SECCR;
  volatile uint32_t ECCR;
  volatile uint32_t OPSR;
       uint32_t RESERVED3[2];
  volatile uint32_t OPTR;
  volatile uint32_t NSBOOTADD0R;
  volatile uint32_t NSBOOTADD1R;
  volatile uint32_t SECBOOTADD0R;
  volatile uint32_t SECWM1R1;
  volatile uint32_t SECWM1R2;
  volatile uint32_t WRP1AR;
  volatile uint32_t WRP1BR;
  volatile uint32_t SECWM2R1;
  volatile uint32_t SECWM2R2;
  volatile uint32_t WRP2AR;
  volatile uint32_t WRP2BR;
  volatile uint32_t OEM1KEYR1;
  volatile uint32_t OEM1KEYR2;
  volatile uint32_t OEM2KEYR1;
  volatile uint32_t OEM2KEYR2;
  volatile uint32_t SECBB1R1;
  volatile uint32_t SECBB1R2;
  volatile uint32_t SECBB1R3;
  volatile uint32_t SECBB1R4;
       uint32_t RESERVED4[4];
  volatile uint32_t SECBB2R1;
  volatile uint32_t SECBB2R2;
  volatile uint32_t SECBB2R3;
  volatile uint32_t SECBB2R4;
       uint32_t RESERVED5[4];
  volatile uint32_t SECHDPCR;
  volatile uint32_t PRIVCFGR;
       uint32_t RESERVED6[2];
  volatile uint32_t PRIVBB1R1;
  volatile uint32_t PRIVBB1R2;
  volatile uint32_t PRIVBB1R3;
  volatile uint32_t PRIVBB1R4;
       uint32_t RESERVED7[4];
  volatile uint32_t PRIVBB2R1;
  volatile uint32_t PRIVBB2R2;
  volatile uint32_t PRIVBB2R3;
  volatile uint32_t PRIVBB2R4;
} FLASH_TypeDef;
typedef struct
{
  volatile uint32_t X1BUFCFG;
  volatile uint32_t X2BUFCFG;
  volatile uint32_t YBUFCFG;
  volatile uint32_t PARAM;
  volatile uint32_t CR;
  volatile uint32_t SR;
  volatile uint32_t WDATA;
  volatile uint32_t RDATA;
} FMAC_TypeDef;
typedef struct
{
  volatile uint32_t MODER;
  volatile uint32_t OTYPER;
  volatile uint32_t OSPEEDR;
  volatile uint32_t PUPDR;
  volatile uint32_t IDR;
  volatile uint32_t ODR;
  volatile uint32_t BSRR;
  volatile uint32_t LCKR;
  volatile uint32_t AFR[2];
  volatile uint32_t BRR;
  volatile uint32_t HSLVR;
  volatile uint32_t SECCFGR;
} GPIO_TypeDef;
typedef struct
{
  volatile uint32_t CR;
       uint32_t RESERVED1[3];
  volatile uint32_t SECCFGR1;
  volatile uint32_t SECCFGR2;
  volatile uint32_t SECCFGR3;
       uint32_t RESERVED2;
  volatile uint32_t PRIVCFGR1;
  volatile uint32_t PRIVCFGR2;
  volatile uint32_t PRIVCFGR3;
       uint32_t RESERVED3[5];
  volatile uint32_t MPCWM1ACFGR;
  volatile uint32_t MPCWM1AR;
  volatile uint32_t MPCWM1BCFGR;
  volatile uint32_t MPCWM1BR;
  volatile uint32_t MPCWM2ACFGR;
  volatile uint32_t MPCWM2AR;
  volatile uint32_t MPCWM2BCFGR;
  volatile uint32_t MPCWM2BR;
  volatile uint32_t MPCWM3ACFGR;
  volatile uint32_t MPCWM3AR;
       uint32_t RESERVED4[2];
  volatile uint32_t MPCWM4ACFGR;
  volatile uint32_t MPCWM4AR;
       uint32_t RESERVED5[2];
  volatile uint32_t MPCWM5ACFGR;
  volatile uint32_t MPCWM5AR;
  volatile uint32_t MPCWM5BCFGR;
  volatile uint32_t MPCWM5BR;
} GTZC_TZSC_TypeDef;
typedef struct
{
  volatile uint32_t CR;
  uint32_t RESERVED1[3];
  volatile uint32_t CFGLOCKR1;
  uint32_t RESERVED2[59];
  volatile uint32_t SECCFGR[32];
  uint32_t RESERVED3[32];
  volatile uint32_t PRIVCFGR[32];
} GTZC_MPCBB_TypeDef;
typedef struct
{
  volatile uint32_t IER1;
  volatile uint32_t IER2;
  volatile uint32_t IER3;
  volatile uint32_t IER4;
  volatile uint32_t SR1;
  volatile uint32_t SR2;
  volatile uint32_t SR3;
  volatile uint32_t SR4;
  volatile uint32_t FCR1;
  volatile uint32_t FCR2;
  volatile uint32_t FCR3;
  volatile uint32_t FCR4;
} GTZC_TZIC_TypeDef;
typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t SR;
  volatile uint32_t IER;
  volatile uint32_t FCR;
  volatile uint32_t HMONR;
  volatile uint32_t MMONR;
       uint32_t RESERVED1[2];
  volatile uint32_t CRR0;
  volatile uint32_t CRR1;
  volatile uint32_t CRR2;
  volatile uint32_t CRR3;
} ICACHE_TypeDef;
typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t SR;
  volatile uint32_t IER;
  volatile uint32_t FCR;
  volatile uint32_t RHMONR;
  volatile uint32_t RMMONR;
       uint32_t RESERVED1[2];
  volatile uint32_t WHMONR;
  volatile uint32_t WMMONR;
  volatile uint32_t CMDRSADDRR;
  volatile uint32_t CMDREADDRR;
} DCACHE_TypeDef;
typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t SR;
  volatile uint32_t RIS;
  volatile uint32_t IER;
  volatile uint32_t MIS;
  volatile uint32_t ICR;
  volatile uint32_t RESERVED1[4];
  volatile uint32_t DR;
} PSSI_TypeDef;
typedef struct
{
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t SMCR;
  volatile uint32_t DIER;
  volatile uint32_t SR;
  volatile uint32_t EGR;
  volatile uint32_t CCMR1;
  volatile uint32_t CCMR2;
  volatile uint32_t CCER;
  volatile uint32_t CNT;
  volatile uint32_t PSC;
  volatile uint32_t ARR;
  volatile uint32_t RCR;
  volatile uint32_t CCR1;
  volatile uint32_t CCR2;
  volatile uint32_t CCR3;
  volatile uint32_t CCR4;
  volatile uint32_t BDTR;
  volatile uint32_t CCR5;
  volatile uint32_t CCR6;
  volatile uint32_t CCMR3;
  volatile uint32_t DTR2;
  volatile uint32_t ECR;
  volatile uint32_t TISEL;
  volatile uint32_t AF1;
  volatile uint32_t AF2;
  volatile uint32_t OR1 ;
       uint32_t RESERVED0[220];
  volatile uint32_t DCR;
  volatile uint32_t DMAR;
} TIM_TypeDef;
typedef struct
{
  volatile uint32_t ISR;
  volatile uint32_t ICR;
  volatile uint32_t DIER;
  volatile uint32_t CFGR;
  volatile uint32_t CR;
  volatile uint32_t CCR1;
  volatile uint32_t ARR;
  volatile uint32_t CNT;
  volatile uint32_t RESERVED0;
  volatile uint32_t CFGR2;
  volatile uint32_t RCR;
  volatile uint32_t CCMR1;
  volatile uint32_t RESERVED1;
  volatile uint32_t CCR2;
} LPTIM_TypeDef;
typedef struct
{
  volatile uint32_t CSR;
} COMP_TypeDef;
typedef struct
{
  volatile uint32_t CSR_ODD;
  volatile uint32_t CSR_EVEN;
} COMP_Common_TypeDef;
typedef struct
{
  volatile uint32_t CSR;
  volatile uint32_t OTR;
  volatile uint32_t LPOTR;
} OPAMP_TypeDef;
typedef struct
{
  volatile uint32_t CSR;
} OPAMP_Common_TypeDef;
typedef struct
{
 volatile uint32_t GCR;
 volatile uint32_t CKGCR;
 uint32_t RESERVED1[6];
 volatile uint32_t OR;
}MDF_TypeDef;
typedef struct
{
 volatile uint32_t SITFCR;
 volatile uint32_t BSMXCR;
 volatile uint32_t DFLTCR;
 volatile uint32_t DFLTCICR;
 volatile uint32_t DFLTRSFR;
 volatile uint32_t DFLTINTR;
 volatile uint32_t OLDCR;
 volatile uint32_t OLDTHLR;
 volatile uint32_t OLDTHHR;
 volatile uint32_t DLYCR;
 volatile uint32_t SCDCR;
 volatile uint32_t DFLTIER;
 volatile uint32_t DFLTISR;
 volatile uint32_t OECCR;
 volatile uint32_t SADCR;
 volatile uint32_t SADCFGR;
 volatile uint32_t SADSDLVR;
 volatile uint32_t SADANLVR;
 uint32_t RESERVED1[9];
 volatile uint32_t SNPSDR;
 volatile uint32_t DFLTDR;
} MDF_Filter_TypeDef;
typedef struct
{
  volatile uint32_t CR;
  uint32_t RESERVED;
  volatile uint32_t DCR1;
  volatile uint32_t DCR2;
  volatile uint32_t DCR3;
  volatile uint32_t DCR4;
  uint32_t RESERVED1[2];
  volatile uint32_t SR;
  volatile uint32_t FCR;
  uint32_t RESERVED2[6];
  volatile uint32_t DLR;
  uint32_t RESERVED3;
  volatile uint32_t AR;
  uint32_t RESERVED4;
  volatile uint32_t DR;
  uint32_t RESERVED5[11];
  volatile uint32_t PSMKR;
  uint32_t RESERVED6;
  volatile uint32_t PSMAR;
  uint32_t RESERVED7;
  volatile uint32_t PIR;
  uint32_t RESERVED8[27];
  volatile uint32_t CCR;
  uint32_t RESERVED9;
  volatile uint32_t TCR;
  uint32_t RESERVED10;
  volatile uint32_t IR;
  uint32_t RESERVED11[3];
  volatile uint32_t ABR;
  uint32_t RESERVED12[3];
  volatile uint32_t LPTR;
  uint32_t RESERVED13[3];
  volatile uint32_t WPCCR;
  uint32_t RESERVED14;
  volatile uint32_t WPTCR;
  uint32_t RESERVED15;
  volatile uint32_t WPIR;
  uint32_t RESERVED16[3];
  volatile uint32_t WPABR;
  uint32_t RESERVED17[7];
  volatile uint32_t WCCR;
  uint32_t RESERVED18;
  volatile uint32_t WTCR;
  uint32_t RESERVED19;
  volatile uint32_t WIR;
  uint32_t RESERVED20[3];
  volatile uint32_t WABR;
  uint32_t RESERVED21[23];
  volatile uint32_t HLCR;
} XSPI_TypeDef;
typedef XSPI_TypeDef OCTOSPI_TypeDef;
typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t PCR[8];
} XSPIM_TypeDef;
typedef XSPIM_TypeDef OCTOSPIM_TypeDef;
typedef struct
{
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t CR3;
  volatile uint32_t VOSR;
  volatile uint32_t SVMCR;
  volatile uint32_t WUCR1;
  volatile uint32_t WUCR2;
  volatile uint32_t WUCR3;
  volatile uint32_t BDCR1;
  volatile uint32_t BDCR2;
  volatile uint32_t DBPR;
  volatile uint32_t UCPDR;
  volatile uint32_t SECCFGR;
  volatile uint32_t PRIVCFGR;
  volatile uint32_t SR;
  volatile uint32_t SVMSR;
  volatile uint32_t BDSR;
  volatile uint32_t WUSR;
  volatile uint32_t WUSCR;
  volatile uint32_t APCR;
  volatile uint32_t PUCRA;
  volatile uint32_t PDCRA;
  volatile uint32_t PUCRB;
  volatile uint32_t PDCRB;
  volatile uint32_t PUCRC;
  volatile uint32_t PDCRC;
  volatile uint32_t PUCRD;
  volatile uint32_t PDCRD;
  volatile uint32_t PUCRE;
  volatile uint32_t PDCRE;
  volatile uint32_t PUCRF;
  volatile uint32_t PDCRF;
  volatile uint32_t PUCRG;
  volatile uint32_t PDCRG;
  volatile uint32_t PUCRH;
  volatile uint32_t PDCRH;
  volatile uint32_t PUCRI;
  volatile uint32_t PDCRI;
} PWR_TypeDef;
typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t IER;
  volatile uint32_t ISR;
  volatile uint32_t SEAR;
  volatile uint32_t DEAR;
  volatile uint32_t ICR;
  volatile uint32_t WPR1;
  volatile uint32_t WPR2;
  uint32_t RESERVED;
  volatile uint32_t ECCKEY;
  volatile uint32_t ERKEYR;
}RAMCFG_TypeDef;
typedef struct
{
  volatile uint32_t CR;
  uint32_t RESERVED0;
  volatile uint32_t ICSCR1;
  volatile uint32_t ICSCR2;
  volatile uint32_t ICSCR3;
  volatile uint32_t CRRCR;
  uint32_t RESERVED1;
  volatile uint32_t CFGR1;
  volatile uint32_t CFGR2;
  volatile uint32_t CFGR3;
  volatile uint32_t PLL1CFGR;
  volatile uint32_t PLL2CFGR;
  volatile uint32_t PLL3CFGR;
  volatile uint32_t PLL1DIVR;
  volatile uint32_t PLL1FRACR;
  volatile uint32_t PLL2DIVR;
  volatile uint32_t PLL2FRACR;
  volatile uint32_t PLL3DIVR;
  volatile uint32_t PLL3FRACR;
  uint32_t RESERVED2;
  volatile uint32_t CIER;
  volatile uint32_t CIFR;
  volatile uint32_t CICR;
  uint32_t RESERVED3;
  volatile uint32_t AHB1RSTR;
  volatile uint32_t AHB2RSTR1;
  volatile uint32_t AHB2RSTR2;
  volatile uint32_t AHB3RSTR;
  uint32_t RESERVED4;
  volatile uint32_t APB1RSTR1;
  volatile uint32_t APB1RSTR2;
  volatile uint32_t APB2RSTR;
  volatile uint32_t APB3RSTR;
  uint32_t RESERVED5;
  volatile uint32_t AHB1ENR;
  volatile uint32_t AHB2ENR1;
  volatile uint32_t AHB2ENR2;
  volatile uint32_t AHB3ENR;
  uint32_t RESERVED6;
  volatile uint32_t APB1ENR1;
  volatile uint32_t APB1ENR2;
  volatile uint32_t APB2ENR;
  volatile uint32_t APB3ENR;
  uint32_t RESERVED7;
  volatile uint32_t AHB1SMENR;
  volatile uint32_t AHB2SMENR1;
  volatile uint32_t AHB2SMENR2;
  volatile uint32_t AHB3SMENR;
  uint32_t RESERVED8;
  volatile uint32_t APB1SMENR1;
  volatile uint32_t APB1SMENR2;
  volatile uint32_t APB2SMENR;
  volatile uint32_t APB3SMENR;
  uint32_t RESERVED9;
  volatile uint32_t SRDAMR;
  uint32_t RESERVED10;
  volatile uint32_t CCIPR1;
  volatile uint32_t CCIPR2;
  volatile uint32_t CCIPR3;
  uint32_t RESERVED11;
  volatile uint32_t BDCR;
  volatile uint32_t CSR;
  uint32_t RESERVED[6];
  volatile uint32_t SECCFGR;
  volatile uint32_t PRIVCFGR;
} RCC_TypeDef;
typedef struct
{
  volatile uint32_t TR;
  volatile uint32_t DR;
  volatile uint32_t SSR;
  volatile uint32_t ICSR;
  volatile uint32_t PRER;
  volatile uint32_t WUTR;
  volatile uint32_t CR;
  volatile uint32_t PRIVCFGR;
  volatile uint32_t SECCFGR;
  volatile uint32_t WPR;
  volatile uint32_t CALR;
  volatile uint32_t SHIFTR;
  volatile uint32_t TSTR;
  volatile uint32_t TSDR;
  volatile uint32_t TSSSR;
       uint32_t RESERVED0;
  volatile uint32_t ALRMAR;
  volatile uint32_t ALRMASSR;
  volatile uint32_t ALRMBR;
  volatile uint32_t ALRMBSSR;
  volatile uint32_t SR;
  volatile uint32_t MISR;
  volatile uint32_t SMISR;
  volatile uint32_t SCR;
       uint32_t RESERVED4[4];
  volatile uint32_t ALRABINR;
  volatile uint32_t ALRBBINR;
} RTC_TypeDef;
typedef struct
{
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t CR3;
  volatile uint32_t FLTCR;
  volatile uint32_t ATCR1;
  volatile uint32_t ATSEEDR;
  volatile uint32_t ATOR;
  volatile uint32_t ATCR2;
  volatile uint32_t SECCFGR;
  volatile uint32_t PRIVCFGR;
       uint32_t RESERVED0;
  volatile uint32_t IER;
  volatile uint32_t SR;
  volatile uint32_t MISR;
  volatile uint32_t SMISR;
  volatile uint32_t SCR;
  volatile uint32_t COUNTR;
       uint32_t RESERVED1[4];
  volatile uint32_t ERCFGR;
       uint32_t RESERVED2[42];
  volatile uint32_t BKP0R;
  volatile uint32_t BKP1R;
  volatile uint32_t BKP2R;
  volatile uint32_t BKP3R;
  volatile uint32_t BKP4R;
  volatile uint32_t BKP5R;
  volatile uint32_t BKP6R;
  volatile uint32_t BKP7R;
  volatile uint32_t BKP8R;
  volatile uint32_t BKP9R;
  volatile uint32_t BKP10R;
  volatile uint32_t BKP11R;
  volatile uint32_t BKP12R;
  volatile uint32_t BKP13R;
  volatile uint32_t BKP14R;
  volatile uint32_t BKP15R;
  volatile uint32_t BKP16R;
  volatile uint32_t BKP17R;
  volatile uint32_t BKP18R;
  volatile uint32_t BKP19R;
  volatile uint32_t BKP20R;
  volatile uint32_t BKP21R;
  volatile uint32_t BKP22R;
  volatile uint32_t BKP23R;
  volatile uint32_t BKP24R;
  volatile uint32_t BKP25R;
  volatile uint32_t BKP26R;
  volatile uint32_t BKP27R;
  volatile uint32_t BKP28R;
  volatile uint32_t BKP29R;
  volatile uint32_t BKP30R;
  volatile uint32_t BKP31R;
} TAMP_TypeDef;
typedef struct
{
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t CR3;
  volatile uint32_t BRR;
  volatile uint32_t GTPR;
  volatile uint32_t RTOR;
  volatile uint32_t RQR;
  volatile uint32_t ISR;
  volatile uint32_t ICR;
  volatile uint32_t RDR;
  volatile uint32_t TDR;
  volatile uint32_t PRESC;
  volatile uint32_t AUTOCR;
} USART_TypeDef;
typedef struct
{
  volatile uint32_t GCR;
  uint32_t RESERVED[16];
  volatile uint32_t PDMCR;
  volatile uint32_t PDMDLY;
} SAI_TypeDef;
typedef struct
{
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t FRCR;
  volatile uint32_t SLOTR;
  volatile uint32_t IMR;
  volatile uint32_t SR;
  volatile uint32_t CLRFR;
  volatile uint32_t DR;
} SAI_Block_TypeDef;
typedef struct
{
  volatile uint32_t SECCFGR;
  volatile uint32_t CFGR1;
  volatile uint32_t FPUIMR;
  volatile uint32_t CNSLCKR;
  volatile uint32_t CSLCKR;
  volatile uint32_t CFGR2;
  volatile uint32_t MESR;
  volatile uint32_t CCCSR;
  volatile uint32_t CCVR;
  volatile uint32_t CCCR;
       uint32_t RESERVED1;
  volatile uint32_t RSSCMDR;
} SYSCFG_TypeDef;
typedef struct
{
  volatile uint32_t POWER;
  volatile uint32_t CLKCR;
  volatile uint32_t ARG;
  volatile uint32_t CMD;
  volatile const uint32_t RESPCMD;
  volatile const uint32_t RESP1;
  volatile const uint32_t RESP2;
  volatile const uint32_t RESP3;
  volatile const uint32_t RESP4;
  volatile uint32_t DTIMER;
  volatile uint32_t DLEN;
  volatile uint32_t DCTRL;
  volatile const uint32_t DCOUNT;
  volatile const uint32_t STA;
  volatile uint32_t ICR;
  volatile uint32_t MASK;
  volatile uint32_t ACKTIME;
  uint32_t RESERVED0[3];
  volatile uint32_t IDMACTRL;
  volatile uint32_t IDMABSIZE;
  volatile uint32_t IDMABASER;
  uint32_t RESERVED1[2];
  volatile uint32_t IDMALAR;
  volatile uint32_t IDMABAR;
  uint32_t RESERVED2[5];
  volatile uint32_t FIFO;
} SDMMC_TypeDef;
typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t CFGR;
} DLYB_TypeDef;
typedef struct
{
  volatile uint32_t CFG1;
  volatile uint32_t CFG2;
  volatile uint32_t CFG3;
  volatile uint32_t CR;
  volatile uint32_t IMR;
  volatile uint32_t SR;
  volatile uint32_t ICR;
  volatile uint32_t TX_ORDSET;
  volatile uint32_t TX_PAYSZ;
  volatile uint32_t TXDR;
  volatile uint32_t RX_ORDSET;
  volatile uint32_t RX_PAYSZ;
  volatile uint32_t RXDR;
  volatile uint32_t RX_ORDEXT1;
  volatile uint32_t RX_ORDEXT2;
} UCPD_TypeDef;
typedef struct
{
  volatile uint32_t GOTGCTL;
  volatile uint32_t GOTGINT;
  volatile uint32_t GAHBCFG;
  volatile uint32_t GUSBCFG;
  volatile uint32_t GRSTCTL;
  volatile uint32_t GINTSTS;
  volatile uint32_t GINTMSK;
  volatile uint32_t GRXSTSR;
  volatile uint32_t GRXSTSP;
  volatile uint32_t GRXFSIZ;
  volatile uint32_t DIEPTXF0_HNPTXFSIZ;
  volatile uint32_t HNPTXSTS;
  volatile uint32_t Reserved30[2];
  volatile uint32_t GCCFG;
  volatile uint32_t CID;
  volatile uint32_t GSNPSID;
  volatile uint32_t GHWCFG1;
  volatile uint32_t GHWCFG2;
  volatile uint32_t GHWCFG3;
  volatile uint32_t Reserved6;
  volatile uint32_t GLPMCFG;
  volatile uint32_t GPWRDN;
  volatile uint32_t GDFIFOCFG;
  volatile uint32_t GADPCTL;
  volatile uint32_t Reserved43[39];
  volatile uint32_t HPTXFSIZ;
  volatile uint32_t DIEPTXF[0x0F];
} USB_OTG_GlobalTypeDef;
typedef struct
{
  volatile uint32_t DCFG;
  volatile uint32_t DCTL;
  volatile uint32_t DSTS;
  uint32_t Reserved0C;
  volatile uint32_t DIEPMSK;
  volatile uint32_t DOEPMSK;
  volatile uint32_t DAINT;
  volatile uint32_t DAINTMSK;
  uint32_t Reserved20;
  uint32_t Reserved9;
  volatile uint32_t DVBUSDIS;
  volatile uint32_t DVBUSPULSE;
  volatile uint32_t DTHRCTL;
  volatile uint32_t DIEPEMPMSK;
  volatile uint32_t DEACHINT;
  volatile uint32_t DEACHMSK;
  uint32_t Reserved40;
  volatile uint32_t DINEP1MSK;
  uint32_t Reserved44[15];
  volatile uint32_t DOUTEP1MSK;
} USB_OTG_DeviceTypeDef;
typedef struct
{
  volatile uint32_t DIEPCTL;
  volatile uint32_t Reserved04;
  volatile uint32_t DIEPINT;
  volatile uint32_t Reserved0C;
  volatile uint32_t DIEPTSIZ;
  volatile uint32_t DIEPDMA;
  volatile uint32_t DTXFSTS;
  volatile uint32_t Reserved18;
} USB_OTG_INEndpointTypeDef;
typedef struct
{
  volatile uint32_t DOEPCTL;
  volatile uint32_t Reserved04;
  volatile uint32_t DOEPINT;
  volatile uint32_t Reserved0C;
  volatile uint32_t DOEPTSIZ;
  volatile uint32_t DOEPDMA;
  volatile uint32_t Reserved18[2];
} USB_OTG_OUTEndpointTypeDef;
typedef struct
{
  volatile uint32_t HCFG;
  volatile uint32_t HFIR;
  volatile uint32_t HFNUM;
  uint32_t Reserved40C;
  volatile uint32_t HPTXSTS;
  volatile uint32_t HAINT;
  volatile uint32_t HAINTMSK;
} USB_OTG_HostTypeDef;
typedef struct
{
  volatile uint32_t HCCHAR;
  volatile uint32_t HCSPLT;
  volatile uint32_t HCINT;
  volatile uint32_t HCINTMSK;
  volatile uint32_t HCTSIZ;
  volatile uint32_t HCDMA;
  uint32_t Reserved[2];
} USB_OTG_HostChannelTypeDef;
typedef struct
{
  volatile uint32_t CREL;
  volatile uint32_t ENDN;
       uint32_t RESERVED1;
  volatile uint32_t DBTP;
  volatile uint32_t TEST;
  volatile uint32_t RWD;
  volatile uint32_t CCCR;
  volatile uint32_t NBTP;
  volatile uint32_t TSCC;
  volatile uint32_t TSCV;
  volatile uint32_t TOCC;
  volatile uint32_t TOCV;
       uint32_t RESERVED2[4];
  volatile uint32_t ECR;
  volatile uint32_t PSR;
  volatile uint32_t TDCR;
       uint32_t RESERVED3;
  volatile uint32_t IR;
  volatile uint32_t IE;
  volatile uint32_t ILS;
  volatile uint32_t ILE;
       uint32_t RESERVED4[8];
  volatile uint32_t RXGFC;
  volatile uint32_t XIDAM;
  volatile uint32_t HPMS;
       uint32_t RESERVED5;
  volatile uint32_t RXF0S;
  volatile uint32_t RXF0A;
  volatile uint32_t RXF1S;
  volatile uint32_t RXF1A;
       uint32_t RESERVED6[8];
  volatile uint32_t TXBC;
  volatile uint32_t TXFQS;
  volatile uint32_t TXBRP;
  volatile uint32_t TXBAR;
  volatile uint32_t TXBCR;
  volatile uint32_t TXBTO;
  volatile uint32_t TXBCF;
  volatile uint32_t TXBTIE;
  volatile uint32_t TXBCIE;
  volatile uint32_t TXEFS;
  volatile uint32_t TXEFA;
} FDCAN_GlobalTypeDef;
typedef struct
{
  volatile uint32_t CKDIV;
       uint32_t RESERVED1[128];
  volatile uint32_t OPTR;
       uint32_t RESERVED2[58];
  volatile uint32_t HWCFG;
  volatile uint32_t VERR;
  volatile uint32_t IPIDR;
  volatile uint32_t SIDR;
} FDCAN_Config_TypeDef;
typedef struct
{
  volatile uint32_t BTCR[8];
  volatile uint32_t PCSCNTR;
} FMC_Bank1_TypeDef;
typedef struct
{
  volatile uint32_t BWTR[7];
} FMC_Bank1E_TypeDef;
typedef struct
{
  volatile uint32_t PCR;
  volatile uint32_t SR;
  volatile uint32_t PMEM;
  volatile uint32_t PATT;
  uint32_t RESERVED0;
  volatile uint32_t ECCR;
} FMC_Bank3_TypeDef;
typedef struct
{
  volatile uint32_t CSR;
  volatile uint32_t CCR;
} VREFBUF_TypeDef;
typedef struct
{
  volatile uint32_t ISR;
  volatile uint32_t IER;
  volatile uint32_t CR;
  volatile uint32_t CFGR1;
  volatile uint32_t CFGR2;
  volatile uint32_t SMPR1;
  volatile uint32_t SMPR2;
  volatile uint32_t PCSEL;
  volatile uint32_t AWD1TR;
  volatile uint32_t AWD2TR;
  volatile uint32_t CHSELR;
  volatile uint32_t AWD3TR;
  volatile uint32_t SQR1;
  volatile uint32_t SQR2;
  volatile uint32_t SQR3;
  volatile uint32_t SQR4;
  volatile uint32_t DR;
  volatile uint32_t PWRR;
  uint32_t RESERVED1;
  volatile uint32_t JSQR;
  uint32_t RESERVED2[4];
  volatile uint32_t OFR1;
  volatile uint32_t OFR2;
  volatile uint32_t OFR3;
  volatile uint32_t OFR4;
  volatile uint32_t GCOMP;
  uint32_t RESERVED3[3];
  volatile uint32_t JDR1;
  volatile uint32_t JDR2;
  volatile uint32_t JDR3;
  volatile uint32_t JDR4;
  uint32_t RESERVED4[4];
  volatile uint32_t AWD2CR;
  volatile uint32_t AWD3CR;
  volatile uint32_t LTR1;
  volatile uint32_t HTR1;
  volatile uint32_t LTR2;
  volatile uint32_t HTR2;
  volatile uint32_t LTR3;
  volatile uint32_t HTR3;
  volatile uint32_t DIFSEL;
  volatile uint32_t CALFACT;
  volatile uint32_t CALFACT2;
  uint32_t RESERVED5;
  volatile uint32_t OR;
} ADC_TypeDef;
typedef struct
{
  volatile uint32_t CCR;
} ADC_Common_TypeDef;
typedef struct
{
  volatile uint32_t CSR;
  volatile uint32_t WDATA;
  volatile uint32_t RDATA;
} CORDIC_TypeDef;
typedef struct
{
  volatile uint32_t KR;
  volatile uint32_t PR;
  volatile uint32_t RLR;
  volatile uint32_t SR;
  volatile uint32_t WINR;
  volatile uint32_t EWCR;
} IWDG_TypeDef;
typedef struct
{
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t CFG1;
  volatile uint32_t CFG2;
  volatile uint32_t IER;
  volatile uint32_t SR;
  volatile uint32_t IFCR;
  volatile uint32_t AUTOCR;
  volatile uint32_t TXDR;
  uint32_t RESERVED1[3];
  volatile uint32_t RXDR;
  uint32_t RESERVED2[3];
  volatile uint32_t CRCPOLY;
  volatile uint32_t TXCRC;
  volatile uint32_t RXCRC;
  volatile uint32_t UDRDR;
} SPI_TypeDef;
typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t IER;
  volatile uint32_t ICR;
  volatile uint32_t ISR;
  volatile uint32_t IOHCR;
  uint32_t RESERVED1;
  volatile uint32_t IOASCR;
  uint32_t RESERVED2;
  volatile uint32_t IOSCR;
  uint32_t RESERVED3;
  volatile uint32_t IOCCR;
  uint32_t RESERVED4;
  volatile uint32_t IOGCSR;
  volatile uint32_t IOGXCR[8];
} TSC_TypeDef;
typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t CFR;
  volatile uint32_t SR;
} WWDG_TypeDef;
typedef uint32_t ( *RSSLIB_S_CloseExitHDP_TypeDef)( uint32_t HdpArea, uint32_t VectorTableAddr );
typedef struct
{
  volatile const uint32_t Reserved[8];
}NSC_pFuncTypeDef;
typedef struct
{
  volatile const uint32_t Reserved2[2];
  volatile const RSSLIB_S_CloseExitHDP_TypeDef CloseExitHDP;
}S_pFuncTypeDef;
typedef struct
{
  NSC_pFuncTypeDef NSC;
  S_pFuncTypeDef S;
}RSSLIB_pFunc_TypeDef;
typedef enum
{
  RESET = 0,
  SET = !RESET
} FlagStatus, ITStatus;
typedef enum
{
  DISABLE = 0,
  ENABLE = !DISABLE
} FunctionalState;
typedef enum
{
  SUCCESS = 0,
  ERROR = !SUCCESS
} ErrorStatus;
typedef int ptrdiff_t;
typedef unsigned int size_t;
typedef unsigned int wchar_t;
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;
typedef unsigned int wint_t;
typedef long __blkcnt_t;
typedef long __blksize_t;
typedef __uint64_t __fsblkcnt_t;
typedef __uint32_t __fsfilcnt_t;
typedef long _off_t;
typedef int __pid_t;
typedef short __dev_t;
typedef unsigned short __uid_t;
typedef unsigned short __gid_t;
typedef __uint32_t __id_t;
typedef unsigned short __ino_t;
typedef __uint32_t __mode_t;
__extension__ typedef long long _off64_t;
typedef _off_t __off_t;
typedef _off64_t __loff_t;
typedef long __key_t;
typedef long _fpos_t;
typedef unsigned int __size_t;
typedef signed int _ssize_t;
typedef _ssize_t __ssize_t;
typedef struct
{
  int __count;
  union
  {
    wint_t __wch;
    unsigned char __wchb[4];
  } __value;
} _mbstate_t;
typedef void *_iconv_t;
typedef unsigned long __clock_t;
typedef __int_least64_t __time_t;
typedef unsigned long __clockid_t;
typedef long __daddr_t;
typedef unsigned long __timer_t;
typedef __uint8_t __sa_family_t;
typedef __uint32_t __socklen_t;
typedef int __nl_item;
typedef unsigned short __nlink_t;
typedef long __suseconds_t;
typedef unsigned long __useconds_t;
typedef __builtin_va_list __va_list;
typedef unsigned long __ULong;
struct __lock;
typedef struct __lock * _LOCK_T;
extern void __retarget_lock_init(_LOCK_T *lock);
extern void __retarget_lock_init_recursive(_LOCK_T *lock);
extern void __retarget_lock_close(_LOCK_T lock);
extern void __retarget_lock_close_recursive(_LOCK_T lock);
extern void __retarget_lock_acquire(_LOCK_T lock);
extern void __retarget_lock_acquire_recursive(_LOCK_T lock);
extern int __retarget_lock_try_acquire(_LOCK_T lock);
extern int __retarget_lock_try_acquire_recursive(_LOCK_T lock);
extern void __retarget_lock_release(_LOCK_T lock);
extern void __retarget_lock_release_recursive(_LOCK_T lock);
typedef _LOCK_T _flock_t;
struct _reent;
struct __locale_t;
struct _Bigint
{
  struct _Bigint *_next;
  int _k, _maxwds, _sign, _wds;
  __ULong _x[1];
};
struct __tm
{
  int __tm_sec;
  int __tm_min;
  int __tm_hour;
  int __tm_mday;
  int __tm_mon;
  int __tm_year;
  int __tm_wday;
  int __tm_yday;
  int __tm_isdst;
};
struct _on_exit_args {
 void * _fnargs[32];
 void * _dso_handle[32];
 __ULong _fntypes;
 __ULong _is_cxa;
};
struct _atexit {
 struct _atexit *_next;
 int _ind;
 void (*_fns[32])(void);
        struct _on_exit_args _on_exit_args;
};
struct __sbuf {
 unsigned char *_base;
 int _size;
};
struct __sFILE {
  unsigned char *_p;
  int _r;
  int _w;
  short _flags;
  short _file;
  struct __sbuf _bf;
  int _lbfsize;
  void * _cookie;
  int (*_read) (struct _reent *, void *,
        char *, int);
  int (*_write) (struct _reent *, void *,
         const char *,
         int);
  _fpos_t (*_seek) (struct _reent *, void *, _fpos_t, int);
  int (*_close) (struct _reent *, void *);
  struct __sbuf _ub;
  unsigned char *_up;
  int _ur;
  unsigned char _ubuf[3];
  unsigned char _nbuf[1];
  struct __sbuf _lb;
  int _blksize;
  _off_t _offset;
  struct _reent *_data;
  _flock_t _lock;
  _mbstate_t _mbstate;
  int _flags2;
};
typedef struct __sFILE __FILE;
extern __FILE __sf[3];
struct _glue
{
  struct _glue *_next;
  int _niobs;
  __FILE *_iobs;
};
extern struct _glue __sglue;
struct _rand48 {
  unsigned short _seed[3];
  unsigned short _mult[3];
  unsigned short _add;
};
struct _reent
{
  int _errno;
  __FILE *_stdin, *_stdout, *_stderr;
  int _inc;
  char _emergency[25];
  struct __locale_t *_locale;
  void (*__cleanup) (struct _reent *);
  struct _Bigint *_result;
  int _result_k;
  struct _Bigint *_p5s;
  struct _Bigint **_freelist;
  int _cvtlen;
  char *_cvtbuf;
  union
    {
      struct
        {
          char * _strtok_last;
          char _asctime_buf[26];
          struct __tm _localtime_buf;
          int _gamma_signgam;
          __extension__ unsigned long long _rand_next;
          struct _rand48 _r48;
          _mbstate_t _mblen_state;
          _mbstate_t _mbtowc_state;
          _mbstate_t _wctomb_state;
          char _l64a_buf[8];
          char _signal_buf[24];
          int _getdate_err;
          _mbstate_t _mbrlen_state;
          _mbstate_t _mbrtowc_state;
          _mbstate_t _mbsrtowcs_state;
          _mbstate_t _wcrtomb_state;
          _mbstate_t _wcsrtombs_state;
   int _h_errno;
   char _getlocalename_l_buf[32 ];
        } _reent;
    } _new;
  void (**_sig_func)(int);
};
extern struct _reent *_impure_ptr ;
extern struct _reent _impure_data ;
extern struct _atexit *__atexit;
extern struct _atexit __atexit0;
extern void (*__stdio_exit_handler) (void);
void _reclaim_reent (struct _reent *);
extern int _fwalk_sglue (struct _reent *, int (*)(struct _reent *, __FILE *),
    struct _glue *);

extern double atan (double);
extern double cos (double);
extern double sin (double);
extern double tan (double);
extern double tanh (double);
extern double frexp (double, int *);
extern double modf (double, double *);
extern double ceil (double);
extern double fabs (double);
extern double floor (double);
extern double acos (double);
extern double asin (double);
extern double atan2 (double, double);
extern double cosh (double);
extern double sinh (double);
extern double exp (double);
extern double ldexp (double, int);
extern double log (double);
extern double log10 (double);
extern double pow (double, double);
extern double sqrt (double);
extern double fmod (double, double);
extern int finite (double);
extern int finitef (float);
extern int finitel (long double);
extern int isinff (float);
extern int isnanf (float);
extern int isinf (double);
extern int isnan (double);
    typedef float float_t;
    typedef double double_t;
extern int __isinff (float);
extern int __isinfd (double);
extern int __isnanf (float);
extern int __isnand (double);
extern int __fpclassifyf (float);
extern int __fpclassifyd (double);
extern int __signbitf (float);
extern int __signbitd (double);
extern double infinity (void);
extern double nan (const char *);
extern double copysign (double, double);
extern double logb (double);
extern int ilogb (double);
extern double asinh (double);
extern double cbrt (double);
extern double nextafter (double, double);
extern double rint (double);
extern double scalbn (double, int);
extern double exp2 (double);
extern double scalbln (double, long int);
extern double tgamma (double);
extern double nearbyint (double);
extern long int lrint (double);
extern long long int llrint (double);
extern double round (double);
extern long int lround (double);
extern long long int llround (double);
extern double trunc (double);
extern double remquo (double, double, int *);
extern double fdim (double, double);
extern double fmax (double, double);
extern double fmin (double, double);
extern double fma (double, double, double);
extern double log1p (double);
extern double expm1 (double);
extern double acosh (double);
extern double atanh (double);
extern double remainder (double, double);
extern double gamma (double);
extern double lgamma (double);
extern double erf (double);
extern double erfc (double);
extern double log2 (double);
extern double hypot (double, double);
extern float atanf (float);
extern float cosf (float);
extern float sinf (float);
extern float tanf (float);
extern float tanhf (float);
extern float frexpf (float, int *);
extern float modff (float, float *);
extern float ceilf (float);
extern float fabsf (float);
extern float floorf (float);
extern float acosf (float);
extern float asinf (float);
extern float atan2f (float, float);
extern float coshf (float);
extern float sinhf (float);
extern float expf (float);
extern float ldexpf (float, int);
extern float logf (float);
extern float log10f (float);
extern float powf (float, float);
extern float sqrtf (float);
extern float fmodf (float, float);
extern float exp2f (float);
extern float scalblnf (float, long int);
extern float tgammaf (float);
extern float nearbyintf (float);
extern long int lrintf (float);
extern long long int llrintf (float);
extern float roundf (float);
extern long int lroundf (float);
extern long long int llroundf (float);
extern float truncf (float);
extern float remquof (float, float, int *);
extern float fdimf (float, float);
extern float fmaxf (float, float);
extern float fminf (float, float);
extern float fmaf (float, float, float);
extern float infinityf (void);
extern float nanf (const char *);
extern float copysignf (float, float);
extern float logbf (float);
extern int ilogbf (float);
extern float asinhf (float);
extern float cbrtf (float);
extern float nextafterf (float, float);
extern float rintf (float);
extern float scalbnf (float, int);
extern float log1pf (float);
extern float expm1f (float);
extern float acoshf (float);
extern float atanhf (float);
extern float remainderf (float, float);
extern float gammaf (float);
extern float lgammaf (float);
extern float erff (float);
extern float erfcf (float);
extern float log2f (float);
extern float hypotf (float, float);
extern long double atanl (long double);
extern long double cosl (long double);
extern long double sinl (long double);
extern long double tanl (long double);
extern long double tanhl (long double);
extern long double frexpl (long double, int *);
extern long double modfl (long double, long double *);
extern long double ceill (long double);
extern long double fabsl (long double);
extern long double floorl (long double);
extern long double log1pl (long double);
extern long double expm1l (long double);
extern long double acosl (long double);
extern long double asinl (long double);
extern long double atan2l (long double, long double);
extern long double coshl (long double);
extern long double sinhl (long double);
extern long double expl (long double);
extern long double ldexpl (long double, int);
extern long double logl (long double);
extern long double log10l (long double);
extern long double powl (long double, long double);
extern long double sqrtl (long double);
extern long double fmodl (long double, long double);
extern long double hypotl (long double, long double);
extern long double copysignl (long double, long double);
extern long double nanl (const char *);
extern int ilogbl (long double);
extern long double asinhl (long double);
extern long double cbrtl (long double);
extern long double nextafterl (long double, long double);
extern float nexttowardf (float, long double);
extern double nexttoward (double, long double);
extern long double nexttowardl (long double, long double);
extern long double logbl (long double);
extern long double log2l (long double);
extern long double rintl (long double);
extern long double scalbnl (long double, int);
extern long double exp2l (long double);
extern long double scalblnl (long double, long);
extern long double tgammal (long double);
extern long double nearbyintl (long double);
extern long int lrintl (long double);
extern long long int llrintl (long double);
extern long double roundl (long double);
extern long lroundl (long double);
extern long long int llroundl (long double);
extern long double truncl (long double);
extern long double remquol (long double, long double, int *);
extern long double fdiml (long double, long double);
extern long double fmaxl (long double, long double);
extern long double fminl (long double, long double);
extern long double fmal (long double, long double, long double);
extern long double acoshl (long double);
extern long double atanhl (long double);
extern long double remainderl (long double, long double);
extern long double lgammal (long double);
extern long double erfl (long double);
extern long double erfcl (long double);
extern double drem (double, double);
extern float dremf (float, float);
extern double gamma_r (double, int *);
extern double lgamma_r (double, int *);
extern float gammaf_r (float, int *);
extern float lgammaf_r (float, int *);
extern double y0 (double);
extern double y1 (double);
extern double yn (int, double);
extern double j0 (double);
extern double j1 (double);
extern double jn (int, double);
extern float y0f (float);
extern float y1f (float);
extern float ynf (int, float);
extern float j0f (float);
extern float j1f (float);
extern float jnf (int, float);
extern int *__signgam (void);

typedef enum
{
  HAL_OK = 0x00,
  HAL_ERROR = 0x01,
  HAL_BUSY = 0x02,
  HAL_TIMEOUT = 0x03
} HAL_StatusTypeDef;
typedef enum
{
  HAL_UNLOCKED = 0x00,
  HAL_LOCKED = 0x01
} HAL_LockTypeDef;
typedef struct
{
  uint32_t PLLState;
  uint32_t PLLSource;
  uint32_t PLLM;
  uint32_t PLLMBOOST;
  uint32_t PLLN;
  uint32_t PLLP;
  uint32_t PLLQ;
  uint32_t PLLR;
  uint32_t PLLRGE;
  uint32_t PLLFRACN;
} RCC_PLLInitTypeDef;
typedef struct
{
  uint32_t OscillatorType;
  uint32_t HSEState;
  uint32_t LSEState;
  uint32_t HSIState;
  uint32_t HSICalibrationValue;
  uint32_t LSIState;
  uint32_t LSIDiv;
  uint32_t MSIState;
  uint32_t MSICalibrationValue;
  uint32_t MSIClockRange;
  uint32_t MSIKClockRange;
  uint32_t HSI48State;
  uint32_t SHSIState;
  uint32_t MSIKState;
  RCC_PLLInitTypeDef PLL;
} RCC_OscInitTypeDef;
typedef struct
{
  uint32_t ClockType;
  uint32_t SYSCLKSource;
  uint32_t AHBCLKDivider;
  uint32_t APB1CLKDivider;
  uint32_t APB2CLKDivider;
  uint32_t APB3CLKDivider;
} RCC_ClkInitTypeDef;
typedef struct
{
  uint32_t PLL2Source;
  uint32_t PLL2M;
  uint32_t PLL2N;
  uint32_t PLL2P;
  uint32_t PLL2Q;
  uint32_t PLL2R;
  uint32_t PLL2RGE;
  uint32_t PLL2FRACN;
  uint32_t PLL2ClockOut;
} RCC_PLL2InitTypeDef;
typedef struct
{
  uint32_t PLL3Source;
  uint32_t PLL3M;
  uint32_t PLL3N;
  uint32_t PLL3P;
  uint32_t PLL3Q;
  uint32_t PLL3R;
  uint32_t PLL3RGE;
  uint32_t PLL3FRACN;
  uint32_t PLL3ClockOut;
} RCC_PLL3InitTypeDef;
typedef struct
{
  uint32_t PLL1_P_Frequency;
  uint32_t PLL1_Q_Frequency;
  uint32_t PLL1_R_Frequency;
} PLL1_ClocksTypeDef;
typedef struct
{
  uint32_t PLL2_P_Frequency;
  uint32_t PLL2_Q_Frequency;
  uint32_t PLL2_R_Frequency;
} PLL2_ClocksTypeDef;
typedef struct
{
  uint32_t PLL3_P_Frequency;
  uint32_t PLL3_Q_Frequency;
  uint32_t PLL3_R_Frequency;
} PLL3_ClocksTypeDef;
typedef struct
{
  uint64_t PeriphClockSelection;
  RCC_PLL2InitTypeDef PLL2;
  RCC_PLL3InitTypeDef PLL3;
  uint32_t Usart1ClockSelection;
  uint32_t Usart2ClockSelection;
  uint32_t Usart3ClockSelection;
  uint32_t Uart4ClockSelection;
  uint32_t Uart5ClockSelection;
  uint32_t Lpuart1ClockSelection;
  uint32_t I2c1ClockSelection;
  uint32_t I2c2ClockSelection;
  uint32_t I2c3ClockSelection;
  uint32_t I2c4ClockSelection;
  uint32_t Lptim1ClockSelection;
  uint32_t Lptim2ClockSelection;
  uint32_t Lptim34ClockSelection;
  uint32_t Fdcan1ClockSelection;
  uint32_t Mdf1ClockSelection;
  uint32_t Adf1ClockSelection;
  uint32_t Sai1ClockSelection;
  uint32_t Sai2ClockSelection;
  uint32_t RngClockSelection;
  uint32_t IclkClockSelection;
  uint32_t SdmmcClockSelection;
  uint32_t AdcDacClockSelection;
  uint32_t Dac1ClockSelection;
  uint32_t OspiClockSelection;
  uint32_t Spi1ClockSelection;
  uint32_t Spi2ClockSelection;
  uint32_t Spi3ClockSelection;
  uint32_t RTCClockSelection;
} RCC_PeriphCLKInitTypeDef;
typedef struct
{
  uint32_t Prescaler;
  uint32_t Source;
  uint32_t Polarity;
  uint32_t ReloadValue;
  uint32_t ErrorLimitValue;
  uint32_t HSI48CalibrationValue;
} RCC_CRSInitTypeDef;
typedef struct
{
  uint32_t ReloadValue;
  uint32_t HSI48CalibrationValue;
  uint32_t FreqErrorCapture;
  uint32_t FreqErrorDirection;
} RCC_CRSSynchroInfoTypeDef;
HAL_StatusTypeDef HAL_RCCEx_PeriphCLKConfig(const RCC_PeriphCLKInitTypeDef *pPeriphClkInit);
void HAL_RCCEx_GetPeriphCLKConfig(RCC_PeriphCLKInitTypeDef *pPeriphClkInit);
uint32_t HAL_RCCEx_GetPeriphCLKFreq(uint64_t PeriphClk);
void HAL_RCCEx_GetPLL1ClockFreq(PLL1_ClocksTypeDef *PLL1_Clocks);
void HAL_RCCEx_GetPLL2ClockFreq(PLL2_ClocksTypeDef *PLL2_Clocks);
void HAL_RCCEx_GetPLL3ClockFreq(PLL3_ClocksTypeDef *PLL3_Clocks);
HAL_StatusTypeDef HAL_RCCEx_EnablePLL2(const RCC_PLL2InitTypeDef *PLL2Init);
HAL_StatusTypeDef HAL_RCCEx_DisablePLL2(void);
HAL_StatusTypeDef HAL_RCCEx_EnablePLL3(const RCC_PLL3InitTypeDef *PLL3Init);
HAL_StatusTypeDef HAL_RCCEx_DisablePLL3(void);
HAL_StatusTypeDef HAL_RCCEx_EnableMSIPLLFastStartup(void);
HAL_StatusTypeDef HAL_RCCEx_DisableMSIPLLFastStartup(void);
HAL_StatusTypeDef HAL_RCCEx_EnableMSIPLLModeSelection(uint32_t MSIPLLModeSelection);
void HAL_RCCEx_WakeUpStopCLKConfig(uint32_t WakeUpClk);
void HAL_RCCEx_KerWakeUpStopCLKConfig(uint32_t WakeUpClk);
void HAL_RCCEx_StandbyMSIRangeConfig(uint32_t MSIRange);
void HAL_RCCEx_StandbyMSIKRangeConfig(uint32_t MSIKRange);
void HAL_RCCEx_EnableLSECSS(void);
void HAL_RCCEx_DisableLSECSS(void);
void HAL_RCCEx_EnableLSECSS_IT(void);
void HAL_RCCEx_EnableMSIPLLUNLCK_IT(void);
void HAL_RCCEx_LSECSS_IRQHandler(void);
void HAL_RCCEx_LSECSS_Callback(void);
void HAL_RCCEx_MSIPLLUNLCK_IRQHandler(void);
void HAL_RCCEx_MSIPLLUNLCK_Callback(void);
void HAL_RCCEx_EnableLSCO(uint32_t LSCOSource);
void HAL_RCCEx_DisableLSCO(void);
void HAL_RCCEx_EnableMSIPLLMode(void);
void HAL_RCCEx_DisableMSIPLLMode(void);
void HAL_RCCEx_CRSConfig(const RCC_CRSInitTypeDef *const pInit);
void HAL_RCCEx_CRSSoftwareSynchronizationGenerate(void);
void HAL_RCCEx_CRSGetSynchronizationInfo(RCC_CRSSynchroInfoTypeDef *pSynchroInfo);
uint32_t HAL_RCCEx_CRSWaitSynchronization(uint32_t Timeout);
void HAL_RCCEx_CRS_IRQHandler(void);
void HAL_RCCEx_CRS_SyncOkCallback(void);
void HAL_RCCEx_CRS_SyncWarnCallback(void);
void HAL_RCCEx_CRS_ExpectedSyncCallback(void);
void HAL_RCCEx_CRS_ErrorCallback(uint32_t Error);
HAL_StatusTypeDef HAL_RCC_DeInit(void);
HAL_StatusTypeDef HAL_RCC_OscConfig(const RCC_OscInitTypeDef *pRCC_OscInitStruct);
HAL_StatusTypeDef HAL_RCC_ClockConfig(const RCC_ClkInitTypeDef *const pRCC_ClkInitStruct, uint32_t FLatency);
void HAL_RCC_MCOConfig(uint32_t RCC_MCOx, uint32_t RCC_MCOSource, uint32_t RCC_MCODiv);
void HAL_RCC_EnableCSS(void);
uint32_t HAL_RCC_GetSysClockFreq(void);
uint32_t HAL_RCC_GetHCLKFreq(void);
uint32_t HAL_RCC_GetPCLK1Freq(void);
uint32_t HAL_RCC_GetPCLK2Freq(void);
uint32_t HAL_RCC_GetPCLK3Freq(void);
void HAL_RCC_GetOscConfig(RCC_OscInitTypeDef *pRCC_OscInitStruct);
void HAL_RCC_GetClockConfig(RCC_ClkInitTypeDef *pRCC_ClkInitStruct, uint32_t *pFLatency);
uint32_t HAL_RCC_GetResetSource(void);
void HAL_RCC_NMI_IRQHandler(void);
void HAL_RCC_CSSCallback(void);
void HAL_RCC_ConfigAttributes(uint32_t Item, uint32_t Attributes);
HAL_StatusTypeDef HAL_RCC_GetConfigAttributes(uint32_t Item, uint32_t *pAttributes);
typedef struct
{
  uint32_t Pin;
  uint32_t Mode;
  uint32_t Pull;
  uint32_t Speed;
  uint32_t Alternate;
} GPIO_InitTypeDef;
typedef enum
{
  GPIO_PIN_RESET = 0U,
  GPIO_PIN_SET
} GPIO_PinState;
typedef struct
{
  GPIO_TypeDef *GPIO_PORT;
  uint32_t Pin_Pos;
} LPGPIO_MapTypeDef;
void HAL_GPIO_Init(GPIO_TypeDef *GPIOx, const GPIO_InitTypeDef *pGPIO_Init);
void HAL_GPIO_DeInit(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);
GPIO_PinState HAL_GPIO_ReadPin(const GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);
void HAL_GPIO_WriteMultipleStatePin(GPIO_TypeDef *GPIOx, uint16_t PinReset, uint16_t PinSet);
void HAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void HAL_GPIO_EnableHighSPeedLowVoltage(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void HAL_GPIO_DisableHighSPeedLowVoltage(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
HAL_StatusTypeDef HAL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void HAL_GPIO_EXTI_IRQHandler(uint16_t GPIO_Pin);
void HAL_GPIO_EXTI_Rising_Callback(uint16_t GPIO_Pin);
void HAL_GPIO_EXTI_Falling_Callback(uint16_t GPIO_Pin);
typedef struct
{
  uint32_t BaseAddress;
  uint32_t RemapAddress;
  uint32_t Size;
  uint32_t TrafficRoute;
  uint32_t OutputBurstType;
} ICACHE_RegionConfigTypeDef;
HAL_StatusTypeDef HAL_ICACHE_Enable(void);
HAL_StatusTypeDef HAL_ICACHE_Disable(void);
uint32_t HAL_ICACHE_IsEnabled(void);
HAL_StatusTypeDef HAL_ICACHE_ConfigAssociativityMode(uint32_t AssociativityMode);
HAL_StatusTypeDef HAL_ICACHE_DeInit(void);
HAL_StatusTypeDef HAL_ICACHE_Invalidate(void);
HAL_StatusTypeDef HAL_ICACHE_Invalidate_IT(void);
HAL_StatusTypeDef HAL_ICACHE_WaitForInvalidateComplete(void);
HAL_StatusTypeDef HAL_ICACHE_Monitor_Start(uint32_t MonitorType);
HAL_StatusTypeDef HAL_ICACHE_Monitor_Stop(uint32_t MonitorType);
HAL_StatusTypeDef HAL_ICACHE_Monitor_Reset(uint32_t MonitorType);
uint32_t HAL_ICACHE_Monitor_GetHitValue(void);
uint32_t HAL_ICACHE_Monitor_GetMissValue(void);
void HAL_ICACHE_IRQHandler(void);
void HAL_ICACHE_InvalidateCompleteCallback(void);
void HAL_ICACHE_ErrorCallback(void);
HAL_StatusTypeDef HAL_ICACHE_EnableRemapRegion(uint32_t Region, const ICACHE_RegionConfigTypeDef *const pRegionConfig);
HAL_StatusTypeDef HAL_ICACHE_DisableRemapRegion(uint32_t Region);
typedef struct
{
  uint32_t MPCBB_SecConfig_array[(32U)];
  uint32_t MPCBB_PrivConfig_array[(32U)];
  uint32_t MPCBB_LockConfig_array[(1U)];
} MPCBB_Attribute_ConfigTypeDef;
typedef struct
{
  uint32_t SecureRWIllegalMode;
  uint32_t InvertSecureState;
  MPCBB_Attribute_ConfigTypeDef AttributeConfig;
} MPCBB_ConfigTypeDef;
typedef struct
{
  uint32_t AreaId;
  uint32_t Offset;
  uint32_t Length;
  uint32_t Attribute;
  uint32_t Lock;
  uint32_t AreaStatus;
} MPCWM_ConfigTypeDef;
HAL_StatusTypeDef HAL_GTZC_TZSC_ConfigPeriphAttributes(uint32_t PeriphId,
                                                       uint32_t PeriphAttributes);
HAL_StatusTypeDef HAL_GTZC_TZSC_GetConfigPeriphAttributes(uint32_t PeriphId,
                                                          uint32_t *PeriphAttributes);
HAL_StatusTypeDef HAL_GTZC_MPCBB_ConfigMem(uint32_t MemBaseAddress,
                                           const MPCBB_ConfigTypeDef *pMPCBB_desc);
HAL_StatusTypeDef HAL_GTZC_MPCBB_GetConfigMem(uint32_t MemBaseAddress,
                                              MPCBB_ConfigTypeDef *pMPCBB_desc);
HAL_StatusTypeDef HAL_GTZC_MPCBB_ConfigMemAttributes(uint32_t MemAddress,
                                                     uint32_t NbBlocks,
                                                     const uint32_t *pMemAttributes);
HAL_StatusTypeDef HAL_GTZC_MPCBB_GetConfigMemAttributes(uint32_t MemAddress,
                                                        uint32_t NbBlocks,
                                                        uint32_t *pMemAttributes);
typedef struct
{
  uint32_t Request;
  uint32_t BlkHWRequest;
  uint32_t Direction;
  uint32_t SrcInc;
  uint32_t DestInc;
  uint32_t SrcDataWidth;
  uint32_t DestDataWidth;
  uint32_t Priority;
  uint32_t SrcBurstLength;
  uint32_t DestBurstLength;
  uint32_t TransferAllocatedPort;
  uint32_t TransferEventMode;
  uint32_t Mode;
} DMA_InitTypeDef;
typedef struct
{
  uint32_t Priority;
  uint32_t LinkStepMode;
  uint32_t LinkAllocatedPort;
  uint32_t TransferEventMode;
  uint32_t LinkedListMode;
} DMA_InitLinkedListTypeDef;
typedef enum
{
  HAL_DMA_STATE_RESET = 0x00U,
  HAL_DMA_STATE_READY = 0x01U,
  HAL_DMA_STATE_BUSY = 0x02U,
  HAL_DMA_STATE_ERROR = 0x03U,
  HAL_DMA_STATE_ABORT = 0x04U,
  HAL_DMA_STATE_SUSPEND = 0x05U,
} HAL_DMA_StateTypeDef;
typedef enum
{
  HAL_DMA_FULL_TRANSFER = 0x00U,
  HAL_DMA_HALF_TRANSFER = 0x01U,
} HAL_DMA_LevelCompleteTypeDef;
typedef enum
{
  HAL_DMA_XFER_CPLT_CB_ID = 0x00U,
  HAL_DMA_XFER_HALFCPLT_CB_ID = 0x01U,
  HAL_DMA_XFER_ERROR_CB_ID = 0x02U,
  HAL_DMA_XFER_ABORT_CB_ID = 0x03U,
  HAL_DMA_XFER_SUSPEND_CB_ID = 0x04U,
  HAL_DMA_XFER_ALL_CB_ID = 0x05U
} HAL_DMA_CallbackIDTypeDef;
typedef struct __DMA_HandleTypeDef
{
  DMA_Channel_TypeDef *Instance;
  DMA_InitTypeDef Init;
  DMA_InitLinkedListTypeDef InitLinkedList;
  HAL_LockTypeDef Lock;
  uint32_t Mode;
  volatile HAL_DMA_StateTypeDef State;
  volatile uint32_t ErrorCode;
  void *Parent;
  void (* XferCpltCallback)(struct __DMA_HandleTypeDef *hdma);
  void (* XferHalfCpltCallback)(struct __DMA_HandleTypeDef *hdma);
  void (* XferErrorCallback)(struct __DMA_HandleTypeDef *hdma);
  void (* XferAbortCallback)(struct __DMA_HandleTypeDef *hdma);
  void (* XferSuspendCallback)(struct __DMA_HandleTypeDef *hdma);
  struct __DMA_QListTypeDef *LinkedListQueue;
} DMA_HandleTypeDef;
typedef struct
{
  uint32_t DataExchange;
  uint32_t DataAlignment;
} DMA_DataHandlingConfTypeDef;
typedef struct
{
  uint32_t TriggerMode;
  uint32_t TriggerPolarity;
  uint32_t TriggerSelection;
} DMA_TriggerConfTypeDef;
typedef struct
{
  uint32_t RepeatCount;
  int32_t SrcAddrOffset;
  int32_t DestAddrOffset;
  int32_t BlkSrcAddrOffset;
  int32_t BlkDestAddrOffset;
} DMA_RepeatBlockConfTypeDef;
typedef enum
{
  HAL_DMA_QUEUE_STATE_RESET = 0x00U,
  HAL_DMA_QUEUE_STATE_READY = 0x01U,
  HAL_DMA_QUEUE_STATE_BUSY = 0x02U
} HAL_DMA_QStateTypeDef;
typedef struct
{
  uint32_t NodeType;
  DMA_InitTypeDef Init;
  DMA_DataHandlingConfTypeDef DataHandlingConfig;
  DMA_TriggerConfTypeDef TriggerConfig;
  DMA_RepeatBlockConfTypeDef RepeatBlockConfig;
  uint32_t SrcAddress;
  uint32_t DstAddress;
  uint32_t DataSize;
} DMA_NodeConfTypeDef;
typedef struct
{
  uint32_t LinkRegisters[8U];
  uint32_t NodeInfo;
} DMA_NodeTypeDef;
typedef struct __DMA_QListTypeDef
{
  DMA_NodeTypeDef *Head;
  DMA_NodeTypeDef *FirstCircularNode;
  uint32_t NodeNumber;
  volatile HAL_DMA_QStateTypeDef State;
  volatile uint32_t ErrorCode;
  volatile uint32_t Type;
} DMA_QListTypeDef;
HAL_StatusTypeDef HAL_DMAEx_List_Init(DMA_HandleTypeDef *const hdma);
HAL_StatusTypeDef HAL_DMAEx_List_DeInit(DMA_HandleTypeDef *const hdma);
HAL_StatusTypeDef HAL_DMAEx_List_Start(DMA_HandleTypeDef *const hdma);
HAL_StatusTypeDef HAL_DMAEx_List_Start_IT(DMA_HandleTypeDef *const hdma);
HAL_StatusTypeDef HAL_DMAEx_List_BuildNode(DMA_NodeConfTypeDef const *const pNodeConfig,
                                           DMA_NodeTypeDef *const pNode);
HAL_StatusTypeDef HAL_DMAEx_List_GetNodeConfig(DMA_NodeConfTypeDef *const pNodeConfig,
                                               DMA_NodeTypeDef const *const pNode);
HAL_StatusTypeDef HAL_DMAEx_List_InsertNode(DMA_QListTypeDef *const pQList,
                                            DMA_NodeTypeDef *const pPrevNode,
                                            DMA_NodeTypeDef *const pNewNode);
HAL_StatusTypeDef HAL_DMAEx_List_InsertNode_Head(DMA_QListTypeDef *const pQList,
                                                 DMA_NodeTypeDef *const pNewNode);
HAL_StatusTypeDef HAL_DMAEx_List_InsertNode_Tail(DMA_QListTypeDef *const pQList,
                                                 DMA_NodeTypeDef *const pNewNode);
HAL_StatusTypeDef HAL_DMAEx_List_RemoveNode(DMA_QListTypeDef *const pQList,
                                            DMA_NodeTypeDef *const pNode);
HAL_StatusTypeDef HAL_DMAEx_List_RemoveNode_Head(DMA_QListTypeDef *const pQList);
HAL_StatusTypeDef HAL_DMAEx_List_RemoveNode_Tail(DMA_QListTypeDef *const pQList);
HAL_StatusTypeDef HAL_DMAEx_List_ReplaceNode(DMA_QListTypeDef *const pQList,
                                             DMA_NodeTypeDef *const pOldNode,
                                             DMA_NodeTypeDef *const pNewNode);
HAL_StatusTypeDef HAL_DMAEx_List_ReplaceNode_Head(DMA_QListTypeDef *const pQList,
                                                  DMA_NodeTypeDef *const pNewNode);
HAL_StatusTypeDef HAL_DMAEx_List_ReplaceNode_Tail(DMA_QListTypeDef *const pQList,
                                                  DMA_NodeTypeDef *const pNewNode);
HAL_StatusTypeDef HAL_DMAEx_List_ResetQ(DMA_QListTypeDef *const pQList);
HAL_StatusTypeDef HAL_DMAEx_List_InsertQ(DMA_QListTypeDef *const pSrcQList,
                                         DMA_NodeTypeDef const *const pPrevNode,
                                         DMA_QListTypeDef *const pDestQList);
HAL_StatusTypeDef HAL_DMAEx_List_InsertQ_Head(DMA_QListTypeDef *const pSrcQList,
                                              DMA_QListTypeDef *const pDestQList);
HAL_StatusTypeDef HAL_DMAEx_List_InsertQ_Tail(DMA_QListTypeDef *const pSrcQList,
                                              DMA_QListTypeDef *const pDestQList);
HAL_StatusTypeDef HAL_DMAEx_List_SetCircularModeConfig(DMA_QListTypeDef *const pQList,
                                                       DMA_NodeTypeDef *const pFirstCircularNode);
HAL_StatusTypeDef HAL_DMAEx_List_SetCircularMode(DMA_QListTypeDef *const pQList);
HAL_StatusTypeDef HAL_DMAEx_List_ClearCircularMode(DMA_QListTypeDef *const pQList);
HAL_StatusTypeDef HAL_DMAEx_List_ConvertQToDynamic(DMA_QListTypeDef *const pQList);
HAL_StatusTypeDef HAL_DMAEx_List_ConvertQToStatic(DMA_QListTypeDef *const pQList);
HAL_StatusTypeDef HAL_DMAEx_List_LinkQ(DMA_HandleTypeDef *const hdma,
                                       DMA_QListTypeDef *const pQList);
HAL_StatusTypeDef HAL_DMAEx_List_UnLinkQ(DMA_HandleTypeDef *const hdma);
HAL_StatusTypeDef HAL_DMAEx_ConfigDataHandling(DMA_HandleTypeDef *const hdma,
                                               DMA_DataHandlingConfTypeDef const *const pConfigDataHandling);
HAL_StatusTypeDef HAL_DMAEx_ConfigTrigger(DMA_HandleTypeDef *const hdma,
                                          DMA_TriggerConfTypeDef const *const pConfigTrigger);
HAL_StatusTypeDef HAL_DMAEx_ConfigRepeatBlock(DMA_HandleTypeDef *const hdma,
                                              DMA_RepeatBlockConfTypeDef const *const pConfigRepeatBlock);
HAL_StatusTypeDef HAL_DMAEx_Suspend(DMA_HandleTypeDef *const hdma);
HAL_StatusTypeDef HAL_DMAEx_Suspend_IT(DMA_HandleTypeDef *const hdma);
HAL_StatusTypeDef HAL_DMAEx_Resume(DMA_HandleTypeDef *const hdma);
uint32_t HAL_DMAEx_GetFifoLevel(DMA_HandleTypeDef const *const hdma);
typedef struct
{
  uint32_t cllr_offset;
  uint32_t previousnode_addr;
  uint32_t currentnode_pos;
  uint32_t currentnode_addr;
  uint32_t nextnode_addr;
} DMA_NodeInQInfoTypeDef;
HAL_StatusTypeDef HAL_DMA_Init(DMA_HandleTypeDef *const hdma);
HAL_StatusTypeDef HAL_DMA_DeInit(DMA_HandleTypeDef *const hdma);
HAL_StatusTypeDef HAL_DMA_Start(DMA_HandleTypeDef *const hdma,
                                uint32_t SrcAddress,
                                uint32_t DstAddress,
                                uint32_t SrcDataSize);
HAL_StatusTypeDef HAL_DMA_Start_IT(DMA_HandleTypeDef *const hdma,
                                   uint32_t SrcAddress,
                                   uint32_t DstAddress,
                                   uint32_t SrcDataSize);
HAL_StatusTypeDef HAL_DMA_Abort(DMA_HandleTypeDef *const hdma);
HAL_StatusTypeDef HAL_DMA_Abort_IT(DMA_HandleTypeDef *const hdma);
HAL_StatusTypeDef HAL_DMA_PollForTransfer(DMA_HandleTypeDef *const hdma,
                                          HAL_DMA_LevelCompleteTypeDef CompleteLevel,
                                          uint32_t Timeout);
void HAL_DMA_IRQHandler(DMA_HandleTypeDef *const hdma);
HAL_StatusTypeDef HAL_DMA_RegisterCallback(DMA_HandleTypeDef *const hdma,
                                           HAL_DMA_CallbackIDTypeDef CallbackID,
                                           void (*const pCallback)(DMA_HandleTypeDef *const _hdma));
HAL_StatusTypeDef HAL_DMA_UnRegisterCallback(DMA_HandleTypeDef *const hdma,
                                             HAL_DMA_CallbackIDTypeDef CallbackID);
HAL_DMA_StateTypeDef HAL_DMA_GetState(DMA_HandleTypeDef const *const hdma);
uint32_t HAL_DMA_GetError(DMA_HandleTypeDef const *const hdma);
HAL_StatusTypeDef HAL_DMA_ConfigChannelAttributes(DMA_HandleTypeDef *const hdma,
                                                  uint32_t ChannelAttributes);
HAL_StatusTypeDef HAL_DMA_GetConfigChannelAttributes(DMA_HandleTypeDef const *const hdma,
                                                     uint32_t *const pChannelAttributes);
HAL_StatusTypeDef HAL_DMA_GetLockChannelAttributes(DMA_HandleTypeDef const *const hdma,
                                                   uint32_t *const pLockState);
typedef struct
{
  uint8_t Enable;
  uint8_t Number;
  uint32_t BaseAddress;
  uint32_t LimitAddress;
  uint8_t AttributesIndex;
  uint8_t AccessPermission;
  uint8_t DisableExec;
  uint8_t IsShareable;
} MPU_Region_InitTypeDef;
typedef struct
{
  uint8_t Number;
  uint8_t Attributes;
} MPU_Attributes_InitTypeDef;
void HAL_NVIC_SetPriorityGrouping(uint32_t PriorityGroup);
void HAL_NVIC_SetPriority(IRQn_Type IRQn, uint32_t PreemptPriority, uint32_t SubPriority);
void HAL_NVIC_EnableIRQ(IRQn_Type IRQn);
void HAL_NVIC_DisableIRQ(IRQn_Type IRQn);
void HAL_NVIC_SystemReset(void);
uint32_t HAL_SYSTICK_Config(uint32_t TicksNumb);
uint32_t HAL_NVIC_GetPriorityGrouping(void);
void HAL_NVIC_GetPriority(IRQn_Type IRQn, uint32_t PriorityGroup, uint32_t *const pPreemptPriority,
                          uint32_t *const pSubPriority);
uint32_t HAL_NVIC_GetPendingIRQ(IRQn_Type IRQn);
void HAL_NVIC_SetPendingIRQ(IRQn_Type IRQn);
void HAL_NVIC_ClearPendingIRQ(IRQn_Type IRQn);
uint32_t HAL_NVIC_GetActive(IRQn_Type IRQn);
void HAL_SYSTICK_CLKSourceConfig(uint32_t CLKSource);
uint32_t HAL_SYSTICK_GetCLKSourceConfig(void);
void HAL_SYSTICK_IRQHandler(void);
void HAL_SYSTICK_Callback(void);
void HAL_MPU_Enable(uint32_t MPU_Control);
void HAL_MPU_Disable(void);
void HAL_MPU_EnableRegion(uint32_t RegionNumber);
void HAL_MPU_DisableRegion(uint32_t RegionNumber);
void HAL_MPU_ConfigRegion(const MPU_Region_InitTypeDef *const pMPU_RegionInit);
void HAL_MPU_ConfigMemoryAttributes(const MPU_Attributes_InitTypeDef *const pMPU_AttributesInit);
typedef struct
{
  uint32_t TypeErase;
  uint32_t Banks;
  uint32_t Page;
  uint32_t NbPages;
} FLASH_EraseInitTypeDef;
typedef struct
{
  uint32_t OptionType;
  uint32_t WRPArea;
  uint32_t WRPStartOffset;
  uint32_t WRPEndOffset;
  FunctionalState WRPLock;
  uint32_t RDPLevel;
  uint32_t USERType;
  uint32_t USERConfig;
  uint32_t BootAddrConfig;
  uint32_t BootAddr;
  uint32_t RDPKeyType;
  uint32_t RDPKey1;
  uint32_t RDPKey2;
} FLASH_OBProgramInitTypeDef;
typedef struct
{
  HAL_LockTypeDef Lock;
  uint32_t ErrorCode;
  uint32_t ProcedureOnGoing;
  uint32_t Address;
  uint32_t Bank;
  uint32_t Page;
  uint32_t NbPagesToErase;
} FLASH_ProcessTypeDef;
typedef struct
{
  uint32_t Bank;
  uint32_t BBAttributesType;
  uint32_t BBAttributes_array[(4U)];
} FLASH_BBAttributesTypeDef;
typedef struct
{
  uint32_t OperationType;
  uint32_t FlashArea;
  uint32_t Address;
} FLASH_OperationTypeDef;
HAL_StatusTypeDef HAL_FLASHEx_Erase(FLASH_EraseInitTypeDef *pEraseInit, uint32_t *PageError);
HAL_StatusTypeDef HAL_FLASHEx_Erase_IT(FLASH_EraseInitTypeDef *pEraseInit);
HAL_StatusTypeDef HAL_FLASHEx_OBProgram(FLASH_OBProgramInitTypeDef *pOBInit);
void HAL_FLASHEx_OBGetConfig(FLASH_OBProgramInitTypeDef *pOBInit);
HAL_StatusTypeDef HAL_FLASHEx_ConfigBBAttributes(FLASH_BBAttributesTypeDef *pBBAttributes);
void HAL_FLASHEx_GetConfigBBAttributes(FLASH_BBAttributesTypeDef *pBBAttributes);
void HAL_FLASHEx_ConfigPrivMode(uint32_t PrivMode);
uint32_t HAL_FLASHEx_GetPrivMode(void);
HAL_StatusTypeDef HAL_FLASHEx_EnablePowerDown(uint32_t Banks);
HAL_StatusTypeDef HAL_FLASHEx_ConfigLowPowerRead(uint32_t ConfigLPM);
uint32_t HAL_FLASHEx_GetLowPowerRead(void);
void HAL_FLASHEx_GetOperation(FLASH_OperationTypeDef *pFlashOperation);
void FLASH_PageErase(uint32_t Page, uint32_t Banks);
HAL_StatusTypeDef HAL_FLASH_Program(uint32_t TypeProgram, uint32_t Address, uint32_t DataAddress);
HAL_StatusTypeDef HAL_FLASH_Program_IT(uint32_t TypeProgram, uint32_t Address, uint32_t DataAddress);
void HAL_FLASH_IRQHandler(void);
void HAL_FLASH_EndOfOperationCallback(uint32_t ReturnValue);
void HAL_FLASH_OperationErrorCallback(uint32_t ReturnValue);
HAL_StatusTypeDef HAL_FLASH_Unlock(void);
HAL_StatusTypeDef HAL_FLASH_Lock(void);
HAL_StatusTypeDef HAL_FLASH_OB_Unlock(void);
HAL_StatusTypeDef HAL_FLASH_OB_Lock(void);
HAL_StatusTypeDef HAL_FLASH_OB_Launch(void);
uint32_t HAL_FLASH_GetError(void);
extern FLASH_ProcessTypeDef pFlash;
HAL_StatusTypeDef FLASH_WaitForLastOperation(uint32_t Timeout);
typedef struct
{
  uint32_t DataType;
  uint32_t KeySize;
  uint8_t *pKey;
} HASH_InitTypeDef;
typedef enum
{
  HAL_HASH_STATE_RESET = 0x00U,
  HAL_HASH_STATE_READY = 0x01U,
  HAL_HASH_STATE_BUSY = 0x02U,
  HAL_HASH_STATE_TIMEOUT = 0x06U,
  HAL_HASH_STATE_ERROR = 0x07U,
  HAL_HASH_STATE_SUSPENDED = 0x08U
} HAL_HASH_StateTypeDef;
typedef enum
{
  HAL_HASH_PHASE_READY = 0x01U,
  HAL_HASH_PHASE_PROCESS = 0x02U,
  HAL_HASH_PHASE_HMAC_STEP_1 = 0x03U,
  HAL_HASH_PHASE_HMAC_STEP_2 = 0x04U,
  HAL_HASH_PHASE_HMAC_STEP_3 = 0x05U
} HAL_HASH_PhaseTypeDef;
typedef enum
{
  HAL_HASH_SUSPEND_NONE = 0x00U,
  HAL_HASH_SUSPEND = 0x01U
} HAL_HASH_SuspendTypeDef;
typedef struct
{
  HASH_InitTypeDef Init;
  uint8_t const *pHashInBuffPtr;
  uint8_t *pHashOutBuffPtr;
  uint8_t *pHashKeyBuffPtr;
  uint8_t const *pHashMsgBuffPtr;
  uint32_t HashBuffSize;
  volatile uint32_t HashInCount;
  volatile uint32_t HashITCounter;
  volatile uint32_t HashKeyCount;
  HAL_StatusTypeDef Status;
  HAL_HASH_PhaseTypeDef Phase;
  DMA_HandleTypeDef *hdmain;
  HAL_LockTypeDef Lock;
  volatile HAL_HASH_StateTypeDef State;
  HAL_HASH_SuspendTypeDef SuspendRequest;
  FlagStatus DigestCalculationDisable;
  volatile uint32_t NbWordsAlreadyPushed;
  volatile uint32_t ErrorCode;
  volatile uint32_t Accumulation;
} HASH_HandleTypeDef;
HAL_StatusTypeDef HAL_HASHEx_SHA224_Start(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                          uint8_t *pOutBuffer, uint32_t Timeout);
HAL_StatusTypeDef HAL_HASHEx_SHA224_Accmlt(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HASHEx_SHA224_Accmlt_End(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                               uint8_t *pOutBuffer, uint32_t Timeout);
HAL_StatusTypeDef HAL_HASHEx_SHA256_Start(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                          uint8_t *pOutBuffer, uint32_t Timeout);
HAL_StatusTypeDef HAL_HASHEx_SHA256_Accmlt(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HASHEx_SHA256_Accmlt_End(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                               uint8_t *pOutBuffer, uint32_t Timeout);
HAL_StatusTypeDef HAL_HASHEx_SHA224_Start_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                             uint8_t *pOutBuffer);
HAL_StatusTypeDef HAL_HASHEx_SHA224_Accmlt_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HASHEx_SHA224_Accmlt_End_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                                  uint8_t *pOutBuffer);
HAL_StatusTypeDef HAL_HASHEx_SHA256_Start_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                             uint8_t *pOutBuffer);
HAL_StatusTypeDef HAL_HASHEx_SHA256_Accmlt_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HASHEx_SHA256_Accmlt_End_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                                  uint8_t *pOutBuffer);
HAL_StatusTypeDef HAL_HASHEx_SHA224_Start_DMA(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HASHEx_SHA224_Finish(HASH_HandleTypeDef *hhash, uint8_t *pOutBuffer, uint32_t Timeout);
HAL_StatusTypeDef HAL_HASHEx_SHA256_Start_DMA(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HASHEx_SHA256_Finish(HASH_HandleTypeDef *hhash, uint8_t *pOutBuffer, uint32_t Timeout);
HAL_StatusTypeDef HAL_HMACEx_SHA224_Start(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                          uint8_t *pOutBuffer, uint32_t Timeout);
HAL_StatusTypeDef HAL_HMACEx_SHA256_Start(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                          uint8_t *pOutBuffer, uint32_t Timeout);
HAL_StatusTypeDef HAL_HMACEx_SHA224_Start_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                             uint8_t *pOutBuffer);
HAL_StatusTypeDef HAL_HMACEx_SHA256_Start_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                             uint8_t *pOutBuffer);
HAL_StatusTypeDef HAL_HMACEx_SHA224_Start_DMA(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HMACEx_SHA256_Start_DMA(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HMACEx_MD5_Step1_2_DMA(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HMACEx_MD5_Step2_DMA(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HMACEx_MD5_Step2_3_DMA(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HMACEx_SHA1_Step1_2_DMA(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HMACEx_SHA1_Step2_DMA(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HMACEx_SHA1_Step2_3_DMA(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HMACEx_SHA224_Step1_2_DMA(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HMACEx_SHA224_Step2_DMA(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HMACEx_SHA224_Step2_3_DMA(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HMACEx_SHA256_Step1_2_DMA(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HMACEx_SHA256_Step2_DMA(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HMACEx_SHA256_Step2_3_DMA(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HASH_Init(HASH_HandleTypeDef *hhash);
HAL_StatusTypeDef HAL_HASH_DeInit(HASH_HandleTypeDef *hhash);
void HAL_HASH_MspInit(HASH_HandleTypeDef *hhash);
void HAL_HASH_MspDeInit(HASH_HandleTypeDef *hhash);
void HAL_HASH_InCpltCallback(HASH_HandleTypeDef *hhash);
void HAL_HASH_DgstCpltCallback(HASH_HandleTypeDef *hhash);
void HAL_HASH_ErrorCallback(HASH_HandleTypeDef *hhash);
HAL_StatusTypeDef HAL_HASH_SHA1_Start(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size, uint8_t *pOutBuffer,
                                      uint32_t Timeout);
HAL_StatusTypeDef HAL_HASH_MD5_Start(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size, uint8_t *pOutBuffer,
                                     uint32_t Timeout);
HAL_StatusTypeDef HAL_HASH_MD5_Accmlt(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HASH_SHA1_Accmlt(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HASH_MD5_Accmlt_End(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                          uint8_t *pOutBuffer, uint32_t Timeout);
HAL_StatusTypeDef HAL_HASH_SHA1_Accmlt_End(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                           uint8_t *pOutBuffer, uint32_t Timeout);
HAL_StatusTypeDef HAL_HASH_SHA1_Start_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                         uint8_t *pOutBuffer);
HAL_StatusTypeDef HAL_HASH_SHA1_Accmlt_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HASH_SHA1_Accmlt_End_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                              uint8_t *pOutBuffer);
HAL_StatusTypeDef HAL_HASH_MD5_Start_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                        uint8_t *pOutBuffer);
HAL_StatusTypeDef HAL_HASH_MD5_Accmlt_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HASH_MD5_Accmlt_End_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                             uint8_t *pOutBuffer);
void HAL_HASH_IRQHandler(HASH_HandleTypeDef *hhash);
HAL_StatusTypeDef HAL_HASH_SHA1_Start_DMA(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HASH_SHA1_Finish(HASH_HandleTypeDef *hhash, uint8_t *pOutBuffer, uint32_t Timeout);
HAL_StatusTypeDef HAL_HASH_MD5_Start_DMA(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HASH_MD5_Finish(HASH_HandleTypeDef *hhash, uint8_t *pOutBuffer, uint32_t Timeout);
HAL_StatusTypeDef HAL_HMAC_SHA1_Start(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size, uint8_t *pOutBuffer,
                                      uint32_t Timeout);
HAL_StatusTypeDef HAL_HMAC_MD5_Start(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size, uint8_t *pOutBuffer,
                                     uint32_t Timeout);
HAL_StatusTypeDef HAL_HMAC_MD5_Start_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                        uint8_t *pOutBuffer);
HAL_StatusTypeDef HAL_HMAC_SHA1_Start_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                         uint8_t *pOutBuffer);
HAL_StatusTypeDef HAL_HMAC_SHA1_Start_DMA(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HMAC_MD5_Start_DMA(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_HASH_StateTypeDef HAL_HASH_GetState(HASH_HandleTypeDef *hhash);
HAL_StatusTypeDef HAL_HASH_GetStatus(HASH_HandleTypeDef *hhash);
void HAL_HASH_ContextSaving(HASH_HandleTypeDef *hhash, uint8_t *pMemBuffer);
void HAL_HASH_ContextRestoring(HASH_HandleTypeDef *hhash, uint8_t *pMemBuffer);
void HAL_HASH_SwFeed_ProcessSuspend(HASH_HandleTypeDef *hhash);
HAL_StatusTypeDef HAL_HASH_DMAFeed_ProcessSuspend(HASH_HandleTypeDef *hhash);
uint32_t HAL_HASH_GetError(HASH_HandleTypeDef *hhash);
HAL_StatusTypeDef HASH_Start(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size, uint8_t *pOutBuffer,
                             uint32_t Timeout, uint32_t Algorithm);
HAL_StatusTypeDef HASH_Accumulate(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size, uint32_t Algorithm);
HAL_StatusTypeDef HASH_Accumulate_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size, uint32_t Algorithm);
HAL_StatusTypeDef HASH_Start_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size, uint8_t *pOutBuffer,
                                uint32_t Algorithm);
HAL_StatusTypeDef HASH_Start_DMA(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size, uint32_t Algorithm);
HAL_StatusTypeDef HASH_Finish(HASH_HandleTypeDef *hhash, uint8_t *pOutBuffer, uint32_t Timeout);
HAL_StatusTypeDef HMAC_Start(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size, uint8_t *pOutBuffer,
                             uint32_t Timeout, uint32_t Algorithm);
HAL_StatusTypeDef HMAC_Start_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size, uint8_t *pOutBuffer,
                                uint32_t Algorithm);
HAL_StatusTypeDef HMAC_Start_DMA(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size, uint32_t Algorithm);
typedef struct
{
  uint32_t PVDLevel;
  uint32_t Mode;
} PWR_PVDTypeDef;
typedef struct
{
  uint32_t PVMType;
  uint32_t Mode;
} PWR_PVMTypeDef;
HAL_StatusTypeDef HAL_PWREx_ControlVoltageScaling(uint32_t VoltageScaling);
uint32_t HAL_PWREx_GetVoltageRange(void);
HAL_StatusTypeDef HAL_PWREx_ConfigSupply(uint32_t SupplySource);
uint32_t HAL_PWREx_GetSupplyConfig(void);
void HAL_PWREx_EnableFastSoftStart(void);
void HAL_PWREx_DisableFastSoftStart(void);
void HAL_PWREx_EnterSTOP1Mode(uint8_t STOPEntry);
void HAL_PWREx_EnterSTOP2Mode(uint8_t STOPEntry);
void HAL_PWREx_EnterSTOP3Mode(uint8_t STOPEntry);
void HAL_PWREx_EnterSHUTDOWNMode(void);
void HAL_PWREx_ConfigSRDDomain(uint32_t SRDState);
void HAL_PWREx_EnableUltraLowPowerMode(void);
void HAL_PWREx_DisableUltraLowPowerMode(void);
void HAL_PWREx_S3WU_IRQHandler(uint32_t WakeUpPin);
void HAL_PWREx_S3WUCallback(uint32_t WakeUpPin);
void HAL_PWREx_EnableBatteryCharging(uint32_t ResistorValue);
void HAL_PWREx_DisableBatteryCharging(void);
void HAL_PWREx_EnableVddUSB(void);
void HAL_PWREx_DisableVddUSB(void);
void HAL_PWREx_EnableVddIO2(void);
void HAL_PWREx_DisableVddIO2(void);
void HAL_PWREx_EnableVddA(void);
void HAL_PWREx_DisableVddA(void);
void HAL_PWREx_EnableUVM(void);
void HAL_PWREx_DisableUVM(void);
void HAL_PWREx_EnableIO2VM(void);
void HAL_PWREx_DisableIO2VM(void);
void HAL_PWREx_EnableAVM1(void);
void HAL_PWREx_DisableAVM1(void);
void HAL_PWREx_EnableAVM2(void);
void HAL_PWREx_DisableAVM2(void);
HAL_StatusTypeDef HAL_PWREx_ConfigPVM(PWR_PVMTypeDef *pConfigPVM);
void HAL_PWREx_EnableMonitoring(void);
void HAL_PWREx_DisableMonitoring(void);
void HAL_PWREx_EnableUCPDStandbyMode(void);
void HAL_PWREx_DisableUCPDStandbyMode(void);
void HAL_PWREx_EnableUCPDDeadBattery(void);
void HAL_PWREx_DisableUCPDDeadBattery(void);
void HAL_PWREx_PVD_PVM_IRQHandler(void);
void HAL_PWREx_UVMCallback(void);
void HAL_PWREx_IO2VMCallback(void);
void HAL_PWREx_AVM1Callback(void);
void HAL_PWREx_AVM2Callback(void);
void HAL_PWREx_EnableSRAM2ContentStandbyRetention(uint32_t SRAM2Pages);
void HAL_PWREx_DisableSRAM2ContentStandbyRetention(uint32_t SRAM2Pages);
void HAL_PWREx_EnableRAMsContentStopRetention(uint32_t RAMSelection);
void HAL_PWREx_DisableRAMsContentStopRetention(uint32_t RAMSelection);
void HAL_PWREx_EnableRAMsContentRunRetention(uint32_t RAMSelection);
void HAL_PWREx_DisableRAMsContentRunRetention(uint32_t RAMSelection);
void HAL_PWREx_EnableFlashFastWakeUp(void);
void HAL_PWREx_DisableFlashFastWakeUp(void);
void HAL_PWREx_EnableSRAM4FastWakeUp(void);
void HAL_PWREx_DisableSRAM4FastWakeUp(void);
HAL_StatusTypeDef HAL_PWREx_EnableBkupRAMRetention(void);
void HAL_PWREx_DisableBkupRAMRetention(void);
void HAL_PWREx_EnablePullUpPullDownConfig(void);
void HAL_PWREx_DisablePullUpPullDownConfig(void);
HAL_StatusTypeDef HAL_PWREx_EnableGPIOPullUp(uint32_t GPIO_Port, uint32_t GPIO_Pin);
HAL_StatusTypeDef HAL_PWREx_DisableGPIOPullUp(uint32_t GPIO_Port, uint32_t GPIO_Pin);
HAL_StatusTypeDef HAL_PWREx_EnableGPIOPullDown(uint32_t GPIO_Port, uint32_t GPIO_Pin);
HAL_StatusTypeDef HAL_PWREx_DisableGPIOPullDown(uint32_t GPIO_Port, uint32_t GPIO_Pin);
void HAL_PWR_DeInit(void);
void HAL_PWR_EnableBkUpAccess(void);
void HAL_PWR_DisableBkUpAccess(void);
HAL_StatusTypeDef HAL_PWR_ConfigPVD(PWR_PVDTypeDef *pConfigPVD);
void HAL_PWR_EnablePVD(void);
void HAL_PWR_DisablePVD(void);
void HAL_PWR_EnableWakeUpPin(uint32_t WakeUpPin);
void HAL_PWR_DisableWakeUpPin(uint32_t WakeUpPin);
void HAL_PWR_EnterSLEEPMode(uint32_t Regulator, uint8_t SleepEntry);
void HAL_PWR_EnterSTOPMode(uint32_t Regulator, uint8_t StopEntry);
void HAL_PWR_EnterSTANDBYMode(void);
void HAL_PWR_EnableSleepOnExit(void);
void HAL_PWR_DisableSleepOnExit(void);
void HAL_PWR_EnableSEVOnPend(void);
void HAL_PWR_DisableSEVOnPend(void);
void HAL_PWR_PVD_IRQHandler(void);
void HAL_PWR_PVDCallback(void);
void HAL_PWR_ConfigAttributes(uint32_t Item, uint32_t Attributes);
HAL_StatusTypeDef HAL_PWR_GetConfigAttributes(uint32_t Item, uint32_t *pAttributes);
typedef struct
{
  uint32_t ClockErrorDetection;
} RNG_InitTypeDef;
typedef enum
{
  HAL_RNG_STATE_RESET = 0x00U,
  HAL_RNG_STATE_READY = 0x01U,
  HAL_RNG_STATE_BUSY = 0x02U,
  HAL_RNG_STATE_TIMEOUT = 0x03U,
  HAL_RNG_STATE_ERROR = 0x04U
} HAL_RNG_StateTypeDef;
typedef struct
{
  RNG_TypeDef *Instance;
  RNG_InitTypeDef Init;
  HAL_LockTypeDef Lock;
  volatile HAL_RNG_StateTypeDef State;
  volatile uint32_t ErrorCode;
  uint32_t RandomNumber;
} RNG_HandleTypeDef;
typedef struct
{
  uint32_t Config1;
  uint32_t Config2;
  uint32_t Config3;
  uint32_t ClockDivider;
  uint32_t NistCompliance;
  uint32_t AutoReset;
  uint32_t HealthTest;
  uint32_t NoiseSource;
} RNG_ConfigTypeDef;
HAL_StatusTypeDef HAL_RNGEx_SetConfig(RNG_HandleTypeDef *hrng, const RNG_ConfigTypeDef *pConf);
HAL_StatusTypeDef HAL_RNGEx_GetConfig(RNG_HandleTypeDef *hrng, RNG_ConfigTypeDef *pConf);
HAL_StatusTypeDef HAL_RNGEx_LockConfig(RNG_HandleTypeDef *hrng);
HAL_StatusTypeDef HAL_RNGEx_RecoverSeedError(RNG_HandleTypeDef *hrng);
HAL_StatusTypeDef HAL_RNG_Init(RNG_HandleTypeDef *hrng);
HAL_StatusTypeDef HAL_RNG_DeInit(RNG_HandleTypeDef *hrng);
void HAL_RNG_MspInit(RNG_HandleTypeDef *hrng);
void HAL_RNG_MspDeInit(RNG_HandleTypeDef *hrng);
HAL_StatusTypeDef HAL_RNG_GenerateRandomNumber(RNG_HandleTypeDef *hrng, uint32_t *random32bit);
HAL_StatusTypeDef HAL_RNG_GenerateRandomNumber_IT(RNG_HandleTypeDef *hrng);
uint32_t HAL_RNG_ReadLastRandomNumber(const RNG_HandleTypeDef *hrng);
void HAL_RNG_IRQHandler(RNG_HandleTypeDef *hrng);
void HAL_RNG_ErrorCallback(RNG_HandleTypeDef *hrng);
void HAL_RNG_ReadyDataCallback(RNG_HandleTypeDef *hrng, uint32_t random32bit);
HAL_RNG_StateTypeDef HAL_RNG_GetState(const RNG_HandleTypeDef *hrng);
uint32_t HAL_RNG_GetError(const RNG_HandleTypeDef *hrng);
HAL_StatusTypeDef RNG_RecoverSeedError(RNG_HandleTypeDef *hrng);
typedef enum
{
  HAL_RTC_STATE_RESET = 0x00U,
  HAL_RTC_STATE_READY = 0x01U,
  HAL_RTC_STATE_BUSY = 0x02U,
  HAL_RTC_STATE_TIMEOUT = 0x03U,
  HAL_RTC_STATE_ERROR = 0x04U
} HAL_RTCStateTypeDef;
typedef struct
{
  uint32_t HourFormat;
  uint32_t AsynchPrediv;
  uint32_t SynchPrediv;
  uint32_t OutPut;
  uint32_t OutPutRemap;
  uint32_t OutPutPolarity;
  uint32_t OutPutType;
  uint32_t OutPutPullUp;
  uint32_t BinMode;
  uint32_t BinMixBcdU;
} RTC_InitTypeDef;
typedef struct
{
  uint8_t Hours;
  uint8_t Minutes;
  uint8_t Seconds;
  uint8_t TimeFormat;
  uint32_t SubSeconds;
  uint32_t SecondFraction;
  uint32_t DayLightSaving;
  uint32_t StoreOperation;
} RTC_TimeTypeDef;
typedef struct
{
  uint8_t WeekDay;
  uint8_t Month;
  uint8_t Date;
  uint8_t Year;
} RTC_DateTypeDef;
typedef struct
{
  RTC_TimeTypeDef AlarmTime;
  uint32_t AlarmMask;
  uint32_t AlarmSubSecondMask;
  uint32_t BinaryAutoClr;
  uint32_t AlarmDateWeekDaySel;
  uint8_t AlarmDateWeekDay;
  uint32_t FlagAutoClr;
  uint32_t Alarm;
} RTC_AlarmTypeDef;
typedef struct
{
  RTC_TypeDef *Instance;
  RTC_InitTypeDef Init;
  HAL_LockTypeDef Lock;
  volatile HAL_RTCStateTypeDef State;
} RTC_HandleTypeDef;
typedef struct
{
  uint32_t Tamper;
  uint32_t Trigger;
  uint32_t NoErase;
  uint32_t MaskFlag;
  uint32_t Filter;
  uint32_t SamplingFrequency;
  uint32_t PrechargeDuration;
  uint32_t TamperPullUp;
  uint32_t TimeStampOnTamperDetection;
} RTC_TamperTypeDef;
typedef struct
{
  uint32_t Enable;
  uint32_t Interrupt;
  uint32_t Output;
  uint32_t NoErase;
  uint32_t MaskFlag;
} RTC_ATampInputTypeDef;
typedef struct
{
  uint32_t ActiveFilter;
  uint32_t ActiveAsyncPrescaler;
  uint32_t TimeStampOnTamperDetection;
  uint32_t ActiveOutputChangePeriod;
  uint32_t Seed[4U];
  RTC_ATampInputTypeDef TampInput[8U];
} RTC_ActiveTampersTypeDef;
typedef struct
{
  uint32_t IntTamper;
  uint32_t TimeStampOnTamperDetection;
  uint32_t NoErase;
} RTC_InternalTamperTypeDef;
typedef struct
{
  uint32_t rtcSecureFull;
  uint32_t rtcNonSecureFeatures;
  uint32_t tampSecureFull;
  uint32_t backupRegisterStartZone2;
  uint32_t backupRegisterStartZone3;
  uint32_t MonotonicCounterSecure;
} RTC_SecureStateTypeDef;
typedef struct
{
  uint32_t rtcPrivilegeFull;
  uint32_t rtcPrivilegeFeatures;
  uint32_t tampPrivilegeFull;
  uint32_t backupRegisterPrivZone;
  uint32_t backupRegisterStartZone2;
  uint32_t backupRegisterStartZone3;
  uint32_t MonotonicCounterPrivilege;
} RTC_PrivilegeStateTypeDef;
HAL_StatusTypeDef HAL_RTCEx_SetTimeStamp(RTC_HandleTypeDef *hrtc, uint32_t TimeStampEdge,
                                         uint32_t RTC_TimeStampPin);
HAL_StatusTypeDef HAL_RTCEx_SetTimeStamp_IT(RTC_HandleTypeDef *hrtc, uint32_t TimeStampEdge,
                                            uint32_t RTC_TimeStampPin);
HAL_StatusTypeDef HAL_RTCEx_DeactivateTimeStamp(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTCEx_SetInternalTimeStamp(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTCEx_DeactivateInternalTimeStamp(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTCEx_GetTimeStamp(RTC_HandleTypeDef *hrtc, RTC_TimeTypeDef *sTimeStamp,
                                         RTC_DateTypeDef *sTimeStampDate, uint32_t Format);
void HAL_RTCEx_TimeStampIRQHandler(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTCEx_PollForTimeStampEvent(RTC_HandleTypeDef *hrtc, uint32_t Timeout);
void HAL_RTCEx_TimeStampEventCallback(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTCEx_SetWakeUpTimer(RTC_HandleTypeDef *hrtc, uint32_t WakeUpCounter, uint32_t WakeUpClock);
HAL_StatusTypeDef HAL_RTCEx_SetWakeUpTimer_IT(RTC_HandleTypeDef *hrtc, uint32_t WakeUpCounter, uint32_t WakeUpClock,
                                              uint32_t WakeUpAutoClr);
HAL_StatusTypeDef HAL_RTCEx_DeactivateWakeUpTimer(RTC_HandleTypeDef *hrtc);
uint32_t HAL_RTCEx_GetWakeUpTimer(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_WakeUpTimerIRQHandler(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_WakeUpTimerEventCallback(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTCEx_PollForWakeUpTimerEvent(RTC_HandleTypeDef *hrtc, uint32_t Timeout);
HAL_StatusTypeDef HAL_RTCEx_SetSmoothCalib(RTC_HandleTypeDef *hrtc, uint32_t SmoothCalibPeriod,
                                           uint32_t SmoothCalibPlusPulses, uint32_t SmoothCalibMinusPulsesValue);
HAL_StatusTypeDef HAL_RTCEx_SetLowPowerCalib(RTC_HandleTypeDef *hrtc, uint32_t LowPowerCalib);
HAL_StatusTypeDef HAL_RTCEx_SetSynchroShift(RTC_HandleTypeDef *hrtc, uint32_t ShiftAdd1S, uint32_t ShiftSubFS);
HAL_StatusTypeDef HAL_RTCEx_SetCalibrationOutPut(RTC_HandleTypeDef *hrtc, uint32_t CalibOutput);
HAL_StatusTypeDef HAL_RTCEx_DeactivateCalibrationOutPut(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTCEx_SetRefClock(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTCEx_DeactivateRefClock(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTCEx_EnableBypassShadow(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTCEx_DisableBypassShadow(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTCEx_MonotonicCounterIncrement(RTC_HandleTypeDef *hrtc, uint32_t Instance);
HAL_StatusTypeDef HAL_RTCEx_MonotonicCounterGet(RTC_HandleTypeDef *hrtc, uint32_t Instance, uint32_t *Value);
HAL_StatusTypeDef HAL_RTCEx_SetSSRU_IT(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTCEx_DeactivateSSRU(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_SSRUIRQHandler(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_SSRUEventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_AlarmBEventCallback(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTCEx_PollForAlarmBEvent(const RTC_HandleTypeDef *hrtc, uint32_t Timeout);
HAL_StatusTypeDef HAL_RTCEx_SetTamper(RTC_HandleTypeDef *hrtc, RTC_TamperTypeDef *sTamper);
HAL_StatusTypeDef HAL_RTCEx_SetActiveTampers(RTC_HandleTypeDef *hrtc, RTC_ActiveTampersTypeDef *sAllTamper);
HAL_StatusTypeDef HAL_RTCEx_SetActiveSeed(RTC_HandleTypeDef *hrtc, uint32_t *pSeed);
HAL_StatusTypeDef HAL_RTCEx_SetTamper_IT(RTC_HandleTypeDef *hrtc, RTC_TamperTypeDef *sTamper);
HAL_StatusTypeDef HAL_RTCEx_DeactivateTamper(RTC_HandleTypeDef *hrtc, uint32_t Tamper);
HAL_StatusTypeDef HAL_RTCEx_DeactivateActiveTampers(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTCEx_PollForTamperEvent(RTC_HandleTypeDef *hrtc, uint32_t Tamper, uint32_t Timeout);
HAL_StatusTypeDef HAL_RTCEx_SetInternalTamper(RTC_HandleTypeDef *hrtc, RTC_InternalTamperTypeDef *sIntTamper);
HAL_StatusTypeDef HAL_RTCEx_SetInternalTamper_IT(RTC_HandleTypeDef *hrtc, RTC_InternalTamperTypeDef *sIntTamper);
HAL_StatusTypeDef HAL_RTCEx_DeactivateInternalTamper(RTC_HandleTypeDef *hrtc, uint32_t IntTamper);
HAL_StatusTypeDef HAL_RTCEx_PollForInternalTamperEvent(RTC_HandleTypeDef *hrtc, uint32_t IntTamper, uint32_t Timeout);
HAL_StatusTypeDef HAL_RTCEx_SetBoothardwareKey(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_GetActiveTampers(RTC_ActiveTampersTypeDef *sAllTamper);
void HAL_RTCEx_GetInternalTampers(RTC_InternalTamperTypeDef *sIntTamper);
void HAL_RTCEx_TamperIRQHandler(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_Tamper1EventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_Tamper2EventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_Tamper3EventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_Tamper4EventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_Tamper5EventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_Tamper6EventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_Tamper7EventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_Tamper8EventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_InternalTamper1EventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_InternalTamper2EventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_InternalTamper3EventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_InternalTamper5EventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_InternalTamper6EventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_InternalTamper7EventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_InternalTamper8EventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_InternalTamper9EventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_InternalTamper11EventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_InternalTamper12EventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_InternalTamper13EventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_BKUPWrite(RTC_HandleTypeDef *hrtc, uint32_t BackupRegister, uint32_t Data);
uint32_t HAL_RTCEx_BKUPRead(RTC_HandleTypeDef *hrtc, uint32_t BackupRegister);
void HAL_RTCEx_BKUPErase(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_BKUPBlock_Enable(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_BKUPBlock_Disable(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_Erase_SecretDev_Conf(RTC_HandleTypeDef *hrtc, uint32_t SecretDeviceConf);
uint32_t HAL_RTCEx_Get_Erase_SecretDev_Conf(void);
HAL_StatusTypeDef HAL_RTCEx_SecureModeGet(RTC_HandleTypeDef *hrtc, RTC_SecureStateTypeDef *secureState);
HAL_StatusTypeDef HAL_RTCEx_PrivilegeModeSet(RTC_HandleTypeDef *hrtc, RTC_PrivilegeStateTypeDef *privilegeState);
HAL_StatusTypeDef HAL_RTCEx_PrivilegeModeGet(RTC_HandleTypeDef *hrtc, RTC_PrivilegeStateTypeDef *privilegeState);
HAL_StatusTypeDef HAL_RTC_Init(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTC_DeInit(RTC_HandleTypeDef *hrtc);
void HAL_RTC_MspInit(RTC_HandleTypeDef *hrtc);
void HAL_RTC_MspDeInit(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTC_SetTime(RTC_HandleTypeDef *hrtc, RTC_TimeTypeDef *sTime, uint32_t Format);
HAL_StatusTypeDef HAL_RTC_GetTime(const RTC_HandleTypeDef *hrtc, RTC_TimeTypeDef *sTime, uint32_t Format);
HAL_StatusTypeDef HAL_RTC_SetDate(RTC_HandleTypeDef *hrtc, RTC_DateTypeDef *sDate, uint32_t Format);
HAL_StatusTypeDef HAL_RTC_GetDate(const RTC_HandleTypeDef *hrtc, RTC_DateTypeDef *sDate, uint32_t Format);
void HAL_RTC_DST_Add1Hour(const RTC_HandleTypeDef *hrtc);
void HAL_RTC_DST_Sub1Hour(const RTC_HandleTypeDef *hrtc);
void HAL_RTC_DST_SetStoreOperation(const RTC_HandleTypeDef *hrtc);
void HAL_RTC_DST_ClearStoreOperation(const RTC_HandleTypeDef *hrtc);
uint32_t HAL_RTC_DST_ReadStoreOperation(const RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTC_SetAlarm(RTC_HandleTypeDef *hrtc, RTC_AlarmTypeDef *sAlarm, uint32_t Format);
HAL_StatusTypeDef HAL_RTC_SetAlarm_IT(RTC_HandleTypeDef *hrtc, RTC_AlarmTypeDef *sAlarm, uint32_t Format);
HAL_StatusTypeDef HAL_RTC_DeactivateAlarm(RTC_HandleTypeDef *hrtc, uint32_t Alarm);
HAL_StatusTypeDef HAL_RTC_GetAlarm(const RTC_HandleTypeDef *hrtc, RTC_AlarmTypeDef *sAlarm, uint32_t Alarm,
                                   uint32_t Format);
void HAL_RTC_AlarmIRQHandler(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTC_PollForAlarmAEvent(const RTC_HandleTypeDef *hrtc, uint32_t Timeout);
void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTC_WaitForSynchro(RTC_HandleTypeDef *hrtc);
HAL_RTCStateTypeDef HAL_RTC_GetState(const RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef RTC_EnterInitMode(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef RTC_ExitInitMode(RTC_HandleTypeDef *hrtc);
uint8_t RTC_ByteToBcd2(uint8_t Value);
uint8_t RTC_Bcd2ToByte(uint8_t Value);
typedef struct
{
  uint32_t BaudRate;
  uint32_t WordLength;
  uint32_t StopBits;
  uint32_t Parity;
  uint32_t Mode;
  uint32_t HwFlowCtl;
  uint32_t OverSampling;
  uint32_t OneBitSampling;
  uint32_t ClockPrescaler;
} UART_InitTypeDef;
typedef struct
{
  uint32_t AdvFeatureInit;
  uint32_t TxPinLevelInvert;
  uint32_t RxPinLevelInvert;
  uint32_t DataInvert;
  uint32_t Swap;
  uint32_t OverrunDisable;
  uint32_t DMADisableonRxError;
  uint32_t AutoBaudRateEnable;
  uint32_t AutoBaudRateMode;
  uint32_t MSBFirst;
} UART_AdvFeatureInitTypeDef;
typedef uint32_t HAL_UART_StateTypeDef;
typedef uint32_t HAL_UART_RxTypeTypeDef;
typedef uint32_t HAL_UART_RxEventTypeTypeDef;
typedef struct __UART_HandleTypeDef
{
  USART_TypeDef *Instance;
  UART_InitTypeDef Init;
  UART_AdvFeatureInitTypeDef AdvancedInit;
  const uint8_t *pTxBuffPtr;
  uint16_t TxXferSize;
  volatile uint16_t TxXferCount;
  uint8_t *pRxBuffPtr;
  uint16_t RxXferSize;
  volatile uint16_t RxXferCount;
  uint16_t Mask;
  uint32_t FifoMode;
  uint16_t NbRxDataToProcess;
  uint16_t NbTxDataToProcess;
  volatile HAL_UART_RxTypeTypeDef ReceptionType;
  volatile HAL_UART_RxEventTypeTypeDef RxEventType;
  void (*RxISR)(struct __UART_HandleTypeDef *huart);
  void (*TxISR)(struct __UART_HandleTypeDef *huart);
  DMA_HandleTypeDef *hdmatx;
  DMA_HandleTypeDef *hdmarx;
  HAL_LockTypeDef Lock;
  volatile HAL_UART_StateTypeDef gState;
  volatile HAL_UART_StateTypeDef RxState;
  volatile uint32_t ErrorCode;
} UART_HandleTypeDef;
typedef struct
{
  uint32_t WakeUpEvent;
  uint16_t AddressLength;
  uint8_t Address;
} UART_WakeUpTypeDef;
typedef struct
{
  uint32_t AutonomousModeState;
  uint32_t TriggerSelection;
  uint32_t TriggerPolarity;
  uint32_t DataSize;
  uint32_t IdleFrame;
} UART_AutonomousModeConfTypeDef;
HAL_StatusTypeDef HAL_RS485Ex_Init(UART_HandleTypeDef *huart, uint32_t Polarity, uint32_t AssertionTime,
                                   uint32_t DeassertionTime);
void HAL_UARTEx_RxFifoFullCallback(UART_HandleTypeDef *huart);
void HAL_UARTEx_TxFifoEmptyCallback(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UARTEx_StopModeWakeUpSourceConfig(UART_HandleTypeDef *huart, UART_WakeUpTypeDef WakeUpSelection);
HAL_StatusTypeDef HAL_UARTEx_EnableStopMode(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UARTEx_DisableStopMode(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_MultiProcessorEx_AddressLength_Set(UART_HandleTypeDef *huart, uint32_t AddressLength);
HAL_StatusTypeDef HAL_UARTEx_EnableFifoMode(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UARTEx_DisableFifoMode(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UARTEx_SetTxFifoThreshold(UART_HandleTypeDef *huart, uint32_t Threshold);
HAL_StatusTypeDef HAL_UARTEx_SetRxFifoThreshold(UART_HandleTypeDef *huart, uint32_t Threshold);
HAL_StatusTypeDef HAL_UARTEx_ReceiveToIdle(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint16_t *RxLen,
                                           uint32_t Timeout);
HAL_StatusTypeDef HAL_UARTEx_ReceiveToIdle_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UARTEx_ReceiveToIdle_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_UART_RxEventTypeTypeDef HAL_UARTEx_GetRxEventType(const UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UARTEx_SetConfigAutonomousMode(UART_HandleTypeDef *huart,
                                                     const UART_AutonomousModeConfTypeDef *sConfig);
HAL_StatusTypeDef HAL_UARTEx_GetConfigAutonomousMode(const UART_HandleTypeDef *huart,
                                                     UART_AutonomousModeConfTypeDef *sConfig);
HAL_StatusTypeDef HAL_UARTEx_ClearConfigAutonomousMode(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_Init(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_HalfDuplex_Init(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_LIN_Init(UART_HandleTypeDef *huart, uint32_t BreakDetectLength);
HAL_StatusTypeDef HAL_MultiProcessor_Init(UART_HandleTypeDef *huart, uint8_t Address, uint32_t WakeUpMethod);
HAL_StatusTypeDef HAL_UART_DeInit(UART_HandleTypeDef *huart);
void HAL_UART_MspInit(UART_HandleTypeDef *huart);
void HAL_UART_MspDeInit(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_Transmit(UART_HandleTypeDef *huart, const uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_UART_Receive(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_UART_Transmit_IT(UART_HandleTypeDef *huart, const uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UART_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UART_Transmit_DMA(UART_HandleTypeDef *huart, const uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UART_Receive_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UART_DMAPause(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_DMAResume(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_DMAStop(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_Abort(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_AbortTransmit(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_AbortReceive(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_Abort_IT(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_AbortTransmit_IT(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_AbortReceive_IT(UART_HandleTypeDef *huart);
void HAL_UART_IRQHandler(UART_HandleTypeDef *huart);
void HAL_UART_TxHalfCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_RxHalfCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart);
void HAL_UART_AbortCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_AbortTransmitCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_AbortReceiveCpltCallback(UART_HandleTypeDef *huart);
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size);
void HAL_UART_ReceiverTimeout_Config(UART_HandleTypeDef *huart, uint32_t TimeoutValue);
HAL_StatusTypeDef HAL_UART_EnableReceiverTimeout(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_DisableReceiverTimeout(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_LIN_SendBreak(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_MultiProcessor_EnableMuteMode(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_MultiProcessor_DisableMuteMode(UART_HandleTypeDef *huart);
void HAL_MultiProcessor_EnterMuteMode(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_HalfDuplex_EnableTransmitter(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_HalfDuplex_EnableReceiver(UART_HandleTypeDef *huart);
HAL_UART_StateTypeDef HAL_UART_GetState(const UART_HandleTypeDef *huart);
uint32_t HAL_UART_GetError(const UART_HandleTypeDef *huart);
HAL_StatusTypeDef UART_SetConfig(UART_HandleTypeDef *huart);
HAL_StatusTypeDef UART_CheckIdleState(UART_HandleTypeDef *huart);
HAL_StatusTypeDef UART_WaitOnFlagUntilTimeout(UART_HandleTypeDef *huart, uint32_t Flag, FlagStatus Status,
                                              uint32_t Tickstart, uint32_t Timeout);
void UART_AdvFeatureConfig(UART_HandleTypeDef *huart);
HAL_StatusTypeDef UART_Start_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef UART_Start_Receive_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
extern const uint16_t UARTPrescTable[12];
typedef enum
{
  HAL_EXTI_COMMON_CB_ID = 0x00U,
  HAL_EXTI_RISING_CB_ID = 0x01U,
  HAL_EXTI_FALLING_CB_ID = 0x02U,
} EXTI_CallbackIDTypeDef;
typedef struct
{
  uint32_t Line;
  void (* RisingCallback)(void);
  void (* FallingCallback)(void);
} EXTI_HandleTypeDef;
typedef struct
{
  uint32_t Line;
  uint32_t Mode;
  uint32_t Trigger;
  uint32_t GPIOSel;
} EXTI_ConfigTypeDef;
HAL_StatusTypeDef HAL_EXTI_SetConfigLine(EXTI_HandleTypeDef *hexti, EXTI_ConfigTypeDef *pExtiConfig);
HAL_StatusTypeDef HAL_EXTI_GetConfigLine(EXTI_HandleTypeDef *hexti, EXTI_ConfigTypeDef *pExtiConfig);
HAL_StatusTypeDef HAL_EXTI_ClearConfigLine(const EXTI_HandleTypeDef *hexti);
HAL_StatusTypeDef HAL_EXTI_RegisterCallback(EXTI_HandleTypeDef *hexti, EXTI_CallbackIDTypeDef CallbackID,
                                            void (*pPendingCbfn)(void));
HAL_StatusTypeDef HAL_EXTI_GetHandle(EXTI_HandleTypeDef *hexti, uint32_t ExtiLine);
void HAL_EXTI_IRQHandler(const EXTI_HandleTypeDef *hexti);
uint32_t HAL_EXTI_GetPending(const EXTI_HandleTypeDef *hexti, uint32_t Edge);
void HAL_EXTI_ClearPending(const EXTI_HandleTypeDef *hexti, uint32_t Edge);
void HAL_EXTI_GenerateSWI(const EXTI_HandleTypeDef *hexti);
void HAL_EXTI_ConfigLineAttributes(uint32_t ExtiLine, uint32_t LineAttributes);
HAL_StatusTypeDef HAL_EXTI_GetConfigLineAttributes(uint32_t ExtiLine, uint32_t *pLineAttributes);
typedef enum
{
  HAL_TICK_FREQ_10HZ = 100U,
  HAL_TICK_FREQ_100HZ = 10U,
  HAL_TICK_FREQ_1KHZ = 1U,
  HAL_TICK_FREQ_DEFAULT = HAL_TICK_FREQ_1KHZ
} HAL_TickFreqTypeDef;
extern volatile uint32_t uwTick;
extern uint32_t uwTickPrio;
extern HAL_TickFreqTypeDef uwTickFreq;
HAL_StatusTypeDef HAL_Init(void);
HAL_StatusTypeDef HAL_DeInit(void);
void HAL_MspInit(void);
void HAL_MspDeInit(void);
HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority);
void HAL_IncTick(void);
void HAL_Delay(uint32_t Delay);
uint32_t HAL_GetTick(void);
uint32_t HAL_GetTickPrio(void);
HAL_StatusTypeDef HAL_SetTickFreq(HAL_TickFreqTypeDef Freq);
HAL_TickFreqTypeDef HAL_GetTickFreq(void);
void HAL_SuspendTick(void);
void HAL_ResumeTick(void);
uint32_t HAL_GetHalVersion(void);
uint32_t HAL_GetREVID(void);
uint32_t HAL_GetDEVID(void);
uint32_t HAL_GetUIDw0(void);
uint32_t HAL_GetUIDw1(void);
uint32_t HAL_GetUIDw2(void);
void HAL_DBGMCU_EnableDBGStopMode(void);
void HAL_DBGMCU_DisableDBGStopMode(void);
void HAL_DBGMCU_EnableDBGStandbyMode(void);
void HAL_DBGMCU_DisableDBGStandbyMode(void);
void HAL_SYSCFG_VREFBUF_VoltageScalingConfig(uint32_t VoltageScaling);
void HAL_SYSCFG_VREFBUF_HighImpedanceConfig(uint32_t Mode);
void HAL_SYSCFG_VREFBUF_TrimmingConfig(uint32_t TrimmingValue);
HAL_StatusTypeDef HAL_SYSCFG_EnableVREFBUF(void);
void HAL_SYSCFG_DisableVREFBUF(void);
void HAL_SYSCFG_EnableIOAnalogBooster(void);
void HAL_SYSCFG_DisableIOAnalogBooster(void);
void HAL_SYSCFG_EnableIOAnalogVoltageSelection(void);
void HAL_SYSCFG_DisableIOAnalogVoltageSelection(void);
void HAL_SYSCFG_EnableSRAMCached(void);
void HAL_SYSCFG_DisableSRAMCached(void);
void HAL_SYSCFG_EnableVddCompensationCell(void);
void HAL_SYSCFG_EnableVddIO2CompensationCell(void);
void HAL_SYSCFG_DisableVddCompensationCell(void);
void HAL_SYSCFG_DisableVddIO2CompensationCell(void);
void HAL_SYSCFG_Lock(uint32_t Item);
HAL_StatusTypeDef HAL_SYSCFG_GetLock(uint32_t *pItem);
enum image_attributes
{
  RE_FLASH_AREA_SCRATCH_SIZE = (0x0),
  RE_IMAGE_FLASH_SECURE_IMAGE_SIZE = ((0x06000)),
  RE_IMAGE_FLASH_NON_SECURE_IMAGE_SIZE = ((0x140000)+(0x06000)),
  RE_IMAGE_FLASH_ADDRESS_SECURE = ((0x0c000000)+(((((((0x0000) + ((0x2000))) + ((0x2000)) + (0x0))+(0x2000))+(0x12000))+((0x2000))) + (0x0))),
  RE_APP_IMAGE_NUMBER = (0x1),
  RE_EXTERNAL_FLASH_ENABLE = (0x0),
  RE_CODE_START_NON_SECURE = (0x0),
  RE_IMAGE_FLASH_ADDRESS_NON_SECURE = (0x0),
  RE_IMAGE_FLASH_SECURE_UPDATE = ((0x0c000000)+(((((((0x0000) + ((0x2000))) + ((0x2000)) + (0x0))+(0x2000))+(0x12000))+((0x2000))) + (0x0))),
  RE_IMAGE_FLASH_NON_SECURE_UPDATE = (0x0),
  RE_PRIMARY_ONLY = (0x1),
  RE_S_DATA_IMAGE_NUMBER = (0x0),
  RE_IMAGE_FLASH_ADDRESS_DATA_SECURE = (0x0),
  RE_IMAGE_FLASH_DATA_SECURE_UPDATE = (0x0),
  RE_IMAGE_FLASH_SECURE_DATA_IMAGE_SIZE = (0x0),
  RE_NS_DATA_IMAGE_NUMBER = (0x0),
  RE_IMAGE_FLASH_ADDRESS_DATA_NON_SECURE = (0x0),
  RE_IMAGE_FLASH_DATA_NON_SECURE_UPDATE = (0x0),
  RE_IMAGE_FLASH_NON_SECURE_DATA_IMAGE_SIZE = (0x0),
  RE_BL2_PERSO_ADDRESS = ((0x0c000000)+(((0x0000) + ((0x2000))) + ((0x2000)) + (0x0))),
  RE_BL2_BOOT_ADDRESS = ((((((0x0C000000)) + (((((0x0000) + ((0x2000))) + ((0x2000)) + (0x0))+(0x2000))))))),
  RE_BL2_SEC1_END = ((((((((0x0000) + ((0x2000))) + ((0x2000)) + (0x0))+(0x2000))+(0x12000))+((0x2000))) + (0x0))+(0x06000)-0x1),
  RE_BL2_SEC2_START = ((0x100000)-0x1),
  RE_BL2_SEC2_END = (0x0),
  RE_BL2_WRP_START = ((((0x0000) + ((0x2000))) + ((0x2000)) + (0x0))),
  RE_BL2_WRP_END = ((((((0x0000) + ((0x2000))) + ((0x2000)) + (0x0))+(0x2000))+(0x12000))+((0x2000))-0x1),
  RE_BL2_HDP_END = ((((((0x0000) + ((0x2000))) + ((0x2000)) + (0x0))+(0x2000))+(0x12000))-0x1),
  RE_IMAGE_FLASH_LOADER_ADDRESS = ((0x0c000000)+(((0x100000)+(0x100000))-(0x4000)-(0x6000))),
  RE_LOADER_NS_CODE_SIZE = ((0x6000)),
  RE_LOADER_IMAGE_S_CODE_SIZE = ((0x4000)),
  RE_LOADER_WRP_START = (((0x100000)-(0x4000)-(0x6000))),
  RE_LOADER_WRP_END = ((0x100000)-0x1),
  RE_EXT_LOADER = (0x1),
  RE_CRYPTO_SCHEME = 0x2,
  RE_ENCRYPTION = (0x1),
  RE_OVER_WRITE = (0x1),
  RE_FLASH_PAGE_NBR = (0x7F)
};
