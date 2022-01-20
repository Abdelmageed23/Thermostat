/*
 * ADC_Implementation.c
 *
 * Created: 1/18/2022 4:21:38 PM
 *  Author: No. 01
 */ 

#include "STD_types.h"
#include "Registers.h"
#include "ADC_Config.h"
#include "ADC_interface.h"


void ADC_init(void)
{
	/*Set port direction to input*/
	PORTA_DIR= INPUT;
	/*Enable ADC and set prescaler to 128*/
	ADCSRA = ((HIGH<<ADEN) | (HIGH<<ADPS2) | (HIGH<<ADPS1) | (HIGH<<ADPS0)); 
	/*Set Vref to 5V (VCC)*/
	ADMUX = HIGH<<REFS0;
}
void ADC_read(uint8_t channel, uint16_t *val)
{
	uint8_t u8_lowByte, u8_highByte;
	//set channel keeping register components
	ADMUX= (ADMUX & ((HIGH<<REFS1) | (HIGH<<REFS0) | (HIGH <<ADLAR))) | (channel & ((HIGH<<MUX2) | (HIGH<<MUX1) | (HIGH <<MUX0)));
	//start conversion
	ADCSRA|= HIGH<<ADSC;
	//Busy wait till conversion is complete
	while(!(((ADCSRA & (HIGH<<ADIF))>>ADIF)&HIGH)) 
	{
		continue;
	}
	//clear interrupt
	ADCSRA|=HIGH<<ADIF;
	//read low byte
	u8_lowByte=ADCL;
	//read high byte
	u8_highByte=ADCH;
	//return the value
	*val = ((uint16_t)(u8_lowByte))+(256*((uint16_t)(u8_highByte)));
}