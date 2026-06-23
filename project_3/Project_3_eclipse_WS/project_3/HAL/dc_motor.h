/*
 * dc_motor.h
 *
 *  Created on: Sep 23, 2025
 *      Author: bavly
 */

#ifndef HAL_DC_MOTOR_H_
#define HAL_DC_MOTOR_H_
#include "std_types.h"
#include "common_macros.h"
#include"../MCAL/pwm.h"

/*Motor pin Configuration*/
#define MOTOR_IN1_PORT_ID PORTB_ID
#define MOTOR_IN2_PORT_ID PORTB_ID
#define MOTOR_IN1_PIN_ID  PIN0_ID
#define MOTOR_IN2_PIN_ID  PIN1_ID
#define MOTOR_EN_PORT_ID  PORTB_ID
#define MOTOR_EN_PIN_ID   PIN3_ID

/*Enum used to define motor state
 * STOP: motor is stopped
 * CW :motor rotating in clockwise direction
 * CCW :motor rotating in counter clockwise direction
 * */
typedef enum{
	STOP,CW,CCW
}DCMotor_state;

/*Function sets port direction and initialezes motor state as STOP*/
void DcMotor_Init(void);


void DcMotor_Rotate(DCMotor_state state,uint8 speed);
#endif /* HAL_DC_MOTOR_H_ */
