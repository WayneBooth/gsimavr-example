#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>

#ifdef __AVR_ATmega328P__
	#define DDR_IN DDRB
	#define DDR_OUT DDRC
	#define PORT_IN PORTB
	#define PORT_OUT PORTC
	#define PIN_IN PINB
	#define PIN_IN_NO PINB0 
#endif
#ifdef __AVR_ATtiny2313__
	#define DDR_IN DDRD
	#define DDR_OUT DDRB
	#define PORT_IN PORTD
	#define PORT_OUT PORTB
	#define PIN_IN PIND
	#define PIN_IN_NO PIND5 
#endif

void main() {

  // Toggle Inputs
  DDR_IN &= ~( 1 << PIN_IN_NO ); // Counter Run Toggle
  PORT_IN |= ( 1 << PIN_IN_NO );

  // Counter Out
  DDR_OUT |= 0xFF;

  while(1) {

    if( PIN_IN & ( 1 << PIN_IN_NO ) ) {
	PORT_OUT += 1;
	if( PORT_OUT > 63 ) {
		PORT_OUT = 0;
	}
	_delay_ms(1000);
    }

  }


}

