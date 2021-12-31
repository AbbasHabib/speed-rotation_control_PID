#ifndef POSITION_CONTROL_INTERFACE_H
#define POSITION_CONTROL_INTERFACE_H

// added volatile to prevent code optimizer from removing it
volatile long EncoderCount = 0; 

void positionControlInit();




#endif
