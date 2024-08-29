#include <Arduino.h>
#include <ArduinoBLE.h>
#include <WiFi.h>

const int chunk = 100;
BLEService niclaService("19B10000-E8F2-537E-4F6C-D104768A1213");
BLECharacteristic enviarcsv("19B10000-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite, chunk);
BLEUnsignedIntCharacteristic receberInt("19B10000-E8F2-537E-4F6C-D104768A1215", BLERead | BLEWrite);

void setup() {
  Serial.begin(9600);

  while (!BLE.begin()) {
    Serial.println("Falha ao iniciar o BLE!");
  }

  BLE.setLocalName("NICLA-VISON");
  BLE.setAdvertisedService(niclaService);
  niclaService.addCharacteristic(enviarcsv);
  niclaService.addCharacteristic(receberInt);

  BLE.addService(niclaService);

  receberInt.setEventHandler(BLEWritten, csvredes);

  //enviarcsv.setEventHandler(BLEWritten, csvredes);

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
    String exemplo = "";
    int n = WiFi.scanNetworks();
    for (int i = 0; i < n; ++i){
      byte bssid[6];
      WiFi.BSSID(i, bssid);
      exemplo += String(WiFi.SSID(i)) + "," + MacAddressStr(bssid) + "," + String(WiFi.RSSI(i)) + "\n"; 
    }
      // lembrar se consegue enviar tudo
    enviarcsv.writeValue(exemplo.c_str());
  }
}

String MacAddressStr(uint8_t mac[]) {
  String macstr = "";
  for (int i = 0; i < 6; i++) {
    if (i > 0) {
      //Serial.print(":");
      macstr += ":";
    }
    if (mac[i] < 16) {
      //Serial.print("0");
      macstr += "0";
    }
    macstr += String(mac[i], HEX);
    //Serial.print(mac[i], HEX);
  }
  return macstr;
  //Serial.println();
}
