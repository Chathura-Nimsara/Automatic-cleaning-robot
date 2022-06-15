#ifndef BATTERY_H_
#define BATTERY_H_

#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include <avr/io.h>

#define ADC_PIN PA3

void battery_init();
double battery_percentage();

#endif /* BATTERY_H_ */