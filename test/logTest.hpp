#ifndef LOG_TEST_HPP
#define LOG_TEST_HPP

#include <Arduino.h>
#include <gtest/gtest.h>

#include "MultiPrinterLoggerInterface.hpp"
#include "MultiPrinterLogger.hpp"

/**
 * @brief Test fixture for MultiPrinterLogger class.
 *
 * This fixture sets up a MultiPrinterLogger instance with Serial as a printer for testing.
 */
class MultiPrinterLoggerTest : public ::testing::Test
{
protected:
    MultiPrinterLogger *myLogger; ///< Pointer to the MultiPrinterLogger instance for testing.
    uint32_t freeHeap;            ///< Initial free heap size before each test.

    /**
     * @brief Set up the test fixture.
     *
     * This method creates a new MultiPrinterLogger instance, adds Serial as a printer,
     * sets the log level to DEBUG, and enables colored output for testing.
     */
    void SetUp() override
    {
        freeHeap = ESP.getFreeHeap();
        myLogger = new MultiPrinterLogger();
        myLogger->addPrinter(&Serial);
        myLogger->setLogLevel(MultiPrinterLogger::LogLevel::DEBUG);
        myLogger->setColorEnabled(true);
    }

    /**
     * @brief Tear down the test fixture.
     *
     * This method deletes the MultiPrinterLogger instance and checks for memory leaks.
     */
    void TearDown() override
    {
        delete myLogger;
        if (ESP.getFreeHeap() != freeHeap)
            Serial.printf(" FAILED : Memory leak detected! %d bytes lost.\n", freeHeap - ESP.getFreeHeap());
    }
};

/**
 * @brief Test case for logging an error message.
 *
 * This test case logs an error message using the Log_Error macro
 * and expects the test to pass without errors.
 */
TEST_F(MultiPrinterLoggerTest, Log_Error_test)
{
    Log_Error(myLogger, "This is an error message.");
    EXPECT_EQ(1, 1);
    delay(500);
}

/**
 * @brief Test case for logging a warning message.
 *
 * This test case logs a warning message using the Log_Warning macro
 * and expects the test to pass without errors.
 */
TEST_F(MultiPrinterLoggerTest, Log_Warning_test)
{
    Log_Warning(myLogger, "This is a warning message.");
    EXPECT_EQ(1, 1);
    delay(500);
}

/**
 * @brief Test case for logging an info message.
 *
 * This test case logs an info message using the Log_Info macro
 * and expects the test to pass without errors.
 */
TEST_F(MultiPrinterLoggerTest, Log_Info_test)
{
    Log_Info(myLogger, "This is an info message.");
    EXPECT_EQ(1, 1);
    delay(500);
}

/**
 * @brief Test case for logging a debug message.
 *
 * This test case logs a debug message using the Log_Debug macro
 * and expects the test to pass without errors.
 */
TEST_F(MultiPrinterLoggerTest, Log_Debug_test)
{
    Log_Debug(myLogger, "This is a debug message.");
    EXPECT_EQ(1, 1);
    delay(500);
}

/**
 * @brief Test case for logging a verbos message.
 *
 * This test case logs a verbos message using the Log_Verbos macro
 * and expects the test to pass without errors.
 */
TEST_F(MultiPrinterLoggerTest, Log_Verbose_test)
{
    Log_Verbose(myLogger, "This is a verbos message.");
    EXPECT_EQ(1, 1);
    delay(500);
}

/**
 * @brief Test case for checking freeheap and min free heap after couple of logs.
 *
 * This test case logs a debug message using the Log_Debug macro
 *
 * and expects the test to pass without errors.
 */
TEST_F(MultiPrinterLoggerTest, Log_test_freeheap)
{
    Log_Verbose(myLogger, "This is a verbos message.");
    Log_Debug(myLogger, "This is a debug message.");
    Log_Info(myLogger, "This is an info message.");
    Log_Warning(myLogger, "This is a warning message.");
    Log_Error(myLogger, "This is an error message.");
    EXPECT_EQ(1, 1);
    delay(100);

    int m_maxFreeHeap = ESP.getMaxAllocHeap();
    int m_freeHeap = ESP.getFreeHeap();

    int count = 0;

    while (count < 5)
    {
        Log_Verbose(myLogger, "This is a verbos message.aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
        Log_Debug(myLogger, "This is a debug message.");
        Log_Info(myLogger, "This is an info message.");
        Log_Warning(myLogger, "This is a warning message.");
        Log_Error(myLogger, "This is an error message.");
        EXPECT_EQ(1, 1);
        delay(100);

        EXPECT_EQ(m_maxFreeHeap, ESP.getMaxAllocHeap());
        EXPECT_EQ(m_freeHeap, ESP.getFreeHeap());

        count++;
        delay(100);
    }
}

#endif // LOG_TEST_HPP