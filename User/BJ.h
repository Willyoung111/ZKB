//适用于驱动五线四相电机
#ifndef __BJ_H
#define __BJ_H

#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "DELAY.h"

//IN1=B12
#define IN1_BJ_PORT    GPIOA
#define IN1_BJ_CLK     RCC_APB2Periph_GPIOA
#define IN1_BJ_PIN     GPIO_Pin_9
//IN2=B13
#define IN2_BJ_PORT    GPIOB
#define IN2_BJ_CLK     RCC_APB2Periph_GPIOB
#define IN2_BJ_PIN     GPIO_Pin_5
//IN3=B14
#define IN3_BJ_PORT    GPIOA
#define IN3_BJ_CLK     RCC_APB2Periph_GPIOA
#define IN3_BJ_PIN     GPIO_Pin_4
//IN4=B15
#define IN4_BJ_PORT    GPIOA
#define IN4_BJ_CLK     RCC_APB2Periph_GPIOA
#define IN4_BJ_PIN     GPIO_Pin_2

#define IN1_ON         GPIO_SetBits(IN1_BJ_PORT,IN1_BJ_PIN)
#define IN2_ON         GPIO_SetBits(IN2_BJ_PORT,IN2_BJ_PIN)
#define IN3_ON         GPIO_SetBits(IN3_BJ_PORT,IN3_BJ_PIN)
#define IN4_ON         GPIO_SetBits(IN4_BJ_PORT,IN4_BJ_PIN)

#define IN1_OFF        GPIO_ResetBits(IN1_BJ_PORT,IN1_BJ_PIN)
#define IN2_OFF        GPIO_ResetBits(IN2_BJ_PORT,IN2_BJ_PIN)
#define IN3_OFF        GPIO_ResetBits(IN3_BJ_PORT,IN3_BJ_PIN)
#define IN4_OFF        GPIO_ResetBits(IN4_BJ_PORT,IN4_BJ_PIN)

void BJ_CONFIG(void);
void BJ_FWD(void);
void BJ_BEH(void);
void BJ_STOP(void);
#endif
