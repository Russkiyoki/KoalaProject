#include <Arduino.h>

// Eyes variables
int trigPin = 3; // D3
int echoPin = 2; // D2
float USDuration, USDistance;

// testing pin
int testPin = 4; //D4
int ms = 0; // timer variable

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(testPin, OUTPUT);
}

void loop() {
  int d = distance();


  // set timer to 3 seconds for testing
  // If timer reaches 10 seconds without distance being greater than 60cm
  // send signal to D4
  // increment by 10ms (0.1s) to avoid slow system, maybe even .2 
  if(d<60){
    if(ms > 300){
      digitalWrite(testPin, HIGH);
    }
    else
      ms+=10;
  }
  else{
    digitalWrite(testPin, LOW);
    ms = 0;
  }
  delay(100);
}

double distance(){
  digitalWrite(trigPin, LOW);
  delay(1);
  digitalWrite(trigPin, HIGH);
  delay(2);
  digitalWrite(trigPin, LOW);

  USDuration = pulseIn(echoPin, HIGH);
  USDistance = (USDuration*0.0343)/2;

  Serial.begin(9600);
  delay(10);
  return USDistance;
}
