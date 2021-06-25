// creating delay of 'x' seconds
#include<LPC214X.h>

void main()
{
	PINSEL0 = 00;
	
	IO0DIR = 0xFFFFFFFF;
	
	while(1)
	{
		IOSET = 0xFFFFFFFF;
		delay(1, 12);	// specify required delay time in seconds and Clock frequency in Mhz
		IOCLR = 0xFFFFFFFF;
		delay();
}
	
void delay(int timeInSec, int clkFreq)
{
	//Fsource = 12Mhz
	//Tsource = 1/Fsource = 1/(12*10^6) = 6.6*10^-8 sec
	//eg. No. of cycles = timeInsec/Tsource = 1/6.6*10^-8 = 15000000
	int Tsource = 1/(clkFreq*1000000);
	T0MR0 = timeInSec/Tsource;	// No. of cycles
	T0MCR = 0x04;	// stop timer when match is attained ie., when T0MR0 = T0TC
	T0TCR = 0x01;
	while(T0MR0 != T0TC)`{	// Run the loop till the T0MR0 = T0TC (setting the action)
	}
	TOTC = 0; // reset after action
}