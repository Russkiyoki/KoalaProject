// Elisey Voichishin
#include <Arduino.h>

// Eyes variables
int trigPin = 3;
int echoPin = 2;
float USDuration, USDistance;

// speaker pin
int testPin = 4;
int ms = 0;
boolean reset = true;
boolean alarmTriggered = false;  // track if alarm already sounded

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(testPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
  int d = distance();
  
  // if user is close and timer is fully reset
  if(d < 60 && reset) {
    reset = false;
    alarmTriggered = false;  // reset alarm flag when user returns
    ms++; // increment until we hit the 3 secs again 
  }
// if user is close and timer is not reset fully, yell at user
  else if(d < 60 && !reset) {
    if(!alarmTriggered) {  // only increment if alarm hasn't triggered yet
      ms++;
      if(ms > 30) {
        alarmTriggered = true;  // mark alarm as triggered
      }
    }
    
    // sound alarm if triggered
    if(alarmTriggered) {
      digitalWrite(testPin, HIGH);
      delay(25);
      digitalWrite(testPin, LOW);
      delay(25);
    }
  }
  // start the countdown timer
  else if(d > 60 && !reset) {
    if(ms > 0) {
      ms--;
      if(ms == 0) {
        reset = true;
        alarmTriggered = false;  // reset alarm flag
        digitalWrite(testPin, LOW);
      }
    }
  }

  delay(100);
}

//function to return the distance via the ultrasonic sensor
double distance(){
  digitalWrite(trigPin, LOW);
  delay(1);
  digitalWrite(trigPin, HIGH);
  delay(2);
  digitalWrite(trigPin, LOW);

  USDuration = pulseIn(echoPin, HIGH);
  USDistance = (USDuration*0.0343)/2;

  delay(10);
  return USDistance;
}
