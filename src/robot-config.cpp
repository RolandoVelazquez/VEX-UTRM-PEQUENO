#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor TraDer = motor(PORT1, ratio18_1, true);
motor DelDer = motor(PORT11, ratio18_1, true);
motor TraIzq = motor(PORT10, ratio18_1, false);
motor DelIzq = motor(PORT20, ratio18_1, false);
motor Brazo1 = motor(PORT9, ratio18_1, true);
motor Brazo2 = motor(PORT2, ratio18_1, false);
controller Controller1 = controller(primary);
motor Pinza = motor(PORT5, ratio18_1, false);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}