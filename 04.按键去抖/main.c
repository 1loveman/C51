#include "reg52.h"

sbit LED1 = P3^7;
sbit LED2 = P3^6;
sbit KEY1 = P2^1;
sbit KEY2 = P2^0;
void Delay50ms()		//@11.0592MHz
{
	unsigned char i, j;

	i = 90;
	j = 163;
	do
	{
		while (--j);
	} while (--i);
}


int main(){
	//实现按键按下LED亮，按键松开LED灭。
	unsigned char KeyDate1;
	unsigned char KeyDate2;
	

	while(1){
		LED1 = 1;
		LED2 = 1;
		if(!(KeyDate1=KEY1)){
			Delay50ms();
			if(!(KeyDate1=KEY1)){
				LED1 = 0;
				while(!(KeyDate1=KEY1));
			}
		}
		if(!(KeyDate2=KEY2)){
			if(!(KeyDate2=KEY2)){
				LED2 = 0;
				while(!(KeyDate2=KEY2));
			}
		}
	}
}