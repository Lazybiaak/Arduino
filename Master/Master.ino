#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <wire.h>

LiquidCrystal_I2C lcd(0x27,20,4);

//connection of pins

const int Arm_Switch = 2;
const int Safe_Switch = 3;
const int Launch_Switch = 4;

const int buzzer = 8;

const int Arm_led = 5;
const int Safe_led = 6;
const int Launch_led = 7;

const int Radio_CE=9;
const int Radio_CSN=10;
// Radio_MOSI=11
// Radio_MISO=12
// Radio_SCK=13
RF24 radio(Radio_CE, Radio_CSN); // CE, CSN

const byte add1[6] = "00001";
const byte add2[6] = "00002";

int data = 0;
int stage=0; // stage of process

void unknown_error(){//Blinks all three led 
      digitalWrite(Safe_led,HIGH);    
      digitalWrite(Arm_led,HIGH);
      digitalWrite(Launch_led,HIGH);
      delay(500);
      digitalWrite(Safe_led,LOW);    
      digitalWrite(Arm_led,LOW);
      digitalWrite(Launch_led,LOW);
      delay(100);
      digitalWrite(Safe_led,HIGH);    
      digitalWrite(Arm_led,HIGH);
      digitalWrite(Launch_led,HIGH);
      delay(500);
      digitalWrite(Safe_led,LOW);    
      digitalWrite(Arm_led,LOW);
      digitalWrite(Launch_led,LOW);
      delay(100);
}
void blink(int a,int b,int c){
  int i;
  for(i=0;i<b;i++){
    digitalWrite(a,HIGH);
    delay(c);
    digitalWrite(a,LOW);
    delay(c/2);
  }
}
void safebuzzer(){
  tone(buzzer,250,100);
  delay(50);
  tone(buzzer,300,500);

}
void armbuzzer(){
   tone(buzzer,300,100);
  delay(50);
  tone(buzzer,350,500);
}
void launchbuzzer(){
   tone(buzzer,350,100);
  delay(50);
  tone(buzzer,350,100);
  delay(50);
  tone(buzzer,400,500);
}
void errorbuzzer(){
   tone(buzzer,350,100);
  delay(50);
  tone(buzzer,350,100);
  delay(50);
  tone(buzzer,400,100);
}
void ready(){
  //ready signal
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("LAUNCH CONTROL BOARD");
  lcd.setCursor(7,2);
  lcd.print("READY");
  digitalWrite(Safe_led,HIGH);
  delay(100);
  digitalWrite(Safe_led,LOW);
  delay(50);
  digitalWrite(Safe_led,HIGH);
  delay(100);
  digitalWrite(Safe_led,LOW);
  delay(50);
  digitalWrite(Safe_led,HIGH);
  delay(100);
  digitalWrite(Safe_led,LOW);
}
void setup() {
  //lcd setup
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("LAUNCH CONTROL BOARD");

  //comm antenna setup
  radio.begin();
  Wire.begin();
  Serial.begin(9600);
  radio.openWritingPipe(add1);
  radio.openReadingPipe(0,add2);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_250KBPS);

  //led setup
  pinMode(Launch_led, OUTPUT);
  pinMode(Arm_led, OUTPUT);
  pinMode(Safe_led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(Launch_Switch, INPUT);
  pinMode(Arm_Switch, INPUT);
  pinMode(Safe_Switch, INPUT);


digitalWrite(Arm_led,LOW);
digitalWrite(Launch_led,LOW);
delay(1000);
//checking if all switch are in off state
  while(digitalRead(Safe_Switch)==1||digitalRead(Arm_Switch)==1||digitalRead(Launch_Switch)==1){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("LAUNCH CONTROL BOARD");
    lcd.setCursor(7,2);
    lcd.print("ERROR");
    lcd.setCursor(0,3);
    lcd.print("Turn off all switch.");
    unknown_error();
  }
  delay(1000);
  
ready();

}
void loop() {
  byte ret_value=9; //expected return value from receiver is 0 and 1 so initializing ret value to 9
  
  switch(stage){ 
    case 0: //safe stage
    if(digitalRead(Safe_Switch)==1){
      digitalWrite(Safe_led,HIGH);
      
      radio.stopListening();
      char ask[32] = "safe";
      Serial.println(ask);
      Serial.println("sent");
       radio.write(&ask, sizeof(ask)); //ask for rocket if safe 
       delay(100);
      digitalWrite(Safe_led,LOW);
      delay(100);
      radio.startListening();                            //This sets the module as receiver
      int safe_ack;
      radio.read(&safe_ack, sizeof(safe_ack)); //receiving reply from rocket
      Serial.println(safe_ack);
      Serial.println("received");
      ret_value=safe_ack;
      
      if(ret_value==1){     // safe xa hai system
       digitalWrite(Safe_led,HIGH);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("LAUNCH CONTROL BOARD");
        lcd.setCursor(1,2);
        lcd.print("Check Complete.");
        noTone(buzzer);
        lcd.setCursor(1,3);
        lcd.print("We are safe to go");
        safebuzzer();
        stage=1;   
      }else if(ret_value==0){ // rocket safe xaina
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("LAUNCH CONTROL BOARD");
        lcd.setCursor(1,2);
        lcd.print("Error Detected.");
        lcd.setCursor(0,3);
        lcd.print("Check and try again.");
        delay(5000);
        Serial.println("Error seq completed");
        errorbuzzer();
        stage=0; 
      }else{unknown_error();}//k vayo tha xaina may be garbage value return aayo
    }
    break;
    
    case 1: //arm stage
    delay(200);
    digitalWrite(Arm_led,HIGH);
    Serial.println("Case arm Reached");
    delay(100);
    digitalWrite(Arm_led,LOW);
    while(digitalRead(Arm_Switch)!=1){}
       if(digitalRead(Arm_Switch)==1){
      digitalWrite(Arm_led,HIGH);
      radio.stopListening();
      char ask[32] = "arm";
      Serial.println(ask);
      Serial.println("sent");
       radio.write(&ask, sizeof(ask));
       delay(100);
      digitalWrite(Arm_led,LOW);
      delay(100);
      int safe_ack;
      radio.startListening();                            //This sets the module as receiver
    radio.read(&safe_ack, sizeof(safe_ack));
    Serial.println(safe_ack);
    Serial.println("received");
      ret_value=safe_ack;
      if(ret_value==1){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("LAUNCH CONTROL BOARD");
        lcd.setCursor(0,2);
        lcd.print("The rocket is armed.");
        lcd.setCursor(0,3);
        lcd.print("Press Launch to go.");
       digitalWrite(Arm_led,HIGH);
       armbuzzer();
       stage=2;   
      }else if(ret_value==0){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("LAUNCH CONTROL BOARD");
        lcd.setCursor(1,2);
        lcd.print("Arm Error Detected.");
        lcd.setCursor(0,3);
        lcd.print("Check and try again.");
        errorbuzzer();
        stage=1;
        Serial.println("Error seq completed");
      }else{break;}
    }
    break;

    case 2:
    int launch=1;
     delay(200);
    digitalWrite(Launch_led,HIGH);
    Serial.println("Case Launch Reached");
    delay(100);
    digitalWrite(Launch_led,LOW);
    while(digitalRead(Launch_Switch)!=1){}
       if(digitalRead(Launch_Switch)==1){
      digitalWrite(Launch_led,HIGH);
      radio.stopListening();
      char ask[32] = "launch";
      Serial.println(ask);
      Serial.println("sent");                       // stop transmitting      
      delay(100);  
       radio.write(&ask, sizeof(ask));
       delay(100);
      //mosfet bata maal jalaune code ...... 
      digitalWrite(Launch_led,LOW);
      delay(1000);
      lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("LAUNCH CONTROL BOARD");
        lcd.setCursor(0,2);
        lcd.print("The rocket is active");
        lcd.setCursor(0,3);
        lcd.print("Flying beyond...");
       digitalWrite(Arm_led,HIGH);
      digitalWrite(Launch_led,HIGH);
      launchbuzzer();
      delay(10000);
      stage=3;
    }else{break;}
    break;

    case 3:
     delay(200);
     lcd.clear();
     lcd.setCursor(0,0);
      
        lcd.print("LAUNCH CONTROL BOARD");
        lcd.setCursor(2,2);
        lcd.print("Flying beyond");
    digitalWrite(Safe_led,LOW);
    digitalWrite(Arm_led,LOW);
    digitalWrite(Launch_led,LOW);
    delay(300);
    lcd.setCursor(15,2);
        lcd.print(".");
    digitalWrite(Safe_led,HIGH);
    delay(300);
    lcd.setCursor(16,2);
        lcd.print(".");
    digitalWrite(Arm_led,HIGH);
    delay(300);
    lcd.setCursor(17,2);
        lcd.print(".");
    digitalWrite(Launch_led,HIGH);
    delay(300);
    break;

    default:
    unknown_error();
    break;
  }
}