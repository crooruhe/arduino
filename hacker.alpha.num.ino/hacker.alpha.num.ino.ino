// Demo the quad alphanumeric display LED backpack kit
// scrolls through every character, then scrolls Serial
// input onto the display

#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_AlphaNum4 alpha4 = Adafruit_AlphaNum4();

char hacker[] = "THIS IS OUR WORLD NOW... THE WORLD OF THE ELECTRON AND THE SWITCH, THE BEAUTY OF THE BAUD. I AM A CRIMINAL. MY CRIME IS THAT OF CURIOSITY... I AM A HACKER, AND THIS IS MY MANIFESTO.    ";
int i = 0;

void setup() {
  Serial.begin(9600);
  
  alpha4.begin(0x70);  // pass in the address

  alpha4.writeDigitRaw(3, 0x0);
  alpha4.writeDigitRaw(0, 0xFFFF);
  alpha4.writeDisplay();
  delay(200);
  alpha4.writeDigitRaw(0, 0x0);
  alpha4.writeDigitRaw(1, 0xFFFF);
  alpha4.writeDisplay();
  delay(200);
  alpha4.writeDigitRaw(1, 0x0);
  alpha4.writeDigitRaw(2, 0xFFFF);
  alpha4.writeDisplay();
  delay(200);
  alpha4.writeDigitRaw(2, 0x0);
  alpha4.writeDigitRaw(3, 0xFFFF);
  alpha4.writeDisplay();
  delay(200);
  
  alpha4.clear();
  alpha4.writeDisplay();

}

void loop() {
  

  alpha4.writeDigitAscii(0, hacker[i]);
  alpha4.writeDigitAscii(1, hacker[i+1]);
  alpha4.writeDigitAscii(2, hacker[i+2]);
  alpha4.writeDigitAscii(3, hacker[i+3]);
  alpha4.writeDisplay();

  delay(300);
  i++;

  if (hacker[i+3] == NULL) {
    i = 0;
  }
  
}