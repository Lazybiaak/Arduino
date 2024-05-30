#include <Servo.h>

Servo abc;

void setup() {
  abc.attach(5);
  pinMode(4,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a;
  a=digitalRead(4);

  if(a==

}
