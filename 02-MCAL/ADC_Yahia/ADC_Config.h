/*
 * ADC_Config.h
 *
 * Created: 1/18/2022 4:21:03 PM
 *  Author: No. 01
 */ 


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

#define OUTPUT 1
#define INPUT 0
#define HIGH 1
#define LOW 0

/*ADMUX BITS**/

#define REFS1 7
#define REFS0 6
#define ADLAR 5
#define MUX4 4
#define MUX3 3
#define MUX2 2
#define MUX1 1
#define MUX0 0

/*ADCSRA bits*/
#define ADEN 7
#define ADSC 6
#define ADATE 5
#define ADIF 4
#define ADIE 3 
#define ADPS2 2
#define ADPS1 1 
#define ADPS0 0




#endif /* ADC_CONFIG_H_ */