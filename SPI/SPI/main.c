/*
 * SPI.c
 *
 * Created: 6/10/2021 7:59:35 PM
 * Author : mohye
 */ 

#include <avr/io.h>
#include "lstd_types.h"
#include "Lbit_math.h"
#include "DIO_NITERFACE.h"
#include "SPI_interface.h"
#define F_CPU	16000000
#include "util/delay.h"

int main(void)
{
	u8_t	x;
	u8_t	y=8;
	set_pin_status(PORTA,PIN0,OUTPUT);
	set_pin_status(PORTB,PIN5,OUTPUT);
	set_pin_status(PORTB,PIN6,INPUT_FLOAT);
	set_pin_status(PORTB,PIN7,OUTPUT);
    spi_init(SPI_MASTER_DEVICE,SPI_MSB_FIRST,SPI_SAMPLE_R_SETUP_F,SPI_CLK_PRE_64);
 
    
		set_pin_value(PORTA,PIN0,LOW);
		spi_masterSendRecv(y,&x);
		set_pin_value(PORTA,PIN0,HIGH);
		_delay_ms(1000);
		set_pin_value(PORTA,PIN0,LOW);
		spi_masterSendRecv(y,&x);
		set_pin_value(PORTA,PIN0,HIGH);
		_delay_ms(1000);
  
}

