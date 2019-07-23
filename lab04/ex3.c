#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void) {
    DDRD |= (1 << 6); //PD6 as output


    TCCR0A |= (1 << WGM01); //set the Timer0 under fast pwm mode
    TCCR0A |= (1 << WGM00); //set the Timer0 under fast pwm mode
//    TCCR0A |= (1 << WGM02); //set the Timer0 under fast pwm mode

    TCCR0A |= (1 << COM0A1);
    OCR0A = 180; //

//    TCCR0B = 0x01;

    sei();
    while (1) {
        TCCR0B = 2;
        _delay_ms(1000);
        TCCR0B = 3;
        _delay_ms(1000);
        TCCR0B = 4;
        _delay_ms(1000);
        TCCR0B = 5;
        _delay_ms(1000);

    }


}
