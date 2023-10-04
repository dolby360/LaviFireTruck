#include <Arduino.h>
#include <SoftwareSerial.h>

// Define the motor control pins
int motor1Pin1 = 4; // N1
int motor1Pin2 = 2; // N2
int motor2Pin1 = 3; // N3
int motor2Pin2 = 5; // N4
unsigned long currentTime = 0;
SoftwareSerial bluetooth(10, 11);  // RX, TX pins for Bluetooth communication

void stopMotors();

void setup() {
  // Set the motor control pins as outputs
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  stopMotors();
  currentTime = millis();
  bluetooth.begin(9600);  // Set the baud rate for Bluetooth communication
  Serial.begin(9600);
}

void stopMotors(){
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}

void turnRight(){
  // shut left
  digitalWrite(motor1Pin1, LOW);
  //turn right
  digitalWrite(motor1Pin2, HIGH);
}

void turnLeft(){
  // shut right
  digitalWrite(motor1Pin2, LOW);
  // turn left
  digitalWrite(motor1Pin1, HIGH);
}

void driveForward(){
  // Disable backward
  digitalWrite(motor2Pin2, LOW);
  // Drive forward
  digitalWrite(motor2Pin1, HIGH);
}

void driveBackward(){
  // Disable forward
  digitalWrite(motor2Pin1, LOW);
  // Drive backward
  digitalWrite(motor2Pin2, HIGH);
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
