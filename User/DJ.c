//舵机控制代码,但是好像不是很对
#include "DJ.h"
void DJ_Config()
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(DJ_GPIO_CLK|RCC_APB2Periph_AFIO,ENABLE);
    GPIO_InitStructure.GPIO_Pin = DJ_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz;
    GPIO_Init(DJ_GPIO_PORT,&GPIO_InitStructure);
}
void DJ_ANGLE(int angle)
{
	  TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_OCInitTypeDef TIM_OCInitStructure;
    angle=angle*5.56;
    angle=angle+1000;
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
    TIM_TimeBaseStructure.TIM_Period=19999;
    TIM_TimeBaseStructure.TIM_Prescaler=143;
    TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
    TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM2;
    TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse=angle;
    TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_Low;

    TIM_OC1Init(TIM4,&TIM_OCInitStructure);
    TIM_OC1PreloadConfig(TIM4,TIM_OCPreload_Enable);

    TIM_ARRPreloadConfig(TIM4, ENABLE);
    TIM_Cmd(TIM4,ENABLE);
}
