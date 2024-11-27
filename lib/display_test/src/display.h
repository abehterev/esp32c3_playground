#ifndef display_h
#define display_h

#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

class display
{
private:
    U8G2 *u8g2;

    uint8_t draw_state = 0;

    void u8g2_prepare(void);
    void u8g2_box_frame(uint8_t a);
    void u8g2_disc_circle(uint8_t a);
    void u8g2_r_frame(uint8_t a);
    void u8g2_string(uint8_t a);
    void u8g2_line(uint8_t a);
    void u8g2_triangle(uint8_t a);
    void u8g2_ascii_1();
    void u8g2_ascii_2();
    void u8g2_extra_page(uint8_t a);
    void u8g2_bitmap_overlay(uint8_t a);
    void u8g2_bitmap_modes(uint8_t transparent);
    void draw(void);

public:
    display(U8G2 *u8g2);
    ~display();

    void loop();
};


#endif