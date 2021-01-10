/*
* SPI.c
*
* Created: 12/19/2020 2:29:11 PM
*  Author: karim
*/

#include "SPI.h"

void SPI_INIT(void)
{
	#if SPI_MODE == MASTER
	/*Define directions for Master pins*/
	SET_BIT(DDRB, MOSI);                                          /*MOSI-OUTPUT*/
	CLR_BIT(DDRB, MISO);                                           /*MISO-INPUT*/
	SET_BIT(DDRB, SCK);                                         /*CLK-OUTPUT*/
	SET_BIT(DDRB, SS);                                             /*SS-OUTPUT*/
	#elif SPI_MODE == SLAVE										  
	/*Define directions for Slave pins*/						  
	CLR_BIT(DDRB, MOSI);                                          /*MOSI-INPUT*/
	SET_BIT(DDRB, MISO);                                           /*MISO-OUTPUT*/
	CLR_BIT(DDRB, SCK);                                            /*CLK-INPUT*/
	CLR_BIT(DDRB, SS);                                             /*SS-INPUT*/
	#endif														  
	CLR_BIT(SPCR, SPIE);                                          /*Disable SPI Interrupt*/
	SET_BIT(SPCR, MSTR);                                          /*Select Master Mode*/
	SET_BIT(SPCR, DORD);                                          /*Data order mode-LSB First*/
	CLR_BIT(SPCR, CPOL);                                          /*Clock Phase-LOW*/
	CLR_BIT(SPSR, SPI2X);SET_BIT(SPCR, SPR1);SET_BIT(SPCR, SPR0); /*Prescaler-128*/
	SET_BIT(SPCR, SPE);                                           /*Enable SPI*/
}
void SPI_TRANSMIT(Uint8t data)
{
	SPDR = data;
	while (GET_BIT(SPSR, SPIF) != 1);
}
void SPI_RECEIVE(Uint8t* data)
{
	while (GET_BIT(SPSR, SPIF) != 1);
	*data = SPDR;
}
void SPI_SLAVESELECT(Uint8t slave)
{
	if(slave == 0)
	{
		CLR_BIT(PORTB, SS);
	}
}

/*

void SPI_Master_Init(void){
	DDRB |= (1 << DDB5) | (1 << DDB7) | (1 << DDB4);
	PORTB |= (1 << DDB4);
	SPCR = (1 << SPE)  | (1 << MSTR) | (1 << SPR0);
}
/*
void SPI_SLAVE_INIT(void)
{
DIO_SetPin_Direction(DIO_PORTB ,DIO_PIN4 , DIO_PIN_INPUT);
DIO_SetPin_Direction(DIO_PORTB ,DIO_PIN5 , DIO_PIN_INPUT);
DIO_SetPin_Direction(DIO_PORTB ,DIO_PIN6 , DIO_PIN_OUTPUT);
DIO_SetPin_Direction(DIO_PORTB ,DIO_PIN7 , DIO_PIN_INPUT);

SPI->SPCR.SPR0 = 0;
SPI->SPCR.SPR1 = 0;
SPI->SPCR.CPHA = 0;
SPI->SPCR.CPOL = 0;
SPI->SPCR.MSTR = 0;
SPI->SPCR.DORD = 0;
SPI->SPCR.SPE  = 1;
}
void SPI_MASTER_START_TRASNMIT(void)
{
DIO_SetPin_Value(DIO_PORTB ,DIO_PIN4 ,DIO_PIN_LOW);
}
void SPI_MASTER_STOP_TRASNMIT(void)
{
DIO_SetPin_Value(DIO_PORTB ,DIO_PIN4 ,DIO_PIN_HIGH);
}
Uint8t SPI_TRANSIVIER(Uint8t Data)
{
Uint8t  rec_data = 0 ;

SPI->SPDR = Data ;

while(GET_BIT(SPI->SPSR , 7)  ==  0);

rec_data = SPI->SPDR;

return rec_data ;
}
*/