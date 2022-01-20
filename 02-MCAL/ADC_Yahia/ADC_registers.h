/*
 * ADC_registers.h
 *
 * Created: 1/20/2022 4:17:44 PM
 *  Author: No. 01
 */ 


#ifndef ADC_REGISTERS_H_
#define ADC_REGISTERS_H_

#define ADMUX (*((volatile uint8_t*)(0x27)))
#define ADCSRA (*((volatile uint8_t*)(0x26)))
#define ADCH (*((volatile uint8_t*)(0x25)))
#define ADCL (*((volatile uint8_t*)(0x24)))



#endif /* ADC_REGISTERS_H_ */