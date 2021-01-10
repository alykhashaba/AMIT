/*
* USART.c
*
* Created: 12/17/2020 8:28:25 AM
*  Author: Karim.elnahal
*/
#include "USART.h"
/*Main Functions*/
void USART_Init(void)
{
	/*Baud Rate Value*/
	Uint16t UBRR_Value = 0;
	/*Define Direction of Rx and Tx*/
	CLR_BIT(DDRD, PD0);/*Rx - Input*/
	SET_BIT(DDRD, PD1);/*Tx - Output*/
	/*Calculations for baud rate*/
	UBRR_Value = ((FRQ) / (16 * BAUD)) - 1;
	UBRRL = UBRR_Value;
	UBRRH= (UBRR_Value >> 8);
	/*Disable Transmit Interrupt*/
	CLR_BIT(UCSRB, TXCIE);
	/*Disable Receive Interrupt*/
	CLR_BIT(UCSRB, RXCIE);
	/*Disable Buffer Empty Interrupt*/
	CLR_BIT(UCSRB, UDRIE);
	/*Enable Transmit Data*/
	SET_BIT(UCSRB, TXEN);
	/*Enable Receive Data*/
	SET_BIT(UCSRB, RXEN);
	/*Select to select UCSRC not UBBRH*/
	SET_BIT(UCSRC, URSEL);
	/*USART Frame Edit (0x06)*/
	CLR_BIT(UCSRC, UCSZ2);SET_BIT(UCSRC, UCSZ1);SET_BIT(UCSRC, UCSZ0);/*8-BIT Mode*/
	CLR_BIT(UCSRC, UPM1);CLR_BIT(UCSRC, UPM0);/*No Parity Bits*/
	CLR_BIT(UCSRC, USBS);/*Stop Bits*/
}
void USART_Tx(Uint8t Transmiter)
{
	UDR = Transmiter;
	while (!(UCSRA & (1<<UDRE)));/*Polling Mode*/
}
Uint8t USART_Rx()
{
while (!(UCSRA & (1 << RXC)));	/*Polling Mode*/
	return(UDR);
}
/*Other Functions*/
void USART_STR_Tx(Uint8t* str_Tx)
{
	while (*str_Tx != '\0')
	{
		USART_Tx(*str_Tx);
		_delay_ms(1);
		str_Tx++;
	}
}
void USART_STR_Rx(Uint8t* str_Rx)
{
	Uint8t receive = 0;
	*str_Rx = "";
	while (receive != '\0')
	{
		USART_Rx(&receive);
		_delay_ms(1);
		str_Rx += receive;
	}
}