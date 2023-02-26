/*
 * safe.c
 *
 * Created: 2/25/2023 1:32:55 PM
 *  Author: Ahmed Saber
 */ 
#include "safe.h"


U8_t safe_pass_status(U16_t address)
{
	U8_t password_status = 0;
	password_status = EEPROM_read(address);
	return password_status;
}


U32_t safe_read_pass(U16_t* address)
{
	U32_t pass_value = 0;
	pass_value = (U8_t)EEPROM_read(*(address+0));
	pass_value <<= 8;
	pass_value |= (U8_t)EEPROM_read(*(address+1));
	pass_value <<= 8;
	pass_value |= (U8_t)EEPROM_read(*(address+2));
	pass_value <<= 8;
	pass_value |= (U8_t)EEPROM_read(*(address+3));
	return pass_value;
}

void safe_set_pass(U8_t* pass, U16_t* address, U16_t pass_status)
{
	U8_t i = 0, digit = 0;
	LCD_clear_screen();
	LCD_F_Write_String("Set 8-b password");
	LCD_F_Go_To(2,1);
	for(i=0; i<6; ++i)
	{
		do
		{
			digit = KPAD_F_Get_Key();
		} while ( digit == 'N' );
		
		LCD_F_Write_Data(digit);
		_delay_ms(500);
		LCD_F_Go_To(2, 1+i);
		LCD_F_Write_Data('*');
		EEPROM_write(address[i], digit-48);
	}
	
	EEPROM_write(pass_status, 0x00);  
	LCD_F_Go_To(3, 1);
	LCD_F_Write_String("Password saved");
	_delay_ms(2000);
}

U8_t safe_check_pass(U16_t* address)
{
	U8_t flag = 0xff, digit = 'N';
	U8_t password1[6] = {0}, password2[6] = {0};
	U8_t i=0;

	LCD_clear_screen();
	LCD_F_Write_String("Enter password:");
	LCD_F_Go_To(2,1);
	
	for(i=0; i<6; ++i)
	{
		do
		{
			digit = KPAD_F_Get_Key();
		} while ( digit == 'N' );
		
		LCD_F_Write_Data(digit);
		_delay_ms(500);
		LCD_F_Go_To(2, 1+i);
		LCD_F_Write_Data('*');
		password1[i] = EEPROM_read(address[i]);
		password2[i] = (digit - 48);
	}
	
	for (i=0; i<6; ++i)
	{
		if (password1[i] != password2[i])
		{
			flag = 0x00;
		}
		else
		{
			flag = 0xff;
			
		}
	}
	
	return flag;
}