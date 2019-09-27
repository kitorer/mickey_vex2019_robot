#include "main.h"

  void tray_macro(void*){//macro function
  while(master.get_digital(DIGITAL_LEFT)){
    intake_macro(-50,-3000);
    auto_tray();
    intake_macro(50,3000);
  }
}
