#include "interrupts.h"
#include "timer.h"

ISR(INT1_vect)
{
    Pause_Timer();
}

ISR(INT0_vect)
{
    Reset_Timer();
}

ISR(INT2_vect)
{
    Resume_Timer();
}

void INT0_Init(void)
{
    DDRD  &= ~(1<<PD2);
    PORTD |= (1<<PD2);
    MCUCR |= (1<<ISC01);
    GICR  |= (1<<INT0);
}

void INT1_Init(void)
{
    DDRD  &= ~(1<<PD3);
    PORTD &= ~(1<<PD3);
    MCUCR |= (1<<ISC11) | (1<<ISC10);
    GICR  |= (1<<INT1);
}

void INT2_Init(void)
{
    DDRB   &= ~(1<<PB2);
    PORTB  |= (1<<PB2);
    GICR   |= (1<<INT2);
}
