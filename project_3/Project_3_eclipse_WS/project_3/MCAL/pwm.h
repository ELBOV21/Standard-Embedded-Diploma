/******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.h
 *
 * Description: Header file for Timer0 PWM driver
 *
 * Author: Bavly Maged
 *
 *******************************************************************************/

#ifndef PWM_H_
#define PWM_H_

#include "std_types.h"

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description:
 * Function to initialize Timer0 in Fast PWM mode (non-inverting)
 * and start generating PWM with the given duty cycle.
 *
 * Parameters:
 *  duty_cycle: Percentage from 0 → 100 (%)
 */
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_H_ */
