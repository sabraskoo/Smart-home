/*
 * internalEEPROM.h
 *
 * Created: 2/25/2023 1:35:30 PM
 *  Author: Ahmed Saber
 */ 


#ifndef INTERNALEEPROM_H_
#define INTERNALEEPROM_H_

#include "TYPE_DEFINTIONS.h"
#include "BIT_MATH.h"
#include <avr/io.h>

void EEPROM_write(U16_t address, U8_t data);

U8_t EEPROM_read(U16_t address);

#endif /* INTERNALEEPROM_H_ */