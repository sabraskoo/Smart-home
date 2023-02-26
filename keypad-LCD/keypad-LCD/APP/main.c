/*
 * keypad-LCD.c
 *
 * Created: 1/23/2023 10:32:18 AM
 * Author : Ahmed Saber
 */ 

//#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>
#include "MEIN_MEM.h"
#include "DIO.h"
#include "LCD.h"
#include "DCM.h"
#include "SERV.h"
#include "ADC.h"
#include "EXIT.h"
#include "safe.h"


volatile U16_t ADC_Global = 0;

U16_t  adc;
U16_t f_loged=0;
#define MAX_TRIES 3


int main(void)
{
	U8_t key;
	U16_t ct_L_blue=0,ct_l_yell=0,ct_L_green=0,ct_door=0,z;
	U16_t adc_val=47 ,adc_f=0,alarm_f=0;
	
	
	U8_t ui[10],i=0,up[10],j=0;
	U8_t user_id,user_pass,f_id=0,f_pass=0;
	U8_t flag = 0x00, count = 0, pass_status = 0;
	U16_t set_pass = 0x76; //in this address will write '0' (pass set) or 0xff (pass not set)
	U16_t address[4] = {0x7A, 0x7B, 0x7C, 0x7D}; //addresses where password will be stored
	U8_t password[6];



	LCD_F_init();
	ADC_F_Init();
	KPAD_F_Init();
	Motor_F_init();
	SERV_F_INIT();
	
	//alarm
	DIO_F_Set_Pin_Dir(GA,PIN0,OUTPUT);
	//led
	DIO_F_Set_Pin_Dir(GC,PIN0,OUTPUT);
	DIO_F_Set_Pin_Dir(GC,PIN1,OUTPUT);
	DIO_F_Set_Pin_Dir(GC,PIN2,OUTPUT);

	pass_status = safe_pass_status(set_pass);
	if (0xff == pass_status)
	{
		DIO_F_Set_Pin_Val(PORTD,PIN1,HIGH);
		DIO_F_Set_Pin_Val(PORTD,PIN0,LOW);
		safe_set_pass(password, address, set_pass);
	}
	while( (0x00 == flag) && (count < MAX_TRIES) )
	{
		count++;
		flag = safe_check_pass(address);
		if (0xff == flag)
		{
			LCD_clear_screen();
			LCD_F_Write_String("Correct password");
			LCD_F_Go_To(2,1);
			LCD_F_Write_String("Safe is opened");
			f_loged=1;
			alarm_f=2;
			break;
		}
		else
		{
			LCD_clear_screen();
			LCD_F_Write_String("Incorrect pass");
			LCD_F_Go_To(2,1);
			LCD_F_Write_String("Safe is closed");
			LCD_F_Go_To(2,1);
			LCD_F_Write_String("Tries left: ");
			LCD_F_Write_Data(48+(MAX_TRIES-count));
			if (MAX_TRIES-count==0)
			{
				alarm_f=1;
			}
			
		}
		_delay_ms(2000);
	}
	
	LCD_F_Go_To(0,0);
	LCD_clear_screen();
	while(1)
	{
		if (alarm_f == 1)
		{
			DIO_F_Set_Pin_Val(GA,PIN0,HIGH);
		}
		
		
		
		key = KPAD_F_Get_Key();
		adc=ADC_F_Read();
		
		if (adc > adc_val)
		{
			if (adc > 47)
			{
				adc_f = 1;
				adc_val = adc;
			}
		}
		else if (adc < adc_val)
		{
			if (adc < 47)
			{
				adc_f =2;
				adc_val = adc;
			}
		}		
		if(key != 'N')
		{
			
			if (f_loged == 1)
			{
				DIO_F_Set_Pin_Val(GB,PIN3,HIGH);

				if (key == '/')
				{
					ct_L_blue+=1;
				}
				if (ct_L_blue==1)
				{
					LCD_F_Go_To(0,0);

					LCD_F_Write_String("blue led is on ");
					
					DIO_F_Set_Pin_Val(GC,PIN0,HIGH);
					_delay_ms(500);
					LCD_F_Go_To(0,0);
					LCD_F_Write_String("                  ");
				}
				if (ct_L_blue==2)
				{
					LCD_F_Go_To(0,0);
					DIO_F_Set_Pin_Val(GC,PIN0,LOW);
					LCD_F_Go_To(0,0);
					LCD_F_Write_String("blue led is off ");
					ct_L_blue=0;
					_delay_ms(500);
					LCD_F_Go_To(0,0);
					LCD_F_Write_String("                  ");
				}
				
				if (key == ')')
				{
					ct_l_yell+=1;
				}
				if (ct_l_yell==1)
				{
					LCD_F_Go_To(0,0);
					LCD_F_Write_String("yellow led is on ");
					DIO_F_Set_Pin_Val(GC,PIN1,HIGH);
					_delay_ms(500);
					LCD_F_Go_To(0,0);
					LCD_F_Write_String("                  ");
				}
				if (ct_l_yell==2)
				{
					LCD_F_Go_To(0,0);
					
					DIO_F_Set_Pin_Val(GC,PIN1,LOW);
					LCD_F_Go_To(0,0);
					LCD_F_Write_String("yellow led is off ");
					ct_l_yell=0;
					_delay_ms(500);
					LCD_F_Go_To(0,0); 
					LCD_F_Write_String("                  ");
				}
				if (key == '-')
				{
					ct_L_green+=1;
				}
				if (ct_L_green==1)
				{
					LCD_F_Go_To(0,0);
					LCD_F_Write_String("green led is on ");
					DIO_F_Set_Pin_Val(GC,PIN2,HIGH);
					_delay_ms(500);
					LCD_F_Go_To(0,0);  
					LCD_F_Write_String("                     ");
				}
				if (ct_L_green==2)
				{
					LCD_F_Go_To(0,0);
					DIO_F_Set_Pin_Val(GC,PIN2,LOW);
					LCD_F_Go_To(0,0);
					LCD_F_Write_String("green led is off ");
					ct_L_green=0;
					_delay_ms(500);
					LCD_F_Go_To(0,0);  
					LCD_F_Write_String("                      ");
				}
				
				if (key == '+')
				{
					ct_door+=1;
				}
				if (ct_door==1)
				{
					LCD_F_Go_To(0,0);
					LCD_F_Write_String("Door is Unlock");
					SERV_F_ON();
					LCD_F_Go_To(0,0);
					LCD_F_Write_String("                    ");
					ct_door=0;
				}	
			}				
		}
		if (f_loged == 1 && adc_f == 1)
		{
			LCD_F_Go_To(0,0);
			//LCD_F_Write_String("             ");
			//LCD_F_Go_To(0,0);
			LCD_F_Write_String("ADC is on");
			Motor_F_ON();
			_delay_ms(500);
			LCD_F_Go_To(0,0);
			LCD_F_Write_String("              ");
			adc_f = 0;
		}
		if (f_loged == 1 && adc_f == 2)
		{
			LCD_F_Go_To(0,0);
			//LCD_F_Write_String("             ");
			//LCD_F_Go_To(0,0);
			LCD_F_Write_String("ADC is off");
			Motor_F_OFF();
			_delay_ms(500);
			LCD_F_Go_To(0,0);
			LCD_F_Write_String("              ");
			adc_f = 0;
		}
	}
}
