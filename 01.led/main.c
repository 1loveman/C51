#include "reg52.h"

sbit LED1 = P3^7;
sbit LED2 = P3^6;

int main(){
	LED1 = 0;
	LED2 = 0;
	while(1);
}