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

  intakeController.setTarget(5000);//4000
  drive.moveDistance(500);
  for(int i =0;i < 4;i++){//use to suck the line of 4
  	drive.setMaxVelocity(65);
  	drive.moveDistance(170);
  	drive.waitUntilSettled();
  }
  drive.turnAngle(33_deg);
  drive.moveDistance(1200);
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

   intakeController.setTarget(17000);//4000
   // /*
   drive.moveDistance(400);
   drive.waitUntilSettled();

   for(int i =0;i < 4;i++){//use to suck the line of 4
     drive.setMaxVelocity(60);
     drive.moveDistance(170);
     drive.waitUntilSettled();
   }
   drive.moveDistance(300);
   drive.waitUntilSettled();
   himeturnRight(30);
   drive.moveDistance(200);
   drive.waitUntilSettled();
   drive.turnAngle(-15);
   drive.moveDistance(400);
   drive.waitUntilSettled();

   for(int i =0;i < 4;i++){//use to suck the line of 4
     drive.setMaxVelocity(60);
     drive.moveDistance(170);
     drive.waitUntilSettled();
   }

   drive.turnAngle(9.5_deg);
   drive.moveDistance(750);
   drive.waitUntilSettled();
   auto_tray();
   drive.moveDistanceAsync(-300);//*/
   drive.turnAngle(-20_deg);
   slowstraight(700,200);

}
void test(){
drive.moveDistance(1000);
/*
  profileController.generatePath({Point{0_ft,0_ft,0_deg}, Point{2_ft, 2_ft, 90_deg}}, "A");
  profileController.setTarget("A");
  profileController.waitUntilSettled();
  profileController.removePath("A");
  */

}
