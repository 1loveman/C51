#include "UART.h"

unsigned char UART_REN_STA = 0;
char URBuf[RSIZE];

void UARTInit(){
	PCON &= 0x7F;
	AUXR = 0x01;
	SCON = 0x50;
	TMOD &= 0x0F;
	TMOD |= 0x20;
	TH1 = 0xFD;
	TL1 = 0xFD;
	ET1 = 0;
	TF1 = 0;
	TR1 =1;
	EA = 1;
	ES = 1;
}

void SendBuf(char *str){
	while(*str != '\0'){
		SBUF = *str++;
		while(!TI);
		TI = 0;
	}
}

void UARTHandler() interrupt 4{
	char ch = SBUF;
	if(RI){
		RI = 0;
		if(!(UART_REN_STA & 0x80)){
			if(UART_REN_STA & 0x40){
				if(ch == 0x0A){
					UART_REN_STA |= 0x80;
				}
				else{
					UART_REN_STA = 0;
				}
			}
			else{
				if(ch == 0x0D){
					UART_REN_STA |= 0x40;
				}
				else{
					URBuf[(UART_REN_STA++) & 0x3F] = ch;
					if((UART_REN_STA&0x3F) > RSIZE){
						UART_REN_STA = 0;
					}
				}
			}
		}
	}
}