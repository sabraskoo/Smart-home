/*
 * keypad.c
 *
 * Created: 1/23/2023 12:10:21 PM
 *  Author: Ahmed Saber
 */ 
#include "keypad.h"
#define ROWS 4
#define COLS 4

static U8_t key_Array[ROWS][COLS] = {
	{'7','8','9','/'},
	{'4','5','6',')'},
	{'1','2','3','-'},
	{'*','0','=','+'},
};
void KPAD_F_Init(void)
{
	DIO_F_Set_Pin_Dir(ROW_PORT, R0_PIN, OUTPUT);
	DIO_F_Set_Pin_Dir(ROW_PORT, R1_PIN, OUTPUT);
	DIO_F_Set_Pin_Dir(ROW_PORT, R2_PIN, OUTPUT);
	DIO_F_Set_Pin_Dir(ROW_PORT, R3_PIN, OUTPUT);
	
	DIO_F_Set_Pin_Dir(COL_PORT, C0_PIN,	INPUT);
	DIO_F_Set_Pin_Dir(COL_PORT, C1_PIN,	INPUT);
	DIO_F_Set_Pin_Dir(COL_PORT, C2_PIN,	INPUT);
	DIO_F_Set_Pin_Dir(COL_PORT, C3_PIN,	INPUT);
	
	DIO_F_Set_Pin_Val(COL_PORT, C0_PIN,	HIGH); // input pull up
	DIO_F_Set_Pin_Val(COL_PORT, C1_PIN,	HIGH);
	DIO_F_Set_Pin_Val(COL_PORT, C2_PIN,	HIGH);
	DIO_F_Set_Pin_Val(COL_PORT, C3_PIN,	HIGH);
}

U8_t KPAD_F_Get_Key(void)
{
	U8_t r, c, key = 'N';
	
	DIO_F_Set_Pin_Val(ROW_PORT, R0_PIN,	HIGH); // deactivated
	DIO_F_Set_Pin_Val(ROW_PORT, R1_PIN,	HIGH); // deactivated
	DIO_F_Set_Pin_Val(ROW_PORT, R2_PIN,	HIGH); // deactivated
	DIO_F_Set_Pin_Val(ROW_PORT, R3_PIN,	HIGH); // deactivated
	
	for(r=0; r<ROWS; r++)
	{
		//activation
		DIO_F_Set_Pin_Val(ROW_PORT, R0_PIN+r, LOW);

		for(c=0; c<COLS; c++)
		{
			if(DIO_F_Get_Pin_Val(COL_PORT, C0_PIN+c) == LOW)
			{
				key = key_Array[r][c];
				while(DIO_F_Get_Pin_Val(COL_PORT, C0_PIN+c) == LOW);
			}
		}
		//deactivation
		DIO_F_Set_Pin_Val(ROW_PORT, R0_PIN+r, HIGH);
		
	}
	
	return key;
	
}
