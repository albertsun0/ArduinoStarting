#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN 8
#define NUMPIXELS 16

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 0;

int currcolor = 0;  //0 for red 1 green 2 blue
int pcurrcolor = 0;
int r = 255;
int b = 0;
int g = 0;

int subtract = 15;


//for rotary
 int pinA = 3;  // Connected to CLK on KY-040
 int pinB = 2;  // Connected to DT on KY-040
 int encoderPos = 0; 
 int pinALast;  
 int aVal;

void setup() {
  Serial.begin(9600);
  pixels.setBrightness(20);
  pixels.begin(); // This initializes the NeoPixel library.

   pinMode (pinA,INPUT);
   pinMode (pinB,INPUT);
   Serial.begin (9600);
}

void loop() {
  currcolor = pcurrcolor;
  r = 255;
  g = 0;
  b = 0;

  aVal = digitalRead(pinA);
   //Serial.println(aVal);
   if (aVal != pinALast){   //refer to rotary code
     if (digitalRead(pinB) != aVal) { 
       encoderPos ++;
       if(encoderPos>NUMPIXELS){
        encoderPos = NUMPIXELS;
       }
     } 
     else {
       //bCW = false;
       encoderPos--;
       if(encoderPos<0){
        encoderPos = 0;
       }
     }
     Serial.println(encoderPos);
     
   } 
   pinALast = aVal;
   
  
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  }
  for (int i = 0; i < encoderPos; i++) { //draw all pixels
    pixels.setPixelColor(i, pixels.Color(r, g, b));               // RGB
    if (currcolor == 0) {
      r -= subtract;
      g = g + subtract;
      if (r == 0) {
        currcolor++;
      }
    }
    if (currcolor == 1) {
      g = g - subtract;
      b = b + subtract;
      if (g == 0) {
        currcolor++;
      }
    }
    if (currcolor == 2) {
      b = b - subtract;
      r = r + subtract;
      if (b == 0) {
        currcolor = 0;
      }
    }

  }
  pixels.show(); // This sends the updated pixel color to the hardware.
  //delay(delayval); // Delay for a period of time (in milliseconds).


}
