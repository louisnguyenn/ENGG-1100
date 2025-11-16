#include <Servo.h>

Servo servoMotor;

void setup() {
  servoMotor.attach(11);
}

void loop() {
  servoMotor.write(0);
  delay(1000);
  servoMotor.write(180);
  delay(1000);
}
