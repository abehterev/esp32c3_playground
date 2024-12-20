#include "display.h"

void display::mui_init()
{
    static muif_t muif_list[] = {
        MUIF_U8G2_FONT_STYLE(0, u8g2_font_helvR08_tr), /* define style 0 */
        MUIF_U8G2_LABEL(),                             /* allow MUI_LABEL command */
        MUIF_BUTTON("BN", mui_u8g2_btn_exit_wm_fi)     /* define exit button */
    };

    static fds_t fds_data[] =                /* Don't use comma between the commands! */
        MUI_FORM(1)                          /* This will start the definition of form 1 */
        MUI_STYLE(0)                         /* select the font defined with style 0 */
        MUI_LABEL(5, 15, "Hello U8g2")       /* place text at postion x=5, y=15 */
        MUI_XYT("BN", 64, 30, " Select Me ") /* place a button at pos x=64, y=30 */
        ;

    mui.begin(u8g2, fds_data, muif_list, sizeof(muif_list) / sizeof(muif_t));
    // mui.gotoForm(/* form_id= */ 1, /* initial_cursor_position= */ 0);
    Serial.println("mui ready");
}

void display::mui_loop(int enc, bool click)
{
    static bool is_redraw = true;

    if (click)
    {
        Serial.println("CL");
        if (!mui.isFormActive())
        {
            Serial.println("Run form");
            uint8_t res = mui.gotoForm(1, 0);
            Serial.printf("res: %llu\n", res);
        }
        else
        {
            mui.sendSelect();
        }
        is_redraw = 1;
    }

    if (enc > 0)
    {
        Serial.println("CW");
        mui.nextField();
        is_redraw = 1;
    }
    else if (enc < 0)
    {
        Serial.println("CCW");
        mui.prevField();
        is_redraw = 1;
    }

    if (mui.isFormActive())
    {
        if (is_redraw)
        {
            u8g2.clearBuffer();
            mui.draw();
            u8g2.sendBuffer();
            is_redraw = 0;
        }
    }
    else
    {
        u8g2.clearBuffer();
        u8g2.setCursor(0, 20);
        u8g2.print(millis());
        u8g2.sendBuffer();

        // mui.gotoForm(/* form_id= */ 1, /* initial_cursor_position= */ 0);
    }
}