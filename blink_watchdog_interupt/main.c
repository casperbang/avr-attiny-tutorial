#include <avr/interrupt.h>
#include <avr/sleep.h>

#define LED PB0

ISR(WDT_vect) {
    // Toggle port B output 0 output state
    PORTB ^= _BV(LED);
}

int main(void) {
    // Set port B output 0 as output
    DDRB = _BV(LED);

    // Prescale timer to 4s
    WDTCR |= (1<<WDP2) | (1<<WDP0);

    // Enable watchdog timer interrupts
    WDTCR |= (1<<WDTIE);

    // Enable global interrupts 
    sei();

    // Use the Power Down sleep mode
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);

    for (;;) {
        sleep_mode(); // Deep sleep, waiting for interrupt
    }
}
