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


void funcionAdelante(bool permitirAdelante){
  if (permitirAdelante){
   DelDer.setVelocity(Controller1.Axis3.position(),percent);
   DelIzq.setVelocity(Controller1.Axis3.position(),percent);
   TraDer.setVelocity(Controller1.Axis3.position(),percent);
   TraIzq.setVelocity(Controller1.Axis3.position(),percent);

  DelDer.spin(forward);
  DelIzq.spin(forward);
  TraDer.spin(forward);
  TraIzq.spin(forward);
  }
}

void funcionGiros(bool permitirAdelante){
  if(!permitirAdelante){
     DelDer.setVelocity(-Controller1.Axis1.position(),percent);
   DelIzq.setVelocity(Controller1.Axis1.position(),percent);
   TraDer.setVelocity(-Controller1.Axis1.position(),percent);
   TraIzq.setVelocity(Controller1.Axis1.position(),percent);

    DelDer.spin(forward);
    DelIzq.spin(forward);
    TraDer.spin(forward);
    TraIzq.spin(forward);
  }
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

void apagarMotores(){
  TraIzq.stop();
  TraDer.stop();
  DelDer.stop();
  TraDer.stop();
}




int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  int velocidadBrazo = 100;
  bool permitirAdelante = true;
  while(true){

   while(Controller1.ButtonR1.pressing()){
    subirBrazo(velocidadBrazo);
   }
  
   while(Controller1.ButtonR2.pressing()){
    bajarBrazo(velocidadBrazo);
   }
  //Funcion para ir adelante 
  while(Controller1.ButtonA.pressing()){
    apagarMotores();
  }

  if(Controller1.Axis3.position()){
    permitirAdelante = true;
    funcionAdelante(permitirAdelante);

  }
   
   if(Controller1.Axis1.position()){
    permitirAdelante = false;
    funcionGiros(permitirAdelante);
  }

  if(Controller1.ButtonA.pressing()){
    DelDer.setVelocity(0,percent);
    DelIzq.setVelocity(0,percent);
    TraDer.setVelocity(0,percent);
    TraIzq.setVelocity(0, percent);
  }


   //funcion para girar
   
   Brazo1.stop();
   Brazo2.stop();

  
  

  }
}
