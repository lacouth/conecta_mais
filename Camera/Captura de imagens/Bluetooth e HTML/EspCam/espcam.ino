#include <ArduinoBLE.h>
#include <eloquent_esp32cam.h>
// #include <camera.h>
// #include "gc2145.h"

// #define IMAGE_MODE CAMERA_RGB565
// #define IMAGE_MODE CAMERA_GRAYSCALE

// GC2145 galaxyCore;
// Camera cam(galaxyCore);
// FrameBuffer fb;
String imagem = "";

using eloq::camera;

BLEService niclaService("19B10000-E8F2-537E-4F6C-D104768A1213");

const int chunk = 20;

BLECharacteristic enviarImagem("19B10000-E8F2-537E-4F6C-D104768A1214", BLERead | BLENotify, chunk);
BLEUnsignedIntCharacteristic receberInt("19B10000-E8F2-537E-4F6C-D104768A1215", BLERead | BLEWrite);

int data = 0;

#define LED_BUILTIN 33

void setup()
{
  Serial.begin(115200);
  // while (!Serial);

  pinMode(LED_BUILTIN, OUTPUT);
  /*
  while (!cam.begin(CAMERA_R160x120, IMAGE_MODE, 30)) {
    Serial.println("falha ao iniciar a câmera!");
  }
   */

  camera.pinout.aithinker();
  camera.brownout.disable();
  camera.resolution.qqvga();
  camera.quality.low();

  while (!camera.begin().isOk())
    Serial.println(camera.exception.toString());

  Serial.println("Camera OK");

  while (!BLE.begin())
  {
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

void loop()
{
  BLEDevice central = BLE.central();

  if (central)
  {
    Serial.print("Connected to central: ");

    Serial.println(central.address());
    digitalWrite(LED_BUILTIN, LOW);

    while (central.connected())
    {
      if (Serial.available())
        updateData();
    }

    digitalWrite(LED_BUILTIN, HIGH);
    Serial.print("Disconnected from central: ");
    Serial.println(central.address());
  }
}

void updateData()
{
  data = Serial.parseInt();
  Serial.print("Enviando dados..");
  Serial.println(data);
  enviarImagem.writeValue(data);
  Serial.read();
}

void dataWritten(BLEDevice central, BLECharacteristic characteristic)
{
  Serial.print("Valor Recebido: ");
  Serial.println(receberInt.value());
  if (receberInt.value() == 1)
  {
    if (camera.capture().isOk())
    {
      int imageOffset = 0;
      while (imageOffset < camera.getSizeInBytes())
      {
        int restante = camera.getSizeInBytes() - imageOffset;
        int bytesToSend = restante < chunk ? restante : chunk;
        enviarImagem.writeValue(&camera.frame[imageOffset], bytesToSend);
        imageOffset += bytesToSend;
        Serial.print("Parte da imagem enviada: ");
        Serial.print(imageOffset);
        Serial.print(" de ");
        Serial.println(camera.getSizeInBytes());
      }
      camera.free();
      Serial.println("Imagem enviada com suscesso!");
    }
    else
    {
      Serial.println("falha ao obter imagem!");
    }
  }
}