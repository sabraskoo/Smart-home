/*
 * SERV.h
 *
 * Created: 2/5/2023 12:46:36 PM
 *  Author: Ahmed Saber
 */ 

#define F_CPU 16000000
#include <util/delay.h>

#include "DIO.h"

#ifndef SERV_H_
#define SERV_H_



#define serv_port	GC
#define serv_pin	PIN3

void SERV_F_INIT();
void SERV_F_ON();


#endif /* SERV_H_ */