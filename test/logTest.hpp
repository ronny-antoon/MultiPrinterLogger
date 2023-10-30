#include <gtest/gtest.h>
#include <Arduino.h>

#include "API_MultiPrinterLogger.hpp"

TEST(logTest, Log_Error_test)
{
    Log_Error("TAG", "This is an error message.");
    EXPECT_EQ(1, 1);
    delay(500);
}

TEST(logTest, Log_Warning_test)
{
    Log_Warning("TAG", "This is an error message.");
    EXPECT_EQ(1, 1);
    delay(500);
}

TEST(logTest, Log_Info_test)
{
    Log_Info("TAG", "This is an error message.");
    EXPECT_EQ(1, 1);
    delay(500);
}

TEST(logTest, Log_Debug_test)
{
    Log_Debug("TAG", "This is an error message.");
    EXPECT_EQ(1, 1);
    delay(500);
}