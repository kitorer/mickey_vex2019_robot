#include "main.h"




void Arm_control(void*)//opctrl
{
  if (master.get_digital(DIGITAL_R1)){

   arm.move_voltage(9000); // This is 100 because it's a 100rpm motor
  }  else if (master.get_digital(DIGITAL_R2)){
   arm.move_voltage(-12000);
  }  else{
   arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
   arm.move_velocity(0);//bug: motor is too powerful
 }}


//HELPER FUNCTIONS
void setArm (int power){
  arm.move_voltage(power);
}

void setArmHeight(){

}
/*DRIVER FUNCTIONS
void setArmMotor(){
  int armPower = 12000 * (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)-master.get_digital(pros::E_CONTROLLER_DIGITAL_R1));
  setArm(armPower);
}
*/
void arm_move(int distance, int voltage){
   while(abs(arm.get_position()) < distance){arm.move_voltage(voltage);}
   arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
   arm.move_velocity(0);
}
