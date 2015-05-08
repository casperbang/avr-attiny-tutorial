# Code samples for basic AVR ATtiny programming
This to go with the following <a href="https://docs.google.com/presentation/d/1a2wwT4YqP0xqO45_aOEBVATeiMRD0omYGxvXWFEEeJE/edit?usp=sharing">Google Slides presentation</a>.
## blink_busywait
Very basic example of blinking an LED in a naive busy-wait loop

## blink_busywait_5_leds
Basic example of blinking 5 LED's in a naive busy-wait loop

## blink_timer_interrupt
Using hardware timer interrupt to blink an LED more effeciently

## blink_watchdog_interrupt
Using hardware watchdog interrupt to blink an LED very effeciently

## blink_hardware_pwm
Using Pulse Width Modulation (timers) to fade an LED

## button_press_interrupt
Using a hardware interrupt to detect and react to a button being pressed

## mailbox_notifier_polling
Small but complete practical example of starting blinking a LED when a mailbox receives mail and turning it off when emptying mailbox

<a href="http://www.youtube.com/watch?feature=player_embedded&v=oG53U8vux84
" target="_blank"><img src="http://img.youtube.com/vi/oG53U8vux84/0.jpg" 
alt="ATtiny mailbox notifier" width="240" height="180" border="10" /></a>


#Howto

##Install
Install the AVR GCC toolchain plus some programming software and use your favorite IDE. Sane developers would use Mac or Linux, I prefer the Debian variety of Linux so if you're on Ubuntu, Mint etc. simple do: sudo apt-get install avr-libc binutils-avr gcc-avr avrdude avarice gdb-avr

##Make
The samples use standard C make files, borrowed from WinAVR. This means compiling, linking, flashing etc. is taken care of with one command. The Makefile have a few constants you may want to tweak if you are *not* using the usbasp programmer or the ATtiny13 MCU.

* make all = Make software.
* make clean = Clean out built project files.
* make coff = Convert ELF to AVR COFF.
* make extcoff = Convert ELF to AVR Extended COFF.
* make program = Download the hex file to the device, using avrdude.
* make debug = Start either simulavr or avarice as specified for debugging, with avr-gdb or avr-insight as the front end for debugging.
* make filename.s = Just compile filename.c into the assembler code only.

---
Creative Commons
