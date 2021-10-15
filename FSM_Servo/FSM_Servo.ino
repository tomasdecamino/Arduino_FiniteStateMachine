//***** Tomas de Camino Beck
//***** tomasdecamino.com
//micro Servo on pin 6, and button on pin 12


/**** MAIN CODE ***/

#include <Servo.h>
#include "StateMachine.h"

TStateMachine StateMachine(2);
int state=0;
boolean button = false;
Servo myservo;

void setup()
{

  myservo.attach(6);
  myservo.write(0);
  
  pinMode(12,INPUT_PULLUP);
  
  StateMachine.add(0, &in); //in state 0 if button execute angle 0
  StateMachine.add(1, &out);//in state 1 if button execute angle 180
}

void loop()
{
  button = digitalRead(12);
  StateMachine.execute();
}


/**** FUNCTIONS ***/

// state 0
uint8_t in() {
  if(button)
    return 1;
  else{
    myservo.write(0);
    return 0;
  }
}

// state 1
uint8_t out() {
  if(button)
    return 0;
  else{
    myservo.write(180);
    return 1;
  }
}
