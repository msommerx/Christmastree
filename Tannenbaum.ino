#include <Wire.h>
#include "DS3231.h"
#include <WS2812FX.h>
#define LED_COUNT 24
#define LED_PIN 2   //D4 -> GPIO2
WS2812FX ws2812fx = WS2812FX(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int day = 0;
int leds = 0;
int brightness = 50;
int speed1 = 21000;

RTClib RTC;

void setup () {
    Serial.begin(9600);
    Wire.begin();
    DateTime now = RTC.now();
    Serial.print(now.day(), DEC);
    day = now.day(), DEC;
    leds = day-1;
    if (leds > 24) {leds = 24;}
    Serial.print(leds);
    //LED Initialize
    ws2812fx.init();
    ws2812fx.setSegment(0, 0, leds, FX_MODE_RAINBOW_CYCLE, RED, speed1, false);
    ws2812fx.setBrightness(50);
    ws2812fx.start();
    pinMode(15, INPUT_PULLUP);
    pinMode(12, INPUT_PULLUP);
    }

void loop () {
    ws2812fx.service();
    if(digitalRead(15) == HIGH) {
      ws2812fx.setBrightness(brightness);
      brightness++;
      delay(50);
      if (brightness > 110) brightness=0;
    }
    if(digitalRead(12) == 0) {
      speed1 = speed1-5000;
      Serial.println("ping");
      ws2812fx.setSpeed(speed1);
      delay(100);
      if (speed1 < 0) speed1=21000;
    }
    

     


    
}
