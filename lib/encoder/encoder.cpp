#include "encoder.h"

Encoder::~Encoder()
{
    detachInterrupt(pinBtn);
    detachInterrupt(pinS1);
    detachInterrupt(pinS2);
}

void Encoder::onEncoderS1()
{
    unsigned long interruptTime = millis();

    if (interruptTime - lastEncoderTimeS1 > DEBOUNCE_DELAY && last_state_S1 == 0)
    {
        lastEncoderTimeS1 = interruptTime;
        last_state_S1 = 1;

        if (last_state_S2)
        {
            counter--;
            Serial.printf("CCW");
            last_state_S1 = last_state_S2 = 0;
        }
    }
}

void Encoder::onEncoderS2()
{
    unsigned long interruptTime = millis();

    if (interruptTime - lastEncoderTimeS2 > DEBOUNCE_DELAY && last_state_S2 == 0)
    {
        lastEncoderTimeS2 = interruptTime;
        last_state_S2 = 1;

        if (last_state_S1)
        {
            counter++;
            Serial.printf("CW");
            last_state_S1 = last_state_S2 = 0;
        }
    }
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
    attachInterrupt(digitalPinToInterrupt(pinS1), std::bind(&Encoder::onEncoderS1, this), FALLING);
    attachInterrupt(digitalPinToInterrupt(pinS2), std::bind(&Encoder::onEncoderS2, this), FALLING);
    attachInterrupt(digitalPinToInterrupt(pinBtn), std::bind(&Encoder::onClick, this), FALLING);
}

void Encoder::printStatus()
{
    static int64_t last_counter = 0;
    if (last_counter != counter)
    {
        Serial.printf("CNT %lld\n", counter);
        last_counter = counter;
    }
}