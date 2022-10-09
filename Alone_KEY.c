#include "stm32f10x.h"                  // Device header
#include "Alone_KEY.h"
#include "LED.h"

void Init_KEY(void)
{
 RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC,ENABLE);

  GPIO_InitTypeDef  GPIO_InitStructure;	

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;  //������K1--PA0  (���¼��ߵ�ƽ)
  GPIO_Init(GPIOA,&GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_13; //����: K2--PC13 (���¼��ߵ�ƽ)
  GPIO_Init(GPIOC,&GPIO_InitStructure);

	
}

void Init_Alone_KEY(void)
{
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
  GPIO_InitTypeDef  GPIO_InitStructure;	
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5;
  GPIO_Init(GPIOC,&GPIO_InitStructure);

}
void LED_config(void)
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&GPIO_InitStructure);

	
	Red_LED  = Green_LED = Blue_LED = 1;


}
// ���°���K1���������ɿ�����K1����Ϩ��
// ���°���K2�̵������ɿ�����K2�̵�Ϩ��
void KEY_Scan(void)
{
  if(K1==1)
	{
	  Blue_LED = 0;
		while(K1==1);
	  Blue_LED = 1;		
	
	}
	
  if(K2==1)
	{
	  Green_LED = 0;
		while(K2==1);
	  Green_LED = 1;
	
	
	}	

}
//���°���K1������� ���ٴΰ��°���K1�����Ϩ��
//���°���K2���Ƶ��� ���ٴΰ��°���K2���Ƶ�Ϩ��
void KEY_Scan1(void)
{
  if(K1==1)
	{

		while(K1==1);
	  Red_LED=~Red_LED;		
	
	}
	
  if(K2==1)
	{
		while(K2==1);
	  Blue_LED=~Blue_LED;
	
	
	}	

}

void KEY_Scan2(void)
{
  if(K1==1)
	{

		while(K1==1);
	  BlueLED_Turn();		
	
	}
	
  if(K2==1)
	{
		while(K2==1);
	  GreenLED_Turn();
	
	
	}	

}

uint8_t KEY_Scan3(void)
{  uint8_t Keynum = 0;
  if(K1==1)
	{

		while(K1==1);
	  	Keynum = 1	;
	
	}
	
  if(K2==1)
	{
		while(K2==1);
	  Keynum = 2;
	
	
	}	


 return Keynum;


}

