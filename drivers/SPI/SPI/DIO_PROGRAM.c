/*/*
 * GccApplication2.c
 *
 * Created: 6/7/2021 4:00:04 PM
 * Author : mohye
 */ 


#include "Lbit_math.h"
#include "lstd_types.h"
#include "DIO_PRIVATE.h"
#include "DIO_NITERFACE.h"



/************************************************************************/
/*			FUNCTIONS DEFINITIONS                                       */
/************************************************************************/


void set_pin_status(u8_t au8_port, u8_t au8_pin ,u8_t au8_status)			 //this function is to set the pin  status to INPUT FLOAT,OUTPUT OR INPUT PULLUP.
{
	switch(au8_port)																		//to switch between PORTS.
	{
		case PORTA:																			//if it was PORT A,SWITCH between the satus inside it.
		{
			switch(au8_status)																//SWITCHING between the status inside PORT A.
			{
				
				case INPUT_FLOAT:															//incase of INPUT FLOATING.
				{
					DIO_DDRA&= ~au8_pin;														//here, we set the PIN to 0
					
					break;																	//breaking from the case.								
				}
				
				case  OUTPUT:																//incase of OUTPUT.
				{
					DIO_DDRA|= au8_pin;															//here, we set the PIN to 1.
					
					break;																	//breaking from the case.
				}
				
				case INPUT_PULLUP:															//incase of INPUT PULLUP.
				{
					DIO_DDRA&=~au8_pin;															//here, we set the PIN to 0.
					
					DIO_PORTA|=au8_pin;															//here, we set the PIN to 1.
					
					break;																	//breaking from the case.
				}
			}
			break;
		}
		
		case PORTB:																			//if it was PORT B,SWITCH between the satus inside it.
		{
			switch(au8_status)																//SWITCHING between the status inside PORT B.
			{
				
				case INPUT_FLOAT:															//incase of INPUT FLOATING.
				{
					DIO_DDRB&= ~au8_pin;														//here, we set the PIN to 0
					
					break;																	//breaking from the case.
				}
				
				case  OUTPUT:																//incase of OUTPUT.
				{
					DIO_DDRB|= au8_pin;															//here, we set the PIN to 1.
					
					break;																	//breaking from the case.
				}
				
				case INPUT_PULLUP:															//incase of INPUT PULLUP.
				{
					DIO_DDRB&=~au8_pin;															//here, we set the PIN to 0.
					
					DIO_PORTB|=au8_pin;															//here, we set the PIN to 1.
					
					break;																	//breaking from the case.
				}
				
			}
			break;
		}
		case PORTC:																			//if it was PORT C,SWITCH between the satus inside it.
		{
			switch(au8_status)																//SWITCHING between the status inside PORT C.
			{
				
				case INPUT_FLOAT:															//incase of INPUT FLOATING.
				{
					DIO_DDRC&= ~au8_pin;														//here, we set the PIN to 0
					
					break;																	//breaking from the case.
				}
				
				case  OUTPUT:																//incase of OUTPUT.
				{
					DIO_DDRC|= au8_pin;															//here, we set the PIN to 1.
					
					break;																	//breaking from the case.
				}
				
				case INPUT_PULLUP:															//incase of INPUT PULLUP.
				{
					DIO_DDRC&=~au8_pin;															//here, we set the PIN to 0.
					
					DIO_PORTC|=au8_pin;															//here, we set the PIN to 1.
					
					break;																	//breaking from the case.
				}
			}
			break;
		}
		case PORTD:																			//if it was PORT D,SWITCH between the satus inside it.
		{
			switch(au8_status)																//SWITCHING between the status inside PORT D.
			{
				
				case INPUT_FLOAT:															//incase of INPUT FLOATING.
				{
					DIO_DDRD&= ~au8_pin;														//here, we set the PIN to 0
					
					break;																	//breaking from the case.
				}
				
				case  OUTPUT:																//incase of OUTPUT.
				{
					DIO_DDRD|= au8_pin;															//here, we set the PIN to 1.
					
					break;																	//breaking from the case.
				}
				
				case INPUT_PULLUP:															//incase of INPUT PULLUP.
				{
					DIO_DDRD&=~au8_pin;															//here, we set the PIN to 0.
					
					DIO_PORTD|=au8_pin;															//here, we set the PIN to 1.
					
					break;																	//breaking from the case.
				}
				
			}
			break;
		}
		
	}
		

}


void set_pin_value(u8_t au8_port, u8_t au8_pin ,u8_t au8_value)			//this function is to set the pin  value to HIGH OR LOW.
{
	switch(au8_port)													//to switch between PORTS.
	{
		case PORTA:														//incase of PORT A.
		{
			if(au8_value==HIGH)											//if the desired value is HIGH.
			{
				DIO_PORTA|=au8_pin;											//setting the PIN to 1.
			}
			else if(au8_value==LOW)										//if the desired value is LOW.
			{
				DIO_PORTA &= ~au8_pin;										//setting the PIN to 0.
			}
			
			break;														//breaking from the case.
		}
		case PORTB:														//incase of PORT B.
		{
			if(au8_value==HIGH)											//if the desired value is HIGH.
			{
				DIO_PORTB|=au8_pin;											//setting the PIN to 1.
			}
			else if(au8_value==LOW)										//if the desired value is LOW.
			{
				DIO_PORTB&= ~au8_pin;										//setting the PIN to 0.
			}
			
			break;														//breaking from the case.
		}
		case PORTC:														//incase of PORT C.
		{
			if(au8_value==HIGH)											//if the desired value is HIGH.
			{
				DIO_PORTC|=au8_pin;											//setting the PIN to 1.
			}
			else if(au8_value==LOW)										//if the desired value is LOW.
			{
				DIO_PORTC&= ~au8_pin;										//setting the PIN to 0.
			}
			
			break;														//breaking from the case.
		}
		case PORTD:														//incase of PORT D.
		{
			if(au8_value==HIGH)											//if the desired value is HIGH.
			{
				DIO_PORTD|=au8_pin;											//setting the PIN to 1.
			}
			else if(au8_value==LOW)										//if the desired value is LOW.
			{
				DIO_PORTD&= ~au8_pin;										//setting the PIN to 0.
			}
			
			break;														//breaking from the case.
		}
	}
}



void toggle_pin(u8_t au8_port,u8_t au8_pin)								//this function is to toggle the pin value from its current value.
{
	switch (au8_port)													//switching between PORTS.
	{
		case PORTA:														//incase of PORT A.
		{
			DIO_PORTA^=au8_pin;												//toggeling the value of the PIN.
			
			break;														//breaking from the case.
		}
		case PORTB:														//incase of PORT B.
		{
			DIO_PORTB^=au8_pin;												//toggeling the value of the PIN.
			
			break;														//breaking from the case.
		}
		case PORTC:														//incase of PORT C.
		{
			DIO_PORTC^=au8_pin;												//toggeling the value of the PIN.
			
			break;														//breaking from the case.
		}
		case PORTD:														//incase of PORT C.
		{
			DIO_PORTD^=au8_pin;												//toggeling the value of the PIN.
			
			break;														//breaking from the case.
		}
	}
}


u8_t get_pin(u8_t au8_port,u8_t au8_pin)									//this function is to get the pin current value.
{
	u8_t au8_pin_value=0;														//a variable was created to return the value of the pin to it.
	
	switch (au8_port)														//switching between PORTS.
	{	
		case PORTA:															//incase of PORT A.
		{
			if (DIO_PINA&au8_pin)											//if the value of the PIN IS 1.
			{
				au8_pin_value=HIGH;											//put the PIN_VALUE 1.
			}
			else															//if the value of the PIN IS 0.	
			{
				au8_pin_value=LOW;											//put the  PIN_VALUE 1.
			}
			
			break;															//breaking from the case.
		}
		case PORTB:															//incase of PORT B.
		{
			if (DIO_PINB&au8_pin)											//if the value of the PIN IS 1.
			{
				au8_pin_value=HIGH;											//put the PIN_VALUE 1.
			}
			else															//if the value of the PIN IS 0.
			{
				au8_pin_value=LOW;											//put the  PIN_VALUE 1.
			}
			
			break;															//breaking from the case.
		}
		case PORTC:															//incase of PORT C.
		{
			if (DIO_PINC&au8_pin)											//if the value of the PIN IS 1.
			{
				au8_pin_value=HIGH;											//put the PIN_VALUE 1.
			}
			else															//if the value of the PIN IS 0.
			{
				au8_pin_value=LOW;											//put the  PIN_VALUE 1.
			}
			
			break;															//breaking from the case.
		}
		case PORTD:															//incase of PORT D.
		{
			if (DIO_PIND&au8_pin)											//if the value of the PIN IS 1.
			{
				au8_pin_value=HIGH;											//put the PIN_VALUE 1.
			}
			else															//if the value of the PIN IS 0.
			{
				au8_pin_value=LOW;											//put the  PIN_VALUE 1.
			}
			
			break;															//breaking from the case.
		}
	}
	return au8_pin_value;													//returning the value from the function
}