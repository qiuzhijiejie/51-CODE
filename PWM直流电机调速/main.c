#include <REGX52.H>
#include "TIMER0.h"
#include "KEY.h"
#include "NIXIE.h"


sbit motor=P1^0;


unsigned char counter ,compare;
unsigned char keynum,speed;
void main()
{

	Timer0Init();
	compare=5;
	while(1)
	{
		keynum=Key();
		if(keynum==1)
		{	
			speed++;
			speed%=4;
			if(speed==0){compare=0;}
			if(speed==1){compare=30;}
			if(speed==2){compare=60;}
			if(speed==3){compare=100;}
		}
		Nixie(1,speed);
		
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
		motor=1;
	}	
	else
	{
		motor=0;
	}
		
}