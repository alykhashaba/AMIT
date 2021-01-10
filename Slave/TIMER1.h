/*
 * TIMER1.h
 *
 * Created: 12/5/2020 12:16:42 PM
 *  Author: karim
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

#include "TIMER1_CONFIG.h"

void TIMER1_Init(void);
void TIMER1_START(void);
void TIMER1_STOP(void);
void TIMER1_SET_DELAY(Uint32t Delay_MS);
void TIMER1_DELAY(Uint32t Delay);


void TIMER1_PWM_Init(void);
void TIMER1_PWM_SETDUTY(Uint8t Duty);
void TIMER1_PWM_Start(void);

#endif /* TIMER1_H_ */