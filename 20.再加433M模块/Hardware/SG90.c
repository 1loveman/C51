#include "SG90.h"

//中断的作用就是产生PWM波形
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
	//通过设置jd_back标志判断手是否有拿开，还是说一直是处在一个位置不动。
	if(jd_back != jd){
		//鸣叫
		DoBuzzer();
		cnt = 0;
	}
}

void SG_0(){
	jd = 1;
	cnt = 0;
}