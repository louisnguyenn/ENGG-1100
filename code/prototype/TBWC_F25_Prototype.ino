// global variables
// declare motor A (for the wheels)
const int enA = 5;  // speed control pin for motor A
const int in1 = 6;
const int in2 = 7;

// declare motor B (motor B will be for the launcher)
// const int enB = 10; // speed control pin for motor B
// const int in3 = 8;
// const int in4 = 9;

void setup() {
  // put your setup code here, to run once:
  // set all pins to OUTPUT mode
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  // pinMode(enB, OUTPUT);
  // pinMode(in3, OUTPUT);
  // pinMode(in4, OUTPUT);
  Serial.begin(9600); // transferring 9600 bits per second (the maximum)

  // PWM range: 0-255 (speed, 255 is max)

  // // FORWARD
  // digitalWrite(in1, HIGH);
  // digitalWrite(in2, LOW);
  // // digitalWrite(in3, LOW);
  // // digitalWrite(in4, HIGH);
  // analogWrite(enA, 200);
  // // analogWrite(enB, 255);
  // delay(2000);

  // // BACKWARDS
  // digitalWrite(in1, LOW);
  // digitalWrite(in2, HIGH);
  // // digitalWrite(in3, HIGH);
  // // digitalWrite(in4, LOW);
  // analogWrite(enA, 200);
  // // analogWrite(enB, 255);
  // delay(2000);

  // // STOP
  // digitalWrite(in1, LOW); // set all pins to LOW
  // digitalWrite(in2, LOW);
  // // digitalWrite(in3, LOW);
  // // digitalWrite(in4, LOW);
  // analogWrite(enA, 0);  // set speed to low
  // // analogWrite(enB, 0);
  // delay(2000);  // stop for 2 seconds
}

void loop() {
  // put your main code here, to run repeatedly:
  // STOP
  digitalWrite(in1, LOW); // set all pins to LOW
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);  // set speed to low
  delay(2000);

  // FORWARD
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 255);
  delay(6000);

  // STOP
  digitalWrite(in1, LOW); // set all pins to LOW
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);  // set speed to low
  delay(6000);

  // BACKWARDS
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 2);
  delay(6000);

  // STOP
  digitalWrite(in1, LOW); // set all pins to LOW
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);  // set speed to low
  delay(6000);
}
