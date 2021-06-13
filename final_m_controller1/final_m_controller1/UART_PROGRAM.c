/*
 * UART_PROGRAM.C
 * contains pROGRAM for the UART DRIVER
 * Created: 6/7/2021 7:09:46 PM
 *  Author: mohye
 * 
 */ 


  /************************************************************************/
 /*                                       INCLUSIONS                     */
/************************************************************************/

#include "lstd_types.h"
#include "Lbit_math.h"
#include "UART_INTERFACE.h"
#include "UART_PRIVATE.h"


void UART_INIT(u16_t au16_baudrate)                                                 //this function is to initialize the UART to send or receive data.
{
 
	UART_UCSRA = 0;                                                                //cancelling the double speed and the multi processor mode

	UART_UCSRB = 0x18;                                                             // enabling the sending TX and receiving RX 
	
	UART_UCSRC = 0x86;                                                            // disabling the parity bit and setting the stop bit  and setting it to ASynch.
	

	UART_UBRRL = (u8_t) au16_baudrate;                                          //Setting the low byte of baud rate

    
    UART_UBRRH = (u8_t) (au16_baudrate >> 8);                                    //Setting the high byte of baud rate

    return;
}


void UART_SEND_data(u8_t au8_databyte)                                             //this function is to send one byte by the UART.
{
    if(GET_BIT(UART_UCSRA,5))                                                           //Checking wether  UART register is empty or not.
    {
        UART_UDR= au8_databyte;                                                       //putting the databyte to the UDR to be sent.

        while(GET_BIT(UART_UCSRA,6)==0);                                               //waiting till the data is sent and there's no data in the buffer//1111111111111
        
        SET_BIT(UART_UCSRA,6);                                                        //setting the flag again to one to be ready to have another byte to send it
        
    }
    return;
}

void UART_RECEIVE_DATA( u8_t* pu8_databyte)                                       //this function is to receive one byte by the UART.
{
    if(GET_BIT(UART_UCSRA,7))                                                     //checking if there is any unread data in the UDR REGISTER.
    {
         *pu8_databyte= UART_UDR;                                               //PASSING THE DATA IN THE UDR REGISTER TO BE READ.                  
    }

    return;
}


void UART_SEND_STREAM(u8_t* pu8_datastream,u8_t au8_data_size)                   //this function is to send a stream of bytes by the UART.
{
    while(au8_data_size--)
	{
		                                                                               
		if(GET_BIT(UART_UCSRA, 5))                                                     //Checking wether  UART register is empty or not.
		{
			
			UART_UDR = *pu8_datastream;                                                 //putting the databyte to the UDR to be sent.
		
			while(GET_BIT(UART_UCSRA, 6) == 0);                                        ///waiting till the data is sent and there's no data in the buffer

			SET_BIT(UART_UCSRA, 6);                                                     //setting the flag again to one to be ready to have another byte to send it
			
			pu8_datastream++;                                                           //Increasing the pointer address.
		}
	}
	
	return;

}



