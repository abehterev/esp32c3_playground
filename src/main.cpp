#include <Arduino.h>
#include <U8g2lib.h>

#include <display.h>
// #include <scanner.h>
#include <encoder.h>

const int encButtonPin = GPIO_NUM_2;
const int encS1Pin = GPIO_NUM_0;
const int encS2Pin = GPIO_NUM_1;

// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// U8G2_SH1106_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* clock=*/SCL, /* data=*/SDA, /* reset=*/U8X8_PIN_NONE);
// U8G2_SH1106_128X64_NONAME_2_4W_SW_SPI u8g2(U8G2_R0, SCK, MISO, 3, 2);
// U8G2_SH1106_128X64_NONAME_1_4W_HW_SPI u8g2(U8G2_R0, 3, 2, 1);

// U8G2_ST7565_ERC12864_ALT_F_4W_HW_SPI u8g2(U8G2_R0, 2, 3, 1); - SPI display

// U8G2_ST7567_ENH_DG128064I_F_HW_I2C u8g2(U8G2_R2, SCL, SDA, U8X8_PIN_NONE);

// U8G2_ST7567_ENH_DG128064I_F_HW_I2C u8g2(U8G2_R2, SCL, SDA, U8X8_PIN_NONE);
// U8G2_ST7567_ENH_DG128064I_F_HW_I2C(U8G2_R2, SCL, SDA, U8X8_PIN_NONE)

display myDisplay(U8G2_SH1106_128X64_NONAME_F_HW_I2C(U8G2_R0, SCL, SDA, U8X8_PIN_NONE));

Encoder myEncoder(encS1Pin, encS2Pin, encButtonPin);

void setup()
{

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

  // delay(2000);

  // Serial.println("System ready");

  // i2c_scanner scanner;

  // scanner.scan();
}

void loop()
{

  static int width = 128;

  int enc, speed = 0;
  bool click = false;

  std::tie(enc, speed) = myEncoder.Rotating();
  click = myEncoder.Clicking();
  // myEncoder.printStatus();
  myEncoder.loop();

  // myDisplay.loop();

  // if (enc != 0 || click)
  // {
  //   Serial.printf("ENC: %d, CL: %d\n", enc, click);
  // }

  int shift = 0;
  switch (enc)
  {
  case abs(2):
    shift = enc * 5;
    break;
  case abs(3):
    shift = enc * 10;
    break;
  case abs(4):
    shift = enc * 20;
    break;

  default:
    shift = enc;
    break;
  }

  int new_width = width + shift;
  if (new_width > 128)
    new_width = 128;
  else if (new_width < 0)
    new_width = 0;

  width = new_width;

  // myDisplay.test_loop(width);
  myDisplay.mui_loop(enc, click);

  // delay(100);
}