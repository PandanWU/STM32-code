#include "stm32f10x.h"                  // Device header

/*********************************************************
  ʹ�� IO ���ⲿ�жϵ�һ�㲽�裺

	1��	��ʼ��GPIO��Ϊ���룻
	2��	����AFIOʱ�ӣ�
	3��	����GPIO�����ж��ߵ�ӳ���ϵ��
	4��	��ʼ�������жϣ����ô��������ȣ�
	5��	�����жϷ��飨NVIC������ʹ���жϣ�
	6��	��д�жϷ�������






***********************************************************/
uint16_t CountSensor;
void Init_CountSensor(void)
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);	
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
 
  GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode =GPIO_Mode_IPU ;  //��������ģʽ
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_11;
	
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
/*********************************************
   	����AFIO������ѡ������
	  ����AFIOʱ�Ӻ�����GPIO�����ж��ߵ�ӳ���ϵ����GPIO�˿�ӳ�䵽EXTI�ж����ϣ�
	
**********************************************/		
	
	TIM_ETRClockMode2Config(TIM2, TIM_ExtTRGPSC_OFF, TIM_ExtTRGPolarity_NonInverted, 0xE);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource11);
	
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line = EXTI_Line11;                //�жϱ�־��Ϊ��EXTI_Line11
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;                  //ʹ���ж���
	EXTI_InitStructure.EXTI_Mode  =  EXTI_Mode_Interrupt;     // EXTIģʽѡ��Ϊ���ж�ģʽ
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;    //ѡ�񴥷���ʽΪ���½��ش���
	EXTI_Init(&EXTI_InitStructure);
	
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);       ////	  ����NVIC�ж����ȼ�����
	
	NVIC_InitTypeDef NVIC_InitStructure; 
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;       //�����ж�ͨ��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;            //ʹ���ж�ͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;  //������ռ���ȼ���Χ
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;         //������Ӧ���ȼ���Χ
	 
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

