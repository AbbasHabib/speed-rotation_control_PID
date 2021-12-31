// UTIL
#include "STD_TYPES.h"
// MCAL
#include <Arduino.h> 
// HAL
#include "SPEED_CONTROL_INTERFACE.h" 
#include "POSITION_CONTROL_INTERFACE.h"



uint8 g_motorPwmDutyCycle = 100;
extern volatile long g_encoderCount;

String g_serialReadBuffer;


void setup() {
  Serial.begin(9600);
  motorSpeedControlInit();
  positionControlInit();
}
char c;
String readString;

void loop() {
 while (Serial.available()) {
  delay(2);  //delay to allow byte to arrive in input buffer
  c = Serial.read();
  break;
 }
 Serial.println(g_encoderCount);
 g_motorPwmDutyCycle = getDutyCycleFromPot();
 motorGo(g_motorPwmDutyCycle, c);
}
