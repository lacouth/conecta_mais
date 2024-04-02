//* Identificar_camera

/**
 * Run Edge Impulse FOMO model.
 * It works on both PSRAM and non-PSRAM boards.
 * 
 * The difference from the PSRAM version
 * is that this sketch only runs on 96x96 frames,
 * while PSRAM version runs on higher resolutions too.
 * 
 * The PSRAM version can be found in my
 * "ESP32S3 Camera Mastery" course
 * at https://dub.sh/ufsDj93
 *
 * BE SURE TO SET "TOOLS > CORE DEBUG LEVEL = INFO"
 * to turn on debug messages
*/

#include <IF_PROJETO_inferencing.h> // precisa baixar a biblioteca do edge impulse
#include <eloquent_esp32cam.h>
#include <eloquent_esp32cam/edgeimpulse/fomo.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define I2C_SDA 15
#define I2C_SCL 14
TwoWire I2Cbus = TwoWire(0);

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &I2Cbus, OLED_RESET);

using eloq::camera;
using eloq::ei::fomo;

#define bot 12

void setup() {
  delay(3000);
  Serial.begin(115200);
  Serial.println("_EDGE IMPULSE FOMO (NO-PSRAM)_");

  // camera settings
  // replace with your own model!
  camera.pinout.aithinker();
  camera.brownout.disable();
  // NON-PSRAM FOMO only works on 96x96 (yolo) RGB565 images
  camera.resolution.yolo();
  camera.pixformat.rgb565();

  // init camera
  while (!camera.begin().isOk())
    Serial.println(camera.exception.toString());

  Serial.println("Camera OK");
  Serial.println("Put object in front of camera");

  I2Cbus.begin(I2C_SDA, I2C_SCL, 100000);

  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);

  pinMode(bot, INPUT_PULLUP);
}


void loop() {
  if (!digitalRead(bot)) {
    Serial.println("Botao pressionado");
    display.clearDisplay();
    display.setCursor(0, 0);

    // capture picture
    if (!camera.capture().isOk()) {
      Serial.println(camera.exception.toString());
      return;
    }

    // run FOMO
    if (!fomo.run().isOk()) {
      Serial.println(fomo.exception.toString());
      return;
    }

    // how many objects were found?
    Serial.printf(
      "Found %d object(s) in %dms\n",
      fomo.count(),
      fomo.benchmark.millis());

    display.printf(
      "%d objeto\nem %dms\n",
      fomo.count(),
      fomo.benchmark.millis());

    display.display();

    // if no object is detected, return
    if (!fomo.foundAnyObject())
      return;

    // if you expect to find a single object, use fomo.first
    Serial.printf(
      "Found %s at (x = %d, y = %d) (size %d x %d). "
      "Proba is %.2f\n",
      fomo.first.label,
      fomo.first.x,
      fomo.first.y,
      fomo.first.width,
      fomo.first.height,
      fomo.first.proba);
    
    display.printf("Sala:\n%s", fomo.first.label);
    display.display();
  }
}