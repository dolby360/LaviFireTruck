#include "motors.h"

enum Direction {
    UNINIT,
    FORWARD,
    BACKWARD
};

int motor1Pin1 = 4; // N1
int motor1Pin2 = 2; // N2
int motor2Pin1 = 3; // N3
int motor2Pin2 = 5; // N4

enum Direction direction;

void init_motors(){
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    direction = UNINIT;
    stopMotors();
}

void stopMotors(){
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
}

void addMovementToTurn(){
    switch (direction) {
        case UNINIT:
            break;
        case FORWARD:
            driveForward();
            break;
        case BACKWARD:
            driveBackward();
            break;
        default:
            break;
    }
    delay(250);
}

void turnRight(){
    addMovementToTurn();
    // shut left
    digitalWrite(motor1Pin1, LOW);
    //turn right
    digitalWrite(motor1Pin2, HIGH);
}

void turnLeft(){
    addMovementToTurn();
    // shut right
    digitalWrite(motor1Pin2, LOW);
    // turn left
    digitalWrite(motor1Pin1, HIGH);
}

void driveForward(){
    direction = FORWARD;
    // Disable backward
    digitalWrite(motor2Pin2, LOW);
    // Drive forward
    digitalWrite(motor2Pin1, HIGH);
}

void driveBackward(){
    direction = BACKWARD;
    // Disable forward
    digitalWrite(motor2Pin1, LOW);
    // Drive backward
    digitalWrite(motor2Pin2, HIGH);
}
