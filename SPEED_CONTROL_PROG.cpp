#include <Arduino.h>
#include "STD_TYPES.h"
#include "SPEED_CONTROL_CONFIG.h"
#include "SPEED_CONTROL_INTERFACE.h" 

void motorSpeedControlInit(){
  pinMode(MOTOR_OUT_PIN_LEFT, OUTPUT);
  pinMode(MOTOR_OUT_PIN_RIGHT, OUTPUT);
  pinMode(MOTOR_ENABLE_PIN, OUTPUT);
  
  digitalWrite(MOTOR_OUT_PIN_LEFT, LOW);
  digitalWrite(MOTOR_OUT_PIN_RIGHT, LOW);
  digitalWrite(MOTOR_ENABLE_PIN, HIGH);
}


void motorGo(uint8 pwm_duty_cycle, uint8 motor_direction){ 
   //  max PWM is 255
  // so duty cycle will be mapped according to the max = 255
  uint8 actpwm = (pwm_duty_cycle/(float)100.0) * 255;
  
  switch (motor_direction){
     case 'L':
              digitalWrite(MOTOR_OUT_PIN_RIGHT, LOW);
              analogWrite (MOTOR_OUT_PIN_LEFT, actpwm) ;
              break;
     case 'R':
              digitalWrite(MOTOR_OUT_PIN_LEFT, LOW);
              analogWrite (MOTOR_OUT_PIN_RIGHT, actpwm);
              break;
  }    
}

uint16 getDutyCycleFromPot(){
  uint16 potVal = analogRead(SPEED_ANALOG_PIN); // returns values from 0 to 1023

  return (potVal/(float)1023.0) * 100; // return duty cycle out of 10
}
