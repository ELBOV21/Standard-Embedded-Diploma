/******************************************************************************
 *
 * Module: LEDS
 *
 * File Name: LED.c
 *
 * Description: Source file for LEDS driver
 *
 * Author: Bavly Maged
 *
 *******************************************************************************/

#include "led.h"
#include "common_macros.h"
#include "std_types.h"

void LEDS_init(void)
{
	/*SETUP LED PINS TO INPUT*/
	GPIO_setupPinDirection(RED_LED_PORT_ID, RED_LED_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(GREEN_LED_PORT_ID, GREEN_LED_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(BLUE_LED_PORT_ID, BLUE_LED_ID, PIN_OUTPUT);
	/* initialize leds to off*/
	GPIO_writePin(RED_LED_PORT_ID, RED_LED_ID, LED_LOGIC_LOW);
	GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_ID, LED_LOGIC_LOW);
	GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_ID, LED_LOGIC_LOW);
}

void LED_on(LED_ID id){
	switch (id)
	{
	case RED_LED:
		GPIO_writePin(RED_LED_PORT_ID, RED_LED_ID, LED_LOGIC_HIGH);
		break;
	case GREEN_LED:
		GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_ID, LED_LOGIC_HIGH);
		break;
	case BLUE_LED:
		GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_ID, LED_LOGIC_HIGH);
		break;

	}
}

void LED_off(LED_ID id){
	switch (id)
	{
	case RED_LED:
		GPIO_writePin(RED_LED_PORT_ID, RED_LED_ID, LED_LOGIC_LOW);
		break;
	case GREEN_LED:
		GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_ID, LED_LOGIC_LOW);
		break;
	case BLUE_LED:
		GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_ID, LED_LOGIC_LOW);
		break;
	}
}
