#ifndef __SYS_H__
#define __SYS_H__
#include "reg52.h"


sbit Trig = P2^2;
sbit Echo = P2^3;
sbit PWM = P2^4;
sbit KEY1 = P2^1;
//必须用extern声明，不能够直接定义在.h里面，如果直接定义在.h里面，其他的.c引用会导致重复定义。
extern unsigned char cnt;
extern unsigned char jd;
extern unsigned char Vabration;
#endif
