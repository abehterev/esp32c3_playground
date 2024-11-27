#include <Arduino.h>
#include <U8g2lib.h>

#include <display.h>
// #include <scanner.h>


// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// U8G2_SH1106_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* clock=*/SCL, /* data=*/SDA, /* reset=*/U8X8_PIN_NONE);
// U8G2_SH1106_128X64_NONAME_2_4W_SW_SPI u8g2(U8G2_R0, SCK, MISO, 3, 2);
// U8G2_SH1106_128X64_NONAME_1_4W_HW_SPI u8g2(U8G2_R0, 3, 2, 1);

// U8G2_ST7565_ERC12864_ALT_F_4W_HW_SPI u8g2(U8G2_R0, 2, 3, 1); - SPI display

// U8G2_ST7567_ENH_DG128064I_F_HW_I2C u8g2(U8G2_R2, SCL, SDA, U8X8_PIN_NONE);

display myDisplay(U8G2_ST7567_ENH_DG128064I_F_HW_I2C(U8G2_R2, SCL, SDA, U8X8_PIN_NONE)); //U8G2_ST7567_ENH_DG128064I_F_HW_I2C u8g2(U8G2_R2, SCL, SDA, U8X8_PIN_NONE);

// void IRAM_ATTR onEncoderEvent() {
  
// }

void setup()
{

  Serial.begin(115200);

  delay(1000);

  Serial.println("Display test");

  // i2c_scanner scanner;

  // scanner.scan();

  myDisplay.init();


  delay(1000);
}



void loop()
{
  myDisplay.loop();
}