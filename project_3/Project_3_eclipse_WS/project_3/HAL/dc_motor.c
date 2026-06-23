/*
 * dc_motor.c
 *
 *  Created on: Sep 23, 2025
 *      Author: bavly
 */
#include "dc_motor.h"
#include "../MCAL/gpio.h"

void DcMotor_Init(void)
{
	GPIO_setupPinDirection(MOTOR_IN1_PORT_ID, MOTOR_IN1_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_IN2_PORT_ID, MOTOR_IN2_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_EN_PORT_ID, MOTOR_EN_PIN_ID, PIN_OUTPUT);

	GPIO_writePin(MOTOR_IN1_PORT_ID, MOTOR_IN1_PIN_ID, LOGIC_LOW);
	GPIO_writePin(MOTOR_IN2_PORT_ID, MOTOR_IN2_PIN_ID, LOGIC_LOW);
	GPIO_writePin(MOTOR_EN_PORT_ID, MOTOR_EN_PIN_ID, LOGIC_LOW);
}
void DcMotor_Rotate(DCMotor_state state,uint8 speed){
	switch(state)
	{
	case STOP:
		GPIO_writePin(MOTOR_IN1_PORT_ID, MOTOR_IN1_PIN_ID, LOGIC_LOW);
			GPIO_writePin(MOTOR_IN2_PORT_ID, MOTOR_IN2_PIN_ID, LOGIC_LOW);
		break;

	case CW:
		GPIO_writePin(MOTOR_IN1_PORT_ID, MOTOR_IN1_PIN_ID, LOGIC_HIGH);
			GPIO_writePin(MOTOR_IN2_PORT_ID, MOTOR_IN2_PIN_ID, LOGIC_LOW);
		break;

	case CCW:
		GPIO_writePin(MOTOR_IN1_PORT_ID, MOTOR_IN1_PIN_ID, LOGIC_LOW);
			GPIO_writePin(MOTOR_IN2_PORT_ID, MOTOR_IN2_PIN_ID, LOGIC_HIGH);
		break;
	}
	PWM_Timer0_Start(speed);
}
