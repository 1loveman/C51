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
}

//char UReceiveByte(){
//	while(!RI);//程序可能在这一直等待。
//	RI = 0;
//	return SBUF;
//}