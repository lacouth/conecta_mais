#include <Arduino.h>
#include <ArduinoBLE.h>
#include "esp_camera.h"

// Definir os pinos da câmera para a ESP32-CAM
#define PWDN_GPIO_NUM     32  
#define RESET_GPIO_NUM    -1  
#define XCLK_GPIO_NUM      0  
#define SIOD_GPIO_NUM     26  
#define SIOC_GPIO_NUM     27  

#define Y9_GPIO_NUM       35  
#define Y8_GPIO_NUM       34  
#define Y7_GPIO_NUM       39  
#define Y6_GPIO_NUM       36  
#define Y5_GPIO_NUM       21  
#define Y4_GPIO_NUM       19  
#define Y3_GPIO_NUM       18  
#define Y2_GPIO_NUM        5  
#define VSYNC_GPIO_NUM    25  
#define HREF_GPIO_NUM     23  
#define PCLK_GPIO_NUM     22 

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
  Serial.begin(115200); 
  while (!Serial); 

  pinMode(LED_PIN, OUTPUT); 

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
  config.frame_size = FRAMESIZE_SVGA; // Tamanho do frame QQVGA (800x600)
  config.jpeg_quality = 10; // Qualidade JPEG (0-63)
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
  BLE.setLocalName("ESP32-CAM");
  BLE.setAdvertisedService(esp32Service); 
  esp32Service.addCharacteristic(enviarImagem);
  esp32Service.addCharacteristic(receberInt);

  BLE.addService(esp32Service);

  receberInt.setEventHandler(BLEWritten, dataWritten);

  BLE.advertise();

  Serial.println("Bluetooth® device active, waiting for connections...");
}

void loop() {
  BLEDevice central = BLE.central(); // Procurar por dispositivos BLE centrais conectados

  if (central) { 
    Serial.print("Connected to central: ");
    Serial.println(central.address());
    digitalWrite(LED_PIN, LOW);

    while (central.connected()) {
      
    }

    digitalWrite(LED_PIN, HIGH);
    Serial.print("Disconnected from central: ");
    Serial.println(central.address());
  }
}

// Função de callback chamada quando o valor da característica receberInt é escrito
void dataWritten(BLEDevice central, BLECharacteristic characteristic) {
  Serial.print("Valor Recebido: ");
  Serial.println(receberInt.value());
  
  if (receberInt.value() == 1) { 
    camera_fb_t * fb = esp_camera_fb_get();
    if (!fb) { 
      Serial.println("Falha ao capturar imagem!");  
      return;
    }

    int imageOffset = 0; 
    uint8_t *img = fb->buf; 
    while (imageOffset < fb->len) { 
      int restante = fb->len - imageOffset; 
      int bytesToSend = restante < chunk ? restante : chunk; 
      enviarImagem.writeValue(&img[imageOffset], bytesToSend);
      imageOffset += bytesToSend;
    }
    
    Serial.print("Imagem enviada com sucesso! - ");
    Serial.println(imageOffset);

    
    esp_camera_fb_return(fb);
  }
}
