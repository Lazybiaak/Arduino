#include <SoftwareSerial.h>
SoftwareSerial BTserial(2, 3);
const int IN1=6;
const int IN2=7;
const int ENA=10;

const int IN3=8;
const int IN4=9;
const int ENB=11;

void setup() {
    Serial.begin(9600);
    BTserial.begin(9600);
    
     pinMode(IN1, OUTPUT);
     pinMode(IN2, OUTPUT);
     pinMode(ENA, OUTPUT);

     pinMode(IN4, OUTPUT);
     pinMode(IN3, OUTPUT);
     pinMode(ENB, OUTPUT);
}
void loop() {
  char bt='F';

  if(bt=='F'){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(ENA,HIGH);
}
if(bt=='S'){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(ENA,HIGH);
}
}
