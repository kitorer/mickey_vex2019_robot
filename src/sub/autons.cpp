#include "main.h"

void easyonelmao()
{
  intakeController.setMaxVelocity(1000);

  ArmController.setMaxVelocity(100);
  tiltController.setMaxVelocity(100);
  drive.setMaxVelocity(100);
  ////////////////////////////////////////////////

  intakeController.setTarget(4000);
  drive.moveDistance(1000);
  drive.stop();
  drive.turnAngle(45_deg);
  drive.moveDistance(1000);

  drive.stop();
  drive.turnAngle(60_deg);
  drive.moveDistance(1300);
  tiltController.setTarget(2800);
  tiltController.waitUntilSettled();
  intakeController.setTarget(-100);
  intakeController.stop();
  drive.moveDistance(-300);
}
void himeturn()
{
  intakeController.setTarget(5000);
  drive.moveDistance(1000);
  himeturnleft(430);
  drive.moveDistance(1000);
  drive.turnAngle(40_deg);
  drive.moveDistance(300);
  tiltController.setTarget(2800);
  tiltController.waitUntilSettled();
}


void lmaodoesntwork()
{
  profileController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3_ft, 0_ft, 0_deg}}, "A");
  profileController.setTarget("A");
  profileController.waitUntilSettled();
  profileController.removePath("A");
}//
void test()
{
drive.moveDistance(1000);

}
