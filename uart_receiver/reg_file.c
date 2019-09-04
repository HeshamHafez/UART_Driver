/*
 * reg_file.c
 *
 *  Created on: Aug 17, 2019
 *      Author: hesha
 */

#include"reg_file.h"

void DIO_WritePin(uint8 PinNum,uint8 PinValue)
{
	if((PinNum >= PIN0) && (PinNum <= PIN7))
	{
		if(PinValue == 0)
		{
			CLEAR_BIT(DIO_PORTA,PinNum);
		}
		else
		{
			SET_BIT(DIO_PORTA,PinNum);
		}
	}
	else if((PinNum >= PIN8) && (PinNum <= PIN15))
	{
		PinNum = PinNum - 8;
		if(PinValue == 0)
		{
			CLEAR_BIT(DIO_PORTB,PinNum);
		}
		else
		{
			SET_BIT(DIO_PORTB,PinNum);
		}

	}
	else if((PinNum >= PIN16) && (PinNum <= PIN23))
	{
		PinNum = PinNum - 16;
		if(PinValue == 0)
		{
			CLEAR_BIT(DIO_PORTC,PinNum);
		}
		else
		{
			SET_BIT(DIO_PORTC,PinNum);
		}

	}
	else if((PinNum >= PIN24) && (PinNum <= PIN31))
	{
		PinNum = PinNum - 24;
		if(PinValue == 0)
		{
			CLEAR_BIT(DIO_PORTD,PinNum);
		}
		else
		{
			SET_BIT(DIO_PORTD,PinNum);
		}

	}
}

uint8 DIO_ReadPin(uint8 PinNum)
{
	uint8 value;
	if((PinNum >= PIN0) && (PinNum <= PIN7))
	{
		value = IS_BIT_SET(DIO_PINA,PinNum);
	}

	else if((PinNum >= PIN8) && (PinNum <= PIN15))
	{
		PinNum = PinNum -8;
		value = IS_BIT_SET(DIO_PINB,PinNum);

	}
	else if((PinNum >= PIN16) && (PinNum <= PIN23))
	{
		PinNum = PinNum -16;
		value = IS_BIT_SET(DIO_PINC,PinNum);

	}
	else if((PinNum >= PIN24) && (PinNum <= PIN31))
	{
		PinNum = PinNum -24;
		value = IS_BIT_SET(DIO_PIND,PinNum);
	}

	if(value != 0)
	{
		value = 1;
	}
	return value;
}

void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection)
{
	if((PinNum >= PIN0) && (PinNum <= PIN7))
	{
		if(PinDirection == 0)
		{
			CLEAR_BIT(DIO_DDRA,PinNum);
		}
		else
		{
			SET_BIT(DIO_DDRA,PinNum);
		}
	}
	if((PinNum >= PIN8) && (PinNum <= PIN15))
	{
		PinNum = PinNum -8;
		if(PinDirection == 0)
		{
			CLEAR_BIT(DIO_DDRB,PinNum);
		}
		else
		{
			SET_BIT(DIO_DDRB,PinNum);
		}
	}
	if((PinNum >= PIN16) && (PinNum <= PIN23))
	{
		PinNum = PinNum - 16;
		if(PinDirection == 0)
		{
			CLEAR_BIT(DIO_DDRC,PinNum);
		}
		else
		{
			SET_BIT(DIO_DDRC,PinNum);
		}
	}
	if((PinNum >= PIN24) && (PinNum <= PIN31))
	{
		PinNum = PinNum - 24;
		if(PinDirection == 0)
		{
			CLEAR_BIT(DIO_DDRD,PinNum);
		}
		else
		{
			SET_BIT(DIO_DDRD,PinNum);
		}
	}

}






