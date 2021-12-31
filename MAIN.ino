#include <Arduino.h>
#include "STD_TYPES.h" // UTIL
#include "SPEED_CONTROL_INTERFACE.h" // HAL


uint8 MOTOR_PWM_DUTY_CYCLE = 100;

void setup() {
  Serial.begin(9600);
  progInit();
}

void loop() {
  MOTOR_PWM_DUTY_CYCLE = getDutyCycleFromPot();
  Serial.print(MOTOR_PWM_DUTY_CYCLE);
  
  motorGo(MOTOR_PWM_DUTY_CYCLE, 'R');
  delay(1000);
  motorGo(MOTOR_PWM_DUTY_CYCLE, 'L');
  delay(1000);
}
