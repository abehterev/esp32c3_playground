#include "encoder.h"

Encoder::~Encoder()
{
    detachInterrupt(pinBtn);
    detachInterrupt(pinS1);
    detachInterrupt(pinS2);
}

uint8_t getGrayCode(uint8_t S1, uint8_t S2)
{
    return (S1 << 1) | S2;
}

void Encoder::onEncoderEvent()
{
    static bool start_flag = 0;
    uint64_t gpio = GPIO.in.val;
    uint32_t S1 = (gpio & (1 << pinS1)) ? 1 : 0;
    uint32_t S2 = (gpio & (1 << pinS2)) ? 1 : 0;

    gray_code = getGrayCode(S1, S2);
    if (gray_code == 0x03)
    {
        start_flag = 1;
        // Serial.println("-start-");
    }
    if (start_flag && gray_code == 0x01)
    {
        // Serial.println("-CW-");
        ++counter;
        start_flag = 0;
    }
    if (start_flag && gray_code == 0x02)
    {
        // Serial.println("-CCW-");
        --counter;
        start_flag = 0;
    }

    // Serial.printf("%llu - S1=%lu S2=%lu\n", ++e_counter, S1, S2);
}

void Encoder::onClick()
{
    unsigned long interruptTime = millis();

    if (interruptTime - lastBtnTime > DEBOUNCE_DELAY)
    {
        lastBtnTime = interruptTime;
        clicks++;
    }
}

void Encoder::init()
{
    attachInterrupt(digitalPinToInterrupt(pinS1), std::bind(&Encoder::onEncoderEvent, this), FALLING);
    attachInterrupt(digitalPinToInterrupt(pinS2), std::bind(&Encoder::onEncoderEvent, this), FALLING);
    attachInterrupt(digitalPinToInterrupt(pinBtn), std::bind(&Encoder::onClick, this), FALLING);
}

void Encoder::printStatus()
{
    static int64_t last_counter = 0;
    static uint64_t last_clicks = 0;

    if (last_counter != counter)
    {
        Serial.printf("CNT %lld\n", counter);
        last_counter = counter;
    }

    if (last_clicks != clicks)
    {
        Serial.printf("BTN %llu\n", clicks);
        last_clicks = clicks;
    }
}
