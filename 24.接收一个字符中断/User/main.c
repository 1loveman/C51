#include "sys.h"
#include "UART.h"
#include "TIMER.h"

int main(){
	Timer0();
	UARTInit();
	LED2 = 1;
	while(1){
		if(T0_Flag){
			SBUF = 'a';
			T0_Flag = 0;
		}
	}
}

