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

int delayval = 500;
int height = 0;

void setup() {
  Serial.begin(1200);
  pixels.setBrightness(20);
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  
   // for(int i=0;i<NUMPIXELS;i++){ //draw all pixels
      int temp = random(1,16);
      pixels.setPixelColor(temp, pixels.Color(100,100,100));                 // RGB
      pixels.show(); // This sends the updated pixel color to the hardware.
     delay(delayval); // Delay for a period of time (in milliseconds).
      pixels.setPixelColor(temp, pixels.Color(0,0,0));     
      

     
     //}
      }
