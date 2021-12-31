#include <Arduino.h>
#include "STD_TYPES.h"
#include "SPEED_CONTROL_CONFIG.h"
#include "SPEED_CONTOL_INTERFACE.h" 

void progInit(){
  pinMode(motor_out_pin_left, OUTPUT);
  pinMode(motor_out_pin_right, OUTPUT);
  pinMode(motor_enable_pin, OUTPUT);
  
  digitalWrite(motor_out_pin_left, LOW);
  digitalWrite(motor_out_pin_right, LOW);
  digitalWrite(motor_enable_pin, HIGH);
}


void motorGo(uint8 pwm_duty_cycle, uint8 motor_direction){ 
   //  max PWM is 255
  // so duty cycle will be mapped according to the max = 255
  uint8 actpwm = (pwm_duty_cycle/(float)100.0) * 255;
  
  switch (motor_direction){
     case 'L':
              digitalWrite(motor_out_pin_right, LOW);
              analogWrite (motor_out_pin_left, actpwm) ;
              break;
     case 'R':
              digitalWrite(motor_out_pin_left, LOW);
              analogWrite (motor_out_pin_right, actpwm);
              break;
  }    
}

uint16 getDutyCycleFromPot(){
  uint16 potVal = analogRead(speed_analog_pin); // returns values from 0 to 1023

  return (potVal/(float)1023.0) * 100; // return duty cycle out of 10
}
