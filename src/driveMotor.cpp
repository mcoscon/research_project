#include "../src/headerfiles/L298N.h"
#include "headerfiles/driveMotor.h"
//pin definition
#define EN1 15
#define IN1 19
#define IN2 21
#define EN2 5
#define IN3 22
#define IN4 23

L298N motor1(EN1, IN1, IN2);
L298N motor2(EN2, IN3, IN4);
uint8_t speed = 225;

void moveForward()
{
    motor1.setSpeed(speed);
    motor2.setSpeed(speed);
    motor1.forward();
    motor2.forward();
}

void stopMotors(){
    motor1.stop();
    motor2.stop();
}

