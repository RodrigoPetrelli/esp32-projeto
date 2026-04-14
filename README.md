link projeto funcionando: 
https://wokwi.com/projects/433665329490696193
# 🌡️ Sistema Ciberfísico ESP32 — Monitoramento Ambiental IoT

Sistema embarcado desenvolvido com **ESP32** para monitoramento remoto de temperatura, umidade e corrente elétrica em tempo real, com alertas visuais e exibição local via display LCD.

---

## 📋 Sobre o Projeto

Este projeto foi desenvolvido como trabalho da disciplina de **Sistemas Ciberfísicos** na PUCPR. O sistema coleta dados ambientais através de sensores, exibe as informações em um display LCD 16x2 e registra logs no terminal serial para análise posterior.

---

## ⚙️ Funcionalidades

- 🌡️ Leitura de **temperatura e umidade** via sensor DHT22
- ⚡ Monitoramento de **corrente elétrica** simulada por potenciômetro
- 🔴 **Alerta visual** com LED vermelho quando umidade cai abaixo de 10%
- 📟 Exibição em tempo real no **display LCD 16x2** (interface I2C)
- 📝 **Registro de logs** no terminal serial para diagnóstico e análise

---

## 🛠️ Hardware Utilizado

| Componente | Função |
|---|---|
| ESP32 DevKit | Microcontrolador principal |
| Sensor DHT22 | Leitura de temperatura e umidade |
| Potenciômetro | Simulação de sensor de corrente |
| Display LCD 16x2 | Visualização local dos dados |
| LED vermelho | Alerta de baixa umidade |

---

## 🔌 Diagrama de Pinos

| Componente | Pino ESP32 |
|---|---|
| DHT22 | GPIO 15 |
| Potenciômetro | GPIO 34 |
| LED | GPIO 2 |
| LCD (RS, EN, D4–D7) | GPIO 12, 13, 14, 27, 26, 25 |

---

## 💻 Tecnologias e Bibliotecas

- **C++ / Arduino Framework**
- `DHTesp` — leitura do sensor DHT22
- `LiquidCrystal` — controle do display LCD

---

## 📊 Desempenho

- **Latência do loop:** 40–60ms por ciclo
- **Intervalo de amostragem:** 2 segundos
- **Consumo estimado:** 80–120mA em operação normal
- **Comunicação serial:** 115200 bps

---

## 🚀 Como Usar

1. Clone o repositório:
   ```bash
   git clone https://github.com/RodrigoPetrelli/esp32-projeto.git
   ```

2. Abra o projeto no **Arduino IDE** ou **PlatformIO**

3. Instale as bibliotecas necessárias:
   - `DHTesp`
   - `LiquidCrystal`

4. Conecte o hardware conforme o diagrama de pinos

5. Faça o upload para o ESP32 e abra o **Monitor Serial** (115200 bps)

---

## 📁 Estrutura do Projeto

```
esp32-projeto/
├── src/
│   └── main.cpp       # Código principal
└── README.md
```

---

## 👤 Autor

**Rodrigo Petrelli**  
Estudante de Ciência da Computação — PUCPR  
[LinkedIn](https://www.linkedin.com/in/rodrigo-petrelli-201523334/) • [GitHub](https://github.com/RodrigoPetrelli)
