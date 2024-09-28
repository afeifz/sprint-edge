#include <WiFi.h>
#include <PubSubClient.h>

#include <DHTesp.h>
const int DHT_PIN = 23;
DHTesp dhtSensor;


const char *ssid = "Wokwi-GUEST";
const char *password = "";
const char *mqtt_server = "broker.hivemq.com";


WiFiClient WOKWI_Client;
PubSubClient client(WOKWI_Client);

const int ledCount = 10;
const int ledPins[ledCount] = {12,13,14,18,19,25,26,27,32,33};

void setup_wifi() {

  delay(10);

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println(".");
  }
  Serial.println("");
  Serial.println("WiFi Conectado");
  Serial.println("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {

  while (!client.connected()) {
    Serial.print("Tentando conectar ao MQTT...");
    
    if (client.connect("WOKWI_Client")) {
      Serial.println("Conectado");
    
    } else {
      Serial.print("failed, rc= ");
      Serial.print(client.state());
      Serial.println("Tentando novamente em 5 segundos");

      delay(5000);
    }  
  }
}


void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);

    for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
}

void setLEDs(float temperature) {

  int ledToLight = map(temperature, 0, 40, 0, ledCount);
  ledToLight = constrain(ledToLight, 0, ledCount);

  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.println(ledToLight);

  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], (i < ledToLight) ? HIGH : LOW);
  }
}

void DHT_Envia() {
  TempAndHumidity  data = dhtSensor.getTempAndHumidity();
  client.publish("CHALLENGE/HEITOR",String(data.temperature).c_str());
  
  Serial.println("Temp: " + String(data.temperature, 2) + "C");
  Serial.println("---");

  setLEDs(data.temperature);
  delay(1000);
}

void loop() {
  reconnect();
  DHT_Envia();
}