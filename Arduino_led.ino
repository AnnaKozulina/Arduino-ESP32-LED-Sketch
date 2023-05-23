#include <FastLED.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3);

#define NUM_LEDS 1

#define DATA_PIN 3
#define CLOCK_PIN 13

CRGB leds[NUM_LEDS];

char receivedChar;
boolean newData = false;

void setup() { 
  
    mySerial.begin(9600);
    Serial.begin(9600);

     FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);  
}

void loop() {
    recvOneChar();
    showNewData();

//  for (int brightness = 0; brightness <= 255; brightness++) {
//    leds[0] = CRGB(brightness, brightness, brightness);
//    FastLED.show();
//    delay(30);
//  }

//  for (int brightness = 255; brightness >= 0; brightness--) {
//    leds[0] = CRGB(brightness, brightness, brightness);
//    FastLED.show();
//    delay(30);
//  }
}

void recvOneChar() {
    if (Serial.available() > 0) {
        receivedChar = Serial.read();
        newData = true;
    }
}

void showNewData() {
  if (newData == true) {

    newData = false;

    switch (receivedChar) {
      case '0': 
        Serial.println("lock");
        break;
      case '1': 
        Serial.println("blink");
          // A
           leds[0] = CRGB::White;
           FastLED.show();
           delay(100);    

           leds[0] = CRGB::Black;
           FastLED.show();
           delay(100); 

           leds[0] = CRGB::White;
           FastLED.show();
           delay(300);             

           leds[0] = CRGB::Black;
           FastLED.show();
           delay(300); 

          // H

           leds[0] = CRGB::White;
           FastLED.show();
           delay(100);    

           leds[0] = CRGB::Black;
           FastLED.show();
           delay(100);           
          
           leds[0] = CRGB::White;
           FastLED.show();
           delay(100);    

           leds[0] = CRGB::Black;
           FastLED.show();
           delay(100);   
          
           leds[0] = CRGB::White;
           FastLED.show();
           delay(100);    

           leds[0] = CRGB::Black;
           FastLED.show();
           delay(100);   
          
           leds[0] = CRGB::White;
           FastLED.show();
           delay(100);    

           leds[0] = CRGB::Black;
           FastLED.show();
           delay(300);   

          // O

           leds[0] = CRGB::White;
           FastLED.show();
           delay(300);   
          
           leds[0] = CRGB::Black;
           FastLED.show();
           delay(100);   

           leds[0] = CRGB::White;
           FastLED.show();
           delay(300);   
          
           leds[0] = CRGB::Black;
           FastLED.show();
           delay(100);  

           leds[0] = CRGB::White;
           FastLED.show();
           delay(300);   
          
           leds[0] = CRGB::Black;
           FastLED.show();
           delay(300);  

          // J

           leds[0] = CRGB::White;
           FastLED.show();
           delay(100);    

           leds[0] = CRGB::Black;
           FastLED.show();
           delay(100);   

           leds[0] = CRGB::White;
           FastLED.show();
           delay(300);   
          
           leds[0] = CRGB::Black;
           FastLED.show();
           delay(100);   

           leds[0] = CRGB::White;
           FastLED.show();
           delay(300);   
          
           leds[0] = CRGB::Black;
           FastLED.show();
           delay(100);  

           leds[0] = CRGB::White;
           FastLED.show();
           delay(300);   
          
           leds[0] = CRGB::Black;
           FastLED.show();
           delay(300);             


           leds[0] = CRGB::Grey;
           FastLED.show();
           delay(1000);
        break;
    }
  }
}