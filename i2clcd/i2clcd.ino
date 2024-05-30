#include <Arduino.h>
#include <LiquidCrystalIO.h>
#include <IoAbstractionWire.h>
#include <Wire.h>
#include <DHT.h>  // Include the DHT sensor library

#define DHT_PIN 8  // Define the pin to which the DHT sensor is connected

DHT dht(DHT_PIN, DHT11);  // Create a DHT object

LiquidCrystalI2C_RS_EN(lcd, 0x27, false)

void setup() {
    Serial.begin(115200);
    Serial.println("Starting LCD example");

    Wire.begin();

    Serial.println("Configure LCD");

    lcd.begin(16, 2);
    lcd.configureBacklightPin(3);
    lcd.backlight();

    dht.begin();  // Initialize the DHT sensor

    taskManager.scheduleFixedRate(2000, [] {
        // Read temperature and humidity from DHT sensor
        float temperature = dht.readTemperature();
        float humidity = dht.readHumidity();

        // Display temperature and humidity on the LCD
        lcd.clear();  // Clear the LCD screen
        lcd.setCursor(0, 0);
        lcd.print("Temp: ");
        lcd.print(temperature);
        lcd.print(" C");

        lcd.setCursor(0, 1);
        lcd.print("Humidity: ");
        lcd.print(humidity);
        lcd.print("%");
    });
}

void loop() {
    taskManager.runLoop();
}
