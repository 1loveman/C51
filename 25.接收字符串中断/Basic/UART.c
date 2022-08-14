#include "UART.h"


char Rbuf[MAXSIZE];

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
	static unsigned char i = 0;
	if(RI){
		RI = 0;
		Rbuf[i++] = SBUF;
		if(MAXSIZE == i){
			i = 0;
			memset(Rbuf,'\0',MAXSIZE);
		}
		if(strstr(Rbuf,"OP")){//在字符串中寻找对应的子串，如果 有返回1反之为0
			LED1 = 0;
			i = 0;
			memset(Rbuf,'\0',MAXSIZE);
		}
		if(strstr(Rbuf,"SH")){
			LED1 = 1;
			i = 0;
			memset(Rbuf,'\0',MAXSIZE);
		}
	}
	if(TI){
		TI = 0;
		LED2 = !LED2;
		
	}
}
