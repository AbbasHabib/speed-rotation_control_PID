#ifndef SPEED_CONTROL_INTERFACE
#define SPEED_CONTROL_INTERFACE

void motorSpeedControlInit();
void motorGo(uint8 pwm_duty_cycle, uint8 motor_direction);
uint16 getDutyCycleFromPot();


#endif
