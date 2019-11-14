#include "main.h"
//drivecontrol header 
void Tank_control(void*);

void setDrive(int left, int right);

void resetdriversencoders();
//auton funct
void customforward(int units,int voltage);

void himeturnleft(int turndeg);

void himeturnRight(int turndeg);

void backleftturn(int turndeg);

void slowdown(int distance, float Kp, float Ki, float Kd);
