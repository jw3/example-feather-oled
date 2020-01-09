#include <Particle.h>
#include <Adafruit_SSD1306.h>

SYSTEM_MODE(MANUAL)

const uint8_t DownArrow[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00,
                             0x18, 0x00, 0x00, 0x18, 0x00, 0x0c, 0x18, 0x30, 0x0e, 0x18, 0x70, 0x07, 0x18, 0xe0, 0x03, 0x99, 0xc0, 0x01, 0xdb, 0x80, 0x00, 0xff, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x3c,
                             0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

const uint8_t UpArrow[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x7e, 0x00, 0x00, 0xff, 0x00, 0x01, 0xdb, 0x80, 0x03,
                           0x99, 0xc0, 0x07, 0x18, 0xe0, 0x0e, 0x18, 0x70, 0x0c, 0x18, 0x30, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18,
                           0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

void paintComponent(Adafruit_SSD1306& tft) {
   tft.clearDisplay();
   tft.drawCircle(40, 10, 3, 1);
   tft.drawCircle(50, 10, 3, 1);
   tft.drawCircle(60, 10, 3, 1);
   tft.drawCircle(70, 10, 3, 1);
   tft.drawCircle(80, 10, 3, 1);
   tft.drawCircle(90, 10, 3, 1);
   tft.drawCircle(100, 10, 3, 1);
   tft.drawCircle(110, 10, 3, 1);
   tft.setCursor(30, 21);

   // status
   tft.fillCircle(110, 10, 3, 1);
   tft.print(" 1234");
   tft.print("/53400");
   tft.drawBitmap(5, 5, DownArrow, 24, 24, 1);
   // end status

   tft.display();
}


Adafruit_SSD1306 tft(128, 32);
void setup() {
   // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
   // Address 0x3C for 128x32
   tft.begin(SSD1306_SWITCHCAPVCC, 0x3C);

   tft.setTextColor(WHITE);
   tft.setTextSize(1);
}


long last = 0;
void loop() {
   if(millis() - last > 1000) {
      paintComponent(tft);
      last = millis();
   }
}
