#include <avr/io.h>
#include <avr/interrupt.h>
int j=0;

void delay_timer1() {
    TCNT1 = 59286; //load the timer counter register with 116
    TIFR1 = 0x01; // clear the timer overflow bit T0V0 for the next round

    TCCR1A = 0x00; //set the Timer0 under normal mode
    TCCR1B = 0x04; //with 1:256 prescaler

    while ((TIFR1 & 0x01) == 0); //wait  till timer overflow bit T0V0 is set

    TCCR1A = 0x00; //clear timer settings this stops the timer
    TCCR1B = 0x00;

    TIFR1 = 0x01; // clear the timer overflow bit T0V0 for the next round

    //in order to clear it,we should  write 1

}


int main(void) {
    DDRB = DDRB | 255;/* configure all pins of PORTB for output*/

    TCNT1 = 59286; //load the timer counter register with 116
    TCCR1A = 0x00; //set the Timer0 under normal mode
    TCCR1B = 0x04; //with 1:256 prescaler


//    TIMSK1=1;

    sei();
    while (1) {
        for (int i = 2; i < 6; ++i) {
            PORTB = PORTB | (1 << i);/* set pin 5 high to turn led on */
            delay_timer1();
            j=(j+1)%10;
            if(j==0){PORTB = PORTB ^ (1 << 1); }

                PORTB = PORTB & ~(1 << i);/* set pin 5 high to turn led on */

        }
        for (int i = 5; i > 2; i--) {
            PORTB = PORTB | (1 << i);/* set pin 5 high to turn led on */
            delay_timer1();
            j=(j+1)%10;
            if(j==0){PORTB = PORTB ^ (1 << 1);}
            PORTB = PORTB & ~(1 << i);/* set pin 5 high to turn led on */

        }
    };
}
