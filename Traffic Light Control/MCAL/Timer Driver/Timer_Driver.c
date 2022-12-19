/*
 * Timer_Driver.c
 *
 * Created: 06/12/2022 23:39:36
 * Author: marwan
 */ 
//Include .h
#include "Timer_Driver.h"

//All timer function definitions
void Timer_init(){
	TCCR0 = 0x00; //normal mode
}

void Timer_delay(uint16_t ms){
	uint16_t OFNum,initTimer;
	double maxDelay,tic;
	uint32_t OFC = 0;
	//max delay 256 micro second
	//at 1MHz no pre-scaler
	//256 pre-scaler
	tic = 256.0/1000.0; //ms    tic = Pre-scaler/FCPU
	maxDelay = 65.536; //ms		Tmaxdelay = tic * 2^8
	if(ms < maxDelay)
	{
		initTimer = (maxDelay - ms)/tic;
		OFNum = 1;
	}
	else 
	{
		if(ms > maxDelay)
		{
			OFNum = ceil((double)ms/maxDelay);
			initTimer = (1<<8) - ((double)ms/tic)/OFNum;
		
		}
		else
		{
			initTimer = 0;
			OFNum = 1;
		}
		
	}
	TCNT0 = initTimer;
	TCCR0 |= (1<<2); //set 256 pre-scaler
	while(OFC < OFNum)
	{
		//busy wait
		while((READ_BIT(TIFR,0)) == 0);
		//clear overflow flag
		SET_BIT(TIFR,0);
		//increment counter
		OFC++;
	}
	//Timer stop
	TCCR0 = 0x00;
}