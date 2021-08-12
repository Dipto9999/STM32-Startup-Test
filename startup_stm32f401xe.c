#include "stdint.h"
#include "system_stm32f4xx.h"
#include "stm32f4xx.h"

/* Constants from Linker Script */

// Start Address For the Initialization Values of the .data Section.
extern uint32_t _sidata;
// Start Address For the .data Section.
extern uint32_t _sdata;
// End Address For the .data Section.
extern uint32_t _edata;
// Start Address For the .bss Section.
extern uint32_t _sbss;
// End Address for the .bss Section.
extern uint32_t _ebss;
// Top of Stack.
extern uint32_t _estack;

// Static Constructor Initializator from libc
extern void __libc_init_array();
// Main Program Entry Point
extern int main();

// Reset Handler
void Reset_Handler() {
  // Initialize data Segment
  uint32_t* dataInit = &_sidata;
  uint32_t* data = &_sdata;
  while(data < &_edata) {
    *data++ = *dataInit++;
  }

  // Initialize bss Segment.
  uint32_t *bss = &_sbss;
  while (bss < &_ebss) {
    *bss++ = 0;
  }

  // Run ST System Initialization.
  SystemInit();
  // Initialize Static Constructor.
  __libc_init_array();

  // Enter Main Program.
  main();
  // Handle Case Where Main Function Returns.
  while(1);
}

// Default Handler for Unimplemented Interrupts
void Default_Handler() {
  while(1);
}

// Weak Definitions of Interrupts
__weak void NMI_Handler(void) { Default_Handler(); }
__weak void HardFault_Handler(void) { Default_Handler(); }
__weak void MemManage_Handler(void) { Default_Handler(); }
__weak void BusFault_Handler(void) { Default_Handler(); }
__weak void UsageFault_Handler(void) { Default_Handler(); }
__weak void SVC_Handler(void) { Default_Handler(); }
__weak void DebugMon_Handler(void) { Default_Handler(); }
__weak void PendSV_Handler(void) { Default_Handler(); }
__weak void SysTick_Handler(void) { Default_Handler(); }
__weak void WWDG_IRQHandler(void) { Default_Handler(); }
__weak void PVD_IRQHandler(void) { Default_Handler(); }
__weak void TAMP_STAMP_IRQHandler(void) { Default_Handler(); }
__weak void RTC_WKUP_IRQHandler(void) { Default_Handler(); }
__weak void FLASH_IRQHandler(void) { Default_Handler(); }
__weak void RCC_IRQHandler(void) { Default_Handler(); }
__weak void EXTI0_IRQHandler(void) { Default_Handler(); }
__weak void EXTI1_IRQHandler(void) { Default_Handler(); }
__weak void EXTI2_IRQHandler(void) { Default_Handler(); }
__weak void EXTI3_IRQHandler(void) { Default_Handler(); }
__weak void EXTI4_IRQHandler(void) { Default_Handler(); }
__weak void DMA1_Stream0_IRQHandler(void) { Default_Handler(); }
__weak void DMA1_Stream1_IRQHandler(void) { Default_Handler(); }
__weak void DMA1_Stream2_IRQHandler(void) { Default_Handler(); }
__weak void DMA1_Stream3_IRQHandler(void) { Default_Handler(); }
__weak void DMA1_Stream4_IRQHandler(void) { Default_Handler(); }
__weak void DMA1_Stream5_IRQHandler(void) { Default_Handler(); }
__weak void DMA1_Stream6_IRQHandler(void) { Default_Handler(); }
__weak void ADC_IRQHandler(void) { Default_Handler(); }
__weak void EXTI9_5_IRQHandler(void) { Default_Handler(); }
__weak void TIM1_BRK_TIM9_IRQHandler(void) { Default_Handler(); }
__weak void TIM1_UP_TIM10_IRQHandler(void) { Default_Handler(); }
__weak void TIM1_TRG_COM_TIM11_IRQHandler(void) { Default_Handler(); }
__weak void TIM1_CC_IRQHandler(void) { Default_Handler(); }
__weak void TIM2_IRQHandler(void) { Default_Handler(); }
__weak void TIM3_IRQHandler(void) { Default_Handler(); }
__weak void TIM4_IRQHandler(void) { Default_Handler(); }
__weak void I2C1_EV_IRQHandler(void) { Default_Handler(); }
__weak void I2C1_ER_IRQHandler(void) { Default_Handler(); }
__weak void I2C2_EV_IRQHandler(void) { Default_Handler(); }
__weak void I2C2_ER_IRQHandler(void) { Default_Handler(); }
__weak void SPI1_IRQHandler(void) { Default_Handler(); }
__weak void SPI2_IRQHandler(void) { Default_Handler(); }
__weak void USART1_IRQHandler(void) { Default_Handler(); }
__weak void USART2_IRQHandler(void) { Default_Handler(); }
__weak void EXTI15_10_IRQHandler(void) { Default_Handler(); }
__weak void RTC_Alarm_IRQHandler(void) { Default_Handler(); }
__weak void OTG_FS_WKUP_IRQHandler(void) { Default_Handler(); }
__weak void DMA1_Stream7_IRQHandler(void) { Default_Handler(); }
__weak void SDIO_IRQHandler(void) { Default_Handler(); }
__weak void TIM5_IRQHandler(void) { Default_Handler(); }
__weak void SPI3_IRQHandler(void) { Default_Handler(); }
__weak void DMA2_Stream0_IRQHandler(void) { Default_Handler(); }
__weak void DMA2_Stream1_IRQHandler(void) { Default_Handler(); }
__weak void DMA2_Stream2_IRQHandler(void) { Default_Handler(); }
__weak void DMA2_Stream3_IRQHandler(void) { Default_Handler(); }
__weak void DMA2_Stream4_IRQHandler(void) { Default_Handler(); }
__weak void OTG_FS_IRQHandler(void) { Default_Handler(); }
__weak void DMA2_Stream5_IRQHandler(void) { Default_Handler(); }
__weak void DMA2_Stream6_IRQHandler(void) { Default_Handler(); }
__weak void DMA2_Stream7_IRQHandler(void) { Default_Handler(); }
__weak void USART6_IRQHandler(void) { Default_Handler(); }
__weak void I2C3_EV_IRQHandler(void) { Default_Handler(); }
__weak void I2C3_ER_IRQHandler(void) { Default_Handler(); }
__weak void FPU_IRQHandler(void) { Default_Handler(); }
__weak void SPI4_IRQHandler(void) { Default_Handler(); }

// Interrupt Vector Table
__attribute__((section(".isr_vector")))
const void(*VectorTable[])(void) = {
  (const void(*)(void))&_estack,
  Reset_Handler,
  NMI_Handler,
  HardFault_Handler,
  MemManage_Handler,
  BusFault_Handler,
  UsageFault_Handler,
  0,
  0,
  0,
  0,
  SVC_Handler,
  DebugMon_Handler,
  0,
  PendSV_Handler,
  SysTick_Handler,
  WWDG_IRQHandler,
  PVD_IRQHandler,
  TAMP_STAMP_IRQHandler,
  RTC_WKUP_IRQHandler,
  FLASH_IRQHandler,
  RCC_IRQHandler,
  EXTI0_IRQHandler,
  EXTI1_IRQHandler,
  EXTI2_IRQHandler,
  EXTI3_IRQHandler,
  EXTI4_IRQHandler,
  DMA1_Stream0_IRQHandler,
  DMA1_Stream1_IRQHandler,
  DMA1_Stream2_IRQHandler,
  DMA1_Stream3_IRQHandler,
  DMA1_Stream4_IRQHandler,
  DMA1_Stream5_IRQHandler,
  DMA1_Stream6_IRQHandler,
  ADC_IRQHandler,
  0,
  0,
  0,
  0,
  EXTI9_5_IRQHandler,
  TIM1_BRK_TIM9_IRQHandler,
  TIM1_UP_TIM10_IRQHandler,
  TIM1_TRG_COM_TIM11_IRQHandler,
  TIM1_CC_IRQHandler,
  TIM2_IRQHandler,
  TIM3_IRQHandler,
  TIM4_IRQHandler,
  I2C1_EV_IRQHandler,
  I2C1_ER_IRQHandler,
  I2C2_EV_IRQHandler,
  I2C2_ER_IRQHandler,
  SPI1_IRQHandler,
  SPI2_IRQHandler,
  USART1_IRQHandler,
  USART2_IRQHandler,
  0,
  EXTI15_10_IRQHandler,
  RTC_Alarm_IRQHandler,
  OTG_FS_WKUP_IRQHandler,
  0,
  0,
  0,
  0,
  DMA1_Stream7_IRQHandler,
  0,
  SDIO_IRQHandler,
  TIM5_IRQHandler,
  SPI3_IRQHandler,
  0,
  0,
  0,
  0,
  DMA2_Stream0_IRQHandler,
  DMA2_Stream1_IRQHandler,
  DMA2_Stream2_IRQHandler,
  DMA2_Stream3_IRQHandler,
  DMA2_Stream4_IRQHandler,
  0,
  0,
  0,
  0,
  0,
  0,
  OTG_FS_IRQHandler,
  DMA2_Stream5_IRQHandler,
  DMA2_Stream6_IRQHandler,
  DMA2_Stream7_IRQHandler,
  USART6_IRQHandler,
  I2C3_EV_IRQHandler,
  I2C3_ER_IRQHandler,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  FPU_IRQHandler,
  0,
  0,
  SPI4_IRQHandler
};
