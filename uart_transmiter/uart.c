/******************************************************************************
 *
 * Module: UART
 *
 * File Name: uart.c
 *
 * Description: Source file for the UART AVR driver
 *
 * Created on: Sep 3, 2019
 *
 * Author: Hesham Hafez
 *
 *******************************************************************************/


/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "uart.h"

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/
static volatile uint8 g_flag = LOW;
static volatile uint8 g_index = LOW;
static volatile uint8 g_RxFlag = LOW;

/*******************************************************************************
 *                       Interrupt Service Routines                            *
 *******************************************************************************/

ISR(USART_TXC_vect)
{
	if(g_flag != LOW)
	{
		UART_UDR = g_flag;
		g_index++ ;
	}
}


ISR(USART_RXC_vect)
{
	g_RxFlag = 1;
}
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*******************************************************************************
 * Function Name:	UART_Init
 *
 * Description: 	*Initialize the UART Driver Registers
 * 					*Set the driver Configurations
 *
 * Inputs:			Configuration Structure
 *
 * Outputs:			NULL
 *
 * Return:			Status to check function execution
 *******************************************************************************/
Status UART_Init(void)
{
	uint16 UART_UBRR = 0u;
	if(UART_Config.DoubleSpeed == UART_DoubleSpeedDisable)
	{
		CLEAR_BIT(UART_UCSRA,UART_U2X);
		UART_UBRR = (((F_CPU / (UART_Config.baud_rate * 16UL))) - 1);
	}
	else if(UART_Config.DoubleSpeed == UART_DoubleSpeedEn)
	{
		SET_BIT(UART_UCSRA,UART_U2X);
		UART_UBRR = (((F_CPU / (UART_Config.baud_rate * 8UL))) - 1);
	}
	else
	{
		return NotOk;
	}

	/*clear to choose UBRRH*/
	CLEAR_BIT(UART_UCSRC,UART_URSEL);
	UART_UBRRL = (uint8)UART_UBRR;
	UART_UBRRH = (uint8)(UART_UBRR >> 8);
	SET_BIT(UART_UCSRC,UART_URSEL);
	/*set to choose UCSRC*/
	/*************************************************************************************/
	if(UART_Config.DataSize == Bit5)
	{
		CLEAR_BIT(UART_UCSRB,UART_UCSZ2);
		CLEAR_BIT(UART_UCSRC,UART_UCSZ1);
		CLEAR_BIT(UART_UCSRC,UART_UCSZ0);
	}
	else if(UART_Config.DataSize == Bit6)
	{
		CLEAR_BIT(UART_UCSRB,UART_UCSZ2);
		CLEAR_BIT(UART_UCSRC,UART_UCSZ1);
		SET_BIT(UART_UCSRC,UART_UCSZ0);
	}
	else if(UART_Config.DataSize == Bit7)
	{
		CLEAR_BIT(UART_UCSRB,UART_UCSZ2);
		SET_BIT(UART_UCSRC,UART_UCSZ1);
		CLEAR_BIT(UART_UCSRC,UART_UCSZ0);
	}
	else if(UART_Config.DataSize == Bit8)
	{
		CLEAR_BIT(UART_UCSRB,UART_UCSZ2);
		SET_BIT(UART_UCSRC,UART_UCSZ1);
		SET_BIT(UART_UCSRC,UART_UCSZ0);
	}
	else if(UART_Config.DataSize == Bit9)
	{
		SET_BIT(UART_UCSRB,UART_UCSZ2);
		SET_BIT(UART_UCSRC,UART_UCSZ1);
		SET_BIT(UART_UCSRC,UART_UCSZ0);
	}
	else
	{
		return NotOk;
	}

	/*********************************************************************************/
	if(UART_Config.Parity == UART_ParityDisabled)
	{
		CLEAR_BIT(UART_UCSRC,UART_UPM0);
		CLEAR_BIT(UART_UCSRC,UART_UPM1);
	}
	else if(UART_Config.Parity == UART_ParityOdd)
	{
		SET_BIT(UART_UCSRC,UART_UPM0);
		SET_BIT(UART_UCSRC,UART_UPM1);
	}
	else if(UART_Config.Parity == UART_ParityEven)
	{
		CLEAR_BIT(UART_UCSRC,UART_UPM0);
		SET_BIT(UART_UCSRC,UART_UPM1);
	}
	else
	{
		return NotOk;
	}

	/*****************************************************************************/
	if(UART_Config.StopBits == UART_StopBit1)
	{
		CLEAR_BIT(UART_UCSRC,UART_USBS);
	}
	else if(UART_Config.StopBits == UART_StopBit2)
	{
		SET_BIT(UART_UCSRC,UART_USBS);
	}
	return Ok;
}

/*******************************************************************************
 * Function Name:	UART_SendChar
 *
 * Description: 	transmit a new byte
 *
 * Inputs:			Transmitting Byte
 *
 * Outputs:			NULL
 *
 * Return:			Status to check function execution
 *******************************************************************************/
Status UART_SendChar(const uint8 a_data)
{

	if(UART_Config.Udr  == UART_UdrDisabled)
	{
		/* UDRE flag is set when the Tx buffer (UDR) is empty and ready for
		 * transmitting a new byte so wait until this flag is set to one */

		while(IS_BIT_CLEAR(UART_UCSRA,UART_UDRE)){}

		/* Put the required data in the UDR register and it also clear the UDRE flag as
		 * the UDR register is not empty now */

		UART_UDR = a_data;
		return Ok;
	}
	else if(UART_Config.Udr == UART_UdrEn)
	{
		g_flag = a_data;
	}
	else
	{
		return NotOk;
	}
	return Ok;
}

/*******************************************************************************
 * Function Name:	UART_ReceiveChar
 *
 * Description: 	Receive a new byte
 *
 * Inputs:			None
 *
 * Outputs:			received Byte
 *
 * Return:			Status to check function execution
 *******************************************************************************/
Status UART_ReceiveChar(uint8 * a_data_ptr)
{
	if (UART_Config.RxInt == UART_RxIntDisabled)
	{
		while(IS_BIT_CLEAR(UART_UCSRA,UART_RXC)){}

		*a_data_ptr = UDR;
	}
	else if(UART_Config.RxInt == UART_RxIntEn)
	{
		if (g_RxFlag == 1)
		{
			*a_data_ptr = UDR;
			g_RxFlag = 0;
		}
		else
		{
			*a_data_ptr = LOW;
		}
	}
	else
	{
		return NotOk;
	}
	return Ok;
}


/*******************************************************************************
 * Function Name:	UART_Send
 *
 * Description: 	transmit a new String
 *
 * Inputs:			Transmitted String
 *
 * Outputs:			NULL
 *
 * Return:			Status to check function execution
 *******************************************************************************/
Status UART_Send(const uint8 * a_data_ptr)
{
	uint8 index = LOW;
	if(UART_Config.Udr  == UART_UdrDisabled)
	{
		while(a_data_ptr[index] != '\0')
		{
			UART_SendChar(a_data_ptr[index]);
			index++;
		}
	}
	else if(UART_Config.Udr == UART_UdrEn)
	{
		g_index = LOW;
		while(a_data_ptr[g_index] != '\0')
		{
			UART_SendChar(a_data_ptr[g_index]);
		}
	}
	else
	{
		return NotOk;
	}

	return Ok;
}

/*******************************************************************************
 * Function Name:	UART_Receive
 *
 * Description: 	Receive a new String
 *
 * Inputs:			None
 *
 * Outputs:			Received String
 *
 * Return:			Status to check function execution
 *******************************************************************************/
Status UART_Receive(uint8 * a_data_ptr)
{
	static uint8 loop_index = 0;

	if (UART_Config.RxInt == UART_RxIntDisabled)
	{
		while(UART_UDR != '#'){
			UART_ReceiveChar(&a_data_ptr[loop_index]);
			loop_index++;
		}
		loop_index=0;
	}
	else if(UART_Config.RxInt == UART_RxIntEn)
	{
		/* ISR will be executed */
		if(UART_UDR != '#'){
			UART_ReceiveChar(&a_data_ptr[loop_index]);
			/* Garbage value detection */
			if (a_data_ptr[loop_index] != LOW)
			{
				loop_index++;
			}
		}
		else
		{
			loop_index=0;
		}
	}
	else
	{
		return NotOk;
	}
	return Ok;
}

/*******************************************************************************
 * Function Name:	UART_Start
 *
 * Description: 	Start transmitting or Receiving
 *
 * Inputs:			NULL
 *
 * Outputs:		NULL
 *
 * Return:			Status to check function execution
 *******************************************************************************/
Status UART_Start(void)
{
	SET_BIT(UART_UCSRB,UART_TXEN);
	SET_BIT(UART_UCSRB,UART_RXEN);
	SET_BIT(UART_UCSRB,UART_UDRIE);

	if(UART_Config.TxInt  == UART_TxIntDisabled)
	{
		CLEAR_BIT(UART_UCSRB,UART_TXCIE);
		CLEAR_BIT(SREG,7);
	}
	else if(UART_Config.TxInt  == UART_TxIntEn)
	{
		SET_BIT(UART_UCSRB,UART_TXCIE);
		SET_BIT(SREG,7);
	}
	else
	{
		return NotOk;
	}

	if(UART_Config.Udr == UART_UdrDisabled)
	{
		CLEAR_BIT(UART_UCSRB,UART_UDRIE);
		CLEAR_BIT(SREG,7);
	}
	else if(UART_Config.Udr  == UART_UdrEn)
	{
		SET_BIT(UART_UCSRB,UART_UDRIE);
		SET_BIT(SREG,7);
	}
	else
	{
		return NotOk;
	}

	if(UART_Config.RxInt  == UART_RxIntDisabled)
	{
		CLEAR_BIT(UART_UCSRB,UART_RXCIE);
		CLEAR_BIT(SREG,7);
	}
	else if(UART_Config.RxInt  == UART_RxIntEn)
	{
		SET_BIT(UART_UCSRB,UART_RXCIE);
		SET_BIT(SREG,7);
	}
	else
	{
		return NotOk;
	}
	return Ok;
}

/*******************************************************************************
 * Function Name:	UART_Stop
 *
 * Description: 	Stop transmitting or Receiving
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			Status to check function execution
 *******************************************************************************/
Status UART_Stop(void)
{
	CLEAR_BIT(UART_UCSRB,UART_TXEN);
	CLEAR_BIT(UART_UCSRB,UART_RXEN);
	CLEAR_BIT(UART_UCSRB,UART_UDRIE);
	CLEAR_BIT(UART_UCSRB,UART_TXCIE);
	CLEAR_BIT(UART_UCSRB,UART_RXCIE);

	return Ok;
}



