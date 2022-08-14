#include "UART.h"



void UARTInit(){
	PCON &= 0x7F;
	AUXR = 0x01;
	SCON = 0x50;
	TMOD &= 0x0F;
	TMOD |= 0x20;
	TH1 = 0xFD;
	TL1 = 0xFD;
	ET1 = 0;
	TR1 = 1;
	EA = 1;
	ES = 1;
}

void URDataHandler() interrupt 4{
	char buf = SBUF;
	if(RI){
		RI = 0;
		if(buf == 'O'){
			LED1 = 0;
		}
		if(buf == 'S'){
			LED1 = 1;
		}
	}
	if(TI){
		TI = 0;
		LED2 = !LED2;
	}
}
