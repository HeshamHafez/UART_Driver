/*************************************************
 * Module 	  : Common Macros
 *
 * File name  : common_macros.h
 *
 * Created on : Apr 9, 2019
 *
 * Author     : Hesham Hafez
 *************************************************/
#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_

#define NULL_PTR    ((void*)0u)

#define I 7u

#define LOW  0u
#define HIGH 1u

#define OUTPUT 0u
#define INPUT  1u

/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT) (REG&=~(1<<BIT))

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

/* Check if a specific bit is set in any register and return true if yes */
#define IS_BIT_SET(REG,BIT) (REG & (1<<BIT))

/* Check if a specific bit is cleared in any register and return true if yes */
#define IS_BIT_CLEAR(REG,BIT) (!(REG & (1<<BIT)))

/* Set a certain nubble in any register */
#define SET_NUBBLE(REG,FIRST_BIT) (REG|=(0x0F<<FIRST_BIT))

/* Clear a certain nubble in any register */
#define CLEAR_NUBBLE(REG,FIRST_BIT) (REG&=~(0x0F<<FIRST_BIT))

/* Toggle a certain nubble in any register */
#define TOGGLE_NUBBLE(REG,FIRST_BIT) (REG^=(0x0F<<FIRST_BIT))
#endif /* COMMON_MACROS_H_ */
