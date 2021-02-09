#define button 10

void setup() {
  for(int i =2; i<7; i++){ //led pins
    pinMode(i, OUTPUT);
  }
  
  pinMode(button, INPUT_PULLUP); //button pin
  
  Serial.begin(9600); //start "console"
  Serial.print("Game Start");
}

int currentled = 2;
int prevled = 6;
boolean buttonState;

unsigned long previousMillis = 0;
long interval = 1000;

void loop() {
  unsigned long currentMillis = millis();
  
  buttonState = digitalRead(button);
  Serial.println(buttonState);
  
  digitalWrite(prevled, LOW);
  digitalWrite(currentled, HIGH);

  if(!buttonState){
    if(currentled != 4){
      wrong();
    }
    else{
      correct();
    }
    currentled = 1; 
    prevled = 6;
  }
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    prevled = currentled;
    currentled++;
    if(currentled > 6){
      currentled = 2;
    }
  }
}

void wrong(){
  for(int i =2; i<7; i++){ //led pins
    digitalWrite(i, HIGH);
  }
  delay(1000);
  for(int i =2; i<7; i++){ //led pins
    digitalWrite(i, LOW);
  }
}

void correct(){
  for(int i = 0; i<3; i++){
    digitalWrite(4, HIGH);
    delay(200);
    digitalWrite(4, LOW);
    delay(200);
  }
  interval = interval/1.5;
  if(interval < 50){
    interval = 50;
  }
}
