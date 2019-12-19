# ArduinoStarting
Basic Arduino projects in order of difficulty

## Blink Light
First program- Light that blinks every x seconds

1. Long end of led into D2 (doesnt matter as long as power pin), other end is in rail
2. Resistor not needed for nano, not sure for other types
3. Connect back to ground

![Setup](https://raw.githubusercontent.com/qwertyuiop888/ArduinoStarting/master/images/IMG_20191216_193600199_HDR.jpg)

## Neopixel
Connect the strip as labeled, I did not need resistors for the nano

Make sure to connect VDC to 5V

![Arduino](https://raw.githubusercontent.com/qwertyuiop888/ArduinoStarting/master/images/IMG_20191217_141521028_HDR.jpg)
![connect](https://raw.githubusercontent.com/qwertyuiop888/ArduinoStarting/master/images/IMG_20191217_231651660_HDR.jpg)

1. Jumping- light up one random pixel every x seconds
2. Wave- x connected pixels loop around 
3. RGB - full rgb effect- fading colors and movement [gif](https://github.com/qwertyuiop888/ArduinoStarting/blob/master/images/rgb.gif)
