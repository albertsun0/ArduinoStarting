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

//int off = NUMPIXELS-6;
int currcolor = 0;  //0 for red 1 g 2 b
int r = 255;
int b = 0;
int g = 0;
int subtract = 45;

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code
  Serial.begin(1200);
  pixels.setBrightness(20);
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {

  for(int spx = 0; spx < NUMPIXELS; spx++)
  {
 
    for(int i=0;i<NUMPIXELS;i++){ //draw all pixels
        pixels.setPixelColor((i+spx)%NUMPIXELS, pixels.Color(r,g,b)); 

        if(currcolor == 0){
          r-=subtract;
          b = b+subtract;
          if(r == 30){
        currcolor++;
          }
        }
        if(currcolor == 1){
          b = b-subtract;
          g = g+subtract;
          if(b == 30){
        currcolor++;
          }
        }
        if(currcolor == 2){
          g = g-subtract;
          r = r+subtract;
          if(g == 30){
        currcolor = 0;
          }
        }
        Serial.print(r);
         pixels.show(); // This sends the updated pixel color to the hardware.
        delay(delayval); // Delay for a period of time (in milliseconds).

        //pixels.setPixelColor(off, pixels.Color(0,0,0));
        //off++;
       // if(off>NUMPIXELS-1){
       //   off = 0;
        //}
      }
}
  
}
