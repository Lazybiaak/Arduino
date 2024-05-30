#include <LiquidCrystal.h>

// Create a LiquidCrystal object
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Initialize the LCD
  lcd.begin(16, 2);
}

void loop() {
  // Display text on the LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Hello, World!");
  delay(2000);
}
