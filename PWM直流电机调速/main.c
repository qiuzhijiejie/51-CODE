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
	
	TL0 = 0x9C;				//���ö�ʱ��ʼֵ
	TH0 = 0xFF;				//���ö�ʱ��ʼֵ
	counter++;
	counter%=100;			//0-100�ļ�����
	if(counter<compare)     //������<�Ƚ�ֵ
	{
		motor=1;
	}	
	else
	{
		motor=0;
	}
		
}