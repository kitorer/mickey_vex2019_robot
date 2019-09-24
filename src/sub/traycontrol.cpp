#include "main.h"


////////////////////////////////////////////////////////////////////////
void Tray_control()
{
  if (master.get_digital(DIGITAL_UP)) {
   Tray.move_voltage(6000); // This is 100 because it's a 100rpm motor
   Tray.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
 }
 else if (master.get_digital(DIGITAL_DOWN)) {
   Tray.move_voltage(-12000);
 }
 else
 {
   Tray.move_velocity(0);
 }
}
////////////////////////////////////////////////////////////////////////////////

//HELPER FUNCTIONS
void setTrayAngler (int power){
  Tray.move_voltage(power);
}

//DRIVER FUNCTIONS
void setTrayAnglerMotor(void*){
  int trayAnglerPower = 12000 *
  (master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)-master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN));
  set_arm(trayAnglerPower);
}

//auton function
void auto_tray(){//should be same values (430 works as 180deg )	himeturnleft(430);

  Tray.tare_position();
  while(Tray.get_position()<2600){
    if(Tray.get_position()<1340)
    {
    setTrayAngler(12000);//full power
    pros::delay(10);
    }

    if(Tray.get_position()>1300 && Tray.get_position()<2600)  {
    setTrayAngler(6100);//full power
    pros::delay(10);
    }
    else{
    Tray.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    }
  }
    setTrayAngler(0);
}

void tray_macro(void*){//macro function
  while(master.get_digital(DIGITAL_LEFT)){
  auto_tray();
  }
}
