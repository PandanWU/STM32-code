#include "stm32f10x.h"                  // Device header


void Init_LightSensor(void)
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_12;
	
	GPIO_Init(GPIOB,&GPIO_InitStructure);
 
}

uint8_t Get_LightSensor(void)
{

return GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12);
}
