# Christmastree

Advent calendar in the shape of a Christmastree.  
Based on WS2812 LEDs and an ESP8266 combined with an DS3231 RTC for non WiFi environment.  

## Hardware
I used an WEMOS D1 Mini to controll the LEDs. If you have a WiFi in range, you don't need the DS3231. Just setup the WiFi on the ESP8266 and get your time via NTP.  
In my case there was no WiFi, so I needed an extra RTC.  
The WS2812 LEDs are connected in parallel. Everything can easyly be driven by a 5V DC Powersupply. 

## Software
Based on the WS2812FX Library, beginning at the 1st of a month, the first LED turns on. The 2nd the second LED turns on and so on.  
At the 24th of a month all LEDs are turned on until the 1st of the next month.  
To hold the time, even if the circuit was disconnected, I used a battery buffered DS3231.

## Circuit Layout
The Eagle layout has only less through-plating so it can easiely be made by your own. Also the wires are sized bigger including clearence between wires and pads.

