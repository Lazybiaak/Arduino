#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN

const byte add1[6] = "00001";
const byte add2[6] = "00002";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(add2);
  radio.openReadingPipe(0,add1);
  radio.setPALevel(RF24_PA_MIN);
}

void loop() {
  radio.startListening();
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
    Serial.println("received");
  delay(5000);
  char hi[32] = "hi there";
  radio.stopListening();                           //This sets the module as transmitter
  radio.write(&hi, sizeof(hi));
  Serial.println(hi);
    Serial.println("sent");
  }

}