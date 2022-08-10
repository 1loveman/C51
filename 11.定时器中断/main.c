#include "reg52.h"

void Timer1(){
	TMOD &= 0x0F;
	TMOD |= 0x10;
	TH1 = 0xDC;
	TL1 = 0x00;
	TF1 = 0;
	TR1 = 1;
	ET1 = 1;
	EA = 1;
}

sbit LED1 = P3^7;
unsigned char cnt = 0;


int main(){
	LED1 = 1;
	Timer1();
	while(1){
		;
	}
}

void Timer1Handle() interrupt 3
{
	cnt++;
	TH1 = 0xDC;
	TL1 = 0x00;
	if(cnt == 100){
		LED1 = !LED1;
		cnt = 0;
	}
}