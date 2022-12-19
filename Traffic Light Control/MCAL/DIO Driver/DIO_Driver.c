/*
 * DIO_Driver.c
 *
 * Created: 06/12/2022 23:33:43
 * Author: marwan
 */ 
//Include .h
#include "DIO_Driver.h"

//All driver function prototypes
void DIO_init(uint8_t portNum, uint8_t pinNum, uint8_t dir)
{
	switch(portNum){
		case PORT_A:
			if(dir == IN){
				CLEAR_BIT(DDRA, pinNum);
			}else if (dir == OUT){
				SET_BIT(DDRA, pinNum);
			}
			else{
				//Error handling
			}
			break;
		case PORT_B:
			if(dir == IN){
				CLEAR_BIT(DDRB, pinNum);
			}else if (dir == OUT){
				SET_BIT(DDRB, pinNum);
			}
			else{
				//Error handling
			}
			break;
		case PORT_C:
			if(dir == IN){
				CLEAR_BIT(DDRC, pinNum);
			}else if (dir == OUT){
				SET_BIT(DDRC, pinNum);
			}
			else{
				//Error handling
			}
			break;
		case PORT_D:
			if(dir == IN){
				CLEAR_BIT(DDRD, pinNum);
			}else if (dir == OUT){
				SET_BIT(DDRD, pinNum);
			}
			else{
				//Error handling
			}
			break;
		default:
			//Error handling
			break;
	}
}

void DIO_write(uint8_t portNum, uint8_t pinNum, uint8_t value)
{
	switch(portNum){
		case PORT_A:
			if(value == LOW){
				CLEAR_BIT(PORTA, pinNum); //Write 0
			}else if (value == HIGH){
				SET_BIT(PORTA, pinNum); //Write 1
			}
			else{
				//Error handling
			}
			break;
		case PORT_B:
			if(value == LOW){
				 
				CLEAR_BIT(PORTB, pinNum); //Write 0
			}else if (value == HIGH){
				SET_BIT(PORTB, pinNum); //Write 1
			}
			else{
				//Error handling
			}
			break;
		case PORT_C:
			if(value == LOW){
				CLEAR_BIT(PORTC, pinNum); //Write 0
			}else if (value == HIGH){
				SET_BIT(PORTC, pinNum); //Write 1
			}
			else{
				//Error handling
			}
			break;
		case PORT_D:
			if(value == LOW){
				CLEAR_BIT(PORTD, pinNum); //Write 0
			}else if (value == HIGH){
				SET_BIT(PORTD, pinNum);//Write 1
			}
			else{
				//Error handling
			}
			break;
		default:
			//Error handling
			break;
	}
}

void DIO_toggle(uint8_t portNum, uint8_t pinNum)
{
	switch(portNum){
		case PORT_A:
			TOGGLE_BIT(PORTA,pinNum);
			break;
		case PORT_B:
			TOGGLE_BIT(PORTB,pinNum);
			break;
		case PORT_C:
			TOGGLE_BIT(PORTC,pinNum);
			break;
		case PORT_D:
			TOGGLE_BIT(PORTD,pinNum);
			break;
		default:
			//Error handling
			break;
	}
}

void DIO_read(uint8_t portNum, uint8_t pinNum, uint8_t* value)
{
	switch(portNum){
		case PORT_A:
			*value = READ_BIT(PINA,pinNum);
			break;
		case PORT_B:
			*value = READ_BIT(PINB,pinNum);
			break;
		case PORT_C:
			*value = READ_BIT(PINC,pinNum);
			break;
		case PORT_D:
			*value = READ_BIT(PIND,pinNum);
			break;
		default:
			//Error handling
			break;
	}
}