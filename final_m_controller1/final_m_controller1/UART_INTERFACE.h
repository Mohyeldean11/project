/*
 * UART_INTERFACE.h
 *
 * Created: 6/7/2021 7:09:46 PM
 *  Author: mohye
 */ 


#ifndef _UART_INTERFACE_h_
#define _UART_INTERFACE_h_


  /************************************************************************/
 /*                             INTERFACING MACROS                       */
/************************************************************************/

#define BAUD_RATE_2400      (416)
#define BAUD_RATE_4800      (207)
#define BAUD_RATE_9600		(103)
#define BAUD_RATE_115200    (8)



  /************************************************************************/
 /*                            FUNCTIONS PROTOTYPES                      */
/************************************************************************/

void UART_INIT(u16_t au16_baudrate);                                                 //this function is to initialize the UART to send or receive data.

 
void UART_SEND_data(u8_t au8_databyte);                                             //this function is to send one byte by the UART.


void UART_SEND_STREAM(u8_t* pu8_datastream,u8_t au8_data_size);                   //this function is to send a stream of bytes by the UART.


void UART_RECEIVE_DATA(u8_t* au8_databyte);                                       //this function is to receive one byte by the UART.




#endif