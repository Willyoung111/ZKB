#ifndef __L298N_H
#define __L298N_H


#include "stm32f10x.h"
#include "stm32f10x_gpio.h"



#define LA1_GPIO_PORT    GPIOB
#define LA1_GPIO_CLK     RCC_APB2Periph_GPIOB
#define LA1_GPIO_PIN     GPIO_Pin_10

#define LA2_GPIO_PORT    GPIOB
#define LA2_GPIO_CLK     RCC_APB2Periph_GPIOB
#define LA2_GPIO_PIN     GPIO_Pin_11

#define LB1_GPIO_PORT    GPIOA
#define LB1_GPIO_CLK     RCC_APB2Periph_GPIOA
#define LB1_GPIO_PIN     GPIO_Pin_8

#define LB2_GPIO_PORT    GPIOA
#define LB2_GPIO_CLK     RCC_APB2Periph_GPIOA
#define LB2_GPIO_PIN     GPIO_Pin_5

#define LENA_GPIO_PORT   GPIOA
#define LENA_GPIO_CLK    RCC_APB2Periph_GPIOA
#define LENA_GPIO_PIN    GPIO_Pin_6

#define LENB_GPIO_PORT   GPIOA
#define LENB_GPIO_CLK    RCC_APB2Periph_GPIOA
#define LENB_GPIO_PIN    GPIO_Pin_7

#define LA1_ON           GPIO_SetBits(LA1_GPIO_PORT,LA1_GPIO_PIN)
#define LA1_OFF          GPIO_ResetBits(LA1_GPIO_PORT,LA1_GPIO_PIN)

#define LA2_ON           GPIO_SetBits(LA2_GPIO_PORT,LA2_GPIO_PIN)
#define LA2_OFF          GPIO_ResetBits(LA2_GPIO_PORT,LA2_GPIO_PIN)

#define LB1_ON           GPIO_SetBits(LB1_GPIO_PORT,LB1_GPIO_PIN)
#define LB1_OFF          GPIO_ResetBits(LB1_GPIO_PORT,LB1_GPIO_PIN)

#define LB2_ON           GPIO_SetBits(LB2_GPIO_PORT,LB2_GPIO_PIN)
#define LB2_OFF          GPIO_ResetBits(LB2_GPIO_PORT,LB2_GPIO_PIN)

#define LENA_ON           GPIO_SetBits(LENA_GPIO_PORT,LENA_GPIO_PIN)
#define LENA_OFF          GPIO_ResetBits(LENA_GPIO_PORT,LENA_GPIO_PIN)

#define LENB_ON           GPIO_SetBits(LENB_GPIO_PORT,LENB_GPIO_PIN)
#define LENB_OFF          GPIO_ResetBits(LENB_GPIO_PORT,LENB_GPIO_PIN)

#define RA1_GPIO_PORT    GPIOB
#define RA1_GPIO_CLK     RCC_APB2Periph_GPIOB
#define RA1_GPIO_PIN     GPIO_Pin_12

#define RA2_GPIO_PORT    GPIOB
#define RA2_GPIO_CLK     RCC_APB2Periph_GPIOB
#define RA2_GPIO_PIN     GPIO_Pin_13

#define RB1_GPIO_PORT    GPIOB
#define RB1_GPIO_CLK     RCC_APB2Periph_GPIOB
#define RB1_GPIO_PIN     GPIO_Pin_14

#define RB2_GPIO_PORT    GPIOB
#define RB2_GPIO_CLK     RCC_APB2Periph_GPIOB
#define RB2_GPIO_PIN     GPIO_Pin_15
//CH3
#define RENA_GPIO_PORT   GPIOB
#define RENA_GPIO_CLK    RCC_APB2Periph_GPIOB
#define RENA_GPIO_PIN    GPIO_Pin_0
//CH4
#define RENB_GPIO_PORT   GPIOB
#define RENB_GPIO_CLK    RCC_APB2Periph_GPIOB
#define RENB_GPIO_PIN    GPIO_Pin_1


#define RA1_ON           GPIO_SetBits(RA1_GPIO_PORT,RA1_GPIO_PIN)
#define RA1_OFF          GPIO_ResetBits(RA1_GPIO_PORT,RA1_GPIO_PIN)

#define RA2_ON           GPIO_SetBits(RA2_GPIO_PORT,RA2_GPIO_PIN)
#define RA2_OFF          GPIO_ResetBits(RA2_GPIO_PORT,RA2_GPIO_PIN)

#define RB1_ON           GPIO_SetBits(RB1_GPIO_PORT,RB1_GPIO_PIN)
#define RB1_OFF          GPIO_ResetBits(RB1_GPIO_PORT,RB1_GPIO_PIN)

#define RB2_ON           GPIO_SetBits(RB2_GPIO_PORT,RB2_GPIO_PIN)
#define RB2_OFF          GPIO_ResetBits(RB2_GPIO_PORT,RB2_GPIO_PIN)

#define RENA_ON          GPIO_SetBits(RENA_GPIO_PORT,RENA_GPIO_PIN)
#define RENA_OFF         GPIO_ResetBits(RENA_GPIO_PORT,RENA_GPIO_PIN)

#define RENB_ON          GPIO_SetBits(RENB_GPIO_PORT,RENB_GPIO_PIN)
#define RENB_OFF         GPIO_ResetBits(RENB_GPIO_PORT,RENB_GPIO_PIN)

void L1F(void);
void L1B(void);
void L2F(void);
void L2B(void);
void R1F(void);
void R1B(void);
void R2F(void);
void R2B(void);
void L298N_FWD(void);
void L298N_BEH(void);
void L298N_STOP(void);
void TURN(double angel);
void L298N_CONFIG(void);
static void PWM_GPIO(void);
static void L298N_PWM(void);
void PWM_INIT(void);
void Set_Speed(uint32_t LA,uint32_t LB,uint32_t RA,uint32_t RB);
void L298N_CARCONTROL(int32_t LA,int32_t LB,int32_t RA,int32_t RB);
void TURN_LEFT(double angel);
void TURN_RIGHT(double angel);


#endif
