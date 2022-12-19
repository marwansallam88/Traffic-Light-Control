/*
 * DIO_Driver.h
 *
 * Created: 06/12/2022 23:33:34
 * Author: marwan
 */ 
#ifndef DIO_DRIVER_H_
#define DIO_DRIVER_H_

//Include .h
#include "../../Utilities/Registers.h"
#include "../../Utilities/Bit_Manipulation.h"

//All port definitions
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

//Direction definitions
#define IN 0
#define OUT 1

//Value definitions
#define LOW 0
#define HIGH 1

//All driver function prototypes
void DIO_init(uint8_t portNum, uint8_t pinNum, uint8_t dir);//Initialize DIO direction
void DIO_write(uint8_t portNum, uint8_t pinNum, uint8_t value);//Write data to DIO
void DIO_toggle(uint8_t portNum, uint8_t pinNum);//Change DIO state
void DIO_read(uint8_t portNum, uint8_t pinNum, uint8_t* value);//Read DIO

#endif /* DIO_DRIVER_H_ */