#include "input.h"

extern unsigned char hours, mins, seconds;
extern unsigned char pressed_H_inc, pressed_H_dec, pressed_M_inc, pressed_M_dec, pressed_S_inc, pressed_S_dec, pressed_Toggle;

enum Mode { Count_down, Count_up };
extern enum Mode Timer_mode;

void Count_Down_Setup(void)
{
    DDRB = 0;
    PORTB = 0xFF;
}

void Adjust_Time(void)
{
    // Hours increment
    if(!(PINB & (1<<PB1))) {
        if(!pressed_H_inc) {
            hours++;
            if(hours >= 24) hours = 0;
            pressed_H_inc = 1;
        }
    } else {
        pressed_H_inc = 0;
    }

    // Hours decrement
    if(!(PINB & (1<<PB0))) {
        if(!pressed_H_dec) {
            if(hours == 0) hours = 23;
            else hours--;
            pressed_H_dec = 1;
        }
    } else {
        pressed_H_dec = 0;
    }

    // Minutes increment
    if(!(PINB & (1<<PB4))) {
        if(!pressed_M_inc) {
            mins++;
            if(mins >= 60) mins = 0;
            pressed_M_inc = 1;
        }
    } else {
        pressed_M_inc = 0;
    }

    // Minutes decrement
    if(!(PINB & (1<<PB3))) {
        if(!pressed_M_dec) {
            if(mins == 0) mins = 59;
            else mins--;
            pressed_M_dec = 1;
        }
    } else {
        pressed_M_dec = 0;
    }

    // Seconds increment
    if(!(PINB & (1<<PB6))) {
        if(!pressed_S_inc) {
            seconds++;
            if(seconds >= 60) seconds = 0;
            pressed_S_inc = 1;
        }
    } else {
        pressed_S_inc = 0;
    }

    // Seconds decrement
    if(!(PINB & (1<<PB5))) {
        if(!pressed_S_dec) {
            if(seconds == 0) seconds = 59;
            else seconds--;
            pressed_S_dec = 1;
        }
    } else {
        pressed_S_dec = 0;
    }
}

void Check_Mode(void)
{
    if(!(PINB & (1<<PB7))) {
        if(!pressed_Toggle) {
            if (Timer_mode == Count_up) {
                Timer_mode = Count_down;
                PORTD &= ~(1<<PD4);
                PORTD |= (1<<PD5);
            }
            else if(Timer_mode == Count_down) {
                Timer_mode = Count_up;
                PORTD |= (1<<PD4);
                PORTD &= ~(1<<PD5);
            }
            pressed_Toggle = 1;
        }
    } else {
        pressed_Toggle = 0;
    }
}
