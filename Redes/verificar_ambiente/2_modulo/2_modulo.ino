//* verificar_ambiente_segundo_modulo.cpp

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

// Chave privada para se comunicar com a panilha
const char PRIVATE_KEY[] PROGMEM = "-----BEGIN PRIVATE KEY-----\nMIIEvgIBADANBgkqhkiG9w0BAQEFAASCBKgwggSkAgEAAoIBAQCIc81jMpnhtOE/\nC1nnM2+M84VW4tpZ6KH8Yv+NfLKKO8NguJs1PNaBchgpPCUYwOV4S7qyn0/5TwZW\n/47QuQq+PIdRXwSg2bRojXg78GfUm0xsCkkqsG52TI4e3yanPJyOYvamrgbyh4PH\nOlKM7Gvr2gTGPORWLN2AVv/oSwYAuWrOXuY9UiE0h4q92odlLPBPMCFwRQe+3ctS\nqtjnTIC3P39/MLcZjQHdP/KmEoUbBdUFeOIf/Hrogj60T61d+E4aKzR9WLcIGLMG\n4bA4cNjUH6EXsgVwHB3SHpLI3UCzDs3xhhIkiDHyLXs7Mqv+g8vFbKqKb2FqcBQ0\novB0iPN9AgMBAAECggEANMwJ9o4HuKuSVCCCQtFGIlW/jCTus8ctlkh/9TEArDf/\nmxcTBwBpR2DsNFhPSkqo/2jd7mtyOFb5bwQnMF/I5l7pRPTtB4f1JFdI5Hha1Ira\ngRthwCDQPPnWK9/QRvlO4lEsesXvbjw9IwNQGbMI9xM+sa2x9B4b/qKrFiihQ/np\nzu1g09NTGl7xhzD3pxe/pYDPQMyVl9HLiQlita+bCp/ehD0/GW1gTryQTCZaQwH4\n/+Fm4sLmwGOeVOP7qVLorgblMStisADqJaUtqCleAA+4844EW6uYFa8pyHiK1xiC\nIYr2HXvg84SYiKb3mNbJfYB185KvfcCkYRBJjsn1SQKBgQC+UFIeRfodnNzqNwkq\nQAn7DRHcfvM4JCKi4tql7z8mMskYtPf+W6whG1fNcFbCG224i4H0LVZqWslfyQCO\nVjOoHeZRU+TM2OItTpaIaT8hGkAAYOukB99Org6RWOyno45DoPM8OHlqMgksWVBc\nXZTEnv+BFAUlMg1vcEBRJBrqrwKBgQC3jGnxupuvN8eU74r4T69MG1O09y0zcbWc\nqs07zT6NJ1+YMiV3W1zFlFPFvYKtj+qHwIHlPnKFtUriRAZJhNhGHBgcpQkGmWFt\nKYK1Ju7x4awr1hnzjUSgH6X384U61Vvm1CqneoZJHplqJcp7ujqehKMywAEXNLq8\nK9tRKicfkwKBgQCvmYELudmcNT6JRZrJRyluYZLXdrOIW58x2EuSy/vijP2MNH6W\nTZO3QHl1b3A9zf0hSGfyG1se6wHfxaEjtFoZhu0aoWP9tyiKUXcICsRbENN5BfSm\n9zSObn+2kOxbicgckoecSyeMWvqn1wkVEKvR+DscqJJOza4j4tkVhVDotQKBgQCX\nJErBQNaeLCJuo+odmxBQbVg6dieEaygPgB5MFjBh74AqRXDQni0AjamF9Q28efu4\nGW9dJFUNgUHOnBFJTNkCsnOwcr3B719oknwNS6gLCbfKyRzJjxRpfmYejSqyTarF\nowQUsTIO1+GgpMndpHZMvg/c5HqBb2wtMzf/1+QrfQKBgEkrkiLtrShI6eX+jJpV\ngytfQ7k+xRiuucx3u1SB2FmeYwDwiWfzg2AkE7ldrertWteWD8WXSP3Ujyh/Zwjn\nJW2F0W9UI8BT7cHDuzZkqOeu3rQhNKPbpyHHczIFUFjBCSY51HIQmNHTRMIS4/Ym\nXFjb8lvO5KvAmpNZfwp4V6KC\n-----END PRIVATE KEY-----\n";

Adafruit_ST7789 display = Adafruit_ST7789(15, 5, 4); // Objeto para o display usando a classe Adafruit_ST7789

#define bot 14 // Pinout para o botao fisico

int temp;            // Int para usar com o millis
#define resetar 5000 // Define de quanto tempo segurar o botao para reseta
#define sem_rede 4000

/*
 * Esolha do Usuario se quer conectar com ou sem WPA2
 * 0 = Utilizar wifi sem protocolo WPA2 (rede dosmetica)
 * 1 = Utilizar wifi com protoclo WPA2 (rede empresariais)
 */
#define WPA2 1

#define Username "Usuario do Suap" //* Usuario para WPA2
#define Password "Senha do Suap"  //* Senha para WPA2
#define Network "IFPB"         //* SSID para WPA2

#define WIFI_SSID "Rede qualquer" //* SSID para rede (sem WPA2)
#define WIFI_PASSWORD "Senha de rede qualquer" //* Senha para rede (sem WPA2)

#define USER_EMAIL "Email publico"                                 //* Email com acesso a panilha
#define PROJECT_ID "esp-panilha"                                          // ID do projeto criado por Google API
#define CLIENT_EMAIL "esp-panilha-sa@esp-panilha.iam.gserviceaccount.com" // Email do projeto criado por Google API

#define spreadsheetid "1thu9vdt5Q-JO_svWjFQgUTNVKU3ixQdf5ewRSagYyzY"                                                    // ID da panilha
#define spreadsheetURL "https://docs.google.com/spreadsheets/d/1thu9vdt5Q-JO_svWjFQgUTNVKU3ixQdf5ewRSagYyzY/edit#gid=0" // Link para panilha

#define gmtOffset_sec -14400 // 3 horas negativos em segundos para regular o horario para nosso padrao
struct tm timeinfo;          // Variavel para horario e data

int value1;
String value2 = "";
String value3 = "";
int value4;

int x[50] = {0.0};
int i;
int n;

File dados; // Arquivo que ler e reseta o CSV

AsyncWebServer server(80); // Porta utilizada para pagina WEB
bool discon = false;       // Bool que controlar o envio de dados para panilha
bool exemplo;              // Bool para scan de redes na pagina web
String leitura = "";

#define ler 1    // Definicao de ler para os switchs das variaveis
#define gravar 2 // Definicao de gravar para os switchs das variaveis
/**
 * Funcao para guarda e ler o numero de clicks no botao
 * @param operacao Escolha entre guardar ou ler a variavel
 * @param valor Qual o valor que ira mudar caso for guardar
 */
int spiffs_num(int operacao = ler, int valor = 0)
{
  switch (operacao)
  {
  case ler:
  {
    File num_spi = SPIFFS.open("/num.txt");
    leitura = num_spi.readStringUntil(',');
    num_spi.close();
    break;
  }
  case gravar:
  {
    File num_spi = SPIFFS.open("/num.txt", FILE_WRITE);
    num_spi.printf("%d,", valor);
    num_spi.close();
    break;
  }
  default:
    break;
  }
  return leitura.toInt();
}

/**
 * Funcao para guarda e ler o numero de linhas para enviar
 * @param operacao Escolha entre guardar ou ler a variavel
 * @param valor Qual o valor que ira mudar caso for guardar
 */
int spiffs_linhas(int operacao = ler, int valor = 0)
{
  switch (operacao)
  {
  case ler:
  {
    File linhas_spi = SPIFFS.open("/linhas.txt");
    leitura = linhas_spi.readStringUntil(',');
    linhas_spi.close();
    break;
  }
  case gravar:
  {
    File linhas_spi = SPIFFS.open("/linhas.txt", FILE_WRITE);
    linhas_spi.printf("%d,", valor);
    linhas_spi.close();
    break;
  }
  default:
    break;
  }
  return leitura.toInt();
}

/**
 * Funcao para guarda e ler o numero de virgulas para pular
 * @param operacao Escolha entre guardar ou ler a variavel
 * @param valor Qual o valor que ira mudar caso for guardar
 */
int spiffs_virgulas(int operacao = ler, int valor = 0)
{
  switch (operacao)
  {
  case ler:
  {
    File virgulas_spi = SPIFFS.open("/virgulas.txt");
    leitura = virgulas_spi.readStringUntil(',');
    virgulas_spi.close();
    break;
  }
  case gravar:
  {
    File virgulas_spi = SPIFFS.open("/virgulas.txt", FILE_WRITE);
    virgulas_spi.printf("%d,", valor);
    virgulas_spi.close();
    break;
  }
  default:
    break;
  }
  return leitura.toInt();
}

// TODO: Funcao utilizada na pagina web, ela ler qual variavel a pagina queira mudar e envia
String pagina(const String &var)
{
  if (var == "Num")
    return String(spiffs_num());
    
  if (var == "value7")
    return value2;

  return String();
}

// TODO: Funcao para resetar EEPROMs e o arquivo CSV
void reset()
{
  File reset = SPIFFS.open("/verificar.txt", FILE_WRITE);
  reset.print("");
  reset.close();
  spiffs_virgulas(gravar);
  spiffs_linhas(gravar);
  Serial.printf("CSV resetado, Linhas: %d, Virgulas: %d \n", spiffs_linhas(), spiffs_virgulas());
  display.setCursor(0, 190);
  display.println("CSV reset");
}

// TODO: Funcao para se conectar na rede wifi, pode ser com WPA2 ou sem
void conectar()
{
#if WPA2
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
  temp = millis();
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
    display.print(".");
    /*
    if (millis() - temp >= sem_rede)
    {
      discon = true;
      break;
    }
    */
  }
  if (!discon)
  {
    Serial.println("Conectado");
    display.println("!");

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
      dados = SPIFFS.open("/verificar.txt");
      while (dados.available())
      {
        Serial.write(dados.read());
        //bytinho = dados.read();
      }
      //char palavra[2];
        //palavra[0] = bytinho;
        //palavra[1] = '\0';
        //printado = String(palavra);
      //Serial.println("\n");
      //Serial.print(printado);
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

    server.on("/enviar", HTTP_GET, [](AsyncWebServerRequest *request)
              {
      spiffs_linhas(gravar, spiffs_virgulas() / 9);
      spiffs_virgulas(gravar);
      request->send(SPIFFS, "/index.html", String(), false, pagina); });

    server.on("/enviar_numero", HTTP_POST, [](AsyncWebServerRequest *request)
              { 
      if (request->hasParam("numero", true)) 
      {
        int num_eeprom = request->arg("numero").toInt();
        spiffs_num(gravar, num_eeprom);
        
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
        value2 = request->arg("value7");
        Serial.print("Novo ambiente: ");
        Serial.println(value2);
      } 
      else 
        request->send(400, "text/plain", "Parametro 'area' ausente na solicitacao");
      request->send(SPIFFS, "/index.html", String(), false, pagina); });

    server.begin();
  }
}

// TODO: Funcao para em caso de erro com a panilha ele mostrar qual
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

// TODO: Funcao para iniciar a panilha
void ini_panilha()
{
  if (!discon)
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
}

// TODO: Funcao principal, envia dados coletados do CSV para panilha
void panilha()
{
  if ((WiFi.status() == WL_CONNECTED) && (GSheet.ready()) && (!discon))
  {
    while (spiffs_linhas() > 0) // se tiver linha para enviar entra no for
    {
      dados = SPIFFS.open("/verificar.txt");
      for (int i = 1; i <= spiffs_virgulas(); i++) // while para atualizar o cursor andando de virgula (motivo de contar virgula)
        dados.readStringUntil(',');

      FirebaseJson response;
      FirebaseJson valueRange;

      valueRange.set("values/[0]/[0]", dados.readStringUntil(',')); // Data
      valueRange.set("values/[0]/[1]", dados.readStringUntil(',')); // Hora
      valueRange.set("values/[0]/[2]", dados.readStringUntil(',')); // Num
      valueRange.set("values/[0]/[3]", dados.readStringUntil(',')); // Ambiente
      valueRange.set("values/[0]/[4]", dados.readStringUntil(',')); // Achado
      valueRange.set("values/[0]/[5]", dados.readStringUntil(',')); // Acerto

      bool success = GSheet.values.append(&response, spreadsheetid, "Dados!A:F", &valueRange); // dados enviados
      if (!success)                                                                            //! se tiver um erro sera mostrado no serial e notificado no display
      {
        Serial.printf("%s \n", GSheet.errorReason());
        display.println("ocorreu um erro ao enviar");
      }
      else
      {
        spiffs_virgulas(gravar, spiffs_virgulas() + 6); // sao 6 dados diferentes
        spiffs_linhas(gravar, spiffs_linhas() - 1);
        Serial.printf("Linha enviada, Linhas: %d, Virgulas: %d \n", spiffs_linhas(), spiffs_virgulas());
      }
    }
    if (spiffs_linhas() == 0)
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

int arvore()
{
  if (x[27] <= -32.5) 
  {
    Serial.println("rssi_27 encontrado");
    display.print("rssi_27, ");
    return 2;
  }
  else
  {

    if (x[17] <= -30.5)
    {
      Serial.println("rssi_17 encontrado");
      display.print("rssi_17, ");
      return 1;
    }

    else
    {
      if (x[4] <= -74.0)
      {
        Serial.println("rssi_4 encontrado 1");
        display.print("rssi_4 1, ");
        return 4;
      }

      else
      {
        if (x[4] <= -58.5)
        {
          Serial.println("rssi_4 encontrado 2");
          display.print("rssi_4 2, ");
          if (x[15] <= -45.5)
          {
            Serial.println("rssi_15 encontrado");
            display.print("rssi_15, ");
            return 4;
          }

          else
          {
            if (x[16] <= -91.5)
            {
              Serial.println("rssi_16 encontrado");
              display.print("rssi_16, ");
              if (x[29] <= -44.0)
              {
                Serial.println("rssi_29 encontrado");
                display.print("rssi_29, ");
                return 3;
              }

              else
              {
                return 5;
              }
            }

            else
            {
              return 3;
            }
          }
        }

        else
        {
          if (x[19] <= -24.5)
          {
            Serial.println("rssi_19 encontrado");
            display.print("rssi_19, ");
            if (x[4] <= -23.5)
            {
              Serial.println("rssi_4 encontrado 3");
              display.print("rssi_4 3, ");
              if (x[48] <= -73.0)
              {
                Serial.println("rssi_48 encontrado");
                display.print("rssi_48, ");
                return 3;
              }

              else
              {
                return 5;
              }
            }

            else
            {
              if (x[18] <= -35.5)
              {
                Serial.println("rssi_18 encontrado");
                display.print("rssi_18, ");
                return 1;
              }

              else
              {
                if (x[5] <= -31.0)
                {
                  Serial.println("rssi_5 encontrado");
                  display.print("rssi_5, ");
                  return 4;
                }

                else
                {
                  return 3;
                }
              }
            }
          }

          else
          {
            return 0;
          }
        }
      }
    }
  }
}

void verificar_ambiente()
{
  if (WiFi.BSSIDstr(i) == "84:F1:47:54:7F:20")
    x[27] = WiFi.RSSI(i);

  if (WiFi.BSSIDstr(i) == "48:51:CF:81:B0:9F")
    x[17] = WiFi.RSSI(i);

  if (WiFi.BSSIDstr(i) == "18:0D:2C:7F:F5:9C")
    x[4] = WiFi.RSSI(i);

  if (WiFi.BSSIDstr(i) == "44:D2:44:DD:32:49")
    x[15] = WiFi.RSSI(i);

  if (WiFi.BSSIDstr(i) == "48:51:CF:81:B0:9E")
    x[16] = WiFi.RSSI(i);

  if (WiFi.BSSIDstr(i) == "84:F1:47:54:8B:A0")
    x[29] = WiFi.RSSI(i);

  if (WiFi.BSSIDstr(i) == "58:10:8C:91:F3:AA")
    x[19] = WiFi.RSSI(i);

  if (WiFi.BSSIDstr(i) == "E4:4E:2D:85:4C:62")
    x[48] = WiFi.RSSI(i);

  if (WiFi.BSSIDstr(i) == "50:C7:BF:EF:56:8A")
    x[18] = WiFi.RSSI(i);

  if (WiFi.BSSIDstr(i) == "18:D6:C7:F9:37:2F")
    x[5] = WiFi.RSSI(i);

  if (i == n - 1)
  {
    switch (arvore())
    {
    case 0:
      value3 = "biomedicos";
      break;
    case 1:
      value3 = "didatica pratica";
      break;
    case 2:
      value3 = "grel";
      break;
    case 3:
      value3 = "fibra(frente)";
      break;
    case 4:
      value3 = "pratica(frente)"; 
      break;
    case 5:
      value3 = "telefo_f";
      break;
    default:
      break;
    }
    display.printf("\nSala: %s\n", value3);
    if (value3 == value2)
      value4 = 1;
    else
      value4 = 0;
  }
}

// TODO: Funcao principal, coleta dados das redes proximas e guarda no arquivo CSV
void scan_redes()
{
  if (exemplo || !digitalRead(bot))
  {
    display.fillScreen(ST77XX_BLACK);
    display.setCursor(0, 0);
    Serial.println("\nExemplo iniciado");

    File excel = SPIFFS.open("/verificar.txt", FILE_APPEND);

    for (i = 0; i < 50; ++i)
      x[i] = 0.0;

    n = WiFi.scanNetworks();

    display.printf("%d redes \n \n", n);
    display.printf("Num: %d \n \n", spiffs_num());

    Serial.printf("%d redes encontradas\n", n);

    for (i = 0; i < n; ++i)
    {
      verificar_ambiente();
    }
    value1 = spiffs_num();

    getLocalTime(&timeinfo);
    excel.print(&timeinfo, "%d/%m/%Y,%H:%M:%S,"); // formato para horario e data
    excel.printf("%d,%s,%s,%d,\n",
                 value1, value2.c_str(), value3.c_str(), value4);


    Serial.printf("%-3s | %-32s | %-32s | %-1s\n",
                  "Num", "Ambiente", "Achado", "Acerto");

    Serial.printf("%3d | %-32.32s | %-32.32s | %1d \n",
                  value1, value2.c_str(), value3.c_str(), value4);
    spiffs_linhas(gravar, spiffs_linhas() + 1); // atualizando quantidade de linhas em base da quantidade de redes
    spiffs_num(gravar, spiffs_num() + 1);       // atualizando quantos click no botao

    exemplo = false;
    excel.close();
    display.println("\nCSV pronto");
    Serial.println("CSV pronto\n");
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

  Serial.printf("Num: %d \n", spiffs_num());
  display.printf("Num: %d \n", spiffs_num());

  conectar();
  ini_panilha();

  dados = SPIFFS.open("/verificar.txt");
  //! caso nao tiver nada no csv, mas tiver no EEPROM de virgulas resetar
  if ((dados.available() == 0) && (spiffs_virgulas() > 0))
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
