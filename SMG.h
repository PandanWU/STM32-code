#ifndef __SMG_H
#define __SMG_H

void Init_SMG(void);
void SMG_Pos(uint16_t channal);
void SMG_Data(uint16_t channal);
void SMG_Bit(uint8_t pos);
void SMG_Dat(uint8_t dat);

void SMG_Run(uint16_t pos,uint16_t value);
void SMG_Display(void);


#endif
