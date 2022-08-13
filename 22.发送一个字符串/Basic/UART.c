#include "UART.h"

void UartInit(){
	PCON &= 0x7F;
	SCON = 0x40;
	AUXR = 0x01;
	TMOD &= 0x0F;
	TMOD |= 0x20;
	TH1 = 0xFD;
	TL1 = 0xFD;
	ET1 = 0;
	TR1 =1;
}

void SendBuf(char *str){
	while(*str != '\0'){
		SBUF = *str++;
		while(!TI);
		TI = 0;
	}
}