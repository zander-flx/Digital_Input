const uint8_t SW1 = 12;
const uint8_t SW2 = 13;

bool SW1_state = 0;
bool SW2_state = 0;

uint8_t const LED[] = {32, 33, 25, 26, 27, 14};
uint8_t NUM_PINS = 6;
uint8_t const LIMIT = 3;

void setup() {
  // put your setup code here, to run once:

  for(uint8_t a = 0 ; a < NUM_PINS ; a++){
    pinMode(LED[a],  OUTPUT);
    }
  pinMode(SW1, INPUT);  
  pinMode(SW2, INPUT);  
}

#include "LED_MODES.h"

void loop() {
  // put your main code here, to run repeatedly:
  
  SW1_state = digitalRead(SW1);
  SW2_state = digitalRead(SW2);
  
  if (SW1_state && SW2_state){
    run();
  } else if(SW1_state){
    alt();
  } else if(SW2_state){
    blink();
  } else{
    for(uint8_t a = 0 ; a < NUM_PINS ; a++){
        digitalWrite(LED[a], LOW);
      }
  }
}
