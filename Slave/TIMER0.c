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
	/*Enable Peripheral Interrupt*/
	SET_BIT(TIMSK, TOIE0);
	#elif WAVE_GENERATION_MODE == PHASE_CORRECT_PWM
	CLR_BIT(TCCR0, WGM01);SET_BIT(TCCR0, WGM00);
	#elif WAVE_GENERATION_MODE == CTC_MODE
	SET_BIT(TCCR0, WGM01);CLR_BIT(TCCR0, WGM00);
	/*Enable Peripheral Interrupt*/
	SET_BIT(TIMSK, OCIE0);
	#elif WAVE_GENERATION_MODE == FAST_PWM
	SET_BIT(TCCR0, WGM01);SET_BIT(TCCR0, WGM00);
	#else
	#warning "Wrong Mode for Timer0"
	#endif
	/*Enable Global Interrupt*/
	SET_BIT(SREG, 7);

}
void TIMER0_START(void)
{
	/*Start by setting value to prescalar, Here will use 1024*/
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
void TIMER0_SET_DELAY(Uint32t Delay_MS, Uint8t Top)
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
	Uint32t Total_OVF = (Delay_MS * 1000) / Tick;
	OCR0 = Top;
	NUM_OVF = Total_OVF / OCR0;
	NUM_OVF ++;
	#endif
}

void TIMER0_FASTPWM_Init(void)
{
	/*Define Direction for pin OC0*/
	SET_BIT(DDRB, PB3);
	/*Choose Mode, Fast PWM*/
	SET_BIT(TCCR0, WGM01);SET_BIT(TCCR0, WGM00);
	/*Choose Non Inverted Mode*/
	/*Non-Inverted*/
	SET_BIT(TCCR0, COM01);CLR_BIT(TCCR0, COM00);
	/*Inverted*/
	//SET_BIT(TCCR0, COM01);SET_BIT(TCCR0, COM00);
}
void TIMER0_FASTPWM_SetDutyCycle(Uint8t DutyCycle)
{
	OCR0 = ((256 * DutyCycle) / 100) - 1;/*Non-Inverting, T-ON*/	
	//OCR0 = 256 - (((256 * DutyCycle) / 100) - 1);/*Inverting, T-ON*/
}
void TIMER0_FASTPWM_Start(void)
{
	/*Choose Prescaler, 256 CLK*/
	SET_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);CLR_BIT(TCCR0, CS00);
}
void TIMER0_FASTPWM_Stop(void)
{
	/*Choose Prescaler, No CLK*/
	CLR_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);CLR_BIT(TCCR0, CS00);
}