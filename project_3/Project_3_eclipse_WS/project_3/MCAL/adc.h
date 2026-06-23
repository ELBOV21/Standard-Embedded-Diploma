/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: Header file for ADC driver
 *
 * Author: Bavly Maged
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"
#include "common_macros.h"
#define ADC_REF_VOLT_VALUE      2.56  /* If you configured ADC to use 2.56V ref */
#define ADC_MAXIMUM_VALUE       1023  /* 10-bit ADC */
typedef enum
{
    REF_AREF,
    REF_AVCC,
    REF_256V
} AdcVoltRef_type;

typedef enum
{
    ADC_SCALER_2 = 1,
    ADC_SCALER_4,
    ADC_SCALER_8,
    ADC_SCALER_16,
    ADC_SCALER_32,
    ADC_SCALER_64,
    ADC_SCALER_128
} AdcScaler_type;

typedef enum
{
    CH_0,
    CH_1,
    CH_2,
    CH_3,
    CH_4,
    CH_5,
    CH_6,
    CH_7
} Adc_channel_type;

/**
 *
 *
 * parameter1 : vref   REF_AREF - REF_AVCC - REF_256V
 * parameter2 : scaler ADC_Scaler_2 : ADC_Scaler_128
 */
extern void ADC_init(AdcVoltRef_type vref, AdcScaler_type scaler);

/**
 * Description: ADC read channel
 *
 * parameters ch CH_0 : CH_7
 * return: u16 ADC reading value 0 : 1023
 */
extern uint16 ADC_read(Adc_channel_type ch);

/**
 * Description ADC Start conversion
 *
 * parameters: ch CH_0 : CH_7
 */
extern void ADC_startConversion(Adc_channel_type ch);

/**
 * Description: Get adc read if completed
 *
 * parameters: read_ptr pointer to store adc value 0:1023
 * return: u8 (1) if get adc value, (0) if adc not finished yet
 */
extern uint8 ADC_getReadPeriodic(uint16 *read_ptr);

/**
 * Description: get value of ADC register
 *
 * Parameters: u16 ADC read after conversion completed 0:1023
 */
extern uint16 ADC_getReadNoBlock(void);

/**
 * Description: Enable ADC interrupt on conversion complete
 *
 */
extern void ADC_intEnable(void);

/**
 * Description: Disable ADC interrupt on conversion complete
 *
 */
extern void ADC_intDisable(void);

/**
 * Description: set address of the function to run when adc interrupt fired
 *
 * Parameters: localPtr address of the function
 */
extern void ADC_intSetCallBack(void (*localPtr)(void));

#endif /* ADC_H_ */
