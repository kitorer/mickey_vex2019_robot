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

void forwardPID(int target){
  resetdriversencoders();
  allMotorCoast();
  float kp =.5;
  float kd =.05;
  float ki=.2;

  int error;
  int lasterror;
  int derivative;
  int power;
  float integral;

  while(error!=0)
    {
   error = (target -driveLeftBack.get_position());// (setpoint-sensorval)*kp
      if(error >150){
        error=150;
      }
//-----------------------------------------------------
     integral = (integral +error)*ki;
     if(error == 0)
     {
       integral =0;
     }
     if (integral >20)
     {
      integral =20;
     }
//------------------------------------------------------
     derivative = (error - lasterror);
     lasterror = error;
     power = error*kp +integral*ki+ derivative*kd ;

     int Rdiff =(driveLeftBack.get_position()-driveRightBack.get_position())*.6;//slows down right side if it is faster
     int Ldiff =(driveRightBack.get_position()-driveLeftBack.get_position())*.6;//slows down left side if it is faster

        setDrive(power + Ldiff ,power +Rdiff );

    }
      pros::delay(15);
  }

  void backPID(int target){
    resetdriversencoders();
    allMotorCoast();
    float kp =.5;
    float kd =.05;
    float ki=.2;

    int error;
    int lasterror;
    int derivative;
    int power;

    float integral;

    while(true)
      {
     error = (target +abs(driveLeftBack.get_position()));// (setpoint-sensorval)*kp
        if(error <-150){
          error=-150;
        }
           power = error*kp +integral*ki+ derivative*kd ;
          setDrive(power,power);
      }
        pros::delay(15);
    }


    void turnLPID(int target){
      resetdriversencoders();
      float kp =.5;
      float kd =.05;
      float ki=.2;

      int error;
      int lasterror;
      int derivative;
      int power;
      float integral;

      while(error!=0)
        {
       error = (target -driveRightBack.get_position());// (setpoint-sensorval)*kp
          if(error >150){
            error=150;
          }
    //-----------------------------------------------------
         integral = (integral +error)*ki;
         if(error == 0)
         {
           integral =0;
         }
         if (integral >20)
         {
          integral =20;
         }
    //------------------------------------------------------
         derivative = (error - lasterror);
         lasterror = error;
         power = error*kp +integral*ki+ derivative*kd ;

            setDrive(-power*1.02 ,power);

        }
          pros::delay(15);
      }
