#include "display.h"

display::display(U8G2 display) { u8g2 = display; }

display::~display() {}

void display::init() {
  // u8g2.setI2CAddress(0x3F * 2);
  u8g2.setBusClock(400000);
  u8g2.begin();
  u8g2.setContrast(120);
  u8g2_prepare();
}

void display::test_loop(int w) {
  static int width = 0;
  if (width != w) {
    width = w;
    u8g2.clearBuffer();
    u8g2_prepare();
    draw_fill_pixels(width);
    u8g2.sendBuffer();
  }
}
