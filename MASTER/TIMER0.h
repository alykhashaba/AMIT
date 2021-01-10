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
void TIMER0_SET_DELAY(Uint32t Delay_MS);
void TIMER0_OVF_DELAY(Uint32t Delay);
void TIMER0_CTC_DELAY(Uint32t Delay, Uint8t OCR);

void TIMER0_FAST_PWM_Init(void);
void TIMER0_FAST_PWM_SET_DUTY(Uint8t Duty);
void TIMER0_FAST_PWM_START(void);

#endif /* TIMER0_H_ */