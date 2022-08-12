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
		//��Trig����10us�ĸߵ�ƽ
		StartTrig();
		//Echo�ӵ͵��ߣ�������ʱ��
		while(!Echo);
		TF0 = 0;
		TR0 = 1;
		//Eecho�Ӹߵ��ͣ�ֹͣ��ʱ����
		while(Echo);
		TR0 = 0;
		//����ʱ��
		Time = (TH0 * 256 + TL0)*1.085;
		//�������
		Distance = 0.017 * Time;//ע�ⵥλ;
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