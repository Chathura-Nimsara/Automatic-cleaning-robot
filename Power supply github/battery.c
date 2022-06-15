#include "battery.h"

void battery_init()
{
	// AREF = AVcc
	ADMUX = (1<<REFS0);
	// ADC Enable and prescaler of 128
	ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}

// read adc value
double  battery_percentage()
{
	double presentage;
	
	uint8_t ch = ADC_PIN;
	// select the corresponding channel 0~7
	ch &= 0b00000111;  // AND operation with 7
	ADMUX = (ADMUX & 0xF8)|ch;
	// start single conversion
	// write '1' to ADSC
	ADCSRA |= (1<<ADSC);
	// wait for conversion to complete
	// ADSC becomes '0' again
	while(ADCSRA & (1<<ADSC))
	presentage=(((double)ADC/204.6)-2.61)/0.0239;
	return (presentage);
}



