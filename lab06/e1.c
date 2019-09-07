#include <avr/io.h>
#define FOSC 16000000  //1843200 // Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1
void main( void )
{

usart_init(MYUBRR);

}

void usart_init( unsigned int ubrr)
{

UBRR0H = (unsigned char)(ubrr>>8);      //Set baud rate 
UBRR0L = (unsigned char)ubrr;
 
UCSR0B = (1<<RXEN0)|(1<<TXEN0);		//Enable receiver and transmitter

/* Set frame format: 8data, 2stop bit */
//UCSR0C = (1<<USBS0)|(3<<UCSZ00);

UCSR0C = (3<<UCSZ00);			//Set frame format: 8data, 1stop bit 

}

void usart_send( unsigned char data)
{
/* Wait for empty transmit buffer */
while ( !( UCSR0A & (1<<UDRE0)) )
;
/* Put data into buffer, sends the data */
UDR0 = data;

}

unsigned char usart_receive( void )
{
/* Wait for data to be received */
while ( !(UCSR0A & (1<<RXC0)) );
/* Get and return received data from buffer */
return UDR0;
}


