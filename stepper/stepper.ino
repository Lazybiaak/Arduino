int p1 = 2; // IN1
int p2 = 3; // IN2
int p3 = 4; // IN3
int p4 = 5; // IN4

void setup() {
  // Set the motor control pins as outputs
  pinMode(p1, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(p3, OUTPUT);
  pinMode(p4, OUTPUT);

  // Initialize the motor in the stopped state
  stopMotor();
}

void loop() {
  // Rotate the motor clockwise
  rotateClockwise(100, 200); // You can adjust the delay values to change the speed and steps
  delay(1000); // Pause for 1 second
  
  // Rotate the motor counterclockwise
  rotateCounterClockwise(100, 200);
  delay(1000); // Pause for 1 second
}

void stopMotor() {
  digitalWrite(p1, LOW);
  digitalWrite(p2, LOW);
  digitalWrite(p3, LOW);
  digitalWrite(p4, LOW);
}

void rotateClockwise(int speed, int steps) {
  for (int i = 0; i < steps; i++) {
    digitalWrite(p1, HIGH);
    digitalWrite(p2, LOW);
    digitalWrite(p3, HIGH);
    digitalWrite(p4, LOW);
    delayMicroseconds(speed);
    
    digitalWrite(p1, LOW);
    digitalWrite(p2, HIGH);
    digitalWrite(p3, HIGH);
    digitalWrite(p4, LOW);
    delayMicroseconds(speed);
    
    digitalWrite(p1, LOW);
    digitalWrite(p2, HIGH);
    digitalWrite(p3, LOW);
    digitalWrite(p4, HIGH);
    delayMicroseconds(speed);
    
    digitalWrite(p1, HIGH);
    digitalWrite(p2, LOW);
    digitalWrite(p3, LOW);
    digitalWrite(p4, HIGH);
    delayMicroseconds(speed);
  }
}

void rotateCounterClockwise(int speed, int steps) {
  for (int i = 0; i < steps; i++) {
    digitalWrite(p1, HIGH);
    digitalWrite(p2, LOW);
    digitalWrite(p3, LOW);
    digitalWrite(p4, HIGH);
    delayMicroseconds(speed);
    
    digitalWrite(p1, LOW);
    digitalWrite(p2, HIGH);
    digitalWrite(p3, LOW);
    digitalWrite(p4, HIGH);
    delayMicroseconds(speed);
    
    digitalWrite(p1, LOW);
    digitalWrite(p2, HIGH);
    digitalWrite(p3, HIGH);
    digitalWrite(p4, LOW);
    delayMicroseconds(speed);
    
    digitalWrite(p1, HIGH);
    digitalWrite(p2, LOW);
    digitalWrite(p3, HIGH);
    digitalWrite(p4, LOW);
    delayMicroseconds(speed);
  }
}
