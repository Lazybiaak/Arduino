const int IN1=6;
const int IN2=7;
const int ENA=10;

const int IN3=8;
const int IN4=9;
const int ENB=11;


char bt='S';
void setup() {
     pinMode(IN1, OUTPUT);
     pinMode(IN2, OUTPUT);
     pinMode(ENA, OUTPUT);

     pinMode(IN4, OUTPUT);
     pinMode(IN3, OUTPUT);
     pinMode(ENB, OUTPUT);
}



void Motor1_Forward(int Speed)
{
     digitalWrite(IN1,HIGH);
     digitalWrite(IN2,LOW);
     analogWrite(ENA,  Speed);
}

void Motor1_Backward(int Speed)
{
     digitalWrite(IN1,LOW);
     digitalWrite(IN2,HIGH);
     analogWrite(ENA,Speed);
}
void Motor1_Brake()
{
     digitalWrite(IN1,LOW);
     digitalWrite(IN2,LOW);
}
void Motor2_Forward(int Speed)
{
     digitalWrite(IN3,HIGH);
     digitalWrite(IN4,LOW);
     analogWrite(ENB,Speed);
}

void Motor2_Backward(int Speed)
{
     digitalWrite(IN3,LOW);
     digitalWrite(IN4,HIGH);
     analogWrite(ENB,Speed);
}
void Motor2_Brake()
{
     digitalWrite(IN3,LOW);
     digitalWrite(IN4,LOW);
}
void stop()
{
  Motor1_Brake();
  Motor2_Brake();
}
void forward()
{
 Motor1_Forward(255);
 Motor2_Forward(255);
}
void backward()
{
 Motor1_Backward(255);
 Motor2_Backward(255);
}
void forwardleft()
{
  stop();
  Motor2_Forward(255);
}
void forwardright()
{
  stop();
  Motor1_Forward(255);
}
void backleft()
{
  stop();
  Motor2_Backward(255);
}
void backright()
{
  stop();
 Motor1_Backward(255);
}
void left()
{
  Motor2_Forward(255);
  Motor1_Backward(255);
}
void right()
{
  Motor1_Forward(255);
  Motor2_Backward(255);
}
void loop() {
  bt=Serial.read();

if(bt=='F')
{
 forward();
}
if(bt=='B')
{
 backward();
 } 
if(bt=='L')
{
 left(); 
 }
if(bt=='R')
{
 right(); 
 }
if(bt=='G')
{
 forwardleft();
 }
if(bt=='I')
{
 forwardright();
 }
if(bt=='H')
{
 backleft();
 } 
if(bt=='J')
{
 backright();
 } 
if(bt=='S')
{
 stop();
}
}
