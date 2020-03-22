/* This C file contains the neccesary functions to serialize sensor data. The JSON is serialised as below */
#include <Arduino.h>
#include "../src/headerfiles/json.h"
#include "../src/headerfiles/thingSpeak.h"
static int flag = 1;

void setup(){
  Serial.begin(115200);
  connectWiFi();
}

void loop(){
  
  createJSON(flag, 3.4, 4.5, 5.6, 3.5, 3.5, 5.3);
  addJSON(3.4, 4.5, 5.6, 3.5, 3.5, 5.3);
  /*
  httpRequest(doc);
  */
  delay(100);
  flag = 0;
}


