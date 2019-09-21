#include "main.h"

int move = arm.get_target_position();

void ArmMove(int MoveVal)//auton
{
  if (arm.get_target_position() < MoveVal)
  {
  arm.move_velocity(100);
  }
  if(arm.get_target_position() > MoveVal)
  {
  arm.move_velocity(-100);
  }
  else
  {
    arm.move_velocity(0);
  }
}


void ArmMcaro(void*)//defective code DONOT USE
{
  {
  ArmController.setMaxVelocity(200);
  intakeController.setMaxVelocity(200);

  ArmController.setTarget(200);
  ArmController.waitUntilSettled();
  intakeController.setTarget(-1000);
  intakeController.waitUntilSettled();
  ArmController.setTarget(500);
  }
}


void Arm_control(void*)//opctrl
{
  if (master.get_digital(DIGITAL_R1)){
   arm.move_velocity(100); // This is 100 because it's a 100rpm motor
  }
  else if (master.get_digital(DIGITAL_R2)){
   arm.move_velocity(-100);
  }
  else{
   arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
   arm.move_velocity(0);//bug: motor is too powerful
 }
}


void set_arm(int input)
{
  arm.move(input);
}
