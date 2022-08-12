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
			//转180；
			SG_180();
			//延时2秒
			Delay2000ms();
		}
		else{
			//转回0
			SG_0();
			//延时300毫秒
			Delay300ms();
		}
	}
}

