// Allocating JSON buffer 
#include "ArduinoJson.h"
void createJSON(int flag, double accX, double accY, double accZ, double gryoX, double gyroY, double gyroZ);
void addJSON(double accX, double accY, double accZ, double gryoX, double gyroY, double gyroZ);
//const int capacity = JSON_ARRAY_SIZE(30) + 4 * JSON_OBJECT_SIZE(8);
static DynamicJsonDocument doc(2048);