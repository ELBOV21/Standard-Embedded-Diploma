#include "buzzer.h"

void Buzzer_Setup(void)
{
    DDRD |= (1<<PD0);
    PORTD &= ~(1<<PD0);
}

void Activate_Buzzer(void)
{
    PORTD |= (1<<PD0);
}
