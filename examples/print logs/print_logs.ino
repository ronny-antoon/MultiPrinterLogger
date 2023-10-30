#include <Arduino.h>

#include "API_MultiPrinterLogger.hpp" // Every where you want to use the logger.
#include "MultiPrinterLogger.hpp"     // Only in Initialize page (e.g., setup() function).
#include "Foo.hpp"                    //A class that uses the logger.

void setup()
{
    // Initialize your desired output destinations (e.g., Serial, Serial1, etc.).
    Serial.begin(115200);

    // Initialize the logger.
    API_MultiPrinterLogger::begin(new MultiPrinterLogger());
    API_MultiPrinterLogger::addPrinter(&Serial);
    API_MultiPrinterLogger::setColorEnabled(true);

    // Create Foo object and DoSomething.
    Foo foo;

    foo.doSomething();
}

void loop()
{
    // Your main code here.
}