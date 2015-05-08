#include <avr/io.h> 
#include <avr/interrupt.h> 
#include <avr/sleep.h> 

#define LED PB0
#define SWITCH PINB3

ISR(PCINT0_vect) {
    if (PINB & _BV(SWITCH))
        PORTB ^= _BV(LED);
}

int main(void)
{ 
	DDRB |= _BV(LED);       // Set port b0 as output (all others are input)
	
	PCMSK |= _BV(SWITCH);   // Set pin change interrupt mask to listen to port b3
	
	MCUCR = _BV(ISC01) | _BV(ISC00);    // Set interrupt on INT0 pin falling edge (high pulled to low)
	
	GIMSK |= _BV(PCIE);     // Enable PCINT interrupt 

	sei();  	            // Global interrupts 

	set_sleep_mode(SLEEP_MODE_PWR_DOWN);

	for (;;) {
		sleep_mode();
	}
}
