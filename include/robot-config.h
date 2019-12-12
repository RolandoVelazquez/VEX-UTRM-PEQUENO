using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor TraDer;
extern motor DelDer;
extern motor TraIzq;
extern motor DelIzq;
extern motor Brazo1;
extern motor Brazo2;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );