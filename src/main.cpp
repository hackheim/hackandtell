#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define PIN        5 // On Trinket or Gemma, suggest changing this to 1
#define NUMPIXELS 109 // Popular NeoPixel ring size

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

const long COUNTDOWN_TIME = (5l*60l*407l);

long startTime;

void setup() {
  pixels.begin();
  pixels.clear();
  startTime = millis();
  Serial.begin(9600);
}


void loop() {
  long time = millis();
  long currentTime = time-startTime;
  //Serial.println(currentTime);
  if (currentTime<=COUNTDOWN_TIME)
  {
    //Serial.println("A");
    int ledProgress = map(currentTime, 0, COUNTDOWN_TIME, 0, NUMPIXELS);
    //Serial.println(ledProgress);

    for(int i=0; i<NUMPIXELS; i++) {
      if (i<=ledProgress)
      {
        pixels.setPixelColor(NUMPIXELS-i-1, pixels.Color(0, 255, 0));
      }
    }
    
    pixels.show();
  } else {
    while (true) {
      for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
        pixels.setPixelColor(i, pixels.Color(255, 0, 0));
      }
      pixels.show();
      delay(300);
      pixels.clear();
      pixels.show();
      delay(300);
    }
  }
}