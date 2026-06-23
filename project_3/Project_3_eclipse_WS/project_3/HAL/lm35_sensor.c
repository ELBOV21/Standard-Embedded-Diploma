/******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: lm35_sensor.c
 *
 * Description: Source file for the LM35 Temperature Sensor driver
 *
 * Author: Bavly Maged
 *
 *******************************************************************************/

#include "lm35_sensor.h"

/*
 * Description :
 * Initialize LM35 sensor (initialize ADC with required settings).
 */
void LM35_init(void)
{
    /* Initialize ADC with configured reference and scaler */
    ADC_init(LM35_ADC_VREF, LM35_ADC_SCALER);
}

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void)
{
    uint16 adc_value = 0;
    uint8 temp_value = 0;

    /* Read ADC channel where the temperature sensor is connected */
    adc_value = ADC_read(SENSOR_CHANNEL_ID);

    /* LM35: 10mV per °C => Temp = (ADC_value * Vref * 1000) / (ADC_max * 10) */
    temp_value = (uint8)(((uint32)adc_value * ADC_REF_VOLT_VALUE * 1000UL)
                        / (ADC_MAXIMUM_VALUE * 10UL));

    return temp_value;
}
