#include "main.h"

void easyonelmao()
{
  intakeController.setMaxVelocity(1000);

  ArmController.setMaxVelocity(100);
  tiltController.setMaxVelocity(100);
  drive.setMaxVelocity(100);
  ////////////////////////////////////////////////

  intakeController.setTarget(7000);
  drive.moveDistance(2600);

  intakeController.setTarget(4000);
  drive.moveDistance(1000);
  drive.stop();
  drive.turnAngle(45_deg);
  drive.moveDistance(1000);

  drive.stop();
  drive.turnAngle(60_deg);
  drive.moveDistance(2600);
  tiltController.setTarget(5600);
  tiltController.waitUntilSettled();
  intakeController.setTarget(-80);
  intakeController.stop();
  drive.moveDistance(-400);
}
void himeturn()
{
  drive.moveDistance(1000);

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
drive.stop();
ArmController.reset();
tiltController.reset();
intakeController.reset();
}
