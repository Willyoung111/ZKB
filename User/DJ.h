#ifndef __DJ_H
#define __DJ_H

#include "stm32f10x.h"
//TIM4_CH1
#define DJ_GPIO_CLK  RCC_APB2Periph_GPIOB
#define DJ_GPIO_PORT GPIOB
#define DJ_GPIO_PIN  GPIO_Pin_6

void DJ_Config(void);
void DJ_ANGLE(int angle);


#endif
