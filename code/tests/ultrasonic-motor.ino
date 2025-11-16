// ULTRASONIC + MOTOR STOP TEST
#include <Servo.h>

const int enA = 5;
const int in1 = 6;
const int in2 = 7;

int echoPin = 10;
int trigPin = 9;

int speed = 180;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

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

  // DRIVE FORWARD
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, speed);

  // STOP EARLY FOR TESTING (10–15 cm)
  if (dist > 0 && dist < 15) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(enA, 0);
    Serial.println("STOPPED AT 10-15 CM");
    delay(2000);
  }

  delay(20);
}
