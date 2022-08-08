#include "reg52.h"

sbit LED1 = P3^7;
sbit LED2 = P3^6;
sbit VbrationS = P2^7;
void Delay1000ms()		//@11.0592MHz
{
	unsigned char i, j, k;
	i = 8;
	j = 1;
	k = 243;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}



int main(){
	//震动一次，灯的状态变化一次。
	unsigned char VSDate;
	LED1 = 1;
	while(1){
		if(!(VSDate=VbrationS)){
			LED1 = !LED1;
			Delay1000ms();
		}
	}
}