#include "sys.h"
#ifndef __Alone_KEY_H
#define __Alone_KEY_H

#define K1 PAin(0)
#define K2 PCin(13)

#define KEY2 PCin(2)
#define KEY3 PCin(3)
#define KEY4 PCin(4)
#define KEY5 PCin(5)
#define Red_LED    PBout(5)   //ºì
#define Green_LED  PBout(0)   //ÂÌ
#define Blue_LED   PBout(1)   //À¶

void Init_KEY(void);
void Init_Alone_KEY(void);
void LED_config(void);
void KEY_Scan(void);
void KEY_Scan1(void);
void KEY_Scan2(void);
uint8_t KEY_Scan3(void);
#endif
