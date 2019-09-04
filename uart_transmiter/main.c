/*
 * main.c
 *
 *  Created on: Sep 2, 2019
 *      Author: hesha
 */

#include"uart.h"

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

