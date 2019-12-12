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
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

void subirBrazo(int velocidad){
  Brazo1.setVelocity(velocidad,percent);
  Brazo2.setVelocity(velocidad,percent);
  Brazo1.spin(forward);
  Brazo2.spin(forward);
}

void bajarBrazo(int velocidad){
  Brazo1.setVelocity(-velocidad,percent);
  Brazo2.setVelocity(-velocidad,percent);
  Brazo1.spin(forward);
  Brazo2.spin(forward);
}

void adelanteAtras(){
  
  DelDer.setVelocity(Controller1.Axis3.position(), percent);
  TraDer.setVelocity(Controller1.Axis3.position(), percent);
  DelIzq.setVelocity(Controller1.Axis3.position(), percent);
  TraIzq.setVelocity(Controller1.Axis3.position(), percent);
  DelDer.spin(forward);
  TraDer.spin(forward);
  DelIzq.spin(forward);
  TraIzq.spin(forward);
}
void otro(){
    Brain.Screen.clearLine();

    Brain.Screen.print(Controller1.Axis2.position());
    Brain.Screen.print(Controller1.Axis2.position());

   // DelDer.setVelocity(Controller1.Axis3.position(),percent);
    DelDer.setVelocity(Controller1.Axis2.position(),percent);
    TraDer.setVelocity(Controller1.Axis2.position(),percent);

   // DelDer.setVelocity(Controller1.Axis4.position(),percent);
    //DelDer.spin(forward);
    DelIzq.spin(forward);
    DelDer.spin(forward);
    TraIzq.spin(forward);
    TraDer.spin(forward);
}

void izquierda(){
    Brain.Screen.clearLine();

    Brain.Screen.print(Controller1.Axis4.position());
    Brain.Screen.print(Controller1.Axis3.position());

   // DelDer.setVelocity(Controller1.Axis3.position(),percent);
    DelIzq.setVelocity(Controller1.Axis3.position(),percent);
   
    TraIzq.setVelocity(Controller1.Axis3.position(),percent);

   // DelDer.setVelocity(Controller1.Axis4.position(),percent);
    //DelDer.spin(forward);
    DelIzq.spin(forward);
    DelDer.spin(forward);
    TraIzq.spin(forward);
    TraDer.spin(forward);


  /*DelDer.setVelocity(Controller1.Axis4.position(), percent);
  TraDer.setVelocity(Controller1.Axis4.position(), percent);
  DelIzq.setVelocity(-Controller1.Axis4.position(), percent);
  TraIzq.setVelocity(-Controller1.Axis4.position(), percent);
  DelDer.spin(forward);
  TraDer.spin(forward);
  DelIzq.spin(forward);
  TraIzq.spin(forward);*/
}
void derecha(){
         //   Brain.Screen.clearScreen();

    Brain.Screen.print("si");


 // Brain.Screen.print(Controller1.Axis4.position());
  /*DelDer.setVelocity(-Controller1.Axis4.position(), percent);
  TraDer.setVelocity(-Controller1.Axis4.position(), percent);
  DelIzq.setVelocity(Controller1.Axis4.position(), percent);
  TraIzq.setVelocity(Controller1.Axis4.position(), percent);
  DelDer.spin(forward);
  TraDer.spin(forward);
  DelIzq.spin(forward);
  TraIzq.spin(forward);*/
}

void apagarMotores(){
  TraIzq.stop();
  TraDer.stop();
  DelDer.stop();
  TraDer.stop();
}

void giros(){
int poss = Controller1.Axis4.position();
if (poss < 1){
  Brain.Screen.print("si");
}
if(poss >1){
  Brain.Screen.print("nO");
}
else{
  apagarMotores();
}

}


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  int velocidadBrazo = 100;
  while(true){

   while(Controller1.ButtonR1.pressing()){
    subirBrazo(velocidadBrazo);
   }
  
   while(Controller1.ButtonR2.pressing()){
    bajarBrazo(velocidadBrazo);
   }

   Brazo1.stop();
   Brazo2.stop();
  
  /*while (Controller1.Axis4.position() > 1){
    izquierda();
  }*/
  //apagarMotores();
  /*while (Controller1.Axis4.position() < 1){
    derecha();
  }*/
  
    otro();

    izquierda();
  //apagarMotores();

//  adelanteAtras();

   //Controller1.Axis4.changed(giros);
   

   // Controller1.Axis3.changed(adelateAtras);
   //apagarMotores();

  }
}
