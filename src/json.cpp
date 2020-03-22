/* This C file contains the neccesary functions to serialize sensor data. The JSON is serialised as below */
#include <Arduino.h>
#include <ArduinoJson.h>
#include "../src/headerfiles/json.h"

/*
const int capacity = JSON_ARRAY_SIZE(30) + 4 * JSON_OBJECT_SIZE(8);
static StaticJsonDocument<capacity> doc;
*/
JsonArray updates = doc.createNestedArray("updates");

// Create JsonObject, only runs the first time. Todo: Set flag in main to run once 
void createJSON(int flag, double accX, double accY, double accZ, double gyroX, double gyroY, double gyroZ){
    if(flag == 1){
    doc["write_api_key"] = "9W6IUZI9EOGWWAVY";
    JsonObject objectIdentifer = updates.createNestedObject();
    objectIdentifer["delta_t"] = 0;
    objectIdentifer["field1"] = accX;
    objectIdentifer["field2"] = accY;
    objectIdentifer["field3"] = accZ;
    objectIdentifer["field4"] = gyroX;
    objectIdentifer["field5"] = gyroY;
    objectIdentifer["field6"] = gyroZ;
    }
}

void addJSON(double accX, double accY, double accZ, double gyroX, double gyroY, double gyroZ)
{
    JsonObject updatesNext = updates.createNestedObject();
    updatesNext["delta_t"] = 1;
    updatesNext["field1"] = accX;
    updatesNext["field2"] = accY;
    updatesNext["field3"] = accZ;
    updatesNext["field4"] = gyroX;
    updatesNext["field5"] = gyroY;
    updatesNext["field6"] = gyroZ;
    serializeJsonPretty(doc,Serial);
}