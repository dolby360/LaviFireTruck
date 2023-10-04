#include <Arduino.h>
#include <SoftwareSerial.h>
#include "motors.h"

unsigned long currentTime = 0;
SoftwareSerial bluetooth(10, 11);  // RX, TX pins for Bluetooth communication

void setup() {
  init_motors();
  currentTime = millis();
  bluetooth.begin(9600);  // Set the baud rate for Bluetooth communication
  Serial.begin(9600);
}

void loop() {
  char command;
  while (bluetooth.available()) {
    command = (char)bluetooth.read();
    Serial.println("Received command: " + String(command));
    currentTime = millis();
    if (command == '1') {
      driveForward();
    } else if (command == '2') {
      driveBackward();
    } else if (command == '4') {
      turnLeft();
    } else if (command == '3') {
      turnRight();
    }
  }
  if(millis() - currentTime >= 500){
    stopMotors();
  }
}
