#ifndef MAIN_H_
#define MAIN_H_

#define BLYNK_TEMPLATE_ID "TMPL_Yq5F5Xs" //blynk function
#define BLYNK_DEVICE_NAME "Home Automation" //blynk function
#define BLYNK_AUTH_TOKEN "5sDIvm0xwB2iNLnJjU-1cyuPDZWYSXVc" //blynk function
#define BLYNK_PRINT Serial //blynk function

#include <BlynkSimpleEsp32.h> //blynk library
#include <DHT.h> //DHT library

#define monitor 9600

#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define light 4
#define fan 5
#define AC 6
#define kitchenLight 7
#define motor 8
#define diningRoomFan 9
#define diningRoomLight 10

char ssid[] = "Neej's Personal"; //ssid of WiFi
char pass[] = "tp010601"; //password of WiFi
char auth[] = BLYNK_AUTH_TOKEN;

BlynkTimer timer;

BLYNK_WRITE (V1)
{
  int val= param.asInt();
  if (val == 0){
    digitalWrite(light, HIGH);
  }
  if (val == 1){
    digitalWrite(light, LOW);
  }
}

BLYNK_WRITE (V2)
{
  int val= param.asInt();
  if (val == 0){
    digitalWrite(fan, HIGH);
  }
  if (val == 1){
    digitalWrite(fan, LOW);
  }
}

BLYNK_WRITE (V3)
{
  int val= param.asInt();
  if (val == 0){
    digitalWrite(AC, HIGH);
  }
  if (val == 1){
    digitalWrite(AC, LOW);
  }
}

BLYNK_WRITE (V4)
{
  int val= param.asInt();
  if (val == 0){
    digitalWrite(kitchenLight, HIGH);
  }
  if (val == 1){
    digitalWrite(kitchenLight, LOW);
  }
}

BLYNK_WRITE (V5)
{
  int val= param.asInt();
  if (val == 0){
    digitalWrite(motor, HIGH);
  }
  if (val == 1){
    digitalWrite(motor, LOW);
  }
}

BLYNK_WRITE (V6)
{
  int val= param.asInt();
  if (val == 0){
    digitalWrite(diningRoomFan, HIGH);
  }
  if (val == 1){
    digitalWrite(diningRoomFan, LOW);
  }
}

BLYNK_WRITE (V7)
{
  int val= param.asInt();
  if (val == 0){
    digitalWrite(diningRoomLight, HIGH);
  }
  if (val == 1){
    digitalWrite(diningRoomLight, LOW);
  }
}

void sendSensor()
{
  int h = dht.readHumidity();
  int t = dht.readTemperature(); 

  if (isnan(h) || isnan(t)) { //isnan = is not a number
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Blynk.virtualWrite(V8, t);
  Blynk.virtualWrite(V9, h);
}

#endif