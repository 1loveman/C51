#include "sys.h"
#include "UART.h"
#include "TIMER.h"

int main(){
	//���ö�ʱ��������ʵ�������ʱԭ��һ�������Ǵ˴�����while(!RI);���µ�һ�������ʱ�����һֱ��while�ȴ�
	//����ʵ�ʵ�һ������Ч���ر�������������������������ݾ��ܿ���ʵ���Ͻ��պ�ִ��������ʱ�ġ�
	//������Ҫ�жϲ�������ʱ��
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