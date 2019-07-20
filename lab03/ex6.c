#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int j = 0;

int main(void) {
    DDRB = DDRB | 255;/* configure all pins of PORTB for output*/

    TCNT0 = 6; //load the timer counter register with 6
    TCCR0A = 0x00; //set the Timer0 under normal mode
    TCCR0B = 0x04; //with 1:1024 prescaler


    TIMSK0 = 1;
    sei();
    while (1) {
    };
}

ISR(TIMER0_OVF_vect){
        TCNT0 = 6; //load the timer counter register with 6
        j = (j + 1) % 25;
        if (j==0){
            PORTB = PORTB ^ (1 << 5);/* set pin 5 high to turn led on */
        }
}
