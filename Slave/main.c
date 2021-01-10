/*
* Interfacing_Module_AMIT_H20.c
*
* Created: 11/12/2020 7:17:10 PM
* Author : karim
*/
#include "LED.h"
#include "USART_RS232_H_file.h"
#include "LCD.h"
#include "SPI.h"
#include "INP_OUT.h"
int main(void)
{
	Uint8t data= 0;
	SPI_INIT();
	SPI_SLAVESELECT(0);
	LED0_Init();
	LCD_Init();
	Buzzer_Init();

	/* Replace with your application code */
	while (1){
		
		
		SPI_SLAVE_RECEIVE(&data);
		
		if(data == LED_OFF)
		{
			LED0_OFF();
			LCD_Clear();
			LCD_Write_String("LED is OFF");
		}
		else if(data == LED_ON)
		{
			LED0_ON();
			LCD_Clear();
			LCD_Write_String("LED is ON");
		}
		else if(data == BUZZ_ON)
		{
			Buzzer_ON();
			LCD_Clear();
			LCD_Write_String("Buzzer ON");
		}
		else if(data == BUZZ_OFF)
		{
			Buzzer_OFF();
			LCD_Clear();
			LCD_Write_String("Buzzer OFF");
		}
		else{
			LED0_OFF();
			LCD_Clear();
			Buzzer_OFF();
			LCD_Write_String("Incorrect Character");
		}
	}
}
