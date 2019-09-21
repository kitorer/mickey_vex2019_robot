#include "main.h"


void setDrive(int left, int right)//voltage left & right
{
  driveRightBack = right;
  driveRightFront = right;
  driveLeftBack = left;
  driveLeftFront = left;
}

void Tank_control(void* param)
{
int  rightjoystick = master.get_analog(ANALOG_RIGHT_Y);
int  leftjoystick = master.get_analog(ANALOG_LEFT_Y);

setDrive(leftjoystick,rightjoystick);

  driveRightBack.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  driveLeftBack.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  driveRightFront.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  driveLeftFront.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}

void resetdriversencoders()
{
  driveRightBack.tare_position();
  driveLeftBack.tare_position();
  driveRightFront.tare_position();
  driveLeftFront.tare_position();
}
void customforward(int units,int voltage)
{
  resetdriversencoders();
  //reset motor encoders
  //drive forward unitl units are reaches
  //brake
  while(driveLeftFront.get_position()< units)
  {
    setDrive(voltage,voltage);
    pros::delay(10);
  }
  setDrive(-10,-10);
  pros::delay(50);
    setDrive(0,0);
}

void himeturnleft(int turndeg)//should be same values
{
  resetdriversencoders();
  while(driveRightFront.get_position()< turndeg)
  {
    setDrive(0,12000);
    pros::delay(10);
  }
  setDrive(-10,-10);
  pros::delay(50);
    setDrive(0,0);
}
