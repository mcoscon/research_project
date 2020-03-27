// Allocating JSON buffer 
#include "ArduinoJson.h"
void connectWiFi();
void httpRequest();
void createJSON(double accX, double accY, double accZ, double gryoX, double gyroY, double gyroZ);
void addJSON(double accX, double accY, double accZ, double gryoX, double gyroY, double gyroZ);