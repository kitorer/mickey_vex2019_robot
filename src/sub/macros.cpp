#include "main.h"

  void tray_macro(void*){//macro function
  while(master.get_digital(DIGITAL_LEFT))
    auto_tray();
  }

  void arm_macro(void*){
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_X)) {
      count++;
      if (count % 4 == 1){
        arm_move(1500,12000);
        set_tray(300, 12000);
      }     else if (count % 4 == 2){
        arm_move(1800,12000);
      }    else if(count % 4 == 3){
        arm_move(2300,12000);
      }else{
        count=0;
        set_tray(300, -12000);
      }}}
