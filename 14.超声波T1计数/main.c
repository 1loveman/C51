#include "reg52.h"

sbit Trig = P2^2;
sbit Echo = P2^3;
sbit LED1 = P3^7;
double Time,Dis;

void Timer1(){
	TMOD &= 0x0F;
	TMOD |= 0x10;
}

void Timer1_ON(){
	TH1 = 0x00;
	TL1 = 0x00;
	TR1 = 1;
}

void Timer1_OFF(){
	TR1 = 0;
}

void Delay10us()		//@11.0592MHz
{
	unsigned char i;
	i = 2;
	while (--i);
}


void StartTrig(){
	Trig = 0;
	Trig = 1;
	Delay10us();
	Trig = 0;
}

int main(){
	Timer1();
	LED1 = 1;
	while(1){
		StartTrig();
		while(!Echo);
		Timer1_ON();
		while(Echo);
		Timer1_OFF();
		Time = 1.085 * (TH1 * 256 + TL1);
		Dis = 0.017 * Time;
		if(Dis < 10){
			LED1 = 0;
		}
		else{
			LED1 = 1;
		}
	}
}