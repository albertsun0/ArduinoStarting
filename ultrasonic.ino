void setup() {
  // put your setup code here, to run once:
  Serial.begin(1200);
  pinMode(3,INPUT);
  pinMode(8,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(8,LOW);
   delayMicroseconds(20);
  digitalWrite(8,HIGH);
 
   Serial.println(pulseIn(3,HIGH)/29.387/2);
  
}
