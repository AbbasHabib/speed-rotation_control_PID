#include "STD_TYPES.h"
#include "POSITION_CONTROL_CONFIG.h"
#include "POSITION_CONTROL_INTERFACE.h"
#include <Arduino.h>

volatile long g_encoderCount = 0;

void positionControlInit(){
  pinMode(MAGNETIC_ENCODER_PIN_A, INPUT_PULLUP);
  pinMode(MAGNETIC_ENCODER_PIN_B, INPUT_PULLUP);
    
    attachInterrupt(
      digitalPinToInterrupt(MAGNETIC_ENCODER_PIN_A),
      ISR_magneticEncoderCountA,
      CHANGE);
    attachInterrupt(
      digitalPinToInterrupt(MAGNETIC_ENCODER_PIN_B),
      ISR_magneticEncoderCountB,
      CHANGE);

     
}


void ISR_magneticEncoderCountA(){
  bool MagAReading = digitalRead(MAGNETIC_ENCODER_PIN_A);
  bool MagBReading = digitalRead(MAGNETIC_ENCODER_PIN_B);

  if(MagBReading == LOW && MagAReading == HIGH) // clock wise direction
    g_encoderCount++;
  else if(MagBReading == LOW && MagAReading == LOW)// counter clock wise direction
     g_encoderCount--;
  else if(MagBReading == HIGH && MagAReading == HIGH) // counter clock wise direction
    g_encoderCount--;
  else if(MagBReading == HIGH && MagAReading == LOW)// clock wise direction
     g_encoderCount++;
}


void ISR_magneticEncoderCountB(){
  bool MagAReading = digitalRead(MAGNETIC_ENCODER_PIN_A);
  bool MagBReading = digitalRead(MAGNETIC_ENCODER_PIN_B);

  if(MagBReading == HIGH && MagAReading == LOW) // clock wise direction
    g_encoderCount--;
  else if(MagBReading == LOW && MagAReading == LOW)// counter clock wise direction
     g_encoderCount++;
  else if(MagBReading == HIGH && MagAReading == HIGH) // counter clock wise direction
    g_encoderCount++;
  else if(MagBReading == LOW && MagAReading == HIGH)// clock wise direction
     g_encoderCount--;
    
}
