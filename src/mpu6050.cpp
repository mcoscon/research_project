#include <Arduino.h>
#include "../src/headerfiles/json.h"
#include "../src/headerfiles/thingSpeak.h"
#include "../src/headerfiles/mpu6050.hpp"
#define SDA 4
#define SCL 18

uint16_t accX, accY, accZ, gyroX, gyroY, gyroZ;
void setupMPU()
{
    /*Set SDA to pin D2, SCL to pin D4*/
    Wire.begin(SDA, SCL);
    mpu6050.begin();
    mpu6050.calcGyroOffsets(true);    
}
/*
void getData()
{
    accX = mpu6050.getAccX();
    accY = mpu6050.getAccX();
    accZ = mpu6050.getAccX();
    gyroX = mpu6050.getAccX();
    gyroY = mpu6050.getAccX();
    gyroZ = mpu6050.getAccX();
    addJSON(accX, accY, accZ, gyroX, gyroY, gyroZ);
    Serial.print(accX);
}

void sendData(){
    httpRequest(doc);
    Serial.println("Sent!\n");
}
*/