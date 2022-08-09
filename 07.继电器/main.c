#include "reg52.h"

sbit VbrationS = P2^7;
sbit Relay = P2^6;
void Delay1000ms()		//@11.0592MHz
{
	unsigned char i, j, k;
	i = 8;
	j = 1;
	k = 243;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}



int main(){
	//震动导致继电器打开。
	Relay = 1;
	while(1){
		if(!VbrationS){
			Relay = !Relay;
			Delay1000ms();
		}
	}
}