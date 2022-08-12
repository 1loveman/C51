#include "VABRATION.h"

void INT0_Init(){
	EX0 = 1;
	IT0 = 0;
}

void INT0Handle() interrupt 0{
	Vabration = 1;
}