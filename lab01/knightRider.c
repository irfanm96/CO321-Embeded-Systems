#include <avr/io.h>
#include <util/delay.h>
#define BLINK_DELAY_MS 200
int main (void){
    DDRB = DDRB | 255;/* configure pin 5 of PORTB for output*/
    while(1){

        for (int i = 2; i < 6; ++i) {
            PORTB = PORTB | (1 << i);/* set pin 5 high to turn led on */
            _delay_ms(BLINK_DELAY_MS);
            PORTB = PORTB & ~(1 << i);/* set pin 5 high to turn led on */

        }
        for (int i = 5; i > 2; i--) {
            PORTB = PORTB | (1 << i);/* set pin 5 high to turn led on */
            _delay_ms(BLINK_DELAY_MS);
            PORTB = PORTB & ~(1 << i);/* set pin 5 high to turn led on */

        }

    }
}