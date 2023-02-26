/*
 * ADC.c
 *
 * Created: 1/28/2023 3:07:33 PM
 *  Author: Ahmed Saber
 */ 

#include "ADC.h"
void ADC_F_Init(void)
{
	
	CLR_BIT(DDRA, 1); 
	ADCSRA &= 0b11111000;
	ADCSRA |= 0x07;
	SET_BIT(ADMUX, 6);
	SET_BIT(ADCSRA, 3);
	SET_BIT(ADCSRA, 7);
}

U16_t ADC_F_Read(void)
{
	SET_BIT(ADMUX, 0);
	SET_BIT(ADCSRA, 6); 
	return ADCL | ADCH<<8;
}