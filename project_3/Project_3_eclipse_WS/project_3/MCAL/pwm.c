/******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.c
 *
 * Description: Source file for Timer0 PWM driver
 *
 * Author: Bavly Maged
 *
 *******************************************************************************/

#include "pwm.h"
#include <avr/io.h>

/*
 * Description:
 * Function to initialize Timer0 in Fast PWM mode (non-inverting)
 * and start generating PWM with the given duty cycle.
 */
void PWM_Timer0_Start(uint8 duty_cycle)
{
    /* ---------------- Configure OC0 (PB3) as output pin ---------------- */
    DDRB |= (1<<PB3);

    /* ---------------- Set Fast PWM mode ----------------
     * WGM00 = 1, WGM01 = 1 → Fast PWM
     */
    TCCR0 |= (1<<WGM00) | (1<<WGM01);

    /* ---------------- Non-inverting mode ----------------
     * COM01 = 1, COM00 = 0
     */
    TCCR0 |= (1<<COM01);
    TCCR0 &= ~(1<<COM00);

    /* ---------------- Set clock prescaler F_CPU/1024 ----------------
     * CS02 = 1, CS01 = 0, CS00 = 1
     */
    TCCR0 |= (1<<CS02) | (1<<CS00);
    TCCR0 &= ~(1<<CS01);

    /* ---------------- Set duty cycle ----------------
     * OCR0 = (duty_cycle / 100) * 255
     */
    OCR0 = (uint8)(((uint32)duty_cycle * 255) / 100);
}
