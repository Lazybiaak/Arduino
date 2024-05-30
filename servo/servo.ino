#include<Servo.h>
Servo motor1;
int i;
void setup() {
  motor1.attach(9);
  motor1.write(0);

}

void loop() {
 for(i=90;i<180;i++){
  motor1.write(i);
  delay(100);
  
 }

}
