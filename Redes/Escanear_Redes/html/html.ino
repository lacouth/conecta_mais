// html_projeto.cpp

#include <Arduino.h>
#include <esp_wpa2.h>
#include <esp_wifi.h>
#include <WiFi.h>
#include "time.h"
#include "esp_sntp.h"
#include "ESPAsyncWebServer.h"
#include "SPIFFS.h"
#include <HTTPClient.h>
#include <ESP_Google_Sheet_Client.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <EEPROM.h>

const char PRIVATE_KEY[] PROGMEM = 
"-----BEGIN PRIVATE KEY-----\
nMIIEvgIBADANBgkqhkiG9w0BAQEFAASCBKgwggSkAgEAAoIBAQCIc81jMpnhtOE/\
nC1nnM2+M84VW4tpZ6KH8Yv+NfLKKO8NguJs1PNaBchgpPCUYwOV4S7qyn0/5TwZW\
n/47QuQq+PIdRXwSg2bRojXg78GfUm0xsCkkqsG52TI4e3yanPJyOYvamrgbyh4PH\
nOlKM7Gvr2gTGPORWLN2AVv/oSwYAuWrOXuY9UiE0h4q92odlLPBPMCFwRQe+3ctS\
nqtjnTIC3P39/MLcZjQHdP/KmEoUbBdUFeOIf/Hrogj60T61d+E4aKzR9WLcIGLMG\
n4bA4cNjUH6EXsgVwHB3SHpLI3UCzDs3xhhIkiDHyLXs7Mqv+g8vFbKqKb2FqcBQ0\
novB0iPN9AgMBAAECggEANMwJ9o4HuKuSVCCCQtFGIlW/jCTus8ctlkh/9TEArDf/\
nmxcTBwBpR2DsNFhPSkqo/2jd7mtyOFb5bwQnMF/I5l7pRPTtB4f1JFdI5Hha1Ira\
ngRthwCDQPPnWK9/QRvlO4lEsesXvbjw9IwNQGbMI9xM+sa2x9B4b/qKrFiihQ/np\
nzu1g09NTGl7xhzD3pxe/pYDPQMyVl9HLiQlita+bCp/ehD0/GW1gTryQTCZaQwH4\
n/+Fm4sLmwGOeVOP7qVLorgblMStisADqJaUtqCleAA+4844EW6uYFa8pyHiK1xiC\
nIYr2HXvg84SYiKb3mNbJfYB185KvfcCkYRBJjsn1SQKBgQC+UFIeRfodnNzqNwkq\
nQAn7DRHcfvM4JCKi4tql7z8mMskYtPf+W6whG1fNcFbCG224i4H0LVZqWslfyQCO\
nVjOoHeZRU+TM2OItTpaIaT8hGkAAYOukB99Org6RWOyno45DoPM8OHlqMgksWVBc\
nXZTEnv+BFAUlMg1vcEBRJBrqrwKBgQC3jGnxupuvN8eU74r4T69MG1O09y0zcbWc\
nqs07zT6NJ1+YMiV3W1zFlFPFvYKtj+qHwIHlPnKFtUriRAZJhNhGHBgcpQkGmWFt\
nKYK1Ju7x4awr1hnzjUSgH6X384U61Vvm1CqneoZJHplqJcp7ujqehKMywAEXNLq8\
nK9tRKicfkwKBgQCvmYELudmcNT6JRZrJRyluYZLXdrOIW58x2EuSy/vijP2MNH6W\
nTZO3QHl1b3A9zf0hSGfyG1se6wHfxaEjtFoZhu0aoWP9tyiKUXcICsRbENN5BfSm\
n9zSObn+2kOxbicgckoecSyeMWvqn1wkVEKvR+DscqJJOza4j4tkVhVDotQKBgQCX\
nJErBQNaeLCJuo+odmxBQbVg6dieEaygPgB5MFjBh74AqRXDQni0AjamF9Q28efu4\
nGW9dJFUNgUHOnBFJTNkCsnOwcr3B719oknwNS6gLCbfKyRzJjxRpfmYejSqyTarF\
nowQUsTIO1+GgpMndpHZMvg/c5HqBb2wtMzf/1+QrfQKBgEkrkiLtrShI6eX+jJpV\
ngytfQ7k+xRiuucx3u1SB2FmeYwDwiWfzg2AkE7ldrertWteWD8WXSP3Ujyh/Zwjn\
nJW2F0W9UI8BT7cHDuzZkqOeu3rQhNKPbpyHHczIFUFjBCSY51HIQmNHTRMIS4/Ym\
nXFjb8lvO5KvAmpNZfwp4V6KC\
n-----END PRIVATE KEY-----\n";

Adafruit_ST7789 display = Adafruit_ST7789(15, 5, 4);

#define bot 27
bool exemplo;

int temp;
#define resetar 5000

#define WPA2 0

#define EXAMPLE_EAP_METHOD 1

#define Username "Usuario do SUAP"
#define Password "Senha do SUAP"
#define Network "IFPB"

#define WIFI_SSID "Nomde rede convencional"
#define WIFI_PASSWORD "Senha da rede convencional"

#define USER_EMAIL "Email publico"
#define PROJECT_ID "esp-panilha"
#define CLIENT_EMAIL "esp-panilha-sa@esp-panilha.iam.gserviceaccount.com"

#define spreadsheetid "1Zq6QtXAT_hTgf-2GD40lWlqmuy1DG-v4jkdpNf-eN3M"
#define spreadsheetURL "https://docs.google.com/spreadsheets/d/1Zq6QtXAT_hTgf-2GD40lWlqmuy1DG-v4jkdpNf-eN3M/edit"

#define gmtOffset_sec -14400

int value1;
int value2;
String value3 = "";
String value4 = "";
int value5;
int value6;

File dados;

AsyncWebServer server(80);
bool discon = false;

String pagina(const String &var)
{
  if (var == "EEPROM")
  {
    return String(EEPROM.read(0));
  }
  return String();
}

void conectar()
{
#if WPA2
  WiFi.disconnect(true);
  WiFi.mode(WIFI_STA);
  ESP_LOGI(TAG, "Setting WiFi configuration SSID %s...", wifi_config.sta.ssid);
  ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
  ESP_ERROR_CHECK(esp_wifi_sta_wpa2_ent_set_username((uint8_t *)Username, strlen(Username)));
  ESP_ERROR_CHECK(esp_wifi_sta_wpa2_ent_set_password((uint8_t *)Password, strlen(Password)));
  esp_wifi_sta_wpa2_ent_enable();
  WiFi.begin(Network);
#else
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
#endif

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
    display.print(".");
  }
  Serial.println("Conectado");
  display.println("!");
}

void tokenStatusCallback(TokenInfo info)
{
  if (info.status == token_status_error)
  {
    GSheet.printf("Token info: type = %s, status = %s\n",
                  GSheet.getTokenType(info).c_str(),
                  GSheet.getTokenStatus(info).c_str());
    GSheet.printf("Token error: %s\n",
                  GSheet.getTokenError(info).c_str());
  }
  else
  {
    GSheet.printf("Token info: type = %s, status = %s\n",
                  GSheet.getTokenType(info).c_str(),
                  GSheet.getTokenStatus(info).c_str());
  }
}

void ini_panilha()
{
  GSheet.setTokenCallback(tokenStatusCallback);

  GSheet.setPrerefreshSeconds(10 * 60);

  GSheet.begin(CLIENT_EMAIL, PROJECT_ID, PRIVATE_KEY);

  while (!GSheet.ready())
    ;

  Serial.printf("Link da panilha: %s \n \n", spreadsheetURL);

  long int t = GSheet.getExpiredTimestamp();
  GSheet.setSystemTime(t gmtOffset_sec);

  display.println("Conectado");
}

void panilha()
{
  if ((WiFi.status() == WL_CONNECTED) && (GSheet.ready()) && (!discon))
  {
    while (EEPROM.read(3))
    {
      FirebaseJson response;
      FirebaseJson valueRange;

      valueRange.set("values/[0]/[0]", dados.readStringUntil(','));
      valueRange.set("values/[0]/[1]", dados.readStringUntil(','));
      valueRange.set("values/[0]/[2]", dados.readStringUntil(','));
      valueRange.set("values/[0]/[3]", dados.readStringUntil(','));
      valueRange.set("values/[0]/[4]", dados.readStringUntil(','));
      valueRange.set("values/[0]/[5]", dados.readStringUntil(','));
      valueRange.set("values/[0]/[6]", dados.readStringUntil(','));
      valueRange.set("values/[0]/[7]", dados.readStringUntil(','));

      EEPROM.write(4, EEPROM.read(4) + 8);

      bool success = GSheet.values.append(&response, spreadsheetid, "Dados!A1:I1000", &valueRange);
      if (!success)
      {
        Serial.printf("%s", GSheet.errorReason());
        display.println("ocorreu um erro ao enviar");
      }
      EEPROM.write(3, EEPROM.read(3) - 1);
      EEPROM.commit();
      Serial.println("Linha enviada");
    }
    if (EEPROM.read(3) == 0)
    {
      display.setCursor(0, 220);
      display.print("Enviado");
    }
  }
  else
  {
    display.setCursor(0, 205);
    display.print("Descon");
  }
}

void scan_redes()
{
  if (exemplo || !digitalRead(bot))
  {
    display.fillScreen(ST77XX_BLACK);
    display.setCursor(0, 0);
    Serial.println("botão pressionado");

    EEPROM.write(0, EEPROM.read(0) + 1);
    EEPROM.commit();

    File excel = SPIFFS.open("/dados.txt", FILE_APPEND);

    int n = WiFi.scanNetworks();

    display.printf("%d redes \n \n", n);

    Serial.printf("%d redes encontradas \n \
    Num | Rank | SSID                             | MAC               | RSSI | CH \n", n);
    for (int i = 0; i < n; ++i)
    {
      value1 = EEPROM.read(0);
      value2 = i + 1;
      value3 = WiFi.SSID(i);
      value4 = WiFi.BSSIDstr(i);
      value5 = WiFi.RSSI(i);
      value6 = WiFi.channel(i);

      struct tm timeinfo;
      getLocalTime(&timeinfo);
      excel.print(&timeinfo, "%d/%m/%Y,%H:%M:%S,");
      excel.print(String(value1) + "," + String(value2) + "," + value3 + "," + 
                  value4 + "," + String(value5) + "," + String(value6));
      excel.println(",");

      Serial.printf("%-3.3d", EEPROM.read(0));
      Serial.print(" |  ");
      Serial.printf("%2d", i + 1);
      Serial.print("  | ");
      Serial.printf("%-32.32s", WiFi.SSID(i).c_str());
      Serial.print(" | ");
      Serial.printf("%-17.17s", WiFi.BSSIDstr(i).c_str());
      Serial.print(" | ");
      Serial.printf("%4d", WiFi.RSSI(i));
      Serial.print(" | ");
      Serial.printf("%2d \n", WiFi.channel(i));
      EEPROM.write(3, EEPROM.read(3) + 1);
      EEPROM.commit();

      if (i == 0)
      {
        display.printf("%s,%d \n \n", WiFi.SSID(i), WiFi.RSSI(i));
        display.printf("%s,%d \n \n", WiFi.SSID(n - 1), WiFi.RSSI(n - 1));
        display.printf("Eeprom: %d \n", EEPROM.read(0));
      }
    }
    exemplo = false;
    excel.close();
    display.println("CSV pronto");
    Serial.println("CSV pronto");
  }
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
  Serial.printf("Eeprom: %d \n", EEPROM.read(0));
  display.printf("Eeprom: %d \n", EEPROM.read(0));

  conectar();
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/index.html", String(), false, pagina); });

  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/style.css", "text/css"); });

  server.on("/exemplo", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    exemplo = true;
    request->send(SPIFFS, "/index.html", String(), false, pagina); });

  server.on("/reset", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    File reset = SPIFFS.open("/dados.txt", FILE_WRITE);
    reset.print("");
    EEPROM.write(4, 0);
    EEPROM.write(3, 0);
    EEPROM.commit();
    Serial.println("csv resetado");
    display.println("csv resetado");
    request->send(SPIFFS, "/index.html", String(), false, pagina); });

  server.on("/print", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    dados = SPIFFS.open("/dados.txt");
    while (dados.available())
      Serial.write(dados.read());
    request->send(SPIFFS, "/index.html", String(), false, pagina); });

  server.on("/discon", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    if(!discon)
    {
      Serial.println("Desconectou");
      discon = true;
    }
    else
    {
      Serial.println("Reconectou");
      dados = SPIFFS.open("/dados.txt");
      for (int i = 1; i <= EEPROM.read(4); i++)
        dados.readStringUntil(',');
      discon = false;
    }
    request->send(SPIFFS, "/index.html", String(), false, pagina); });

  server.begin();

  ini_panilha();

  dados = SPIFFS.open("/dados.txt");
  while (dados.available())
    Serial.write(dados.read());

  dados = SPIFFS.open("/dados.txt");
  for (int i = 1; i <= EEPROM.read(4); i++)
    dados.readStringUntil(',');

  temp = millis();
  while (!digitalRead(bot))
    if (millis() - temp >= resetar)
    {
      File reset = SPIFFS.open("/dados.txt", FILE_WRITE);
      reset.print("");
      EEPROM.write(4, 0);
      EEPROM.write(3, 0);
      EEPROM.commit();
      Serial.println("csv resetado");
      display.println("csv resetado");
      delay(3000);
      break;
    }

  Serial.println("preparado");
}

void loop()
{
  scan_redes();
  panilha();
}