
#include <stm32f10x_map.h>

#ifndef _LCD_DRIVER_H_
#define _LCD_DRIVER_H_

//-----------------------------SPI ��������--------------------------------------//
#define USE_HARDWARE_SPI     0  //1:Enable Hardware SPI;0:USE Soft SPI

/////////////////////////////////////�û�������///////////////////////////////////	 
//֧�ֺ��������ٶ����л�
#define USE_HORIZONTAL  		0	//�����Ƿ�ʹ�ú��� 		0,��ʹ��.1,ʹ��.

//-------------------------��Ļ������������--------------------------------------//
#ifdef USE_HORIZONTAL			//��������˺��� 
#define LCD_X_SIZE	        176
#define LCD_Y_SIZE	        220
#define X_MAX_PIXEL	        LCD_X_SIZE
#define Y_MAX_PIXEL	        LCD_Y_SIZE
#else
#define LCD_X_SIZE	        176
#define LCD_Y_SIZE	        220
#define X_MAX_PIXEL	        LCD_X_SIZE
#define Y_MAX_PIXEL	        LCD_Y_SIZE
#endif

//////////////////////////////////////////////////////////////////////////////////
#define RED  	0xf800
#define GREEN	0x07e0
#define BLUE 	0x001f
#define WHITE	0xffff
#define BLACK	0x0000
#define YELLOW  0xFFE0
#define GRAY0   0xEF7D   	//��ɫ0 3165 00110 001011 00101
#define GRAY1   0x8410    //��ɫ1  00000 000000 00000
#define GRAY2   0x4208    //��ɫ2  11111 111110 11111



//�����Գ���ʹ�õ���ģ��SPI�ӿ�����
//�����ɸ��Ľӿ�IO���ã�ʹ����������4 IO������ɱ���Һ��������ʾ

//Һ�����ƿڲ������궨��
#define	LCD_CS_SET  	GPIOB->ODR |= 0x00001000	//PB12
#define	LCD_CS_CLR 		GPIOB->ODR &= ~0x00001000	
#define	LCD_RST_SET		GPIOB->ODR |= 0x00000020	//PB5
#define	LCD_RST_CLR		GPIOB->ODR &= ~0x00000020
#define	LCD_RS_SET  	GPIOB->ODR |= 0x00002000	//PB13
#define	LCD_RS_CLR		GPIOB->ODR &= ~0x00002000
#define	LCD_SDI_SET  	GPIOB->ODR |= 0x00004000	//PB14
#define	LCD_SDI_CLR  	GPIOB->ODR &= ~0x00004000	
#define	LCD_CLK_SET  	GPIOB->ODR |= 0x00008000	//PB15
#define	LCD_CLK_CLR  	GPIOB->ODR &= ~0x00008000
#define	LCD_LED_SET  	
#define	LCD_LED_CLR  	


#define LCD_DATAOUT(x) LCD_DATA->ODR=x; //�������
#define LCD_DATAIN     LCD_DATA->IDR;   //��������

#define LCD_WR_DATA(data){\
LCD_RS_SET;\
LCD_CS_CLR;\
LCD_DATAOUT(data);\
LCD_WR_CLR;\
LCD_WR_SET;\
LCD_CS_SET;\
} 



extern void LCD_GPIO_Init(void);
extern void Lcd_WriteIndex(u8 Index);
extern void Lcd_WriteData(u8 Data);
extern void Lcd_WriteReg(u8 Index,u8 Data);
extern u16 	Lcd_ReadReg(u8 LCD_Reg);
extern void Lcd_Reset(void);
extern void LCD_Init(void);
extern void Lcd_Clear(u16 Color);
extern void Lcd_SetXY(u16 x,u16 y);
extern void Gui_DrawPoint(u16 x,u16 y,u16 Data);
extern unsigned int Lcd_ReadPoint(u16 x,u16 y);
extern void Lcd_SetRegion(u8 x_start,u8 y_start,u8 x_end,u8 y_end);
extern void Lcd_WriteData_16Bit(u16 Data);

#endif
