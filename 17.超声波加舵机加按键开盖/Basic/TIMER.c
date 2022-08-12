#include "TIMER.h"


void Timer0(){
	TMOD &= 0xF0;
	TMOD |= 0x01;
	TH0 = 0xFE;
	TL0 = 0x33;
	TF0 = 0;
	TR0 = 1;
	EA = 1;
	ET0 = 1;
}

void Timer1(){
	TMOD &= 0x0F;
	TMOD |= 0x10;
}

void Timer1_ON(){
	TH1 = 0;
	TL1 = 0;
	TR1 = 1;
}

void Timer1_OFF(){
	TR1 = 0;
}

