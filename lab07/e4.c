#include <avr/io.h>
#include <string.h>
#include <stdlib.h>
#include <util/delay.h>

#define FOSC 16000000  //1843200 // Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

void usart_init(unsigned int ubrr);

unsigned char usart_receive(void);

void usart_send(char c);

char EEPROMread(unsigned int address) {
    while (EECR & (1 << EEPE));//wait for completion of previous write

    //set up address
    EEAR = address;

    //start eeprom read
    EECR |= (1 << EERE);

    //return data
    return EEDR;
}

void EEPROMwrite(unsigned int address, char data) {
    while (EECR & (1 << EEPE)); //wait for completion of previous write

    //set up address and data regs
    //EEAR = address;
    //EEARH=0x00;
    EEAR = address;
    EEDR = data;

    //write logical 1 to EEMPE
    EECR |= (1 << EEMPE);

    //start eeprom write
    EECR |= (1 << EEPE);
}

int main() {
    usart_init(MYUBRR);

    EECR &= ~(1 << EEPM0);
    EECR &= ~(1 << EEPM1);

    while (1){
        int i=0;
        while (i < 1024) {
            char a = EEPROMread(i);
            usart_send(a);
            i++;
        }
        usart_send('\n');
        _delay_ms(100);
    }

    return 0;

}




void usart_init(unsigned int ubrr) {
    UBRR0H = (unsigned char) (ubrr >> 8);      //Set baud rate
    UBRR0L = (unsigned char) ubrr;

    UCSR0B = (1 << RXEN0) | (1 << TXEN0);        //Enable receiver and transmitter

    UCSR0C = (3 << UCSZ00);            //Set frame format: 8data, 1stop bit

}


void usart_send(char c) {
    UCSR0B |= (1 << TXEN0);//Transmitter enable
    UDR0 = c;
    while (!(UCSR0A & (1 << UDRE0))) {//wait
        //wait
    }

}


unsigned char usart_receive(void) {

    UCSR0B |= (1 << RXEN0);//Reciever enable
/* Wait for data to be received */
    while (!(UCSR0A & (1 << RXC0)));
/* Get and return received data from buffer */
    return UDR0;
}

