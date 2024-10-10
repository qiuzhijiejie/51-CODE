#include <REGX52.H>
#include "delay.h"

unsigned char keynum;


unsigned char key()
{
	unsigned char temp;
	temp=keynum;
	keynum=0;
	return temp;
}


unsigned char key_gatstate() // 获取独立按键码
{
    unsigned char keynum = 0;

    if (P3_1 == 0) {  keynum = 1; }
    
    if (P3_0 == 0) {  keynum = 2; }
    
    if (P3_2 == 0) {  keynum = 3; }
    
    if (P3_3 == 0) {  keynum = 4; }

    return keynum;
}




void key_lop()
{
	static unsigned char last,now;
	last=now;
	now=key_gatstate();
	if(last==1 && now==0)//按键处于松手
	{
		keynum=1;
	}
	
	if(last==2 && now==0)
	{
		keynum=2;
	}
	
	if(last==3 && now==0)
	{
		keynum=3;
	}
	
	
	if(last==4 && now==0)
	{
		keynum=4;
	}

}	