/*
 * Bit_Manipulation.h
 *
 * Created: 06/12/2022 23:42:49
 * Author: marwan
 */ 
#ifndef BIT_MANIPULATION_H_
#define BIT_MANIPULATION_H_

//All bit manipulation macros
#define CLEAR_BIT(REG, NUM) REG&=~(1<<NUM)//Clearing bit in register to 0
#define SET_BIT(REG, NUM) REG |= (1<<NUM)//Setting bit in register to 1
#define TOGGLE_BIT(REG, NUM) REG ^= (1<<NUM)//Changing bit state in register
#define READ_BIT(REG, NUM) ((REG & (1<<NUM))>>NUM)//Read bit in register

#endif /* BIT_MANIPULATION_H_ */