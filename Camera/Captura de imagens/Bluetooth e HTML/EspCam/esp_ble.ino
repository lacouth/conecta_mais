#include <Arduino.h>
#include <ArduinoBLE.h>
#include "esp_camera.h"

// Definir os pinos da câmera para a ESP32-CAM
#define PWDN_GPIO_NUM     32  // Pino de energia da câmera
#define RESET_GPIO_NUM    -1  // Pino de reset (não usado)
#define XCLK_GPIO_NUM      0  // Pino do clock externo
#define SIOD_GPIO_NUM     26  // Pino de dados I2C
#define SIOC_GPIO_NUM     27  // Pino de clock I2C

#define Y9_GPIO_NUM       35  // Pino de dados Y9
#define Y8_GPIO_NUM       34  // Pino de dados Y8
#define Y7_GPIO_NUM       39  // Pino de dados Y7
#define Y6_GPIO_NUM       36  // Pino de dados Y6
#define Y5_GPIO_NUM       21  // Pino de dados Y5
#define Y4_GPIO_NUM       19  // Pino de dados Y4
#define Y3_GPIO_NUM       18  // Pino de dados Y3
#define Y2_GPIO_NUM        5  // Pino de dados Y2
#define VSYNC_GPIO_NUM    25  // Pino de sincronização vertical
#define HREF_GPIO_NUM     23  // Pino de referência horizontal
#define PCLK_GPIO_NUM     22  // Pino de clock de pixel

#define LED_PIN 33 // Definir o pino do LED para a ESP32-CAM

// Definir um serviço BLE com UUID específico
BLEService esp32Service("19B10000-E8F2-537E-4F6C-D104768A1213");

// Tamanho do fragmento de dados a ser enviado via BLE
const int chunk = 100;

// Definir características BLE para enviar e receber dados
BLECharacteristic enviarImagem("19B10000-E8F2-537E-4F6C-D104768A1214", BLERead | BLENotify, chunk);
BLEUnsignedIntCharacteristic receberInt("19B10000-E8F2-537E-4F6C-D104768A1215", BLERead | BLEWrite);

int data = 0; // Variável para armazenar dados recebidos

void setup() {
  Serial.begin(115200); // Iniciar a comunicação serial com baud rate de 115200
  while (!Serial); // Esperar até que a comunicação serial esteja pronta

  pinMode(LED_PIN, OUTPUT); // Configurar o pino do LED como saída

  // Configurar as configurações da câmera
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000; // Frequência do clock externo
  config.pixel_format = PIXFORMAT_GRAYSCALE; // Formato de pixel Grayscale para captura de imagem
  config.frame_size = FRAMESIZE_SVGA; // Tamanho do frame SVGA (800x600)
  config.jpeg_quality = 10; // Qualidade JPEG (0-63), 0 é a maior qualidade
  config.fb_count = 1; // Número de frame buffers

  // Inicializar a câmera
  if (esp_camera_init(&config) != ESP_OK) {
    Serial.println("Falha ao inicializar a câmera");
    return;
  }
  Serial.println("Câmera inicializada com sucesso");

  // Inicializar o BLE
  while (!BLE.begin()) {
    Serial.println("Falha ao iniciar o BLE!");
  }

  // Configurar BLE
  BLE.setLocalName("ESP32-CAM"); // Nome do dispositivo BLE
  BLE.setAdvertisedService(esp32Service); // Configurar o serviço BLE a ser anunciado
  esp32Service.addCharacteristic(enviarImagem); // Adicionar característica de enviar imagem
  esp32Service.addCharacteristic(receberInt); // Adicionar característica de receber inteiro

  BLE.addService(esp32Service); // Adicionar o serviço BLE

  receberInt.setEventHandler(BLEWritten, dataWritten); // Definir manipulador de evento para quando o valor da característica receberInt for escrito

  BLE.advertise(); // Começar a anunciar o serviço BLE

  Serial.println("Bluetooth® device active, waiting for connections...");
}

void loop() {
  BLEDevice central = BLE.central(); // Procurar por dispositivos BLE centrais conectados

  if (central) { // Se um dispositivo central se conectar
    Serial.print("Connected to central: ");
    Serial.println(central.address());
    digitalWrite(LED_PIN, LOW); // Acender o LED

    while (central.connected()) {
      // Aqui você pode adicionar código para executar enquanto o dispositivo central está conectado
    }

    digitalWrite(LED_PIN, HIGH); // Apagar o LED
    Serial.print("Disconnected from central: ");
    Serial.println(central.address());
  }
}

// Função de callback chamada quando o valor da característica receberInt é escrito
void dataWritten(BLEDevice central, BLECharacteristic characteristic) {
  Serial.print("Valor Recebido: ");
  Serial.println(receberInt.value()); // Imprimir o valor recebido
  
  if (receberInt.value() == 1) { // Se o valor recebido for 1
    camera_fb_t * fb = esp_camera_fb_get(); // Capturar uma imagem
    if (!fb) { // Se a captura da imagem falhar
      Serial.println("Falha ao capturar imagem!");
      return;
    }

    // Recortar a imagem em partes de 160x120 e enviar
    sendImageChunks(fb);

    // Liberar a memória da imagem
    esp_camera_fb_return(fb);
  }
}

void sendImageChunks(camera_fb_t * fb) {
  int imgWidth = 800;
  int imgHeight = 600;
  int chunkWidth = 160;
  int chunkHeight = 120;
  
  for (int y = 0; y < imgHeight; y += chunkHeight) {
    for (int x = 0; x < imgWidth; x += chunkWidth) {
      // Calcular o endereço do pixel inicial do bloco
      int startIndex = y * imgWidth + x;

      // Enviar o bloco de pixels via BLE
      for (int i = 0; i < chunkHeight; i++) {
        int offset = startIndex + i * imgWidth;
        enviarImagem.writeValue(&fb->buf[offset], chunkWidth);
      }
      
      Serial.print("Bloco enviado - Início: ");
      Serial.print(x);
      Serial.print(", ");
      Serial.print(y);
      Serial.print(" Tamanho: ");
      Serial.print(chunkWidth);
      Serial.print(", ");
      Serial.println(chunkHeight);
    }
  }
}
