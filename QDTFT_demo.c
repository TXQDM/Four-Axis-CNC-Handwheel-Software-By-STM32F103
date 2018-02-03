/* --------------------------Includes ---------------------------------------------*/
//#include "stm32f10x.h"
#include <stm32f10x_map.h>
#include "Lcd_Driver.h"
#include "GUI.h"
#include "delay.h"
#include "Picture.h"
#include "QDTFT_demo.h"
#include "user.h"
/* ----------------------End of Includes ---------------------------------------------*/

unsigned char Num[10]={0,1,2,3,4,5,6,7,8,9};
//���Ʋ��Բ˵�
//2D������ťʾ��
void Redraw_Mainmenu(void)
{

	Lcd_Clear(GRAY0);
	
	Gui_DrawFont_GBK16(16,2,BLUE,GRAY0,"ȫ�����Ӽ���");
	Gui_DrawFont_GBK16(16,20,RED,GRAY0,"Һ�����Գ���");

	DisplayButtonUp(15,38,113,58); //x1,y1,x2,y2
	Gui_DrawFont_GBK16(16,40,YELLOW,GRAY0,"��ɫ������");

	DisplayButtonUp(15,68,113,88); //x1,y1,x2,y2
	Gui_DrawFont_GBK16(16,70,BLUE,GRAY0,"������ʾ����");

	DisplayButtonUp(15,98,113,118); //x1,y1,x2,y2
	Gui_DrawFont_GBK16(16,100,RED,GRAY0,"ͼƬ��ʾ����");


	//Gui_DrawFont_GBK16(16,120,BLUE,GRAY0,"Welcome");
	Gui_DrawFont_GBK16(16,140,RED,GRAY0, "Welcome");
	
	Gui_DrawFont_Num32(100,125,RED,GRAY0,Num[5]);
	delay_ms(1000);
	Gui_DrawFont_Num32(100,125,RED,GRAY0,Num[4]);
	delay_ms(1000);
	Gui_DrawFont_Num32(100,125,RED,GRAY0,Num[3]);
	delay_ms(1000);
	Gui_DrawFont_Num32(100,125,RED,GRAY0,Num[2]);
	delay_ms(1000);
	Gui_DrawFont_Num32(100,125,RED,GRAY0,Num[1]);
	delay_ms(1000);
	Gui_DrawFont_Num32(100,125,RED,GRAY0,Num[0]);	
}
//�������������
void Num_Test(void)
{
	u8 i=0;
	Lcd_Clear(GRAY0);
	Gui_DrawFont_GBK16(16,20,RED,GRAY0,"Num Test");
	delay_ms(1000);
	Lcd_Clear(GRAY0);

	for(i=0;i<10;i++)
	{
		Gui_DrawFont_Num32((i%3)*40,32*(i/3)+30,RED,GRAY0,Num[i]);
		delay_ms(100);
	}
	
}
//��Ӣ����ʾ����
void Font_Test(void)
{
	Lcd_Clear(GRAY0);
	Gui_DrawFont_GBK16(16,10,BLUE,GRAY0,"������ʾ����");

	delay_ms(1000);
	Lcd_Clear(GRAY0);
	Gui_DrawFont_GBK16(16,30,RED,GRAY0,"ȫ�����Ӽ���");
	Gui_DrawFont_GBK16(16,50,BLUE,GRAY0,"רעҺ������");
	Gui_DrawFont_GBK16(16,70,RED,GRAY0, "ȫ�̼���֧��");
	Gui_DrawFont_GBK16(0,100,BLUE,GRAY0,"Tel:15989313508");
	Gui_DrawFont_GBK16(0,130,RED,GRAY0, "www.qdtech.net");	
	delay_ms(1000);	
}
//��ˢ������
void Color_Test(void)
{
	u8 i=1;
	Lcd_Clear(GRAY0);
	
	Gui_DrawFont_GBK16(20,10,BLUE,GRAY0,"��ɫ������");
	delay_ms(1000);

	while(i--)
	{
		Lcd_Clear(WHITE);
		Lcd_Clear(BLACK);
		Lcd_Clear(RED);
	  Lcd_Clear(GREEN);
	  Lcd_Clear(BLUE);
	}		
}

//������ʾ����
//16λBMP 40X40 QQͼ��ȡģ����
//Image2LCDȡģѡ������
//ˮƽɨ��
//16λ
//40X40
//������ͼ��ͷ����
//��������
//�Զ�����
//��λ��ǰ
void showimage(const unsigned char *p) //��ʾ40*40 QQͼƬ
{
  int i,j,k; 
	unsigned char picH,picL; 
	Lcd_Clear(GRAY0);
	Gui_DrawFont_GBK16(16,10,BLUE,GRAY0,"ͼƬ��ʾ����");
	delay_ms(1000);

	Lcd_Clear(GRAY0);
	for(k=0;k<5;k++)
	{
	  for(j=0;j<4;j++)
		{	
			Lcd_SetRegion(40*j,40*k,40*j+39,40*k+39);		//��������
		    for(i=0;i<40*40;i++)
			 {	
			 	picL=*(p+i*2);	//���ݵ�λ��ǰ
				picH=*(p+i*2+1);				
				Lcd_WriteData_16Bit(picH<<8|picL);  						
			 }	
		 }
	}		
}
//�ۺϲ��Ժ���
void QDTFT_Test_Demo(void)
{
//	LCD_Init();
	LCD_LED_SET;//ͨ��IO���Ʊ�����				
	Redraw_Mainmenu();//�������˵�(�����������ڷֱ��ʳ�������ֵ�����޷���ʾ)
	Color_Test();//�򵥴�ɫ������
	Num_Test();//������������
	Font_Test();//��Ӣ����ʾ����		
	showimage(gImage_qq);//ͼƬ��ʾʾ��
//	delay_ms(1200);
	LCD_LED_CLR;//IO���Ʊ�����	
}

void LCD_ADC_Init(void)
{
	Lcd_Clear(GRAY0);
	Gui_DrawFont_GBK16(40,10,BLUE,GRAY0,"ADC ��ʾ����");
	Gui_DrawFont_GBK16(16,40,BLUE,GRAY0,"ADC1");
	Gui_DrawFont_GBK16(16,72,BLUE,GRAY0,"ADC2");
	Gui_DrawFont_GBK16(16,104,BLUE,GRAY0,"ADC3");
	Gui_DrawFont_GBK16(16,136,BLUE,GRAY0,"ADC4");
	Gui_DrawFont_GBK16(10,170,BLUE,GRAY0,"KEY1");
	Gui_DrawFont_GBK16(90,170,BLUE,GRAY0,"KEY2");
	Gui_DrawFont_GBK16(10,190,BLUE,GRAY0,"KEY3");
	Gui_DrawFont_GBK16(90,190,BLUE,GRAY0,"KEY4");
}

void LCD_KEY_GBK16(void)
{	
	u8 i,j,temp[5];
	
	for(i=0;i<4;i++)
	{
		temp[0] = KEY_Count[i] / 10000;
		temp[1] = (KEY_Count[i] % 10000) / 1000;		
		temp[2] = ((KEY_Count[i] % 10000) % 1000) / 100;
		temp[3] = (((KEY_Count[i] % 10000) % 1000) % 100) / 10;
		temp[4] = (((KEY_Count[i] % 10000) % 1000) % 100) % 10;
		
		for(j=0;j<5;j++)
		{
			switch(temp[j])
			{
				case 0:Gui_DrawFont_GBK16((i%2)*80+j*8+44,(i/2)*20+170,RED,GRAY1,"0");
					break;
				case 1:Gui_DrawFont_GBK16((i%2)*80+j*8+44,(i/2)*20+170,RED,GRAY1,"1");
					break;
				case 2:Gui_DrawFont_GBK16((i%2)*80+j*8+44,(i/2)*20+170,RED,GRAY1,"2");
					break;
				case 3:Gui_DrawFont_GBK16((i%2)*80+j*8+44,(i/2)*20+170,RED,GRAY1,"3");
					break;
				case 4:Gui_DrawFont_GBK16((i%2)*80+j*8+44,(i/2)*20+170,RED,GRAY1,"4");
					break;
				case 5:Gui_DrawFont_GBK16((i%2)*80+j*8+44,(i/2)*20+170,RED,GRAY1,"5");
					break;
				case 6:Gui_DrawFont_GBK16((i%2)*80+j*8+44,(i/2)*20+170,RED,GRAY1,"6");
					break;
				case 7:Gui_DrawFont_GBK16((i%2)*80+j*8+44,(i/2)*20+170,RED,GRAY1,"7");
					break;
				case 8:Gui_DrawFont_GBK16((i%2)*80+j*8+44,(i/2)*20+170,RED,GRAY1,"8");
					break;
				case 9:Gui_DrawFont_GBK16((i%2)*80+j*8+44,(i/2)*20+170,RED,GRAY1,"9");
					break;
				default:
					break;
			}	
		}
	}
}

void LCD_ADC_Test(void)
{	
	u8 i,temp1,temp2,temp3,temp4;
	
	for(i=0;i<4;i++)
	{
		/*ʮ����ģʽ*/
		temp1 = ADC_Data[i] / 1000;
		temp2 = (ADC_Data[i] % 1000) / 100;		
		temp3 = ((ADC_Data[i] % 1000) % 100) / 10;
		temp4 = ((ADC_Data[i] % 1000) % 100) % 10;

		Gui_DrawFont_Num32(0*26+50,32*i+30,RED,GRAY1,Num[temp1]);
		Gui_DrawFont_Num32(1*26+50,32*i+30,RED,GRAY1,Num[temp2]);
		Gui_DrawFont_Num32(2*26+50,32*i+30,RED,GRAY1,Num[temp3]);
		Gui_DrawFont_Num32(3*26+50,32*i+30,RED,GRAY1,Num[temp4]);

		/*ʮ������ģʽ*/
/*		temp1 = ADC_Data[i] / 0xFFF;
		temp2 = (ADC_Data[i] % 0xFFF) / 0xFF;		
		temp3 = ((ADC_Data[i] % 0xFFF) % 0xFF) / 0xF;
		temp4 = ((ADC_Data[i] % 0xFFF) % 0xFF) % 0xF;

		Gui_DrawFont_Num32(0*26+50,32*i+30,RED,GRAY1,Num[temp1]);
		Gui_DrawFont_Num32(1*26+50,32*i+30,RED,GRAY1,Num[temp2]);
		Gui_DrawFont_Num32(2*26+50,32*i+30,RED,GRAY1,Num[temp3]);
		Gui_DrawFont_Num32(3*26+50,32*i+30,RED,GRAY1,Num[temp4]);
*/
	}
}


