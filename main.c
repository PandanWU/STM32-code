#include "stm32f10x.h"
#include  "LED.h"
/********************************
 ����LED������˸
�졢�̡������ơ��ϡ��ࡢ��

********************************/

int main(void)
{
 Init_LED();
 while(1)
 {
 LED_Run();

 
 }


}

