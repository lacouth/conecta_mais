//* html_projeto.cpp

// Inclsão de Bibliotecas
#include <Arduino.h>
#include <esp_wpa2.h>
#include <esp_wifi.h>
#include <WiFi.h>
#include "time.h"
#include "esp_sntp.h"
#include "AsyncTCP.h"
#include "ESPAsyncWebServer.h"
#include "SPIFFS.h"
#include <HTTPClient.h>
#include <ESP_Google_Sheet_Client.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <EEPROM.h>

// Chave privada para se comunicar com a panilha 
const char PRIVATE_KEY[] PROGMEM = "-----BEGIN PRIVATE KEY-----\nMIIEvgIBADANBgkqhkiG9w0BAQEFAASCBKgwggSkAgEAAoIBAQCIc81jMpnhtOE/\nC1nnM2+M84VW4tpZ6KH8Yv+NfLKKO8NguJs1PNaBchgpPCUYwOV4S7qyn0/5TwZW\n/47QuQq+PIdRXwSg2bRojXg78GfUm0xsCkkqsG52TI4e3yanPJyOYvamrgbyh4PH\nOlKM7Gvr2gTGPORWLN2AVv/oSwYAuWrOXuY9UiE0h4q92odlLPBPMCFwRQe+3ctS\nqtjnTIC3P39/MLcZjQHdP/KmEoUbBdUFeOIf/Hrogj60T61d+E4aKzR9WLcIGLMG\n4bA4cNjUH6EXsgVwHB3SHpLI3UCzDs3xhhIkiDHyLXs7Mqv+g8vFbKqKb2FqcBQ0\novB0iPN9AgMBAAECggEANMwJ9o4HuKuSVCCCQtFGIlW/jCTus8ctlkh/9TEArDf/\nmxcTBwBpR2DsNFhPSkqo/2jd7mtyOFb5bwQnMF/I5l7pRPTtB4f1JFdI5Hha1Ira\ngRthwCDQPPnWK9/QRvlO4lEsesXvbjw9IwNQGbMI9xM+sa2x9B4b/qKrFiihQ/np\nzu1g09NTGl7xhzD3pxe/pYDPQMyVl9HLiQlita+bCp/ehD0/GW1gTryQTCZaQwH4\n/+Fm4sLmwGOeVOP7qVLorgblMStisADqJaUtqCleAA+4844EW6uYFa8pyHiK1xiC\nIYr2HXvg84SYiKb3mNbJfYB185KvfcCkYRBJjsn1SQKBgQC+UFIeRfodnNzqNwkq\nQAn7DRHcfvM4JCKi4tql7z8mMskYtPf+W6whG1fNcFbCG224i4H0LVZqWslfyQCO\nVjOoHeZRU+TM2OItTpaIaT8hGkAAYOukB99Org6RWOyno45DoPM8OHlqMgksWVBc\nXZTEnv+BFAUlMg1vcEBRJBrqrwKBgQC3jGnxupuvN8eU74r4T69MG1O09y0zcbWc\nqs07zT6NJ1+YMiV3W1zFlFPFvYKtj+qHwIHlPnKFtUriRAZJhNhGHBgcpQkGmWFt\nKYK1Ju7x4awr1hnzjUSgH6X384U61Vvm1CqneoZJHplqJcp7ujqehKMywAEXNLq8\nK9tRKicfkwKBgQCvmYELudmcNT6JRZrJRyluYZLXdrOIW58x2EuSy/vijP2MNH6W\nTZO3QHl1b3A9zf0hSGfyG1se6wHfxaEjtFoZhu0aoWP9tyiKUXcICsRbENN5BfSm\n9zSObn+2kOxbicgckoecSyeMWvqn1wkVEKvR+DscqJJOza4j4tkVhVDotQKBgQCX\nJErBQNaeLCJuo+odmxBQbVg6dieEaygPgB5MFjBh74AqRXDQni0AjamF9Q28efu4\nGW9dJFUNgUHOnBFJTNkCsnOwcr3B719oknwNS6gLCbfKyRzJjxRpfmYejSqyTarF\nowQUsTIO1+GgpMndpHZMvg/c5HqBb2wtMzf/1+QrfQKBgEkrkiLtrShI6eX+jJpV\ngytfQ7k+xRiuucx3u1SB2FmeYwDwiWfzg2AkE7ldrertWteWD8WXSP3Ujyh/Zwjn\nJW2F0W9UI8BT7cHDuzZkqOeu3rQhNKPbpyHHczIFUFjBCSY51HIQmNHTRMIS4/Ym\nXFjb8lvO5KvAmpNZfwp4V6KC\n-----END PRIVATE KEY-----\n";

Adafruit_ST7789 display = Adafruit_ST7789(15, 5, 4); // Objeto para o display usando a classe Adafruit_ST7789

#define bot 27 // Pinout para o botao fisico

int temp; // Int para usar com o millis 
#define resetar 5000 // Define de quanto tempo segurar o botao para resetar

/*
 * Esolha do Usuario se quer conectar com ou sem WPA2
 * 0 = Utilizar wifi sem protocolo WPA2 (rede dosmetica)
 * 1 = Utilizar wifi com protoclo WPA2 (rede empresariais)
*/
#define WPA2 0

#define EXAMPLE_EAP_METHOD 1 //? veio para se conectar com WPA2 mas sem testes se precisa ou nao

#define Username "Usuario do SUAP" //* Usuario para WPA2
#define Password "Senha do SUAP" //* Senha para WPA2
#define Network "IFPB" //* SSID para WPA2

#define WIFI_SSID "Rede" //* SSID para rede (sem WPA2)
#define WIFI_PASSWORD "Senha" //* Senha para rede (sem WPA2)

#define USER_EMAIL "Email Publico" //* Email com acesso a panilha
#define PROJECT_ID "esp-panilha" // ID do projeto criado por Google API
#define CLIENT_EMAIL "esp-panilha-sa@esp-panilha.iam.gserviceaccount.com" // Email do projeto criado por Google API 

#define spreadsheetid "1Zq6QtXAT_hTgf-2GD40lWlqmuy1DG-v4jkdpNf-eN3M" // ID da panilha
#define spreadsheetURL "https://docs.google.com/spreadsheets/d/1Zq6QtXAT_hTgf-2GD40lWlqmuy1DG-v4jkdpNf-eN3M/edit" // Link para panilha 

#define gmtOffset_sec -14400 // 3 horas negativos em segundos para regular o horario para nosso padrao
struct tm timeinfo; // Variavel para horario e data

String value1 = ""; // Numero de clicks no botao, NUM
int value2;         // Ranque da rede mais forte para mais fraca, Rank
String value3 = ""; // Nome da rede, RSSID
String value4 = ""; // Endereco unico, MAC
int value5;         // Potencia da rede, RSSI
int value6;         // Canal utilizado, CH
String value7 = ""; // Local escaneado, Area

File dados; // Arquivo que ler e reseta o CSV

#define eeprom_num 0 // Local da memoria para Num na EEPROM
#define eeprom_linhas 3 // Local da memoria para linhas na EEPROM
#define eeprom_virgulas 4 // Local da memoria para virgulas na EEPROM

AsyncWebServer server(80); // Porta utilizada para pagina WEB
bool discon = false; // Bool que controlar o envio de dados para panilha
bool exemplo; // Bool para scan de redes na pagina web
int linhas; // Int para complementar metodo de linhas para enviar 
int virgulas; // Int para complementar metodo de virgulas puladas

//TODO: Funcao utilizada na pagina web, ela ler qual variavel a pagina queira mudar e envia
String pagina(const String &var)
{
  if (var == "Num")
  {
    return String(EEPROM.read(eeprom_num));
  }
  if (var == "value7")
  {
    return value7;
  }
  return String();
}

//TODO: Funcao para resetar EEPROMs e o arquivo CSV
void reset()
{
  File reset = SPIFFS.open("/dados.txt", FILE_WRITE);
  reset.print("");
  EEPROM.write(4, 0);
  EEPROM.write(3, 0);
  EEPROM.commit();
  Serial.printf("CSV resetado, Linhas: %d, Virgulas: %d \n", EEPROM.read(eeprom_linhas), EEPROM.read(eeprom_virgulas));
  display.println("CSV resetado");
}

//TODO: Funcao para se conectar na rede wifi, pode ser com WPA2 ou sem
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

//TODO: Funcao para em caso de erro com a panilha ele mostrar qual
void tokenStatusCallback(TokenInfo info)
{
  if (info.status == token_status_error)
  {
    GSheet.printf("Token info: type = %s, status = %s\n", GSheet.getTokenType(info).c_str(), GSheet.getTokenStatus(info).c_str());
    GSheet.printf("Token error: %s\n", GSheet.getTokenError(info).c_str());
  }
  else
  {
    GSheet.printf("Token info: type = %s, status = %s\n", GSheet.getTokenType(info).c_str(), GSheet.getTokenStatus(info).c_str());
  }
}

//TODO: Funcao para iniciar a panilha
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

  display.println("Sicronizado");
}

//TODO: Funcao principal, envia dados coletados do CSV para panilha
void panilha()
{
  if ((WiFi.status() == WL_CONNECTED) && (GSheet.ready()) && (!discon))
  {
    linhas = EEPROM.read(eeprom_linhas);
    for (int i = 0; i < linhas; i++) // se tiver linha para enviar entra no for 
    {
      if (i == 0) // atualiza os EEPROM e as virgulas
      {
        virgulas = EEPROM.read(eeprom_virgulas);
        EEPROM.write(eeprom_linhas, 0);
        EEPROM.write(eeprom_virgulas, EEPROM.read(eeprom_virgulas) + linhas * 9);
        EEPROM.commit();
      }
      dados = SPIFFS.open("/dados.txt"); 
      for (int i = 1; i <= virgulas; i++) // while para atualizar o cursor andando de virgula (motivo de contar virgula)
        dados.readStringUntil(',');

      FirebaseJson response;
      FirebaseJson valueRange;

      valueRange.set("values/[0]/[0]", dados.readStringUntil(',')); // Data
      valueRange.set("values/[0]/[1]", dados.readStringUntil(',')); // Hora
      valueRange.set("values/[0]/[2]", dados.readStringUntil(',')); // Num
      valueRange.set("values/[0]/[3]", dados.readStringUntil(',')); // Rank
      valueRange.set("values/[0]/[4]", dados.readStringUntil(',')); // SSID
      valueRange.set("values/[0]/[5]", dados.readStringUntil(',')); // MAC
      valueRange.set("values/[0]/[6]", dados.readStringUntil(',')); // RSSI
      valueRange.set("values/[0]/[7]", dados.readStringUntil(',')); // CH
      valueRange.set("values/[0]/[8]", dados.readStringUntil(',')); // Area

      virgulas += 9; // sao 9 dados diferentes

      bool success = GSheet.values.append(&response, spreadsheetid, "Dados!A:J", &valueRange); // dados enviados
      if (!success) //! se tiver um erro sera mostrado no serial e notificado no display
      {
        Serial.printf("%s", GSheet.errorReason());
        display.println("ocorreu um erro ao enviar");
      }
      Serial.printf("Linha enviada, Linhas: %d, Virgulas: %d \n", i, virgulas);
    }
    if (linhas == 0)
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

//TODO: Funcao principal, coleta dados das redes proximas e guarda no arquivo CSV
void scan_redes()
{
  if (exemplo || !digitalRead(bot))
  {
    display.fillScreen(ST77XX_BLACK);
    display.setCursor(0, 0);
    Serial.println("botão pressionado");

    File excel = SPIFFS.open("/dados.txt", FILE_APPEND);

    int n = WiFi.scanNetworks();

    display.printf("%d redes \n \n", n);

    Serial.printf("%d redes encontradas\n", n);
    Serial.printf("%-3s | %-4s | %-32s | %-17s | %-4s | %-2s | %-4s\n",
                  "Num", "Rank", "SSID", "MAC", "RSSI", "CH", "Area");
    for (int i = 0; i < n; ++i)
    {
      if (i == 0)
      {
        display.printf("%s,%d \n \n", WiFi.SSID(i), WiFi.RSSI(i));
        display.printf("%s,%d \n \n", WiFi.SSID(n - 1), WiFi.RSSI(n - 1));
        display.printf("Num: %d \n", EEPROM.read(eeprom_num));
      }

      value1 = EEPROM.read(eeprom_num);
      value2 = i + 1;
      value3 = WiFi.SSID(i);
      value4 = WiFi.BSSIDstr(i);
      value5 = WiFi.RSSI(i);
      value6 = WiFi.channel(i);

      getLocalTime(&timeinfo);
      excel.print(&timeinfo, "%d/%m/%Y,%H:%M:%S,"); //formato para horario e data
      excel.printf("%s,%d,%s,%s,%d,%d,%s,\n", 
                    value1, value2, value3.c_str(), value4.c_str(), value5, value6, value7);

      Serial.printf("%-3.3s | %4d | %-32.32s | %-17.17s | %4d | %2d | %4s \n",
                    value1, value2, value3.c_str(), value4.c_str(), value5, value6, value7);
    }
    EEPROM.write(eeprom_linhas, EEPROM.read(eeprom_linhas) + n); // atualizando quantidade de linhas em base da quantidade de redes
    EEPROM.write(eeprom_num, EEPROM.read(eeprom_num) + 1); // atualizando quantos click no botao
    EEPROM.commit();
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
  Serial.printf("Num: %d \n", EEPROM.read(eeprom_num));
  display.printf("Num: %d \n", EEPROM.read(eeprom_num));

  conectar();
  Serial.println(WiFi.localIP());
  display.println(WiFi.localIP());

  // Configurando paginas e css, cada botao no html vai para uma subpagina
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
      reset();
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
        discon = false;
      }
      request->send(SPIFFS, "/index.html", String(), false, pagina); });

  server.on("/enviar_numero", HTTP_POST, [](AsyncWebServerRequest *request)
            { 
      if (request->hasParam("numero", true)) 
      {
        int num_eeprom = request->arg("numero").toInt();
        EEPROM.write(0, num_eeprom);
        EEPROM.commit();

        Serial.print("Novo num: ");
        Serial.println(num_eeprom);
      } 
      else 
        request->send(400, "text/plain", "Parametro 'numero' ausente na solicitacao");
      request->send(SPIFFS, "/index.html", String(), false, pagina); });

  server.on("/enviar_value7", HTTP_POST, [](AsyncWebServerRequest *request)
            { 
      if (request->hasParam("value7", true)) 
      {
        value7 = request->arg("value7");
        Serial.print("Nova area: ");
        Serial.println(value7);
      } 
      else 
        request->send(400, "text/plain", "Parametro 'area' ausente na solicitacao");
      request->send(SPIFFS, "/index.html", String(), false, pagina); });

  server.begin();

  ini_panilha();

  dados = SPIFFS.open("/dados.txt");
  //! caso nao tiver nada no csv, mas tiver no EEPROM de virgulas resetar
  if ((dados.available() == 0) && (EEPROM.read(eeprom_virgulas) > 0))
    reset();
  while (dados.available())
    Serial.write(dados.read());

  temp = millis();
  while (!digitalRead(bot)) // Metodo para resetar pelo jeito fisico (segurar o botao ao iniciar)
    if (millis() - temp >= resetar)
    {
      reset();
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