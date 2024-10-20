#include <REGX52.H>

sbit XPT2026_CS=P3^5;
sbit XPT2026_DCLK=P3^6;
sbit XPT2026_DIN=P3^4;
sbit XPT2026_DOUT=P3^7;


unsigned int XPT2026_readAD(unsigned char command)
{
	
	unsigned char i;
	unsigned int ADvalue=0;
	XPT2026_DCLK=0;
	XPT2026_CS=0;
	for(i=0;i<8;i++)
	{
		XPT2026_DIN=command&(0x80>>i);
		XPT2026_DCLK=1;
		XPT2026_DCLK=0;
	}
	for(i=0;i<16;i++)
	{
		XPT2026_DCLK=1;
		XPT2026_DCLK=0;
		if(XPT2026_DOUT){ADvalue|=(0x8000>>i);}
	}
	XPT2026_CS=1;
	if(command&0x08)
	{
		return ADvalue>>8;//8λ
	}
	else
	{
		return ADvalue>>4;//12λ
	}
	
}	