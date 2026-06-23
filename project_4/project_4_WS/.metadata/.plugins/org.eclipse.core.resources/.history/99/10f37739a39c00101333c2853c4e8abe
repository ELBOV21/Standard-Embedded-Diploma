/******************************************************************************
 *
 * Module: LEDS
 *
 * File Name: LED.h
 *
 * Description: Header file for LEDS driver
 *
 * Author: Bavly Maged
 *
 *******************************************************************************/


#ifndef HAL_LED_H_
#define HAL_LED_H_
#include "../MCAL/gpio.h"
#include "std_types.h"
#include "common_macros.h"
/*Leds Port Configuration*/
#define RED_LED_PORT_ID PORTB_ID
#define GREEN_LED_PORT_ID PORTB_ID
#define BLUE_LED_PORT_ID PORTB_ID
/*Leds Pin Configuration*/
#define RED_LED_ID PIN5_ID
#define GREEN_LED_ID PIN6_ID
#define BLUE_LED_ID PIN7_ID
/*Leds Logic*/
#define LED_LOGIC_HIGH LOGIC_HIGH
#define LED_LOGIC_LOW LOGIC_LOW

/*enum used to define led id*/
typedef enum
{
	RED_LED,GREEN_LED,BLUE_LED
}LED_ID;

/*
 * Function used to setup led pins as outputs
 * and initialize leds to off
 *
 * */
void LEDS_init(void);
/*
 * Function turns led on according to led id
 * */
void LED_on(LED_ID id);
/*
 * Function turns led off according to led id
 * */
void LED_off(LED_ID id);


#endif /* HAL_LED_H_ */
