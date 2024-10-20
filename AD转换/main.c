#include <REGX52.H>
#include "lcd1602.h"
#include "delay.h"
#include "XPT2026.h"

unsigned int ADC;

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"ADJ NTC RG");
	while(1)
	{
	    ADC=XPT2026_readAD(XPT2026_XP_8);
		LCD_ShowNum(2,1,ADC,3);
		ADC=XPT2026_readAD(XPT2026_YP_8);
		LCD_ShowNum(2,5,ADC,3);
		ADC=XPT2026_readAD(XPT2026_VBAT_8);
		LCD_ShowNum(2,9,ADC,3);
		Delay(10);
	}
}