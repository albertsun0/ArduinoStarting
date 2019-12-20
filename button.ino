#define button 5
boolean buttonState;
#define led 9

void setup() {
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  buttonState = digitalRead(button); // 0 for pressed, 1 for unpressed
  Serial.println(buttonState);

  //turn on led if button pressed / state = 0
  if(!buttonState){
    digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(led, LOW);
  }
  
}
