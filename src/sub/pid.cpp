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
      if(driveLeftBack.get_position() <  target/4){
        error=driveLeftBack.get_position()+5;
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

     int Rdiff =(driveLeftBack.get_position()-driveRightBack.get_position())*.3;//slows down right side if it is faster

        setDrive(power  ,power +Rdiff );

    }
      pros::delay(15);
  }

  void backPID(int target/*has to be negative*/){
     resetdriversencoders();
     allMotorCoast();
     float kp =.6;
     float kd =.05;
     float ki=.2;

     int error;
     int lasterror;
     int derivative;
     int power;

     float integral;

     while(error!=0)
       {
      error = (target +abs(driveLeftBack.get_position()));// (setpoint-sensorval)*kp
       if(error<-100){
         error =-100;
       }

       integral = (integral +error)*ki;
       if(error == 0)
       {
         integral =0;
       }
       if (integral >30)

       {
        integral =30;
       }
       derivative = (error - lasterror);
       lasterror = error;

            power = error*kp +integral*ki+ derivative*kd ;

            int Rdiff =(driveLeftBack.get_position()-driveRightBack.get_position())*.3;//returns a negative value

           setDrive(power,power-Rdiff);
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

       while(true)
         {
        error = (target -driveRightBack.get_position());// (setpoint-sensorval)*kp
           if(error >130){
             error=130;
           }
     //-----------------------------------------------------
          integral = (integral +error)*ki;
          if(error == 0)
          {
            integral =0;
          }
          if (integral >30)
          {
           integral =30;
          }
     //------------------------------------------------------
          derivative = (error - lasterror);
          lasterror = error;
          power = error*kp +integral*ki+ derivative*kd ;

             setDrive(-power ,power);

         }
           pros::delay(15);
       }

          void turnRPID(int target){
            resetdriversencoders();
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
             error = (target -driveLeftBack.get_position());// (setpoint-sensorval)*kp
                if(error >130){
                  error=130;
                }
          //-----------------------------------------------------
               integral = (integral +error)*ki;
               if(error == 0)
               {
                 integral =0;
               }
               if (integral >30)
               {
                integral =30;
               }
          //------------------------------------------------------
               derivative = (error - lasterror);
               lasterror = error;
               power = error*kp +integral*ki+ derivative*kd ;

                  setDrive(power ,-power);

              }
                pros::delay(15);
            }
