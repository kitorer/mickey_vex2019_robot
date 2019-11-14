#include "main.h"
typedef struct {
  float kp;
  float ki;
  float kd;

  float currentL = 0;
  float currentR =0;
  float pi=3.14592653589;
  float circ ;
  float ticksToFeet = 71.656;

   float powerL;
   float powerR;
   float errorL;
   float errorR;
   float lastErrorL;
   float lastErrorR;
   float proportionL;
   float proportionR;
   float integralL;
   float integralR;
   float derivativeL;
   float derivativeR;
}PID;

void moveForwardPID(QLength feet)
{
  profileController.moveTo({Point{0_ft, 0_ft, 0_deg}, Point{feet, 0_ft, 0_deg}});
}

void basePID(int distance){
  PID moveStraightPID;

    while( distance > driveLeftBack.get_target_position() &&
    distance > driveRightBack.get_target_position() );
//proportional section
    moveStraightPID.errorL= distance - driveLeftBack.get_target_position();
    moveStraightPID.errorR= distance - driveRightBack.get_target_position();
//integral section
    moveStraightPID.integralL = moveStraightPID.integralL + moveStraightPID.errorL;
    moveStraightPID.integralR = moveStraightPID.integralR + moveStraightPID.errorR;

    if (moveStraightPID.errorL == 0|| moveStraightPID.errorL >distance)
    {
      moveStraightPID.integralL =0;
    }
    if( moveStraightPID.errorR == 0|| moveStraightPID.errorR >distance )
    {
      moveStraightPID.integralR =0;
    }
    if( moveStraightPID.errorL >moveStraightPID.powerL && moveStraightPID.errorR >moveStraightPID.powerR )  //if error is big
    {
      moveStraightPID.integralL =0;
      moveStraightPID.integralR =0;
    }

//derivative section
    moveStraightPID.derivativeL = moveStraightPID.errorL -moveStraightPID.lastErrorL;
    moveStraightPID.derivativeR = moveStraightPID.errorR -moveStraightPID.lastErrorR;
    moveStraightPID.lastErrorL= moveStraightPID.errorL;
    moveStraightPID.lastErrorR= moveStraightPID.errorR;


    moveStraightPID.powerL = moveStraightPID.errorL * moveStraightPID.kp +
                             moveStraightPID.integralL * moveStraightPID.ki +
                             moveStraightPID.derivativeL * moveStraightPID.kd;

    moveStraightPID.powerR = moveStraightPID.errorR * moveStraightPID.kp +
                             moveStraightPID.integralR * moveStraightPID.ki +
                             moveStraightPID.derivativeR * moveStraightPID.kd;

    setDrive(moveStraightPID.powerL, moveStraightPID.powerR);

}
