#include <LiquidCrystal.h>
int regSelect = 13;
int enable = 12;
int d4 = 11;
int d5 = 10;
int d6 = 9;
int d7 = 8;
int trigPin = 7;
int echoPin = 6;
int switchPin = 5;
int responseTime;
int switchState;
int newVal;
int oldVal = 1;
float distance;

LiquidCrystal Display(regSelect, enable, d4, d5, d6, d7);

void setup() {
	
  Display.begin(16, 2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(switchPin, INPUT);
  digitalWrite(switchPin, HIGH);

} 
void loop() {
  
  newVal = digitalRead(switchPin);
  
  if (newVal == 0 && oldVal == 1) {
    if (switchState == true) {
    	digitalWrite(trigPin, LOW);
        delayMicroseconds(10);
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);
        responseTime = pulseIn(echoPin, HIGH);
      	Display.setCursor(0, 0);
      	Display.print("Nearest Target");
        Display.setCursor(0, 1);
      	distance = (responseTime * 123436685. / 1000000. / 3600. / 2.);
        Display.print(distance);
      	Display.print("cm");
      	Display.print(" ");
      	Display.print("away");
      	switchState = false;
    } else {
    	Display.clear();
      	switchState = true;
    }
  }
  
}