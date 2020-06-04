#include "../src/headerfiles/L298N.h"
#include <Arduino.h>
#include <analogWrite.h>
#include "../src/headerfiles/driveMotor.h"
//#include "../src/headerfiles/thingSpeak.h"
#include "../src/headerfiles/json.h"
#include <Ticker.h>
#include "../src/headerfiles/mpu6050.hpp"

long lastConnectionTime = 15L * 1000L; // Track the last connection time
unsigned long lastUpdateTime = 0; // Track the last update time
const long postingInterval = 6L * 1000L; // Post data every 15 minutes
const unsigned long updateInterval = 0.02L * 1000L; // Update once every 0.2 second
unsigned long deltaT;

void sendToThingSpeak(void);

void setup() {
  Serial.begin(115200);
  connectWiFi();
  /*
  connectWiFi();
  setupMPU();
  */
  setupMPU();
  Serial.println("start");
  moveForward();
  createJSON(0,0,0,0,0,0);
}

void loop() {
  mpu6050.update();
   if (millis() - lastUpdateTime >=  updateInterval) {
     deltaT = (millis() - lastUpdateTime)/1000;
     addJSON(deltaT, mpu6050.getAccX(),mpu6050.getAccY(), mpu6050.getAccZ(),
      mpu6050.getGyroX(), mpu6050.getGyroY(), mpu6050.getGyroZ());
     httpRequest();
     lastUpdateTime = millis(); // Update the last update time
  }
 }

