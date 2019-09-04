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
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
/*******************************************************************************
 *                          Mapped Registers                                   *
 *******************************************************************************/
#define UDR   (*(volatile uint8 *)0x002C)	/* USART I/O Data Register – UDR */
#define UCSRA (*(volatile uint8 *)0x002B)	/* USART Control and Status Register A – UCSRA */
#define UCSRB (*(volatile uint8 *)0x002A)	/* USART Control and Status Register B – UCSRB */
#define UCSRC (*(volatile uint8 *)0x0040)	/* USART Control and Status Register C – UCSRC */
#define UBRRH (*(volatile uint8 *)0x0040)	/* USART Baud Rate Registers – UBRRH */
#define UBRRL (*(volatile uint8 *)0x0029)	/* USART Baud Rate Registers – UBRRL */

/*******************************************************************************
 *                          Registers Pins                                     *
 *******************************************************************************/

/**************************** UCSRA PINS ***************************************/
#define RXC  (7u)		/*Bit 7 – RXC: USART Receive Complete*/
#define TXC  (6u)		/*Bit 6 – TXC: USART Transmit Complete*/
#define UDRE (5u)		/*Bit 5 – UDRE: USART Data Register Empty*/
#define FE   (4u)		/*Bit 4 – FE: Frame Error*/
#define DOR  (3u)		/*Bit 3 – DOR: Data OverRun*/
#define PE   (2u)		/*Bit 2 – PE: Parity Error*/
#define U2X	 (1u)		/*Bit 1 – U2X: Double the USART Transmission Speed*/
#define MPCM (0u)		/*Bit 0 – MPCM: Multi-processor Communication Mode*/

/**************************** UCSRB PINS ***************************************/
#define RXCIE  (7u)		/*Bit 7 – RXCIE: RX Complete Interrupt Enable*/
#define TXCIE  (6u)		/*Bit 6 – TXCIE: TX Complete Interrupt Enable*/
#define UDRIE  (5u)		/*Bit 5 – UDRIE: USART Data Register Empty Interrupt Enable*/
#define RXEN   (4u)		/*Bit 4 – RXEN: Receiver Enable*/
#define TXEN   (3u)		/*Bit 3 – TXEN: Transmitter Enable*/
#define UCSZ2  (2u)		/*Bit 2 – UCSZ2: Character Size*/
#define RXB8   (1u)		/*Bit 1 – RXB8: Receive Data Bit 8*/
#define TXB8   (0u)		/*Bit 0 – TXB8: Transmit Data Bit 8*/

/**************************** UCSRC PINS ***************************************/
#define URSEL  (7u)		/*Bit 7 – URSEL: Register Select*/
#define UMSEL  (6u)		/*Bit 6 – UMSEL: USART Mode Select*/
#define UPM1   (5u)		/*Bit 5 – UPM1: Parity Mode*/
#define UPM0   (4u)		/*Bit 4 – UPM0: Parity Mode*/
#define USBS   (3u)		/*Bit 3 – USBS: Stop Bit Select*/
#define UCSZ1  (2u)		/*Bit 2 – UCSZ1: Character Size*/
#define UCSZ0  (1u)		/*Bit 1 – UCSZ0: Character Size*/
#define UCPOL  (0u)		/*Bit 0 – UCPOL: Clock Polarity*/

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
Status UART_Init(UART_cfg* a_UartCfg_ptr);


#endif /* UART_H_ */
