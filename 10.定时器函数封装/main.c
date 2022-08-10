#include "reg52.h"

void Timer(){
	TMOD &= 0xF0;
	TMOD |= 0x01;
	TH0 = 0xDC;
	TL0 = 0x00;
	TF0 = 0;
	TR0 = 1;
}

sbit LED1 = P3^7;

int main(){
	unsigned char cnt = 0;
	LED1 = 1;
	while(1){
		Timer();
		while(!TF0);
		cnt++;
		if(cnt == 100){
			LED1 = !LED1;
			cnt = 0;
		}
	}
}