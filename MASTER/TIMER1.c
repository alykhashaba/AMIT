/*
* TIMER1.c
*
* Created: 12/5/2020 12:16:50 PM
*  Author: karim
*/




#include "TIMER1.h"

Uint32t NUM_OCF = 0;

void TIMER1_Init(void)
{
	/*Will choose CTC Mode*/
	CLR_BIT(TCCR1B, WGM13);SET_BIT(TCCR1B, WGM12);CLR_BIT(TCCR1A, WGM11);CLR_BIT(TCCR1A, WGM10);
	/*Enable Global Interrupt*/
	SET_BIT(SREG, 7);
	/*Enable Peripheral Interrupt*/
	SET_BIT(TIMSK, OCIE1A);
}
void TIMER1_START(void)
{
	/*Select CLK Needed*/
	SET_BIT(TCCR1B, CS12);CLR_BIT(TCCR1B, CS11);SET_BIT(TCCR1B, CS10);
}
void TIMER1_STOP(void)
{
	/*Select No-CLK Needed*/
	CLR_BIT(TCCR1B, CS12);CLR_BIT(TCCR1B, CS11);CLR_BIT(TCCR1B, CS10);
}
void TIMER1_SET_DELAY(Uint32t Delay_MS)
{
	if (Delay_MS <= 4000)
	{
		Uint8t Tick = 1024 / 16;
		Uint32t Number_Ticks = (Delay_MS * 1000) / Tick;
		OCR1A = Number_Ticks - 1;
		NUM_OCF++;
	}
}



void TIMER1_PWM_Init(void)
{
	SET_BIT(DDRD, 5);
	/*Timer1 Mode 14*/
	SET_BIT(TCCR1A, 1);
	SET_BIT(TCCR1B, 3);
	SET_BIT(TCCR1B, 4);
	/*Select Non-Inverted Mode*/
	SET_BIT(TCCR1A, 7);
	/*Control Top Value using ICR*/
	ICR1 = 1250;
}
void TIMER1_PWM_SETDUTY(Uint8t Duty)
{
	OCR1A = ((Duty * 1250) / 100) - 1;
}
void TIMER1_PWM_Start(void)
{
	/*Using Prescaler 256*/
	SET_BIT(TCCR1B, 2);
}

void TIMER1_PWM_Stop(void)
{
	
}