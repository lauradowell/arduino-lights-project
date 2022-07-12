
#define envelopePin A0

#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 16

//What pin is PIN connected to
#define DATA_PIN 5

// Define the array of leds
CRGB leds[NUM_LEDS];


int soundlevel;
int redlevel;
int bluelevel;


void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS); // GRB ordering is assumed
  Serial.begin( 9600 );
  pinMode( envelopePin, INPUT );

}

void loop() {
  // put your main code here, to run repeatedly:
  //this line samples the mic 
  soundlevel  = analogRead(envelopePin);
  delay (100);
  Serial.println(soundlevel);

  if (soundlevel >= 350) {
    Serial.println("red");
    for (int i = 0; i < NUM_LEDS; i ++){
    
    leds[i] = CRGB(200, 0, 0);
    FastLED.show();

    
    } 
      

  } else if (soundlevel < 180) {
    delay(50);
    Serial.println("blue");
    for (int i = 0; i < NUM_LEDS; i ++){
    
    leds[i] = CRGB(0, 0, 200);
    FastLED.show();
    
  }
  
    
  }




}
