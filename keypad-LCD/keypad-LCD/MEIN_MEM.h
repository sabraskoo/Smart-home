/*
 * MEIN_MEM.h
 *
 * Created: 1/19/2023 2:26:00 PM
 *  Author: Ahmed Saber
 */ 


#ifndef MEIN_MEM_H_
#define MEIN_MEM_H_
/********************DIO*****************/
#define DDRA  *(volatile U8_t*)0x3A
#define PORTA *(volatile U8_t*)0X3B
#define PINA  *(volatile U8_t*)0x39

#define DDRB  *(volatile U8_t*)0x37
#define PORTB *(volatile U8_t*)0X38
#define PINB  *(volatile U8_t*)0X36


#define DDRC  *(volatile U8_t*)0x34
#define PORTC *(volatile U8_t*)0X35
#define PINC  *(volatile U8_t*)0X33


#define DDRD  *(volatile U8_t*)0x31
#define PORTD *(volatile U8_t*)0X32
#define PIND  *(volatile U8_t*)0X30

/********************ADC*****************/
#define ADMUX   *(volatile U8_t*)0x27
#define ADCSRA  *(volatile U8_t*)0X26
#define ADCH    *(volatile U8_t*)0x25
#define ADCL    *(volatile U8_t*)0x24

/********************INTERRUPT*****************/
#define ISR(x)	void x(void)  __attribute__((signal));\
				void x(void)

//
//#define EXTI0_vector		__vector_1
//#define EXTI1_vector		__vector_2
//#define EXTI2_vector		__vector_3

#define ADC_vector			__vector_16

/********************EX_INTERRUPT*****************/
 #define MCUCR	*(volatile U8_t*)0x55
 #define MCUCSR *(volatile U8_t*)0x54
 #define GICR	*(volatile U8_t*)0x5B
 #define GIFR	*(volatile U8_t*)0x5A



#endif /* MEIN_MEM_H_ */