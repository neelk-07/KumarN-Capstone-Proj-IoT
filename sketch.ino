
// Author: Neel Kumar
// Project: NFT Hydroponics Monitoring System
// Platform: ESP32 + Wokwi + Adafruit IO
// Date: June 2025

#include <WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include <DHT.h>

// WiFi credentials
const char* ssid = "Wokwi-GUEST";

// Adafruit IO configuration
#define IO_SERVER       "io.adafruit.com"
#define IO_PORT         1883
#define IO_USERNAME     "neelkmr"
#define IO_KEY          "aio_rETw52sJjhJNST4AnAI8azZiDr9i"

// Sensor and component pins
#define PIN_DHT         13
#define SENSOR_TYPE     DHT22
#define PIN_CO2         34
#define PIN_LEVELSWITCH 5
#define PIN_INDICATOR   12

// Sensor initialization
DHT environmentSensor(PIN_DHT, SENSOR_TYPE);
WiFiClient wifiClient;
Adafruit_MQTT_Client mqttClient(&wifiClient, IO_SERVER, IO_PORT, IO_USERNAME, IO_KEY);

// MQTT Feeds
Adafruit_MQTT_Publish feedTemperature = Adafruit_MQTT_Publish(&mqttClient, IO_USERNAME "/feeds/capstone-feeds.temperature");
Adafruit_MQTT_Publish feedHumidity    = Adafruit_MQTT_Publish(&mqttClient, IO_USERNAME "/feeds/capstone-feeds.humidity");
Adafruit_MQTT_Publish feedCO2         = Adafruit_MQTT_Publish(&mqttClient, IO_USERNAME "/feeds/capstone-feeds.co2");
Adafruit_MQTT_Publish feedLevel       = Adafruit_MQTT_Publish(&mqttClient, IO_USERNAME "/feeds/capstone-feeds.water");
Adafruit_MQTT_Publish feedAlert       = Adafruit_MQTT_Publish(&mqttClient, IO_USERNAME "/feeds/capstone-feeds.alert");
Adafruit_MQTT_Publish feedLight       = Adafruit_MQTT_Publish(&mqttClient, IO_USERNAME "/feeds/capstone-feeds.light");

void setup() {
  Serial.begin(115200);
  pinMode(PIN_LEVELSWITCH, INPUT);
  pinMode(PIN_INDICATOR, OUTPUT);

  environmentSensor.begin();

  connectToWiFi();
}

void connectToWiFi() {
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println(" Connected!");
}

void connectToMQTT() {
  while (!mqttClient.connected()) {
    int8_t result = mqttClient.connect();
    if (result == 0) {
      Serial.println("MQTT connected");
    } else {
      Serial.print("MQTT connection failed: ");
      Serial.println(mqttClient.connectErrorString(result));
      mqttClient.disconnect();
      delay(10000);
    }
  }
}

void loop() {
  connectToMQTT();

  float temperature   = environmentSensor.readTemperature();
  float humidity      = environmentSensor.readHumidity();
  int co2Level        = analogRead(PIN_CO2) / 4;
  int waterLow        = digitalRead(PIN_LEVELSWITCH);
  bool alarmActive    = (co2Level > 200 || waterLow);

  digitalWrite(PIN_INDICATOR, alarmActive);

  Serial.print("Publishing temperature... ");
  Serial.println(feedTemperature.publish(temperature) ? "OK" : "FAIL");

  Serial.print("Publishing humidity... ");
  Serial.println(feedHumidity.publish(humidity) ? "OK" : "FAIL");

  Serial.print("Publishing CO₂... ");
  Serial.println(feedCO2.publish(String(co2Level).c_str()) ? "OK" : "FAIL");

  Serial.print("Publishing water level... ");
  Serial.println(feedLevel.publish(String(waterLow).c_str()) ? "OK" : "FAIL");

  Serial.print("Publishing alarm status... ");
  Serial.println(feedAlert.publish(String(alarmActive).c_str()) ? "OK" : "FAIL");

  Serial.print("Publishing light status... ");
  Serial.println(feedLight.publish("1") ? "OK" : "FAIL");

  mqttClient.processPackets(10000);
  mqttClient.ping();

  delay(15000);
}