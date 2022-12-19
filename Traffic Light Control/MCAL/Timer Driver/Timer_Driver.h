/*
 * Timer_Driver.h
 *
 * Created: 06/12/2022 23:39:05
 * Author: marwan
 */ 
#ifndef TIMER_DRIVER_H_
#define TIMER_DRIVER_H_

//Include .h
#include "../../Utilities/Registers.h"
#include <math.h>
#include "../../Utilities/Bit_Manipulation.h"

//All timer function prototypes
void Timer_init();//Initialize timer
void Timer_delay(uint16_t ms);//Calculate delay

#endif /* TIMER_DRIVER_H_ */