#include <Servo.h> 

const int enA = 5;
const int in1 = 6;
const int in2 = 7;

Servo servoMotor;

// max 255
int speed = 235;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  servoMotor.attach(11);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, speed);
  delay(4300);

  // STOP
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  delay(1000);

  // REVERSE
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, speed);
  delay(9999);
}
