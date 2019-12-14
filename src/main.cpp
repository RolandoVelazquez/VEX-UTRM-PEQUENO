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
// DelIzq               motor         19              
// Brazo1               motor         9               
// Brazo2               motor         2               
// Controller1          controller                    
// Garra                motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
using namespace vex;

/*
  (int) velocidad la velocida ========> valores validos = 1 o 5
  Valor inicial de velocidad = 1;
  Velocidad se usa para dividir el valor resultante de la operación de la
  posicion axis

  ejemplo = velocidad resultante  = 100  entonces 100/1 o 100 /5

  ======================================================================================
  Con la siguiente función se asigna la velocidad que tendrá cada motor
  **todo se controla con el axis 4**
*/

//Este será el modo autonomo
void autonomo(){
  while(true){

  } 
}

void axisIzquierdo(int velocidad) {
  DelIzq.setVelocity(
      (Controller1.Axis3.position() + Controller1.Axis4.position()) / velocidad,
      percent);
  DelDer.setVelocity(
      (Controller1.Axis3.position() - Controller1.Axis4.position()) / velocidad,
      percent);
  TraIzq.setVelocity(
      (Controller1.Axis3.position() + Controller1.Axis4.position()) / velocidad,
      percent);
  TraDer.setVelocity(
      (Controller1.Axis3.position() - Controller1.Axis4.position()) / velocidad,
      percent);
}

/*
  (int) velocidad la velocida ========> valores validos = 1 o 5
  Valor inicial de velocidad = 1;
  Velocidad se usa para dividir el valor resultante de la operación de la
  posicion axis

  ejemplo = velocidad resultante  = 100  entonces 100/1 o 100 /5

  ======================================================================================
  Con la siguiente función se asigna la velocidad que tendrá cada motor
  **todo se controla con el axis2**
*/
void axisDerecho(int velocidad) {
  Brazo1.setVelocity(Controller1.Axis2.position() / velocidad, percent);
  Brazo2.setVelocity(Controller1.Axis2.position() / velocidad, percent);
}

/*

Con la siguiente funcion se controla el motor del puerto 5
motor puerto 5 = Motor de Garra

Esta función se ha creado para Cerrar la Garra asignandole -100
-100 por que se necesita velocidad
*/
void cerrarGarra() {
  Garra.spin(forward);
  Garra.setVelocity(-100, percent);
  waitUntil(!Controller1.ButtonL1.pressing());
  Garra.stop();
}

/*

Con la siguiente funcion se controla el motor del puerto 5
motor puerto 5 = Motor de Garra

Esta función se ha creado para Abrir la Garra asignandole 100
100 por que se necesita velocidad
*/
void abrirGarra() {

  Garra.spin(forward);
  Garra.setVelocity(100, percent);
  waitUntil(!Controller1.ButtonR1.pressing());
  Garra.stop();
}

int main() {

  vexcodeInit();

  /*
    (bool)

    Ciclo para que nunca se detenga el robot
  */
  while (true) {
    // Usado para que el robot avance rapido o lento
    int velocidad = 1;
    // Condición para para entrar a modo Robot Lento
    if (Controller1.ButtonL2.pressing()) {
      velocidad = 5;
    }
    // Condicion para salir del moto Robot Lento
    if (!Controller1.ButtonL2.pressing()) {
      velocidad = 1;
    }

    /*
      (int) velocidad ====> Para el modo lento del robot

      Funciones para Controlar a la direccion en la que irá el robot
    */
    axisIzquierdo(velocidad);
    axisDerecho(velocidad);

    /*
      Usados para capturar el evento de presión de cada botón
    */
    Controller1.ButtonL1.pressed(cerrarGarra);
    Controller1.ButtonR1.pressed(abrirGarra);

    /*
      Usado para detener los motores asignados a la garra
    */
    Garra.setStopping(hold);

    /*
      Lo siguiente es usado para asigar la direccion que tendrá cada motor
    */
    Brazo1.spin(forward);
    Brazo2.spin(forward);
    DelDer.spin(forward);
    DelIzq.spin(forward);
    TraDer.spin(forward);
    TraIzq.spin(forward);

    wait(25, msec);
  }
}
