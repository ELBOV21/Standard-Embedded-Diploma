/******************************************************************************
 *
 * Module: Flame Sensor
 *
 * File Name: flame_sensor.h
 *
 * Description: Header file for Flame Sensor driver
 *
 * Author: Bavly Maged
 *
 *******************************************************************************/

#ifndef HAL_FLAME_SENSOR_H_
#define HAL_FLAME_SENSOR_H_

#include "../MCAL/gpio.h"
#include "std_types.h"
#include "common_macros.h"

/*Flame Sensor pin Configuration*/
#define FLAME_SENSOR_PORT_ID PORTD_ID
#define FLAME_SENSOR_PIN_ID  PIN2_ID

/*Function sets flame sensor pin as output*/
void FlameSensor_init(void);
/*
 * Function returns the Reading og flame sensor
 *  if 1 --> Flame
 *  if 0 --> no FLame
 * */
uint8 FlameSensor_getValue(void) ;


#endif /* HAL_FLAME_SENSOR_H_ */
