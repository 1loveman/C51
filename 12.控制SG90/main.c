#include "reg52.h"

sbit PWM = P2^4;
unsigned char cnt = 0;
unsigned char jd;

void Delay2000ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	i = 15;
	j = 2;
	k = 235;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


void Timer(){
	TMOD &= 0xF0;
	TMOD |= 0x01;
	TL0 = 0x33;
	TH0 = 0xFE;
	TF0 = 0;
	TR0 = 1;
	EA = 1;
	ET0 = 1;
}

int main(){
	//转动180度再返回原位；
	Timer();
	PWM = 1;
	jd = 1;
	while(1){
		jd = 5;
		cnt = 0; 
		Delay2000ms();
		jd = 1;
		cnt = 0;
		Delay2000ms();
	}
}

void Timer0Handle() interrupt 1{
	cnt++;
	TL0 = 0x33;
	TH0 = 0xFE;
	if(cnt == jd){
		PWM = 0;
	}
	if(cnt == 40){
		PWM = 1;
		cnt = 0;
	}
}
