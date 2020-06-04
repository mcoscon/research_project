/* This C file contains the neccesary functions to serialize sensor data. The JSON is serialised as below */
#include <Arduino.h>
#include <ArduinoJson.h>
#include "../src/headerfiles/json.h"
#include <WiFi.h>
#include "../src/headerfiles/secrets.h"

const int capacity = JSON_ARRAY_SIZE(300) + JSON_OBJECT_SIZE(2) + 300*JSON_OBJECT_SIZE(7);
StaticJsonDocument<capacity> doc;

/*
const int capacity = JSON_ARRAY_SIZE(30) + 4 * JSON_OBJECT_SIZE(8);
static StaticJsonDocument<capacity> doc;
*/
JsonArray updates = doc.createNestedArray("updates");

char ssid[] = SECRET_SSID;   // your network SSID (name) 
char pass[] = SECRET_PASS;   // your network password
size_t len;

WiFiClient client;
char server[] = "api.thingspeak.com"; 

void connectWiFi(){
if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(SECRET_SSID);
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, pass);  // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      Serial.print("!");
      delay(5000);     
    } 
    //Serial.println("\nConnected");
  }
}

void httpRequest() {
  if(updates.size()==250){
    len = measureJson(doc);
    String dataLength = String(len);
    // Close any connection before sending a new request
    client.stop();
    // POST data to ThingSpeak
    if (client.connect(server, 80)) {
      client.println("POST /channels/1047495/bulk_update.json HTTP/1.1");
      client.println("Host: api.thingspeak.com");
      client.println("Connection: close");
      client.println("Content-Type: application/json");
      client.println("Content-Length: "+dataLength);
      client.println();
      serializeJson(doc, client);
    }
    else {
      //Serial.println("Failure: Failed to connect to ThingSpeak");
    }
    //Wait to receive the responseError: No content was passed for subject, html, text, nor attachments message props. Check that the files for the template "html" exis
    //delay(50);
    client.parseFloat();
    String resp = String(client.parseInt());
    Serial.println("Response code:"+resp); 
    }
    else{
      //serializeJsonPretty(doc, Serial);
    }
}


void createJSON(double accX, double accY, double accZ, double gyroX, double gyroY, double gyroZ){
    doc["write_api_key"] = "B2JWIR26G2TBK7WD";
    JsonObject objectIdentifer = updates.createNestedObject();
    objectIdentifer["delta_t"] = 0;
    objectIdentifer["field1"] = accX;
    objectIdentifer["field2"] = accY;
    objectIdentifer["field3"] = accZ;
    objectIdentifer["field4"] = gyroX;
    objectIdentifer["field5"] = gyroY;
    objectIdentifer["field6"] = gyroZ;
    
}

void addJSON(unsigned long deltaT, double accX, double accY, double accZ, double gyroX, double gyroY, double gyroZ)
{
  
    // doc["write_api_key"] = "T07CXGKRMLDOL193";
    JsonObject objectIdentifer = updates.createNestedObject();
    objectIdentifer["delta_t"] = millis();
    objectIdentifer["field1"] = accX;
    objectIdentifer["field2"] = accY;
    objectIdentifer["field3"] = accZ;
    objectIdentifer["field4"] = gyroX;
    objectIdentifer["field5"] = gyroY;
    objectIdentifer["field6"] = gyroZ;
    //serializeJsonPretty(doc,Serial);
     
}