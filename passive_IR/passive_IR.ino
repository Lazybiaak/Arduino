int ledPin = 7;
int pirPin = 3;

int pirValue = 0;
int pirState = LOW;

void setup()
{
Serial.begin(9600);
pinMode(ledPin, OUTPUT);
pinMode(pirPin, INPUT);
}

void loop()
{
pirValue = digitalRead(pirPin);

if (pirValue == HIGH)
{
    digitalWrite(ledPin, HIGH);
    if (pirState == LOW)
    {
    Serial.println("Hey! Motion recorded.");
    pirState = HIGH;
    }
}
else
{
digitalWrite(ledPin, LOW);

if(pirState == HIGH){
Serial.println("Hmmm....No motion now!");
pirState = LOW;
}
}
}
