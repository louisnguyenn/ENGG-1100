// global variables
// declare motor A
const int enA = 5;  // speed control pin for motor A
const int in1 = 6;
const int in2 = 7;

// declare motor B
const int enB = 10; // speed control pin for motor B
const int in3 = 8;
const int in4 = 9;

void setup() {
  // put your setup code here, to run once:
  // set all pins to OUTPUT mode
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600); // transferring 9600 bits per second (the maximum)

  // PWM range: 0-255

  // // MOTOR A CLOCKWISE
  // digitalWrite(in1, HIGH);  // turn on right wheel
  // digitalWrite(in2, LOW); // turn off left wheel
  // analogWrite(enA, 255); // motor will run at maxiumum speed

  // // MOTOR B CLOCKWISE
  // digitalWrite(in3, HIGH);  // turn on right wheel
  // digitalWrite(in4, LOW); // turn off left wheel
  // analogWrite(enB, 255); // motor will run at maxiumum speed
  // delay(2000); // will run for 2 seconds

  // // MOTOR A COUNTERCLOCKWISE
  // digitalWrite(in1, LOW); // turn off left wheel
  // digitalWrite(in2, HIGH);  // turn on right wheel
  // analogWrite(enA, 255);

  // // MOTOR B COUNTERCLOCKWISE
  // digitalWrite(in3, LOW); // turn off left wheel
  // digitalWrite(in4, HIGH);  // turn on right wheel
  // analogWrite(enB, 255);
  // delay(2000);

  // FORWARD
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 255);
  analogWrite(enB, 255);
  delay(2000);

  // BACKWARDS
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 255);
  analogWrite(enB, 255);
  delay(2000);

  // TURN LEFT
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 255);
  analogWrite(enB, 255);
  delay(2000);

  // TURN RIGHT
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 255);
  analogWrite(enB, 255);
  delay(2000);

  // STOP
  digitalWrite(in1, LOW); // set pins to LOW
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  delay(2000);  // stop for 2 seconds
}

void loop() {
  // put your main code here, to run repeatedly:

}
