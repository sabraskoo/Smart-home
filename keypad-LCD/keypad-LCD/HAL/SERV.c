/*
 * SERV.c
 *
 * Created: 2/5/2023 12:46:49 PM
 *  Author: Ahmed Saber
 */ 
#include "SERV.h"

void SERV_F_INIT()
{
	DIO_F_Set_Pin_Dir(serv_port,serv_pin,OUTPUT);
}
void SERV_F_ON()
{
	DIO_F_Set_Pin_Val(serv_port,serv_pin,HIGH);
	_delay_ms(1000);
	DIO_F_Set_Pin_Val(serv_port,serv_pin,LOW);
}