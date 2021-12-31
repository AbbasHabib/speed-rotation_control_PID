#ifndef POSITION_CONTROL_CONFIG_H
#define POSITION_CONTROL_CONFIG_H

#define MAGNETIC_ENCODER_PIN_A  2
#define MAGNETIC_ENCODER_PIN_B  3

void ISR_magneticEncoderCountA();

void ISR_magneticEncoderCountB();

#endif
