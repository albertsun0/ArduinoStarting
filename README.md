# ArduinoStarting
Basic Arduino projects in order of difficulty. 

This documents my personal adventure learning Arduinos, and is meant to be a guide of projects for anyone seeking to learn Arduinos, or a fun, simple guide of projects in general. This is also the curriculum for Arduino lessons at Clements Inventors Club. 


## Starting
If you are an absolute beginner, I would recommend starting with this [video](https://www.youtube.com/watch?v=R102xfcx75I) for setting up an Arduino Nano, which goes through the blink light program and setup.
For other Arduinos, try to find similar videos.

**Neopixel**

Neopixel is an rgb strip that is easily attached to the Arduino, and can be used to create cool lighting effects. To me, the Neopixel was a practical use for Arduinos, and really interesting to play around with. I’ve basically connected everything to Neopixel in some way, and made a ton of fun projects with it (documented below). I used 2 [8 pixel sticks](https://www.adafruit.com/product/1426) soldered together. 

**Which Arduino should I use?**

It really does not matter. For beginners, I would recommend getting either the Uno or Nano. A Nano basically does the same things that an Uno can, just with a smaller size. In these tutorials, I am using the Nano because it is available at the club, and is compact. 

**Code fails to upload onto the Nano**

Check that the board and port are correct. To check for ports, unplug and replug the Nano, and see which port appears in the list. If that still does not work, try changing the processor to ATmega328P (old bootloader).

## Try to do the projects yourself before looking at the instructions or code!

## Blink Light
First program- LED that blinks every x seconds

1. Long end of led into D2 (it does not matter as long as a digital pin), the other end is in rail (Remember current travels down the rails)
2. Resistor not needed for nano, not sure for other arduinos
3. Connect a resistor or wire to ground

![Setup](https://raw.githubusercontent.com/qwertyuiop888/ArduinoStarting/master/images/IMG_20191216_193600199_HDR.jpg)

## Button
Log into serial when button is pressed 

Turn on LED when button pressed

1. Connect a digital pin on the same row as one of the connectors
2. Connect the other end to ground
You can now test serial logging (refer to button.ino)

![Setup](https://raw.githubusercontent.com/qwertyuiop888/ArduinoStarting/master/images/button.jpg)

3. Insert the led the same way as in blink light (I connected to D9)

![LED](https://raw.githubusercontent.com/qwertyuiop888/ArduinoStarting/master/images/buttonled.jpg)
![LEDON](https://raw.githubusercontent.com/qwertyuiop888/ArduinoStarting/master/images/buttonled2.jpg)

if you used different digital pins, remember to change in code!

More button- neopixel button, neopixel button game (in neopixel section)

## Rotary
Rotary value- Add when rotating one way, subtract when rotating the other way
Detect if rotated clockwise or counterclockwise

For this I am using the Keyes Rotary Encoder, but any other rotart would do the same things. Just search how to connect

1. Connect CLK and DT to digital pins (I used D3 and D2)
2. Connect + to 5V
3. Connect GND to ground

![Rotary](https://raw.githubusercontent.com/qwertyuiop888/ArduinoStarting/master/images/rotary.jpg)
![Rotary2](https://raw.githubusercontent.com/qwertyuiop888/ArduinoStarting/master/images/rotart.jpg)

More rotary- Rotary Neopixel


## Neopixel
Connect the strip as labeled (GND to ground, Din to a digita input, VDC to 5V), I did not need resistors for this setup on the nano

Make sure to connect VDC to 5V


In the IDE, go to Sketch> Include Library > Manage Libraries> and install Adafruit Neopixel

![Arduino](https://raw.githubusercontent.com/qwertyuiop888/ArduinoStarting/master/images/IMG_20191217_141521028_HDR.jpg)
![connect](https://raw.githubusercontent.com/qwertyuiop888/ArduinoStarting/master/images/IMG_20191217_231651660_HDR.jpg)


Basic Neopixel- Try to do these without the code!

1. Jumping- light up one random pixel every x seconds
2. Wave- x connected pixels loop around 
3. RGB - full rgb effect- fading colors and movement [gif](https://github.com/qwertyuiop888/ArduinoStarting/blob/master/images/rgb.gif)

**Neopixel Button**

Connect the Neopixel with the button
![Neopixelb](https://raw.githubusercontent.com/qwertyuiop888/ArduinoStarting/master/images/buttonneopixel.jpg)
![Neobut2](https://raw.githubusercontent.com/qwertyuiop888/ArduinoStarting/master/images/buttonneo2.jpg)

Make a program that lights up more pixels when button is pressed, and subtracts pixels when unpressed (neopixel_button.ino)

Simple game- match a looping pixel to stationary pixel to win ()

**Neopixel Rotary***

Connect Nepixel onto rotary
![NeopixelRota](https://raw.githubusercontent.com/qwertyuiop888/ArduinoStarting/master/images/rotaryneopixel.jpg)

You can connect multiple things to the same 5V and multiple things to the same ground

Make a program that adds/subtracts pixels on rotating the rotary

Reaction time test - soon, 


