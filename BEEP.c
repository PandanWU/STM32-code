#include "stm32f10x.h"                  // Device header
#include "sys.h"
#include "Delay.h"

void Init_BEEP(void)
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP ;
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_8|GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz ;
	
	GPIO_Init(GPIOA,&GPIO_InitStructure);
   PAout(8)=PAout(11)=0;

}

void BEEP_ON(void)
{

 GPIO_SetBits(GPIOA,GPIO_Pin_8);


}
void BEEP_OFF(void)
{

 GPIO_ResetBits(GPIOA,GPIO_Pin_8);


}
void BEEP_Way1(void)    // 1秒内 间隔响1次
{

 GPIO_SetBits(GPIOA,GPIO_Pin_11);
	Delay_ms(500);
 GPIO_ResetBits(GPIOA,GPIO_Pin_11);
  Delay_ms(500);	

}

void BEEP_Way2(void)     //1秒内连续响两声
{

 GPIO_SetBits(GPIOA,GPIO_Pin_11);
	Delay_ms(100);
 GPIO_ResetBits(GPIOA,GPIO_Pin_11);
  Delay_ms(100);	
 GPIO_SetBits(GPIOA,GPIO_Pin_11);
	Delay_ms(100);
 GPIO_ResetBits(GPIOA,GPIO_Pin_11);
  Delay_ms(700);
}

void BEEP_Way3(void)    // 1秒内连续响三声
{

 GPIO_SetBits(GPIOA,GPIO_Pin_11);
	Delay_ms(100);
 GPIO_ResetBits(GPIOA,GPIO_Pin_11);
  Delay_ms(100);	
 GPIO_SetBits(GPIOA,GPIO_Pin_11);
	Delay_ms(100);
 GPIO_ResetBits(GPIOA,GPIO_Pin_11);
  Delay_ms(100);
 GPIO_SetBits(GPIOA,GPIO_Pin_11);
	Delay_ms(100);
 GPIO_ResetBits(GPIOA,GPIO_Pin_11);
  Delay_ms(500);
}




























