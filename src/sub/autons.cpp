#include "main.h"


void redsidredsideUnprotected_5(){
  intakeController.setMaxVelocity(1000);
  ArmController.setMaxVelocity(100);
  tiltController.setMaxVelocity(100);
  drive.setMaxVelocity(100);
  ////////////////////////////////////////////////

  intakeController.setTarget(4000);
  drive.moveDistance(1400);
  drive.stop();
  drive.turnAngle(30_deg);
  drive.moveDistance(1100);
  stackingintake(-100,30);
  auto_tray();
  pros::delay(1000);
	stackingintake(-50,30);
  drive.moveDistance(-200);
  intakeController.stop();
}
void redsidredsideUnprotected_10(){
  intakeController.setTarget(5000);
  drive.moveDistance(1000);
  himeturnleft(430);
  drive.moveDistance(1000);
  drive.turnAngle(65_deg);
  drive.moveDistance(400);
  tiltController.setTarget(2800);
  tiltController.waitUntilSettled();
}


void lmaodoesntwork(){
  profileController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3_ft, 0_ft, 0_deg}}, "A");
  profileController.setTarget("A");
  profileController.waitUntilSettled();
  profileController.removePath("A");
}//
void test(){
drive.moveDistance(1000);

}
