/*
 * SERVO.c
 *
 * Created: 12/11/2020 4:04:53 PM
 *  Author: karim
 */ 


#include "SERVO.h"

void SERVO_MOTOR_Init(void)
{
	TIMER1_PWM_Init();
	TIMER1_PWM_Start();
}
void SERVO_MOTOR_Angle(Uint8t angle)
{
	TIMER1_PWM_SETDUTY(angle);
}