/*
 * DIO.c
 *
 * Created: 1/19/2023 2:34:01 PM
 *  Author: Ahmed Saber
 */ 
#include "DIO.h"

void DIO_F_Set_Pin_Val(U8_t group, U8_t pin_Number, U8_t val)
{
	switch(val)
	{
		case LOW:  
		switch(group)
		{
			case GA:
			CLR_BIT(PORTA, pin_Number);
			break;
			case GB:
			CLR_BIT(PORTB, pin_Number);
			break;
			case GC:
			CLR_BIT(PORTC, pin_Number);
			break;
			case GD:
			CLR_BIT(PORTD, pin_Number);
			break;
		}
		break;
		case HIGH:
		switch(group)
		{
			case GA:
			SET_BIT(PORTA, pin_Number);
			break;
			case GB:
			SET_BIT(PORTB, pin_Number);
			break;
			case GC:
			SET_BIT(PORTC, pin_Number);
			break;
			case GD:
			SET_BIT(PORTD, pin_Number);
			break;
		}
		break;
		
	}
}

void DIO_F_Set_Pin_Dir(U8_t group, U8_t pin_Number, U8_t dir)
{
	switch(dir)
	{
		case INPUT:  
		switch(group)
		{
			case GA:
			CLR_BIT(DDRA, pin_Number);
			break;
			case GB:
			CLR_BIT(DDRB, pin_Number);
			break;
			case GC:
			CLR_BIT(DDRC, pin_Number);
			break;
			case GD:
			CLR_BIT(DDRD, pin_Number);
			break;
		}
		break;
		case OUTPUT:
		switch(group)
		{
			case GA:
			SET_BIT(DDRA, pin_Number);
			break;
			case GB:
			SET_BIT(DDRB, pin_Number);
			break;
			case GC:
			SET_BIT(DDRC, pin_Number);
			break;
			case GD:
			SET_BIT(DDRD, pin_Number);
			break;
		}
		break;
		
	}
}


U8_t DIO_F_Get_Pin_Val(U8_t group, U8_t pin_Number)
{
	switch(group)
	{
		case GA:
		return GET_BIT(PINA, pin_Number);
		break;
		case GB:
		return GET_BIT(PINB, pin_Number);
		break;
		case GC:
		return GET_BIT(PINC, pin_Number);
		break;
		case GD:
		return GET_BIT(PIND, pin_Number);
		break;
	}
}



void DIO_F_Set_Port_Dir(U8_t group, U8_t dir)
{
	switch(dir)
	{
		case INPUT:
		switch(group)
		{
			case GA:
			DDRA = 0x00;
			break;
			case GB:
			DDRB = 0x00;
			break;
			case GC:
			DDRC = 0x00;
			break;
			case GD:
			DDRD = 0x00;
			break;
		}
		break;
		case OUTPUT:
		switch(group)
		{
			case GA:
			DDRA = 0xFF;
			break;
			case GB:
			DDRB = 0xFF;
			break;
			case GC:
			DDRC = 0xFF;
			break;
			case GD:
			DDRD = 0xFF;
			break;
		}
		break;
	}
}


void DIO_F_Set_Port_Val(U8_t group, U8_t val)
{
	switch(group)
	{
		case GA:
		PORTA = val;
		break;
		case GB:
		PORTB = val;
		break;
		case GC:
		PORTC = val;
		break;
		case GD:
		PORTD = val;
		break;
	}
}


U8_t DIO_F_Get_Port_Val(U8_t group)
{
	switch(group)
	{
		case GA:
		return PINA;
		break;
		case GB:
		return PINB;
		break;
		case GC:
		return PINC;
		break;
		case GD:
		return PIND;
		break;
	}
}

void DIO_F_Toggle_Pin(U8_t group, U8_t pin_Number)
{
	switch(group)
	{
		case GA:
		TOGGLE_BIT(PORTA, pin_Number);
		break;
		case GB:
		TOGGLE_BIT(PORTB, pin_Number);
		break;
		case GC:
		TOGGLE_BIT(PORTC, pin_Number);
		break;
		case GD:
		TOGGLE_BIT(PORTD, pin_Number);
		break;
	}
}