#include <DHT.h>

// Define the type of DHT sensors (DHT11 in this case)
#define DHTPIN1 8    // Pin for the first DHT sensor
//#define DHTPIN2 9    // Pin for the second DHT sensor
#define DHTTYPE DHT11 // Change this to DHT22 or DHT21 if you're using a different sensor
const int light = 9;
const int bulb =13;

// Initialize the DHT sensors
DHT dht1(DHTPIN1, DHTTYPE);
//DHT dht2(DHTPIN2, DHTTYPE);

void setup() {
  pinMode(light, OUTPUT);
  digitalWrite(light,LOW);
  pinMode(bulb, OUTPUT);
  digitalWrite(bulb,HIGH);

  Serial.begin(9600);
  // Serial.println("DHT11 Sensor Test");

  dht1.begin();
  //dht2.begin();
}

void loop() {
  // Wait a few seconds between measurements
  delay(100);

  // Read data from the first DHT sensor
  //float humidity1 = dht1.readHumidity();
  float temperature1 = dht1.readTemperature();

  // Read data from the second DHT sensor
  //float humidity2 = dht2.readHumidity();
 // float temperature2 = dht2.readTemperature();

  // Check if any reads failed and exit early (to try again).
  

Serial.println(String(temperature1));

}
