/*
 * LED_Driver.c
 *
 * Created: 06/12/2022 23:40:05
 * Author: marwan
 */ 
//Include .h
#include "LED_Driver.h"

//All led function prototypes
void LED_init(uint8_t ledPort,uint8_t ledPin){
	DIO_init(ledPort,ledPin,OUT);
}
void LED_on(uint8_t ledPort,uint8_t ledPin){
	DIO_write(ledPort,ledPin,HIGH);
}
void LED_off(uint8_t ledPort,uint8_t ledPin){
	DIO_write(ledPort,ledPin,LOW);
}
void LED_toggle(uint8_t ledPort,uint8_t ledPin){
	DIO_toggle(ledPort,ledPin);
}