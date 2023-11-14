#include <Arduino.h>
#include "MultiPrinterLogger.hpp"
#include "Foo.hpp"

void setup()
{
    // Initialize your desired output destinations (e.g., Serial, Serial1, etc.).
    Serial.begin(115200);

    // Initialize the logger.
    MultiPrinterLogger *myLogger = new MultiPrinterLogger();
    myLogger->addPrinter(&Serial);
    myLogger->setLogLevel(MultiPrinterLogger::LogLevel::DEBUG);
    myLogger->setColorEnabled(true);

    // Create Foo object and DoSomething.
    Foo foo(myLogger);

    foo.doSomething();
}

void loop()
{
    // Your main code here.
}
