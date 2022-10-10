#ifndef __OLED_H
#define __OLED_H

void OLED_Init(void);//��ʼ������OLED
void OLED_Clear(void);//���OLED����

/*
�����Ҫ�ֲ�������ݣ��������ַ�������
OLED_ShowString(uint8_t Line, uint8_t Column, "�ո���");




*/

//OLED��ʾ�ַ��ĺ���   ������1���У�����2���У�����3���ַ����ݣ�
void OLED_ShowChar(uint8_t Line, uint8_t Column, char Char);

//OLED��ʾ�ַ����ĺ���   ������1���У�����2���У�����3���ַ������ݣ�
void OLED_ShowString(uint8_t Line, uint8_t Column, char *String);

//OLED��ʾ���ֵĺ���   ������1���У�����2���У�����3���������ݣ�����4�����ֳ��ȣ�
void OLED_ShowNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);

//OLED��ʾ�з������ֵĺ���   ������1���У�����2���У�����3���з����������ݣ�����4�����ֳ��ȣ�
void OLED_ShowSignedNum(uint8_t Line, uint8_t Column, int32_t Number, uint8_t Length);

//OLED��ʾ16�������ĺ���   ������1���У�����2���У�����3��16�����������ݣ�����4�����ֳ��ȣ�
void OLED_ShowHexNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);

//OLED��ʾ���������ĺ���   ������1���У�����2���У�����3���������������ݣ�����4�����ֳ��ȣ�
void OLED_ShowBinNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);


#endif
