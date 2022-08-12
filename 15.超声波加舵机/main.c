#include "reg52.h"

sbit Trig = P2^2;
sbit Echo = P2^3;
sbit PWM = P2^4;
sbit LED1 = P3^7;

unsigned char jd;
unsigned char cnt = 0;

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

void Delay300ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	i = 3;
	j = 26;
	k = 223;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}



void StartTrig(){
	Trig = 0;
	Trig = 1;
	Delay10us();
	Trig = 0;
}

double Get_Dis(){
	double Time;
	StartTrig();
	while(!Echo);
	Timer1_ON();
	while(Echo);
	Timer1_OFF();
	Time = 1.085 * (TH1 * 256 + TL1);
	return (0.017 * Time);
}




int main(){
	double Dis;
	Delay300ms();
	Timer1();
	Timer0();
	while(1){
		Dis = Get_Dis();
		if(Dis < 20){
			jd = 5;
			cnt = 0;
			Delay300ms();
			Delay300ms();
			Delay300ms();
		}
		else{
			jd = 1;
			cnt = 0;
			Delay300ms();
		}
	}
}


void Timer0Handle() interrupt 1{
	cnt++;
	if(cnt == jd){
		PWM = 0;
	}
	if(cnt == 40){
		PWM = 1;
		cnt = 0;
	}
	TH0 = 0xFE;
	TL0 = 0x33;
}
