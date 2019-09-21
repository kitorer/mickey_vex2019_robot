#include "main.h"

void Intake_control(void*)
{
  if (master.get_digital(DIGITAL_L1)){
  Lintake.move_velocity(100); // This is 100 because it's a 100rpm motor
  Rintake.move_velocity(100);
  }
 else if (master.get_digital(DIGITAL_L2)){
  Rintake.move_velocity(-100);
  Lintake.move_velocity(-100);
 }
 else{
   Rintake.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
   Lintake.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  Rintake.move_velocity(0);
  Lintake.move_velocity(0);//bug: motor is too powerful
}
}
