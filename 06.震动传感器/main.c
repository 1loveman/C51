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
	//��һ�Σ��Ƶ�״̬�仯һ�Ρ�
	unsigned char VSDate;
	LED1 = 1;
	while(1){
		if(!(VSDate=VbrationS)){
			LED1 = !LED1;
			Delay1000ms();
		}
	}
}