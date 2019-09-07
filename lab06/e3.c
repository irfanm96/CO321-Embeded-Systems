#include <avr/io.h>
#include <string.h>
#include <stdlib.h>
#define FOSC 16000000  //1843200 // Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

void usart_init(unsigned int ubrr);

unsigned char usart_receive(void);

void usart_send(char c);

int main() {
    usart_init(MYUBRR);
    while (1) {
        char c = usart_receive();
            if (c >= 'A' && c <= 'Z') {
                c = (char) ((c - 'A' + 3) % 26 + 'A');
            } else if (c >= 'a' && c <= 'z') {
                c = (char) ((c - 'a' + 3) % 26 + 'a');
            }
        usart_send(c);
    }


    return 0;
}

void usart_init(unsigned int ubrr) {
    UBRR0H = (unsigned char) (ubrr >> 8);      //Set baud rate
    UBRR0L = (unsigned char) ubrr;

    UCSR0B = (1 << RXEN0) | (1 << TXEN0);        //Enable receiver and transmitter

    UCSR0C = (3 << UCSZ00);            //Set frame format: 8data, 1stop bit

}


void usart_send(char c){
    UCSR0B |= (1<<TXEN0);//Transmitter enable
    UDR0=c;
    while(!(UCSR0A & (1<<UDRE0))){//wait
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

