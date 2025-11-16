#include <Servo.h> 

// declare motor A (for the wheels)
const int enA = 5;
const int in1 = 6;
const int in2 = 7;

// servo motor pins
Servo servoMotor;
int pos = 0;

// ultrasonic sensor pins
int echoPin = 10;
int trigPin = 9;

// task variable
int task = 0;

// speed
int speed = 150; // lower speed for safety testing

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  servoMotor.attach(11);
  Serial.begin(9600);
}

void loop() {
  long dist;

  // ultrasonic
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  dist = pulseIn(echoPin, HIGH, 30000);
  dist = dist * 0.034 / 2;

  Serial.println(dist);

  switch (task) {

    // task 1: forward to wall
    case 0:
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      analogWrite(enA, speed);

      // *** lowered from 40 → 15 cm ***
      if (dist > 0 && dist < 15) {
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        analogWrite(enA, 0);

        task = 1;
      }
      break;

    // task 2: reverse
    case 1:
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(enA, speed);

      // *** lowered from 150 → 50 cm ***
      if (dist > 50 || dist == 0) {
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        analogWrite(enA, 0);

        task = 2;
      }
      break;

    // task 3: small-distance launch test
    case 2:
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      analogWrite(enA, speed);

      // *** lowered from 20–40 → 10–15 cm ***
      if (dist > 10 && dist < 15) {
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        analogWrite(enA, 0);

        servoMotor.write(180);
        delay(800);
        servoMotor.write(0);

        task = 3;
      }
      break;

    case 3:
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      analogWrite(enA, 0);
      break;
  }

  delay(20);
}
