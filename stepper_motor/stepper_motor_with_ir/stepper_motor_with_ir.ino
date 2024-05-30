/*
  Stepper Motor Demonstration 1
  Stepper-Demo1.ino
  Demonstrates 28BYJ-48 Unipolar Stepper with ULN2003 Driver
  Uses Arduino Stepper Library

  DroneBot Workshop 2018
  https://dronebotworkshop.com
*/

//Include the Arduino Stepper Library
#include <Stepper.h>

// Define Constants

// Number of steps per internal motor revolution 
const float STEPS_PER_REV = 32; 

//  Amount of Gear Reduction
const float GEAR_RED = 64;

// Number of steps per geared output rotation
const float STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RED;

// Define Variables

// Number of Steps Required
int StepsRequired;

// Create Instance of Stepper Class
// Specify Pins used for motor coils
// The pins used are 8,9,10,11 
// Connected to ULN2003 Motor Driver In1, In2, In3, In4 
// Pins entered in sequence 1-3-2-4 for proper step sequencing

Stepper steppermotor(STEPS_PER_REV, 8, 10, 9, 11);

void setup()
{
//(Stepper Library sets pins as outputs)
pinMode(3,INPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
}

void loop()
{
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  if (digitalRead(3)== LOW)
  {
    digitalWrite(6,LOW);
   // Rotate CW
  StepsRequired  =  STEPS_PER_OUT_REV * 0.1; 
  steppermotor.setSpeed(1000);   
  steppermotor.step(StepsRequired);
  delay(50);

  // Rotate CCW
  StepsRequired  =  - STEPS_PER_OUT_REV / 10;   
  steppermotor.setSpeed(1000);  
  steppermotor.step(StepsRequired);
  delay(50);
  }
  else 
  {
    digitalWrite(5,LOW);
    delay(10);
  }

}
