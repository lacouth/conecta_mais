#include <esp_wifi.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <EEPROM.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);

#define bot 4

#define EXAMPLE_EAP_METHOD 1

#define Username "Usuario do SUAP"
#define Password "Senha do SUAP"
#define WiFi_SSID "IFPB"

String GOOGLE_SCRIPT_ID = "AKfycbx813D1hS-xJsyCSSmoB6FUBXTjHQp3cpBivmUzWWjzf1L3rdxsWv-j_JmKl_g4omCr";

int value1;
int value2;
String value3 = "";
String value4 = "";
int value5;
int value6;

void setup()
{
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Protocolo para iniciar o display
    display.setTextColor(WHITE);               // Colocando cor para o texto
    display.clearDisplay();                    // Limpando o display no inicio do loop

    pinMode(bot, INPUT_PULLUP);
    Serial.begin(115200);
    EEPROM.begin(12);
    //EEPROM.write(0, 0);
    //EEPROM.commit();
    Serial.println(EEPROM.read(0));
    WiFi.disconnect(true);
    WiFi.mode(WIFI_STA);
    ESP_LOGI(TAG, "Setting WiFi configuration SSID %s...", wifi_config.sta.ssid);
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_sta_wpa2_ent_set_username((uint8_t *)Username, strlen(Username)));
    ESP_ERROR_CHECK(esp_wifi_sta_wpa2_ent_set_password((uint8_t *)Password, strlen(Password)));
    esp_wifi_sta_wpa2_ent_enable();
    WiFi.begin(WiFi_SSID);

    display.println("conectando... ");
    display.print("EEPROM: ");
    display.println(EEPROM.read(0));
    display.display();

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("Conectado");
    display.print("Conectado");
    display.display();
}
void loop()
{
    if (WiFi.status() != WL_CONNECTED)
    {
        display.clearDisplay();  // Limpando o display no inicio do loop
        display.setCursor(0, 0); // Setando para todos iniciar no inicio da tela
        WiFi.reconnect();
        while (WiFi.status() != WL_CONNECTED)
        {
            delay(500);
            Serial.print(".");
            display.print(".");
            display.display();
        }
    }

    if (!digitalRead(bot))
    {
        display.clearDisplay();  // Limpando o display no inicio do loop
        display.setCursor(0, 0); // Setando para todos iniciar no inicio da tela
        Serial.println("botão pressionado");
        EEPROM.write(0, EEPROM.read(0) + 1);
        EEPROM.commit();
        int n = WiFi.scanNetworks();
        if (n == 0)
        {
            Serial.println("Nenhuma rede encontrada");
        }
        else
        {
            Serial.print(n);
            Serial.println(" redes encontradas");
            Serial.println("Num | Rank | SSID                             | MAC               | RSSI | CH");
            for (int i = 0; i < n; ++i)
            {
                value1 = EEPROM.read(0);
                value2 = i + 1;
                value3 = WiFi.SSID(i);
                value3.replace(" ", "+");
                value4 = WiFi.BSSIDstr(i);
                value5 = WiFi.RSSI(i);
                value6 = WiFi.channel(i);

                Serial.printf("%2d", EEPROM.read(0));
                Serial.print("  |  ");
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
                    // display.println();
                    display.print(WiFi.SSID(n - 1));
                    display.print(",");
                    display.println(WiFi.RSSI(n - 1));
                    display.println();
                    display.print("Eprom: ");
                    display.println(EEPROM.read(0));
                }

                sendData(String(value1) + "&value2=" + String(value2) + "&value3=" + value3 + "&value4=" + value4 + "&value5=" + String(value5) + "&value6=" + String(value6));
            }
            display.print("Aperte denovo");
            display.display();
            Serial.println("");
            Serial.println("Todos enviado, aperte denovo");
        }
    }
}

void sendData(String params)
{
    HTTPClient http;
    String url = "https://script.google.com/macros/s/" + GOOGLE_SCRIPT_ID + "/exec?value1=" + params;
    http.begin(url);
    int httpCode = http.GET();
    http.end();
    // Serial.println("Enviado");
}
