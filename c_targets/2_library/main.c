#include <avr/io.h>
#include <util/delay.h>
#include <Arduino.h>

// Vprof

int a = 1;  //For displaying segment "a"
int b = 2;  //For displaying segment "b"
int c = 3;  //For displaying segment "c"
int d = 4;  //For displaying segment "d"
int e = 5;  //For displaying segment "e"
int f = 6;  //For displaying segment "f"
int g = 7;  //For displaying segment "g"

int led = 13; // Synchronized with the shield led
const int button = 10;
int i;
boolean led_on;
int button_state = 0;

// setup is common for AC and CC
void setup() {               
  //Setup for 7 segment.
  pinMode(a, OUTPUT);  //A
  pinMode(b, OUTPUT);  //B
  pinMode(c, OUTPUT);  //C
  pinMode(d, OUTPUT);  //D
  pinMode(e, OUTPUT);  //E
  pinMode(f, OUTPUT);  //F
  pinMode(g, OUTPUT);  //G
  //Setup for LED on pin 
  pinMode(led, OUTPUT);  
  pinMode(button, INPUT);
  
  led_on=true;
  i=0;
}

void turnOff() //  this could be prettier
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}


void displayDigit(int digit)
{
  turnOff();
  //Conditions for displaying segment a
  if(digit!=1 && digit != 4)
    digitalWrite(a,HIGH);
  
 //Conditions for displaying segment b
  if(digit != 5 && digit != 6)
    digitalWrite(b,HIGH);
  
 //Conditions for displaying segment c
  if(digit !=2)
    digitalWrite(c,HIGH);
  
  //Conditions for displaying segment d
  if(digit != 1 && digit !=4 && digit !=7)
    digitalWrite(d,HIGH);
  
 //Conditions for displaying segment e 
  if(digit == 2 || digit ==6 || digit == 8 || digit==0)
    digitalWrite(e,HIGH);
 
 //Conditions for displaying segment f
  if(digit != 1 && digit !=2 && digit!=3 && digit !=7)
    digitalWrite(f,HIGH);

  if (digit!=0 && digit!=1 && digit !=7)
    digitalWrite(g,HIGH);
}


void change_state_led(){
  if (led_on){
    digitalWrite(led, LOW);
  } else
    digitalWrite(led, HIGH);
  led_on = !led_on;
}

int main(void)
{
  setup();
  while(1)
    {

      button_state=digitalRead(button);
      
      if (button_state == HIGH) {
	i=0;
	change_state_led();
      } 
      
      displayDigit(i);
      if (i==9) i=0; else i=i+1;
  
      _delay_ms(1000);
      
    }
  return 0;
}
