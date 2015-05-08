#include <avr/io.h>
#define F_CPU 1200000UL
#include <util/delay.h>

int main(void)
{
    DDRB = 1<<PB0 | 1<<PB1 | 1<<PB2 | 1<<PB3 | 1<<PB4;

	//DDRB |= (1 << (PB3));		/* Set PORTB bit 4 to output. */

    PORTB &= ~(1 << PB0);
    PORTB &= ~(1 << PB1);
    PORTB &= ~(1 << PB2);
    PORTB &= ~(1 << PB3);
    PORTB &= ~(1 << PB4);

	while (1) {

		PORTB |= (1 << PB0);
		_delay_ms(50);
		PORTB &= ~(1 << PB0);
		_delay_ms(50);

		PORTB |= (1 << PB1);
		_delay_ms(50);
		PORTB &= ~(1 << PB1);
		_delay_ms(50);

		PORTB |= (1 << PB2);
		_delay_ms(50);
		PORTB &= ~(1 << PB2);
		_delay_ms(50);

		PORTB |= (1 << PB3);
		_delay_ms(50);
		PORTB &= ~(1 << PB3);
		_delay_ms(50);

		PORTB |= (1 << PB4);
		_delay_ms(50);
		PORTB &= ~(1 << PB4);
		_delay_ms(50);


	}

	return 0;
}
