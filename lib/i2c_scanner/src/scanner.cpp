#include "scanner.h"

i2c_scanner::i2c_scanner(/* args */)
{
    if (!Wire.available())
    {
        Wire.begin();
    }

    Serial.println("I2C Scanner");
    Serial.println("Scanning...");
}

i2c_scanner::~i2c_scanner()
{
}

void i2c_scanner::scan()
{

    byte error, address;

    for (address = 1; address < 127; address++)
    {

        Serial.printf("Address: 0x%02X...", address);

        Wire.beginTransmission(address);
        error = Wire.endTransmission();

        if (error == 0)
        {
            Serial.print("found");
        }
        else if (error == 4)
        {
            Serial.print("error");
        }
        else
        {
            Serial.print("not found");
        }
        Serial.println();
        Serial.flush();
        delay(100);
    }
}
