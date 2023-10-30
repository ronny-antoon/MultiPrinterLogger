# MultiPrinterLogger Library

[![Latest](https://img.shields.io/github/v/tag/ronny-antoon/MultiPrinterLogger?color=red&label=last+release)](https://github.com/ronny-antoon/MultiPrinterLogger/releases)
[![Latest](https://badges.registry.platformio.org/packages/ronny-antoon/library/MultiPrinterLogger.svg)](https://registry.platformio.org/libraries/ronny-antoon/MultiPrinterLogger)
[![UnitTests](https://github.com/ronny-antoon/MultiPrinterLogger/actions/workflows/build-and-test-embeded.yaml/badge.svg)](https://github.com/ronny-antoon/MultiPrinterLogger/actions/workflows/build-and-test-embeded.yaml)

The MultiPrinterLogger library is a simple logging library for Arduino that logs messages to multiple output destinations. It is designed to be easy to use and highly customizable, allowing you to control log levels, colored output, and the choice of output destinations.

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

The MultiPrinterLogger library simplifies the process of logging messages from your Arduino application to various output devices. It allows you to log messages with different log levels (e.g., errors, warnings, information, and debugging) and customize the formatting and output destinations.

## Features
- Supports logging to multiple output devices simultaneously.
- Log messages with different log levels (ERROR, WARNING, INFO, DEBUG).
- Customize message formatting and colored output for better visualization.
- EFlexible and extensible design, allowing you to add custom output devices as needed.

## Installation

**Method 1**:
To use the **MultiPrinterLogger** library in your PlatformIO project, follow these steps:

1. Open "platformio.ini," a project configuration file located in the root of the PlatformIO project.

2. Add the following line to the `lib_deps` option of `[env:]` section:
   `ronny-antoon/MultiPrinterLogger@^3.0.1`

3. Build your project, and PlatformIO will automatically install the required dependencies.

**Method 2**:
To use the **MultiPrinterLogger** library in your Arduino project, follow these steps:

1. Download the latest release from the [GitHub repository](https://github.com/ronny-antoon/MultiPrinterLogger).

2. In the Arduino IDE, click "Sketch" -> "Include Library" -> "Add .ZIP Library" and select the downloaded `.zip` file.

## Usage

The MultiPrinterLogger library provides a convenient way to log messages to multiple output destinations. You can customize the log levels, message formatting, and enable colored output.

### Class Overview

The library includes the following classes:
- `MultiPrinterLogger`: The main class for logging messages to multiple output destinations.
- `I_MultiPrinterLogger`: The Interface class.
- `API_MultiPrinterLogger`: The API to use for logging.
- `LogLevel`: An enumeration representing log levels (ERROR, WARNING, INFO, DEBUG).

### Example

Here's a simple example of how to use the MultiPrinterLogger library to log messages:

```cpp
#include "API_MultiPrinterLogger.hpp" // API for logging.
#include "MultiPrinterLogger.hpp"     // Only for Initialize the logger (in setup function).

void setup() {
      // Initialize your desired output destinations (e.g., Serial, Serial1, etc.).
    Serial.begin(115200);

    // Initialize the logger.
    API_MultiPrinterLogger::begin(new MultiPrinterLogger());

    // Add Serial as an output destination.
    API_MultiPrinterLogger::addPrinter(&Serial);

    // Enable colored output.
    API_MultiPrinterLogger::setColorEnabled(true);

}

void loop() {
    // Your application code here.

    // Log messages with different log levels.
    Log_Error("TAG", "This is an error message.");
    Log_Warning("TAG", "This is a warning message.");
    Log_Info("TAG", "This is an info message.");
    Log_Debug("TAG", "This is a debug message.");
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