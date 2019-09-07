#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void) {

    DDRC &= ~(1 << 1); //PC1 as input, ADC1 is the channel
    DDRC = 0; //PC1 as input, ADC1 is the channel
    DDRB = 255; //PB as output
    DDRD = 255; //PD as output

    /*
     * TURN ON THE ADC MODULE
     * This bit enables the ADC. Setting this bit to '1' will enable the
        ADC, and clearing this bit to '0' will disable it even while a conversion is in progress.
     * */

    ADCSRA |= (1 << ADEN);

    /*
     * Select the conversion speed. We use registers ADPS2:0 to select the conversion speed.
     *
     * */

    ADCSRA |= (1 << ADPS0 | 1 << ADPS1 | 1 << ADPS2); // set the prescaler 128


    //use AVCC as the reference voltage
    ADMUX &= ~(1 << REFS0);
    ADMUX &= ~(1 << REFS1);

    //use ADC1 as the input channel
    ADMUX |= (1 << MUX0);

    // start conversion
    ADCSRA |= (1 << ADSC);

    ADMUX |= (1 << ADLAR); // use left justification

    unsigned int val = 0;
    while (1) {
        // start conversion
        ADCSRA |= (1 << ADSC);

        while (((ADCSRA >> ADIF) & 0x01) ==0); //Wait for the conversion to be completed by polling the ADIF bit in the ADCSRA register.

        if(ADCH<10){
            PORTD|=(1<<6);
        } else{
            PORTD&=~(1<<6);

        }

    }


}
