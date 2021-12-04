// starter code

#include <avr/io.h>
#include <util/delay.h>

void init(void)
{
  // Define pins direction (0 = read, 1 = write)
  DDRD |= 0b11111110; // Pins 0->7. 7seg on pins 1 to 7.
  DDRB |= 0b00100000; // Pins 8->13. Led on pin 13.
  // Set inital values on digital ports
  PORTB = 0b00100000; // Pins 9->16
}

void change_led_state(){
  PORTB ^= 0b00100000; // Invert pin #13 value
}

int is_switch_high() {
  // Switch is on pin #10
  // PINB is the input pin registry for pins 8 to 13
  // => When the button is pushed, PINB's second bit (10 = 8+2) is High
  return  PINB & 4; // 4 = 2^2 => check the second bit
}

/**
  7 segments display:
  -  Segments are labelled from (a) (pin #1) to (g) (pin #7)
        (a)
        ___
  (f)  |   | (b)
       |---| <------- (g)
  (e)  |___| (c)
        (d)

  - the PORTD global variable is a byte that controls the signals sent to pins 1 -> 7
  - Example:
    - to draw a zero, we need to activate a -> f, so pins 1 to 6 needs to be set to 1
                    gfedcba 
      ==> PORTD = 0b01111110;
    - to draw a two, we need to activate a, b, g, e, and d:
                    gfedcba 
      ==> PORTD = 0b10110110;    
  - do not hesitate to play with the sandbox available in the simulator to understand 
    how to use the display
**/

void display_7seg(int value){
  // Always display a 0
  PORTD = 0b01111110; // Pins 1->7 set to High
}

int main(void)
{
  init();
  while(1) //infinite loop
    {
      display_7seg(0); 
      change_led_state();
      _delay_ms(1000);     // 1Hz period
    }
  return 0;
}
