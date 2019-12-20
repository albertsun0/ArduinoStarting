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

int delayval = 0;

int currcolor = 0;  //0 for red 1 green 2 blue
int pcurrcolor = 0;
int r = 255;
int b = 0;
int g = 0;

int subtract = 15;


//for press thing
#define button 5
boolean buttonState;
int height = 0;

void setup() {
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);
  pixels.setBrightness(20);
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  currcolor = pcurrcolor;
  r = 255;
  g = 0;
  b = 0;

  buttonState = digitalRead(button); // 0 for pressed, 1 for unpressed
  Serial.println(buttonState);
  Serial.println(height);
  if (!buttonState) {
    if (height < NUMPIXELS) {
      height++;
    }
  }
  else {
    if (height > 0) {
      height--;
    }

  }
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  }
  for (int i = 0; i < height; i++) { //draw all pixels
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
  delay(delayval); // Delay for a period of time (in milliseconds).


}
