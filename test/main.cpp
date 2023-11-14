#include <Arduino.h>
#include <gtest/gtest.h>

// TEST Files
#include "logTest.hpp"

/**
 * @brief Arduino setup function.
 *
 * This function initializes Serial communication and initializes Google Test.
 */
void setup()
{
    Serial.begin(115200);
    ::testing::InitGoogleTest();
}

/**
 * @brief Arduino loop function.
 *
 * This function runs all Google Test cases and prints a message when all tests are finished.
 */
void loop()
{
    if (RUN_ALL_TESTS())
        ;

    delay(500);

    Serial.println("-----------------------------------Finished all tests!-----------------------------------");

    delay(10000);
}
