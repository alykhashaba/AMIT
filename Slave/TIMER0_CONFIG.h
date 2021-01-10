/*
 * TIMER0_CONFIG.h
 *
 * Created: 12/4/2020 8:38:16 PM
 *  Author: karim
 */ 


#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_

#include "CPU_CONFIGURATION.h"

#define NORMAL_MODE         0
#define PHASE_CORRECT_PWM   1
#define CTC_MODE            2
#define FAST_PWM            3

#define NO_CLK 0
#define CLK_1024 5

#define WAVE_GENERATION_MODE      CTC_MODE
#define TIMER0_Prescalar          CLK_1024

#endif /* TIMER0_CONFIG_H_ */