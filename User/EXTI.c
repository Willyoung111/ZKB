#include "EXTI.h"
static void NVIC_Configuration(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    NVIC_InitStructure.NVIC_IRQChannel = Switch1_EXTI_IRQ;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    NVIC_InitStructure.NVIC_IRQChannel = Switch2_EXTI_IRQ;
    NVIC_Init(&NVIC_InitStructure);
}

void EXTI_CONFIG(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    EXTI_InitTypeDef EXTI_InitStructure;
	
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO,ENABLE);
    NVIC_Configuration();

    GPIO_InitStructure.GPIO_Pin = Switch1_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_IN_FLOATING;
    GPIO_Init(Switch1_GPIO_PORT, &GPIO_InitStructure);
    GPIO_EXTILineConfig(Switch1_EXTI_PORTSOURCE, Switch1_EXTI_PINSOURCE);
    EXTI_InitStructure.EXTI_Line = Switch1_EXTI_LINE;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
    EXTI_InitStructure.EXTI_LineCmd = DISABLE;
    EXTI_Init(&EXTI_InitStructure);

    GPIO_InitStructure.GPIO_Pin = Switch2_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_IN_FLOATING;
    GPIO_Init(Switch2_GPIO_PORT, &GPIO_InitStructure);
    GPIO_EXTILineConfig(Switch2_EXTI_PORTSOURCE, Switch2_EXTI_PINSOURCE);
    EXTI_InitStructure.EXTI_Line = Switch2_EXTI_LINE;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
    EXTI_InitStructure.EXTI_LineCmd = DISABLE;
    EXTI_Init(&EXTI_InitStructure);
}
