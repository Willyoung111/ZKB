/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.c
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTI

  AL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"
#include "SWITCH.h"
#include "L298N.h"
#include "DELAY.h"
#include "RED.h"
#include "BJ.h"
#include "DJ.h"
#define DJ_START DJ_ANGLE(-25);
#define DJ_GET DJ_ANGLE(18);
#define BJ_START BJ_BEH();DELAY_MS(5000);BJ_BEH();DELAY_MS(5000);
#define BJ_GET BJ_FWD();DELAY_MS(5000);BJ_FWD();DELAY_MS(5000);



unsigned int Task_Delay[2]={0};

/** @addtogroup STM32F10x_StdPeriph_Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}
//0.828079
//0.021159s
//0.019902
/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
//EXTI_GenerateSWInterrupt()
void SysTick_Handler(void)
{
}

void EXTI3_IRQHandler(void)//left
{

	
	
		while(GPIO_ReadInputDataBit(Switch1_GPIO_PORT, Switch1_GPIO_PIN) == 0)
		{
			L298N_CARCONTROL(5000,5000,19000,19000);
			DELAY_MS(1000);
			
		}
		L298N_CARCONTROL(0,0,0,0);
		DJ_GET;
		DELAY_MS(3000);//需要调
		BJ_START;
		L298N_CARCONTROL(-19000,-19000,-19000,-19000);//需要调
		DELAY_MS(5000);//需要调
		TURN_RIGHT(45);//需要调
		L298N_CARCONTROL(19000,19000,19000,19000);
		DELAY_MS(2000);
		
		

    
}

void EXTI1_IRQHandler(void)//right
{
		

	
		while(GPIO_ReadInputDataBit(Switch1_GPIO_PORT, Switch1_GPIO_PIN) == 0)
		{
			L298N_CARCONTROL(5000,5000,19000,19000);
			DELAY_MS(1000);
			
		}
		L298N_CARCONTROL(0,0,0,0);
		DJ_GET;
		DELAY_MS(3000);//需要调
		BJ_START;
		L298N_CARCONTROL(-19000,-19000,-19000,-19000);//需要调
		DELAY_MS(5000);//需要调
		TURN_RIGHT(135);//需要调
		L298N_CARCONTROL(19000,19000,19000,19000);
		DELAY_MS(2000);
		

   
    
}


/*void EXTI3_IRQHandler(void)
{
	 L298N_CARCONTROL(10000,10000,5000,5000);
                DELAY_MS(5000);
    if(EXTI_GetITStatus(EXTI_Line3) != RESET)
    {
        if(line==3)
        {
            TURN(90);
            L298N_FWD();
            DELAY_MS(500);
        }
        if(line==5)
        {
            TURN(90);
            L298N_FWD();
            DELAY_MS(500);
        }
        if(line==7)
        {
            TURN(90);
            L298N_FWD();
            DELAY_MS(500);
        }
        line++;
        EXTI_ClearITPendingBit(EXTI_Line3);
    }
}*/

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
