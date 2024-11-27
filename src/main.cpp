#include <Arduino.h>
#include <U8g2lib.h>

#include <display.h>
#include <scanner.h>

// #include <Adafruit_GFX.h>
// #include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// U8G2_SH1106_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* clock=*/SCL, /* data=*/SDA, /* reset=*/U8X8_PIN_NONE);
// U8G2_SH1106_128X64_NONAME_2_4W_SW_SPI u8g2(U8G2_R0, SCK, MISO, 3, 2);
// U8G2_SH1106_128X64_NONAME_1_4W_HW_SPI u8g2(U8G2_R0, 3, 2, 1);
// U8G2_ST7567_JLX12864_1_HW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);
//  U8G2_ST7567_ENH_DG128064I_1_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);

// U8G2_SH1106_128X64_NONAME_2_4W_SW_SPI(const u8g2_cb_t *rotation, uint8_t clock, uint8_t data, uint8_t cs, uint8_t dc, uint8_t reset = U8X8_PIN_NONE)
// U8G2_ST7565_EA_DOGM128_F_4W_HW_SPI(const u8g2_cb_t *rotation, uint8_t cs, uint8_t dc, uint8_t reset = U8X8_PIN_NONE)

// U8G2_ST7565_ERC12864_ALT_F_4W_HW_SPI u8g2(U8G2_R0, 2, 3, 1); - SPI display

U8G2_ST7567_ENH_DG128064I_F_HW_I2C u8g2(U8G2_R2, SCL, SDA, U8X8_PIN_NONE);

// display myDisplay(&u8g2);

// void IRAM_ATTR onEncoderEvent() {
  
// }

void setup()
{

  Serial.begin(115200);

  delay(1000);

  Serial.println("Display test");

  i2c_scanner scanner;

  scanner.scan();

  delay(1000);
}



void loop()
{
  // myDisplay.loop();
  // delay(300);
}