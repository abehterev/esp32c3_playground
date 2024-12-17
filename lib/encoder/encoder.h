#ifndef encoder_h
#define encoder_h

#include <Arduino.h>
#include <FunctionalInterrupt.h>

#define DEBOUNCE_DELAY 4
#define DEAD_INTERVAL 50

class Encoder
{
private:
    const uint8_t pinS1, pinS2, pinBtn;

    volatile  int64_t counter = 0;
    volatile  uint64_t clicks = 0;

    volatile unsigned long lastEncoderTimeS1 = 0;
    volatile unsigned long lastEncoderTimeS2 = 0;
    volatile unsigned long lastBtnTime = 0;

    volatile uint8_t last_state_S1 = 0;
    volatile uint8_t last_state_S2 = 0;

    volatile uint8_t gray_code = 0;
    volatile uint64_t e_counter = 0;

public:
    Encoder(uint8_t S1, uint8_t S2, uint8_t Btn) : pinS1(S1), pinS2(S2), pinBtn(Btn)
    {
        pinMode(pinS1, INPUT_PULLUP);
        pinMode(pinS2, INPUT_PULLUP);
        pinMode(pinBtn, INPUT_PULLUP);
    };

    ~Encoder();

    void init();
    void printStatus();

    void ARDUINO_ISR_ATTR onEncoderEvent();
    void ARDUINO_ISR_ATTR onClick();
};

#endif