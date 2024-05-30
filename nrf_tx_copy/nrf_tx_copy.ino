#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN

const byte add1[6] = "00001";
const byte add2[6] = "00002";

void setup() {
  radio.begin();
  Serial.begin(9600);
  radio.openWritingPipe(add1);
  radio.openReadingPipe(0,add2);
  radio.setPALevel(RF24_PA_MIN);
  
}

void loop() {
  radio.stopListening();
  const char text[32] = "Hello there";
  Serial.println(text);
  Serial.println("sent");
  radio.write(&text, sizeof(text));
  delay(100);

  radio.startListening();                            //This sets the module as receiver
 
  char rec[32] = "";
    radio.read(&rec, sizeof(rec));
    Serial.println(rec);
    Serial.println("received");
delay(5000);
}