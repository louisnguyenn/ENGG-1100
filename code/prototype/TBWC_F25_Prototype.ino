#include <Servo.h> 

// declare motor A (for the wheels)
const int enA = 5;  // speed control pin for motor A
const int in1 = 6;
const int in2 = 7;

// servo motor pins
Servo servoMotor;
int pos = 0;  // storing the position of the servo

// ultrasonic sensor pins
int echoPin = 10;
int trigPin = 9;

// this variable keeps track of what code to run for each task
int task = 0;

// speed variable
// PWM range: 0-255 (speed, 255 is max)
int speed = 225;

void setup() {
  // put your setup code here, to run once:
  // set all pins to OUTPUT mode
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  servoMotor.attach(11);  // linking the servo motor with the pin
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  long dist = 0;

  // ultrasonic sensor code
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  dist = pulseIn(echoPin, HIGH, 30000);
  dist = dist * 0.034 / 2;  // convert to cm
  Serial.println(dist);

  switch (task) {
    // task 1: drive forward to line C
    case 0:
      // FORWARD
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      analogWrite(enA, speed);

      if (dist > 0 && dist < 40)
      {
        // STOP
        digitalWrite(in1, LOW); // set all pins to LOW
        digitalWrite(in2, LOW);
        analogWrite(enA, 0);

        // change to task 2
        task = 1;
      }
      break;

    // task 2: drive backwards/reverse back to line A
    case 1:
      // REVERSE
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(enA, speed);

      if (dist > 150 || dist == 0) 
      {
        // STOP
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        analogWrite(enA, 0);

        task = 2;
      }
      break;

    // task 3: launching challenge
    case 2:
      // FORWARD
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      analogWrite(enA, speed);

      // *** updated: target distance is now 30–40 cm ***
      if (dist > 20 && dist < 40)
      {
        // STOP
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        analogWrite(enA, 0);

        // rotate servo
        servoMotor.write(180);
        delay(1000);
        task = 3;
      }
      break;

    case 3:
      // stop all operations
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      analogWrite(enA, 0);
      break;
  }

  delay(20);
}
