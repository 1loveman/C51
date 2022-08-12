#include "VABRATION.h"

void INT0_Init(){
	EX0 = 1;
	IT0 = 0;
}
//将震动传感器改成中断的触发形势。
void INT0Handle() interrupt 0{
	Vabration = 1;
}