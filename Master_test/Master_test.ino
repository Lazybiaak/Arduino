#include<Wire.h>      //Library for I2C Communication functions
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
void setup() {
  Serial.begin(9600); //Begins Serial Communication at 9600 baud rate
  Wire.begin();      //Begins I2C communication at pin (A4,A5)

  lcd.init();
  lcd.backlight();
  
  lcd.clear();
  lcd.setCursor(0,0);
      
        lcd.print("LAUNCH CONTROL BOARD");
}

void loop() {
  Wire.requestFrom(8,2);    // request 2 byte from slave arduino ()
  Serial.println("data requested");
  byte a = Wire.read();             // receive a byte from the slave arduino and store in MasterReceive
  Serial.println(a);
  lcd.setCursor(0,0);
      
        lcd.print("LAUNCH CONTROL BOARD");
        lcd.setCursor(2,2);
        lcd.print("Data Received: ");
        lcd.setCursor(16,2);
        lcd.print(a);
  delay(1000);

}
