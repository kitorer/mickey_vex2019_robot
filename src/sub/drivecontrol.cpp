#include "main.h"
void brake_coast(){

   driveRightBack.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
   driveLeftBack.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
   driveRightFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
   driveLeftFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

}


void SetDriveSlower(int left, int right){
 driveRightBack = right-70;
 driveRightFront = right-70;
 driveLeftBack = left-60;
 driveLeftFront = left-60;
}
void Tank_control(void* param){

int  rightjoystick = master.get_analog(ANALOG_RIGHT_Y);
int  leftjoystick = master.get_analog(ANALOG_LEFT_Y);

if (abs(rightjoystick) < 10) rightjoystick = 0;
if(abs(leftjoystick) < 10) leftjoystick = 0;

 setDrive(leftjoystick,rightjoystick);

 driveRightBack.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
 driveLeftBack.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
 driveRightFront.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
 driveLeftFront.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}
