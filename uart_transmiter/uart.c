/*
 * uart.c
 *
 *  Created on: Sep 2, 2019
 *      Author: hesha
 */

#include"uart.h"

Status UART_Init(UART_cfg* a_UartCfg_ptr)
{
	uint16 UBRR = 0u;
	if(a_UartCfg_ptr -> DoubleSpeed == UART_DoubleSpeedDisable)
	{
		CLEAR_BIT(UCSRA,U2X);
		UBRR = (((F_CPU / (a_UartCfg_ptr->baud_rate * 16UL))) - 1);
	}
	else if(a_UartCfg_ptr->DoubleSpeed == UART_DoubleSpeedEn)
	{
		SET_BIT(UCSRA,U2X);
		UBRR = (((F_CPU / (a_UartCfg_ptr->baud_rate * 8UL))) - 1);
	}
	else
	{
		return NotOk;
	}

	/*clear to choose UBRRH*/
	CLEAR_BIT(UCSRC,URSEL);
	UBRRL = (uint8)UBRR;
	UBRRH = (uint8)(UBRR >> 8);
	SET_BIT(UCSRC,URSEL);
	/*set to choose UCSRC*/
	/*************************************************************************************/
	if(a_UartCfg_ptr -> TxInt  == UART_TxIntDisabled)
	{
		CLEAR_BIT(UCSRB,TXCIE);
	}
	else if(a_UartCfg_ptr -> TxInt  == UART_TxIntEn)
	{
		SET_BIT(UCSRB,TXCIE);
	}
	else
	{
		return NotOk;
	}
	/*************************************************************************************/
	if(a_UartCfg_ptr -> RxInt  == UART_RxIntDisabled)
	{
		CLEAR_BIT(UCSRB,RXCIE);
	}
	else if(a_UartCfg_ptr -> RxInt  == UART_RxIntEn)
	{
		SET_BIT(UCSRB,RXCIE);
	}
	else
	{
		return NotOk;
	}
	/***************************************************************************************/
	if(a_UartCfg_ptr -> Udr == UART_UdrDisabled)
	{
		CLEAR_BIT(UCSRB,UDRIE);
	}
	else if(a_UartCfg_ptr -> Udr  == UART_UdrEn)
	{
		SET_BIT(UCSRB,UDRIE);
	}
	else
	{
		return NotOk;
	}
	/********************************************************************************************/
	if(a_UartCfg_ptr -> DataSize == Bit5)
	{
		CLEAR_BIT(UCSRB,UCSZ2);
		CLEAR_BIT(UCSRC,UCSZ1);
		CLEAR_BIT(UCSRC,UCSZ0);
	}
	else if(a_UartCfg_ptr -> DataSize == Bit6)
	{
		CLEAR_BIT(UCSRB,UCSZ2);
		CLEAR_BIT(UCSRC,UCSZ1);
		SET_BIT(UCSRC,UCSZ0);
	}
	else if(a_UartCfg_ptr -> DataSize == Bit7)
	{
		CLEAR_BIT(UCSRB,UCSZ2);
		SET_BIT(UCSRC,UCSZ1);
		CLEAR_BIT(UCSRC,UCSZ0);
	}
	else if(a_UartCfg_ptr -> DataSize == Bit8)
	{
		CLEAR_BIT(UCSRB,UCSZ2);
		SET_BIT(UCSRC,UCSZ1);
		SET_BIT(UCSRC,UCSZ0);
	}
	else if(a_UartCfg_ptr -> DataSize == Bit9)
	{
		SET_BIT(UCSRB,UCSZ2);
		SET_BIT(UCSRC,UCSZ1);
		SET_BIT(UCSRC,UCSZ0);
	}
	else
	{
		return NotOk;
	}

	/*********************************************************************************/
	if(a_UartCfg_ptr -> Parity == UART_ParityDisabled)
	{
		CLEAR_BIT(UCSRC,UPM0);
		CLEAR_BIT(UCSRC,UPM1);
	}
	else if(a_UartCfg_ptr -> Parity == UART_ParityOdd)
	{
		SET_BIT(UCSRC,UPM0);
		SET_BIT(UCSRC,UPM1);
	}
	else if(a_UartCfg_ptr -> Parity == UART_ParityEven)
	{
		CLEAR_BIT(UCSRC,UPM0);
		SET_BIT(UCSRC,UPM1);
	}
	else
	{
		return NotOk;
	}

	/*****************************************************************************/
	if(a_UartCfg_ptr -> StopBits == UART_StopBit1)
	{
		CLEAR_BIT(UCSRC,USBS);
	}
	else if(a_UartCfg_ptr -> StopBits == UART_StopBit2)
	{
		SET_BIT(UCSRC,USBS);
	}
	return Ok;
}
