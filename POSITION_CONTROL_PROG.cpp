#include "STD_TYPES.h"
#include "POSITION_CONTROL_CONFIG.h"
#include <Arduino.h>

void positionControlInit(){
    
    attachInterrupt(
      digitalPinToInterrupt(MAGNETIC_ENCODER_PIN_A),
      ISR_magneticEncoderCount(),
      CHANGE);
    attachInterrupt(
      digitalPinToInterrupt(MAGNETIC_ENCODER_PIN_B),
      ISR_magneticEncoderCount(),
      CHANGE);
}


void ISR_magneticEncoderCount(){
  bool MagAReading = digitalRead(MAGNETIC_ENCODER_PIN_A);
  bool MagBReading = digitalRead(MAGNETIC_ENCODER_PIN_B);

  if(MagBReading == LOW && MagBReading == HIGH){ // clock wise direction
    
  }
}
