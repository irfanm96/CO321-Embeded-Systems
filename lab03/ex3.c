#include <avr/io.h>

void delay_timer0() {
    TCNT0 = 131; //load the timer counter register with 116

    TCCR0A = 0x00; //set the Timer0 under normal mode
    TCCR0B = 0x04; //with 1:256 prescaler

    while ((TIFR0 & 0x01) == 0); //wait  till timer overflow bit T0V0 is set

    TCCR0A = 0x00; //clear timer settings this stops the timer
    TCCR0B = 0x00;

    TIFR0 = 0x01; // clear the timer overflow bit T0V0 for the next round

    //in order to clear it,we should  write 1

}


int main(void){
    DDRB|= (1<<5); //PB5 as output
    while (1){
        PORTB=PORTB ^ (1<<5); //toggle
        delay_timer0();
    }
}
