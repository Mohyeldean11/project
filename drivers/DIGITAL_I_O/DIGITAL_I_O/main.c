/*
 * GccApplication2.c
 *
 * Created: 6/7/2021 4:00:04 PM
 * Author : mohye
 */ 

#include <avr/io.h>
#include "Lbit_math.h"
#include "lstd_types.h"
#include "DIO_NITERFACE.h"

int main(void)
{
	set_pin_status(PORTC,PIN0|PIN7,OUTPUT);
	set_pin_value(PORTC,PIN0|PIN7,HIGH);
	set_pin_status(PORTB,PIN1,OUTPUT);
	set_pin_value(PORTB,PIN1,HIGH);
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

