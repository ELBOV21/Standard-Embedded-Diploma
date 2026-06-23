/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.C
 *
 * Description: Source file for ADC driver
 *
 * Author: Bavly Maged
 *
 *******************************************************************************/

#include "adc.h"
#include <avr/io.h>

/* pointer to function to use it in callback function */
static void (*adc_fPtr)(void) = NULL_PTR;

/* to prevent start conversion before the previous is finished */
static uint8 reading_flag = 1;

void ADC_init(AdcVoltRef_type vref, AdcScaler_type scaler)
{
    /* voltage reference */
    switch (vref)
    {
    case REF_AREF:
    	 CLEAR_BIT(ADMUX, REFS0);
    	 CLEAR_BIT(ADMUX, REFS1);
        break;

    case REF_AVCC:
        SET_BIT(ADMUX, REFS0);
        CLEAR_BIT(ADMUX, REFS1);
        break;

    case REF_256V:
        SET_BIT(ADMUX, REFS0);
        SET_BIT(ADMUX, REFS1);
        break;
    }

    /* clock initialize */
    ADCSRA = ADCSRA & 0xF8;
    ADCSRA = ADCSRA | scaler;

    /* left adjustment */
    CLEAR_BIT(ADMUX, ADLAR);

    /* enable ADC */
    SET_BIT(ADCSRA, ADEN);
}

uint16 ADC_read(Adc_channel_type ch)
{
    uint16 read = 0;
    /* channel selection */
    ADMUX = ADMUX & 0xE0;
    ADMUX = ADMUX | (ch & 0x1F);

    /* ADC start conversion */
    SET_BIT(ADCSRA, ADSC);

    /* polling till conversion complete */
    while (1 == GET_BIT(ADCSRA, ADSC));

    /* get first 10 bits */
    read = ADC & 0x03FF;

    return read;
}

void ADC_startConversion(Adc_channel_type ch)
{
    if (reading_flag == 1)
    {
        /* Channel selection */
        ADMUX = ADMUX & 0xE0;
        ADMUX = ADMUX | (ch & 0x1F);

        /* ADC start conversion */
        SET_BIT(ADCSRA, ADSC);
        reading_flag = 0;
    }
}

uint8 ADC_getReadPeriodic(uint16 *read_ptr)
{
    /* if conversion completed */
    if (0 == GET_BIT(ADCSRA, ADSC))
    {
        *read_ptr = ADC;
        reading_flag = 1;
        return 1;
    }
    return 0;
}

uint16 ADC_getReadNoBlock(void)
{
    return ADC;
}

void ADC_intEnable(void)
{
    SET_BIT(ADCSRA, ADIE);
}

void ADC_intDisable(void)
{
	CLEAR_BIT(ADCSRA, ADIE);
}

void ADC_intSetCallBack(void (*localPtr)(void))
{
    adc_fPtr = localPtr;
}

ISR(ADC_VECT)
{
    if (adc_fPtr != NULL_PTR)
    {
        adc_fPtr();
    }
}
