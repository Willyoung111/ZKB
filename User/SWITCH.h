#ifndef __SWITCH_H
#define	__SWITCH_H


#include "stm32f10x.h"

#define Switch1_GPIO_PORT    GPIOA
#define Switch1_GPIO_CLK     RCC_APB2Periph_GPIOA
#define Switch1_GPIO_PIN     GPIO_Pin_10

#define SWITCH GPIO_ReadInputDataBit(Switch1_GPIO_PORT, Switch1_GPIO_PIN)
void SWITCH_CONFIG(void);

#endif
