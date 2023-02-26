/*
 * BIT_MAP.h
 *
 * Created: 1/19/2023 2:25:30 PM
 *  Author: Ahmed Saber
 */ 


#ifndef BIT_MAP_H_
#define BIT_MAP_H_

#define SET_BIT(reg,bit)		(reg = reg |(1<<bit))
#define CLR_BIT(reg,bit)		(reg = reg &~ (1<<bit))
#define GET_BIT(reg,bit)		((reg & 1<<bit)>>bit)
#define TOGGLE_BIT(reg,bit)		(reg = reg ^(1<<bit))
#define READ_BIT(reg,bit)		((reg>>bit)&1)

#endif /* BIT_MAP_H_ */