/*
 * internalEEPROM.c
 *
 * Created: 2/25/2023 1:35:51 PM
 *  Author: Ahmed Saber
 */ 
#include "internalEEPROM.h"

void EEPROM_write(U16_t address, U8_t data)
{
	while (READ_BIT(EECR,EEWE))
	{	
	}
	while (READ_BIT(SPMCR,SPMEN))
	{
	}
	EEARL = (U8_t) address;
	EEARH = (U8_t) (address>>8);
	EEDR = data;
	SET_BIT(EECR,EEMWE);
	SET_BIT(EECR,EEWE);
	while (READ_BIT(EECR,EEWE))
	{
	}
}


U8_t EEPROM_read(U16_t address)
{
	U8_t data = 0;
	while (READ_BIT(EECR,EEWE))
	{
	}
	EEARL = (U8_t) address;
	EEARH = (U8_t) (address>>8);
	SET_BIT(EECR,EERE);
	data = EEDR;
	return data;
}