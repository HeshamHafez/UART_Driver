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

/*******************************************************************************
 *                       	Main Function	                                   *
 *******************************************************************************/
int main(void)
{
	uint8 data;
	UART_Init();
	UART_Start();
	while(1)
	{
		UART_ReceiveChar(&data); //Receive Byte from Terminal1
		UART_SendChar(data); //Resend the received byte to Terminal2
	}
}

