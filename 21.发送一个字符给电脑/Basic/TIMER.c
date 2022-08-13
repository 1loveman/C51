#include "TIMER.h"

unsigned char cnt = 0;
unsigned char T0_Flag = 0;

void Timer0(){
	TMOD &= 0xF0;
	TMOD |= 0x01;
	TH0 = 0xDC;
	TL0 = 0x00;
	TF0 = 0;
	TR0 = 1;
	EA = 1;
	ET0 = 1;
}

void Timer0Handler() interrupt 1{
	cnt++;
	if(cnt == 100){
		T0_Flag = 1;
		cnt = 0;
	}
	TH0 = 0xDC;
	TL0 = 0x00;
}