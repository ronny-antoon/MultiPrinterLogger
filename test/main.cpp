#include <Arduino.h>
#include <gtest/gtest.h>

// TEST Files
#include "logTest.hpp"

// Classes for Testing
#include "API_MultiPrinterLogger.hpp"
#include "MultiPrinterLogger.hpp"

// Setup the test environment
// a.
void setup()
{
    Serial.begin(115200);
    delay(100);

    API_MultiPrinterLogger::begin(new MultiPrinterLogger());
    API_MultiPrinterLogger::addPrinter(&Serial);
    API_MultiPrinterLogger::setColorEnabled(true);

    ::testing::InitGoogleTest();
}

void loop()
{
    if (RUN_ALL_TESTS())
        ;

    delay(500);

    Serial.println("-----------------------------------Finished all tests!-----------------------------------");

    delay(10000);
}