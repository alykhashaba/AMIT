/*
 * INP_OUT.c
 *
 * Created: 11/12/2020 8:40:16 PM
 *  Author: karim
 */ 


#include "INP_OUT.h"


void Relay_Init(void)
{
	SET_BIT(DDRA,2);
}
void Relay_ON(void)
{
	SET_BIT(PORTA,2);
}
void Relay_OFF(void)
{
	CLR_BIT(PORTA,2);
}
void Relay_TGL(void)
{
	TGL_BIT(PORTA,2);
}

void Buzzer_Init(void)
{
	SET_BIT(DDRA,3);
}
void Buzzer_ON(void)
{
	SET_BIT(PORTA,3);
}
void Buzzer_OFF(void)
{
	CLR_BIT(PORTA,3);
}
void Buzzer_TGL(void)
{
	TGL_BIT(PORTA,3);
}