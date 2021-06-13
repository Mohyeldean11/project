/*
 * UART_private.h
 * contains private registers for the UART DRIVER
 * Created: 6/7/2021 7:09:46 PM
 *  Author: mohye
 * 
 */ 

#ifndef UART_private_h_
#define UART_private_h_

/************************************************************************/
/*                            UART Registers                            */
/************************************************************************/

#define UART_UDR        (*(volatile u8_t*)(0x2C))
#define UART_UCSRA      (*(volatile u8_t*)(0x2B))
#define UART_UCSRB      (*(volatile u8_t*)(0x2A))
#define UART_UCSRC      (*(volatile u8_t*)(0x40))
#define UART_UBRRH      (*(volatile u8_t*)(0x40))
#define UART_UBRRL      (*(volatile u8_t*)(0x29))


#endif 