#include "main.h"


////////////////////////////////////////////////////////////////////////
void Tray_control(void*)//with the arm
{
  if(master.get_digital(DIGITAL_R1) && Tray.get_position() <400) {
   Tray.move_voltage(12000); // This is 100 because it's a 100rpm motor
   Tray.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
} else if(master.get_digital(DIGITAL_R2) && Tray.get_position() >0){
  Tray.move_voltage(-8000);
}}

////////////////////////////////////////////////////////////////////////////////

//HELPER FUNCTIONS
void setTrayAngler (int power){
  Tray.move_voltage(power);
}

//DRIVER FUNCTIONS
void setTrayAnglerMotor(void*){

  if (master.get_digital(DIGITAL_UP)) {
   Tray.move_voltage(12000); // This is 100 because it's a 100rpm motor
   Tray.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
 } else if (master.get_digital(DIGITAL_DOWN)) {
   Tray.move_voltage(-12000);
 }else{
   Tray.move_velocity(0);
}}

//auton functions
void set_tray(int distance, int voltage){
    Tray.tare_position();
    while(Tray.get_position()<distance){
      setTrayAngler(voltage);
}}

void auto_tray(void)
{
  Tray.tare_position();
  Tray.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  while (Tray.get_position() < 2800)
  {
//        if (Tray.get_position() < 1500)
            setTrayAngler(12000); // full power

//        else
//            setTrayAngler(6100); // half power

        pros::delay(10);
   }
   Tray.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
   setTrayAngler(0);
}


void reverse_tray(void)
{
  Tray.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    while(Tray.get_position() >0)
  {
//        if (Tray.get_position() < 1500)
            setTrayAngler(-12000); // full power
//        else
//            setTrayAngler(6100); // half power

        pros::delay(10);
   }
   Tray.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
   setTrayAngler(0);
}

void reverse_tray(void)
{
  //Tray.tare_position();
  Tray.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  while (Tray.get_position() > 0)
  {
//        if (Tray.get_position() < 1500)
            setTrayAngler(-12000); // full power
//        else
//            setTrayAngler(6100); // half power

        pros::delay(10);
   }
   Tray.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
   setTrayAngler(0);
}
