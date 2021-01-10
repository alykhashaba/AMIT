/*
* Aly's kit.c
*
* Created: 1/7/2021 6:01:40 PM
* Author : kc
*/

#include <avr/io.h>
#include "SPI.h"
#include "USART_RS232_H_file.h"
int main(void)
{
	USART_Init(9600);
	SPI_INIT();
	Uint8t Data_in;
	/* Replace with your application code */
	while (1)
	{
		Data_in= USART_RxChar();
		SPI_TRANSMIT(Data_in);
	}
}

