/*
 * UART.c
 *
 * Created: 6/9/2021 1:59:50 AM
 * Author : mohye
 */ 

#include <avr/io.h>
#include "Lbit_math.h"
#include "lstd_types.h"
#include "UART_INTERFACE.h"
#include "DIO_NITERFACE.h"
#define	F_CPU	16000000UL

int main(void)
{
	u8_t data;
	set_pin_status(PORTD,PIN0,INPUT_FLOAT);
	set_pin_status(PORTD,PIN1,OUTPUT);
	set_pin_status(PORTC,PIN0,OUTPUT);
    UART_INIT(BAUD_RATE_9600);
    while (1) 
    {
			UART_RECEIVE_DATA(&data);
			if(data == 'a')
			{
				set_pin_value(PORTC,PIN0,HIGH);
			}
			if(data == 'b')
			{
				set_pin_value(PORTB,PIN1,HIGH);
			}
    }
}

