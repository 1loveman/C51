#ifndef __SYS_H__
#define __SYS_H__
#include "reg52.h"


sbit Trig = P2^2;
sbit Echo = P2^3;
sbit PWM = P2^4;
//������extern���������ܹ�ֱ�Ӷ�����.h���棬���ֱ�Ӷ�����.h���棬������.c���ûᵼ���ظ����塣
extern unsigned char cnt;
extern unsigned char jd;

#endif
