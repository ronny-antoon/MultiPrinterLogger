#include <Arduino.h>
#include <MultiPrinterLogger.hpp>

void setup()
{
    // Initialize your desired output destinations (e.g., Serial, Serial1, etc.).
    Serial.begin(9600);

    // Get the instance of MultiPrinterLogger.
    MultiPrinterLogger &logger = MultiPrinterLogger::getInstance();

    // Add printers (output destinations).
    logger.addPrinter(&Serial);

    // Enable colored output (optional).
    logger.setColorEnabled(true);

    // Log messages at different log levels.
    logger.log(LogLevel::ERROR, "TAG", "This is an error message.");
    logger.log(LogLevel::WARNING, "TAG", "This is a warning message.");
    logger.log(LogLevel::INFO, "TAG", "This is an info message.");
    logger.log(LogLevel::DEBUG, "TAG", "This is a debug message.");
}

void loop()
{
    // Your main code here.
}