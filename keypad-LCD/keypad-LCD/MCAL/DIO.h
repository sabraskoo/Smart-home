/*
 * DIO.h
 *
 * Created: 1/19/2023 2:34:10 PM
 *  Author: Ahmed Saber
 */ 


#include "BIT_MATH.h"
#include "MEIN_MEM.h"
#include "TYPE_DEFINTIONS.h"

#ifndef DIO_H_
#define DIO_H_

#define GA		0
#define GB		1
#define GC		2
#define GD		3

#define PIN0	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5	5
#define PIN6	6
#define PIN7	7

#define INPUT	0
#define OUTPUT	1

#define LOW		0
#define HIGH	1





void DIO_F_Set_Pin_Val(U8_t group, U8_t pin_Number, U8_t val);
void DIO_F_Set_Pin_Dir(U8_t group, U8_t pin_Number, U8_t dir);
U8_t DIO_F_Get_Pin_Val(U8_t group, U8_t pin_Number);
void DIO_F_Set_Port_Dir(U8_t group, U8_t dir);
void DIO_F_Set_Port_Val(U8_t group, U8_t val);
U8_t DIO_F_Get_Port_Val(U8_t group);
void DIO_F_Toggle_Pin(U8_t group, U8_t pin_Number);




#endif /* DIO_H_ */