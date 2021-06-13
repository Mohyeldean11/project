/*
 * SPI_PRIVATE.h
 *
 * Created: 6/10/2021 7:09:21 PM
 *  Author: mohye
 */ 

/*Header file guard*/
#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

/************************************************************************/
/*                            SPI Registers                             */
/************************************************************************/

#define SPI_SPCR    (*(volatile u8_t *)(0x2D))
#define SPI_SPSR    (*(volatile u8_t *)(0x2E))
#define SPI_SPDR    (*(volatile u8_t *)(0x2F))

#endif 