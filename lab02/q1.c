#include <avr/io.h>
//#include <avr/interrupt.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 1000

int main(void) {
    DDRD &= ~(1 << 7);// PD7 is input --> digital pin 7
    DDRB |= 0b00111111;// PB0 is output --> digital pin 8

    PORTB = 0; // set all pins to zero
    while (1) {

        if ((PIND >> 7) & 1) {
//            PORTB |= (1 << 0); //set PB0 as high
//            PORTB &= ~(1 << 0); //set PB0 as low

             PORTB+=1;
             _delay_ms(BLINK_DELAY_MS);


        }


    }

    return 0;
}

//ISR(INT0_vect){
//        PORTB &= ~(1 << 0); //set PB0 as low
//        _delay_ms(BLINK_DELAY_MS);
//        PORTB |= (1<<0); //set PB0 as high
//
//}