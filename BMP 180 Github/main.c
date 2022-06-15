#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <math.h>

#ifndef F_CPU
#define F_CPU 8000000L
#endif

#include <util/delay.h>

#include "bmp085.h"
#include "lcdlib.h"
#include "height.h"

int main(void) {
	double d,p;
	char printbuff[10];
	LCD_init();

	sei();

	bmp085_init();

	while(1)
	{
				
		p = bmp085_getpressure();
		d =-(1 - pow(bmp085_rawpressure/(double)101325, 0.1903 )) * 44330;
		dtostrf(d, 10, 4, printbuff);
		LCD_write_string(printbuff, 1, 2);		
		
		_delay_ms(1500);
	}
	
	return 0;
}
