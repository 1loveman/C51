#include "sys.h"
#include "UART.h"
#include "TIMER.h"

int main(){
	//采用定时器计数其实跟软件计时原理一样，但是此处由于while(!RI);导致第一次输入的时候程序一直在while等待
	//导致实际第一个数据效果特别灵敏，但是如果连发两个数据就能看出实际上接收和执行是有延时的。
	//还是需要中断才是无延时。
	char ReceiveData;
	Timer0();
	UARTInit();
	while(1){
		if(T0_Flag){
			SBUF = 'a';
//			ReceiveData = UReceiveByte();
			ReceiveData = SBUF;
			if(ReceiveData == 'O'){
				LED1 = 0;
			}
			else if(ReceiveData == 'S'){
				LED1 = 1;
			}
			RI = 0;
			T0_Flag = 0;
		}
	}
}