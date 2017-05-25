#include "RED.h"
void RED_CONFIG(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RR_GPIO_CLK|LR_GPIO_CLK, ENABLE);
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;

    GPIO_InitStructure.GPIO_Pin = RR_GPIO_PIN;
    GPIO_Init(RR_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = LR_GPIO_PIN;
    GPIO_Init(LR_GPIO_PORT, &GPIO_InitStructure);
}
