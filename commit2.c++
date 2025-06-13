#include <DHTesp.h>

const int DHT_PIN = 15;
const int CURRENT_PIN = 34;

DHTesp dht;

void setup() {
  Serial.begin(115200);
  dht.setup(DHT_PIN, DHTesp::DHT22);
}

void loop() {
  TempAndHumidity data = dht.getTempAndHumidity();
  int rawCurrent = analogRead(CURRENT_PIN);

  Serial.print("Temperatura: ");
  Serial.print(data.temperature);
  Serial.print(" °C, Umidade: ");
  Serial.print(data.humidity);
  Serial.print(" %, Corrente (raw): ");
  Serial.println(rawCurrent);

  delay(2000);
}
