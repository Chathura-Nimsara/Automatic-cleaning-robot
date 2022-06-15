/*
 * height.c
 *
 * Created: 5/24/2022 5:35:12 PM
 *  Author: 99wak
 */ 
#include "bmp085.h"
#include "lcdlib.h"
#include "height.h"

double messure_height()
{
	long l;
	double d;
	char printbuff[10];
	
	d = bmp085_getaltitude();
	dtostrf(d, 10, 2, printbuff);
	LCD_write_string(printbuff, 1, 2);
	
	_delay_ms(1500);
	
}