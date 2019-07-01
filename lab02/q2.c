#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 100

int main(void) {
    DDRD &= ~(1 << 2);// PD2 INT0 is input
    DDRB =0b00111111;// PB0 is output


    EICRA |= (1 << ISC01); // set for rising edge detection
    EICRA |= (1 << ISC00); // set for rising edge detection




    sei(); //enable global interrupts
    EIMSK |= (1 << INT0); //enable external interrupts for int0


    while (1) {

    }

    return 0;
}

ISR(INT0_vect){



//        if ((PORTB >> 0) & 1 ){
//            PORTB &= ~(1 << 0);
//        }else{
//            PORTB |= (1 << 0);
//
//        }

         PORTB+=1;
//        _delay_ms(BLINK_DELAY_MS);

}