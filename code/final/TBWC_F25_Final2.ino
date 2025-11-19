#include <Servo.h> 

// Author: Louis Nguyen (1321410)

const int enA = 5;
const int in1 = 6;
const int in2 = 7;

Servo servoMotor;

int speed = 205;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  servoMotor.attach(11);
  Serial.begin(9600);
}

void loop() {
  //
  // Successfully move forward for the allocated number of time
  // Effectiveness: 10/10
  //
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, speed);
  delay(3950);

  //
  // Successfully stopped for the allocated number of time
  // Effectiveness: 10/10
  //
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  delay(2000);

  //
  // Successfully rotated the servo motor, activating the launching mechanism
  // Effectiveness: 10/10
  //
  servoMotor.write(180);  // rotate servo 180 degrees
  delay(1000);
  servoMotor.write(0);  // rotate servo 0 degrees
  delay(1000);
  
  //
  // Successfully stopped for the allocated number of time
  // Effectiveness: 10/10
  //
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  delay(10000);

  // Overall effectiveness: 10/10
  // The code was very effective, as everything went smoothly during testing and performance day. 
  
  // Possible Improvements for the future:
  // For the future, more testing could have been done at the projectile launch course, where we should've tested the optimal speed for the TBWC to traverse over the bump and launch the projectile. During our performance demonstration, the speed was set too high, causing the projectile to fall out of it's place, resulting in a lower mark. Overall, the code was effective and successful, but more testing should have been done to ensure that the speed and timing went more smoothly.
}
