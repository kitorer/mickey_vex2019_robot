#include "main.h"

void Tank_control(void* param)
{
  driveRightBack.move(master.get_analog(ANALOG_RIGHT_Y));
  driveRightFront.move(master.get_analog(ANALOG_RIGHT_Y));
  driveLeftBack.move(master.get_analog(ANALOG_LEFT_Y));
  driveLeftFront.move(master.get_analog(ANALOG_LEFT_Y));

  driveRightBack.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  driveLeftBack.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  driveRightFront.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  driveLeftFront.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}
