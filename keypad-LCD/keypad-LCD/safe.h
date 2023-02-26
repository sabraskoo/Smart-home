/*
 * safe.h
 *
 * Created: 2/25/2023 1:32:32 PM
 *  Author: Ahmed Saber
 */ 


#ifndef SAFE_H_
#define SAFE_H_

#include "LCD.h"
#include "keypad.h"
#include "internalEEPROM.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


U8_t safe_pass_status(U16_t address);
U32_t safe_read_pass(U16_t* address);
void safe_set_pass(U8_t* pass, U16_t* address, U16_t pass_status);
U8_t safe_check_pass(U16_t* address);




#endif /* SAFE_H_ */