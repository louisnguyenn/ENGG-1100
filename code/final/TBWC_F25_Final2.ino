#include <Servo.h> 

const int enA = 5;
const int in1 = 6;
const int in2 = 7;

Servo servoMotor;

int speed = 200;
int task = 0;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  servoMotor.attach(11);
  Serial.begin(9600);
}

void loop() {

  switch (task) {

    case 0:
      // FORWARD
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      analogWrite(enA, speed);
      delay(4500);

      // STOP
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      analogWrite(enA, 0);

      task = 1;
      break;

    case 1:
      servoMotor.write(180);  // rotate servo 180 degrees
      delay(800);
      break;
  }

  delay(10);
}
