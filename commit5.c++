#include <DHTesp.h>
#include <LiquidCrystal.h>

// Definições dos pinos
#define DHT_PIN 15
#define POT_PIN 34
#define LED_PIN 4

// Setup DHT
DHTesp dht;

// Setup LCD 16x2: pinos RS, E, D4, D5, D6, D7 conectados conforme JSON
LiquidCrystal lcd(12, 13, 14, 27, 26, 25);

// Estrutura para logs
struct LogEntry {
  unsigned long time;
  String msg;
};

LogEntry logs[50];
int logIdx = 0;

void addLog(String m) {
  if (logIdx < 50) {
    logs[logIdx] = {millis(), m};
    logIdx++;
  }
}

void printLogs() {
  Serial.println("=== Logs ===");
  for (int i = 0; i < logIdx; i++) {
    Serial.print(logs[i].time);
    Serial.print(": ");
    Serial.println(logs[i].msg);
  }
  Serial.println("============");
}

void setup() {
  Serial.begin(115200);
  dht.setup(DHT_PIN, DHTesp::DHT22);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Iniciando...");
}

void loop() {
  unsigned long start = millis();

  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();
  int rawCurrent = analogRead(POT_PIN);

  // Converter rawCurrent para algo "perceptível", por exemplo, tensão (0-3.3V)
  float voltage = (rawCurrent / 4095.0) * 3.3;

  // Controle LED: acende se umidade < 10%
  if (humidity >= 0 && humidity < 10.0) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  // Mostrar no LCD (2 linhas)
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T:");
  if (temperature >= -40 && temperature <= 80) {  // faixa típica do sensor
    lcd.print(temperature, 1);
    lcd.print("C ");
  } else {
    lcd.print("--.-C ");
  }
  lcd.print("H:");
  if (humidity >= 0 && humidity <= 100) {
    lcd.print(humidity, 1);
    lcd.print("%");
  } else {
    lcd.print("---%");
  }

  lcd.setCursor(0, 1);
  lcd.print("Corr:");
  lcd.print(voltage, 2);
  lcd.print(" V");

  // Logs para o terminal
  addLog("Temp: " + String(temperature, 1) + "C Hum: " + String(humidity, 1) + "%");
  addLog("Corrente: " + String(voltage, 2) + " V");
  printLogs();

  // Mostrar no terminal serial
  Serial.print("Temp: ");
  Serial.print(temperature, 1);
  Serial.print(" C, Hum: ");
  Serial.print(humidity, 1);
  Serial.print(" %, Corrente: ");
  Serial.print(voltage, 2);
  Serial.println(" V");

  unsigned long loopTime = millis() - start;
  Serial.print("Loop time: ");
  Serial.print(loopTime);
  Serial.println(" ms");

  delay(2000);
}