/*
 * SPI_PROGRAM.c
 *
 * Created: 6/7/2021 7:09:21 PM
 *  Author: mohye
 */ 

/************************************************************************/
/*                              Includes                                */
/************************************************************************/

#include "lstd_types.h"
#include "Lbit_math.h"
#include "SPI_private.h"
#include "SPI_interface.h"

#define F_CPU  16000000UL
#include "util/delay.h"

/************************************************************************/
/*                             Important macros                         */
/************************************************************************/

#define TIMEOUT_VALUE   (100)

/************************************************************************/
/*                          Functions' definitions                      */
/************************************************************************/

void spi_init(u8_t au8_spiDevType, u8_t au8_dataOrder, u8_t au8_dataTransfer_clkType, u8_t au8_clkFrequency)				//This function is used to initialize the control register and set the SPI to send or recieve.
{

    SPI_SPCR = 0;																											//Reseting the SPCR register.
   
    if( (au8_clkFrequency % 2) == 0 )																						//Checking the clk value to enable double speed or to not it.
    {
	
	    SET_BIT(SPI_SPSR, 0);																								//Enable double speed.
    }	
    else
    {
		
        CLEAR_BIT(SPI_SPSR, 0);																						   //Disable double speed.
    }

    SPI_SPCR = (1<<6)|au8_spiDevType | au8_dataOrder | (au8_dataTransfer_clkType << 2) | (au8_clkFrequency / 2);					//Setting the SPCR register parameters.
    
    return;
}

void spi_masterSendRecv(u8_t au8_sendData, u8_t* au8_recvData)																//This function is used to send data from master and receive data from slave.
{
    u8_t au8_timeOut = 0;																									 //A variable to time out mechanism.
    
    SPI_SPDR = au8_sendData;																								 //Setting the master data that will be sent.
    
    while( (GET_BIT(SPI_SPSR, 7) == 0) && (au8_timeOut < TIMEOUT_VALUE) )													//Wait until the SPI flag rises.											
    {
        au8_timeOut++;																										//Increasing the timeout variable by one every one loop.
		
        _delay_us(1);																										//Wait for 1 microsecond.
    }
    
    
    *au8_recvData = SPI_SPDR;																								//Getting the received data from the slave.																								

    return;
}

void spi_slaveSendRecv(u8_t au8_sendData, u8_t* au8_recvData)																//This function is used to send data from slave and receive data from master.
{   
    
    if( GET_BIT(SPI_SPSR, 7) )																								//Checking wether the SPI flag rises or not.
    {
        *au8_recvData = SPI_SPDR;																							//Getting rid the received master data.
        
        SPI_SPDR = au8_sendData;																							//Set the new data to be sent for the master.
    }
  
    return;
}