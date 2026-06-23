#include "display.h"

#define NUMBER_OF_SCREENS 6
enum Display { H1, H0, M1, M0, S1, S0 };
enum Display Screen = H1;

extern unsigned char hours, mins, seconds;

void Setup_display(void)
{
    DDRC |= 0x0F;   // set pins to input
    PORTC &= 0xF0;  //initialize to 0

    DDRA |= 0x3F;   // digit enable pins
    PORTA |= 0x3F;  // disable all digits initially
}

void Display_Digit(unsigned char digit, unsigned char value)
{
    PORTA &= 0xC0; //set output to zer0
    PORTA |= (1<<digit);//choose enable bit
    PORTC &= 0xF0;
    PORTC |= (value & 0x0F);//display the value wanted
}

void Display_Screen(void)
{
    switch(Screen) {
        case H1: Display_Digit(PA0, hours/10); break;
        case H0: Display_Digit(PA1, hours%10); break;
        case M1: Display_Digit(PA2, mins/10);  break;
        case M0: Display_Digit(PA3, mins%10);  break;
        case S1: Display_Digit(PA4, seconds/10); break;
        case S0: Display_Digit(PA5, seconds%10); break;
    }
    Screen = (Screen + 1) % NUMBER_OF_SCREENS;
    _delay_ms(2);
}
