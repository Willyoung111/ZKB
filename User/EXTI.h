
#ifndef __EXTI_H
#define __EXTI_H
#include "stm32f10x.h"



#define Switch1_GPIO_PORT    GPIOA
#define Switch1_GPIO_CLK     (RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO)
#define Switch1_GPIO_PIN    GPIO_Pin_1
#define Switch1_EXTI_PORTSOURCE   GPIO_PortSourceGPIOA
#define Switch1_EXTI_PINSOURCE    GPIO_PinSource1
#define Switch1_EXTI_LINE         EXTI_Line1
#define Switch1_EXTI_IRQ          EXTI1_IRQn
#define Switch1_IRQHandler        EXTI1_IRQHandler

#define Switch2_GPIO_PORT    GPIOA
#define Switch2_GPIO_CLK     (RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO)
#define Switch2_GPIO_PIN    GPIO_Pin_3
#define Switch2_EXTI_PORTSOURCE   GPIO_PortSourceGPIOA
#define Switch2_EXTI_PINSOURCE    GPIO_PinSource3
#define Switch2_EXTI_LINE         EXTI_Line3
#define Switch2_EXTI_IRQ          EXTI3_IRQn
#define Switch2_IRQHandler        EXTI3_IRQHandler


static void NVIC_Configuration(void);
void EXTI_CONFIG(void);
#endif
