#include <avr/io.h>
#include <avr/interrupt.h>
#include "display.h"
#include "timer.h"
#include "interrupts.h"
#include "input.h"
#include "buzzer.h"

// ===== Global Variables =====
unsigned char hours = 0, mins = 0, seconds = 0;
unsigned char pressed_H_inc = 0, pressed_H_dec = 0;
unsigned char pressed_M_inc = 0, pressed_M_dec = 0;
unsigned char pressed_S_inc = 0, pressed_S_dec = 0;
unsigned char pressed_Toggle = 0;
unsigned char Is_Paused = 0;

int main(void)
{
    // Led setup
    DDRD |= 0x30;          // PD4 + PD5 as output
    PORTD |= (1<<PD4);     // red LED ON initially
    PORTD &= ~(1<<PD5);    // yellow LED OFF initially


    Count_Down_Setup();     // buttons input setup
    Buzzer_Setup();         // buzzer setup
    INT0_Init();            // reset interrupt
    INT1_Init();            // pause interrupt
    INT2_Init();            // resume interrupt
    Setup_display();        // 7-seg setup
    Timer1_Init_COMP_Mode();// timer1 setup
    sei();                  // enable I-bit

    // ===== Main Loop =====
    while(1)
    {
        Display_Screen();//update the screen

        if(Is_Paused) {
            Adjust_Time();  // allow user to adjust
            Check_Mode();   // allow user to switch mode
        }
    }
}
