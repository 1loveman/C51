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
	//io¿ÚµÄ·­×ª¡£
	unsigned char KeyDate1;
	unsigned char KeyDate2;
	LED1 = 1;
	LED2 = 1;

	while(1){
		if(!(KeyDate1=KEY1)){
			Delay50ms();
			if(!(KeyDate1=KEY1)){
				LED1 = !LED1;
				while(!(KeyDate1=KEY1));
			}
		}
		if(!(KeyDate2=KEY2)){
			if(!(KeyDate2=KEY2)){
				LED2 = !LED2;
				while(!(KeyDate2=KEY2));
			}
		}
	}
}