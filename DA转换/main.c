#include <REGX52.H>
#include "TIMER0.h"
#include "delay.h"


sbit DA=P2^1;


unsigned char counter ,compare,i;

void main()
{

	Timer0Init();
	compare=5;
	while(1)
	{

		for(i=0;i<100;i++)
		{
			compare=i;
			Delay(10);
		}
		
		for(i=100;i>0;i--)
		{
			compare=i;
			Delay(10);
		}
	}
	
}
	

void Timer0_Routine() interrupt 1
{
	
	TL0 = 0x9C;				//设置定时初始值
	TH0 = 0xFF;				//设置定时初始值
	counter++;
	counter%=100;			//0-100的计数器
	if(counter<compare)     //计数器<比较值
	{
		DA=1;
	}	
	else
	{
		DA=0;
	}
		
}