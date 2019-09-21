#include "main.h"


void Tray_control(void*)
{
  if (master.get_digital(DIGITAL_UP)) {
   Tray.move_velocity(35); // This is 100 because it's a 100rpm motor
   Tray.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
 }
 else if (master.get_digital(DIGITAL_DOWN)) {
   Tray.move_velocity(-100);
 }
 else
 {
   Tray.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
   Tray.move_velocity(0);
 }
}
