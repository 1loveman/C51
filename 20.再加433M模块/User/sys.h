#ifndef __SYS_H__
#define __SYS_H__
#include "reg52.h"


sbit Trig = P2^2;
sbit Echo = P2^3;
sbit PWM = P2^4;
sbit KEY1 = P2^1;
sbit Buzzer = P1^7;
sbit D0 = P1^6;
//������extern���������ܹ�ֱ�Ӷ�����.h���棬���ֱ�Ӷ�����.h���棬������.c���ûᵼ���ظ����塣
extern unsigned char cnt;
extern unsigned char jd;
extern unsigned char jd_back;
extern unsigned char Vabration;
#endif
