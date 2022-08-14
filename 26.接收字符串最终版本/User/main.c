#include "sys.h"
#include "TIMER.h"
#include "UART.h"


int main(){
	Timer0();
	UARTInit();
	LED1 = 1;
	while(1){
		if(T0_Flag){
			SendBuf(URBuf); 
			if((UART_REN_STA&0x3F) == 4){
				LED1 = 0;
			}
			T0_Flag = 0;
		}
	}
}