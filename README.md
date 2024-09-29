# Sistema de Monitoramento de Temperatura das Pistas de Fórmula E

## Integrantes
### Mohamed Afif Smaili RM 554445
### Gustavo Atanazio RM 559098
### Heitor Prestes RM 554823
### Lucca Cardinale RM 556668


### Link do projeto no wokwi:
https://wokwi.com/projects/410275858992851969


## Descrição do Projeto

Este projeto foi desenvolvido para monitorar a temperatura das pistas de Fórmula E utilizando o sensor DHT22 acoplado a um ESP32. As leituras de temperatura são enviadas via Wi-Fi para um broker MQTT (HiveMQ) e visualizadas em um dashboard no Node-RED. Além disso, o ESP32 aciona uma série de LEDs conforme a variação da temperatura.

## Arquitetura Proposta

A arquitetura do sistema segue o padrão IoT, com os seguintes componentes principais:

1. **Dispositivo IoT (ESP32 com DHT22)**: O ESP32 é o dispositivo responsável por capturar as leituras de temperatura do sensor DHT22 e enviar os dados para o broker MQTT via Wi-Fi.
   
2. **Back-end (Broker MQTT)**: Utilizamos o broker público HiveMQ para gerenciar a comunicação entre o ESP32 e o dashboard Node-RED.

3. **Front-end (Node-RED Dashboard)**: O Node-RED recebe os dados enviados pelo ESP32 via MQTT e exibe essas informações em tempo real em um dashboard visual.

## Recursos Necessários

### Dispositivos IoT
- **ESP32**: Microcontrolador com suporte a Wi-Fi.
- **DHT22**: Sensor de temperatura e umidade.
- **LEDs**: 10 LEDs conectados ao ESP32 para indicar visualmente a variação da temperatura.

### Back-end
- **Broker MQTT (HiveMQ)**: Responsável por receber os dados do ESP32 e disponibilizá-los para o Node-RED.

### Front-end
- **Node-RED**: Plataforma de desenvolvimento de automação que permite criar fluxos e dashboards. Será usada para exibir as leituras de temperatura.

## Instruções de Uso

### Pré-requisitos

- **Hardware**: ESP32, sensor DHT22, LEDs e jumpers para as conexões.
- **Software**: Arduino IDE, biblioteca PubSubClient e DHTesp, Node-RED instalado e configurado, conexão com o broker HiveMQ.

### Como Configurar

1. **ESP32**:
   - Conecte o DHT22 ao pino 23 do ESP32.
   - Conecte os LEDs aos pinos especificados no código.
   - Faça o upload do código fornecido ao ESP32 utilizando o Arduino IDE.

2. **Node-RED**:
   - Instale o Node-RED e configure o nó MQTT para se conectar ao broker HiveMQ.
   - Crie um dashboard para exibir as leituras de temperatura recebidas no tópico MQTT.

### Requisitos

- **ESP32**: Conexão Wi-Fi com SSID e senha configurados.
- **Node-RED**: Configurado com um fluxo para consumir os dados MQTT.
- **Broker MQTT**: Broker público ou privado configurado (no caso, HiveMQ).

## Dependências

### Bibliotecas Arduino
- **WiFi.h**: Para conexão à rede Wi-Fi.
- **PubSubClient.h**: Para comunicação via MQTT.
- **DHTesp.h**: Para manipulação do sensor DHT22.

### Node-RED
- **Nó MQTT**: Para receber as mensagens do broker.
- **Nó Dashboard**: Para exibir os dados de temperatura no front-end.

