#include <REGX52.H>
#include "timer0.h"
#include "delay.h"
#include "key.h"
#include "livesmg.h"
#include "i2c.h"
#include "AT24C02.h"



unsigned char keynums;
extern unsigned char min,sec,minsec;
unsigned char runflag;
void main()
{
	Timer0Init();
	while(1)
	{
		keynums=key();
		if(keynums==1)
		{
			runflag=!runflag;
		}
		if(keynums==2)
		{
			min=0;
			sec=0;
			minsec=0;
		}
		if(keynums==3)
		{
			AT24C02_writebyte(0,min);
			Delay(5);
			AT24C02_writebyte(1,sec);
			Delay(5);
			AT24C02_writebyte(2,minsec);
			Delay(5);
		}
		if(keynums==4)
		{
			min=AT24C02_receiveByte(0);
			sec=AT24C02_receiveByte(1);
			minsec=AT24C02_receiveByte(2);
			
		}
		smg(1,min/10);
	    smg(2,min%10);
		smg(3,11);
		smg(4,sec/10);
	    smg(5,sec%10);
		smg(6,11);
		smg(7,minsec/10);
	    smg(8,minsec%10);
			
	}
}

void sec_loop(void)
{
	if(runflag)
	{	
	minsec++;
	if(minsec>= 100)
	{
		minsec=0;
		sec++;
		if(sec>= 60)
		{
			sec=0;
			min++;
			if(min>= 60)
			{
				min= 0;
			}
				
		}
		
		
	}
	
}
	
	
}



void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count,T0Count1,T0Count2;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0Count++;
	if(T0Count>=20)
	{
		T0Count=0;
		key_lop();
		
	}
	
	T0Count1++;
	if(T0Count1>=2)
	{
		T0Count1=0;
		livesmg_lop();
		
	}
	
	T0Count2++;
	if(T0Count2>=10)
	{
		T0Count2=0;
		sec_loop();
		
	}
}