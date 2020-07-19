/*
 * Project Particle_Temp_Hum_To_Azure_IoTHub
 */

#include "Grove_Temperature_And_Humidity_Sensor.h"

//Temperature and Humidity Sensor
DHT sensor(D2);
String temp;
String hum;

// setup() runs once, when the device is first turned on.
void setup()

  //Temperature and Humidity Sensor
  Serial.begin(9600);
  sensor.begin();
}

// loop() runs over and over again (delay duration can be manipulated in the Particle App)
void loop()
{

  //get sensor data
  temp = String(sensor.getTempCelcius());
  hum = String(sensor.getHumidity());

  //AZURE build data string and publish data
  String res = "{\"temperature\":" + temp + ", \"humidity\":" + hum + "}";
  Particle.publish("temperature", res, PRIVATE);

  //wait for 30 seconds
  delay(30 * 1000);
}
