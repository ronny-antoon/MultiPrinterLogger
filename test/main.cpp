#include <Arduino.h>
#include "MultiPrinterLogger.hpp"
#include <gtest/gtest.h>

void setup()
{
    Serial.begin(115200);
    ::testing::InitGoogleTest();
}

TEST(ExampleTest, Test1)
{

    EXPECT_EQ(1, 1);
}

void loop()
{
    if (RUN_ALL_TESTS())
        ;

    delay(1000);

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

    Serial.println("-----------------------------------Finished all tests!-----------------------------------");

    delay(10000);
}