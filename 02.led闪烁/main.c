#include "reg52.h"

sbit LED1 = P3^7;
sbit LED2 = P3^6;
void Delay500ms()		//@11.0592MHz
{
	unsigned char i, j, k;
	i = 4;
	j = 129;
	k = 119;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


int main(){
	while(1){
		LED1 = 0;
		LED2 = 1;
		Delay500ms();
		LED1 = 1;
		LED2 = 0;
		Delay500ms();
	}
}