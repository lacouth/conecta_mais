#include <ArduinoBLE.h>
#include <WiFi.h>
#include <Wire.h>
#include <VL53L1X.h>

VL53L1X proximity;
bool blinkState = false;
int reading = 0;
int timeStart = 0;
int blinkTime = 2000;

BLEService niclaService("19B10000-E8F2-537E-4F6C-D104768A1213");

const int chunk = 100;

BLECharacteristic enviarImagem("19B10000-E8F2-537E-4F6C-D104768A1214", BLERead | BLENotify, chunk);
BLEUnsignedIntCharacteristic receberInt("19B10000-E8F2-537E-4F6C-D104768A1215", BLERead | BLEWrite);

void setup() {
  Serial.begin(9600);

  Wire1.begin();
  Wire1.setClock(400000); // use 400 kHz I2C
  proximity.setBus(&Wire1);

  pinMode(LEDB, OUTPUT);
  digitalWrite(LEDB, blinkState);

  if (!proximity.init()) {
    Serial.println("Failed to detect and initialize sensor!");
    while (1);
  }

  proximity.setDistanceMode(VL53L1X::Long);
  proximity.setMeasurementTimingBudget(10000);
  proximity.startContinuous(10);

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

    while (central.connected()) {
      reading = proximity.read();

      if (millis() - timeStart >= reading) {
      digitalWrite(LEDB, blinkState);
      timeStart = millis();

      blinkState = !blinkState;
      }
      
    }
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
      exemplo = String(WiFi.SSID(i)) + "," + MacAddressStr(bssid) + "," + WiFi.RSSI(i) + "," + WiFi.channel(i);
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
