#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "DELAY.h"
#include "BJ.h"
void BJ_CONFIG(void)
{

        GPIO_InitTypeDef GPIO_InitStructure;

        RCC_APB2PeriphClockCmd(IN1_BJ_CLK|IN2_BJ_CLK|IN3_BJ_CLK|IN4_BJ_CLK, ENABLE);
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);

        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;

        GPIO_InitStructure.GPIO_Pin = IN1_BJ_PIN;
        GPIO_Init(IN1_BJ_PORT, &GPIO_InitStructure);

        GPIO_InitStructure.GPIO_Pin = IN2_BJ_PIN;
        GPIO_Init(IN2_BJ_PORT, &GPIO_InitStructure);

        GPIO_InitStructure.GPIO_Pin = IN3_BJ_PIN;
        GPIO_Init(IN3_BJ_PORT, &GPIO_InitStructure);

        GPIO_InitStructure.GPIO_Pin = IN4_BJ_PIN;
        GPIO_Init(IN4_BJ_PORT, &GPIO_InitStructure);

}
void BJ_BEH(void)
{
	int i;
for(i=0;i<1000;i++)
    {
        IN1_ON;
        IN2_OFF;
        IN3_OFF;
        IN4_OFF;
        DELAY_MS(2);
        IN2_ON;
        IN1_OFF;
        IN3_OFF;
        IN4_OFF;
        DELAY_MS(2);
        IN3_ON;
        IN1_OFF;
        IN2_OFF;
        IN4_OFF;
        DELAY_MS(2);
        IN4_ON;
        IN1_OFF;
        IN2_OFF;
        IN3_OFF;
        DELAY_MS(2);
    }

}
void BJ_FWD(void)
{
	int i;
for(i=0;i<1000;i++)
    {
        IN4_ON;
        IN1_OFF;
        IN2_OFF;
        IN3_OFF;
        DELAY_MS(2);
        IN3_ON;
        IN1_OFF;
        IN2_OFF;
        IN4_OFF;
        DELAY_MS(2);
        IN2_ON;
        IN1_OFF;
        IN3_OFF;
        IN4_OFF;
        DELAY_MS(2);
        IN1_ON;
        IN2_OFF;
        IN3_OFF;
        IN4_OFF;
        DELAY_MS(2);
				
    }

}
void BJ_STOP(void)
{

    while(1)
    {
        IN4_OFF;
        IN1_OFF;
        IN2_OFF;
        IN3_OFF;
    }

}
