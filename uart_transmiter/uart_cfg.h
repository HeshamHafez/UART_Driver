/******************************************************************************
 *
 * Module: UART
 *
 * File Name: uart_cfg.h
 *
 * Description: Header file for configurations of the UART AVR driver
 *
 * Created on: Sep 3, 2019
 *
 * Author: Hesham Hafez
 *
 *******************************************************************************/

#ifndef UART_CFG_H_
#define UART_CFG_H_

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include"std_types.h"
#include"common_macros.h"

/*******************************************************************************
 *                   	 CPU Frequency configurations                          *
 *******************************************************************************/
#ifndef F_CPU
#define F_CPU 8000000UL //8MHz Clock frequency
#endif

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
/* Double Speed Mode Enable/Disable */
typedef enum {
	UART_DoubleSpeedDisable = 0u,
	UART_DoubleSpeedEn      = 1u
}UART_DoubleSpeed;

/* Transmit Interrupt Enable/Disable */
typedef enum {
	UART_TxIntDisabled = 0u,
	UART_TxIntEn       = 1u
}UART_TxInt;

/* Receive Interrupt Enable/Disable */
typedef enum {
	UART_RxIntDisabled = 0u,
	UART_RxIntEn       = 1u
}UART_RxInt;

/* UDR Interrupt Enable/Disable */
typedef enum {
	UART_UdrDisabled = 0u,
	UART_UdrEn       = 1u
}UART_UdrInt;

/* Data Frame bits numbers*/
typedef enum {
	Bit5 = 5u,
	Bit6 = 6u,
	Bit7 = 7u,
	Bit8 = 8u,
	Bit9 = 9u
}UART_DataSize;

/*Parity Bits configurations */
typedef enum {
	UART_ParityDisabled = 0u,
	UART_ParityOdd      = 1u,
	UART_ParityEven     = 2u
}UART_Parity;

/* check number of stop bits*/
typedef enum {
	UART_StopBit1 = 1u,
	UART_StopBit2 = 2u
}UART_StopBits;

/*check the function execution*/
typedef enum {
	NotOk = 0u,
	Ok    = 1u
}Status;

/*******************************************************************************
 *                         Configurations Structure                            *
 *******************************************************************************/
typedef struct{
	uint16 baud_rate;
	UART_DoubleSpeed	DoubleSpeed;
	UART_TxInt			TxInt;
	UART_RxInt			RxInt;
	UART_UdrInt			Udr;
	UART_DataSize		DataSize;
	UART_Parity			Parity;
	UART_StopBits		StopBits;
}UART_cfg;


#endif /* UART_CFG_H_ */
