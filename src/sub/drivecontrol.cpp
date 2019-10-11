#include "main.h"

void setDrive(int left, int right){//VELOCITY left & right
 driveRightBack = right-10;
 driveRightFront = right-10;
 driveLeftBack = left;
 driveLeftFront = left;
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
/*
if(master.get_digital(DIGITAL_L1) ){//now only slows down when joysitcks are being used @ slower speed
  SetDriveSlower(leftjoystick, rightjoystick);
}else{//normal drive controls @full speed & no more drift
 setDrive(leftjoystick,rightjoystick);
}*/
 setDrive(leftjoystick,rightjoystick);

 driveRightBack.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
 driveLeftBack.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
 driveRightFront.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
 driveLeftFront.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void resetdriversencoders(){
 driveRightBack.tare_position();
 driveLeftBack.tare_position();
 driveRightFront.tare_position();
 driveLeftFront.tare_position();
}
void customforward(int units,int velocity){
 resetdriversencoders();
 //reset motor encoders
 //drive forward unitl units are reaches
 //brake
 while(driveLeftFront.get_position()< units){
   setDrive(velocity,velocity-10);
   pros::delay(10);
 }
 setDrive(-10,-10);
 pros::delay(50);
   setDrive(0,0);
}

void himeturnleft(int turndeg){//should be same values (430 works as 180deg )	himeturnleft(430);
 resetdriversencoders();
 while(driveLeftFront.get_position()< turndeg){
   setDrive(30,200);//50 for left
   pros::delay(10);
 }
 setDrive(-10,-10);
 pros::delay(50);
   setDrive(0,0);
}

void himeturnRight(int turndeg){
 resetdriversencoders();
 while(driveRightFront.get_position()< turndeg){
   setDrive(200,30);//50 for left
   pros::delay(10);
 }
 setDrive(-10,-10);
 pros::delay(50);
   setDrive(0,0);
}
