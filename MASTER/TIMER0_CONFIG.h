/*
 * TIMER0_CONFIG.h
 *
 * Created: 12/4/2020 8:38:16 PM
 *  Author: karim
 */ 


#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_

#include "CPU_CONFIGURATION.h"

/************************************** TIMER0-Registers *********************************************/
/*
#define TCNT0  (*(volatile Uint8t*) (0x52))
#define TCCR0  (*(volatile Uint8t*) (0x53))
#define TIMSK  (*(volatile Uint8t*) (0x59))
#define OCR0   (*(volatile Uint8t*) (0x5C))
*/
#define NORMAL_MODE         0
#define PHASE_CORRECT_PWM   1
#define CTC_MODE            2
#define FAST_PWM            3

#define INVERTING_MODE 0
#define NON_INVERTING_MODE 1

#define NO_CLK 0
#define CLK_1024 5

#define WAVE_GENERATION_MODE      NORMAL_MODE
#define TIMER0_Prescalar          CLK_1024
#define TIMER0_PWM_MODE  NON_INVERTING_MODE
#endif /* TIMER0_CONFIG_H_ */