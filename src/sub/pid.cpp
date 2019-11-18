#include "main.h"

#include "main.h"

void allMotorCoast()
{
  driveLeftFront.set_brake_mode(MOTOR_BRAKE_COAST);
  driveLeftBack.set_brake_mode(MOTOR_BRAKE_COAST);
  driveRightBack.set_brake_mode(MOTOR_BRAKE_COAST);
  driveRightFront.set_brake_mode(MOTOR_BRAKE_COAST);
}
void resetdriversencoders(){
 driveRightBack.tare_position();
 driveLeftBack.tare_position();
 driveRightFront.tare_position();
 driveLeftFront.tare_position();
}

void setDrive(int left, int right){//VELOCITY left & right
 driveRightBack = right;
 driveRightFront = right;
 driveLeftBack = left;
 driveLeftFront = left;
}

void moveProportional(int target){
  allMotorCoast();
  resetdriversencoders();
  float kp =.5;
  int error;

  while(true)
    {
     error = (target -driveLeftBack.get_position())*kp;// (setpoint-sensorval)*kp

        setDrive(error,error);
      pros::delay(20);
    }
}

void basePD(int target)
{
  allMotorCoast();
  resetdriversencoders();
  float kp =.3;
  float kd =.05;
  float ki=.1;

  int error;
  int lasterror;
  int derivative;
  int power;
  int integralRaw;
  float integral;
  bool timerbool=true;
    int absloute =  driveLeftBack.get_target_velocity();
  while(true)
    {
     error = (target -driveLeftBack.get_position());// (setpoint-sensorval)*kp



     derivative = (error - lasterror);
     lasterror = error;
     power = error*kp + derivative*kd;
        setDrive(power,power);
      pros::delay(20);
    }
  }

void basePID(int target){
  resetdriversencoders();
  float kp =.5;
  float kd =.05;
  float ki=.1;

  int error;
  int lasterror;
  int derivative;
  int power;
  int integralRaw;
  float integral;
  bool timerbool=true;

  while(error==0)
    {
   error = (target -driveLeftFront.get_position());// (setpoint-sensorval)*kp

     integralRaw = integralRaw +error;
     integral = ki*integralRaw;
     if(error == 0)
     {
       integral =0;
     }
     if (integral >200)
     {
      integral =0;
     }

     derivative = (error - lasterror);
     lasterror = error;
     power = error*kp +integral*ki+ derivative*kd ;
        setDrive(power,power);
    }
      pros::delay(15);
  }
/*

*/
