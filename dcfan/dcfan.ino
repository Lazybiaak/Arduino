const int fanControlPin = 9; // Digital pin connected to the gate of IRFZ44

void setup() {
  pinMode(fanControlPin, OUTPUT);
}

void loop() {
  analogWrite(fanControlPin, 25); // Adjust PWM value (0-255) for fan speed control
  delay(5000); // Run the fan at a certain speed for 5 seconds

  analogWrite(fanControlPin, 0); // Turn off the fan
  delay(10000); // Wait for 5 seconds before repeating
}
