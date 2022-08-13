#include "sys.h"
#include "TIMER.h"
#include "UART.h"

int main(){
	Timer0();
	UartInit();
	while(1){
		if(T0_Flag){
			SBUF = 'a';
			T0_Flag = 0;
		}
	}
}