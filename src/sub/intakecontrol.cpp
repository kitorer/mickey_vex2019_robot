#include "main.h"

void stackingintake(int distance,int velocity){//okapi
    intakeController.setMaxVelocity(velocity);
    intakeController.setTarget(distance);
}

void intakereset (){
  Rintake.tare_position();
}
////////////////////////////////////////////////////////////////
void Intake_control(void*){
  if (master.get_digital(DIGITAL_L1)){
  Lintake.move_voltage(12000); // This is 100 because it's a 100rpm motor
  Rintake.move_voltage(12000);
  }
 else if (master.get_digital(DIGITAL_L2)){
  Rintake.move_voltage(-12000);
  Lintake.move_voltage(-12000);
 }
 else{
   Rintake.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
   Lintake.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  Rintake.move_velocity(0);
  Lintake.move_velocity(0);//bug: motor is too powerful
}
}
///////////////////////////////////////////////////////////////////////

//HELPER FUNCTIONS
void setIntake (int power){
  Lintake.move_voltage(power);
  Rintake.move_voltage(power);
}

//DRIVER FUNCTIONS
void setIntakeMotors(void*){
  int intakePower = 12000 *
  (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)-master.get_digital(pros::E_CONTROLLER_DIGITAL_L1));
  setIntake(intakePower);
}

//auton or macro use (doesnt work okapi is used instead)
void intake_macro(int distance,int voltage)
{
    intakereset();
  if(Rintake.get_position() < distance){//forward
     setIntake(1200);
  }
  if(Rintake.get_position() > distance){//backward
     setIntake(-3000);
  }
}
