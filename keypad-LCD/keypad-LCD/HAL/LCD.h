/*
 * LCD.h
 *
 * Created: 1/23/2023 11:05:40 AM
 *  Author: Ahmed Saber
 */ 

#define F_CPU 16000000
#include <util/delay.h>
#include "DIO.h"


#ifndef LCD_H_
#define LCD_H_

#define LCD_RS_PIN			PIN0
#define LCD_RW_PIN			PIN1
#define LCD_E_PIN			PIN2

#define LCD_Data_Port		GA
#define LCD_Control_Port	GB

void LCD_F_init();
void LCD_F_Write_command(U8_t command);
void LCD_F_Write_Data(U8_t data);
void Tragger();
void LCD_F_Write_String(U8_t* ptr);
void LCD_F_Write_Number(S32_t number);

void LCD_F_Go_To(U8_t row, U8_t col);

#endif /* LCD_H_ */