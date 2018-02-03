
#include <stm32f10x_map.h>

#ifndef __QDTFT_DEMO_H
#define __QDTFT_DEMO_H 

extern unsigned char Num[];

extern void Redraw_Mainmenu(void);
extern void Num_Test(void);
extern void Font_Test(void);
extern void Color_Test(void);
extern void showimage(const unsigned char *p); 
extern void QDTFT_Test_Demo(void);
extern void LCD_ADC_Init(void);
extern void LCD_KEY_GBK16(void);
extern void LCD_ADC_Test(void);
#endif
