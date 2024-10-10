#include <REGX52.H>
#include "delay.h"


unsigned int nums[]={0x3f,0x06,0x5b,0x4f,
					 0x66,0x6d,0x7d,0x07,
					 0x7f,0x6f,0x00,0x40};

unsigned int smg_buf[9]={0,10,10,10,10,10,10,10};

void smg(unsigned char location, num )		
{
	smg_buf[location]=num;
}	


void livesmg(unsigned char location,num)//数码管
{
	P0=0x00;
	switch(location)//位选位置
	{
		case 1:P2_4=1;P2_3=1;P2_2=1;break;//Y7,LED8.morelihgt
		case 2:P2_4=1;P2_3=1;P2_2=0;break;//Y6
		case 3:P2_4=1;P2_3=0;P2_2=1;break;//Y5
		case 4:P2_4=1;P2_3=0;P2_2=0;break;//Y4
		case 5:P2_4=0;P2_3=1;P2_2=1;break;//Y3
		case 6:P2_4=0;P2_3=1;P2_2=0;break;//Y2
		case 7:P2_4=0;P2_3=0;P2_2=1;break;//Y1
		case 8:P2_4=0;P2_3=0;P2_2=0;break;//Y0
	}
	P0=nums[num];

}

void livesmg_lop(void)
{
	
	static unsigned char i=1;
	livesmg(i,smg_buf[i]);
	i++;
	if(i>=9){i=1;}
}










