#include "timer.h"
#include "buzzer.h"

extern unsigned char hours, mins, seconds;
extern unsigned char Is_Paused;

enum Mode { Count_down, Count_up };
enum Mode Timer_mode = Count_up;

void Timer1_Init_COMP_Mode(void)
{
    TCNT1 = 0;
    OCR1A = 15624;               // 1 second (16MHz / 1024)
    TIMSK |= (1<<OCIE1A);
    TCCR1A = (1<<FOC1A);
    TCCR1B = (1<<WGM12) | (1<<CS12) | (1<<CS10);
}

void Reset_Timer(void)
{
    PORTD &= ~(1<<PD0);
    seconds=0; mins=0; hours=0;
}

void Pause_Timer(void)
{
    PORTD &= ~(1<<PD0);
    TCCR1B = 0;
    Is_Paused=1;
}

void Resume_Timer(void)
{
    TCCR1B = (1<<WGM12) | (1<<CS12) | (1<<CS10);
    Is_Paused=0;
}

ISR(TIMER1_COMPA_vect)
{
    if (Timer_mode == Count_up) {
        seconds++;
        if(seconds >= 60) { seconds = 0; mins++; }
        if(mins >= 60)    { mins = 0; hours++; }
        if(hours >= 24)   { hours = 0; }
    }
    else if(Timer_mode == Count_down)
    {
        if(seconds == 0 && mins == 0 && hours == 0) {
            Activate_Buzzer();
        } else {
            if(seconds > 0) {
                seconds--;
            } else {
                seconds = 59;
                if(mins > 0) {
                    mins--;
                } else {
                    mins = 59;
                    if(hours > 0) {
                        hours--;
                    }
                }
            }
        }
    }
}
