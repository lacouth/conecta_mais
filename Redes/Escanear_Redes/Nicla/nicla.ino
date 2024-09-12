#include <ArduinoBLE.h>
#include <WiFi.h>

BLEService niclaService("19B10000-E8F2-537E-4F6C-D104768A1213");

const int chunk = 100;

BLECharacteristic enviarImagem("19B10000-E8F2-537E-4F6C-D104768A1214", BLERead | BLENotify, chunk);
BLEUnsignedIntCharacteristic receberInt("19B10000-E8F2-537E-4F6C-D104768A1215", BLERead | BLEWrite);

void setup() {
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);

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

  Serial.println("Esperando conexão do Bluetooth®");
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

void dataWritten(BLEDevice central, BLECharacteristic characteristic) {
 
  Serial.print("Valor Recebido: ");
  Serial.println(receberInt.value());
  if(receberInt.value() == 1 ){
    String exemplo = "";
    int n = WiFi.scanNetworks();
    for (int i = 0; i < n; ++i){
      byte bssid[6];
      WiFi.BSSID(i, bssid);
      exemplo = String(WiFi.SSID(i)) + "," + MacAddressStr(bssid) + "," + String(WiFi.RSSI(i) + "," + WiFi.channel(i));
      Serial.println(exemplo);
      enviarImagem.writeValue(exemplo.c_str());
    }
    Serial.println("Enviado");
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
