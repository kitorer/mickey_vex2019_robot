#include "main.h"


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
