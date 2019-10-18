#include "main.h"

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor driveLeftBack(11, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveRightBack(20, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveLeftFront(12, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveRightFront(19, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor Tray(8, pros::E_MOTOR_GEARSET_36,true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor arm(9, pros::E_MOTOR_GEARSET_36,false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor Lintake(2,pros::E_MOTOR_GEARSET_36,false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor Rintake(10, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);

//AsyncVelPIDController ArmController = AsyncControllerFactory::velPID(9, 2, 5);
ChassisControllerIntegrated drive = ChassisControllerFactory::create(
     {11,12},//left side
     {-19,-20},//right side
     AbstractMotor::gearset::green,
     {4,13.5}
);

AsyncMotionProfileController profileController = AsyncControllerFactory::motionProfile(
  1.0,  // Maximum linear velocity of the Chassis in m/s
  2.0,  // Maximum linear acceleration of the Chassis in m/s/s
  10.0, // Maximum linear jerk of the Chassis in m/s/s/s
  drive // Chassis Controller
);

AsyncPosIntegratedController tiltController = AsyncControllerFactory::posIntegrated(-8);
AsyncPosIntegratedController ArmController = AsyncControllerFactory::posIntegrated(9);
AsyncPosIntegratedController intakeController = AsyncControllerFactory::posIntegrated({2,-10});

/*
int sgn(int input){
  if (input>0)
    return 1;
  else if (input < 0)
    return -1;
  return 0;
}
int clipnum(int input, int clip){
  if (input > clip)
    return clip;
  else if (input < clip)
    return -clip;
  return input;
}
*/
int toggleval = 0;
int count;
/*
void toggle(){
  if (master.get_digital(DIGITAL_B))
  {
    toggleval =1;
  }
  else if(master.get_digital_new_press(DIGITAL_B))
  {
    toggleval =0;
  }
}
*/
void slowdown(){ //returns an integer that slowly decreases


}
