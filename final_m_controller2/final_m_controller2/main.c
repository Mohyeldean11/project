/*
 * final_m_controller2.c
 *
 * Created: 6/13/2021 2:02:06 AM
 * Author : mohye
 */ 

#include <avr/io.h>
#include "lstd_types.h"
#include "Lbit_math.h"
#include "DIO_NITERFACE.h"
#include "SPI_interface.h"

int main(void)
{
	/*a variable to receive the master data*/
	u8_t x;
	
	  /*setting the SPI pins*/	
	  set_pin_status(PORTB,PIN4,INPUT_FLOAT);
	  set_pin_status(PORTB,PIN5,INPUT_FLOAT);
	  set_pin_status(PORTB,PIN6,OUTPUT);
	  set_pin_status(PORTB,PIN7,INPUT_FLOAT);
	  
	  /*setting the LED PINS*/
	  set_pin_status(PORTD,PIN3,OUTPUT);
	  set_pin_status(PORTC,PIN2,OUTPUT);
	  
	  
	  /*initializing the SPI*/
	  spi_init(SPI_SLAVE_DEVICE,SPI_MSB_FIRST,SPI_SAMPLE_F_SETUP_R,SPI_CLK_PRE_64);
    
	
	while(1)
			{
	
				/*RECEIVING DATA FROM THE MASTER*/
				spi_slaveSendRecv(0,&x);
						
				if (x=='a')
				{
					set_pin_value(PORTD,PIN3,HIGH);
					set_pin_value(PORTC,PIN2,LOW);
				}
				else if(x=='b')
				{
					set_pin_value(PORTC,PIN2,HIGH);
					set_pin_value(PORTD,PIN3,LOW);
				}
			}
}

