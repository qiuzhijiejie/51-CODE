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
	
	TL0 = 0x9C;				//���ö�ʱ��ʼֵ
	TH0 = 0xFF;				//���ö�ʱ��ʼֵ
	counter++;
	counter%=100;			//0-100�ļ�����
	if(counter<compare)     //������<�Ƚ�ֵ
	{
		DA=1;
	}	
	else
	{
		DA=0;
	}
		
}