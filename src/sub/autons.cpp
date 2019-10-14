#include "main.h"
void slowstraight(int Distance,int Velocity){
  drive.setMaxVelocity(Velocity);
  drive.moveDistance(Distance);
}

void redsidredsideUnprotected_5(){
  drive.setMaxVelocity(60);
  ////////////////////////////////////////////////
  ArmController.setTarget(450);
  ArmController.waitUntilSettled();
  ArmController.setTarget(-80);
  ArmController.stop();

  intakeController.setTarget(5000);//4000
  drive.moveDistance(1300);
  drive.stop();
  drive.turnAngle(33_deg);
  drive.moveDistance(1100);
  stackingintake(-50,50);//-100,30
  auto_tray();
  pros::delay(1000);
	//stackingintake(-50,30);
  drive.moveDistance(-300);
  intakeController.stop();

}

void blusidredsideUnprotected_5(){
  intakeController.setMaxVelocity(1000);
  drive.setMaxVelocity(60);
  ////////////////////////////////////////////////
  ArmController.setTarget(450);
  ArmController.waitUntilSettled();
  ArmController.setTarget(-80);
  ArmController.stop();

  intakeController.setTarget(4000);//4000
  drive.moveDistance(1100);
  drive.stop();
  drive.turnAngle(-33_deg);
  drive.moveDistance(1000);
  stackingintake(-50,50);//-100,30
  auto_tray();
  pros::delay(1000);
	//stackingintake(-50,30);
  drive.moveDistance(-300);
  intakeController.stop();

}
void movestraight(){
  intakeController.setMaxVelocity(1000);
  drive.setMaxVelocity(200);
  ////////////////////////////////////////////////
  ArmController.setTarget(450);
  ArmController.waitUntilSettled();
  ArmController.setTarget(-80);
  ArmController.stop();

  intakeController.setTarget(6000);//4000
  drive.moveDistance(1100);
  intakeController.waitUntilSettled();
  himeturnRight(100);
  drive.waitUntilSettled();

  /*drive.turnAngle(32.5_deg);
  drive.moveDistance(1000);
  stackingintake(-50,15);//-100,30
  auto_tray();
  pros::delay(1000);
	//stackingintake(-50,30);
  drive.moveDistance(-300);
  intakeController.stop();
*/
}

void lmaodoesntwork(){
  profileController.generatePath({Point{8_ft, 0_ft, 0_deg}, Point{8_ft, 3_ft, 0_deg}}, "A");
  profileController.setTarget("A");
  profileController.waitUntilSettled();
  profileController.removePath("A");
}//
void skills(){
}
void test(){
drive.moveDistance(1000);

}
