#include "sys.h"
#include "DELAY.h"
#include "TIMER.h"
#include "SG90.h"
#include "UT.h"
#include "KEY.h"
#include "VABRATION.h"

unsigned char cnt = 0;
unsigned char jd = 1;
unsigned char Vabration = 0;

int main(){
	Timer0();
	Timer1();
	INT0_Init();
	while(1){
		if(!GetKey1Status()||Get_Distance() < 10 || Vabration){
			//ת180��
			SG_180();
			//��ʱ2��
			Delay2000ms();
			Vabration = 0;
		}
		else{
			//ת��0
			SG_0();
			//��ʱ300����
			Delay300ms();
		}
	}
}

