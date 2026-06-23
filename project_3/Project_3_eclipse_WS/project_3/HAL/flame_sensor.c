



#include "flame_sensor.h"
#include "std_types.h"
void FlameSensor_init(void)
{
	GPIO_setupPinDirection(FLAME_SENSOR_PORT_ID, FLAME_SENSOR_PIN_ID, PIN_INPUT);
	}

uint8 FlameSensor_getValue(void)
{
	uint8 reading=0;
	reading=GPIO_readPin(FLAME_SENSOR_PORT_ID,FLAME_SENSOR_PIN_ID );
	return reading;
}
