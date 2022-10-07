#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "sys.h"

#define Red_LED    PBout(5)   //红
#define Green_LED  PBout(0)   //绿
#define Blue_LED   PBout(1)   //蓝


void Init_LED(void)
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&GPIO_InitStructure);

	
	Red_LED  = Green_LED = Blue_LED = 1;


}
void Red_LED_ON(void)
{
  Red_LED = 0;

}
void Red_LED_OFF(void)
{
  Red_LED = 1;

}

void Green_LED_ON(void)
{
  Green_LED = 0;

}
void Green_LED_OFF(void)
{
  Green_LED = 1;

}
void Yellow_LED_ON(void)
{
  Red_LED =Green_LED= 0;

}
void Yellow_LED_OFF(void)
{
  Red_LED = Green_LED =1;

}
void Blue_LED_ON(void)
{
  Blue_LED = 0;

}
void Blue_LED_OFF(void)
{
  Blue_LED = 1;

}
void White_LED_ON(void)
{
  Red_LED = Green_LED = Blue_LED = 0;

}
void White_LED_OFF(void)
{
  Red_LED = Green_LED= Blue_LED = 1;

}

void LED_Run(void)
{ 
//红色
  Red_LED = 0;
	Delay_ms(500);
  Red_LED = 1;
	Delay_ms(500);	
//绿色
  Green_LED = 0;
	Delay_ms(500);
  Green_LED = 1;
	Delay_ms(500);
//蓝色
  Blue_LED = 0;
	Delay_ms(500);
  Blue_LED = 1;
	Delay_ms(500);
//黄色
	Red_LED  = Green_LED  = 0;
	Delay_ms(500);
	Red_LED  = Green_LED  = 1;
	Delay_ms(500);
//紫色
	Red_LED  = Blue_LED = 0 ;
	Delay_ms(500);
	Red_LED  = Blue_LED = 1;
	Delay_ms(500);
//青色
  Green_LED = Blue_LED = 0;
	Delay_ms(500);
  Green_LED = Blue_LED = 1;
	Delay_ms(500);
//白色	
	Red_LED  = Green_LED = Blue_LED = 0;
	Delay_ms(500);
	Red_LED  = Green_LED = Blue_LED = 1;
	Delay_ms(500);	
	
	

}

