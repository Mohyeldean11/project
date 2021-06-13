/*
 * SPI_INTERFACE.h
 *
 * Created: 6/10/2021 7:09:21 PM
 *  Author: mohye
 */ 

/*Header file guard*/
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

/************************************************************************/
/*                           Interfacing macros                         */
/************************************************************************/

/*Master and slave selection*/
#define SPI_MASTER_DEVICE     (0x10)
#define SPI_SLAVE_DEVICE      (0x00)

/*SPI data order*/
#define SPI_LSB_FIRST         (0x20)
#define SPI_MSB_FIRST         (0x00)

/*CLK type in data transfer*/
#define SPI_SAMPLE_R_SETUP_F  (0)
#define SPI_SETUP_R_SAMPLE_F  (1)
#define SPI_SAMPLE_F_SETUP_R  (2)
#define SPI_SETUP_F_SAMPLE_R  (3)

/*SPI CLK frequency options*/
#define SPI_CLK_PRE_2         (0)
#define SPI_CLK_PRE_4         (1)
#define SPI_CLK_PRE_8         (2)
#define SPI_CLK_PRE_16        (3)
#define SPI_CLK_PRE_32        (4)
#define SPI_CLK_PRE_64        (5)
#define SPI_CLK_PRE_128       (7)

/************************************************************************/
/*                           Functions' prototypes                      */
/************************************************************************/


void spi_init(u8_t au8_spiDevType, u8_t au8_dataOrder, u8_t au8_dataTransfer_clkType, u8_t au8_clkFrequency);			//This function is used to initialize the control register and set the SPI to send or recieve.


void spi_masterSendRecv(u8_t au8_sendData, u8_t* au8_recvData);															//This function is used to send data from master and receive data from slave.


void spi_slaveSendRecv(u8_t au8_sendData, u8_t* au8_recvData);															//This function is used to send data from slave and receive data from master.

#endif 