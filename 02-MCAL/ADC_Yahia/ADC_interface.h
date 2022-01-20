/*
 * ADC_interface.h
 *
 * Created: 1/18/2022 4:21:17 PM
 *  Author: No. 01
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

void ADC_init(void);
void ADC_read(uint8_t channel, uint16_t *val);




#endif /* ADC_INTERFACE_H_ */