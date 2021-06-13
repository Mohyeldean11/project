/*
 * final_m_controller1.c
 *
 * Created: 6/13/2021 1:05:54 AM
 * Author : mohye
 */ 

#include "Lbit_math.h"
#include "lstd_types.h"
#include "DIO_NITERFACE.h"
#include "UART_INTERFACE.h"
#include "SPI_interface.h"
#define F_CPU	16000000
#include "util/delay.h"
int main(void)
{
	/*VARIABLE TO RECEIVE DATA from UART*/
   u8_t	x;
   
   
   /*VARIABLE TO RECEIVE DATA from SLAVE*/
   u8_t y;
   
   
   /*setting the UART PINS*/
   set_pin_status(PORTD,PIN0,INPUT_FLOAT);
   set_pin_status(PORTD,PIN1,OUTPUT);
   
   
   /*setting the SPI PINS*/
   set_pin_status(PORTA,PIN0,OUTPUT);
   set_pin_status(PORTB,PIN5,OUTPUT);
   set_pin_status(PORTB,PIN6,INPUT_FLOAT);
   set_pin_status(PORTB,PIN7,OUTPUT);
 
   /*initializing the UART*/
   UART_INIT(BAUD_RATE_9600);
   
   
   /*initializing the SPI*/
   spi_init(SPI_MASTER_DEVICE,SPI_MSB_FIRST,SPI_SAMPLE_F_SETUP_R,SPI_CLK_PRE_64);
   
   
   while(1)
   {
	   /*receiving the information from the UART*/
	   UART_RECEIVE_DATA(&x);

	 
		set_pin_value(PORTA,PIN0,LOW);
		/*sending the value to the slave m_controller2*/
	   spi_masterSendRecv(x,&y);
	   set_pin_value(PORTA,PIN0,HIGH);
	   
	   _delay_ms(10);
	 
   }
 }

