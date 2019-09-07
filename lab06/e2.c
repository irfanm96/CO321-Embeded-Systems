#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#define FOSC 16000000  //1843200 // Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

void usart_init(unsigned int ubrr);

void sendLine(char arr[]);

void main(void) {
    usart_init(MYUBRR);
    char arr[] = "E15209 Kithma, E15138 Irfan, E15307 Rishi\n";
    sendLine(arr);

}


void usart_init(unsigned int ubrr) {
    UBRR0H = (unsigned char) (ubrr >> 8);      //Set baud rate
    UBRR0L = (unsigned char) ubrr;

    UCSR0B = (1 << RXEN0) | (1 << TXEN0);        //Enable receiver and transmitter

    UCSR0C = (3 << UCSZ00);            //Set frame format: 8data, 1stop bit

}

void sendLine(char arr[]) {
    int i = 0;
    while (1) {
/* Wait for empty transmit buffer */
        //while ( !( UCSR0A & (1<<UDRE0)));
        for (i = 0; i < strlen(arr); i++) {
            while (!(UCSR0A & (1 << UDRE0)));
            /* Put data into buffer, sends the data */
            UDR0 = arr[i];
            if (i == (strlen(arr) - 1)) {
                break;
            }
        }
      _delay_ms(500);
    }
}

