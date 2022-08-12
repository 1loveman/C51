#include "SG90.h"

void Timer0Handle() interrupt 1 {
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

void SG_180(){
	jd = 5;
	if(jd_back != jd){
		//УљНа
		DoBuzzer();
		cnt = 0;
	}
}

void SG_0(){
	jd = 1;
	cnt = 0;
}