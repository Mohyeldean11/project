/*
 * DIONITERFACE.h
 *
 * Created: 6/7/2021 7:09:21 PM
 *  Author: mohye
 */ 


#ifndef DIONITERFACE_H_
#define DIONITERFACE_H_

/************************************************************************/
/*					MACROS                                              */
/************************************************************************/

/*PORTS*/
#define PORTA	(0)
#define PORTB	(1)
#define PORTC	(2)
#define PORTD	(3)

/*PINS*/
#define PIN0         (0b00000001)
#define PIN1         (0b00000010)
#define PIN2         (0b00000100)
#define PIN3         (0b00001000)
#define PIN4         (0b00010000)
#define PIN5         (0b00100000)
#define PIN6         (0b01000000)
#define PIN7         (0b10000000)


/*PORT Pins' status*/
#define OUTPUT       (0)
#define INPUT_FLOAT  (1)
#define INPUT_PULLUP (2)

/*PIN VALUE*/
#define HIGH		(1)
#define LOW			(0)

/************************************************************************/
/*                            FUNCTION PROTOTYPES                       */
/************************************************************************/

void set_pin_status(u8_t au8_port, u8_t au8_pin ,u8_t au8_status);			 //this function is to set the pin  status to INPUT FLOAT,OUTPUT OR INPUT PULLUP.

void set_pin_value(u8_t au8_port, u8_t au8_pin ,u8_t au8_value);			//this function is to set the pin  value to HIGH OR LOW.

void toggle_pin(u8_t au8_port,u8_t au8_pin);								//this function is to toggle the pin value from its current value.

u8_t get_pin(u8_t au8_port,u8_t au8_pin);									//this function is to get the pin current value.


#endif /* DIONITERFACE_H_ */