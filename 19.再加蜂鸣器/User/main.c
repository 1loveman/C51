#include "sys.h"
#include "DELAY.h"
#include "TIMER.h"
#include "SG90.h"
#include "UT.h"
#include "KEY.h"
#include "VABRATION.h"


unsigned char cnt = 0;
unsigned char jd = 1;
unsigned char jd_back = 0;
unsigned char Vabration = 0;

int main(){
	Timer0();
	Timer1();
	INT0_Init();
	Buzzer = 1;
	while(1){
		if(!GetKey1Status()||Get_Distance() < 10 || Vabration){
			//转180；
			SG_180();
			//延时2秒
			Delay2000ms();
			//震动标记清零
			Vabration = 0;
			jd_back = jd;
		}
		else{
			//转回0
			SG_0();
			//延时300毫秒
			Delay300ms();
			jd_back = jd;
		}
	}
}

