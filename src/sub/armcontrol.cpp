#include "main.h"
/*
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

*/

void Arm_control(void*)//opctrl
{
  if (master.get_digital(DIGITAL_R1)){
   arm.move_voltage(12000); // This is 100 because it's a 100rpm motor
  }
  else if (master.get_digital(DIGITAL_R2)){
   arm.move_voltage(-12000);
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

int a_target;
void
set_arm_pid(int input) {
  a_target = input;
}
void arm_pid(void*)
{
  while (true)
   {
    set_arm((a_target-arm.get_position())*0.5);
    pros::delay(20);
  }
}


void
Arm_macro (void*) {
	pros::Controller master(CONTROLLER_MASTER);
pros::Task arm_t (arm_pid);
	bool was_pid;
	//while (true) {
		if (master.get_digital(DIGITAL_X)) {
			was_pid = true;
			arm_t.resume();
			set_arm_pid(2300);
		} else if (master.get_digital(DIGITAL_A)) {
			was_pid = true;
			arm_t.resume();
			set_arm_pid(1800);
		} else {
			if (master.get_digital(DIGITAL_R1)||master.get_digital(DIGITAL_R2)) {
				was_pid = false;
				set_arm((master.get_digital(DIGITAL_R1)-master.get_digital(DIGITAL_R2))*127);
			} else {
				if (!was_pid) {
					set_arm(0);
				}
			}
	//	}

		if (!was_pid) {
			arm_t.suspend();
		}

		pros::delay(20);
	}
}
