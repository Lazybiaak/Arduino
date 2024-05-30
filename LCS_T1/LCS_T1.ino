const int Launch_Switch = 2;
const int Arm_Switch = 3;
const int Safe_Switch = 4;

const int Launch_led = 11;
const int Arm_led = 12;
const int Safe_led = 13;


void setup() {
  pinMode(Launch_led, OUTPUT);
  pinMode(Arm_led, OUTPUT);
  pinMode(Safe_led, OUTPUT);

  pinMode(Launch_Switch, INPUT);
  pinMode(Arm_Switch, INPUT);
  pinMode(Safe_Switch, INPUT);

  digitalWrite(Safe_led,LOW);
digitalWrite(Arm_led,LOW);
digitalWrite(Launch_led,LOW);
delay(1000);

}
int a=0;
void loop() {
  if(digitalRead(Launch_Switch)==1){
    delay(30);
    digitalWrite(Launch_led,HIGH);
    a=1;
    
  }else if(a==0){
    digitalWrite(Launch_led,LOW);
  }
  if(digitalRead(Arm_Switch)==1){
    digitalWrite(Arm_led,HIGH);
  }else{
    digitalWrite(Arm_led,LOW);
  }
  if(digitalRead(Safe_Switch)==1){
    digitalWrite(Safe_led,HIGH);
  }else{
    digitalWrite(Safe_led,LOW);
  }

}
