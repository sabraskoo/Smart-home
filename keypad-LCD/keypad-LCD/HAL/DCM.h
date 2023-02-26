/*
 * DCM.h
 *
 * Created: 2/5/2023 12:00:37 PM
 *  Author: Ahmed Saber
 */ 


#ifndef DCM_H_
#define DCM_H_
#include "DIO.h"

#define Motor_port	GB
#define Motor_PinA	PIN5
#define Motor_PinB	PIN6

void Motor_F_init();
void Motor_F_ON();
void Motor_F_OFF();



#endif /* DCM_H_ */