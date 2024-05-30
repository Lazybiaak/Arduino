int irsensor = 12;
int buzzer = 7;
void setup()
{
  Serial.begin(9600);
  pinMode(irsensor,INPUT);
  pinMode(buzzer, OUTPUT);
  
}

void loop()
{
  int value = digitalRead(irsensor);
  Serial.println("");
  Serial.print("Sensor Value = ");
  Serial.print(value);
  if (value == 0)
  {
    digitalWrite(buzzer, HIGH);
  }
  else
  {
    digitalWrite(buzzer, LOW);
  }
  delay(50);
}


  
  
