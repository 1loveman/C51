#include "reg52.h"

sbit VbrationS = P2^7;
sbit Relay = P2^6;
sbit A433 = P2^5;
sbit B433 = P2^4;

void Delay50us()		//@11.0592MHz
{
	unsigned char i;
	i = 20;
	while (--i);
}



void Delay100ms()		//@11.0592MHz
{
	unsigned char i, j;

	i = 180;
	j = 73;
	do
	{
		while (--j);
	} while (--i);
}



void Delay200ms()		//@11.0592MHz
{
	unsigned char i, j, k;
	i = 2;
	j = 103;
	k = 147;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}




int main(){
	//遥控打开或者解除上锁;
	unsigned char LockStatus = 1;
	Relay = 1;
	while(1){
		if(A433){
			Relay = 0;
			Delay200ms();
			Relay = 1;
			LockStatus = 0;
		}
		if(B433){
			Relay = 0;
			Delay100ms();
			Relay = 1;
			LockStatus = 1;
		}
		if(!LockStatus){
			if(!VbrationS){
				Delay50us();
				if(!VbrationS){
					Relay = 0;
				}
			}
		}
	}
}
