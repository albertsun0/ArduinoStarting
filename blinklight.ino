void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT); //set pin 2 to be output pin
  
  Serial.begin(9600);
  Serial.print("work"); //log
}

void loop() {
  // repeat forever
  digitalWrite(2,HIGH); //high is on
  delay(500); //ms
  digitalWrite(2,LOW);
  delay(500); 
Serial.print("work");
}
