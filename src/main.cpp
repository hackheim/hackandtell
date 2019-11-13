#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define PIN        5 // On Trinket or Gemma, suggest changing this to 1
#define NUMPIXELS 186 // Popular NeoPixel ring size

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 324*5 // Time (in milliseconds) to pause between pixels

void setup() {
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}


void loop() {
  pixels.clear(); // Set all pixel colors to 'off'

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(0, 150, 0));

    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }


  for(int f=0; f<30; f++) {
    for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
      pixels.setPixelColor(i, pixels.Color(150, 0, 0));
    }
    pixels.show();
    delay(200);
    pixels.clear();
    pixels.show();
    delay(200);
  }
}