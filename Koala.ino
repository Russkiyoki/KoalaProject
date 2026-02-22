#include <Arduino.h>

// Eyes variables
int trigPin = 3; // D3
int echoPin = 2; // D2
float USDuration, USDistance;

// testing pin
int testPin = 4; //D4

// Timer variables
// to be created

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(testPin, OUTPUT);
}

void loop() {
  int d = distance();
  if(d > 5)
    digitalWrite(testPin, HIGH);
  else
    digitalWrite(testPin, LOW);
  delay(100);
}

double distance(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  USDuration = pulseIn(echoPin, HIGH);
  USDistance = (USDuration*0.0343)/2;

  Serial.begin(9600);
  delay(100);
  return USDistance;
}
