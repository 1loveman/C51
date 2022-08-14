#ifndef __UART_H__
#define __UART_H__
#include "sys.h"
#define RSIZE 20

extern unsigned char UART_REN_STA;
extern char URBuf[RSIZE];

void UARTInit();
void SendBuf(char *str);

#endif
