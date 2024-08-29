#include <Arduino.h>
#include <ArduinoBLE.h>
#include <WiFi.h>

const int chunk = 20;
BLEService esp32Service("19B10000-E8F2-537E-4F6C-D104768A1213");
BLECharacteristic enviarcsv("19B10000-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite);

void setup() {
  Serial.begin(9600);

  while (!BLE.begin()) {
    Serial.println("Falha ao iniciar o BLE!");
  }

  BLE.setLocalName("NICLA-VISON");
  BLE.setAdvertisedService(niclaService);
  niclaService.addCharacteristic(enviarcsv);

  BLE.addService(niclaService);

  enviarcsv.setEventHandler(BLEWritten, csvredes);

  BLE.advertise();
}

void loop() {
  BLEDevice central = BLE.central();

  if (central) {  // Se um dispositivo central se conectar
    Serial.print("Connected to central: ");
    Serial.println(central.address());

    while (central.connected()) {
      // Aqui você pode adicionar código para executar enquanto o dispositivo central está conectado
    }

    Serial.print("Disconnected from central: ");
    Serial.println(central.address());
  }
}

void csvredes(BLEDevice central, BLECharacteristic characteristic) {
  uint8_t valor = receberInt.value();
  Serial.print("Valor Recebido: ");
  Serial.println(valor);

  if (valor == 1) {
    int n = WiFi.scanNetworks();
    for (int i = 0; i < n; ++i) {
      // value1 = EEPROM.read(eeprom_num);
      // value2 = i + 1;
      // value3 = WiFi.SSID(i);
      // value4 = WiFi.BSSIDstr(i);
      // value5 = WiFi.RSSI(i);
      // value6 = WiFi.channel(i);
    }
  }
}
