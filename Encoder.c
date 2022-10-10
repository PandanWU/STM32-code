#include "stm32f10x.h"      

/*
	A��--PB2��B��--PB3
˳ʱ�뷽��A�೬ǰB��90��     
��ʱ�뷽��A���ͺ�B��90��


*/
 int16_t CountNum;

void Init_Encoder(void)
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);	

  GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;  //��������ģʽ
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3;	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz ;
	GPIO_Init(GPIOA,&GPIO_InitStructure);

  GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource2);
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource3);
	
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line = EXTI_Line2|EXTI_Line3;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;   //A,B������������ش���  
	EXTI_Init(&EXTI_InitStructure);

  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_Init(&NVIC_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;	
  NVIC_Init(&NVIC_InitStructure);


}

int16_t CountNum_Get(void)
{ 


 return  CountNum;
}

void  EXTI2_IRQHandler(void)
{
 if(EXTI_GetITStatus(EXTI_Line2)==SET)   //A��Ϊ�����ش��� ���B���Ƿ�Ϊ�͵�ƽ
 {
    if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_3)==SET)
		{
			CountNum++;
		}
	 
    EXTI_ClearITPendingBit(EXTI_Line2);
 }


}
void  EXTI3_IRQHandler(void)
{
 if(EXTI_GetITStatus(EXTI_Line3)==SET) //B��Ϊ�����ش��� ���A���Ƿ�Ϊ�͵�ƽ
 {
    if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_2)==SET)
		{
			CountNum--;
		}
		
   EXTI_ClearITPendingBit(EXTI_Line3);
 }


}




