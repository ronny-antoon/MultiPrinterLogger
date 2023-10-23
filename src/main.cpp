#include <Arduino.h>

#include "MultiPrinterLogger.hpp"

void setup()
{
  MultiPrinterLogger printer = MultiPrinterLogger::getInstance();
  Serial.begin(115200);
  printer.addPrinter(&Serial);
  printer.setColorEnabled(true);
  printer.log(LogLevel::INFO, "Main", "hellow world");
}

void loop()
{
}