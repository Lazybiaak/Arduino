#include<Servo.h>
Servo motor;
int p=0;
int angle=30;
void setup() {
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  
  motor.attach(9);
  motor.write(0);
  digitalWrite(5,LOW);
  for(p=0;p<180;p++){
  motor.write(p);
delay(5);
}
digitalWrite(5,HIGH);
digitalWrite(6,LOW);
for(p=180;p>0;p--){
  motor.write(p);
delay(5);
}
digitalWrite(6,HIGH);

}

void loop() {
  if (digitalRead(3)== LOW)
  {
    digitalWrite(6,LOW);
for(p=0;p<angle;p++){
  motor.write(p);
  delay(5);
}
for(p=angle;p>0;p--){
  motor.write(p);
  delay(5);
}
  }
  else{
   digitalWrite(5,LOW); 
   delay(10);
  }
}
