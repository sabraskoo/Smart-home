/*
 * keypad.h
 *
 * Created: 1/23/2023 12:10:04 PM
 *  Author: Ahmed Saber
 */ 

#include "DIO.h"

#ifndef KEYPAD_H_
#define KEYPAD_H_


#include "DIO.h"

#define R0_PIN PIN4
#define R1_PIN PIN5
#define R2_PIN PIN6
#define R3_PIN PIN7

#define ROW_PORT GC

#define C0_PIN PIN3
#define C1_PIN PIN4
#define C2_PIN PIN5
#define C3_PIN PIN6

#define COL_PORT GD

void KPAD_F_Init(void);
U8_t KPAD_F_Get_Key(void);


#endif /* KEYPAD_H_ */