#include <Servo.h> 

// Author: Louis Nguyen (1321410)

const int enA = 5;
const int in1 = 6;
const int in2 = 7;

Servo servoMotor;

int speed = 245;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  servoMotor.attach(11);
  Serial.begin(9600);
}

void loop() {
  // Set servomotor position to 0
  // Effectiveness: 10/10
  servoMotor.write(0);
  
  //
  // Successfully moved forward for the allocated number of time
  // Effectiveness: 10/10 
  //
  // Move forward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, speed);
  delay(3900);

  //
  // Successfully stopped for the allocated number of time
  // Effectiveness: 10/10
  //
  // Stop
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  delay(1000);

  //
  // Successfully reversed for the allocated number of time
  // Effectiveness: 10/10
  //
  // Reverse
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, speed);
  delay(10000);

  // Overall effectiveness: 10/10
  // The code was very effective, as there weren't any issues with the Arduino control during test and performance day.
  
  // Possible Improvements for the future:
  // For the future, more testing could be done with the code and chassis before our performance day. For example, we should've tested various speeds to ensure our TBWC was able to traverse the course at a fast time while also ensuring it doesn't cause any drifting issues.
}
