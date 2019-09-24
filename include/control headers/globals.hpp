#include "main.h"

using namespace okapi;

// Variables
extern int toggleval;

// Controller
extern pros::Controller master;

// @victor extern is used to let the compiler know that we have already declared
// these objects somewhere else but we want to use them here (and include them
// in main.h so all files have acess to it). In this case, they were declared in
// globals.cpp

extern pros::Motor driveLeftBack;
extern pros::Motor driveRightBack;
extern pros::Motor driveLeftFront;
extern pros::Motor driveRightFront;
extern pros::Motor Tray;
extern pros::Motor arm;
extern pros::Motor Lintake;
extern pros::Motor Rintake;

extern ChassisControllerIntegrated drive;

extern AsyncPosIntegratedController intakeController;
extern AsyncPosIntegratedController ArmController;
extern AsyncPosIntegratedController tiltController;

extern AsyncMotionProfileController profileController;
// Function headers
int sgn(int input);

int clipnum(int input, int clip);

void toggle();


///////////////// autons
void redsidredsideUnprotected_5();
void redsidredsideUnprotected_10();
void lmaodoesntwork();
void test();
