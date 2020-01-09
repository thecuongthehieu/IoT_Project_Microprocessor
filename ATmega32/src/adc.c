#include "include/adc.h"

void init_adc()
{
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS0);
	ADMUX = ADC_VREF_TYPE;
}

uint16_t read_adc(uint8_t channel)
{
	ADMUX |= channel;
	ADCSRA |= (1 << ADSC);
	loop_until_bit_is_set(ADCSRA, ADIF);
	return ADCW;
}

int get_temperature() {
	uint16_t adc_value = read_adc(CHANNEL);
	int temp = adc_value / 2.01;
	return temp;
}