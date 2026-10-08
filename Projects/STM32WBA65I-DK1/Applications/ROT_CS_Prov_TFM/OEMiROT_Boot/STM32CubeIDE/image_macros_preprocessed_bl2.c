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
  PVD_IRQn = 1,
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
  SAES_IRQn = 28,
  GPDMA1_Channel0_IRQn = 29,
  GPDMA1_Channel1_IRQn = 30,
  GPDMA1_Channel2_IRQn = 31,
  GPDMA1_Channel3_IRQn = 32,
  GPDMA1_Channel4_IRQn = 33,
  GPDMA1_Channel5_IRQn = 34,
  GPDMA1_Channel6_IRQn = 35,
  GPDMA1_Channel7_IRQn = 36,
  TIM1_BRK_IRQn = 37,
  TIM1_UP_IRQn = 38,
  TIM1_TRG_COM_IRQn = 39,
  TIM1_CC_IRQn = 40,
  TIM2_IRQn = 41,
  TIM3_IRQn = 42,
  I2C1_EV_IRQn = 43,
  I2C1_ER_IRQn = 44,
  SPI1_IRQn = 45,
  USART1_IRQn = 46,
  USART2_IRQn = 47,
  LPUART1_IRQn = 48,
  LPTIM1_IRQn = 49,
  LPTIM2_IRQn = 50,
  TIM16_IRQn = 51,
  TIM17_IRQn = 52,
  COMP_IRQn = 53,
  I2C3_EV_IRQn = 54,
  I2C3_ER_IRQn = 55,
  SAI1_IRQn = 56,
  TSC_IRQn = 57,
  AES_IRQn = 58,
  RNG_IRQn = 59,
  FPU_IRQn = 60,
  HASH_IRQn = 61,
  PKA_IRQn = 62,
  SPI3_IRQn = 63,
  ICACHE_IRQn = 64,
  ADC4_IRQn = 65,
  RADIO_IRQn = 66,
  WKUP_IRQn = 67,
  HSEM_IRQn = 68,
  HSEM_S_IRQn = 69,
  WKUP_S_IRQn = 70,
  RCC_AUDIOSYNC_IRQn = 71,
  TIM4_IRQn = 72,
  I2C2_EV_IRQn = 73,
  I2C2_ER_IRQn = 74,
  SPI2_IRQn = 75,
  USB_OTG_HS_IRQn = 76,
  I2C4_EV_IRQn = 77,
  I2C4_ER_IRQn = 78,
  USART3_IRQn = 79,
  EXTI19_RADIO_IO_IRQn = 80,
  EXTI20_RADIO_IO_IRQn = 81,
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
extern const uint8_t AHBPrescTable[8];
extern const uint8_t APBPrescTable[8];
extern const uint8_t AHB5PrescTable[8];
extern void SystemInit (void);
extern void SystemCoreClockUpdate (void);
extern uint32_t SECURE_SystemCoreClockUpdate(void);
typedef struct
{
  volatile uint32_t ISR;
  volatile uint32_t IER;
  volatile uint32_t CR;
  volatile uint32_t CFGR1;
  volatile uint32_t CFGR2;
  volatile uint32_t SMPR;
       uint32_t RESERVED0[2];
  volatile uint32_t AWD1TR;
  volatile uint32_t AWD2TR;
  volatile uint32_t CHSELR;
  volatile uint32_t AWD3TR;
       uint32_t RESERVED1[4];
  volatile uint32_t DR;
  volatile uint32_t PWRR;
       uint32_t RESERVED2[22];
  volatile uint32_t AWD2CR;
  volatile uint32_t AWD3CR;
       uint32_t RESERVED3[7];
  volatile uint32_t CALFACT;
} ADC_TypeDef;
typedef struct
{
  volatile uint32_t CCR;
} ADC_Common_TypeDef;
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
  volatile uint32_t DR;
  volatile uint32_t IDR;
  volatile uint32_t CR;
       uint32_t RESERVED0;
  volatile uint32_t INIT;
  volatile uint32_t POL;
} CRC_TypeDef;
typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t SR;
  volatile uint32_t DINR;
  volatile uint32_t DOUTR;
  volatile uint32_t KEYR0;
  volatile uint32_t KEYR1;
  volatile uint32_t KEYR2;
  volatile uint32_t KEYR3;
  volatile uint32_t IVR0;
  volatile uint32_t IVR1;
  volatile uint32_t IVR2;
  volatile uint32_t IVR3;
  volatile uint32_t KEYR4;
  volatile uint32_t KEYR5;
  volatile uint32_t KEYR6;
  volatile uint32_t KEYR7;
  volatile uint32_t SUSP0R;
  volatile uint32_t SUSP1R;
  volatile uint32_t SUSP2R;
  volatile uint32_t SUSP3R;
  volatile uint32_t SUSP4R;
  volatile uint32_t SUSP5R;
  volatile uint32_t SUSP6R;
  volatile uint32_t SUSP7R;
       uint32_t RESERVED1[168];
  volatile uint32_t IER;
  volatile uint32_t ISR;
  volatile uint32_t ICR;
} AES_TypeDef;
typedef struct
{
  volatile uint32_t IDCODE;
  volatile uint32_t SCR;
  volatile uint32_t APB1LFZR;
  volatile uint32_t APB1HFZR;
  volatile uint32_t APB2FZR;
       uint32_t RESERVED1[4];
  volatile uint32_t APB7FZR;
  volatile uint32_t AHB1FZR;
} DBGMCU_TypeDef;
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
       uint32_t RESERVED3[10];
  volatile uint32_t CLLR;
} DMA_Channel_TypeDef;
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
       uint32_t RESERVED0;
  volatile uint32_t NSKEYR;
  volatile uint32_t SECKEYR;
  volatile uint32_t OPTKEYR;
       uint32_t RESERVED1;
  volatile uint32_t PDKEY1R;
  volatile uint32_t PDKEY2R;
  volatile uint32_t NSSR;
  volatile uint32_t SECSR;
  volatile uint32_t NSCR1;
  volatile uint32_t SECCR1;
  volatile uint32_t ECCR;
  volatile uint32_t OPSR;
  volatile uint32_t NSCR2;
  volatile uint32_t SECCR2;
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
       uint32_t RESERVED2[4];
  volatile uint32_t SECBB2R1;
  volatile uint32_t SECBB2R2;
  volatile uint32_t SECBB2R3;
  volatile uint32_t SECBB2R4;
       uint32_t RESERVED3[4];
  volatile uint32_t SECHDPCR;
  volatile uint32_t PRIVCFGR;
       uint32_t RESERVED4[2];
  volatile uint32_t PRIVBB1R1;
  volatile uint32_t PRIVBB1R2;
  volatile uint32_t PRIVBB1R3;
  volatile uint32_t PRIVBB1R4;
       uint32_t RESERVED5[4];
  volatile uint32_t PRIVBB2R1;
  volatile uint32_t PRIVBB2R2;
  volatile uint32_t PRIVBB2R3;
  volatile uint32_t PRIVBB2R4;
} FLASH_TypeDef;
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
} GTZC_TZSC_TypeDef;
typedef struct
{
  volatile uint32_t CR;
  uint32_t RESERVED1[3];
  volatile uint32_t CFGLOCK;
  uint32_t RESERVED2[59];
  volatile uint32_t SECCFGR[28];
  uint32_t RESERVED3[36];
  volatile uint32_t PRIVCFGR[28];
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
  volatile uint32_t DIN;
  volatile uint32_t STR;
  volatile uint32_t HR[5];
  volatile uint32_t IMR;
  volatile uint32_t SR;
       uint32_t RESERVED0[52];
  volatile uint32_t CSR[54];
} HASH_TypeDef;
typedef struct
{
  volatile uint32_t HR[8];
} HASH_DIGEST_TypeDef;
typedef struct
{
  volatile uint32_t R[16];
   uint32_t Reserved1[16];
  volatile uint32_t RLR[16];
   uint32_t Reserved2[16];
  volatile uint32_t IER;
  volatile uint32_t ICR;
  volatile uint32_t ISR;
  volatile uint32_t MISR;
   uint32_t Reserved3[28];
  volatile uint32_t SIER;
  volatile uint32_t SICR;
  volatile uint32_t SISR;
  volatile uint32_t SMISR;
   uint32_t Reserved4[28];
  volatile uint32_t SECCFGR;
   uint32_t Reserved5[3];
  volatile uint32_t PRIVCFGR;
   uint32_t Reserved6[7];
  volatile uint32_t CR;
  volatile uint32_t KEYR;
} HSEM_TypeDef;
typedef struct
{
  volatile uint32_t IER;
  volatile uint32_t ICR;
  volatile uint32_t ISR;
  volatile uint32_t MISR;
   uint32_t Reserved3[28];
  volatile uint32_t SIER;
  volatile uint32_t SICR;
  volatile uint32_t SISR;
  volatile uint32_t SMISR;
} HSEM_Common_TypeDef;
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
  volatile uint32_t KR;
  volatile uint32_t PR;
  volatile uint32_t RLR;
  volatile uint32_t SR;
  volatile uint32_t WINR;
  volatile uint32_t EWCR;
} IWDG_TypeDef;
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
  volatile uint32_t CR;
  volatile uint32_t SR;
  volatile uint32_t CLRFR;
  uint32_t Reserved[253];
  volatile uint32_t RAM[1334];
} PKA_TypeDef;
typedef struct
{
  volatile uint32_t ACTCR;
  volatile uint32_t PRICR;
  volatile uint32_t CR;
} PTACONV_TypeDef;
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
  volatile uint32_t RESERVED0[2];
  volatile uint32_t DBPR;
       uint32_t RESERVED1;
  volatile uint32_t SECCFGR;
  volatile uint32_t PRIVCFGR;
  volatile uint32_t SR;
  volatile uint32_t SVMSR;
       uint32_t RESERVED2;
  volatile uint32_t WUSR;
  volatile uint32_t WUSCR;
  volatile uint32_t APCR;
  volatile uint32_t IORETENRA;
  volatile uint32_t IORETRA;
  volatile uint32_t IORETENRB;
  volatile uint32_t IORETRB;
  volatile uint32_t IORETENRC;
  volatile uint32_t IORETRC;
  volatile uint32_t IORETENRD;
  volatile uint32_t IORETRD;
  volatile uint32_t IORETENRE;
  volatile uint32_t IORETRE;
       uint32_t RESERVED3[2];
  volatile uint32_t IORETENRG;
  volatile uint32_t IORETRG;
  volatile uint32_t IORETENRH;
  volatile uint32_t IORETRH;
       uint32_t RESERVED4[28];
  volatile uint32_t RADIOSCR;
  volatile uint32_t S2RETR;
} PWR_TypeDef;
typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t IER;
  volatile uint32_t ISR;
  uint32_t RESERVED0;
  volatile uint32_t PEAR;
  volatile uint32_t ICR;
  volatile uint32_t WPR1;
  volatile uint32_t WPR2;
  uint32_t RESERVED1[2];
  volatile uint32_t ERKEYR;
}RAMCFG_TypeDef;
typedef struct
{
  volatile uint32_t CR;
  uint32_t RESERVED0[3];
  volatile uint32_t ICSCR3;
  uint32_t RESERVED1[2];
  volatile uint32_t CFGR1;
  volatile uint32_t CFGR2;
  volatile uint32_t CFGR3;
  volatile uint32_t PLL1CFGR;
  uint32_t RESERVED2[2];
  volatile uint32_t PLL1DIVR;
  volatile uint32_t PLL1FRACR;
  uint32_t RESERVED3[5];
  volatile uint32_t CIER;
  volatile uint32_t CIFR;
  volatile uint32_t CICR;
  uint32_t RESERVED4;
  volatile uint32_t AHB1RSTR;
  volatile uint32_t AHB2RSTR;
  uint32_t RESERVED5;
  volatile uint32_t AHB4RSTR;
  volatile uint32_t AHB5RSTR;
  volatile uint32_t APB1RSTR1;
  volatile uint32_t APB1RSTR2;
  volatile uint32_t APB2RSTR;
  volatile uint32_t APB7RSTR;
  uint32_t RESERVED6;
  volatile uint32_t AHB1ENR;
  volatile uint32_t AHB2ENR;
  uint32_t RESERVED7;
  volatile uint32_t AHB4ENR;
  volatile uint32_t AHB5ENR;
  volatile uint32_t APB1ENR1;
  volatile uint32_t APB1ENR2;
  volatile uint32_t APB2ENR;
  volatile uint32_t APB7ENR;
  uint32_t RESERVED8;
  volatile uint32_t AHB1SMENR;
  volatile uint32_t AHB2SMENR;
  uint32_t RESERVED9;
  volatile uint32_t AHB4SMENR;
  volatile uint32_t AHB5SMENR;
  volatile uint32_t APB1SMENR1;
  volatile uint32_t APB1SMENR2;
  volatile uint32_t APB2SMENR;
  volatile uint32_t APB7SMENR;
  uint32_t RESERVED10[3];
  volatile uint32_t CCIPR1;
  volatile uint32_t CCIPR2;
  volatile uint32_t CCIPR3;
  uint32_t RESERVED11;
  volatile uint32_t BDCR1;
  volatile uint32_t CSR;
  volatile uint32_t BDCR2;
  uint32_t RESERVED12[5];
  volatile uint32_t SECCFGR;
  volatile uint32_t PRIVCFGR;
  uint32_t RESERVED13[42];
  volatile uint32_t ASCR;
  volatile uint32_t ASIER;
  volatile uint32_t ASSR;
  volatile uint32_t ASCNTR;
  volatile uint32_t ASARR;
  volatile uint32_t ASCAR;
  volatile uint32_t ASCOR;
  uint32_t RESERVED14[9];
  volatile uint32_t CFGR4;
  uint32_t RESERVED15;
  volatile uint32_t RADIOENR;
  uint32_t RESERVED16;
  volatile uint32_t ECSCR1;
} RCC_TypeDef;
typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t SR;
  volatile uint32_t DR;
  volatile uint32_t NSCR;
  volatile uint32_t HTCR[4];
} RNG_TypeDef;
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
       uint32_t RESERVED1;
  volatile uint32_t ALRMAR;
  volatile uint32_t ALRMASSR;
  volatile uint32_t ALRMBR;
  volatile uint32_t ALRMBSSR;
  volatile uint32_t SR;
  volatile uint32_t MISR;
  volatile uint32_t SMISR;
  volatile uint32_t SCR;
       uint32_t RESERVED3[4];
  volatile uint32_t ALRABINR;
  volatile uint32_t ALRBBINR;
} RTC_TypeDef;
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
       uint32_t RESERVED2[17];
  volatile uint32_t OTGHSPHYCR;
       uint32_t RESERVED3;
  volatile uint32_t OTGHSPHYTUNER2;
} SYSCFG_TypeDef;
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
  volatile uint32_t COUNT1R;
       uint32_t RESERVED2[4];
  volatile uint32_t RPCFGR;
       uint32_t RESERVED3[42];
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
  volatile uint32_t OR;
       uint32_t RESERVED0[220];
  volatile uint32_t DCR;
  volatile uint32_t DMAR;
} TIM_TypeDef;
typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t IER;
  volatile uint32_t ICR;
  volatile uint32_t ISR;
  volatile uint32_t IOHCR;
  uint32_t RESERVED0;
  volatile uint32_t IOASCR;
  uint32_t RESERVED1;
  volatile uint32_t IOSCR;
  uint32_t RESERVED2;
  volatile uint32_t IOCCR;
  uint32_t RESERVED3;
  volatile uint32_t IOGCSR;
  volatile uint32_t IOGXCR[7];
} TSC_TypeDef;
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
  volatile uint32_t CSR;
  volatile uint32_t CCR;
} VREFBUF_TypeDef;
typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t CFR;
  volatile uint32_t SR;
} WWDG_TypeDef;
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
  uint32_t Reserved30[2];
  volatile uint32_t GCCFG;
  volatile uint32_t CID;
  volatile uint32_t GSNPSID;
    uint32_t Reserved44[4];
  volatile uint32_t GLPMCFG;
  volatile uint32_t GPWRDN;
  volatile uint32_t GDFIFOCFG;
    uint32_t Reserved60[40];
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
  uint32_t Reserved04;
  volatile uint32_t DIEPINT;
  uint32_t Reserved0C;
  volatile uint32_t DIEPTSIZ;
  volatile uint32_t DIEPDMA;
  volatile uint32_t DTXFSTS;
  uint32_t Reserved18;
} USB_OTG_INEndpointTypeDef;
typedef struct
{
  volatile uint32_t DOEPCTL;
  uint32_t Reserved04;
  volatile uint32_t DOEPINT;
  uint32_t Reserved0C;
  volatile uint32_t DOEPTSIZ;
  volatile uint32_t DOEPDMA;
  uint32_t Reserved18[2];
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
  uint32_t SrcAddress;
  uint32_t DstAddress;
  uint32_t DataSize;
} DMA_NodeConfTypeDef;
typedef struct
{
  uint32_t LinkRegisters[6U];
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
void HAL_NVIC_GetPriority(IRQn_Type IRQn, uint32_t PriorityGroup, uint32_t *pPreemptPriority, uint32_t *pSubPriority);
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
void HAL_MPU_ConfigRegion(MPU_Region_InitTypeDef *MPU_RegionInit);
void HAL_MPU_ConfigMemoryAttributes(MPU_Attributes_InitTypeDef *MPU_AttributesInit);
typedef struct
{
  uint32_t DataType;
  uint32_t KeySize;
  uint32_t *pKey;
  uint32_t *pInitVect;
  uint32_t Algorithm;
  uint32_t *Header;
  uint32_t HeaderSize;
  uint32_t *B0;
  uint32_t DataWidthUnit;
  uint32_t HeaderWidthUnit;
  uint32_t KeyIVConfigSkip;
  uint32_t KeyMode;
  uint32_t KeySelect;
  uint32_t KeyProtection;
} CRYP_ConfigTypeDef;
typedef enum
{
  HAL_CRYP_STATE_RESET = 0x00U,
  HAL_CRYP_STATE_READY = 0x01U,
  HAL_CRYP_STATE_BUSY = 0x02U,
} HAL_CRYP_STATETypeDef;
typedef struct
{
  uint32_t DataType;
  uint32_t KeySize;
  uint32_t *pKey;
  uint32_t *pInitVect;
  uint32_t Algorithm;
  uint32_t DataWidthUnit;
  uint32_t KeyIVConfigSkip;
  uint32_t KeyMode;
  uint32_t Phase;
  uint32_t KeyIVConfig;
  uint32_t CR_Reg;
  uint32_t IER_Reg;
  uint32_t IVR0_Reg;
  uint32_t IVR1_Reg;
  uint32_t IVR2_Reg;
  uint32_t IVR3_Reg;
} CRYP_ContextTypeDef;
typedef struct
{
  AES_TypeDef *Instance;
  CRYP_ConfigTypeDef Init;
  uint32_t *pCrypInBuffPtr;
  uint32_t *pCrypOutBuffPtr;
  volatile uint16_t CrypHeaderCount;
  volatile uint16_t CrypInCount;
  volatile uint16_t CrypOutCount;
  uint16_t Size;
  uint32_t Phase;
  DMA_HandleTypeDef *hdmain;
  DMA_HandleTypeDef *hdmaout;
  HAL_LockTypeDef Lock;
  volatile HAL_CRYP_STATETypeDef State;
  volatile uint32_t ErrorCode;
  uint32_t KeyIVConfig;
  uint32_t SizesSum;
} CRYP_HandleTypeDef;
HAL_StatusTypeDef HAL_CRYPEx_AESGCM_GenerateAuthTAG(CRYP_HandleTypeDef *hcryp, const uint32_t *pAuthTag,
                                                    uint32_t Timeout);
HAL_StatusTypeDef HAL_CRYPEx_AESCCM_GenerateAuthTAG(CRYP_HandleTypeDef *hcryp, const uint32_t *pAuthTag,
                                                    uint32_t Timeout);
HAL_StatusTypeDef HAL_CRYPEx_UnwrapKey(CRYP_HandleTypeDef *hcryp, uint32_t *pInput, uint32_t Timeout);
HAL_StatusTypeDef HAL_CRYPEx_WrapKey(CRYP_HandleTypeDef *hcryp, uint32_t *pInput, uint32_t *pOutput, uint32_t Timeout);
HAL_StatusTypeDef HAL_CRYPEx_EncryptSharedKey(CRYP_HandleTypeDef *hcryp, uint32_t *pKey, uint32_t *pOutput, uint32_t ID,
                                              uint32_t Timeout);
HAL_StatusTypeDef HAL_CRYPEx_DecryptSharedKey(CRYP_HandleTypeDef *hcryp, uint32_t *pKey, uint32_t ID, uint32_t Timeout);
HAL_StatusTypeDef HAL_CRYP_Init(CRYP_HandleTypeDef *hcryp);
HAL_StatusTypeDef HAL_CRYP_DeInit(CRYP_HandleTypeDef *hcryp);
void HAL_CRYP_MspInit(CRYP_HandleTypeDef *hcryp);
void HAL_CRYP_MspDeInit(CRYP_HandleTypeDef *hcryp);
HAL_StatusTypeDef HAL_CRYP_SetConfig(CRYP_HandleTypeDef *hcryp, CRYP_ConfigTypeDef *pConf);
HAL_StatusTypeDef HAL_CRYP_GetConfig(CRYP_HandleTypeDef *hcryp, CRYP_ConfigTypeDef *pConf);
HAL_StatusTypeDef HAL_CRYP_SaveContext(CRYP_HandleTypeDef *hcryp, CRYP_ContextTypeDef *pcont);
HAL_StatusTypeDef HAL_CRYP_RestoreContext(CRYP_HandleTypeDef *hcryp, CRYP_ContextTypeDef *pcont);
HAL_StatusTypeDef HAL_CRYP_Encrypt(CRYP_HandleTypeDef *hcryp, uint32_t *pInput, uint16_t Size, uint32_t *pOutput,
                                   uint32_t Timeout);
HAL_StatusTypeDef HAL_CRYP_Decrypt(CRYP_HandleTypeDef *hcryp, uint32_t *pInput, uint16_t Size, uint32_t *pOutput,
                                   uint32_t Timeout);
HAL_StatusTypeDef HAL_CRYP_Encrypt_IT(CRYP_HandleTypeDef *hcryp, uint32_t *pInput, uint16_t Size, uint32_t *pOutput);
HAL_StatusTypeDef HAL_CRYP_Decrypt_IT(CRYP_HandleTypeDef *hcryp, uint32_t *pInput, uint16_t Size, uint32_t *pOutput);
HAL_StatusTypeDef HAL_CRYP_Encrypt_DMA(CRYP_HandleTypeDef *hcryp, uint32_t *pInput, uint16_t Size, uint32_t *pOutput);
HAL_StatusTypeDef HAL_CRYP_Decrypt_DMA(CRYP_HandleTypeDef *hcryp, uint32_t *pInput, uint16_t Size, uint32_t *pOutput);
void HAL_CRYP_IRQHandler(CRYP_HandleTypeDef *hcryp);
HAL_CRYP_STATETypeDef HAL_CRYP_GetState(const CRYP_HandleTypeDef *hcryp);
void HAL_CRYP_InCpltCallback(CRYP_HandleTypeDef *hcryp);
void HAL_CRYP_OutCpltCallback(CRYP_HandleTypeDef *hcryp);
void HAL_CRYP_ErrorCallback(CRYP_HandleTypeDef *hcryp);
uint32_t HAL_CRYP_GetError(const CRYP_HandleTypeDef *hcryp);
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
HAL_StatusTypeDef HAL_EXTI_SetConfigLine(EXTI_HandleTypeDef *hexti, const EXTI_ConfigTypeDef *pExtiConfig);
HAL_StatusTypeDef HAL_EXTI_GetConfigLine(const EXTI_HandleTypeDef *hexti, EXTI_ConfigTypeDef *pExtiConfig);
HAL_StatusTypeDef HAL_EXTI_ClearConfigLine(const EXTI_HandleTypeDef *hexti);
HAL_StatusTypeDef HAL_EXTI_RegisterCallback(EXTI_HandleTypeDef *hexti, EXTI_CallbackIDTypeDef CallbackID, void (*pPendingCbfn)(void));
HAL_StatusTypeDef HAL_EXTI_GetHandle(EXTI_HandleTypeDef *hexti, uint32_t ExtiLine);
void HAL_EXTI_IRQHandler(const EXTI_HandleTypeDef *hexti);
uint32_t HAL_EXTI_GetPending(const EXTI_HandleTypeDef *hexti, uint32_t Edge);
void HAL_EXTI_ClearPending(const EXTI_HandleTypeDef *hexti, uint32_t Edge);
void HAL_EXTI_GenerateSWI(const EXTI_HandleTypeDef *hexti);
void HAL_EXTI_ConfigLineAttributes(uint32_t ExtiLine, uint32_t LineAttributes);
HAL_StatusTypeDef HAL_EXTI_GetConfigLineAttributes(uint32_t ExtiLine, uint32_t *pLineAttributes);
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
typedef struct
{
  uint32_t Area;
  uint32_t Address;
  uint32_t MasterID;
} FLASH_EccInfoTypeDef;
HAL_StatusTypeDef HAL_FLASHEx_Erase(const FLASH_EraseInitTypeDef *pEraseInit, uint32_t *PageError);
HAL_StatusTypeDef HAL_FLASHEx_Erase_IT(FLASH_EraseInitTypeDef *pEraseInit);
HAL_StatusTypeDef HAL_FLASHEx_OBProgram(FLASH_OBProgramInitTypeDef *pOBInit);
void HAL_FLASHEx_OBGetConfig(FLASH_OBProgramInitTypeDef *pOBInit);
HAL_StatusTypeDef HAL_FLASHEx_ConfigBBAttributes(const FLASH_BBAttributesTypeDef *pBBAttributes);
void HAL_FLASHEx_GetConfigBBAttributes(FLASH_BBAttributesTypeDef *pBBAttributes);
void HAL_FLASHEx_SuspendOperation(uint32_t Request);
void HAL_FLASHEx_AllowOperation(uint32_t Request);
uint32_t HAL_FLASHEx_IsOperationSuspended(void);
void HAL_FLASHEx_ConfigPrivMode(uint32_t PrivMode);
uint32_t HAL_FLASHEx_GetPrivMode(void);
HAL_StatusTypeDef HAL_FLASHEx_EnablePowerDown(uint32_t Banks);
HAL_StatusTypeDef HAL_FLASHEx_ConfigLowPowerRead(uint32_t ConfigLPM);
uint32_t HAL_FLASHEx_GetLowPowerRead(void);
void HAL_FLASHEx_GetOperation(FLASH_OperationTypeDef *pFlashOperation);
void HAL_FLASHEx_EnableEccCorrectionInterrupt(void);
void HAL_FLASHEx_DisableEccCorrectionInterrupt(void);
void HAL_FLASHEx_GetEccInfo(FLASH_EccInfoTypeDef *pData);
void HAL_FLASHEx_ECCD_IRQHandler(void);
__attribute__((weak)) void HAL_FLASHEx_EccDetectionCallback(void);
__attribute__((weak)) void HAL_FLASHEx_EccCorrectionCallback(void);
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
void HAL_GPIO_Init(GPIO_TypeDef *GPIOx, const GPIO_InitTypeDef *GPIO_Init);
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
  uint32_t MPCBB_SecConfig_array[28U];
  uint32_t MPCBB_PrivConfig_array[28U];
  uint32_t MPCBB_LockConfig_array[1U];
} MPCBB_Attribute_ConfigTypeDef;
typedef struct
{
  uint32_t SecureRWIllegalMode;
  uint32_t InvertSecureState;
  MPCBB_Attribute_ConfigTypeDef AttributeConfig;
} MPCBB_ConfigTypeDef;
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
  uint32_t DataType;
  uint32_t KeySize;
  uint8_t *pKey;
  uint32_t Algorithm;
} HASH_ConfigTypeDef;
typedef enum
{
  HAL_HASH_STATE_RESET = 0x00U,
  HAL_HASH_STATE_READY = 0x01U,
  HAL_HASH_STATE_BUSY = 0x02U,
  HAL_HASH_STATE_SUSPENDED = 0x03U
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
  HASH_TypeDef *Instance;
  HASH_ConfigTypeDef Init;
  uint8_t const *pHashInBuffPtr;
  uint8_t *pHashOutBuffPtr;
  volatile uint32_t HashInCount;
  uint32_t Size;
  uint8_t *pHashKeyBuffPtr;
  HAL_HASH_PhaseTypeDef Phase;
  DMA_HandleTypeDef *hdmain;
  HAL_LockTypeDef Lock;
  volatile uint32_t ErrorCode;
  volatile HAL_HASH_StateTypeDef State;
  volatile uint32_t Accumulation;
  volatile HAL_HASH_SuspendTypeDef SuspendRequest;
  HASH_ConfigTypeDef Init_saved;
  uint8_t const *pHashInBuffPtr_saved;
  uint8_t *pHashOutBuffPtr_saved;
  volatile uint32_t HashInCount_saved;
  uint32_t Size_saved;
  uint8_t *pHashKeyBuffPtr_saved;
  HAL_HASH_PhaseTypeDef Phase_saved;
} HASH_HandleTypeDef;
HAL_StatusTypeDef HAL_HASH_Init(HASH_HandleTypeDef *hhash);
HAL_StatusTypeDef HAL_HASH_DeInit(HASH_HandleTypeDef *hhash);
void HAL_HASH_MspInit(HASH_HandleTypeDef *hhash);
void HAL_HASH_MspDeInit(HASH_HandleTypeDef *hhash);
HAL_StatusTypeDef HAL_HASH_GetConfig(HASH_HandleTypeDef *hhash, HASH_ConfigTypeDef *pConf);
HAL_StatusTypeDef HAL_HASH_SetConfig(HASH_HandleTypeDef *hhash, const HASH_ConfigTypeDef *pConf);
HAL_StatusTypeDef HAL_HASH_ProcessSuspend(HASH_HandleTypeDef *hhash);
void HAL_HASH_Resume(HASH_HandleTypeDef *hhash, uint8_t *pMemBuffer);
void HAL_HASH_Suspend(HASH_HandleTypeDef *hhash, uint8_t *pMemBuffer);
HAL_StatusTypeDef HAL_HASH_Start(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                 uint8_t *const pOutBuffer,
                                 uint32_t Timeout);
HAL_StatusTypeDef HAL_HASH_Start_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                    uint8_t *const pOutBuffer);
HAL_StatusTypeDef HAL_HASH_Start_DMA(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                     uint8_t *const pOutBuffer);
HAL_StatusTypeDef HAL_HASH_Accumulate(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                      uint32_t Timeout);
HAL_StatusTypeDef HAL_HASH_AccumulateLast(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                          uint8_t *const pOutBuffer,
                                          uint32_t Timeout);
HAL_StatusTypeDef HAL_HASH_AccumulateLast_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                             uint8_t *const pOutBuffer);
HAL_StatusTypeDef HAL_HASH_Accumulate_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HASH_HMAC_Start(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                      uint8_t *const pOutBuffer,
                                      uint32_t Timeout);
HAL_StatusTypeDef HAL_HASH_HMAC_Start_DMA(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                          uint8_t *const pOutBuffer);
HAL_StatusTypeDef HAL_HASH_HMAC_Start_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                         uint8_t *const pOutBuffer);
HAL_StatusTypeDef HAL_HASH_HMAC_Accumulate(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                           uint32_t Timeout);
HAL_StatusTypeDef HAL_HASH_HMAC_AccumulateLast(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                               uint8_t *const pOutBuffer, uint32_t Timeout);
HAL_StatusTypeDef HAL_HASH_HMAC_Accumulate_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HASH_HMAC_AccumulateLast_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer,
                                                  uint32_t Size, uint8_t *const pOutBuffer);
void HAL_HASH_IRQHandler(HASH_HandleTypeDef *hhash);
void HAL_HASH_InCpltCallback(HASH_HandleTypeDef *hhash);
void HAL_HASH_DgstCpltCallback(HASH_HandleTypeDef *hhash);
void HAL_HASH_ErrorCallback(HASH_HandleTypeDef *hhash);
HAL_HASH_StateTypeDef HAL_HASH_GetState(const HASH_HandleTypeDef *hhash);
uint32_t HAL_HASH_GetError(const HASH_HandleTypeDef *hhash);
typedef struct
{
  uint32_t Timing;
  uint32_t OwnAddress1;
  uint32_t AddressingMode;
  uint32_t DualAddressMode;
  uint32_t OwnAddress2;
  uint32_t OwnAddress2Masks;
  uint32_t GeneralCallMode;
  uint32_t NoStretchMode;
} I2C_InitTypeDef;
typedef enum
{
  HAL_I2C_STATE_RESET = 0x00U,
  HAL_I2C_STATE_READY = 0x20U,
  HAL_I2C_STATE_BUSY = 0x24U,
  HAL_I2C_STATE_BUSY_TX = 0x21U,
  HAL_I2C_STATE_BUSY_RX = 0x22U,
  HAL_I2C_STATE_LISTEN = 0x28U,
  HAL_I2C_STATE_BUSY_TX_LISTEN = 0x29U,
  HAL_I2C_STATE_BUSY_RX_LISTEN = 0x2AU,
  HAL_I2C_STATE_ABORT = 0x60U,
} HAL_I2C_StateTypeDef;
typedef enum
{
  HAL_I2C_MODE_NONE = 0x00U,
  HAL_I2C_MODE_MASTER = 0x10U,
  HAL_I2C_MODE_SLAVE = 0x20U,
  HAL_I2C_MODE_MEM = 0x40U
} HAL_I2C_ModeTypeDef;
typedef struct __I2C_HandleTypeDef
{
  I2C_TypeDef *Instance;
  I2C_InitTypeDef Init;
  uint8_t *pBuffPtr;
  uint16_t XferSize;
  volatile uint16_t XferCount;
  volatile uint32_t XferOptions;
  volatile uint32_t PreviousState;
  HAL_StatusTypeDef(*XferISR)(struct __I2C_HandleTypeDef *hi2c, uint32_t ITFlags, uint32_t ITSources);
  DMA_HandleTypeDef *hdmatx;
  DMA_HandleTypeDef *hdmarx;
  HAL_LockTypeDef Lock;
  volatile HAL_I2C_StateTypeDef State;
  volatile HAL_I2C_ModeTypeDef Mode;
  volatile uint32_t ErrorCode;
  volatile uint32_t AddrEventCount;
  volatile uint32_t Devaddress;
  volatile uint32_t Memaddress;
} I2C_HandleTypeDef;
typedef struct
{
  uint32_t TriggerState;
  uint32_t TriggerSelection;
  uint32_t TriggerPolarity;
} I2C_AutonomousModeConfTypeDef;
HAL_StatusTypeDef HAL_I2CEx_ConfigAnalogFilter(I2C_HandleTypeDef *hi2c, uint32_t AnalogFilter);
HAL_StatusTypeDef HAL_I2CEx_ConfigDigitalFilter(I2C_HandleTypeDef *hi2c, uint32_t DigitalFilter);
HAL_StatusTypeDef HAL_I2CEx_EnableWakeUp(I2C_HandleTypeDef *hi2c);
HAL_StatusTypeDef HAL_I2CEx_DisableWakeUp(I2C_HandleTypeDef *hi2c);
HAL_StatusTypeDef HAL_I2CEx_ConfigFastModePlus(I2C_HandleTypeDef *hi2c, uint32_t FastModePlus);
HAL_StatusTypeDef HAL_I2CEx_SetConfigAutonomousMode(I2C_HandleTypeDef *hi2c,
                                                    const I2C_AutonomousModeConfTypeDef *sConfig);
HAL_StatusTypeDef HAL_I2CEx_GetConfigAutonomousMode(const I2C_HandleTypeDef *hi2c,
                                                    I2C_AutonomousModeConfTypeDef *sConfig);
HAL_StatusTypeDef HAL_I2CEx_ClearConfigAutonomousMode(I2C_HandleTypeDef *hi2c);
HAL_StatusTypeDef HAL_I2C_Init(I2C_HandleTypeDef *hi2c);
HAL_StatusTypeDef HAL_I2C_DeInit(I2C_HandleTypeDef *hi2c);
void HAL_I2C_MspInit(I2C_HandleTypeDef *hi2c);
void HAL_I2C_MspDeInit(I2C_HandleTypeDef *hi2c);
HAL_StatusTypeDef HAL_I2C_Master_Transmit(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData,
                                          uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_I2C_Master_Receive(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData,
                                         uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_I2C_Slave_Transmit(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size,
                                         uint32_t Timeout);
HAL_StatusTypeDef HAL_I2C_Slave_Receive(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size,
                                        uint32_t Timeout);
HAL_StatusTypeDef HAL_I2C_Mem_Write(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress,
                                    uint16_t MemAddSize, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_I2C_Mem_Read(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress,
                                   uint16_t MemAddSize, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_I2C_IsDeviceReady(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint32_t Trials,
                                        uint32_t Timeout);
HAL_StatusTypeDef HAL_I2C_Master_Transmit_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData,
                                             uint16_t Size);
HAL_StatusTypeDef HAL_I2C_Master_Receive_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData,
                                            uint16_t Size);
HAL_StatusTypeDef HAL_I2C_Slave_Transmit_IT(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_I2C_Slave_Receive_IT(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_I2C_Mem_Write_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress,
                                       uint16_t MemAddSize, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_I2C_Mem_Read_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress,
                                      uint16_t MemAddSize, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_I2C_Master_Seq_Transmit_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData,
                                                 uint16_t Size, uint32_t XferOptions);
HAL_StatusTypeDef HAL_I2C_Master_Seq_Receive_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData,
                                                uint16_t Size, uint32_t XferOptions);
HAL_StatusTypeDef HAL_I2C_Slave_Seq_Transmit_IT(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size,
                                                uint32_t XferOptions);
HAL_StatusTypeDef HAL_I2C_Slave_Seq_Receive_IT(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size,
                                               uint32_t XferOptions);
HAL_StatusTypeDef HAL_I2C_EnableListen_IT(I2C_HandleTypeDef *hi2c);
HAL_StatusTypeDef HAL_I2C_DisableListen_IT(I2C_HandleTypeDef *hi2c);
HAL_StatusTypeDef HAL_I2C_Master_Abort_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress);
HAL_StatusTypeDef HAL_I2C_Master_Transmit_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData,
                                              uint16_t Size);
HAL_StatusTypeDef HAL_I2C_Master_Receive_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData,
                                             uint16_t Size);
HAL_StatusTypeDef HAL_I2C_Slave_Transmit_DMA(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_I2C_Slave_Receive_DMA(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_I2C_Mem_Write_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress,
                                        uint16_t MemAddSize, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_I2C_Mem_Read_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress,
                                       uint16_t MemAddSize, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_I2C_Master_Seq_Transmit_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData,
                                                  uint16_t Size, uint32_t XferOptions);
HAL_StatusTypeDef HAL_I2C_Master_Seq_Receive_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData,
                                                 uint16_t Size, uint32_t XferOptions);
HAL_StatusTypeDef HAL_I2C_Slave_Seq_Transmit_DMA(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size,
                                                 uint32_t XferOptions);
HAL_StatusTypeDef HAL_I2C_Slave_Seq_Receive_DMA(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size,
                                                uint32_t XferOptions);
void HAL_I2C_EV_IRQHandler(I2C_HandleTypeDef *hi2c);
void HAL_I2C_ER_IRQHandler(I2C_HandleTypeDef *hi2c);
void HAL_I2C_MasterTxCpltCallback(I2C_HandleTypeDef *hi2c);
void HAL_I2C_MasterRxCpltCallback(I2C_HandleTypeDef *hi2c);
void HAL_I2C_SlaveTxCpltCallback(I2C_HandleTypeDef *hi2c);
void HAL_I2C_SlaveRxCpltCallback(I2C_HandleTypeDef *hi2c);
void HAL_I2C_AddrCallback(I2C_HandleTypeDef *hi2c, uint8_t TransferDirection, uint16_t AddrMatchCode);
void HAL_I2C_ListenCpltCallback(I2C_HandleTypeDef *hi2c);
void HAL_I2C_MemTxCpltCallback(I2C_HandleTypeDef *hi2c);
void HAL_I2C_MemRxCpltCallback(I2C_HandleTypeDef *hi2c);
void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c);
void HAL_I2C_AbortCpltCallback(I2C_HandleTypeDef *hi2c);
HAL_I2C_StateTypeDef HAL_I2C_GetState(const I2C_HandleTypeDef *hi2c);
HAL_I2C_ModeTypeDef HAL_I2C_GetMode(const I2C_HandleTypeDef *hi2c);
uint32_t HAL_I2C_GetError(const I2C_HandleTypeDef *hi2c);
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
typedef enum
{
  HAL_PKA_STATE_RESET = 0x00U,
  HAL_PKA_STATE_READY = 0x01U,
  HAL_PKA_STATE_BUSY = 0x02U,
  HAL_PKA_STATE_ERROR = 0x03U,
}
HAL_PKA_StateTypeDef;
typedef struct
{
  PKA_TypeDef *Instance;
  volatile HAL_PKA_StateTypeDef State;
  volatile uint32_t ErrorCode;
  volatile uint32_t primeordersize;
  volatile uint32_t opsize;
  volatile uint32_t modulussize;
} PKA_HandleTypeDef;
typedef struct
{
  uint32_t scalarMulSize;
  uint32_t modulusSize;
  uint32_t coefSign;
  const uint8_t *coefA;
  const uint8_t *coefB;
  const uint8_t *modulus;
  const uint8_t *pointX;
  const uint8_t *pointY;
  const uint8_t *scalarMul;
  const uint8_t *primeOrder;
} PKA_ECCMulInTypeDef;
typedef struct
{
  uint32_t primeOrderSize;
  uint32_t scalarMulSize;
  uint32_t modulusSize;
  uint32_t coefSign;
  const uint8_t *coefA;
  const uint8_t *coefB;
  const uint8_t *modulus;
  const uint8_t *pointX;
  const uint8_t *pointY;
  const uint8_t *scalarMul;
  const uint8_t *primeOrder;
} PKA_ECCMulExInTypeDef;
typedef struct
{
  uint32_t modulusSize;
  uint32_t coefSign;
  const uint8_t *coefA;
  const uint8_t *coefB;
  const uint8_t *modulus;
  const uint8_t *pointX;
  const uint8_t *pointY;
  const uint32_t *pMontgomeryParam;
} PKA_PointCheckInTypeDef;
typedef struct
{
  uint32_t size;
  const uint8_t *pOpDp;
  const uint8_t *pOpDq;
  const uint8_t *pOpQinv;
  const uint8_t *pPrimeP;
  const uint8_t *pPrimeQ;
  const uint8_t *popA;
} PKA_RSACRTExpInTypeDef;
typedef struct
{
  uint32_t primeOrderSize;
  uint32_t modulusSize;
  uint32_t coefSign;
  const uint8_t *coef;
  const uint8_t *modulus;
  const uint8_t *basePointX;
  const uint8_t *basePointY;
  const uint8_t *pPubKeyCurvePtX;
  const uint8_t *pPubKeyCurvePtY;
  const uint8_t *RSign;
  const uint8_t *SSign;
  const uint8_t *hash;
  const uint8_t *primeOrder;
} PKA_ECDSAVerifInTypeDef;
typedef struct
{
  uint32_t primeOrderSize;
  uint32_t modulusSize;
  uint32_t coefSign;
  const uint8_t *coef;
  const uint8_t *coefB;
  const uint8_t *modulus;
  const uint8_t *integer;
  const uint8_t *basePointX;
  const uint8_t *basePointY;
  const uint8_t *hash;
  const uint8_t *privateKey;
  const uint8_t *primeOrder;
} PKA_ECDSASignInTypeDef;
typedef struct
{
  uint8_t *RSign;
  uint8_t *SSign;
} PKA_ECDSASignOutTypeDef;
typedef struct
{
  uint8_t *ptX;
  uint8_t *ptY;
} PKA_ECDSASignOutExtParamTypeDef, PKA_ECCMulOutTypeDef, PKA_ECCProjective2AffineOutTypeDef,
PKA_ECCDoubleBaseLadderOutTypeDef;
typedef struct
{
  uint8_t *ptX;
  uint8_t *ptY;
  uint8_t *ptZ;
} PKA_ECCCompleteAdditionOutTypeDef;
typedef struct
{
  uint32_t expSize;
  uint32_t OpSize;
  const uint8_t *pExp;
  const uint8_t *pOp1;
  const uint8_t *pMod;
} PKA_ModExpInTypeDef;
typedef struct
{
  uint32_t expSize;
  uint32_t OpSize;
  const uint8_t *pOp1;
  const uint8_t *pExp;
  const uint8_t *pMod;
  const uint8_t *pPhi;
} PKA_ModExpProtectModeInTypeDef;
typedef struct
{
  uint32_t expSize;
  uint32_t OpSize;
  const uint8_t *pExp;
  const uint8_t *pOp1;
  const uint8_t *pMod;
  const uint32_t *pMontgomeryParam;
} PKA_ModExpFastModeInTypeDef;
typedef struct
{
  uint32_t size;
  const uint8_t *pOp1;
} PKA_MontgomeryParamInTypeDef;
typedef struct
{
  uint32_t size;
  const uint32_t *pOp1;
  const uint32_t *pOp2;
} PKA_AddInTypeDef, PKA_SubInTypeDef, PKA_MulInTypeDef, PKA_CmpInTypeDef;
typedef struct
{
  uint32_t size;
  const uint32_t *pOp1;
  const uint8_t *pMod;
} PKA_ModInvInTypeDef;
typedef struct
{
  uint32_t OpSize;
  uint32_t modSize;
  const uint32_t *pOp1;
  const uint8_t *pMod;
} PKA_ModRedInTypeDef;
typedef struct
{
  uint32_t size;
  const uint32_t *pOp1;
  const uint32_t *pOp2;
  const uint8_t *pOp3;
} PKA_ModAddInTypeDef, PKA_ModSubInTypeDef, PKA_MontgomeryMulInTypeDef;
typedef struct
{
  uint32_t primeOrderSize;
  uint32_t modulusSize;
  uint32_t coefSign;
  const uint8_t *coefA;
  const uint8_t *modulus;
  const uint8_t *integerK;
  const uint8_t *integerM;
  const uint8_t *basePointX1;
  const uint8_t *basePointY1;
  const uint8_t *basePointZ1;
  const uint8_t *basePointX2;
  const uint8_t *basePointY2;
  const uint8_t *basePointZ2;
} PKA_ECCDoubleBaseLadderInTypeDef;
typedef struct
{
  uint32_t modulusSize;
  const uint8_t *modulus;
  const uint8_t *basePointX;
  const uint8_t *basePointY;
  const uint8_t *basePointZ;
  const uint32_t *pMontgomeryParam;
} PKA_ECCProjective2AffineInTypeDef;
typedef struct
{
  uint32_t modulusSize;
  uint32_t coefSign;
  const uint8_t *modulus;
  const uint8_t *coefA;
  const uint8_t *basePointX1;
  const uint8_t *basePointY1;
  const uint8_t *basePointZ1;
  const uint8_t *basePointX2;
  const uint8_t *basePointY2;
  const uint8_t *basePointZ2;
} PKA_ECCCompleteAdditionInTypeDef;
HAL_StatusTypeDef HAL_PKA_Init(PKA_HandleTypeDef *hpka);
HAL_StatusTypeDef HAL_PKA_DeInit(PKA_HandleTypeDef *hpka);
void HAL_PKA_MspInit(PKA_HandleTypeDef *hpka);
void HAL_PKA_MspDeInit(PKA_HandleTypeDef *hpka);
HAL_StatusTypeDef HAL_PKA_ModExp(PKA_HandleTypeDef *hpka, PKA_ModExpInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_ModExp_IT(PKA_HandleTypeDef *hpka, PKA_ModExpInTypeDef *in);
HAL_StatusTypeDef HAL_PKA_ModExpFastMode(PKA_HandleTypeDef *hpka, PKA_ModExpFastModeInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_ModExpFastMode_IT(PKA_HandleTypeDef *hpka, PKA_ModExpFastModeInTypeDef *in);
HAL_StatusTypeDef HAL_PKA_ModExpProtectMode(PKA_HandleTypeDef *hpka, PKA_ModExpProtectModeInTypeDef *in,
                                            uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_ModExpProtectMode_IT(PKA_HandleTypeDef *hpka, PKA_ModExpProtectModeInTypeDef *in);
void HAL_PKA_ModExp_GetResult(PKA_HandleTypeDef *hpka, uint8_t *pRes);
HAL_StatusTypeDef HAL_PKA_ECDSASign(PKA_HandleTypeDef *hpka, PKA_ECDSASignInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_ECDSASign_IT(PKA_HandleTypeDef *hpka, PKA_ECDSASignInTypeDef *in);
void HAL_PKA_ECDSASign_GetResult(PKA_HandleTypeDef *hpka, PKA_ECDSASignOutTypeDef *out,
                                 PKA_ECDSASignOutExtParamTypeDef *outExt);
HAL_StatusTypeDef HAL_PKA_ECDSAVerif(PKA_HandleTypeDef *hpka, PKA_ECDSAVerifInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_ECDSAVerif_IT(PKA_HandleTypeDef *hpka, PKA_ECDSAVerifInTypeDef *in);
uint32_t HAL_PKA_ECDSAVerif_IsValidSignature(PKA_HandleTypeDef const *const hpka);
HAL_StatusTypeDef HAL_PKA_RSACRTExp(PKA_HandleTypeDef *hpka, PKA_RSACRTExpInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_RSACRTExp_IT(PKA_HandleTypeDef *hpka, PKA_RSACRTExpInTypeDef *in);
void HAL_PKA_RSACRTExp_GetResult(PKA_HandleTypeDef *hpka, uint8_t *pRes);
HAL_StatusTypeDef HAL_PKA_PointCheck(PKA_HandleTypeDef *hpka, PKA_PointCheckInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_PointCheck_IT(PKA_HandleTypeDef *hpka, PKA_PointCheckInTypeDef *in);
uint32_t HAL_PKA_PointCheck_IsOnCurve(PKA_HandleTypeDef const *const hpka);
HAL_StatusTypeDef HAL_PKA_ECCMul(PKA_HandleTypeDef *hpka, PKA_ECCMulInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_ECCMul_IT(PKA_HandleTypeDef *hpka, PKA_ECCMulInTypeDef *in);
HAL_StatusTypeDef HAL_PKA_ECCMulEx(PKA_HandleTypeDef *hpka, PKA_ECCMulExInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_ECCMulEx_IT(PKA_HandleTypeDef *hpka, PKA_ECCMulExInTypeDef *in);
void HAL_PKA_ECCMul_GetResult(PKA_HandleTypeDef *hpka, PKA_ECCMulOutTypeDef *out);
HAL_StatusTypeDef HAL_PKA_Add(PKA_HandleTypeDef *hpka, PKA_AddInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_Add_IT(PKA_HandleTypeDef *hpka, PKA_AddInTypeDef *in);
HAL_StatusTypeDef HAL_PKA_Sub(PKA_HandleTypeDef *hpka, PKA_SubInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_Sub_IT(PKA_HandleTypeDef *hpka, PKA_SubInTypeDef *in);
HAL_StatusTypeDef HAL_PKA_Cmp(PKA_HandleTypeDef *hpka, PKA_CmpInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_Cmp_IT(PKA_HandleTypeDef *hpka, PKA_CmpInTypeDef *in);
HAL_StatusTypeDef HAL_PKA_Mul(PKA_HandleTypeDef *hpka, PKA_MulInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_Mul_IT(PKA_HandleTypeDef *hpka, PKA_MulInTypeDef *in);
HAL_StatusTypeDef HAL_PKA_ModAdd(PKA_HandleTypeDef *hpka, PKA_ModAddInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_ModAdd_IT(PKA_HandleTypeDef *hpka, PKA_ModAddInTypeDef *in);
HAL_StatusTypeDef HAL_PKA_ModSub(PKA_HandleTypeDef *hpka, PKA_ModSubInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_ModSub_IT(PKA_HandleTypeDef *hpka, PKA_ModSubInTypeDef *in);
HAL_StatusTypeDef HAL_PKA_ModInv(PKA_HandleTypeDef *hpka, PKA_ModInvInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_ModInv_IT(PKA_HandleTypeDef *hpka, PKA_ModInvInTypeDef *in);
HAL_StatusTypeDef HAL_PKA_ModRed(PKA_HandleTypeDef *hpka, PKA_ModRedInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_ModRed_IT(PKA_HandleTypeDef *hpka, PKA_ModRedInTypeDef *in);
HAL_StatusTypeDef HAL_PKA_MontgomeryMul(PKA_HandleTypeDef *hpka, PKA_MontgomeryMulInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_MontgomeryMul_IT(PKA_HandleTypeDef *hpka, PKA_MontgomeryMulInTypeDef *in);
void HAL_PKA_Arithmetic_GetResult(PKA_HandleTypeDef *hpka, uint32_t *pRes);
HAL_StatusTypeDef HAL_PKA_MontgomeryParam(PKA_HandleTypeDef *hpka, PKA_MontgomeryParamInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_MontgomeryParam_IT(PKA_HandleTypeDef *hpka, PKA_MontgomeryParamInTypeDef *in);
void HAL_PKA_MontgomeryParam_GetResult(PKA_HandleTypeDef *hpka, uint32_t *pRes);
HAL_StatusTypeDef HAL_PKA_ECCDoubleBaseLadder(PKA_HandleTypeDef *hpka, PKA_ECCDoubleBaseLadderInTypeDef *in,
                                              uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_ECCDoubleBaseLadder_IT(PKA_HandleTypeDef *hpka, PKA_ECCDoubleBaseLadderInTypeDef *in);
void HAL_PKA_ECCDoubleBaseLadder_GetResult(PKA_HandleTypeDef *hpka, PKA_ECCDoubleBaseLadderOutTypeDef *out);
HAL_StatusTypeDef HAL_PKA_ECCProjective2Affine(PKA_HandleTypeDef *hpka, PKA_ECCProjective2AffineInTypeDef *in,
                                               uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_ECCProjective2Affine_IT(PKA_HandleTypeDef *hpka, PKA_ECCProjective2AffineInTypeDef *in);
void HAL_PKA_ECCProjective2Affine_GetResult(PKA_HandleTypeDef *hpka, PKA_ECCProjective2AffineOutTypeDef *out);
HAL_StatusTypeDef HAL_PKA_ECCCompleteAddition(PKA_HandleTypeDef *hpka, PKA_ECCCompleteAdditionInTypeDef *in,
                                              uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_ECCCompleteAddition_IT(PKA_HandleTypeDef *hpka, PKA_ECCCompleteAdditionInTypeDef *in);
void HAL_PKA_ECCCompleteAddition_GetResult(PKA_HandleTypeDef *hpka, PKA_ECCCompleteAdditionOutTypeDef *out);
HAL_StatusTypeDef HAL_PKA_Abort(PKA_HandleTypeDef *hpka);
void HAL_PKA_RAMReset(PKA_HandleTypeDef *hpka);
void HAL_PKA_OperationCpltCallback(PKA_HandleTypeDef *hpka);
void HAL_PKA_ErrorCallback(PKA_HandleTypeDef *hpka);
void HAL_PKA_IRQHandler(PKA_HandleTypeDef *hpka);
HAL_PKA_StateTypeDef HAL_PKA_GetState(const PKA_HandleTypeDef *hpka);
uint32_t HAL_PKA_GetError(const PKA_HandleTypeDef *hpka);
typedef struct
{
  uint32_t PVDLevel;
  uint32_t Mode;
} PWR_PVDTypeDef;
HAL_StatusTypeDef HAL_PWREx_ControlVoltageScaling(uint32_t VoltageScaling);
uint32_t HAL_PWREx_GetVoltageRange(void);
HAL_StatusTypeDef HAL_PWREx_ConfigSupply(uint32_t SupplySource);
uint32_t HAL_PWREx_GetSupplyConfig(void);
void HAL_PWREx_EnableSMPSPWM(void);
void HAL_PWREx_DisableSMPSPWM(void);
void HAL_PWREx_EnableFastSoftStart(void);
void HAL_PWREx_DisableFastSoftStart(void);
void HAL_PWREx_ConfigVdd11UsbSwitchDelay(uint32_t Delay);
void HAL_PWREx_EnableVdd11USB(void);
void HAL_PWREx_DisableVdd11USB(void);
HAL_StatusTypeDef HAL_PWREx_EnableUSBBooster(void);
HAL_StatusTypeDef HAL_PWREx_DisableUSBBooster(void);
void HAL_PWREx_EnableUSBPWR(void);
void HAL_PWREx_DisableUSBPWR(void);
void HAL_PWREx_EnableVddUSB(void);
void HAL_PWREx_DisableVddUSB(void);
void HAL_PWREx_EnableVddIO2(void);
void HAL_PWREx_DisableVddIO2(void);
void HAL_PWREx_EnableUltraLowPowerMode(void);
void HAL_PWREx_DisableUltraLowPowerMode(void);
void HAL_PWREx_EnableSRAM2ContentStandbyRetention(uint32_t SRAM2Pages);
void HAL_PWREx_DisableSRAM2ContentStandbyRetention(void);
void HAL_PWREx_EnableRadioSRAMClockStandbyRetention(uint32_t RadioSRAM);
void HAL_PWREx_DisableRadioSRAMClockStandbyRetention(void);
void HAL_PWREx_EnableSRAM1ContentStandbyRetention(uint32_t SRAM1Pages);
void HAL_PWREx_DisableSRAM1ContentStandbyRetention(void);
void HAL_PWREx_EnableRAMsContentStopRetention(uint32_t RAMSelection);
void HAL_PWREx_DisableRAMsContentStopRetention(uint32_t RAMSelection);
void HAL_PWREx_EnableFlashFastWakeUp(void);
void HAL_PWREx_DisableFlashFastWakeUp(void);
HAL_StatusTypeDef HAL_PWREx_EnableStandbyIORetention(uint32_t GPIO_Port, uint32_t GPIO_Pin);
HAL_StatusTypeDef HAL_PWREx_DisableStandbyIORetention(uint32_t GPIO_Port, uint32_t GPIO_Pin);
uint32_t HAL_PWREx_GetStandbyIORetentionStatus(uint32_t GPIO_Port);
HAL_StatusTypeDef HAL_PWREx_DisableStandbyRetainedIOState(uint32_t GPIO_Port, uint32_t GPIO_Pin);
void HAL_PWREx_EnablePTAOutputStop2Retention(void);
void HAL_PWREx_DisablePTAOutputStop2Retention(void);
uint32_t HAL_PWREx_GetPTAOutputStop2RetentionState(void);
void HAL_PWREx_ClearPTAOutputStop2RetentionState(void);
uint32_t HAL_PWREx_GetRADIOOperatingMode(void);
uint32_t HAL_PWREx_GetRADIOPHYOperatingMode(void);
uint32_t HAL_PWREx_GetRADIOEncryptionOperatingMode(void);
uint32_t HAL_PWREx_GetRFVDDHPA(void);
HAL_StatusTypeDef HAL_PWREx_SetREGVDDHPAInputSupply(uint32_t SupplySelection);
uint32_t HAL_PWREx_GetREGVDDHPAInputSupply(void);
void HAL_PWREx_EnableREGVDDHPABypass(void);
void HAL_PWREx_DisableREGVDDHPABypass(void);
void HAL_PWR_DeInit(void);
void HAL_PWR_EnableBkUpAccess(void);
void HAL_PWR_DisableBkUpAccess(void);
HAL_StatusTypeDef HAL_PWR_ConfigPVD(const PWR_PVDTypeDef *sConfigPVD);
void HAL_PWR_EnablePVD(void);
void HAL_PWR_DisablePVD(void);
void HAL_PWR_EnableWakeUpPin(uint32_t WakeUpPin);
void HAL_PWR_DisableWakeUpPin(uint32_t WakeUpPin);
uint32_t HAL_PWR_GetClearWakeupSource(void);
void HAL_PWR_EnterSLEEPMode(uint32_t Regulator, uint8_t SLEEPEntry);
void HAL_PWR_EnterSTOPMode(uint32_t Regulator, uint8_t STOPEntry);
void HAL_PWR_EnterSTANDBYMode(void);
void HAL_PWR_EnableSleepOnExit(void);
void HAL_PWR_DisableSleepOnExit(void);
void HAL_PWR_EnableSEVOnPend(void);
void HAL_PWR_DisableSEVOnPend(void);
void HAL_PWR_PVD_IRQHandler(void);
void HAL_PWR_PVD_Rising_Callback(void);
void HAL_PWR_PVD_Falling_Callback(void);
void HAL_PWR_WKUP_IRQHandler(void);
void HAL_PWR_WKUP1_Callback(void);
void HAL_PWR_WKUP2_Callback(void);
void HAL_PWR_WKUP3_Callback(void);
void HAL_PWR_WKUP4_Callback(void);
void HAL_PWR_WKUP5_Callback(void);
void HAL_PWR_WKUP6_Callback(void);
void HAL_PWR_WKUP7_Callback(void);
void HAL_PWR_WKUP8_Callback(void);
void HAL_PWR_ConfigAttributes(uint32_t Item, uint32_t Attributes);
HAL_StatusTypeDef HAL_PWR_GetConfigAttributes(uint32_t Item, uint32_t *pAttributes);
static inline void LL_RCC_HSE_Enable(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CR) |= ((0x1UL << (16UL))));
}
static inline void LL_RCC_HSE_Disable(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CR) &= ~((0x1UL << (16UL))));
}
static inline uint32_t LL_RCC_HSE_IsReady(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CR) & ((0x1UL << (17UL)))) == (0x1UL << (17UL))) ? 1UL : 0UL);
}
static inline void LL_RCC_HSE_EnablePrescaler(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CR) |= ((0x1UL << (20UL))));
}
static inline uint32_t LL_RCC_HSE_IsEnabledPrescaler(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CR) & ((0x1UL << (20UL)))) == (0x1UL << (20UL))) ? 1UL : 0UL);
}
static inline void LL_RCC_HSE_DisablePrescaler(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CR) &= ~((0x1UL << (20UL))));
}
static inline void LL_RCC_HSE_EnableCSS(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CR) |= ((0x1UL << (19UL))));
}
static inline void LL_RCC_HSE_SetClockTrimming(uint32_t Value)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->ECSCR1)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->ECSCR1))) & (~((0x3FUL << (16UL))))) | (Value << (16UL)))));
}
static inline uint32_t LL_RCC_HSE_GetClockTrimming(void)
{
  return (uint32_t)(((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->ECSCR1) & ((0x3FUL << (16UL)))) >> (16UL));
}
static inline void LL_RCC_HSI_EnableInStopMode(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CR) |= ((0x1UL << (9UL))));
}
static inline void LL_RCC_HSI_DisableInStopMode(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CR) &= ~((0x1UL << (9UL))));
}
static inline uint32_t LL_RCC_HSI_IsEnabledInStopMode(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CR) & ((0x1UL << (9UL)))) == (0x1UL << (9UL))) ? 1UL : 0UL);
}
static inline void LL_RCC_HSI_Enable(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CR) |= ((0x1UL << (8UL))));
}
static inline void LL_RCC_HSI_Disable(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CR) &= ~((0x1UL << (8UL))));
}
static inline uint32_t LL_RCC_HSI_IsReady(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CR) & ((0x1UL << (10UL)))) == (0x1UL << (10UL))) ? 1UL : 0UL);
}
static inline uint32_t LL_RCC_HSI_GetCalibration(void)
{
  return (uint32_t)(((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->ICSCR3) & ((0xFFFUL << (0UL)))) >> (0UL));
}
static inline void LL_RCC_HSI_SetCalibTrimming(uint32_t Value)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->ICSCR3)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->ICSCR3))) & (~((0x1FUL << (16UL))))) | (Value << (16UL)))));
}
static inline uint32_t LL_RCC_HSI_GetCalibTrimming(void)
{
  return (uint32_t)(((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->ICSCR3) & ((0x1FUL << (16UL)))) >> (16UL));
}
static inline void LL_RCC_LSE_Enable(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1) |= ((0x1UL << (0UL))));
}
static inline void LL_RCC_LSE_Disable(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1) &= ~((0x1UL << (0UL))));
}
static inline void LL_RCC_LSE_EnableBypass(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1) |= ((0x1UL << (2UL))));
}
static inline void LL_RCC_LSE_DisableBypass(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1) &= ~((0x1UL << (2UL))));
}
static inline void LL_RCC_LSE_EnableGlitchFilter(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1) |= ((0x1UL << (12UL))));
}
static inline void LL_RCC_LSE_DisableGlitchFilter(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1) &= ~((0x1UL << (12UL))));
}
static inline void LL_RCC_LSE_SetClockTrimming(uint32_t LSETrim)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1))) & (~((0x3UL << (13UL))))) | (LSETrim))));
}
static inline uint32_t LL_RCC_LSE_GetClockTrimming(void)
{
  return (uint32_t)(((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1) & ((0x3UL << (13UL)))));
}
static inline void LL_RCC_LSE_SetDriveCapability(uint32_t LSEDrive)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1))) & (~((0x3UL << (3UL))))) | (LSEDrive))));
}
static inline uint32_t LL_RCC_LSE_GetDriveCapability(void)
{
  return (uint32_t)(((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1) & ((0x3UL << (3UL)))));
}
static inline void LL_RCC_LSE_EnableCSS(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1) |= ((0x1UL << (5UL))));
}
static inline void LL_RCC_LSE_DisableCSS(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1) &= ~((0x1UL << (5UL))));
}
static inline uint32_t LL_RCC_LSE_IsReady(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1) & ((0x1UL << (1UL)))) == (0x1UL << (1UL))) ? 1UL : 0UL);
}
static inline void LL_RCC_LSE_EnablePropagation(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1) |= ((0x1UL << (7UL))));
}
static inline void LL_RCC_LSE_DisablePropagation(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1) &= ~((0x1UL << (7UL))));
}
static inline uint32_t LL_RCC_LSE_IsPropagationReady(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1) & ((0x1UL << (11UL)))) == (0x1UL << (11UL))) ? 1UL : 0UL);
}
static inline uint32_t LL_RCC_LSE_IsCSSDetected(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1) & ((0x1UL << (6UL)))) == (0x1UL << (6UL))) ? 1UL : 0UL);
}
static inline void LL_RCC_LSI1_Enable(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1) |= ((0x1UL << (26UL))));
}
static inline void LL_RCC_LSI1_Disable(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1) &= ~((0x1UL << (26UL))));
}
static inline uint32_t LL_RCC_LSI1_IsReady(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1) & ((0x1UL << (27UL)))) == (0x1UL << (27UL))) ? 1UL : 0UL);
}
static inline void LL_RCC_LSI1_SetPrescaler(uint32_t LSI1Prescaler)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1))) & (~((0x1UL << (28UL))))) | (LSI1Prescaler))));
}
static inline uint32_t LL_RCC_LSI1_GetPrescaler(void)
{
  return (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1) & ((0x1UL << (28UL)))));
}
static inline void LL_RCC_LSI2_Enable(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1) |= ((0x1UL << (29UL))));
}
static inline void LL_RCC_LSI2_Disable(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1) &= ~((0x1UL << (29UL))));
}
static inline uint32_t LL_RCC_LSI2_IsReady(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1) & ((0x1UL << (30UL)))) == (0x1UL << (30UL))) ? 1UL : 0UL);
}
static inline void LL_RCC_LSI2_SetTempSensitivity(uint32_t Sensitivity)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR2)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR2))) & (~((0xFUL << (4UL))))) | (Sensitivity))));
}
static inline uint32_t LL_RCC_LSI2_GetTempSensitivity(void)
{
  return (uint32_t)(((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR2) & ((0xFUL << (4UL)))));
}
static inline void LL_RCC_LSI2_SetOperatingMode(uint32_t Mode)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR2)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR2))) & (~((0x7UL << (0UL))))) | (Mode))));
}
static inline uint32_t LL_RCC_LSI2_GetOperatingMode(void)
{
  return (uint32_t)(((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR2) & ((0x7UL << (0UL)))));
}
static inline void LL_RCC_LSCO_Enable(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1) |= ((0x1UL << (24UL))));
}
static inline void LL_RCC_LSCO_Disable(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1) &= ~((0x1UL << (24UL))));
}
static inline void LL_RCC_LSCO_SetSource(uint32_t Source)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1))) & (~((0x1UL << (25UL))))) | (Source))));
}
static inline uint32_t LL_RCC_LSCO_GetSource(void)
{
  return (uint32_t)(((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1) & ((0x1UL << (25UL)))));
}
static inline void LL_RCC_SetSysClkSource(uint32_t Source)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CFGR1)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CFGR1))) & (~((0x3UL << (0UL))))) | (Source))));
}
static inline uint32_t LL_RCC_GetSysClkSource(void)
{
  return (uint32_t)(((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CFGR1) & ((0x3UL << (2UL)))));
}
static inline void LL_RCC_SetAHBPrescaler(uint32_t Prescaler)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CFGR2)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CFGR2))) & (~((0x7UL << (0UL))))) | (Prescaler))));
}
static inline void LL_RCC_SetSystickClockSource(uint32_t SystickSource)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CCIPR1)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CCIPR1))) & (~((0x3UL << (22UL))))) | (SystickSource))));
}
static inline void LL_RCC_SetAPB1Prescaler(uint32_t Prescaler)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CFGR2)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CFGR2))) & (~((0x7UL << (4UL))))) | (Prescaler))));
}
static inline void LL_RCC_SetAPB2Prescaler(uint32_t Prescaler)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CFGR2)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CFGR2))) & (~((0x7UL << (8UL))))) | (Prescaler))));
}
static inline void LL_RCC_SetAPB7Prescaler(uint32_t Prescaler)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CFGR3)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CFGR3))) & (~((0x7UL << (4UL))))) | (Prescaler))));
}
static inline void LL_RCC_SetAHB5Prescaler(uint32_t Prescaler)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CFGR4)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CFGR4))) & (~((0x7UL << (0UL))))) | (Prescaler))));
}
static inline void LL_RCC_SetAHB5Divider(uint32_t Divider)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CFGR4)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CFGR4))) & (~((0x1UL << (4UL))))) | (Divider))));
}
static inline uint32_t LL_RCC_GetAHBPrescaler(void)
{
  return (uint32_t)(((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CFGR2) & ((0x7UL << (0UL)))));
}
static inline uint32_t LL_RCC_GetSystickClockSource(void)
{
  return (uint32_t)(((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CCIPR1) & ((0x3UL << (22UL)))));
}
static inline uint32_t LL_RCC_GetAPB1Prescaler(void)
{
  return (uint32_t)(((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CFGR2) & ((0x7UL << (4UL)))));
}
static inline uint32_t LL_RCC_GetAPB2Prescaler(void)
{
  return (uint32_t)(((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CFGR2) & ((0x7UL << (8UL)))));
}
static inline uint32_t LL_RCC_GetAPB7Prescaler(void)
{
  return (uint32_t)(((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CFGR3) & ((0x7UL << (4UL)))));
}
static inline uint32_t LL_RCC_GetAHB5Prescaler(void)
{
  return (uint32_t)(((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CFGR4) & ((0x7UL << (0UL)))));
}
static inline uint32_t LL_RCC_GetAHB5Divider(void)
{
  return (uint32_t)(((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CFGR4) & ((0x1UL << (4UL)))));
}
static inline void LL_RCC_RADIO_EnableBasebandClock(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->RADIOENR) |= ((0x1UL << (1UL))));
}
static inline void LL_RCC_RADIO_DisableBasebandClock(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->RADIOENR) &= ~((0x1UL << (1UL))));
}
static inline uint32_t LL_RCC_RADIO_IsEnabledBasebandClock(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->RADIOENR) & ((0x1UL << (1UL)))) == (0x1UL << (1UL))) ? 1UL : 0UL);
}
static inline void LL_RCC_RADIO_DisableSleepTimerClock(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->RADIOENR) &= ~((0x1UL << (16UL))));
}
static inline uint32_t LL_RCC_RADIO_IsEnabledSleepTimerClock(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->RADIOENR) & ((0x1UL << (16UL)))) == (0x1UL << (16UL))) ? 1UL : 0UL);
}
static inline uint32_t LL_RCC_RADIO_IsBusClockReady(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->RADIOENR) & ((0x1UL << (17UL)))) == (0x1UL << (17UL))) ? 1UL : 0UL);
}
static inline void LL_RCC_RADIO_SetSleepTimerClockSource(uint32_t Source)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1))) & (~((0x3UL << (18UL))))) | (Source))));
}
static inline uint32_t LL_RCC_RADIO_GetSleepTimerClockSource(void)
{
  return (uint32_t)(((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1) & ((0x3UL << (18UL)))));
}
static inline void LL_RCC_ConfigMCO(uint32_t MCOxSource, uint32_t MCOxPrescaler)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CFGR1)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CFGR1))) & (~((0xFUL << (24UL)) | (0x7UL << (28UL))))) | (MCOxSource | MCOxPrescaler))));
}
static inline void LL_RCC_SetUSARTClockSource(uint32_t USARTxSource)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CCIPR1)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CCIPR1))) & (~(USARTxSource >> 16U))) | ((USARTxSource & 0x0000FFFFU)))));
}
static inline void LL_RCC_SetLPUARTClockSource(uint32_t LPUARTxSource)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CCIPR3)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CCIPR3))) & (~((0x3UL << (0UL))))) | (LPUARTxSource))));
}
static inline void LL_RCC_SetI2CClockSource(uint32_t I2CxSource)
{
  volatile uint32_t *reg = (volatile uint32_t *)(uint32_t)(((0x40000000UL + 0x06020000UL) + 0x0C00UL) + 0xE0U + (I2CxSource >> 24U));
  (((*reg)) = ((((((*reg))) & (~(3UL << (((I2CxSource & 0x00FF0000U) >> 16U) & 0x1FU)))) | (((I2CxSource & 0x000000FFU) << (((I2CxSource & 0x00FF0000U) >> 16U) & 0x1FU))))));
}
static inline void LL_RCC_SetSPIClockSource(uint32_t SPIxSource)
{
  volatile uint32_t *reg = (volatile uint32_t *)(uint32_t)(((0x40000000UL + 0x06020000UL) + 0x0C00UL) + 0xE0U + (SPIxSource >> 24U));
  (((*reg)) = ((((((*reg))) & (~(3UL << (((SPIxSource & 0x00FF0000U) >> 16U) & 0x1FU)))) | (((SPIxSource & 0x000000FFU) << (((SPIxSource & 0x00FF0000U) >> 16U) & 0x1FU))))));
}
static inline void LL_RCC_SetLPTIMClockSource(uint32_t LPTIMxSource)
{
  volatile uint32_t *reg = (volatile uint32_t *)(uint32_t)(((0x40000000UL + 0x06020000UL) + 0x0C00UL) + 0xE0U + (LPTIMxSource >> 24U));
  (((*reg)) = ((((((*reg))) & (~(3UL << (((LPTIMxSource & 0x00FF0000U) >> 16U) & 0x1FU)))) | (((LPTIMxSource & 0x000000FFU) << (((LPTIMxSource & 0x00FF0000U) >> 16U) & 0x1FU))))));
}
static inline void LL_RCC_SetSAIClockSource(uint32_t SAIxSource)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CCIPR2)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CCIPR2))) & (~((SAIxSource >> 16U)))) | ((SAIxSource & 0x0000FFFFU)))));
}
static inline void LL_RCC_SetRNGClockSource(uint32_t RNGxSource)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CCIPR2)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CCIPR2))) & (~((0x3UL << (12UL))))) | (RNGxSource))));
}
static inline void LL_RCC_SetADCClockSource(uint32_t ADC4Source)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CCIPR3)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CCIPR3))) & (~((0x7UL << (12UL))))) | (ADC4Source))));
}
static inline void LL_RCC_SetOTGHSClockSource(uint32_t OTGHSxSource)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CCIPR2)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CCIPR2))) & (~((0x3UL << (28UL))))) | (OTGHSxSource))));
}
static inline uint32_t LL_RCC_GetUSARTClockSource(uint32_t USARTx)
{
  return (uint32_t)(((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CCIPR1) & (USARTx)) | (USARTx << 16U));
}
static inline uint32_t LL_RCC_GetLPUARTClockSource(uint32_t LPUARTx)
{
  return (uint32_t)(((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CCIPR3) & (LPUARTx)));
}
static inline uint32_t LL_RCC_GetI2CClockSource(uint32_t I2Cx)
{
  volatile const uint32_t *reg = (volatile uint32_t *)(uint32_t)(((0x40000000UL + 0x06020000UL) + 0x0C00UL) + 0xE0U + (I2Cx >> 24U));
  return (uint32_t)((((*reg) & ((3UL << (((I2Cx & 0x00FF0000UL) >> 16U) & 0x1FUL)))) >> (((I2Cx & 0x00FF0000UL) >> 16U) & 0x1FUL)) | (I2Cx & 0xFFFF0000UL));
}
static inline uint32_t LL_RCC_GetSPIClockSource(uint32_t SPIx)
{
  volatile const uint32_t *reg = (volatile uint32_t *)(uint32_t)(((0x40000000UL + 0x06020000UL) + 0x0C00UL) + 0xE0U + (SPIx >> 24U));
  return (uint32_t)((((*reg) & ((3UL << (((SPIx & 0x00FF0000UL) >> 16U) & 0x1FUL)))) >> (((SPIx & 0x00FF0000UL) >> 16U) & 0x1FUL)) | (SPIx & 0xFFFF0000UL));
}
static inline uint32_t LL_RCC_GetLPTIMClockSource(uint32_t LPTIMx)
{
  volatile const uint32_t *reg = (volatile uint32_t *)(uint32_t)(((0x40000000UL + 0x06020000UL) + 0x0C00UL) + 0xE0U + (LPTIMx >> 24U));
  return (uint32_t)((((*reg) & ((3UL << (((LPTIMx & 0x00FF0000UL) >> 16U) & 0x1FUL)))) >> (((LPTIMx & 0x00FF0000UL) >> 16U) & 0x1FUL)) | (LPTIMx & 0xFFFF0000UL));
}
static inline void LL_RCC_SetTIMICClockSource(uint32_t TIMICSource)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CCIPR1)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CCIPR1))) & (~((0x1UL << (31UL))))) | (TIMICSource))));
}
static inline uint32_t LL_RCC_GetTIMICClockSource(void)
{
  return (uint32_t)(((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CCIPR1) & ((0x1UL << (31UL)))));
}
static inline uint32_t LL_RCC_GetSAIClockSource(uint32_t SAIx)
{
  return (uint32_t)(((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CCIPR2) & (SAIx)) | (SAIx << 16U));
}
static inline uint32_t LL_RCC_GetRNGClockSource(uint32_t RNGx)
{
  return (uint32_t)(((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CCIPR2) & (RNGx)));
}
static inline uint32_t LL_RCC_GetADCClockSource(uint32_t ADCx)
{
  return (uint32_t)(((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CCIPR3) & (ADCx)));
}
static inline uint32_t LL_RCC_GetOTGHSClockSource(uint32_t OTGHSx)
{
  return (uint32_t)(((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CCIPR2) & (OTGHSx)));
}
static inline void LL_RCC_SetRTCClockSource(uint32_t Source)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1))) & (~((0x3UL << (8UL))))) | (Source))));
}
static inline uint32_t LL_RCC_GetRTCClockSource(void)
{
  return (uint32_t)(((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1) & ((0x3UL << (8UL)))));
}
static inline void LL_RCC_ForceBackupDomainReset(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1) |= ((0x1UL << (16UL))));
}
static inline void LL_RCC_ReleaseBackupDomainReset(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->BDCR1) &= ~((0x1UL << (16UL))));
}
static inline void LL_RCC_PLL1_Enable(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CR) |= ((0x1UL << (24UL))));
}
static inline void LL_RCC_PLL1_Disable(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CR) &= ~((0x1UL << (24UL))));
}
static inline uint32_t LL_RCC_PLL1_IsReady(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CR) & ((0x1UL << (25UL)))) == (0x1UL << (25UL))) ? 1UL : 0UL);
}
static inline void LL_RCC_PLL1_EnablePLL1RCLKDivision(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1CFGR) |= ((0x1UL << (20UL))));
}
static inline void LL_RCC_PLL1_DisablePLL1RCLKDivision(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1CFGR) &= ~((0x1UL << (20UL))));
}
static inline void LL_RCC_PLL1_SetPLL1RCLKDivisionStep(uint32_t Step)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1CFGR)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1CFGR))) & (~((0x1UL << (21UL))))) | (Step))));
}
static inline uint32_t LL_RCC_PLL1_GetPLL1RCLKDivisionStep(void)
{
  return (uint32_t)(((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1CFGR) & ((0x1UL << (21UL)))));
}
static inline uint32_t LL_RCC_PLL1_IsPLL1RCLKDivisionReady(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1CFGR) & ((0x1UL << (22UL)))) == (0x1UL << (22UL))) ? 1UL : 0UL);
}
static inline void LL_RCC_PLL1_ConfigDomain_PLL1R(uint32_t Source, uint32_t PLLM, uint32_t PLLN, uint32_t PLLR)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1CFGR)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1CFGR))) & (~((0x3UL << (0UL)) | (0x7UL << (8UL))))) | (Source | ((PLLM - 1UL) << (8UL))))));
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1DIVR)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1DIVR))) & (~((0x1FFUL << (0UL)) | (0x7FUL << (24UL))))) | (((PLLN - 1UL) << (0UL)) | ((PLLR - 1UL) << (24UL))))));
}
static inline void LL_RCC_PLL1_ConfigDomain_PLL1P(uint32_t Source, uint32_t PLLM, uint32_t PLLN, uint32_t PLLP)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1CFGR)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1CFGR))) & (~((0x3UL << (0UL)) | (0x7UL << (8UL))))) | (Source | ((PLLM - 1UL) << (8UL))))));
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1DIVR)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1DIVR))) & (~((0x1FFUL << (0UL)) | (0x7FUL << (9UL))))) | (((PLLN - 1UL) << (0UL)) | ((PLLP - 1UL) << (9UL))))));
}
static inline void LL_RCC_PLL1_ConfigDomain_PLL1Q(uint32_t Source, uint32_t PLLM, uint32_t PLLN, uint32_t PLLQ)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1CFGR)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1CFGR))) & (~((0x3UL << (0UL)) | (0x7UL << (8UL))))) | (Source | ((PLLM - 1UL) << (8UL))))));
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1DIVR)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1DIVR))) & (~((0x1FFUL << (0UL)) | (0x7FUL << (16UL))))) | (((PLLN - 1UL) << (0UL)) | ((PLLQ - 1UL) << (16UL))))));
}
static inline void LL_RCC_PLL1_SetMainSource(uint32_t PLL1Source)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1CFGR)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1CFGR))) & (~((0x3UL << (0UL))))) | (PLL1Source))));
}
static inline uint32_t LL_RCC_PLL1_GetMainSource(void)
{
  return (uint32_t)(((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1CFGR) & ((0x3UL << (0UL)))));
}
static inline void LL_RCC_PLL1_SetN(uint32_t PLL1N)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1DIVR)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1DIVR))) & (~((0x1FFUL << (0UL))))) | ((PLL1N - 1UL) << (0UL)))));
}
static inline uint32_t LL_RCC_PLL1_GetN(void)
{
  return (uint32_t)((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1DIVR) & ((0x1FFUL << (0UL)))) >> (0UL)) + 1UL);
}
static inline void LL_RCC_PLL1_SetP(uint32_t PLL1P)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1DIVR)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1DIVR))) & (~((0x7FUL << (9UL))))) | ((PLL1P - 1UL) << (9UL)))));
}
static inline uint32_t LL_RCC_PLL1_GetP(void)
{
  return (uint32_t)((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1DIVR) & ((0x7FUL << (9UL)))) >> (9UL)) + 1UL);
}
static inline void LL_RCC_PLL1_SetQ(uint32_t PLL1Q)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1DIVR)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1DIVR))) & (~((0x7FUL << (16UL))))) | ((PLL1Q - 1UL) << (16UL)))));
}
static inline uint32_t LL_RCC_PLL1_GetQ(void)
{
  return (uint32_t)((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1DIVR) & ((0x7FUL << (16UL)))) >> (16UL)) + 1UL);
}
static inline void LL_RCC_PLL1_SetR(uint32_t PLL1R)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1DIVR)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1DIVR))) & (~((0x7FUL << (24UL))))) | ((PLL1R - 1UL) << (24UL)))));
}
static inline uint32_t LL_RCC_PLL1_GetR(void)
{
  return (uint32_t)((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1DIVR) & ((0x7FUL << (24UL)))) >> (24UL)) + 1UL);
}
static inline void LL_RCC_PLL1_SetDivider(uint32_t PLL1M)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1CFGR)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1CFGR))) & (~((0x7UL << (8UL))))) | ((PLL1M - 1UL) << (8UL)))));
}
static inline uint32_t LL_RCC_PLL1_GetDivider(void)
{
  return (uint32_t)((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1CFGR) & ((0x7UL << (8UL)))) >> (8UL)) + 1UL);
}
static inline void LL_RCC_PLL1_EnableDomain_PLL1P(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1CFGR) |= ((0x1UL << (16UL))));
}
static inline void LL_RCC_PLL1_DisableDomain_PLL1P(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1CFGR) &= ~((0x1UL << (16UL))));
}
static inline uint32_t LL_RCC_PLL1_IsEnabledDomain_PLL1P(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1CFGR) & ((0x1UL << (16UL)))) == (0x1UL << (16UL))) ? 1UL : 0UL);
}
static inline void LL_RCC_PLL1_EnableDomain_PLL1Q(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1CFGR) |= ((0x1UL << (17UL))));
}
static inline void LL_RCC_PLL1_DisableDomain_PLL1Q(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1CFGR) &= ~((0x1UL << (17UL))));
}
static inline uint32_t LL_RCC_PLL1_IsEnabledDomain_PLL1Q(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1CFGR) & ((0x1UL << (17UL)))) == (0x1UL << (17UL))) ? 1UL : 0UL);
}
static inline void LL_RCC_PLL1_EnableDomain_PLL1R(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1CFGR) |= ((0x1UL << (18UL))));
}
static inline void LL_RCC_PLL1_DisableDomain_PLL1R(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1CFGR) &= ~((0x1UL << (18UL))));
}
static inline uint32_t LL_RCC_PLL1_IsEnabledDomain_PLL1R(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1CFGR) & ((0x1UL << (18UL)))) == (0x1UL << (18UL))) ? 1UL : 0UL);
}
static inline void LL_RCC_PLL1FRACN_Enable(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1CFGR) |= ((0x1UL << (4UL))));
}
static inline uint32_t LL_RCC_PLL1FRACN_IsEnabled(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1CFGR) & ((0x1UL << (4UL)))) == (0x1UL << (4UL))) ? 1UL : 0UL);
}
static inline void LL_RCC_PLL1FRACN_Disable(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1CFGR) &= ~((0x1UL << (4UL))));
}
static inline void LL_RCC_PLL1_SetFRACN(uint32_t FRACN)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1FRACR)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1FRACR))) & (~((0x1FFFUL << (3UL))))) | (FRACN << (3UL)))));
}
static inline uint32_t LL_RCC_PLL1_GetFRACN(void)
{
  return (uint32_t)(((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1FRACR) & ((0x1FFFUL << (3UL)))) >> (3UL));
}
static inline void LL_RCC_PLL1_SetVCOInputRange(uint32_t InputRange)
{
  (((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1CFGR)) = ((((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PLL1CFGR))) & (~((0x3UL << (2UL))))) | (InputRange << (2UL)))));
}
static inline void LL_RCC_EnableNSecPrivilegedMode(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PRIVCFGR) |= ((0x1UL << (1UL))));
}
static inline void LL_RCC_DisableNSecPrivilegedMode(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PRIVCFGR) &= ~((0x1UL << (1UL))));
}
static inline uint32_t LL_RCC_IsEnabledNSecPrivilegedMode(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->PRIVCFGR) & ((0x1UL << (1UL)))) == (0x1UL << (1UL))) ? 1UL : 0UL);
}
static inline void LL_RCC_ClearFlag_LSI1RDY(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CICR) |= ((0x1UL << (0UL))));
}
static inline void LL_RCC_ClearFlag_LSI2RDY(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CICR) |= ((0x1UL << (16UL))));
}
static inline void LL_RCC_ClearFlag_LSERDY(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CICR) |= ((0x1UL << (1UL))));
}
static inline void LL_RCC_ClearFlag_HSIRDY(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CICR) |= ((0x1UL << (3UL))));
}
static inline void LL_RCC_ClearFlag_HSERDY(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CICR) |= ((0x1UL << (4UL))));
}
static inline void LL_RCC_ClearFlag_PLL1RDY(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CICR) |= ((0x1UL << (6UL))));
}
static inline void LL_RCC_ClearFlag_HSECSS(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CICR) |= ((0x1UL << (10UL))));
}
static inline uint32_t LL_RCC_IsActiveFlag_LSI1RDY(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CIFR) & ((0x1UL << (0UL)))) == (0x1UL << (0UL))) ? 1UL : 0UL);
}
static inline uint32_t LL_RCC_IsActiveFlag_LSI2RDY(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CIFR) & ((0x1UL << (16UL)))) == (0x1UL << (16UL))) ? 1UL : 0UL);
}
static inline uint32_t LL_RCC_IsActiveFlag_LSERDY(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CIFR) & ((0x1UL << (1UL)))) == (0x1UL << (1UL))) ? 1UL : 0UL);
}
static inline uint32_t LL_RCC_IsActiveFlag_HSIRDY(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CIFR) & ((0x1UL << (3UL)))) == (0x1UL << (3UL))) ? 1UL : 0UL);
}
static inline uint32_t LL_RCC_IsActiveFlag_HSERDY(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CIFR) & ((0x1UL << (4UL)))) == (0x1UL << (4UL))) ? 1UL : 0UL);
}
static inline uint32_t LL_RCC_IsActiveFlag_PLL1RDY(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CIFR) & ((0x1UL << (6UL)))) == (0x1UL << (6UL))) ? 1UL : 0UL);
}
static inline uint32_t LL_RCC_IsActiveFlag_HSECSS(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CIFR) & ((0x1UL << (10UL)))) == (0x1UL << (10UL))) ? 1UL : 0UL);
}
static inline uint32_t LL_RCC_IsActiveFlag_IWDGRST(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CSR) & ((0x1UL << (29UL)))) == (0x1UL << (29UL))) ? 1UL : 0UL);
}
static inline uint32_t LL_RCC_IsActiveFlag_LPWRRST(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CSR) & ((0x1UL << (31UL)))) == (0x1UL << (31UL))) ? 1UL : 0UL);
}
static inline uint32_t LL_RCC_IsActiveFlag_OBLRST(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CSR) & ((0x1UL << (25UL)))) == (0x1UL << (25UL))) ? 1UL : 0UL);
}
static inline uint32_t LL_RCC_IsActiveFlag_PINRST(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CSR) & ((0x1UL << (26UL)))) == (0x1UL << (26UL))) ? 1UL : 0UL);
}
static inline uint32_t LL_RCC_IsActiveFlag_SFTRST(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CSR) & ((0x1UL << (28UL)))) == (0x1UL << (28UL))) ? 1UL : 0UL);
}
static inline uint32_t LL_RCC_IsActiveFlag_WWDGRST(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CSR) & ((0x1UL << (30UL)))) == (0x1UL << (30UL))) ? 1UL : 0UL);
}
static inline uint32_t LL_RCC_IsActiveFlag_BORRST(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CSR) & ((0x1UL << (27UL)))) == (0x1UL << (27UL))) ? 1UL : 0UL);
}
static inline void LL_RCC_ClearResetFlags(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CSR) |= ((0x1UL << (23UL))));
}
static inline void LL_RCC_EnableIT_LSI1RDY(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CIER) |= ((0x1UL << (0UL))));
}
static inline void LL_RCC_EnableIT_LSI2RDY(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CIER) |= ((0x1UL << (16UL))));
}
static inline void LL_RCC_EnableIT_LSERDY(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CIER) |= ((0x1UL << (1UL))));
}
static inline void LL_RCC_EnableIT_HSIRDY(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CIER) |= ((0x1UL << (3UL))));
}
static inline void LL_RCC_EnableIT_HSERDY(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CIER) |= ((0x1UL << (4UL))));
}
static inline void LL_RCC_EnableIT_PLL1RDY(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CIER) |= ((0x1UL << (6UL))));
}
static inline void LL_RCC_DisableIT_LSI1RDY(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CIER) &= ~((0x1UL << (0UL))));
}
static inline void LL_RCC_DisableIT_LSI2RDY(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CIER) &= ~((0x1UL << (16UL))));
}
static inline void LL_RCC_DisableIT_LSERDY(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CIER) &= ~((0x1UL << (1UL))));
}
static inline void LL_RCC_DisableIT_HSIRDY(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CIER) &= ~((0x1UL << (3UL))));
}
static inline void LL_RCC_DisableIT_HSERDY(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CIER) &= ~((0x1UL << (4UL))));
}
static inline void LL_RCC_DisableIT_PLL1RDY(void)
{
  ((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CIER) &= ~((0x1UL << (6UL))));
}
static inline uint32_t LL_RCC_IsEnabledIT_LSI1RDY(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CIER) & ((0x1UL << (0UL)))) == (0x1UL << (0UL))) ? 1UL : 0UL);
}
static inline uint32_t LL_RCC_IsEnabledIT_LSI2RDY(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CIER) & ((0x1UL << (16UL)))) == (0x1UL << (16UL))) ? 1UL : 0UL);
}
static inline uint32_t LL_RCC_IsEnabledIT_LSERDY(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CIER) & ((0x1UL << (1UL)))) == (0x1UL << (1UL))) ? 1UL : 0UL);
}
static inline uint32_t LL_RCC_IsEnabledIT_HSIRDY(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CIER) & ((0x1UL << (3UL)))) == (0x1UL << (3UL))) ? 1UL : 0UL);
}
static inline uint32_t LL_RCC_IsEnabledIT_HSERDY(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CIER) & ((0x1UL << (4UL)))) == (0x1UL << (4UL))) ? 1UL : 0UL);
}
static inline uint32_t LL_RCC_IsEnabledIT_PLL1RDY(void)
{
  return ((((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->CIER) & ((0x1UL << (6UL)))) == (0x1UL << (6UL))) ? 1UL : 0UL);
}
static inline uint32_t LL_RCC_GetConfigSecure(void)
{
  return (uint32_t)(((((RCC_TypeDef *) ((0x40000000UL + 0x06020000UL) + 0x0C00UL))->SECCFGR) & (0x10FBU)));
}
typedef struct
{
  uint32_t PLLState;
  uint32_t PLLSource;
  uint32_t PLLM;
  uint32_t PLLN;
  uint32_t PLLP;
  uint32_t PLLQ;
  uint32_t PLLR;
  uint32_t PLLFractional;
} RCC_PLLInitTypeDef;
typedef struct
{
  uint32_t OscillatorType;
  uint32_t HSEState;
  uint32_t HSEDiv;
  uint32_t LSEState;
  uint32_t HSIState;
  uint32_t HSICalibrationValue;
  uint32_t LSIState;
  uint32_t LSIDiv;
  RCC_PLLInitTypeDef PLL1;
} RCC_OscInitTypeDef;
typedef struct
{
  uint32_t ClockType;
  uint32_t SYSCLKSource;
  uint32_t AHBCLKDivider;
  uint32_t APB1CLKDivider;
  uint32_t APB2CLKDivider;
  uint32_t APB7CLKDivider;
  uint32_t AHB5_PLL1_CLKDivider;
  uint32_t AHB5_HSEHSI_CLKDivider;
} RCC_ClkInitTypeDef;
typedef struct
{
  uint32_t FreqTempSens;
  uint32_t OpMode;
} RCC_LSIConfigTypeDef;
typedef struct
{
  uint32_t PeriphClockSelection;
  uint32_t Usart1ClockSelection;
  uint32_t Usart2ClockSelection;
  uint32_t Usart3ClockSelection;
  uint32_t I2c1ClockSelection;
  uint32_t I2c2ClockSelection;
  uint32_t I2c4ClockSelection;
  uint32_t Spi2ClockSelection;
  uint32_t Lptim2ClockSelection;
  uint32_t Spi1ClockSelection;
  uint32_t SystickClockSelection;
  uint32_t TimIcClockSelection;
  uint32_t Sai1ClockSelection;
  uint32_t RngClockSelection;
  uint32_t UsbOtgHsPhyClockSelection;
  uint32_t AudioSyncClockSelection;
  uint32_t Lpuart1ClockSelection;
  uint32_t Spi3ClockSelection;
  uint32_t I2c3ClockSelection;
  uint32_t Lptim1ClockSelection;
  uint32_t AdcClockSelection;
  uint32_t RTCClockSelection;
  uint32_t RadioSlpTimClockSelection;
} RCC_PeriphCLKInitTypeDef;
typedef struct
{
uint32_t CapturePrescaler;
uint32_t ClockPrescaler;
uint32_t AutoReloadValue;
uint32_t CompareValue;
} RCC_AudioSyncConfigTypeDef;
HAL_StatusTypeDef HAL_RCCEx_PeriphCLKConfig(const RCC_PeriphCLKInitTypeDef *PeriphClkInit);
void HAL_RCCEx_GetPeriphCLKConfig(RCC_PeriphCLKInitTypeDef *PeriphClkInit);
uint32_t HAL_RCCEx_GetPeriphCLKFreq(uint32_t PeriphClk);
void HAL_RCCEx_EnableLSECSS(void);
void HAL_RCCEx_DisableLSECSS(void);
void HAL_RCCEx_EnableLSCO(uint32_t LSCOSource);
void HAL_RCCEx_DisableLSCO(void);
void HAL_RCCEx_HSESetTrimming(uint32_t Trimming);
uint32_t HAL_RCCEx_HSEGetTrimming(void);
void HAL_RCCEx_LSESetTrimming(uint32_t Trimming);
uint32_t HAL_RCCEx_LSEGetTrimming(void);
void HAL_RCCEx_LSI2SetConfig(const RCC_LSIConfigTypeDef *pConfig);
void HAL_RCCEx_LSI2GetConfig(RCC_LSIConfigTypeDef *pConfig);
void HAL_RCCEx_EnableRadioBBClock(void);
void HAL_RCCEx_DisableRadioBBClock(void);
void HAL_RCCEx_EnableRequestUponRadioWakeUpEvent(void);
void HAL_RCCEx_DisableRequestUponRadioWakeUpEvent(void);
uint32_t HAL_RCCEx_GetRadioBusClockReadiness(void);
void HAL_RCCEx_EnableAudioSyncClock(void);
void HAL_RCCEx_DisableAudioSyncClock(void);
HAL_StatusTypeDef HAL_RCCEx_SetConfigAudioSync(const RCC_AudioSyncConfigTypeDef *pConf);
void HAL_RCCEx_GetConfigAudioSync(RCC_AudioSyncConfigTypeDef *pConf);
uint32_t HAL_RCCEx_GetAudioSyncCounterValue(void);
uint32_t HAL_RCCEx_GetAudioSyncCaptureValue(void);
HAL_StatusTypeDef HAL_RCC_DeInit(void);
HAL_StatusTypeDef HAL_RCC_OscConfig(const RCC_OscInitTypeDef *RCC_OscInitStruct);
HAL_StatusTypeDef HAL_RCC_ClockConfig(const RCC_ClkInitTypeDef *RCC_ClkInitStruct, uint32_t FLatency);
void HAL_RCC_MCOConfig(uint32_t RCC_MCOx, uint32_t RCC_MCOSource, uint32_t RCC_MCODiv);
void HAL_RCC_EnableCSS(void);
uint32_t HAL_RCC_GetSysClockFreq(void);
uint32_t HAL_RCC_GetHCLKFreq(void);
uint32_t HAL_RCC_GetPCLK1Freq(void);
uint32_t HAL_RCC_GetPCLK2Freq(void);
uint32_t HAL_RCC_GetPCLK7Freq(void);
uint32_t HAL_RCC_GetHCLK5Freq(void);
uint32_t HAL_RCC_GetPLL1PFreq(void);
uint32_t HAL_RCC_GetPLL1QFreq(void);
uint32_t HAL_RCC_GetPLL1RFreq(void);
void HAL_RCC_GetOscConfig(RCC_OscInitTypeDef *RCC_OscInitStruct);
void HAL_RCC_GetClockConfig(RCC_ClkInitTypeDef *RCC_ClkInitStruct, uint32_t *pFLatency);
void HAL_RCC_NMI_IRQHandler(void);
void HAL_RCC_CSSCallback(void);
uint32_t HAL_RCC_GetResetSource(void);
void HAL_RCC_ConfigAttributes(uint32_t Item, uint32_t Attributes);
HAL_StatusTypeDef HAL_RCC_GetConfigAttributes(uint32_t Item, uint32_t *pAttributes);
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
  RTC_ATampInputTypeDef TampInput[6U];
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
HAL_StatusTypeDef HAL_RTCEx_SetTimeStamp(RTC_HandleTypeDef *hrtc, uint32_t TimeStampEdge, uint32_t RTC_TimeStampPin);
HAL_StatusTypeDef HAL_RTCEx_SetTimeStamp_IT(RTC_HandleTypeDef *hrtc, uint32_t TimeStampEdge, uint32_t RTC_TimeStampPin);
HAL_StatusTypeDef HAL_RTCEx_DeactivateTimeStamp(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTCEx_GetTimeStamp(const RTC_HandleTypeDef *hrtc, RTC_TimeTypeDef *sTimeStamp,
                                         RTC_DateTypeDef *sTimeStampDate, uint32_t Format);
void HAL_RTCEx_TimeStampIRQHandler(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTCEx_PollForTimeStampEvent(const RTC_HandleTypeDef *hrtc, uint32_t Timeout);
void HAL_RTCEx_TimeStampEventCallback(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTCEx_SetWakeUpTimer(RTC_HandleTypeDef *hrtc, uint32_t WakeUpCounter, uint32_t WakeUpClock);
HAL_StatusTypeDef HAL_RTCEx_SetWakeUpTimer_IT(RTC_HandleTypeDef *hrtc, uint32_t WakeUpCounter, uint32_t WakeUpClock,
                                              uint32_t WakeUpAutoClr);
HAL_StatusTypeDef HAL_RTCEx_DeactivateWakeUpTimer(RTC_HandleTypeDef *hrtc);
uint32_t HAL_RTCEx_GetWakeUpTimer(const RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_WakeUpTimerIRQHandler(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_WakeUpTimerEventCallback(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTCEx_PollForWakeUpTimerEvent(const RTC_HandleTypeDef *hrtc, uint32_t Timeout);
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
HAL_StatusTypeDef HAL_RTCEx_MonotonicCounterIncrement(const RTC_HandleTypeDef *hrtc, uint32_t Instance);
HAL_StatusTypeDef HAL_RTCEx_MonotonicCounterGet(const RTC_HandleTypeDef *hrtc, uint32_t Instance, uint32_t *pValue);
HAL_StatusTypeDef HAL_RTCEx_SetSSRU_IT(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTCEx_DeactivateSSRU(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_SSRUIRQHandler(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_SSRUEventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_AlarmBEventCallback(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTCEx_PollForAlarmBEvent(const RTC_HandleTypeDef *hrtc, uint32_t Timeout);
HAL_StatusTypeDef HAL_RTCEx_SetTamper(const RTC_HandleTypeDef *hrtc, const RTC_TamperTypeDef *sTamper);
HAL_StatusTypeDef HAL_RTCEx_SetActiveTampers(RTC_HandleTypeDef *hrtc, const RTC_ActiveTampersTypeDef *sAllTamper);
HAL_StatusTypeDef HAL_RTCEx_SetActiveSeed(RTC_HandleTypeDef *hrtc, const uint32_t *pSeed);
HAL_StatusTypeDef HAL_RTCEx_SetTamper_IT(const RTC_HandleTypeDef *hrtc, const RTC_TamperTypeDef *sTamper);
HAL_StatusTypeDef HAL_RTCEx_DeactivateTamper(const RTC_HandleTypeDef *hrtc, uint32_t Tamper);
HAL_StatusTypeDef HAL_RTCEx_DeactivateActiveTampers(const RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTCEx_PollForTamperEvent(const RTC_HandleTypeDef *hrtc, uint32_t Tamper, uint32_t Timeout);
HAL_StatusTypeDef HAL_RTCEx_SetInternalTamper(const RTC_HandleTypeDef *hrtc,
                                              const RTC_InternalTamperTypeDef *sIntTamper);
HAL_StatusTypeDef HAL_RTCEx_SetInternalTamper_IT(const RTC_HandleTypeDef *hrtc,
                                                 const RTC_InternalTamperTypeDef *sIntTamper);
HAL_StatusTypeDef HAL_RTCEx_DeactivateInternalTamper(const RTC_HandleTypeDef *hrtc, uint32_t IntTamper);
HAL_StatusTypeDef HAL_RTCEx_PollForInternalTamperEvent(const RTC_HandleTypeDef *hrtc, uint32_t IntTamper,
                                                       uint32_t Timeout);
HAL_StatusTypeDef HAL_RTCEx_LockBootHardwareKey(const RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_TamperIRQHandler(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_Tamper1EventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_Tamper2EventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_Tamper3EventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_Tamper4EventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_Tamper5EventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_Tamper6EventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_InternalTamper3EventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_InternalTamper5EventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_InternalTamper6EventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_InternalTamper7EventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_InternalTamper8EventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_InternalTamper9EventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_InternalTamper11EventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_InternalTamper12EventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_InternalTamper13EventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_BKUPWrite(const RTC_HandleTypeDef *hrtc, uint32_t BackupRegister, uint32_t Data);
uint32_t HAL_RTCEx_BKUPRead(const RTC_HandleTypeDef *hrtc, uint32_t BackupRegister);
void HAL_RTCEx_BKUPErase(const RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_BKUPBlock(const RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_BKUPUnblock(const RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_ConfigEraseDeviceSecrets(const RTC_HandleTypeDef *hrtc, uint32_t DeviceSecretConf);
HAL_StatusTypeDef HAL_RTCEx_SecureModeGet(const RTC_HandleTypeDef *hrtc, RTC_SecureStateTypeDef *secureState);
HAL_StatusTypeDef HAL_RTCEx_PrivilegeModeSet(const RTC_HandleTypeDef *hrtc,
                                             const RTC_PrivilegeStateTypeDef *privilegeState);
HAL_StatusTypeDef HAL_RTCEx_PrivilegeModeGet(const RTC_HandleTypeDef *hrtc, RTC_PrivilegeStateTypeDef *privilegeState);
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
  uint32_t Mode;
  uint32_t Direction;
  uint32_t DataSize;
  uint32_t CLKPolarity;
  uint32_t CLKPhase;
  uint32_t NSS;
  uint32_t BaudRatePrescaler;
  uint32_t FirstBit;
  uint32_t TIMode;
  uint32_t CRCCalculation;
  uint32_t CRCPolynomial;
  uint32_t CRCLength;
  uint32_t NSSPMode;
  uint32_t NSSPolarity;
  uint32_t FifoThreshold;
  uint32_t TxCRCInitializationPattern;
  uint32_t RxCRCInitializationPattern;
  uint32_t MasterSSIdleness;
  uint32_t MasterInterDataIdleness;
  uint32_t MasterReceiverAutoSusp;
  uint32_t MasterKeepIOState;
  uint32_t IOSwap;
  uint32_t ReadyMasterManagement;
  uint32_t ReadyPolarity;
} SPI_InitTypeDef;
typedef enum
{
  HAL_SPI_STATE_RESET = 0x00UL,
  HAL_SPI_STATE_READY = 0x01UL,
  HAL_SPI_STATE_BUSY = 0x02UL,
  HAL_SPI_STATE_BUSY_TX = 0x03UL,
  HAL_SPI_STATE_BUSY_RX = 0x04UL,
  HAL_SPI_STATE_BUSY_TX_RX = 0x05UL,
  HAL_SPI_STATE_ERROR = 0x06UL,
  HAL_SPI_STATE_ABORT = 0x07UL
} HAL_SPI_StateTypeDef;
typedef struct __SPI_HandleTypeDef
{
  SPI_TypeDef *Instance;
  SPI_InitTypeDef Init;
  const uint8_t *pTxBuffPtr;
  uint16_t TxXferSize;
  volatile uint16_t TxXferCount;
  uint8_t *pRxBuffPtr;
  uint16_t RxXferSize;
  volatile uint16_t RxXferCount;
  uint32_t CRCSize;
  void (*RxISR)(struct __SPI_HandleTypeDef *hspi);
  void (*TxISR)(struct __SPI_HandleTypeDef *hspi);
  DMA_HandleTypeDef *hdmatx;
  DMA_HandleTypeDef *hdmarx;
  HAL_LockTypeDef Lock;
  volatile HAL_SPI_StateTypeDef State;
  volatile uint32_t ErrorCode;
} SPI_HandleTypeDef;
typedef struct
{
  uint32_t TriggerState;
  uint32_t TriggerSelection;
  uint32_t TriggerPolarity;
} SPI_AutonomousModeConfTypeDef;
HAL_StatusTypeDef HAL_SPIEx_FlushRxFifo(const SPI_HandleTypeDef *hspi);
HAL_StatusTypeDef HAL_SPIEx_EnableLockConfiguration(SPI_HandleTypeDef *hspi);
HAL_StatusTypeDef HAL_SPIEx_ConfigureUnderrun(SPI_HandleTypeDef *hspi, uint32_t UnderrunDetection,
                                              uint32_t UnderrunBehaviour);
HAL_StatusTypeDef HAL_SPIEx_SetConfigAutonomousMode(SPI_HandleTypeDef *hspi,
                                                    const SPI_AutonomousModeConfTypeDef *sConfig);
HAL_StatusTypeDef HAL_SPIEx_GetConfigAutonomousMode(const SPI_HandleTypeDef *hspi,
                                                    SPI_AutonomousModeConfTypeDef *sConfig);
HAL_StatusTypeDef HAL_SPIEx_ClearConfigAutonomousMode(SPI_HandleTypeDef *hspi);
HAL_StatusTypeDef HAL_SPI_Init(SPI_HandleTypeDef *hspi);
HAL_StatusTypeDef HAL_SPI_DeInit(SPI_HandleTypeDef *hspi);
void HAL_SPI_MspInit(SPI_HandleTypeDef *hspi);
void HAL_SPI_MspDeInit(SPI_HandleTypeDef *hspi);
HAL_StatusTypeDef HAL_SPI_Transmit(SPI_HandleTypeDef *hspi, const uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_SPI_Receive(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_SPI_TransmitReceive(SPI_HandleTypeDef *hspi, const uint8_t *pTxData, uint8_t *pRxData,
                                          uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_SPI_Transmit_IT(SPI_HandleTypeDef *hspi, const uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_SPI_Receive_IT(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_SPI_TransmitReceive_IT(SPI_HandleTypeDef *hspi, const uint8_t *pTxData, uint8_t *pRxData,
                                             uint16_t Size);
HAL_StatusTypeDef HAL_SPI_Transmit_DMA(SPI_HandleTypeDef *hspi, const uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_SPI_Receive_DMA(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_SPI_TransmitReceive_DMA(SPI_HandleTypeDef *hspi, const uint8_t *pTxData, uint8_t *pRxData,
                                              uint16_t Size);
HAL_StatusTypeDef HAL_SPI_DMAPause(SPI_HandleTypeDef *hspi);
HAL_StatusTypeDef HAL_SPI_DMAResume(SPI_HandleTypeDef *hspi);
HAL_StatusTypeDef HAL_SPI_DMAStop(SPI_HandleTypeDef *hspi);
HAL_StatusTypeDef HAL_SPI_Abort(SPI_HandleTypeDef *hspi);
HAL_StatusTypeDef HAL_SPI_Abort_IT(SPI_HandleTypeDef *hspi);
void HAL_SPI_IRQHandler(SPI_HandleTypeDef *hspi);
void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi);
void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi);
void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef *hspi);
void HAL_SPI_TxHalfCpltCallback(SPI_HandleTypeDef *hspi);
void HAL_SPI_RxHalfCpltCallback(SPI_HandleTypeDef *hspi);
void HAL_SPI_TxRxHalfCpltCallback(SPI_HandleTypeDef *hspi);
void HAL_SPI_ErrorCallback(SPI_HandleTypeDef *hspi);
void HAL_SPI_AbortCpltCallback(SPI_HandleTypeDef *hspi);
void HAL_SPI_SuspendCallback(SPI_HandleTypeDef *hspi);
HAL_SPI_StateTypeDef HAL_SPI_GetState(const SPI_HandleTypeDef *hspi);
uint32_t HAL_SPI_GetError(const SPI_HandleTypeDef *hspi);
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
typedef enum
{
  UART_CLOCKSOURCE_PCLK1 = 0x00U,
  UART_CLOCKSOURCE_PCLK2 = 0x01U,
  UART_CLOCKSOURCE_PCLK7 = 0x02U,
  UART_CLOCKSOURCE_HSI = 0x04U,
  UART_CLOCKSOURCE_SYSCLK = 0x08U,
  UART_CLOCKSOURCE_LSE = 0x10U,
  UART_CLOCKSOURCE_UNDEFINED = 0x20U,
} UART_ClockSourceTypeDef;
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
void HAL_SYSCFG_EnableIOAnalogSwitchBooster(void);
void HAL_SYSCFG_DisableIOAnalogSwitchBooster(void);
void HAL_SYSCFG_EnableIOAnalogSwitchVdd(void);
void HAL_SYSCFG_DisableIOAnalogSwitchVdd(void);
void HAL_SYSCFG_VREFBUF_VoltageScalingConfig(uint32_t VoltageScaling);
void HAL_SYSCFG_VREFBUF_HighImpedanceConfig(uint32_t Mode);
void HAL_SYSCFG_VREFBUF_TrimmingConfig(uint32_t TrimmingValue);
HAL_StatusTypeDef HAL_SYSCFG_EnableVREFBUF(void);
void HAL_SYSCFG_DisableVREFBUF(void);
void HAL_SYSCFG_SetOTGPHYReferenceClockSelection(uint32_t RefClockSelection);
void HAL_SYSCFG_SetOTGPHYPowerDownConfig(uint32_t PowerDownConfig);
void HAL_SYSCFG_EnableOTGPHY(uint32_t OTGPHYConfig);
void HAL_SYSCFG_SetOTGPHYDisconnectThreshold(uint32_t DisconnectThreshold);
void HAL_SYSCFG_SetOTGPHYSquelchThreshold(uint32_t SquelchThreshold);
void HAL_SYSCFG_SetOTGPHYPreemphasisCurrent(uint32_t PreemphasisCurrent);
void HAL_SYSCFG_EnableCompensationCell(uint32_t Selection);
void HAL_SYSCFG_DisableCompensationCell(uint32_t Selection);
uint32_t HAL_SYSCFG_GetCompensationCellReadyStatus(uint32_t Selection);
void HAL_SYSCFG_ConfigCompensationCell(uint32_t Selection, uint32_t Code, uint32_t NmosValue,
                                       uint32_t PmosValue);
HAL_StatusTypeDef HAL_SYSCFG_GetCompensationCell(uint32_t Selection, uint32_t *pCode, uint32_t *pNmosValue,
                                                 uint32_t *pPmosValue);
void HAL_SYSCFG_Lock(uint32_t Item);
HAL_StatusTypeDef HAL_SYSCFG_GetLock(uint32_t *pItem);
HAL_StatusTypeDef HAL_SYSCFG_GetConfigAttributes(uint32_t Item, uint32_t *pAttributes);
typedef enum
{
  HAL_CRC_STATE_RESET = 0x00U,
  HAL_CRC_STATE_READY = 0x01U,
  HAL_CRC_STATE_BUSY = 0x02U,
  HAL_CRC_STATE_TIMEOUT = 0x03U,
  HAL_CRC_STATE_ERROR = 0x04U
} HAL_CRC_StateTypeDef;
typedef struct
{
  uint8_t DefaultPolynomialUse;
  uint8_t DefaultInitValueUse;
  uint32_t GeneratingPolynomial;
  uint32_t CRCLength;
  uint32_t InitValue;
  uint32_t InputDataInversionMode;
  uint32_t OutputDataInversionMode;
} CRC_InitTypeDef;
typedef struct
{
  CRC_TypeDef *Instance;
  CRC_InitTypeDef Init;
  HAL_LockTypeDef Lock;
  volatile HAL_CRC_StateTypeDef State;
  uint32_t InputDataFormat;
} CRC_HandleTypeDef;
HAL_StatusTypeDef HAL_CRCEx_Polynomial_Set(CRC_HandleTypeDef *hcrc, uint32_t Pol, uint32_t PolyLength);
HAL_StatusTypeDef HAL_CRCEx_Input_Data_Reverse(CRC_HandleTypeDef *hcrc, uint32_t InputReverseMode);
HAL_StatusTypeDef HAL_CRCEx_Output_Data_Reverse(CRC_HandleTypeDef *hcrc, uint32_t OutputReverseMode);
HAL_StatusTypeDef HAL_CRC_Init(CRC_HandleTypeDef *hcrc);
HAL_StatusTypeDef HAL_CRC_DeInit(CRC_HandleTypeDef *hcrc);
void HAL_CRC_MspInit(CRC_HandleTypeDef *hcrc);
void HAL_CRC_MspDeInit(CRC_HandleTypeDef *hcrc);
uint32_t HAL_CRC_Accumulate(CRC_HandleTypeDef *hcrc, uint32_t pBuffer[], uint32_t BufferLength);
uint32_t HAL_CRC_Calculate(CRC_HandleTypeDef *hcrc, uint32_t pBuffer[], uint32_t BufferLength);
HAL_CRC_StateTypeDef HAL_CRC_GetState(const CRC_HandleTypeDef *hcrc);
enum image_attributes
{
  RE_FLASH_AREA_SCRATCH_SIZE = (0x0000),
  RE_IMAGE_FLASH_SECURE_IMAGE_SIZE = ((0x40000)),
  RE_IMAGE_FLASH_NON_SECURE_IMAGE_SIZE = ((0x180000)),
  RE_IMAGE_FLASH_ADDRESS_SECURE = ((0x0c000000)+((((((((((0x0000) + ((0x2000))) + ((0x2000)) + (0x0000))+(0x2000)) + (0x10000)) + ((0x2000)))+((0x2000) + (0x2000)))+((0x2000) + (0x2000))) + ((0x2000) + (0x2000))) + (0x0))),
  RE_APP_IMAGE_NUMBER = (0x2),
  RE_IMAGE_NUMBER = (0x2),
  RE_EXTERNAL_FLASH_ENABLE = (0x1),
  RE_IMAGE_FLASH_ADDRESS_NON_SECURE = ((0x0c000000)+((((((((((0x0000) + ((0x2000))) + ((0x2000)) + (0x0000))+(0x2000)) + (0x10000)) + ((0x2000)))+((0x2000) + (0x2000)))+((0x2000) + (0x2000))) + ((0x2000) + (0x2000))) + (0x0) + ((0x40000)))),
  RE_IMAGE_FLASH_SECURE_UPDATE = ((0x00000000)+((0x00000000))),
  RE_IMAGE_FLASH_NON_SECURE_UPDATE = ((0x00000000)+((0x00000000) + ((0x40000)))),
  RE_PRIMARY_ONLY = (0x0),
  RE_S_DATA_IMAGE_NUMBER = (0x0),
  RE_IMAGE_FLASH_ADDRESS_DATA_SECURE = (0x0),
  RE_IMAGE_FLASH_DATA_SECURE_UPDATE = (0x0),
  RE_IMAGE_FLASH_SECURE_DATA_IMAGE_SIZE = (0x0),
  RE_NS_DATA_IMAGE_NUMBER = (0x0),
  RE_IMAGE_FLASH_ADDRESS_DATA_NON_SECURE = (0x0),
  RE_IMAGE_FLASH_DATA_NON_SECURE_UPDATE = (0x0),
  RE_IMAGE_FLASH_NON_SECURE_DATA_IMAGE_SIZE = (0x0),
  RE_BL2_PERSO_ADDRESS = ((0x0c000000)+(((0x0000) + ((0x2000))) + ((0x2000)) + (0x0000))),
  RE_OEMIROT_DOWNLOAD_IMAGE_AREA_0 = (0x0),
  RE_OEMIROT_DOWNLOAD_IMAGE_AREA_0_OFFSET = (0x0),
  RE_OEMIROT_DOWNLOAD_IMAGE_AREA_0_SIZE = (0x0),
  RE_OEMIROT_DOWNLOAD_IMAGE_AREA_2_OFFSET = (0x0),
  RE_OEMIROT_DOWNLOAD_IMAGE_AREA_2_SIZE = (0x0),
  RE_BL2_BOOT_ADDRESS = ((((((0x0C000000)) + (((((0x0000) + ((0x2000))) + ((0x2000)) + (0x0000))+(0x2000))))))),
  RE_BL2_SEC1_START = 0x0,
  RE_BL2_SEC1_END = (((((((((((0x0000) + ((0x2000))) + ((0x2000)) + (0x0000))+(0x2000)) + (0x10000)) + ((0x2000)))+((0x2000) + (0x2000)))+((0x2000) + (0x2000))) + ((0x2000) + (0x2000))) + (0x0))+(0x40000)-0x1),
  RE_BL2_WRP_START = ((((0x0000) + ((0x2000))) + ((0x2000)) + (0x0000))),
  RE_BL2_WRP_END = ((((((0x0000) + ((0x2000))) + ((0x2000)) + (0x0000))+(0x2000)) + (0x10000)) + ((0x2000)) - 0x1),
  RE_BL2_HDP_END = ((((((0x0000) + ((0x2000))) + ((0x2000)) + (0x0000))+(0x2000)) + (0x10000))-0x1),
  RE_AREA_0_OFFSET = ((((((((((0x0000) + ((0x2000))) + ((0x2000)) + (0x0000))+(0x2000)) + (0x10000)) + ((0x2000)))+((0x2000) + (0x2000)))+((0x2000) + (0x2000))) + ((0x2000) + (0x2000))) + (0x0)),
  RE_AREA_0_SIZE = ((0x40000)),
  RE_AREA_1_OFFSET = ((((((((((0x0000) + ((0x2000))) + ((0x2000)) + (0x0000))+(0x2000)) + (0x10000)) + ((0x2000)))+((0x2000) + (0x2000)))+((0x2000) + (0x2000))) + ((0x2000) + (0x2000))) + (0x0) + ((0x40000))),
  RE_AREA_1_SIZE = ((0x180000)),
  RE_AREA_2_OFFSET = ((0x00000000)),
  RE_AREA_2_SIZE = ((0x40000)),
  RE_AREA_3_OFFSET = ((0x00000000) + ((0x40000))),
  RE_AREA_3_SIZE = ((0x180000)),
  RE_AREA_4_OFFSET = (0x0),
  RE_AREA_4_SIZE = (0x0),
  RE_AREA_5_OFFSET = (0x0),
  RE_AREA_5_SIZE = (0x0),
  RE_AREA_6_OFFSET = (0x0),
  RE_AREA_6_SIZE = (0x0),
  RE_AREA_7_OFFSET = (0x0),
  RE_AREA_7_SIZE = (0x0),
  RE_S_NS_PARTITION_SIZE = ((0x40000)+(0x180000)),
  RE_FLASH_B_SIZE = (0x100000),
  RE_CRYPTO_SCHEME = 0x2,
  RE_ENCRYPTION = (0x1),
  RE_OVER_WRITE = (0x1),
  RE_FLASH_PAGE_NBR = (0x7F),
  RE_OEMIROT_APPLI_FULL_SECURE = (0x0),
  RE_SELECT_WBA_TARGET = (0x65),
  RE_IS_WBA_BOARD_DK = (0x1),
  RE_OEMIROT_FIRST_BOOT_STAGE = (0x0),
};
