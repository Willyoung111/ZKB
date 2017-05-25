#include "L298N.h"
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "DELAY.h"
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

#define LA1_ON           GPIO_SetBits(LA1_GPIO_PORT,LA1_GPIO_PIN)
#define LA1_OFF          GPIO_ResetBits(LA1_GPIO_PORT,LA1_GPIO_PIN)

#define LA2_ON           GPIO_SetBits(LA2_GPIO_PORT,LA2_GPIO_PIN)
#define LA2_OFF          GPIO_ResetBits(LA2_GPIO_PORT,LA2_GPIO_PIN)

#define LB1_ON           GPIO_SetBits(LB1_GPIO_PORT,LB1_GPIO_PIN)
#define LB1_OFF          GPIO_ResetBits(LB1_GPIO_PORT,LB1_GPIO_PIN)

#define LB2_ON           GPIO_SetBits(LB2_GPIO_PORT,LB2_GPIO_PIN)
#define LB2_OFF          GPIO_ResetBits(LB2_GPIO_PORT,LB2_GPIO_PIN)

#define LENA_ON          GPIO_SetBits(LENA_GPIO_PORT,LENA_GPIO_PIN)
#define LENA_OFF         GPIO_ResetBits(LENA_GPIO_PORT,LENA_GPIO_PIN)

#define LENB_ON          GPIO_SetBits(LENB_GPIO_PORT,LENB_GPIO_PIN)
#define LENB_OFF         GPIO_ResetBits(LENB_GPIO_PORT,LENB_GPIO_PIN)

void L298N_CONFIG(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(LA1_GPIO_CLK|LA2_GPIO_CLK|LB1_GPIO_CLK|LB2_GPIO_CLK, ENABLE);
    RCC_APB2PeriphClockCmd(RA1_GPIO_CLK|RA2_GPIO_CLK|RB1_GPIO_CLK|RB2_GPIO_CLK, ENABLE);
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;

    GPIO_InitStructure.GPIO_Pin = LA1_GPIO_PIN;
    GPIO_Init(LA1_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = LA2_GPIO_PIN;
    GPIO_Init(LA2_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = LB1_GPIO_PIN;
    GPIO_Init(LB1_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = LB2_GPIO_PIN;
    GPIO_Init(LB2_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = RA1_GPIO_PIN;
    GPIO_Init(RA1_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = RA2_GPIO_PIN;
    GPIO_Init(RA2_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = RB1_GPIO_PIN;
    GPIO_Init(RB1_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = RB2_GPIO_PIN;
    GPIO_Init(RB2_GPIO_PORT, &GPIO_InitStructure);

}
static void PWM_GPIO(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO,ENABLE);
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Pin = LENA_GPIO_PIN;
    GPIO_Init(LENA_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = LENB_GPIO_PIN;
    GPIO_Init(LENB_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = RENA_GPIO_PIN;
    GPIO_Init(RENA_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = RENB_GPIO_PIN;
    GPIO_Init(RENB_GPIO_PORT, &GPIO_InitStructure);

}
static void L298N_PWM(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_OCInitTypeDef TIM_OCInitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);

    TIM_TimeBaseStructure.TIM_Period=19999;
    TIM_TimeBaseStructure.TIM_Prescaler=143;
    TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

    TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM2;
    TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = 0;
    TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_Low;

    TIM_OC1Init(TIM3,&TIM_OCInitStructure);
    TIM_OC1PreloadConfig(TIM3,TIM_OCPreload_Enable);

    TIM_OC2Init(TIM3,&TIM_OCInitStructure);
    TIM_OC2PreloadConfig(TIM3,TIM_OCPreload_Enable);

    TIM_OC3Init(TIM3,&TIM_OCInitStructure);
    TIM_OC3PreloadConfig(TIM3,TIM_OCPreload_Enable);

    TIM_OC4Init(TIM3,&TIM_OCInitStructure);
    TIM_OC4PreloadConfig(TIM3,TIM_OCPreload_Enable);

    TIM_ARRPreloadConfig(TIM3, ENABLE);
    TIM_Cmd(TIM3,ENABLE);
}
void PWM_INIT(void)
{
    PWM_GPIO();
    L298N_PWM();
}
//LA A6 CH1/ LB A7 CH2/ RA B0 CH3/ RB B1 CH4/
void Set_Speed(uint32_t LA,uint32_t LB,uint32_t RA,uint32_t RB)
{
	TIM3->CCR1 = LA;
	TIM3->CCR2 = LB;
	TIM3->CCR3 = RA;
  TIM3->CCR4 = RB;
}
void L298N_CARCONTROL(int32_t LA,int32_t LB,int32_t RA,int32_t RB)
{
    if (LA<0)
	   {
	     L1B();
	     LA = -1*LA;
	   }
	else
	     L1F();


	if (LB<0)
	   {
	     L2B();
	     LB = -1*LB;
       }
	else
	     L2F();
	

	if (RA<0)
	   {
	     R1B();
	     RA = -1*RA;
       }
	   else
	     R1F();


	if (RB<0)
	   {
	     R2B();
	     RB = -1*RB;
       }
	   else
	     R2F();


    Set_Speed(LA,LB,RA,RB);

}
void L1F(void)
{
    LA1_OFF;
    LA2_ON;
   
}

void L1B(void)
{
    LA1_ON;
    LA2_OFF;
}

//L2
void L2F(void)
{
    LB1_OFF;
    LB2_ON;

}
void L2B(void)
{
    LB1_ON;
    LB2_OFF;
}
//R1
void R1F(void)
{
    RA1_ON;
    RA2_OFF;
}

void R1B(void)
{
    RA1_OFF;
    RA2_ON;
}
//R2
void R2F(void)
{
    RB1_OFF;
    RB2_ON;
}

void R2B(void)
{
    RB1_ON;
    RB2_OFF;
}
//void L298N_FWD();
//void L298N_BEH();
//void TURN_LEFT();
//void TURN_RIGHT();
void L298N_FWD(void)
{
    L298N_CARCONTROL(16750,16750,19900,19900);
}
void L298N_BEH(void)
{
    L298N_CARCONTROL(-16750,-16750,-19900,-19900);

}
void TURN_LEFT(double angel)
{
    double TURNtime;
    int T;
	DELAY_MS(50);
	L298N_BEH();
	DELAY_MS(50);
	L298N_STOP();
	DELAY_MS(250);
    TURNtime=6.3142*angel+31.928;
    T=TURNtime;
   L298N_CARCONTROL(-16750,-16750,19700,19700);
    DELAY_MS(T);

		L298N_FWD();
		DELAY_MS(400);
		
}
void TURN_RIGHT(double angel)
{
    double TURNtime;
    int T;
	DELAY_MS(50);
		L298N_BEH();
	DELAY_MS(50);
	L298N_STOP();
	DELAY_MS(250);
    TURNtime=6.3142*angel+31.928;
    T=TURNtime;
     L298N_CARCONTROL(16750,16750,-19700,-19700);
    DELAY_MS(T);
		L298N_FWD();
		DELAY_MS(400);
		
}
void L298N_STOP(void)
{
    L298N_CARCONTROL(0,0,0,0);
}
