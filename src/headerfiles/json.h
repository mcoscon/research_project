// Allocating JSON buffer 
#include "ArduinoJson.h"
void connectWiFi();
void httpRequest();
void createJSON(double accX, double accY, double accZ, double gryoX, double gyroY, double gyroZ);
void addJSON(unsigned long deltaT, double accX, double accY, double accZ, double gryoX, double gyroY, double gyroZ);

/* Collect data once every 15 seconds and post data to ThingSpeak channel once every 2 minutes */