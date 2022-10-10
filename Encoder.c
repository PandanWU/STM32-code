#include "stm32f10x.h"      

/*
	A相--PB2，B相--PB3
顺时针方向：A相超前B相90度     
逆时针方向：A相滞后B相90度


*/
 int16_t CountNum;

void Init_Encoder(void)
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);	

  GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;  //上拉输入模式
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3;	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz ;
	GPIO_Init(GPIOA,&GPIO_InitStructure);

  GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource2);
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource3);
	
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line = EXTI_Line2|EXTI_Line3;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;   //A,B相均采用上升沿触发  
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
 if(EXTI_GetITStatus(EXTI_Line2)==SET)   //A相为上升沿触发 检测B相是否为低电平
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
 if(EXTI_GetITStatus(EXTI_Line3)==SET) //B相为上升沿触发 检测A相是否为低电平
 {
    if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_2)==SET)
		{
			CountNum--;
		}
		
   EXTI_ClearITPendingBit(EXTI_Line3);
 }


}




