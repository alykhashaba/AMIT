/*
* TIMER0.c
*
* Created: 12/4/2020 8:38:36 PM
*  Author: karim
*/

#include "TIMER0.h"

Uint32t NUM_OVF = 0;
Uint32t INITIAL_VALUE = 0;

void TIMER0_Init(void)
{
	#if WAVE_GENERATION_MODE == NORMAL_MODE
	CLR_BIT(TCCR0, WGM01);CLR_BIT(TCCR0, WGM00);
	#elif WAVE_GENERATION_MODE == PHASE_CORRECT_PWM
	CLR_BIT(TCCR0, WGM01);SET_BIT(TCCR0, WGM00);
	#elif WAVE_GENERATION_MODE == CTC_MODE
	SET_BIT(TCCR0, WGM01);CLR_BIT(TCCR0, WGM00);
	#elif WAVE_GENERATION_MODE == FAST_PWM
	SET_BIT(TCCR0, WGM01);SET_BIT(TCCR0, WGM00);
	#else
	#warning "Wrong Mode for Timer0"
	#endif
	/*Enable Global Interrupt*/
	SET_BIT(SREG, 7);
	/*Enable Peripheral Interrupt*/
	SET_BIT(TIMSK, TOIE0);
}
void TIMER0_START(void)
{
	/*Start by setting value to prescaler, Here will use 1024*/
	#if TIMER0_Prescalar == CLK_1024
	SET_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);SET_BIT(TCCR0, CS00);
	#endif
}
void TIMER0_STOP(void)
{
	/*Stop by setting value to prescalar, Here will use 1024*/
	#if TIMER0_Prescalar == NO_CLK
	CLR_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);CLR_BIT(TCCR0, CS00);
	#endif
}
void TIMER0_SET_DELAY(Uint32t Delay_MS)
{
	#if WAVE_GENERATION_MODE == NORMAL_MODE
	Uint8t Tick = 1024 / 16;
	Uint32t Total_OVF = (Delay_MS * 1000) / Tick;
	NUM_OVF = Total_OVF / 256;
	INITIAL_VALUE = 256 - (Total_OVF % 256);
	TCNT0 = INITIAL_VALUE;
	NUM_OVF ++;
	#elif WAVE_GENERATION_MODE == CTC_MODE
	Uint8t Tick = 1024 / 16;
	Uint32t Number_Ticks = (Delay_MS * 1000) / Tick;
	OCR0 = Number_Ticks - 1;
	NUM_OVF++;
	#else
	#warning "Wrong Mode for Timer0"
	#endif	
}
void TIMER0_OVF_DELAY(Uint32t Delay)
{
	Uint8t Tick = 1024/16;
	Uint32t T_OVF = 256 * Tick;
	NUM_OVF = (Delay * 1000) / T_OVF;
	INITIAL_VALUE = 256 - (Delay % 256);
	TCNT0 = INITIAL_VALUE;
	NUM_OVF++;
}
void TIMER0_CTC_DELAY(Uint32t Delay, Uint8t OCR)
{
		Uint8t Tick = 1024 / 16;
		Uint32t Total_OVF = (Delay * 1000) / Tick;
		NUM_OVF = Total_OVF / OCR;
		NUM_OVF ++;
}

void TIMER0_FAST_PWM_Init(void)
{
	/*Define Direction of OC0 as Output*/
	SET_BIT(DDRB, PB3);
	/*Fast PWM Mode*/
	SET_BIT(TCCR0, WGM01);SET_BIT(TCCR0, WGM00);
	/*Non-Inverted*/
	SET_BIT(TCCR0, COM01);CLR_BIT(TCCR0, COM00);
}
void TIMER0_FAST_PWM_SET_DUTY(Uint8t Duty)
{
	#if TIMER0_PWM_MODE == NON_INVERTING_MODE
	OCR0 = ((256 * Duty) / 100) - 1);
	#elif TIMER0_PWM_MODE == INVERTING_MODE
	OCR0 = 256 - (((256 * Duty) / 100) - 1);
	#else
	#warning "Wrong PWM Mode"
	#endif
}
void TIMER0_FAST_PWM_START(void)
{
	/*Choose Prescaler*/
	SET_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);CLR_BIT(TCCR0, CS00);
}


