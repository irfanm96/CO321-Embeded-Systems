#include <avr/io.h>
#include <avr/interrupt.h>

int j = 0;
int k = 0;

int main(void) {
    DDRB = DDRB | 255;/* configure all pins of PORTB for output*/

        TCNT0 = 203; //load the timer counter register with 116
    TCCR0A = 0x00; //set the Timer0 under normal mode
    TCCR0B = 0x04; //with 1:256 prescaler



    TCNT1 = 34286; //load the timer counter register with 34286
    TCCR1A = 0x00; //set the Timer0 under normal mode
    TCCR1B = 0x04; //with 1:256 prescaler


    TIMSK1 = 1;
    TIMSK0 = 1;

    sei();
    while (1) {
    };
}

ISR(TIMER0_OVF_vect){

        j = (j + 1) % 13;
        if (j==0){
            PORTB = PORTB ^ (1 << 5);/* set pin 5 high to turn led on */
            TCNT0 = 203; //load the timer counter register with 116

        }
}
ISR(TIMER1_OVF_vect){

        PORTB = PORTB ^ (1 << 4);/* set pin 5 high to turn led on */
        TCNT1 = 34286; //load the timer counter register with 34286

}
