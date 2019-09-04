/******************************************************************************
 *
 * Module: UART
 *
 * File Name: uart.h
 *
 * Description: Header file for the UART AVR driver
 *
 * Created on: Sep 3, 2019
 *
 * Author: Hesham Hafez
 *
 *******************************************************************************/

#ifndef UART_H_
#define UART_H_

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include"uart_cfg.h"

/*******************************************************************************
 *                          Mapped Registers                                   *
 *******************************************************************************/
#define UART_UDR   (*(volatile uint8 *)0x002C)	/* USART I/O Data Register – UDR */
#define UART_UCSRA (*(volatile uint8 *)0x002B)	/* USART Control and Status Register A – UCSRA */
#define UART_UCSRB (*(volatile uint8 *)0x002A)	/* USART Control and Status Register B – UCSRB */
#define UART_UCSRC (*(volatile uint8 *)0x0040)	/* USART Control and Status Register C – UCSRC */
#define UART_UBRRH (*(volatile uint8 *)0x0040)	/* USART Baud Rate Registers – UBRRH */
#define UART_UBRRL (*(volatile uint8 *)0x0029)	/* USART Baud Rate Registers – UBRRL */

/*******************************************************************************
 *                          Registers Pins                                     *
 *******************************************************************************/

/**************************** UCSRA PINS ***************************************/
#define UART_RXC  (7u)		/*Bit 7 – RXC: USART Receive Complete*/
#define UART_TXC  (6u)		/*Bit 6 – TXC: USART Transmit Complete*/
#define UART_UDRE (5u)		/*Bit 5 – UDRE: USART Data Register Empty*/
#define UART_FE   (4u)		/*Bit 4 – FE: Frame Error*/
#define UART_DOR  (3u)		/*Bit 3 – DOR: Data OverRun*/
#define UART_PE   (2u)		/*Bit 2 – PE: Parity Error*/
#define UART_U2X  (1u)		/*Bit 1 – U2X: Double the USART Transmission Speed*/
#define UART_MPCM (0u)		/*Bit 0 – MPCM: Multi-processor Communication Mode*/

/**************************** UCSRB PINS ***************************************/
#define UART_RXCIE  (7u)		/*Bit 7 – RXCIE: RX Complete Interrupt Enable*/
#define UART_TXCIE  (6u)		/*Bit 6 – TXCIE: TX Complete Interrupt Enable*/
#define UART_UDRIE  (5u)		/*Bit 5 – UDRIE: USART Data Register Empty Interrupt Enable*/
#define UART_RXEN   (4u)		/*Bit 4 – RXEN: Receiver Enable*/
#define UART_TXEN   (3u)		/*Bit 3 – TXEN: Transmitter Enable*/
#define UART_UCSZ2  (2u)		/*Bit 2 – UCSZ2: Character Size*/
#define UART_RXB8   (1u)		/*Bit 1 – RXB8: Receive Data Bit 8*/
#define UART_TXB8   (0u)		/*Bit 0 – TXB8: Transmit Data Bit 8*/

/**************************** UCSRC PINS ***************************************/
#define UART_URSEL  (7u)		/*Bit 7 – URSEL: Register Select*/
#define UART_UMSEL  (6u)		/*Bit 6 – UMSEL: USART Mode Select*/
#define UART_UPM1   (5u)		/*Bit 5 – UPM1: Parity Mode*/
#define UART_UPM0   (4u)		/*Bit 4 – UPM0: Parity Mode*/
#define UART_USBS   (3u)		/*Bit 3 – USBS: Stop Bit Select*/
#define UART_UCSZ1  (2u)		/*Bit 2 – UCSZ1: Character Size*/
#define UART_UCSZ0  (1u)		/*Bit 1 – UCSZ0: Character Size*/
#define UART_UCPOL  (0u)		/*Bit 0 – UCPOL: Clock Polarity*/

/*******************************************************************************
 *                      Functions Prototypes                                   *
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
extern Status UART_Init(void);

/*******************************************************************************
 * Function Name:	UART_SendChar
 *
 * Description: 	transmit a new byte
 *
 * Inputs:			Transmitted Byte
 *
 * Outputs:			NULL
 *
 * Return:			Status to check function execution
 *******************************************************************************/
extern Status UART_SendChar(const uint8 a_data);

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
extern Status UART_Send(const uint8 * a_data_ptr);

/*******************************************************************************
 * Function Name:	UART_Start
 *
 * Description: 	Start transmitting or Receiving
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			Status to check function execution
 *******************************************************************************/
extern Status UART_Start(void);

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
extern Status UART_Stop(void);

#endif /* UART_H_ */
