#include<Wire.h>                          //Library for I2C Communication functions

void setup() {
 Serial.begin(9600);                     //Begins Serial Communication at 9600 baud rate
  Wire.begin(8);                          //Begins I2C communication with Slave Address as 1 at pin (A4,A5)
  Wire.onReceive(receiveEvent);           //Function call when Slave receives value from master
  Wire.onRequest(requestEvent);           //Function call when Master request value from Slave

}

void loop() {
  // put your main code here, to run repeatedly:

}
void receiveEvent ()                    //This Function is called when Slave receives value from master
{
  int SlaveReceived = Wire.read();                    //Used to read value received from master and store in variable SlaveReceived
}
void requestEvent()                                //This Function is called when Master wants value from slave
{
  Serial.println("Data Requested");
  byte data = random(0,2);                 
  Wire.write(data);                          // sends one byte converted POT value to master
  Serial.println("Data Sent");
  Serial.println(data);
}
void receiveEvent (int howMany)               //This Function is called when Slave receives value from master
{
   int data = Wire.read();                    //Used to read value received from master and store in variable SlaveReceived
   //Start Launch Sequence
}

