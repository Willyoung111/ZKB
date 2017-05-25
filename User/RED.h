#ifndef __RED_H
#define __RED_H
#include "stm32f10x.h"
#include "L298N.h"
#include "DELAY.h"
#define black 1
#define white 0


#define RR_GPIO_PORT    GPIOA
#define RR_GPIO_CLK     RCC_APB2Periph_GPIOB
#define RR_GPIO_PIN     GPIO_Pin_11

#define LR_GPIO_PORT    GPIOA
#define LR_GPIO_CLK     RCC_APB2Periph_GPIOB
#define LR_GPIO_PIN     GPIO_Pin_12


#define LR GPIO_ReadInputDataBit(LR_GPIO_PORT, LR_GPIO_PIN)
#define RR GPIO_ReadInputDataBit(RR_GPIO_PORT, RR_GPIO_PIN)

void RED_CONFIG(void);
#endif
