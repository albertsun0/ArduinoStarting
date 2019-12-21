# ArduinoStarting
Basic Arduino projects in order of difficulty. 

This documents my personal adventure learning Arduinos, and is meant to be a guide of projects for anyone seeking to learn Arduinos, or a fun, simple guide of projects in general. This is also the curriculum for Arduino lessons at Clements Inventors Club. 


## Starting
If you are an absolute beginner, I would recommend starting with this [video](https://www.youtube.com/watch?v=R102xfcx75I) for setting up an Arduino Nano, which goes through the blink light program and setup.
For other Arduinos, try to find similar videos.

**Which Arduino should I use?**

It really does not matter. For beginners, I would recommend getting either the Uno or Nano. A Nano basically does the same things that an Uno can, just with a smaller size. In these tutorials, I am using the Nano because it is available at the club, and is compact. 

**Code fails to upload onto the Nano**

Check that the board and port are correct. To check for ports, unplug and replug the Nano, and see which port appears in the list. If that still does not work, try changing the processor to ATmega328P (old bootloader).


## Blink Light
First program- Light that blinks every x seconds

1. Long end of led into D2 (it does not matter as long as a power pin), the other end is in rail
2. Resistor not needed for nano, not sure for other types
3. Connect back to ground

![Setup](https://raw.githubusercontent.com/qwertyuiop888/ArduinoStarting/master/images/IMG_20191216_193600199_HDR.jpg)

## Button


## Neopixel
Connect the strip as labeled, I did not need resistors for the nano

Make sure to connect VDC to 5V

![Arduino](https://raw.githubusercontent.com/qwertyuiop888/ArduinoStarting/master/images/IMG_20191217_141521028_HDR.jpg)
![connect](https://raw.githubusercontent.com/qwertyuiop888/ArduinoStarting/master/images/IMG_20191217_231651660_HDR.jpg)

1. Jumping- light up one random pixel every x seconds
2. Wave- x connected pixels loop around 
3. RGB - full rgb effect- fading colors and movement [gif](https://github.com/qwertyuiop888/ArduinoStarting/blob/master/images/rgb.gif)



Reaction time test - soon


