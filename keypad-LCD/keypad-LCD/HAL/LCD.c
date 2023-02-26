/*
 * LCD.c
 *
 * Created: 1/23/2023 11:05:26 AM
 *  Author: Ahmed Saber
 */ 

#include "LCD.h"

//4bit\\\/
void LCD_F_init()
{
	DIO_F_Set_Pin_Dir(LCD_Control_Port,LCD_E_PIN,OUTPUT);
	DIO_F_Set_Pin_Dir(LCD_Control_Port,LCD_RS_PIN,OUTPUT);
	DIO_F_Set_Pin_Dir(LCD_Control_Port,LCD_RW_PIN,OUTPUT);
	
	DIO_F_Set_Pin_Dir(LCD_Data_Port,PIN7,OUTPUT);
	DIO_F_Set_Pin_Dir(LCD_Data_Port,PIN6,OUTPUT);
	DIO_F_Set_Pin_Dir(LCD_Data_Port,PIN5,OUTPUT);
	DIO_F_Set_Pin_Dir(LCD_Data_Port,PIN4,OUTPUT);
	
	_delay_ms(50);
	///function set//
	LCD_F_Write_command(0x02);
	LCD_F_Write_command(0x28);
	_delay_ms(1);
	////Display on\off//
	LCD_F_Write_command(0x0F);
	_delay_ms(1);
	//clear display//
	LCD_F_Write_command(0x01);
	_delay_ms(2);
	//entry mode //
	LCD_F_Write_command(0x06);
	

}
void LCD_F_Write_command(U8_t command)
{
	DIO_F_Set_Pin_Val(LCD_Control_Port,LCD_RS_PIN,LOW);
	DIO_F_Set_Pin_Val(LCD_Control_Port,LCD_RW_PIN,LOW);
	DIO_F_Set_Port_Val(LCD_Data_Port,command & 0xF0);
	Tragger();
	DIO_F_Set_Port_Val(LCD_Data_Port,command <<4);
	Tragger();
}
void LCD_F_Write_Data(U8_t data)
{
	DIO_F_Set_Pin_Val(LCD_Control_Port,LCD_RS_PIN,HIGH);
	DIO_F_Set_Pin_Val(LCD_Control_Port,LCD_RW_PIN,LOW);
	DIO_F_Set_Port_Val(LCD_Data_Port,data & 0xF0);
	Tragger();
	DIO_F_Set_Port_Val(LCD_Data_Port,data <<4);
	Tragger();
}
void Tragger()
{
	DIO_F_Set_Pin_Val(LCD_Control_Port,LCD_E_PIN,HIGH);
	_delay_ms(1);
	DIO_F_Set_Pin_Val(LCD_Control_Port,LCD_E_PIN,LOW);
	_delay_ms(1);
}
void LCD_F_Write_String(U8_t* ptr)
{
	while (*ptr != '\0')
	{
		LCD_F_Write_Data(*ptr);
		_delay_ms(50);
		ptr++;
		
	}
	
}
void LCD_F_Write_Number(S32_t num)
{
	U8_t rem, i = 0, arr[10];
	S8_t j;
	if(num == 0)
	{
		LCD_F_Write_Data('0');
		return;
	}
	else if(num < 0)
	{
		LCD_F_Write_Data('-');
		num *= -1;
	}
	
	while(num > 0)
	{
		rem = num % 10;
		rem = rem + '0';
		arr[i] = rem;
		i++;
		num = num / 10;
	}
	for(j=i-1; j>=0; j--)
	{
		LCD_F_Write_Data(arr[j]);
	}
	
}

void LCD_F_Go_To(U8_t row, U8_t col)
{
	U8_t r = 0;
	U8_t c = 0;
	
	if( (row>0) && (row<5) && (col>0) && (col<21) )
	{
		if (1 == row)
		{
			c = (0x80 + col - 1);
		}
		else if (2 == row)
		{
			c = (0xC0 + col - 1);
		}
		else if (3 == row)
		{
			c = (0x90 + col - 1);
		}
		else
		{
			c = (0xD0 + col - 1);
		}
	}
	else
	{
		c = 0x80;
	}
	LCD_F_Write_command(c);
}
void LCD_clear_screen(void)
{
	LCD_F_Write_command(0x1);
	_delay_ms(2);
}
