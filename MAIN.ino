// UTIL
#include "STD_TYPES.h"
// MCAL
#include <Arduino.h> 
// HAL
#include "SPEED_CONTROL_INTERFACE.h" 
#include "POSITION_CONTROL_INTERFACE.h"



uint8 g_motorPwmDutyCycle = 100;
extern volatile long g_encoderCount;

void setup() {
  Serial.begin(9600);
  motorSpeedControlInit();
  
}

void loop() {
  g_motorPwmDutyCycle = getDutyCycleFromPot();
  Serial.println(g_motorPwmDutyCycle);
}
