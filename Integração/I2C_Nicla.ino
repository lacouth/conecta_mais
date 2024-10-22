#include <Wire.h>

#define esp_addr 9

#define tam_resp 5

void setup() {
  Wire.begin();

  Serial.begin(9600);

}

void loop() {
  delay(50);

  Serial.println("enviando data");
  Wire.beginTransmission(esp_addr);
  Wire.write(0);
  Wire.endTransmission();
  

  Serial.println("Recebendo data: ");

  Wire.requestFrom(esp_addr,tam_resp);

  String resposta = "";
  while(Wire.available())
  {
    char b = Wire.read();
    resposta += b;
  }

  Serial.println(resposta); 
}
