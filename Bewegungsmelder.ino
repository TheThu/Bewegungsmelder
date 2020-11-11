/* HC-SR04 ultrasonic distance sensor with NewPing library example code. More info: www.makerguides.com */

// Include the library:
#include <NewPing.h>
// Define pins and max distance:
#define trigPin  2
#define echoPin  3

// LED Pins
#define LED_RED  7
#define LED_GREEN 8
#define MAX_DISTANCE 350 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(trigPin, echoPin, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
float duration, distance;
void setup() {

  // Set LED as output terminal 
  pinMode(LED_RED,OUTPUT);
  pinMode(LED_GREEN,OUTPUT);
  Serial.begin(9600); // Open serial monitor at 9600 baud to see ping results.
  
}
void loop() {
  delay(50); // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  
// Count variable 
  static int i;
  int iterations = 10;

  // Build median 
  duration = sonar.ping_median(iterations);
  distance = (duration / 2) * 0.0343;

// if distance < 90cm

  if(distance< 90){
    
    digitalWrite(LED_GREEN,LOW);
    if (millis() % 1000 > 500) {
    digitalWrite(LED_RED,HIGH);
    }     
    else {
    digitalWrite(LED_RED,LOW);
    }

     standby = true;
      i = 0;
     
  }
  else{ 
    i++;
    if(i > 28){
      digitalWrite(LED_RED,LOW);
      digitalWrite(LED_GREEN,LOW);
      standby == false;
    }
    else{
    digitalWrite(LED_RED,LOW);
    
          if (millis() % 1000 > 500){
          digitalWrite(LED_GREEN,HIGH);
          }     
          else {
          digitalWrite(LED_GREEN,LOW);
          }  

    }
  }
  Serial.print("Distance = ");
  Serial.print(distance); // Distance will be 0 when out of set max range.
  Serial.println(" cm");
}
