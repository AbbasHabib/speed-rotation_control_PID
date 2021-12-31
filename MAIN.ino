#include <Arduino.h>
#include "STD_TYPES.h" // UTIL
#include "SPEED_CONTROL_INTERFACE.h" // HAL


uint8 g_motorPwmDutyCycle = 100;

void setup() {
  Serial.begin(9600);
  motorSpeedControlInit();
  
}

void loop() {
  g_motor_pwm_duty_cycle = getDutyCycleFromPot();
  Serial.print(g_motorPwmDutyCycle);
}
