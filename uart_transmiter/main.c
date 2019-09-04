/*
 * main.c
 *
 *  Created on: Sep 2, 2019
 *      Author: hesha
 */

#include"uart.h"

int main(void)
{
	UART_cfg UART_Config = {9600,UART_DoubleSpeedEn,UART_TxIntDisabled,UART_RxIntDisabled,UART_UdrDisabled,Bit8,UART_ParityDisabled,UART_StopBit1};
	UART_Init(&UART_Config);
	while(1)
	{

	}
}

