/*
* USART.h
*
* Created: 12/17/2020 8:28:38 AM
*  Author: Karim.elnahal
*/
/*
#define UBRRH (*((volatile Uint8t*)0x40))
#define UBRRL (*((volatile Uint8t*)0x29))
#define UCSRA (*((volatile Uint8t*)0x2B))
#define UCSRB (*((volatile Uint8t*)0x2A))
#define UCSRC (*((volatile Uint8t*)0x40))
#define UDR   (*((volatile Uint8t*)0x2C))
*/

#ifndef USART_H_
#define USART_H_

/*Macros*/
#include "USART_CONFIG.h"

/*Main Functions*/
void USART_Init(void);
void USART_Tx(Uint8t Transmiter);
Uint8t USART_Rx();
/*Other Functions*/
void USART_STR_Tx(Uint8t* str_Tx);
void USART_STR_Rx(Uint8t* str_Rx);

#endif /* USART_H_ */