#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>

void main() {

  // Outputs to the shift register
  DDRB &= ~( 1 << PINB0 ); // Counter Run Toggle
  PORTB |= ( 1 << PINB0 );

  // Counter Out
  DDRC |= 0xFF;

  while(1) {

    if( PINB & ( 1 << PINB0 ) ) {
	PORTC += 1;
	if( PORTC > 63 ) {
		PORTC = 0;
	}
	_delay_ms(1000);
    }

  }


}

