/*
 * USART_CONFIG.h
 *
 * Created: 12/20/2020 9:53:33 AM
 *  Author: karim
 */ 


#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_

#include "CPU_CONFIGURATION.h"

/************************************** UART-Registers************************************************/
/*
#define UBRRH (*((volatile Uint8t*)0x40))
#define UBRRL (*((volatile Uint8t*)0x29))
#define UCSRA (*((volatile Uint8t*)0x2B))
#define UCSRB (*((volatile Uint8t*)0x2A))
#define UCSRC (*((volatile Uint8t*)0x40))
#define UDR   (*((volatile Uint8t*)0x2C))
*/
#define FRQ 16000000
#define BAUD 9600

#endif /* USART_CONFIG_H_ */