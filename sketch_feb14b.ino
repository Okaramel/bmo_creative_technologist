#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>

#if defined(ARDUINO_FEATHER_ESP32) // Feather Huzzah32
  #define TFT_CS         14
  #define TFT_RST        15
  #define TFT_DC         32
#else
  // For the breakout board, you can use any 2 or 3 pins.
  // These pins will also work for the 1.8" TFT shield.
  #define TFT_CS        10
  #define TFT_RST        8 // Or set to -1 and connect to Arduino RESET pin
  #define TFT_DC         9
#endif

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
float p = 3.1415926;

uint16_t convertRGB(uint32_t hexColor) {
  uint8_t r = (hexColor >> 16) & 0xFF;
  uint8_t g = (hexColor >> 8) & 0xFF;
  uint8_t b = hexColor & 0xFF;
  return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
}

const int boutonPin = 1;  // Broche du bouton
const int boutonPin2 = 2;  // Broche du bouton
const int boutonPin3 = 3;  // Broche du bouton
const int boutonPin7 = 7;  // Broche du bouton

void setup(void) {

  pinMode(boutonPin2, INPUT_PULLUP);
  pinMode(boutonPin3, INPUT_PULLUP);
  pinMode(boutonPin, INPUT_PULLUP);
  pinMode(boutonPin7, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.print(F("Hello! ST77xx TFT Test"));

  // Use this initializer if using a 1.8" TFT screen:
  tft.initR(INITR_BLACKTAB);
}

void loop() {
  if (digitalRead(boutonPin7) == LOW) {
    uint16_t customColor = convertRGB(0xB5DFD8);
    tft.fillRoundRect(0, 0, 160, 160, 0, customColor);
    tft.fillRoundRect(0, 0, 160, 160, 0, customColor);
    tft.fillRoundRect(70, 25, 15, 15, 10, ST77XX_BLACK);
    tft.fillRoundRect(70, 100, 15, 15, 10, ST77XX_BLACK);
    tft.fillRoundRect(80, 33, 5, 5, 10, ST77XX_WHITE);
    tft.fillRoundRect(80, 107, 5, 5, 10, ST77XX_WHITE);
    tft.fillCircle(50, 70, 20, ST77XX_BLACK);
    tft.fillCircle(65, 70, 30, customColor);
  }
  if (digitalRead(boutonPin2) == LOW) {
    uint16_t customColor = convertRGB(0xB5DFD8);
    tft.fillRoundRect(0, 0, 160, 160, 0, customColor);
    tft.fillRoundRect(0, 0, 160, 160, 0, customColor);
    tft.fillRoundRect(70, 25, 15, 15, 10, ST77XX_BLACK);
    tft.fillRoundRect(70, 100, 15, 15, 10, ST77XX_BLACK);
    tft.fillRoundRect(80, 33, 5, 5, 10, ST77XX_WHITE);
    tft.fillRoundRect(80, 107, 5, 5, 10, ST77XX_WHITE);
    uint16_t customColor2 = convertRGB(0xDE5D83);
    tft.fillRoundRect(60, 10, 15, 15, 10, customColor2);
    tft.fillRoundRect(60, 115, 15, 15, 10, customColor2);
    tft.fillCircle(30, 70, 20, ST77XX_BLACK);
  } 
  
  if (digitalRead(boutonPin3) == LOW) {
    uint16_t customColor = convertRGB(0xB5DFD8);
    tft.fillRoundRect(0, 0, 160, 160, 0, customColor);
    tft.fillRoundRect(0, 0, 160, 160, 0, customColor);
    tft.fillRoundRect(70, 25, 15, 15, 10, ST77XX_BLACK);
    tft.fillRoundRect(70, 100, 15, 15, 10, ST77XX_BLACK);
    tft.fillRoundRect(80, 33, 5, 5, 10, ST77XX_WHITE);
    tft.fillRoundRect(80, 107, 5, 5, 10, ST77XX_WHITE);
    tft.fillRoundRect(40, 70, 15, 15, 7, ST77XX_BLACK);
  } 
  
  if (digitalRead(boutonPin) == LOW) {
    while (digitalRead(boutonPin) ==  LOW) {
      uint16_t customColor = convertRGB(0xB5DFD8);
      tft.fillRoundRect(0, 0, 160, 160, 0, customColor);
      tft.fillRoundRect(0, 0, 160, 160, 0, customColor);
      tft.fillRoundRect(70, 25, 15, 15, 10, ST77XX_BLACK);
      tft.fillRoundRect(70, 100, 15, 15, 10, ST77XX_BLACK);
      tft.fillRoundRect(80, 33, 5, 5, 10, ST77XX_WHITE);
      tft.fillRoundRect(80, 107, 5, 5, 10, ST77XX_WHITE);
      tft.fillCircle(50, 70, 20, ST77XX_BLACK);
      tft.fillCircle(65, 70, 30, customColor);
      delay(500);
      tft.fillRoundRect(0, 0, 160, 160, 0, customColor);
      tft.fillRoundRect(0, 0, 160, 160, 0, customColor);
      tft.fillRoundRect(70, 25, 15, 15, 10, ST77XX_BLACK);
      tft.fillRoundRect(70, 100, 15, 15, 10, ST77XX_BLACK);
      tft.fillRoundRect(80, 33, 5, 5, 10, ST77XX_WHITE);
      tft.fillRoundRect(80, 107, 5, 5, 10, ST77XX_WHITE);
      tft.fillCircle(30, 70, 20, ST77XX_BLACK);
      delay(500);
      tft.fillRoundRect(0, 0, 160, 160, 0, customColor);
      tft.fillRoundRect(0, 0, 160, 160, 0, customColor);
      tft.fillRoundRect(70, 25, 15, 15, 10, ST77XX_BLACK);
      tft.fillRoundRect(70, 100, 15, 15, 10, ST77XX_BLACK);
      tft.fillRoundRect(80, 33, 5, 5, 10, ST77XX_WHITE);
      tft.fillRoundRect(80, 107, 5, 5, 10, ST77XX_WHITE);
      tft.fillRoundRect(30, 50, 30, 40, 15, ST77XX_BLACK);
      delay(500);
    }
  }
}
