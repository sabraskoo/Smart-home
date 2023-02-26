/*
 * DCM.c
 *
 * Created: 2/5/2023 12:00:23 PM
 *  Author: Ahmed Saber
 */ 
#include "DCM.h"
void Motor_F_init()
{
	DIO_F_Set_Pin_Dir(Motor_port,Motor_PinA,OUTPUT);
	DIO_F_Set_Pin_Dir(Motor_port,Motor_PinB,OUTPUT);
}
void Motor_F_ON()
{
	DIO_F_Set_Pin_Dir(Motor_port,Motor_PinA,LOW);
	DIO_F_Set_Pin_Dir(Motor_port,Motor_PinB,HIGH);
}

void Motor_F_OFF()
{
	DIO_F_Set_Pin_Dir(Motor_port,Motor_PinA,LOW);
	DIO_F_Set_Pin_Dir(Motor_port,Motor_PinB,LOW);
}