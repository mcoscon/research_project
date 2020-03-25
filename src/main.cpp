#include "../src/headerfiles/L298N.h"
#include <Arduino.h>
#include <analogWrite.h>

//pin definition
#define EN 15
#define IN1 19
#define IN2 21

//create a motor instance
L298N motor(EN, IN1, IN2);
void callback();
//initial speed
unsigned short theSpeed = 0;

void setup() {

  //set the initial speed
  motor.setSpeed(theSpeed);

}

void loop() {

  //move motor for 5 seconds and then execute the callback function
  motor.forwardFor(5000, callback);
  Serial.print(theSpeed);
}

void callback() {

  //each time the callback function is called increase the speed of the motor or reset to 0
  if (theSpeed <= 255) {
    theSpeed += 25;
  } else {
    theSpeed = 0;
  }

  //re-enable motor movements
  motor.reset();
  //set the new speed
  motor.setSpeed(theSpeed);

}