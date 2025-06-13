#include <DHTesp.h>
#include <LiquidCrystal.h>

const int DHT_PIN = 15;
const int CURRENT_PIN = 34;

// LCD pinos: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 13, 14, 27, 26, 25);

DHTesp dht;

void setup() {
  Serial.begin(115200);
  dht.setup(DHT_PIN, DHTesp::DHT22);
  lcd.begin(16, 2);
  lcd.print("Iniciando...");
  delay(1000);
}

void loop() {
  TempAndHumidity data = dht.getTempAndHumidity();
  int rawCurrent = analogRead(CURRENT_PIN);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(data.temperature);
  lcd.print("C H:");
  lcd.print(data.humidity);
  lcd.setCursor(0, 1);
  lcd.print("Corr:");
  lcd.print(rawCurrent);

  Serial.print("Temp: ");
  Serial.print(data.temperature);
  Serial.print(" °C, Hum: ");
  Serial.print(data.humidity);
  Serial.print(" %, Corrente: ");
  Serial.println(rawCurrent);

  delay(2000);
}

