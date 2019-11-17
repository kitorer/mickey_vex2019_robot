#include "main.h"
void slowstraight(int Distance,int Velocity){
  drive.setMaxVelocity(Velocity);
  drive.moveDistance(Distance);
}
void Red_SideUnprotected_5(){
  drive.setMaxVelocity(65);
  ////////////////////////////////////////////////
  ArmController.setTarget(500);
  ArmController.waitUntilSettled();
  ArmController.setTarget(-80);
  ArmController.stop();

  intakeController.setTarget(6000);//4000
  drive.moveDistance(500);
  for(int i =0;i < 4;i++){//use to suck the line of 4
  	drive.setMaxVelocity(65);
  	drive.moveDistance(170);
  	drive.waitUntilSettled();
  }
  drive.turnAngle(33_deg);
  drive.moveDistance(1000);
  stackingintake(-50,50);//-100,30
  auto_tray();
  pros::delay(1000);
	//stackingintake(-50,30);
  drive.moveDistance(-300);
  intakeController.stop();

}

void Blu_SideUnprotected_5(){
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
void blu_sideprotected(){
  intakeController.setMaxVelocity(1000);
  drive.setMaxVelocity(150);
  ////////////////////////////////////////////////

  ArmController.setTarget(450);
  ArmController.waitUntilSettled();
  ArmController.setTarget(-80);
  ArmController.stop();

  intakeController.setTarget(6000);//4000
  drive.moveDistance(1200);
  //drive.waitUntilSettled();
  //drive.moveDistance(-270);
  //himeturnRight(230);
  //drive.turnAngle(9_deg);
  //rive.moveDistance(800);
  //drive.waitUntilSettled();

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

void red_Sideprotected(){
  intakeController.setMaxVelocity(1000);
  drive.setMaxVelocity(80);
  ////////////////////////////////////////////////

}//

void skills(){
  ArmController.setTarget(500);
   ArmController.waitUntilSettled();
   ArmController.setTarget(-80);
   ArmController.stop();
   drive.setMaxVelocity(80);
   intakeController.setTarget(17000);//4000
   //
   drive.moveDistance(400);
   drive.waitUntilSettled();

   for(int i =0;i < 4;i++){//use to suck the line of 4
     drive.setMaxVelocity(60);
     drive.moveDistance(170);
     drive.waitUntilSettled();
   }
   drive.moveDistance(300);
   drive.waitUntilSettled();
   //himeturnRight(30);
   drive.moveDistance(200);
   drive.waitUntilSettled();
   //drive.turnAngle(-15);
   drive.moveDistance(400);
   drive.waitUntilSettled();

   for(int i =0;i < 4;i++){//use to suck the line of 4
     drive.setMaxVelocity(60);
     drive.moveDistance(170);
     drive.waitUntilSettled();
   }
   drive.moveDistance(440);
   drive.waitUntilSettled();
   drive.turnAngle(10_deg);
   drive.moveDistance(450);
   drive.waitUntilSettled();

   stackingintake(-70,50);
   intakeController.stop();
   auto_tray();
   pros::delay(2000);
   slowstraight(80,40);
   drive.moveDistanceAsync(-300);//
   reverse_tray();
   drive.waitUntilSettled();
   drive.turnAngle(-30_deg);
   slowstraight(700,200);

}
void test(){
/*  intakeController.setMaxVelocity(1000);
  drive.setMaxVelocity(80);
  ArmController.setTarget(500);
   ArmController.waitUntilSettled();
   ArmController.setTarget(-80);
   ArmController.stop();
*/
   profileController.generatePath({
     Point{0_ft,0_ft,0_deg},
     Point{3_ft, 0_ft, 0_deg}}, "A");
   profileController.setTarget("A");
   profileController.waitUntilSettled();
//  moveForwardPID(4_ft);
   //profileController.removePath("A");
  }
  /*
  profileController.generatePath({Point{0_ft,0_ft,0_deg}, Point{2_ft, 2_ft, 90_deg}}, "A");
  profileController.setTarget("A");
  profileController.waitUntilSettled();
  profileController.removePath("A");
  */
