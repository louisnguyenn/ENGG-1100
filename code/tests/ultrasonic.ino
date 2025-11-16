int trigPin = 9;
int echoPin = 10;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, dist;

  // Send trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo
  duration = pulseIn(echoPin, HIGH, 30000);

  // Convert to cm
  dist = duration * 0.034 / 2;

  // Print
  Serial.print("Distance: ");
  Serial.print(dist);
  Serial.println(" cm");

  delay(100);
}
