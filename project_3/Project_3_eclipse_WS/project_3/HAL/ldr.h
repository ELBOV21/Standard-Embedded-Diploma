/******************************************************************************
 *
 * Module: LDR
 *
 * File Name: ldr.h
 *
 * Description: Header file for Ldr driver
 *
 * Author: Bavly Maged
 *
 *******************************************************************************/

#ifndef HAL_LDR_H_
#define HAL_LDR_H_

#include "std_types.h"
#include "../MCAL/adc.h"

/*ldr pin configuration*/
#define LDR_SENSOR_CHANNEL_ID CH_0

/* LDR sensor max voltage*/
#define LDR_SENSOR_MAX_VOLT_VALUE 2.56

/*LDR Refrence Voltage*/
#define LDR_ADC_VREF           REF_256V      /* REF_AVCC, REF_AREF, REF_256V */

/* Select ADC prescaler */
#define LDR_ADC_SCALER         ADC_SCALER_128

/*LDR sensor max intensity set to 100%*/
#define LDR_SENSOR_MAX_LIGHT_INTENSITY 100

/*Function returns the light intensity 0-->100*/
uint16 LDR_getLightIntensity(void);


#endif /* HAL_LDR_H_ */
