#include "sys.h"
#include "DELAY.h"
#include "TIMER.h"
#include "SG90.h"
#include "UT.h"

unsigned char cnt = 0;
unsigned char jd = 1;

int main(){
	Timer0();
	Timer1();
	while(1){
		if(Get_Distance() < 10){
			//ת180��
			SG_180();
			//��ʱ2��
			Delay2000ms();
		}
		else{
			//ת��0
			SG_0();
			//��ʱ300����
			Delay300ms();
		}
	}
}

