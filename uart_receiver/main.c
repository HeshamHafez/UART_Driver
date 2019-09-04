/******************************************************************************
 * File Name: main.c
 *
 * Description: main Function
 *
 * Created on: Sep 3, 2019
 *
 * Author: Hesham Hafez
 *
 *******************************************************************************/

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include"uart.h"
#include <util/delay.h>
#include "reg_file.h"
/*******************************************************************************
 *                       	Main Function	                                   *
 *******************************************************************************/
int main(void)
{
	uint8 count = 0;
	DIO_SetPinDirection(PIN8,1);
	DIO_SetPinDirection(PIN9,1);
	DIO_SetPinDirection(PIN10,1);
	DIO_SetPinDirection(PIN11,1);

	DIO_WritePin(PIN8,0);
	DIO_WritePin(PIN9,0);
	DIO_WritePin(PIN10,0);
	DIO_WritePin(PIN11,0);

	DIO_SetPinDirection(PIN26,1);
	DIO_SetPinDirection(PIN28,1);

	DIO_WritePin(PIN26,1);
	DIO_WritePin(PIN28,0);

	UART_Init();
	UART_Start();
	while(1)
	{
		UART_ReceiveChar(&count);
		PORTB = (PORTB & 0xf0) | (count & 0x0f);
	}
}
