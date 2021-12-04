#include <avr/io.h>
#include <util/delay.h>

int val; // value displayed on the 7 segment
int reset; // this is plain C, you do not have booleans

void init_all(void)
{
  DDRD |= 0b11111110; // write: 7seg display (#1 -> #7)
  DDRB |= 0b00100000; // write: LED (#13)
  PORTB = 0b00100000;
  val   = 0; // counter starts at 0
  reset = 0; //reset is false
}

void display_7seg(int value) {
  switch (value) {
  case 0: 
    PORTD = 0b01111110; //a,b,c,d,e,f
    break;
  case 1: 
    PORTD = 0b00001100; //b,c
    break;
  case 2: 
    PORTD = 0b10110110; //a,b,d,e,g
    break;
  case 3: 
    PORTD = 0b10011110; //a,b,c,d,g
    break;
  case 4:
    PORTD = 0b11001100; //b,c,f,g
    break;
  case 5:
    PORTD = 0b11011010; //a,c,d,f,g
    break;
  case 6: 
    PORTD = 0b11111010; //afgcde
    break;
  case 7: 
    PORTD = 0b00001110; //a,b,c
    break;
  case 8: 
    PORTD = 0b11111110; // all 
    break;
  case 9: 
    PORTD = 0b011001110; //a,b,g,f,c
    break;
  default:
    PORTD = 0b11111111;
  }
}

void change_led_state(){
  PORTB ^= 0b00100000;
}

int is_switch_high(){ 
  return  PINB & 4;
}

void change_7seg_state (int reset){
  
  if (reset || val == 10) {    
    val = 0;
  }
  display_7seg(val);
  val++;
}

int main(void)
{
  init_all();
  display_7seg(0);
  while(1)
    {
      reset = is_switch_high();
      if (reset){
        change_led_state();
      }
      change_7seg_state(reset);
      _delay_ms(1000);
    }
  
  return 0;
}