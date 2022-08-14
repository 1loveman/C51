#ifndef __SYS_H__
#define __SYS_H__
#include "reg52.h"

sfr AUXR = 0x8E;
sbit LED1 = P3^7;
sbit LED2 = P3^6;

#endif
