#include <Servo.h> 

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
  // DRIVE FORWARD
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, speed);
  delay(3950);

  // STOP
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  delay(2000);

  // ROTATE SERVO
  servoMotor.write(180);  // rotate servo 180 degrees
  delay(1000);
  servoMotor.write(0);  // rotate servo 0 degrees
  delay(1000);
  
  // FINAL STOP
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);

  while (true); // stop forever
}
