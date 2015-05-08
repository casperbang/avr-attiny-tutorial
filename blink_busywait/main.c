#include <avr/io.h>
#include <util/delay.h>

#define LED PB0
#define DELAY_MS 500

int main(void)
{
    // Set port B output 0 as output
    DDRB = _BV(LED);
	
    while (1) {
        // Toggle port b output 0
		PORTB ^= _BV(LED);
        // Busy wait		
        _delay_ms(DELAY_MS);
	}
	return 0;
}
