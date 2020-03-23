#include <Servo.h>
Servo myservo;

int triggerPin = A0;
int echoPin = A1;
int time;
int d1 = 0;
int d2 = 0;
int d3 = 0;
int d4 = 0;
int d5 = 0;
int avg = 0;
int distance = 0;
bool isTurned = false;

void setup() {
//  Serial.begMin(9600);
  myservo.attach(11);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {

  //run the motor depending on the detected sensorValue.
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  time = pulseIn(echoPin, HIGH);
  distance = (time*0.034)/2;

  if(distance > 0){
    d1 = d2;
    d2 = d3;
    d3 = d4;
    d4 = d5;
    d5 = distance;
    avg = (d1 + d2 + d3 + d4 + d5)/5;

//    Serial.println(avg);
    
    if ((avg > 0) && (avg <=30)) {
      
      if(!isTurned){
//        Serial.println("TRUE");
        myservo.write(180);
        delay(500);
        isTurned = true;
      }
      else{
        myservo.write(180);
        delay(100);
      }
    }
    else {
      if(isTurned){
//        Serial.println("FALSE");
        myservo.write(0);
        delay(500);
        isTurned = false;
      }
      else{
        delay(100);
      }
    }
  }
}

