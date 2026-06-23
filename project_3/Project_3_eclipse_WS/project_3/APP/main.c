#include "system_control.h"

int main(void)
{
	/*Initialize All Devices*/
    System_Init();

    while(1) {
    	 /* Continuously update system behavior*/
        System_Update();
    }
}
