#include "../src/headerfiles/L298N.h"
#include <Arduino.h>
#include <analogWrite.h>
#include "../src/headerfiles/driveMotor.h"
#include "../src/headerfiles/thingSpeak.h"
#include "../src/headerfiles/json.h"
#include <Ticker.h>
#include "../src/headerfiles/mpu6050.hpp"

uint16_t timer1 = 0;
uint16_t timer2 = 0;
uint16_t milliTimer = 0;
void getData();
void sendData();

void setup() {
  Serial.begin(115200);
  connectWiFi();
  setupMPU();
  moveForward();
  delay(1000);
  createJSON(0,0,0,0,0,0);
  delay(2000);

}

void loop() {
  mpu6050.update();
  /*
  addJSON(mpu6050.getAccX(), mpu6050.getAccX(),
  mpu6050.getAccX(), mpu6050.getAccX(), mpu6050.getAccX(), 
  mpu6050.getAccX());
  */
  //Serial.print(mpu6050.getAccX());
  //delay(1000);
  addJSON(mpu6050.getAccX(),mpu6050.getAccY(), mpu6050.getAccZ(),
    mpu6050.getGyroX(), mpu6050.getGyroY(), mpu6050.getGyroZ());
  httpRequest(doc);
  delay(15000);
}

void getData() {
  if(millis()-timer1 > 2000)
  {
    Serial.print(mpu6050.getAccX());
    addJSON(mpu6050.getAccX(),mpu6050.getAccY(), mpu6050.getAccZ(),
    mpu6050.getGyroX(), mpu6050.getGyroY(), mpu6050.getGyroZ());
    timer1 = millis();
  }
  }

void sendData(){
  if(millis()-timer2 > 20000)
  {
    httpRequest(doc);
     //Serial.print(mpu6050.getAccX());
     timer2 = millis();
  }
}
