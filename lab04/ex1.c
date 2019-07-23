#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void delay_timer0() {
//    TCNT0 = 131; //load the timer counter register with 116

//    TCCR0A = (1<<WGM01); //set the Timer0 under fast pwm mode
//    TCCR0A = (1<<WGM01); //set the Timer0 under fast pwm mode

//    TCCR0B = 0x03; //with 1:64 prescaler

//    while ((TIFR0 & 0x01) == 0); //wait  till timer overflow bit T0V0 is set

//    TCCR0A = 0x00; //clear timer settings this stops the timer
//    TCCR0B = 0x00;

//    TIFR0 = 0x01; // clear the timer overflow bit T0V0 for the next round

    //in order to clear it,we should  write 1

}


int main(void) {
    DDRD |= (1 << 6); //PD6 as output


    TCCR0A |= (1 << WGM01); //set the Timer0 under fast pwm mode
    TCCR0A |= (1 << WGM00); //set the Timer0 under fast pwm mode

    TCCR0A |= (1 << COM0A1); //set output toggle

    OCR0A = 0; //
    TCCR0B = 0x03; //with 1:64 prescaler

    sei();
    int i = 0;
    int state = 0;
    while (1) {
        _delay_ms(100);
        if (i == 0)
        { state = 0; }
        if (i == 255)
        { state = 1; }
        if (state == 1) { i--; } else { i++; }
        OCR0A = i;
    }


}
