const int trigPin = 9;
const int echoPin = 10;

float duration;
float distanceCM;
float distanceIN;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  }

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  duration = pulseIn(echoPin, HIGH);

  distanceCM = (duration * 0.034) / 2;

  distanceIN = distanceCM / 2.54;

  Serial.print("Distance: ");
  Serial.print(distanceCM);
  Serial.print(" cm | ");
  Serial.print(distanceIN);
  Serial.println(" in");
  delay(100);
}
