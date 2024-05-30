#include <SPI.h>
#include <RF24.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

RF24 radio(9, 10); // CE, CSN

const byte add1[6] = "00001";
const byte add2[6] = "00002";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(add2);
  radio.openReadingPipe(0,add1);
  radio.setPALevel(RF24_PA_MIN);

  lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on
  
  // Print a message on both lines of the LCD.
  lcd.setCursor(2,0);   //Set cursor to character 2 on line 0
  lcd.print("Receiver Display");
}

void loop() {
  char text[10];
  radio.startListening();
  if (radio.available()) {
    radio.read(&text, sizeof(text));
    Serial.println(text);
    lcd.setCursor(2,1);   //Set cursor to character 2 on line 0
    lcd.print(text);
    lcd.setCursor(2,2);   //Set cursor to character 2 on line 0
    lcd.print("received");
    Serial.println("received");
    if(strcmp(text,"safe")==0){
      radio.stopListening();                           //This sets the module as transmitter

      char hello[10]="hello";
      char hi[10]="hi";

    if(rand()%2==0){
      delay(100);
      radio.write(&hi, sizeof(hi));
      delay(100);
      radio.write(&hi, sizeof(hi));
      Serial.println(hi);
      Serial.println("sent");
    }else{
      delay(100);
      radio.write(&hello, sizeof(hello));
      delay(100);
      radio.write(&hello, sizeof(hello));
      Serial.println(hello);
      Serial.println("sent");
    }
    }else if(text==2){
      radio.stopListening();                           //This sets the module as transmitter
      int hi=1;
      radio.write(&hi, sizeof(hi));
      Serial.println(hi);
      Serial.println("sent");
    }else if(text==3){
      radio.stopListening();                           //This sets the module as transmitter
      int hi=1;
      radio.write(&hi, sizeof(hi));
      Serial.println(hi);
      Serial.println("sent");
    }else{
      
    }
    
  delay(100);
  }

}