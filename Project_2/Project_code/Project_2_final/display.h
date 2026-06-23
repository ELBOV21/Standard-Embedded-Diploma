#ifndef DISPLAY_H
#define DISPLAY_H

#include <avr/io.h>
#include <util/delay.h>

void Setup_display(void);
void Display_Digit(unsigned char digit, unsigned char value);
void Display_Screen(void);

#endif
