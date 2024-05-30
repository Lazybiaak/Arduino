int RGBLED_RedPin = 9;
int RGBLED_GreenPin = 10;
int RGBLED_BluePin = 11; 
int Previous_PWMValue_RedPin = 0;
int Threshold_PWMValue_RedPin = 0;
int Previous_PWMValue_GreenPin = 0;
int Threshold_PWMValue_GreenPin = 0;
int Previous_PWMValue_BluePin = 0;
int Threshold_PWMValue_BluePin = 0;
 
void setup() 
{ Serial.begin(9600); // initialize serial communications at 9600 bps
  pinMode(RGBLED_RedPin, OUTPUT);
 pinMode(RGBLED_GreenPin, OUTPUT);
 pinMode(RGBLED_BluePin, OUTPUT);
}
 
void loop() 
{  int Pot_RedPin = analogRead(A0);
 int PWMValue_RedPin = Pot_RedPin/4;
 int Pot_GreenPin = analogRead(A1);
 int PWMValue_GreenPin = Pot_GreenPin/4;
 int Pot_BluePin = analogRead(A2);
 int PWMValue_BluePin = Pot_BluePin/4;
 
 //Use this code for RGB LED COMMON CATHODE and comment the code for COMMON ANODE
 analogWrite(RGBLED_RedPin, PWMValue_RedPin);
 analogWrite(RGBLED_GreenPin, PWMValue_GreenPin);
 analogWrite(RGBLED_BluePin, PWMValue_BluePin);
 
 //Use this code for RGB LED COMMON ANODE and comment the code for COMMON CATHODE
 /*
 analogWrite(RGBLED_RedPin, 255-PWMValue_RedPin);
 analogWrite(RGBLED_GreenPin, 255-PWMValue_GreenPin);
 analogWrite(RGBLED_BluePin, 255-PWMValue_BluePin);
 */
 
 //This section is for serial printing the RGB decimal values. 
 //Sometimes you get unstable output due to jumper wires not properly connected, poor quality breadboard, or poor quality potentiometers.
 Threshold_PWMValue_RedPin = abs(Pot_RedPin - Previous_PWMValue_RedPin);
 Threshold_PWMValue_GreenPin = abs(Pot_GreenPin - Previous_PWMValue_GreenPin);
 Threshold_PWMValue_BluePin = abs(Pot_BluePin - Previous_PWMValue_BluePin);
 if (Threshold_PWMValue_RedPin >= 10 || Threshold_PWMValue_GreenPin >= 10 || Threshold_PWMValue_BluePin >= 10)
 
 Serial.print("RGB (");
 Serial.print(PWMValue_RedPin);
 Serial.print(", ");
 Serial.print(PWMValue_GreenPin);
 Serial.print(", ");
 Serial.print(PWMValue_BluePin);
 Serial.println(") ");
 Previous_PWMValue_RedPin = Pot_RedPin;
 Previous_PWMValue_GreenPin = Pot_GreenPin;
 Previous_PWMValue_BluePin = Pot_BluePin;
 //This section is for serial printing the RGB decimal values. 
 //Sometimes you get unstable output due to jumper wires not properly connected, poor quality breadboard, or poor quality potentiometers.
 
 delay(2);
}
