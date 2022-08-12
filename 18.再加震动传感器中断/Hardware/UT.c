#include "UT.h"

void UTStart(){
	Trig = 0;
	Trig = 1;
	Delay10us();
	Trig = 0;
}


double Get_Distance(){
	double Time;
	//开始计时
	UTStart();
	//等待Echo拉高
	while(!Echo);
	//开始计时
	Timer1_ON();
	//等待Echo拉低
	while(Echo);
	//关闭计时
	Timer1_OFF();
	//计算时间
	Time = 1.085 * (TH1 * 256 +TL1);
	//返回距离
	return (0.017 * Time);
}