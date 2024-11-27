#ifndef scanner_h
#define scanner_h

#include <Arduino.h>
#include <Wire.h>

class i2c_scanner
{
private:
    /* data */
public:
    i2c_scanner(/* args */);
    ~i2c_scanner();

    void scan();
};

#endif