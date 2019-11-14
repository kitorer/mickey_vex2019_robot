#include "main.h"
void slowstraight(int Distance,int Velocity){
  drive.setMaxVelocity(Velocity);
  drive.moveDistance(Distance);
}
void Red_SideUnprotected_5(){
  drive.moveDistance(400);
  drive.waitUntilSettled();
  drive.moveDistance(-500);
/*

  drive.setMaxVelocity(65);
  ////////////////////////////////////////////////
  ArmController.setTarget(500);
  //intakeController.setTarget(-100);
  ArmController.waitUntilSettled();
  pros::delay(500);
  ArmController.setTarget(-80);
  ArmController.stop();
  drive.moveDistance(-50);
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
  drive.moveDistance(-500);
  intakeController.stop();
*/
}

void Blu_SideUnprotected_5(){
  intakeController.setMaxVelocity(1000);
  drive.setMaxVelocity(60);
  ////////////////////////////////////////////////
  drive.moveDistance(400);
  drive.waitUntilSettled();
  drive.moveDistance(-500);
/* ArmController.setTarget(450);
  ArmController.waitUntilSettled();
  ArmController.setTarget(-80);
  ArmController.stop();
  drive.moveDistance(-50);
  intakeController.setTarget(6000);//4000
  drive.moveDistance(500);
  for(int i =0;i < 3;i++){//use to suck the line of 4
  	drive.setMaxVelocity(65);
  	drive.moveDistance(170);
  	drive.waitUntilSettled();
  }
  drive.turnAngle(-33_deg);
  drive.moveDistance(900);
  stackingintake(-50,50);//-100,30
  auto_tray();
  pros::delay(1000);
	//stackingintake(-50,30);
  drive.moveDistance(-500);
  intakeController.stop();

}
void blu_sideprotected(){
  intakeController.setMaxVelocity(1000);
  drive.setMaxVelocity(100);
  ////////////////////////////////////////////////

  ArmController.setTarget(450);
  ArmController.waitUntilSettled();
  ArmController.setTarget(-80);
  ArmController.stop();
  drive.moveDistance(-50);
  intakeController.setTarget(9000);//4000
  drive.moveDistance(1200);
  drive.turnAngle(5_deg);
  drive.moveDistance(200);
  drive.moveDistance(-200);
  drive.turnAngle(23_deg);
  drive.moveDistance(1150);
  auto_tray();
  stackingintake(-50,50);
  pros::delay(700);
  drive.moveDistance(-500);*/
}

void red_Sideprotected(){
  intakeController.setMaxVelocity(1000);
  drive.setMaxVelocity(100);
  ////////////////////////////////////////////////

  ArmController.setTarget(450);
  ArmController.waitUntilSettled();
  ArmController.setTarget(-80);
  ArmController.stop();
  drive.moveDistance(-50);
  intakeController.setTarget(9000);//4000
  drive.moveDistance(1200);
  drive.turnAngle(-6_deg);
  drive.moveDistance(200);
  drive.moveDistance(-200);
  drive.turnAngle(-21_deg);
  drive.moveDistance(1100);
  auto_tray();
  stackingintake(-50,50);
  pros::delay(1000);
  drive.moveDistance(-300);
}//

void skills(){
  ArmController.setTarget(500);
   ArmController.waitUntilSettled();
   ArmController.setTarget(-80);
   ArmController.stop();
   drive.setMaxVelocity(80);
   intakeController.setTarget(18000);//4000
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
   drive.moveDistance(550);
   drive.waitUntilSettled();
   drive.turnAngle(10_deg);
   drive.moveDistance(230);
   drive.waitUntilSettled();

   stackingintake(-50,30);
   intakeController.stop();
   auto_tray();
   pros::delay(2000);
   slowstraight(80,40);
   drive.moveDistanceAsync(-500);//
   drive.waitUntilSettled();
   reverse_tray();
   drive.turnAngle(-28_deg);
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

profileController.generatePath({Point{4_ft,0_ft,0_deg}, Point{6_ft, 0_ft, 0_deg}}, "A");
profileController.setTarget("A");
profileController.waitUntilSettled();
profileController.removePath("A");
 //profileController.removePath("A");
  }
  /*
  profileController.generatePath({Point{0_ft,0_ft,0_deg}, Point{2_ft, 2_ft, 90_deg}}, "A");
  profileController.setTarget("A");
  profileController.waitUntilSettled();
  profileController.removePath("A");
  */
