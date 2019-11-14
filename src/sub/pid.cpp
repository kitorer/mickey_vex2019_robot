#include "main.h"

float kp;
float ki;
float kd;

float currentL = 0;
float currentR =0;
float pi=3.14592653589;
float circ ;

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



void basePID(int distance){


    while( distance < driveLeftBack.get_target_position() &&
    distance < driveRightBack.get_target_position() )
      {
//proportional section
     errorL= distance - driveLeftBack.get_target_position();
     errorR= distance - driveRightBack.get_target_position();
//integral section
     integralL =  integralL +  errorL;
     integralR =  integralR +  errorR;

    if ( errorL == 0||  errorL >distance)
    {
       integralL =0;
    }
    if(  errorR == 0||  errorR >distance )
    {
       integralR =0;
    }
    if(  integralL >200)// powerL &&  errorR > powerR )  //if error is big
    {
       integralL =0;
       integralR =0;
    }

//derivative section
     derivativeL =  errorL - lastErrorL;
     derivativeR =  errorR - lastErrorR;
     lastErrorL=  errorL;
     lastErrorR=  errorR;


     powerL =  errorL *  kp +
                              integralL *  ki +
                              derivativeL *  kd;

     powerR =  errorR *  kp +
                              integralR *  ki +
                              derivativeR *  kd;

    setDrive( powerL,  powerR);
  }
}
