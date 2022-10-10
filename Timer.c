#include "stm32f10x.h"                  // Device header
#include "LED.h"
#include "sys.h"

uint16_t num;
void Init_Timer(void)
{
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	
	TIM_InternalClockConfig(TIM2);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;//����Ƶ
	TIM_TimeBaseInitStructure.TIM_CounterMode  =  TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period    = 10000-1; //�Զ���װֵ
	TIM_TimeBaseInitStructure.TIM_Prescaler =  7200-1; //Ԥ��Ƶ��
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter =0 ;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);
	
	TIM_ClearFlag(TIM2,TIM_FLAG_Update);  //�ֶ���������жϱ�־λ�������˸ճ�ʼ����ͽ����жϵ�����
	
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel =TIM2_IRQn ;
	NVIC_InitStructure.NVIC_IRQChannelCmd =ENABLE ;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =2 ;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =1 ;	
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_Cmd(TIM2,ENABLE);


}
uint16_t Get_num(void)
{


 return num;
}

void TIM2_IRQHandler(void)
{
  if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET)
	{
	 PBout(1) =~PBout(1) ;
	
	  num++;
	
	 TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
	}

}

