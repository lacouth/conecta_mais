#include <Arduino.h>
#include <esp_wpa2.h>
#include <esp_wifi.h>
#include <WiFi.h>
#include "time.h"
#include "esp_sntp.h"
#include "SPIFFS.h"
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <EEPROM.h>

Adafruit_ST7789 display = Adafruit_ST7789(15, 5, 4);

#define bot 27

int temp;
#define resetar 5000

#define Username "Usuario do Suap"
#define Password "Senha do Suap"
#define Network "IFPB"

#define WIFI_SSID "Rede qualquer"
#define WIFI_PASSWORD "Senha da rede qualquer"

const char *ntpServer = "pool.ntp.org";
#define gmtOffset_sec -10800
const int daylightOffset_sec = 0;

int value1;
int value2;
String value3 = "";
String value4 = "";
int value5;
int value6;

void printLocalTime()
{
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo))
  {
    Serial.println("No time available (yet)");
    return;
  }
  Serial.println(&timeinfo, "%d/%m/%Y,%H:%M:%S,");
}

void conectar()
{
  WiFi.disconnect(true);
  WiFi.setAutoReconnect(true);
  WiFi.mode(WIFI_STA);
  ESP_LOGI(TAG, "Setting WiFi configuration SSID %s...", wifi_config.sta.ssid);
  ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
  ESP_ERROR_CHECK(esp_wifi_sta_wpa2_ent_set_username((uint8_t *)Username, strlen(Username)));
  ESP_ERROR_CHECK(esp_wifi_sta_wpa2_ent_set_password((uint8_t *)Password, strlen(Password)));
  esp_wifi_sta_wpa2_ent_enable();
  WiFi.begin(Network);

  display.println("conectando");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
    display.print(".");
  }
  Serial.println("conectado");
  display.print("!");
}

void setup()
{
  display.init(135, 240);
  display.setTextColor(ST77XX_WHITE);
  display.setRotation(2);
  display.setTextSize(2);
  display.fillScreen(ST77XX_BLACK);

  pinMode(bot, INPUT_PULLUP);

  Serial.begin(115200);
  SPIFFS.begin(true);

  EEPROM.begin(12);
  // EEPROM.write(0, 76);
  // EEPROM.commit();
  Serial.println(EEPROM.read(0));
  display.print("EEPROM: ");
  display.println(EEPROM.read(0));

  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

  conectar();
  //WiFi.begin(WIFI_SSID, WIFI_PASSWORD);


  File csv = SPIFFS.open("/dados.txt");
  if (SPIFFS.exists("/dados.txt"))
    while (csv.available())
      Serial.write(csv.read());
  csv.close();

  temp = millis();
  while (!digitalRead(bot))
    if (millis() - temp >= resetar)
    {
      File reset = SPIFFS.open("/dados.txt", FILE_WRITE);
      reset.print("");
      Serial.println("csv resetado");
      display.println("csv resetado");
      delay(3000);
      break;
    }
}
void loop()
{
  if (!digitalRead(bot))
  {
    display.fillScreen(ST77XX_BLACK);
    display.setCursor(0, 0);

    Serial.println("botão pressionado");

    EEPROM.write(0, EEPROM.read(0) + 1);
    EEPROM.commit();

    File excel = SPIFFS.open("/dados.txt", FILE_APPEND);

    int n = WiFi.scanNetworks();

    display.print(n);
    display.println(" redes");
    display.println();

    Serial.print(n);
    Serial.println(" redes encontradas");
    Serial.println("Num | Rank | SSID                             | MAC               | RSSI | CH");
    for (int i = 0; i < n; ++i)
    {
      value1 = EEPROM.read(0);
      value2 = i + 1;
      value3 = WiFi.SSID(i);
      value4 = WiFi.BSSIDstr(i);
      value5 = WiFi.RSSI(i);
      value6 = WiFi.channel(i);

      struct tm timeinfo;
      if (!getLocalTime(&timeinfo))
      {
        Serial.println("Sem tempo definido");
        return;
      }
      excel.print(&timeinfo, "%d/%m/%Y,%H:%M:%S,");
      excel.print(String(value1) + "," + String(value2) + "," + value3 + "," + value4 + "," + String(value5) + "," + String(value6));
      excel.println(",");

      Serial.printf("%2d", EEPROM.read(0));
      Serial.print(" |  ");
      Serial.printf("%2d", i + 1);
      Serial.print("  | ");
      Serial.printf("%-32.32s", WiFi.SSID(i).c_str());
      Serial.print(" | ");
      Serial.printf("%-17.17s", WiFi.BSSIDstr(i).c_str());
      Serial.print(" | ");
      Serial.printf("%4d", WiFi.RSSI(i));
      Serial.print(" | ");
      Serial.printf("%2d", WiFi.channel(i));
      Serial.println();

      if (i == 0)
      {
        display.print(WiFi.SSID(i));
        display.print(",");
        display.println(WiFi.RSSI(i));
        display.println();
        display.print(WiFi.SSID(n - 1));
        display.print(",");
        display.println(WiFi.RSSI(n - 1));
        display.println();
        display.print("Eprom: ");
        display.println(EEPROM.read(0));
        display.println();
      }
    }
    excel.close();
    display.print("Aperte denovo");

    Serial.println("Todos enviado, aperte denovo");
    Serial.println();
  }
}
