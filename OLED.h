#ifndef __OLED_H
#define __OLED_H

void OLED_Init(void);//初始化配置OLED
void OLED_Clear(void);//清除OLED数据

/*
如果想要局部清除数据，可以用字符串函数
OLED_ShowString(uint8_t Line, uint8_t Column, "空格数");




*/

//OLED显示字符的函数   （参数1：行；参数2：列；参数3：字符数据）
void OLED_ShowChar(uint8_t Line, uint8_t Column, char Char);

//OLED显示字符串的函数   （参数1：行；参数2：列；参数3：字符串内容）
void OLED_ShowString(uint8_t Line, uint8_t Column, char *String);

//OLED显示数字的函数   （参数1：行；参数2：列；参数3：数字内容；参数4：数字长度）
void OLED_ShowNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);

//OLED显示有符号数字的函数   （参数1：行；参数2：列；参数3：有符号数字内容；参数4：数字长度）
void OLED_ShowSignedNum(uint8_t Line, uint8_t Column, int32_t Number, uint8_t Length);

//OLED显示16进制数的函数   （参数1：行；参数2：列；参数3：16进制数字内容；参数4：数字长度）
void OLED_ShowHexNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);

//OLED显示二进制数的函数   （参数1：行；参数2：列；参数3：二进制数字内容；参数4：数字长度）
void OLED_ShowBinNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);


#endif
