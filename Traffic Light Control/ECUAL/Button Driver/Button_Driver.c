/*
 * Button_Driver.c
 *
 * Created: 06/12/2022 23:39:52
 * Author: marwan
 */ 
//Include .h
#include "Button_Driver.h"

//All button function definitions
void Button_init(uint8_t buttonPort,uint8_t buttonPin){
	DIO_init(buttonPort,buttonPin,IN);
}

void Button_read(uint8_t buttonPort,uint8_t buttonPin,uint8_t* value){
	DIO_read(buttonPort,buttonPin,value);
}