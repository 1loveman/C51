#include "sys.h"
#include "DELAY.h"
#include "TIMER.h"
#include "SG90.h"
#include "UT.h"
#include "KEY.h"
#include "VABRATION.h"
#include "433.h"

//为了防止其他的文件重复定义，将sfr ，sbit 等都放在一个公用的头文件sys.h里面，
//全局变量直接定义在源文件里面，用extern在sys.h里面声明。

unsigned char cnt = 0;
unsigned char jd = 1;
unsigned char jd_back = 0;
unsigned char Vabration = 0;


int main(){
	//启动T0提供PWM信号
	Timer0();
	//配置T1
	Timer1();
	//打开外部中断0
	INT0_Init();
	Buzzer = 1;
	while(1){
		if(!GetKey1Status()||Get_Distance() < 10 || Vabration || Get_D0()){
			//转180+蜂鸣器鸣叫；
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

