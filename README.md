# MultiPrinterLogger Library

[![Donate](https://img.shields.io/badge/Donate-PayPal-green.svg)](https://www.paypal.com/donate/?hosted_button_id=BACPRJTAU4G4E)
[![Latest](https://img.shields.io/github/v/tag/ronny-antoon/MultiPrinterLogger?color=red&label=last+release)](https://github.com/ronny-antoon/MultiPrinterLogger/releases)
[![Latest](https://badges.registry.platformio.org/packages/ronny-antoon/library/MultiPrinterLogger.svg)](https://registry.platformio.org/libraries/ronny-antoon/MultiPrinterLogger)
[![UnitTests](https://github.com/ronny-antoon/MultiPrinterLogger/actions/workflows/build-and-test-embeded.yaml/badge.svg)](https://github.com/ronny-antoon/MultiPrinterLogger/actions/workflows/build-and-test-embeded.yaml)

The MultiPrinterLogger library is a simple logging library for Arduino/ESP32 that logs messages to multiple output destinations. It is designed to be easy to use and highly customizable, allowing you to control log levels, colored output, and the choice of output destinations.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Class Overview](#class-overview)
- [Example](#example)
- [License](#license)
- [Contributions](#contributions)

## Introduction

The MultiPrinterLogger library provides a flexible and extensible logging mechanism for Arduino projects. It allows you to log messages at different levels (ERROR, WARNING, INFO, DEBUG) and direct those messages to multiple output destinations.

## Features
- **Log Levels**: Supports different log levels to categorize messages based on their severity.
- **Multiple Printers**: Logs messages to multiple printers, making it versatile for different output destinations.
- **Colored Output**: Optionally supports colored output for better visual distinction of log levels. To use colored output, You need to Add "monitor_raw = true" to your platformio.ini file.
- **Flexible Configuration**: Easily configurable log level and color options.

## Installation

**Method 1**:
To use the **MultiPrinterLogger** library in your PlatformIO project, follow these steps:

1. Open "platformio.ini," a project configuration file located in the root of the PlatformIO project.

2. Add the following line to the `lib_deps` option of `[env:]` section:
   `ronny-antoon/MultiPrinterLogger@^4.1.1`

3. Build your project, and PlatformIO will automatically install the required dependencies.

**Method 2**:
To use the **MultiPrinterLogger** library in your Arduino project, follow these steps:

1. Download the latest release from the [GitHub repository](https://github.com/ronny-antoon/MultiPrinterLogger).

2. In the Arduino IDE, click "Sketch" -> "Include Library" -> "Add .ZIP Library" and select the downloaded `.zip` file.

## Usage

The MultiPrinterLogger library provides a convenient way to log messages to multiple output destinations. You can customize the log levels, message formatting, and enable colored output.

### Class Overview

The library includes the following classes:
- `MultiPrinterLoggerInterface`: This abstract class defines the interface for a logger that supports multiple log levels.
Convenient macros for logging messages:
**Log_Error(myLogger, format, ...)**
**Log_Warning(myLogger, format, ...)**
**Log_Info(myLogger, format, ...)**
**Log_Debug(myLogger, format, ...)**

- `MultiPrinterLogger`: This class implements the MultiPrinterLoggerInterface and is responsible for logging messages to multiple printers.
Methods:
**void log(LogLevel level, const char *format, ...)**: Log a message with the specified log level.
**void setLogLevel(LogLevel level)**: Set the log level for the logger.
**void addPrinter(Print *printer)**: Add a printer to the list of printers.
**void setColorEnabled(bool enable)**: Enable or disable colored output.

### Example

Here's a simple example of how to use the MultiPrinterLogger library to log messages:

```cpp
#include <Arduino.h>
#include "MultiPrinterLogger.hpp"

MultiPrinterLogger *myLogger;

void setup()
{
    // Initialize your desired output destinations (e.g., Serial, Serial1, etc.).
    Serial.begin(115200);

    // Initialize the logger.
    myLogger = new MultiPrinterLogger();
    myLogger->addPrinter(&Serial);
    myLogger->setLogLevel(MultiPrinterLogger::LogLevel::DEBUG);
    myLogger->setColorEnabled(true);

    // Use the logger in your code.
    // ...
}

void loop() {
    // Your application code here.

    // Log messages with different log levels.
    Log_Error(myLogger, "This is an error message.");
    Log_Warning(myLogger, "This is a warning message.");
    Log_Info(myLogger, "This is an info message.");
    Log_Debug(myLogger, "This is a debug message.");
    delay(10000);
}
```

For a complete list of methods and error codes, refer to the class documentation in the header code.

### License

This library is provided under the MIT License. You are free to use, modify, and distribute it as needed.

### Contributions

Contributions to the MultiPrinterLogger library are welcome. If you find any issues, have suggestions for improvements, or want to contribute code, please create a pull request on the GitHub repository.

### Author

This library was created by Ronny Antoon. You can contact me at [ronny.antoon@gmail.com] for any questions or feedback.

## Platformio Registry

https://registry.platformio.org/libraries/ronny-antoon/MultiPrinterLogger