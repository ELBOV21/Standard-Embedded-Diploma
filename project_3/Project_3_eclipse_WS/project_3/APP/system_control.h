
 /******************************************************************************
 *
 * Module:
 *
 * File Name: system_control.h
 *
 * Description: Header file for the AVR GPIO driver
 *
 * Author: Bavly Maged
 *
 *******************************************************************************/

#ifndef SYSTEM_CONTROL_H_
#define SYSTEM_CONTROL_H_

#include "std_types.h"

/* Enum to represent the fan's current state */
typedef enum {
    FAN_OFF,
    FAN_ON
} FanState;

/*
 * Initializes all system peripherals (LCD, sensors, actuators).
 * Must be called once at the beginning of main().
 */
void System_Init(void);

/*
 * Updates system state by:
 *   - Reading sensors
 *   - Controlling fan and lights
 *   - Handling fire alert if detected
 *   - Updating the LCD
 */
void System_Update(void);

#endif /* SYSTEM_CONTROL_H_ */

