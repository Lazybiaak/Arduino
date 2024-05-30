const int outputPin = 9;

void setup() {
  // Nothing to initialize in this example
}

void loop() {
  // Generate a smooth transition from 0 to 255 (8-bit resolution)
  for (int i = 0; i <= 255; ++i) {
    analogWrite(outputPin, i);
    delay(10);  // Adjust the delay as needed for your application
  }
delay(1000);
  // Generate a smooth transition from 255 back to 0
  for (int i = 255; i >= 0; --i) {
    analogWrite(outputPin, i);
    delay(10);  // Adjust the delay as needed for your application
  }

delay(1000);}