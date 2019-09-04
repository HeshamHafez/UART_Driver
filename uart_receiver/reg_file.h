/*
 * reg_file.h
 *
 *  Created on: Aug 17, 2019
 *      Author: hesha
 */

#ifndef REG_FILE_H_
#define REG_FILE_H_

#include "common_macros.h"
#include "std_types.h"

#define DIO_PORTA (*(volatile uint8 *)0x003B)
#define DIO_DDRA  (*(volatile uint8 *)0x003A)
#define DIO_PINA  (*(volatile const uint8 *)0x0039)

#define DIO_PORTB (*(volatile uint8 *)0x0038)
#define DIO_DDRB  (*(volatile uint8 *)0x0037)
#define DIO_PINB  (*(volatile const uint8 *)0x0036)

#define DIO_PORTC (*(volatile uint8 *)0x0035)
#define DIO_DDRC  (*(volatile uint8 *)0x0034)
#define DIO_PINC  (*(volatile const uint8 *)0x0033)

#define DIO_PORTD (*(volatile uint8 *)0x0032)
#define DIO_DDRD  (*(volatile uint8 *)0x0031)
#define DIO_PIND  (*(volatile const uint8 *)0x0030)

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define PIN8  8
#define PIN9  9
#define PIN10 10
#define PIN11 11
#define PIN12 12
#define PIN13 13
#define PIN14 14
#define PIN15 15

#define PIN16 16
#define PIN17 17
#define PIN18 18
#define PIN19 19
#define PIN20 20
#define PIN21 21
#define PIN22 22
#define PIN23 23

#define PIN24 24
#define PIN25 25
#define PIN26 26
#define PIN27 27
#define PIN28 28
#define PIN29 29
#define PIN30 30
#define PIN31 31

void DIO_WritePin(uint8 PinNum,uint8 PinValue);
uint8 DIO_ReadPin(uint8 PinNum);
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection);

#endif /* REG_FILE_H_ */
