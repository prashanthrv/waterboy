#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ThingerSmartConfig.h>

#define USERNAME "prashanthrv"
#define DEVICE_ID "esp8266"
#define DEVICE_CREDENTIAL "pras123"

ThingerSmartConfig thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);

  // digital pin control example (i.e. turning on/off a light, a relay, configuring a parameter, etc)
  thing["led"] << digitalPin(BUILTIN_LED);

  // resource output example (i.e. reading a sensor value)
  thing["millis"] >> outputValue(millis());

  // more details at http://docs.thinger.io/arduino/
}

void loop() {
  thing.handle();
}
