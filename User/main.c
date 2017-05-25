//L298N_CARCONTROL(16750,16750,19700,19700);
//L298N_CARCONTROL(-19000,-19000,19000,19000);ת���ٶ�
//y = 6.3142x + 31.928��604->90,32S0->45)
//	L298N_CARCONTROL(0,0,0,0);
//DJ参数（50=0°100=180°）


//void L298N_FWD();
//void L298N_BEH();
//void TURN_LEFT();
//void TURN_RIGHT();

#include "L298N.h"
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "DELAY.h"
#include "SYS.h"
#include "SWITCH.h"
#include "BJ.h"
#include "DJ.h"
#include "RED.h"
//舵机上限2 0,下限-110
//舵机角定位-25，抓取定位18
#define DJ_START                DJ_ANGLE(-60);
#define DJ_GET                  DJ_ANGLE(50);
#define TURN_RIGHT_90           TURN_RIGHT(97)
#define TURN_RIGHT_90_1         TURN_RIGHT(112)
#define TURN_LEFT_90 			TURN_LEFT(122.3)
#define TURN_LEFT_90_1 			TURN_LEFT(122.3)
#define color 1
#define TURN_LEFT_45            TURN_LEFT(52)
#define TURN_RIGHT_45           TURN_RIGHT(56)
#define FWD                     L298N_CARCONTROL(16750,16750,19700,19700)
#define STOP                    L298N_CARCONTROL(0,0,0,0)
#define BEH                     L298N_CARCONTROL(-16750,-16750,-19700,-19700)
int temp=0;
int i;
int GET(void)
	{
			if(LR == 0&&RR==0&&temp==0)
			{
				DELAY_MS(2);
				if(LR == 0&&RR==0&&temp==0)
				{temp=1;}}
				DELAY_MS(10);

				if (LR==1 && RR==1 && temp==1)
				{
					temp=0;
					return 1;
				}

			else
			return 0;
	}

int main(void)
{
	int count=0;
	i=color;
	L298N_CONFIG();
	DELAY_CONFIG();
	PWM_INIT();
    BJ_CONFIG();
    DJ_Config();
	SWITCH_CONFIG();
	RED_CONFIG();
	FWD;
	while(1)
	{
		if(GET()==1)
		{
			count++;
		}

	    if(count==3+i)
		{
			TURN_RIGHT(103);
			count++;
		}
		if(count==6+i)
		{
			TURN_LEFT_45;
			FWD;
			DELAY_MS(200);
			STOP;
			DJ_ANGLE(-60);
			DELAY_MS(1000);
			BEH;
			DELAY_MS(800);
			STOP;
			DELAY_MS(500);
			DJ_ANGLE(50);
			TURN_LEFT(50);
			BEH;
			DELAY_MS(800);
			TURN_RIGHT(75 );
			DELAY_MS(800);
			FWD;
			DELAY_MS(1000);
			DELAY_MS(1200);
			while(1)
			STOP;
			count++;
		}
	}
}
