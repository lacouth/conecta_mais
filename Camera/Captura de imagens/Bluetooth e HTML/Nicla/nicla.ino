#include <ArduinoBLE.h>
#include <camera.h>
#include "gc2145.h"

// #define IMAGE_MODE CAMERA_RGB565
#define IMAGE_MODE CAMERA_GRAYSCALE

GC2145 galaxyCore;
Camera cam(galaxyCore);
FrameBuffer fb;
String imagem = "";

BLEService niclaService("19B10000-E8F2-537E-4F6C-D104768A1213");

const int chunk = 20;

BLECharacteristic enviarImagem("19B10000-E8F2-537E-4F6C-D104768A1214", BLERead | BLENotify, chunk);
BLEUnsignedIntCharacteristic receberInt("19B10000-E8F2-537E-4F6C-D104768A1215", BLERead | BLEWrite);

int data = 0;


void setup() {
  Serial.begin(9600);
  while (!Serial);

  pinMode(LED_BUILTIN, OUTPUT);

  while (!cam.begin(CAMERA_R160x120, IMAGE_MODE, 30)) {
    Serial.println("falha ao iniciar a câmera!");
  }

  while (!BLE.begin()) {
    Serial.println("falha ao iniciar o BLE!");
  }

  BLE.setLocalName("NiclaVision");
  BLE.setAdvertisedService(niclaService);
  niclaService.addCharacteristic(enviarImagem);
  niclaService.addCharacteristic(receberInt);

  BLE.addService(niclaService);
  
  receberInt.setEventHandler(BLEWritten, dataWritten);

  BLE.advertise();

  Serial.println("Bluetooth® device active, waiting for connections...");
}

void loop() {
  
  BLEDevice central = BLE.central();

  
  if (central) {
    Serial.print("Connected to central: ");
  
    Serial.println(central.address());
    digitalWrite(LED_BUILTIN, LOW);

    while (central.connected()) {
      // if(Serial.available())
      //   updateData();
    }
    
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.print("Disconnected from central: ");
    Serial.println(central.address());
  }
}

// void updateData() {
//   data = Serial.parseInt();
//   Serial.print("Enviando dados..");
//   Serial.println(data);
//   enviarImagem.writeValue(data);
//   Serial.read();
// }

void dataWritten(BLEDevice central, BLECharacteristic characteristic) {
 
  Serial.print("Valor Recebido: ");
  Serial.println(receberInt.value());
  if(receberInt.value() == 1 ){
    if (cam.grabFrame(fb, 3000) == 0) {
      int imageOffset = 0;
      uint8_t *img = fb.getBuffer();
      while(imageOffset < cam.frameSize()){
        int restante = cam.frameSize() - imageOffset;
        int bytesToSend = restante < chunk ? restante : chunk;
        enviarImagem.writeValue(&img[imageOffset],bytesToSend);
        imageOffset += bytesToSend;
        // Serial.print("Parte da imagem enviada: ");
        // Serial.print(imageOffset);
        // Serial.print(" de ");
        // Serial.println(cam.frameSize());

      }
      Serial.println("Imagem enviada com suscesso!");
    } else {
      Serial.println("falha ao obter imagem!");
    }
  }
}