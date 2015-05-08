#include <avr/io.h> 
#include <util/delay.h> 

#define LED PB0

int main (void){ 
    // Set port B output 0 as output
    DDRB |= _BV(LED); 
    
    // COM0A1 - COM0A0 (Set OC0A on Compare Match, clear OC0A at TOP, set fast PWM)
    TCCR0A |= (_BV(COM0A1) | _BV(COM0A0) | _BV(WGM01) | _BV(WGM00));
    
    // Initialize Output Compare Register A to 0
    OCR0A = 0;
    
    // Start timer at Fcpu / 256 
    TCCR0B |= (1 << CS01);

    for (int i;;){
        // Update Output Compare Register (PWM 0-100%)
        for (i = 0 ; i < 255 ; i++ ){ 
            OCR0A = i;
            _delay_ms(5);
        }
        // Update Output Compare Register (PWM 100%-0)         
        for (i = 255 ; i > 0 ; i-- ){
            OCR0A = i;
            _delay_ms(5); 
        }
    } 
}
