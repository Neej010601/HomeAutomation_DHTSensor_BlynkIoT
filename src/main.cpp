#include <Arduino.h>

#include <WiFi.h>
#include "main.h" //Own Made library including all the blynk and DHT code.

void setup()
{
Serial.begin(monitor);
Blynk.begin(auth, ssid, pass);
pinMode(light, OUTPUT);
pinMode(fan, OUTPUT);
pinMode(AC, OUTPUT);
pinMode(kitchenLight, OUTPUT);
pinMode(motor, OUTPUT);
pinMode(diningRoomFan, OUTPUT);
pinMode(diningRoomLight, OUTPUT);
dht.begin();
timer.setInterval(10L, sendSensor);
}

void loop()
{
Blynk.run();
timer.run();
}