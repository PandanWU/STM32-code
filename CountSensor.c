#include "stm32f10x.h"                  // Device header

/*********************************************************
  使用 IO 口外部中断的一般步骤：

	1、	初始化GPIO口为输入；
	2、	开启AFIO时钟；
	3、	设置GPIO口与中断线的映射关系；
	4、	初始化线上中断，设置触发条件等；
	5、	配置中断分组（NVIC），并使能中断；
	6、	编写中断服务函数；






***********************************************************/
uint16_t CountSensor;
void Init_CountSensor(void)
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);	
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
 
  GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode =GPIO_Mode_IPU ;  //上拉输入模式
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_11;
	
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
/*********************************************
   	配置AFIO的数据选择器，
	  开启AFIO时钟后，设置GPIO口与中断线的映射关系（将GPIO端口映射到EXTI中断线上）
	
**********************************************/		
	
	TIM_ETRClockMode2Config(TIM2, TIM_ExtTRGPSC_OFF, TIM_ExtTRGPolarity_NonInverted, 0xE);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource11);
	
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line = EXTI_Line11;                //中断标志线为：EXTI_Line11
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;                  //使能中断线
	EXTI_InitStructure.EXTI_Mode  =  EXTI_Mode_Interrupt;     // EXTI模式选择为：中断模式
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;    //选择触发方式为：下降沿触发
	EXTI_Init(&EXTI_InitStructure);
	
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);       ////	  配置NVIC中断优先级分组
	
	NVIC_InitTypeDef NVIC_InitStructure; 
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;       //配置中断通道
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;            //使能中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;  //配置抢占优先级范围
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;         //配置响应优先级范围
	 
  NVIC_Init(&NVIC_InitStructure);



}
uint16_t Get_CountNum(void)
{



return CountSensor;
}


void EXTI15_10_IRQHandler(void)
{
  if(EXTI_GetITStatus(EXTI_Line11)==SET)
	{
	
	CountSensor++;
	
	 EXTI_ClearITPendingBit(EXTI_Line11);
	}


}

