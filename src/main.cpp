#include <Arduino.h>

#include <MultiPrinterLogger.hpp>
#include <MultiPrinterLoggerInterface.hpp>

void setup()
{
    Serial.begin(115200);
    Serial.println("Start");

    Serial.printf("[%.0f]Minimum heap that has ever been available: %d\n\r", (esp_timer_get_time() / 1000ULL / 1000ULL), esp_get_minimum_free_heap_size());
    Serial.printf("Before Initialize logger, free heap: %d\n\r", esp_get_free_heap_size());

    MultiPrinterLogger *myLogger = new MultiPrinterLogger();
    myLogger->addPrinter(&Serial);
    myLogger->setLogLevel(MultiPrinterLoggerInterface::LogLevel::VERBOSE);
    myLogger->setColorEnabled(true);

    Log_Info(myLogger, "First Log_Info message.");
    Log_Verbose(myLogger, "First Log_Verbose message.");
    Log_Debug(myLogger, "First Log_Debug message.");
    Log_Warning(myLogger, "First Log_Warning message.");
    Log_Error(myLogger, "First Log_Error message.");

    Serial.printf("Minimum heap that has ever been available: %d\n\r", esp_get_minimum_free_heap_size());
    Serial.printf("After Initialize logger, free heap: %d\n\r", esp_get_free_heap_size());

    delete myLogger;

    Serial.printf("Minimum heap that has ever been available: %d\n\r", esp_get_minimum_free_heap_size());
    Serial.printf("After Delete logger, free heap: %d\n\r", esp_get_free_heap_size());
}

void loop()
{
    delay(1000);
}