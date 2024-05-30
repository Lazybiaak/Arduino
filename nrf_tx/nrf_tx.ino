#include <SPI.h>
#include <LiquidCrystal_I2C.h>
#include <nRF24L01.h>
#include <RF24.h>
#include<SoftwareSerial.h>

RF24 radio(9, 10); // CE, CSN
LiquidCrystal_I2C lcd(0x27,20,4);
const byte address[6] = "00001";
int stage=0;
void unknown_error(){//Blinks all three led 
      digitalWrite(5,HIGH);    
      digitalWrite(6,HIGH);
      digitalWrite(7,HIGH);
      delay(500);
      digitalWrite(5,LOW);    
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      delay(100);
      digitalWrite(5,HIGH);    
      digitalWrite(6,HIGH);
      digitalWrite(7,HIGH);
      delay(500);
      digitalWrite(5,LOW);    
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      delay(100);
      Serial.println("Error");
}
void ready(){
  //ready signal
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("LAUNCH CONTROL BOARD");
  lcd.setCursor(7,2);
  lcd.print("Ready");
  Serial.println("Ready");
  delay(500);
}
void setup() {

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("LAUNCH CONTROL BOARD");

  pinMode(5,OUTPUT);
   pinMode(6,OUTPUT);
   pinMode(7,OUTPUT);
   pinMode(2,INPUT);
   pinMode(3,INPUT);
   pinMode(4,INPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_250KBPS);
  radio.stopListening();
while(digitalRead(5)==1||digitalRead(6)==1||digitalRead(7)==1){
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
  delay(100);

  switch(stage){
  case 0:
   if(digitalRead(2)==HIGH){
    const char text[] = "a";
    Serial.println(text);
    Serial.println("sent");
    radio.write(&text, sizeof(text));
    digitalWrite(5,HIGH);
   digitalWrite(6,LOW);
   digitalWrite(7,LOW);
    lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("LAUNCH CONTROL BOARD");
        lcd.setCursor(1,2);
        lcd.print("Radio Connected");
        lcd.setCursor(1,3);
        lcd.print("The rocket is armed");
    if(digitalRead(3)==HIGH){
    stage=1;
    }
    delay(100);
   }
   break;
    case 1:
  if(digitalRead(2)==HIGH && digitalRead(3)==HIGH){
    const char text[] = "b";
    Serial.println(text);
    Serial.println("sent");
    radio.write(&text, sizeof(text));
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("LAUNCH CONTROL BOARD");
        lcd.setCursor(0,2);
        lcd.print("The rocket is SAFE.");
        lcd.setCursor(0,3);
        lcd.print("Press Launch to go.");
        stage=2;
  }
  break;
  case 2:
  digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
  if (digitalRead(2)==HIGH && digitalRead(3)==HIGH && digitalRead(4)==HIGH){
    const char text[] = "c";
    Serial.println(text);
    Serial.println("sent");
    radio.write(&text, sizeof(text));
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("LAUNCH CONTROL BOARD");
        lcd.setCursor(0,2);
        lcd.print("The rocket is active");
        lcd.setCursor(0,3);
        lcd.print("Flying beyond...");\
    stage=3;
  }
  break;
  
  

    case 3:
    delay(200);
    const char text[] = "c";
    Serial.println(text);
    Serial.println("sent");
    radio.write(&text, sizeof(text));
     lcd.clear();
     lcd.setCursor(0,0);
        lcd.print("LAUNCH CONTROL BOARD");
        lcd.setCursor(2,2);
        lcd.print("Flying beyond");
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    delay(300);
    lcd.setCursor(15,2);
        lcd.print(".");
    digitalWrite(5,HIGH);
    delay(300);
    lcd.setCursor(16,2);
        lcd.print(".");
    digitalWrite(6,HIGH);
    delay(300);
    lcd.setCursor(17,2);
        lcd.print(".");
    digitalWrite(7,HIGH);
    delay(300);
  break;

  default:
  break;
  }
  delay(100);
}
