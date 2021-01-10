/*
 * TIMER0.h
 *
 * Created: 12/4/2020 8:38:28 PM
 *  Author: karim
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include "TIMER0_CONFIG.h"

void TIMER0_Init(void);
void TIMER0_START(void);
void TIMER0_STOP(void);
void TIMER0_SET_DELAY(Uint32t Delay_MS, Uint8t Top);

void TIMER0_FASTPWM_Init(void);
void TIMER0_FASTPWM_SetDutyCycle(Uint8t DutyCycle);
void TIMER0_FASTPWM_Start(void);
void TIMER0_FASTPWM_Stop(void);

#endif /* TIMER0_H_ */