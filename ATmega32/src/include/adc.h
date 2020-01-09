#ifndef ADC_H
#define ADC_H

/* AVR Library */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

/**
*	3 MODE of Reference Voltage
*		1. External VREF Pin
*		2. External AVCC Pin
*		3. Interal 2.56V
*/
#define AREF_MODE 0  
#define AVCC_MODE (1 << REFS0)
#define INT_MODE (1 << REFS1) | (1 << REFS0)

/* MODE Selection */
#define ADC_VREF_TYPE AVCC_MODE

/* ADC Pin Selection */
#define CHANNEL 1

/* ADC Initiation */
void init_adc();

/* Read ADC Value */
uint16_t read_adc(uint8_t channel);

/* Get Temperature Value */
int get_temperature();

#endif