#ifndef __MOTORS__
#define __MOTORS__

#include <Arduino.h>

extern int motor1Pin1;  // N1 
extern int motor1Pin2;  // N2 
extern int motor2Pin1;  // N3 
extern int motor2Pin2;  // N4 

void init_motors();
void stopMotors();
void turnRight();
void turnLeft();
void driveForward();
void driveBackward();

#endif
