/*
 * DIO_PRIVATE.h
 *
 * Created: 6/7/2021 7:09:46 PM
 *  Author: mohye
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

/************************************************************************/
/*                    REGISTERS                                         */
/************************************************************************/

/*PORT A*/
#define DIO_PORTA	(*(volatile u8_t*)(0x3B))
#define	DIO_DDRA	(*(volatile u8_t*)(0x3A))
#define DIO_PINA	(*(volatile u8_t*)(0x39))

/*PORTB*/

#define DIO_PORTB	(*(volatile u8_t*)(0x38))
#define	DIO_DDRB	(*(volatile u8_t*)(0x37))
#define DIO_PINB	(*(volatile u8_t*)(0x36))

/*PORTC*/
#define DIO_PORTC	(*(volatile u8_t*)(0x35))
#define	DIO_DDRC	(*(volatile u8_t*)(0x34))
#define DIO_PINC	(*(volatile u8_t*)(0x33))

/*PORTD*/
#define DIO_PORTD	(*(volatile u8_t*)(0x32))
#define	DIO_DDRD	(*(volatile u8_t*)(0x31))
#define DIO_PIND	(*(volatile u8_t*)(0x30))
#endif /* DIO_PRIVATE_H_ */