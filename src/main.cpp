/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\velaz                                            */
/*    Created:      Wed Dec 11 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// TraDer               motor         1               
// DelDer               motor         11              
// TraIzq               motor         10              
// DelIzq               motor         20              
// Brazo1               motor         9               
// Brazo2               motor         2               
// Controller1          controller                    
// Pinza                motor         5               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;


void axisIzquierdo(){
  DelIzq.setVelocity((Controller1.Axis3.position() + Controller1.Axis4.position())/2,percent);
  DelDer.setVelocity((Controller1.Axis3.position() - Controller1.Axis4.position())/2, percent);
  TraIzq.setVelocity((Controller1.Axis3.position() + Controller1.Axis4.position())/2,percent);
  TraDer.setVelocity((Controller1.Axis3.position() - Controller1.Axis4.position())/2, percent);
}

void axisDerecho(){
  Brazo1.setVelocity(Controller1.Axis2.position(), percent);
  Brazo2.setVelocity(Controller1.Axis2.position(), percent);
}

void cerrarGarra(){
  Pinza.spin(forward);
  Pinza.setVelocity(-100, percent);
  waitUntil(!Controller1.ButtonL1.pressing());
  Pinza.stop();
}

void abrirGarra(){
  Pinza.spin(forward);
  Pinza.setVelocity(100, percent);
  waitUntil(!Controller1.ButtonR1.pressing());
  Pinza.stop();
}

int main() {

vexcodeInit();

while(true){

  axisIzquierdo();
  axisDerecho();
  
  Controller1.ButtonL1.pressed(cerrarGarra);
  Controller1.ButtonR1.pressed(abrirGarra);


  Pinza.setStopping(hold);
  Brazo1.spin(forward);
  Brazo2.spin(forward);

  DelDer.spin(forward);
  DelIzq.spin(forward);
  TraDer.spin(forward);
  TraIzq.spin(forward);

  
  wait(25, msec);
}
}
