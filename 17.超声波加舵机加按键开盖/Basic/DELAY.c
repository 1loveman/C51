#include "DELAY.h"

void Delay10us()		//@11.0592MHz
{
	unsigned char i;
	i = 2;
	while (--i);
}

void Delay300ms()		//@11.0592MHz
{
	unsigned char i, j, k;
	i = 3;
	j = 26;
	k = 223;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void Delay2000ms()		//@11.0592MHz
{
	unsigned char i, j, k;
	i = 15;
	j = 2;
	k = 235;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
