#include "stm32f10x.h"                  // Device header
#include "sys.h"
#include "Delay.h"
 
#define    Pos1 PBout(12)
#define    Pos2 PBout(13)
#define    Pos3 PBout(14)
#define    Pos4 PBout(15)
#define    A   PAout(2)
#define    B   PAout(3)
#define    C   PAout(4)
#define    D   PAout(5)
#define    E   PAout(6)
#define    F   PAout(7)
#define    G   PAout(11)
#define    DP  PAout(12)

void Init_SMG(void)
{
  
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);	
	
 GPIO_InitTypeDef GPIOA_InitStructure;
 GPIOA_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
 GPIOA_InitStructure.GPIO_Pin   = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_11|GPIO_Pin_12;
 GPIOA_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOA,&GPIOA_InitStructure);	
	
 GPIO_InitTypeDef GPIOB_InitStructure;
 GPIOB_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
 GPIOB_InitStructure.GPIO_Pin   = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
 GPIOB_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOB,&GPIOB_InitStructure);	
	
	Pos1=Pos2=Pos3=Pos4=0; //关闭四位数码管
	A=B=C=D=E=F=G=DP=1;   //关闭八个段码
}



void SMG_Pos(uint16_t channal)
{
  switch (channal)
	{
	  case 1:
			Pos1=1;
		  Pos2=0;
			Pos3=0;
		  Pos4=0;		
		break;
	
	  case 2:
			Pos1=0;
		  Pos2=1;
			Pos3=0;
		  Pos4=0;
		break;
		
	  case 3:
			Pos1=0;
		  Pos2=0;
			Pos3=1;
		  Pos4=0;
		break;

	  case 4:
			Pos1=0;
		  Pos2=0;
			Pos3=0;
		  Pos4=1;
		break;
	  case 5:   //打开全部数码管
			Pos1=1;
		  Pos2=1;
			Pos3=1;
		  Pos4=1;
		break;
	  case 6:   //关闭所有数码管
			Pos1=0;
		  Pos2=0;
			Pos3=0;
		  Pos4=0;
		break;		
	
	}


}
void SMG_Data(uint16_t channal)
{  switch (channal)
	{
	case 0:
		A=B=C=D=E=F=0;
 		G=DP=1;
	break;
	case 1:
		B=C=0;
 	A=D=E=F=G=DP=1;	
	break;
	case 2:
		A=B=D=E=G=0;
 		C=F=DP=1;
	break;
	case 3:
		A=B=C=D=G=0;
 		E=F=DP=1;
	break;
	case 4:
		B=C=F=G=0;
 		A=D=E=DP=1;
	break;
	case 5:
		A=C=D=F=G=0;
 		B=E=DP=1;
	break;
	case 6:
		A=C=D=E=F=G=0;
 		B=DP=1;
	break;
	case 7:
		A=B=C=0;
   D=E=F=G=DP=1;	
	break;
	case 8:
		A=B=C=D=E=F=G=0;
 		DP=1;
	break;
	case 9:
		A=B=C=D=F=G=0;
 		E=DP=1;
	break;

	case 10: //A
		A=B=C=E=F=G=0;
 		D=DP=1;
	break;
	case 11: //B
		A=B=C=D=E=F=G=0;
 		DP=1;
	break;
	case 12:  //C
		A=D=E=F=0;
 		B=C=G=DP=1;
	break;
	case 13: //D
		A=B=C=D=E=F=0;
 		G=DP=1;
	break;	
	case 14: //E
		A=D=E=G=F=0;
 		B=C=DP=1;
	break;
	case 15: //F
		A=E=F=G=0;
 		B=C=D=DP=1;
	break;	
	
	}

}
//void SMG_Bit(uint8_t pos)
//{
//      switch(pos)		
//		 { 
//				case 1:                                         
//		GPIO_WriteBit(GPIOB,GPIO_Pin_12,(BitAction)1);
//		GPIO_WriteBit(GPIOB,GPIO_Pin_13,(BitAction)0);
//		GPIO_WriteBit(GPIOB,GPIO_Pin_14,(BitAction)0);
//		GPIO_WriteBit(GPIOB,GPIO_Pin_15,(BitAction)0);

//			 break;
//			case 2:                                         
//		GPIO_WriteBit(GPIOB,GPIO_Pin_12,(BitAction)0);
//		GPIO_WriteBit(GPIOB,GPIO_Pin_13,(BitAction)1);
//		GPIO_WriteBit(GPIOB,GPIO_Pin_14,(BitAction)0);
//		GPIO_WriteBit(GPIOB,GPIO_Pin_15,(BitAction)0);

//			 break;
//			case 3:                                         
//		GPIO_WriteBit(GPIOB,GPIO_Pin_12,(BitAction)0);
//		GPIO_WriteBit(GPIOB,GPIO_Pin_13,(BitAction)0);
//		GPIO_WriteBit(GPIOB,GPIO_Pin_14,(BitAction)1);
//		GPIO_WriteBit(GPIOB,GPIO_Pin_15,(BitAction)0);

//			 break;
//			case 4:                                         
//		GPIO_WriteBit(GPIOB,GPIO_Pin_12,(BitAction)0);
//		GPIO_WriteBit(GPIOB,GPIO_Pin_13,(BitAction)0);
//		GPIO_WriteBit(GPIOB,GPIO_Pin_14,(BitAction)0);
//		GPIO_WriteBit(GPIOB,GPIO_Pin_15,(BitAction)1);

//			 break;				
//			case 5:                                         //打开全部数码管 
//		GPIO_WriteBit(GPIOB,GPIO_Pin_12,(BitAction)1);
//		GPIO_WriteBit(GPIOB,GPIO_Pin_13,(BitAction)1);
//		GPIO_WriteBit(GPIOB,GPIO_Pin_14,(BitAction)1);
//		GPIO_WriteBit(GPIOB,GPIO_Pin_15,(BitAction)1);

//			 break;			 
//			case 6:                                         // 关闭全部数码管
//		GPIO_WriteBit(GPIOB,GPIO_Pin_12,(BitAction)0);
//		GPIO_WriteBit(GPIOB,GPIO_Pin_13,(BitAction)0);
//		GPIO_WriteBit(GPIOB,GPIO_Pin_14,(BitAction)0);
//		GPIO_WriteBit(GPIOB,GPIO_Pin_15,(BitAction)0);

//			 break;	 
//	 }


//}
//void SMG_Dat(uint8_t dat)
//{  switch(dat)
//	{ case 0:
//		GPIO_WriteBit(GPIOA,GPIO_Pin_2,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_3,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_4,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_5,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_6,(BitAction)0);
//    GPIO_WriteBit(GPIOA,GPIO_Pin_7,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_11,(BitAction)1);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_12,(BitAction)1);

//   break;		
//	 case 1:       
//		GPIO_WriteBit(GPIOA,GPIO_Pin_2,(BitAction)1);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_3,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_4,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_5,(BitAction)1);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_6,(BitAction)1);
//    GPIO_WriteBit(GPIOA,GPIO_Pin_7,(BitAction)1);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_11,(BitAction)1);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_12,(BitAction)1);
//   break;	
//   case 2:       
//	 	GPIO_WriteBit(GPIOA,GPIO_Pin_2,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_3,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_4,(BitAction)1);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_5,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_6,(BitAction)0);
//    GPIO_WriteBit(GPIOA,GPIO_Pin_7,(BitAction)1);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_11,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_12,(BitAction)1);
//   break;	
//   case 3:       
//		GPIO_WriteBit(GPIOA,GPIO_Pin_2,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_3,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_4,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_5,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_6,(BitAction)1);
//    GPIO_WriteBit(GPIOA,GPIO_Pin_7,(BitAction)1);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_11 ,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_12 ,(BitAction)1);
//   break;	
//   case 4:       
//		GPIO_WriteBit(GPIOA,GPIO_Pin_2,(BitAction)1);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_3,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_4,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_5,(BitAction)1);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_6,(BitAction)1);
//    GPIO_WriteBit(GPIOA,GPIO_Pin_7,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_11,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_12,(BitAction)1);
//   break;	
//   case 5:       
//		GPIO_WriteBit(GPIOA,GPIO_Pin_2,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_3,(BitAction)1);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_4,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_5,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_6,(BitAction)1);
//    GPIO_WriteBit(GPIOA,GPIO_Pin_7,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_11,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_12,(BitAction)1);
//   break;	
//   case 6:       
//		GPIO_WriteBit(GPIOA,GPIO_Pin_2,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_3,(BitAction)1);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_4,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_5,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_6,(BitAction)0);
//    GPIO_WriteBit(GPIOA,GPIO_Pin_7,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_11,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_12,(BitAction)1);
//   break;	
//   case 7:       
//		GPIO_WriteBit(GPIOA,GPIO_Pin_2,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_3,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_4,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_5,(BitAction)1);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_6,(BitAction)1);
//    GPIO_WriteBit(GPIOA,GPIO_Pin_7,(BitAction)1);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_11,(BitAction)1);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_12,(BitAction)1);
//   break;	
//   case 8:       
//		GPIO_WriteBit(GPIOA,GPIO_Pin_2,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_3,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_4,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_5,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_6,(BitAction)0);
//    GPIO_WriteBit(GPIOA,GPIO_Pin_7,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_11,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_12,(BitAction)1);
//   break;	
//   case 9:       
//		GPIO_WriteBit(GPIOA,GPIO_Pin_2,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_3,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_4,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_5,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_6,(BitAction)1);
//    GPIO_WriteBit(GPIOA,GPIO_Pin_7,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_11,(BitAction)0);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_12,(BitAction)1);
//   break;	
//	  case 10:
//		GPIO_WriteBit(GPIOA,GPIO_Pin_2, (BitAction)1);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_3, (BitAction)1);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_4, (BitAction)1);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_5, (BitAction)1);
//	 	GPIO_WriteBit(GPIOA,GPIO_Pin_6, (BitAction)1);
//    GPIO_WriteBit(GPIOA,GPIO_Pin_7, (BitAction)1);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_11,(BitAction)1);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_12,(BitAction)1);
//   break;	

//	
//	}
//	


//}

void SMG_Run(uint16_t pos,uint16_t value)
{
  SMG_Pos(pos);
	SMG_Data(value);


}

void SMG_Display(void)
{
   uint8_t i,j;
	for(i=1;i<=4;i++)
 { for(j=0;j<16;j++)
	 {
	     SMG_Run(i,j);
	      Delay_ms(500); 
	 
	 }

 
 }
 for(j=0;j<16;j++)
 {
   	SMG_Run(5,j);
	  Delay_ms(1000);
 
 
 }


}

