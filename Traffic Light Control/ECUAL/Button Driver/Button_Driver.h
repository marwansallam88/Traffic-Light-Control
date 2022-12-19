/*
 * Button_Driver.h
 *
 * Created: 06/12/2022 23:40:23
 * Author: marwan
 */ 
#ifndef BUTTON_DRIVER_H_
#define BUTTON_DRIVER_H_

//Include .h
#include "../../MCAL/DIO Driver/DIO_Driver.h"
#include "../../MCAL/Timer Driver/Timer_Driver.h"
#include "../../MCAL/Interrupts/Interrupts.h"

//Button port and pin
#define Button_Port PORT_D
#define Button_Pin PIN2

//All button function prototypes
void Button_init(uint8_t buttonPort,uint8_t buttonPin);//Initialize button
void Button_read(uint8_t buttonPort,uint8_t buttonPin,uint8_t* value);//Read button

#endif /* BUTTON_DRIVER_H_ */