#include "main.h"

ChassisControllerIntegrated drive = ChassisControllerFactory::create(
     {11,12},//left side
     {-19,-20},//right side
     AbstractMotor::gearset::green,
     {4,13.5}
);

AsyncMotionProfileController profileController = AsyncControllerFactory::motionProfile(
  1.0,  // Maximum linear velocity of the Chassis in m/s
  2.0,  // Maximum linear acceleration of the Chassis in m/s/s
  10.0, // Maximum linear jerk of the Chassis in m/s/s/s
  drive // Chassis Controller
);

AsyncPosIntegratedController tiltController = AsyncControllerFactory::posIntegrated(-8);
AsyncPosIntegratedController ArmController = AsyncControllerFactory::posIntegrated(9);
AsyncPosIntegratedController intakeController = AsyncControllerFactory::posIntegrated({1,-10});
