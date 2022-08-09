#include "reg52.h"

sbit LED1 = P3^7;

int main(){
	unsigned char cnt = 0;
	LED1 = 1;
	TMOD &= 0xF0;
	TMOD |= 0x01;
	TL0 = 0x00;
	TH0 = 0xDC;
	TF0 = 0;
	TR0 = 1;
	while(1){
		if(TF0){
			TF0 = 0;
			TL0 = 0x00;
			TH0 = 0xDC;
			cnt++;
		}
		if(cnt==100){
			LED1 = !LED1;
			cnt = 0;
		}
	}
	
}