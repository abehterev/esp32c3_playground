#include <Arduino.h>
#include <U8g2lib.h>
#include <display.h>
#include <encoder.h>

const int encButtonPin = GPIO_NUM_2;
const int encS1Pin = GPIO_NUM_0;
const int encS2Pin = GPIO_NUM_1;

Encoder myEncoder(encS1Pin, encS2Pin, encButtonPin);

display myDisplay(U8G2_SH1106_128X64_NONAME_F_HW_I2C(U8G2_R0, SCL, SDA,
                                                     U8X8_PIN_NONE));

void setup() {
  Serial.begin(115200);
  int cnt = 0;
  while (!Serial) {
    ++cnt;
  }

  delay(1000);
  Serial.printf("cnt: %d\n");

  myEncoder.init();
  myDisplay.init();
  myDisplay.mui_init();

  Serial.println("init completed");
}

void loop() {
  int enc, speed = 0;
  bool click = false;

  std::tie(enc, speed) = myEncoder.Rotating();
  click = myEncoder.Clicking();

  myEncoder.loop();

  myDisplay.mui_loop(enc, click);
}