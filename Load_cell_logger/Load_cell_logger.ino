/*
  SD card Load Cell datalogger

  This Program shows how to log data from load sensor
  to an SD card using the HX711 and SD library.

  The circuit:
   SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4 (for MKRZero SD: SDCARD_SS_PIN)

  HX711 circuit wiring
  LOADCELL_DOUT_PIN = 2;
  LOADCELL_SCK_PIN = 3;
*/

#include <HX711.h>
// #include <SPI.h>
// #include <SD.h>

const int LOADCELL_DOUT_PIN = 13;
const int LOADCELL_SCK_PIN = 14;
// const int chipSelect = 4;

HX711 scale;

void setup() {
  Serial.begin(38400);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  // Serial.print("Initializing SD card...");
  // // see if the card is present and can be initialized:
  // if (!SD.begin(chipSelect)) {
  //   Serial.println("Card failed, or not present");
  //   // don't do anything more:
  //   while (1);
  // }
  // Serial.println("card initialized.");

  Serial.println("Initializing the scale");
  // Initialize library with data output pin, clock input pin and gain factor.
  // Channel selection is made by passing the appropriate gain:
  // - With a gain factor of 64 or 128, channel A is selected
  // - With a gain factor of 32, channel B is selected
  // By omitting the gain factor parameter, the library
  // default "128" (Channel A) is used here.
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

  Serial.println("Before setting up the scale:");
  Serial.print("read: \t\t");
  Serial.println(scale.read());			// print a raw reading from the ADC

  Serial.print("read average: \t\t");
  Serial.println(scale.read_average(20));  	// print the average of 20 readings from the ADC

  Serial.print("get value: \t\t");
  Serial.println(scale.get_value(5));		// print the average of 5 readings from the ADC minus the tare weight (not set yet)

  Serial.print("get units: \t\t");
  Serial.println(scale.get_units(5), 1);	// print the average of 5 readings from the ADC minus tare weight (not set) divided
						// by the SCALE parameter (not set yet)

  scale.set_scale(8.7512);                      // this value is obtained by calibrating the scale with known weights; see the README for details
  scale.tare();				        // reset the scale to 0

  Serial.println("After setting up the scale:");

  Serial.print("read: \t\t");
  Serial.println(scale.read());                 // print a raw reading from the ADC

  Serial.print("read average: \t\t");
  Serial.println(scale.read_average(20));       // print the average of 20 readings from the ADC

  Serial.print("get value: \t\t");
  Serial.println(scale.get_value(5));		// print the average of 5 readings from the ADC minus the tare weight, set with tare()

  Serial.print("get units: \t\t");
  Serial.println(scale.get_units(5), 1);        // print the average of 5 readings from the ADC minus tare weight, divided
						// by the SCALE parameter set with set_scale

  Serial.println("Readings:");
  // File dataFile = SD.open("datalog.txt", FILE_WRITE);
  //   dataFile.print(millis());
  //   dataFile.print("\t");
  //   dataFile.println("data Insertion Started\n\n");
  // dataFile.close();
}
String data= "";

void loop() {

  // make a string for assembling the data to log:
  
  
  // File dataFile = SD.open("datalog.txt", FILE_WRITE);
  while(1){
  // if the file is available, write to it:
  if (1) {
    data=scale.get_units();
    // dataFile.print(millis());
    // dataFile.print("\t");
    // dataFile.println(data);
   
    // print to the serial port too:
    Serial.println(data);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
    break;
  } 
  // dataFile.close();
  }
  // scale.power_down();			        // put the ADC in sleep mode
  //delay(10);
  // scale.power_up();
  
}