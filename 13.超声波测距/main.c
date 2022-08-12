#include "reg52.h"

sbit Trig = P2^2;
sbit Echo = P2^3;
sbit LED1 = P3^7;
double Time;
double Distance;

void Delay11us()		//@11.0592MHz
{
	unsigned char i;
	i = 2;
	while (--i);
}

void StartTrig(){
	Trig = 0;
	Trig = 1;
	Delay11us();
	Trig = 0;
}

void Timer0(){
	TMOD &= 0xF0;
	TMOD |= 0x01;
	TH0 = 0;
	TL0 = 1;
}

int main(){
	Timer0();
	while(1){
		//给Trig至少10us的高电平
		StartTrig();
		//Echo从低到高，启动定时器
		while(!Echo);
		TF0 = 0;
		TR0 = 1;
		//Eecho从高到低，停止定时器。
		while(Echo);
		TR0 = 0;
		//计算时间
		Time = (TH0 * 256 + TL0)*1.085;
		//计算距离
		Distance = 0.017 * Time;//注意单位;
		if(Distance <10){
			LED1 = 0;
		}
		else{
			LED1 = 1;
		}
		TH0 = 0;
		TL0 = 1;
	}
}