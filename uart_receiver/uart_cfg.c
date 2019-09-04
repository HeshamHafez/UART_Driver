/******************************************************************************
 *
 * Module: UART
 *
 * File Name: uart_cfg.c
 *
 * Description: Source file for configurations of the UART AVR driver
 *
 * Created on: Sep 3, 2019
 *
 * Author: Hesham Hafez
 *
 *******************************************************************************/

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include"uart_cfg.h"

/*******************************************************************************
 *                         Configurations Structure                            *
 *******************************************************************************/
UART_cfg UART_Config =
{
		9600,
		UART_DoubleSpeedEn,
		UART_TxIntDisabled,
		UART_RxIntDisabled,
		UART_UdrDisabled,
		Bit8,
		UART_ParityDisabled,
		UART_StopBit1
};



