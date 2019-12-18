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

int delayval = 30;

int currcolor = 0;  //0 for red 1 green 2 blue
int pcurrcolor = 0;
int r = 255;
int b = 0;
int g = 0;

int pr = 255;  //color from before
int pb = 0;
int pg = 0;

int subtract = 15;

void setup() {
  Serial.begin(1200);
  pixels.setBrightness(20);
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
    if(currcolor == 0){
        if(pb == 0){
          pcurrcolor = 2;
        }
        pr-=subtract;
        pb = pb+subtract;
        
      }
      if(currcolor == 1){
        if(pr == 0){
          pcurrcolor--;
        }
        pg = pg-subtract;
        pr = pr+subtract;
        
      }
      if(currcolor == 2){
         if(pg == 0){
          pcurrcolor--;
        }
        pb = pb-subtract;
        pg = pg+subtract;
       
      }   
      currcolor = pcurrcolor;
      r = pr;
      g = pg;
      b = pb;
      
    for(int i=0;i<NUMPIXELS;i++){ //draw all pixels
      pixels.setPixelColor(i, pixels.Color(r,g,b));                 // RGB
      if(currcolor == 0){
        r-=subtract;
        g = g+subtract;
        if(r == 0){
          currcolor++;
        }
      }
      if(currcolor == 1){
        g = g-subtract;
        b = b+subtract;
        if(g == 0){
          currcolor++;
        }
      }
      if(currcolor == 2){
        b = b-subtract;
        r = r+subtract;
        if(b == 0){
          currcolor = 0;
        }
      }   
     
     }
      pixels.show(); // This sends the updated pixel color to the hardware.
     delay(delayval); // Delay for a period of time (in milliseconds).


}
