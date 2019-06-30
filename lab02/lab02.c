#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 1000

int main(void) {
    DDRB = DDRB | 0b00111100;/* configure pin 5 of PORTB for output*/
    while (1) {

        for (int i = 2; i < 6; ++i) {
            PORTB = PORTB | (1 << i);/* set pin 5 high to turn led on */

        }
        _delay_ms(BLINK_DELAY_MS);
        for (int i = 2; i < 6; ++i) {
            PORTB = PORTB & ~(1 << i);/* set pin 5 high to turn led on */

        }
        _delay_ms(BLINK_DELAY_MS);


    }
}
