//* verificar_ambiente_quarto_modulo_light.cpp

#include <Arduino.h>
#include <WiFi.h>
#include "SPIFFS.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "RandomForestClassifier.h"
Eloquent::ML::Port::RandomForest regressor;

Adafruit_SSD1306 display(128, 64, &Wire, -1); // Objeto para o display usando a classe Adafruit_ST7789

#define bot 14 // Pinout para o botao fisico

int temp;            // Int para usar com o millis
#define resetar 5000 // Define de quanto tempo segurar o botao para reseta

int value1;
String value2 = "";
String value3 = "";
int value4;

#define macs 49

String z[] = {"00:13:46:BC:50:6A", "00:25:9C:35:93:E2", "00:26:5A:66:55:EF", "00:27:19:CA:71:D2", "18:0D:2C:7F:F5:9C", "18:D6:C7:F9:37:2F", "24:36:DA:2B:5E:C0", "24:36:DA:2B:5E:C2", "24:36:DA:2B:BC:00", "24:36:DA:2B:BC:02", "24:FD:0D:57:19:26", "24:FD:0D:57:19:27", "44:D2:44:DD:24:A5", "44:D2:44:DD:2C:C4", "44:D2:44:DD:2E:58", "44:D2:44:DD:32:40", "44:D2:44:DD:32:41", "44:D2:44:DD:32:49", "48:49:C7:EB:28:B4", "48:51:CF:81:B0:9E", "48:51:CF:81:B0:9F", "50:C7:BF:EF:56:8A", "58:10:8C:91:F3:AA", "64:66:B3:62:EB:86", "64:70:02:99:FE:F4", "7C:21:0D:84:EE:40", "7C:21:0D:84:EE:42", "84:F1:47:54:6B:80", "84:F1:47:54:6B:82", "84:F1:47:54:71:00", "84:F1:47:54:71:02", "84:F1:47:54:7F:20", "84:F1:47:54:7F:22", "84:F1:47:54:8B:A2", "84:F1:47:54:95:E0", "84:F1:47:54:95:E2", "84:F1:47:54:96:E0", "84:F1:47:54:96:E2", "84:F1:47:54:EB:20", "84:F1:47:54:EB:22", "84:F1:47:54:F9:80", "84:F1:47:54:F9:82", "84:F1:47:54:FD:C0", "84:F1:47:54:FD:C2", "B8:11:4B:1D:1E:40", "B8:11:4B:1D:1E:42", "E4:4E:2D:85:4C:60", "E4:4E:2D:85:4C:62", "E8:94:F6:B9:2F:46"};

int n;

File dados; // Arquivo que ler e reseta o CSV

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

// TODO: Funcao para resetar EEPROMs e o arquivo CSV
void reset()
{
  File reset = SPIFFS.open("/verificar.txt", FILE_WRITE);
  reset.print("");
  reset.close();
  display.setCursor(0, 64);
  display.println("CSV reset");
}

// TODO: Funcao para se conectar na rede wifi, pode ser com WPA2 ou sem
void conectar()
{
  WiFi.mode(WIFI_STA);
  WiFi.disconnect(true);
}

void verificar_ambiente()
{
  double x[macs] = {0.0};

  for (int i = 0; i < n; i++)
  {
    for (int f = 0; f <= macs; f++)
      if (WiFi.BSSIDstr(i) == z[f])
        x[f] = WiFi.RSSI(i);
    
    if (i == n - 1)
    {
      switch (regressor.predict(x))
      {
      case 0:
        value3 = "cod_eng";
        break;
      case 1:
        value3 = "fibra"; 
        break;
      case 2:
        value3 = "aferi";
        break;
      case 3:
        value3 = "aud";
        break;
      case 4:
        value3 = "biomedi"; 
        break;
      case 5:
        value3 = "med_tele"; 
        break;
      case 6:
        value3 = "pesq_eng"; 
        break;
      case 7:
        value3 = "prati";
        break;
      case 8:
        value3 = "telefo";
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
}

// TODO: Funcao principal, coleta dados das redes proximas e guarda no arquivo CSV
void scan_redes()
{
  if (!digitalRead(bot))
  {
    display.clearDisplay();  // Limpando o display no inicio do loop
    display.setCursor(0, 0);
    Serial.println("\nExemplo iniciado");

    File excel = SPIFFS.open("/verificar.txt", FILE_APPEND);

    n = WiFi.scanNetworks();

    display.printf("%d redes \n \n", n);
    display.printf("Num: %d \n \n", spiffs_num());

    Serial.printf("%d redes encontradas\n", n);

    verificar_ambiente();

    value1 = spiffs_num();

    excel.printf(",,%d,%s,%s,%d,\n",
                 value1, value2.c_str(), value3.c_str(), value4);

    Serial.printf("%-3s | %-32s | %-32s | %-1s\n",
                  "Num", "Ambiente", "Achado", "Acerto");

    Serial.printf("%3d | %-32.32s | %-32.32s | %1d \n",
                  value1, value2.c_str(), value3.c_str(), value4);
    spiffs_num(gravar, spiffs_num() + 1);       // atualizando quantos click no botao

    excel.close();
    display.println("\nCSV pronto");
    display.display();
    Serial.println("CSV pronto\n");
  }
}

void setup()
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Protocolo para iniciar o display
  display.setTextColor(WHITE);               // Colocando cor para o texto
  display.setRotation(2);
  display.clearDisplay();

  pinMode(bot, INPUT_PULLUP);

  Serial.begin(115200);
  SPIFFS.begin(true);

  Serial.printf("Num: %d \n", spiffs_num());
  display.printf("Num: %d \n", spiffs_num());

  conectar();

  dados = SPIFFS.open("/verificar.txt");
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
}
