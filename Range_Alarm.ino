#include <Servo.h>

int trigPin = 8;
int echoPin = 7;
int buzzer = 10;
int button = 12;
int redLED = 6;
int greenLED = 5;
Servo servo1;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT); 
  servo1.attach(9);
}

void loop() {
  long duration, distance;
  int buttonState;
  digitalWrite(trigPin, LOW);
  delay(2);
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2)/29.1;
  Serial.println(duration);
  buttonState = digitalRead(button);
  
  if(distance < 100 && buttonState == 1)
  {
    tone(buzzer, 523);
    analogWrite(redLED, 100);
    analogWrite(greenLED, 0);
    servo1.write(0);
  }
  else
  {
    noTone(buzzer);
    analogWrite(redLED, 0);
    analogWrite(greenLED, 100);
    servo1.write(180);
  }
}
