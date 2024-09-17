#include <Arduino.h>
#include <ArduinoBLE.h>
#include <WiFi.h>

BLEService niclaService("19B10000-E8F2-537E-4F6C-D104768A1213");

const int chunk = 100;

BLECharacteristic enviarImagem("19B10000-E8F2-537E-4F6C-D104768A1214", BLERead | BLENotify, chunk);
BLEUnsignedIntCharacteristic receberInt("19B10000-E8F2-537E-4F6C-D104768A1215", BLERead | BLEWrite);

#include "DecisionTreeClassifier.h"
Eloquent::ML::Port::DecisionTree regressor;

String achado = "";

#define macs 38

String z[] = {"00:25:9c:35:93:e2", "00:26:5a:66:55:ef", "00:27:19:ca:71:d2", "18:0d:2c:7f:eb:ac", "18:0d:2c:7f:f5:9c", "18:d6:c7:f9:37:2f", "24:36:da:2b:5e:c0", "24:36:da:2b:5e:c2", "24:36:da:2b:bc:00", "24:36:da:2b:bc:02", "24:fd:0d:57:19:26", "44:d2:44:dd:2e:58", "44:d2:44:dd:32:41", "44:d2:44:dd:32:49", "48:51:cf:81:b0:9e", "50:c7:bf:ef:56:8a", "58:10:8c:91:f3:aa", "64:66:b3:62:eb:86", "64:70:02:99:fe:f4", "84:f1:47:54:6b:80", "84:f1:47:54:6b:82", "84:f1:47:54:7f:60", "84:f1:47:54:7f:62", "84:f1:47:54:8b:a0", "84:f1:47:54:8b:a2", "84:f1:47:54:96:e0", "84:f1:47:54:96:e2", "84:f1:47:54:97:00", "84:f1:47:54:97:02", "84:f1:47:54:eb:20", "84:f1:47:54:eb:22", "84:f1:47:54:f9:80", "84:f1:47:54:f9:82", "cc:32:e5:0c:fc:2b", "e4:4e:2d:85:4c:60", "e4:4e:2d:85:4c:62", "e8:94:f6:b9:2f:46", "f6:c4:7f:b0:20:79"};

int n;

void verificar_ambiente()
{
  n = WiFi.scanNetworks();
  
  float x[macs] = {0.0};

  for (int i = 0; i < n; i++)
  {
    for (int f = 0; f <= macs; f++)
    {
      byte bssid[6];
      WiFi.BSSID(i, bssid);
      if (MacAddressStr(bssid) == z[f])
        x[f] = WiFi.RSSI(i);
    }
    
    if (i == n - 1)
    {
      switch (regressor.predict(x))
      {
      case 0:
        achado = "cod_eng";
        break;
      case 1:
        achado = "fibra"; 
        break;
      case 2:
        achado = "aferi";
        break;
      case 3:
        achado = "aud";
        break;
      case 4:
        achado = "biomedi"; 
        break;
      case 5:
        achado = "med_tele"; 
        break;
      case 6:
        achado = "pesq_eng"; 
        break;
      case 7:
        achado = "prati";
        break;
      default:
        break;
      }

      enviarImagem.writeValue(achado.c_str());
    }
  }
}

void dataWritten(BLEDevice central, BLECharacteristic characteristic) {
 
  Serial.print("Valor Recebido: ");
  Serial.println(receberInt.value());
  if(receberInt.value() == 1 ){
    verificar_ambiente();
    /*String exemplo = "";
    int n = WiFi.scanNetworks();
    for (int i = 0; i < n; ++i){
      byte bssid[6];
      WiFi.BSSID(i, bssid);
      exemplo = String(WiFi.SSID(i)) + "," + MacAddressStr(bssid) + "," + String(WiFi.RSSI(i) + "," + WiFi.channel(i));
      Serial.println(exemplo);
      enviarImagem.writeValue(exemplo.c_str());
    }
    Serial.println("Enviado");*/
  }
}

void setup()
{
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

void loop()
{
  //scan_redes();
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
