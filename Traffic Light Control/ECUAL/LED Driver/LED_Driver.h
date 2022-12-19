/*
 * LED_Driver.h
 *
 * Created: 06/12/2022 23:40:35
 * Author: marwan
 */ 
#ifndef LED_DRIVER_H_
#define LED_DRIVER_H_

//Include .h
#include "../../MCAL/DIO Driver/DIO_Driver.h"
#include "../../MCAL/Timer Driver/Timer_Driver.h"
#include "../../MCAL/Interrupts/Interrupts.h"

//Car port and pins
#define LED_Car_Port PORT_A
#define LED_Car_G_Pin PIN0
#define LED_Car_Y_Pin PIN1
#define LED_Car_R_Pin PIN2

//Pedestrian port and pins
#define LED_Ped_Port PORT_B
#define LED_Ped_G_Pin PIN0
#define LED_Ped_Y_Pin PIN1
#define LED_Ped_R_Pin PIN2

//All led function prototypes
void LED_init(uint8_t ledPort,uint8_t ledPin);//Initialize LED
void LED_on(uint8_t ledPort,uint8_t ledPin);//Turn LED on
void LED_off(uint8_t ledPort,uint8_t ledPin);//Turn LED off
void LED_toggle(uint8_t ledPort,uint8_t ledPin);//Change LED state

#endif /* LED_DRIVER_H_ */