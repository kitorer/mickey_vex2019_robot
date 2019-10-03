#include "main.h"

  void tray_macro(void*){//macro function
  while(master.get_digital(DIGITAL_LEFT))
    auto_tray();
  }
