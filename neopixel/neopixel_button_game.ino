//known issues
//button sometimes doesnt work on lower levels, logic problem
//after 10 wins, the delay value goes negative, which does not work

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN 3
#define NUMPIXELS 16

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 100;

//for press thing
#define button 5
boolean buttonState;

//for game
int currentval; //where you are at
int target; //target
int gamestate = 4; //idk if this is nessasary, but for game logic. 1 = playing, 2 = win, 3 = loss, 4 = reset game

void setup() {
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);
  pixels.setBrightness(20);
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  
  if(gamestate == 4){
    currentval = 0;
    target = random(1,NUMPIXELS-1);
    gamestate = 1;
  }
  
  if(gamestate == 1){  
    buttonState = digitalRead(button); // 0 for pressed, 1 for unpressed
    for (int i = 0; i < NUMPIXELS; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
       }
       pixels.setPixelColor(target, pixels.Color(255, 0, 0));
       pixels.setPixelColor(currentval, pixels.Color(0, 255, 0));
       pixels.show(); 
       currentval++;
       if(currentval > NUMPIXELS){
        currentval = 0;
      }
    if (!buttonState) {
      if (currentval-1 == target){   //not sure about this, may have something to do with when its updating
        gamestate = 2; //win
      }
      else{
        gamestate = 3; //loss
      }
    }
   delay(delayval);
       
   
  }
  
  if(gamestate == 2){  //win
    currentval--;
    delay(500);
    for(int a = 0; a<3; a++){ //blink green 3 times
      for (int i = 0; i < NUMPIXELS; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 255, 0));
      }
      pixels.show();
      delay(500);
      for (int i = 0; i < NUMPIXELS; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
      pixels.show();
      delay(500);
    }
    delayval = delayval-10;
    gamestate = 4;
  }
  
  if(gamestate == 3){  //loss
    currentval--;
    for(int a = 0; a<3; a++){ //blink red 3 times
      for (int i = 0; i < NUMPIXELS; i++) {
        if(i == currentval){
          pixels.setPixelColor(i, pixels.Color(0, 255, 0));
        }
        else{
          pixels.setPixelColor(i, pixels.Color(255, 0, 0));
        }
      }
      pixels.show();
      delay(100);
      for (int i = 0; i < NUMPIXELS; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
      pixels.show();
      delay(100);
    }
    gamestate = 1;
  }
  
  // This sends the updated pixel color to the hardware.
   // Delay for a period of time (in milliseconds).


}
