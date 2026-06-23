/******************************************************************************
 *
 * File Name: app.h
 *
 * Description: Header file for the application
 *
 * Author: Bavly Maged Naguib
 *
 *******************************************************************************/


#ifndef APP_H_
#define APP_H_

#include "../MCAL/std_types.h"
/*
 * Function initializes
 * 1)led
 * 2)lcd
 * 3)buzzer
 * 4)ultasonic
 * */
void APP_init(void);

/*
 * function updates system parameters
 * */
void APP_update(void);

#endif /* APP_H_ */
