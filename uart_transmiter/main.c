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
	uint8 i,count = 0;
	DIO_SetPinDirection(PIN20,LOW);

	UART_Init();
	UART_Start();
	while(1)
	{
		for(i=0;i<10;i++)
		{
			if(DIO_ReadPin(20)==HIGH)
			{
				_delay_ms(30);
				if(DIO_ReadPin(20)== HIGH)
				{
						if(count<9)
						{
							count++;
						}
						else
						{
							count = 0;
						}
				}
			}
			_delay_ms(50);
		}

		UART_SendChar(count);
	}
}

