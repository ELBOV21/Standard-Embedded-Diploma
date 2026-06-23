#ifndef TIMER_H
#define TIMER_H

#include <avr/io.h>
#include <avr/interrupt.h>

void Timer1_Init_COMP_Mode(void);
void Reset_Timer(void);
void Pause_Timer(void);
void Resume_Timer(void);

#endif
