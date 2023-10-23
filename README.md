# MultiPrinterLogger Library

## Overview
The MultiPrinterLogger library is an Arduino framework-based implementation of a flexible logger system that allows you to log messages to multiple output destinations. It provides support for different log levels (ERROR, WARNING, INFO, DEBUG) and enables or disables colored output for log messages.

## Features
Multiple Output Destinations: Log messages can be directed to multiple output destinations simultaneously. This can be useful for debugging and monitoring your Arduino projects on various interfaces.

Log Levels: Messages are categorized into different log levels, such as ERROR, WARNING, INFO, and DEBUG, making it easy to distinguish the importance of each log message.

Colored Output: You can enable or disable colored output for log messages, enhancing the visibility and distinction of log levels.

Singleton Pattern: The library follows the Singleton pattern, ensuring a single instance of the logger throughout your project.

## Installation
**Method 1**:
To use the **MultiPrinterLogger** library in your PlatformIO project, follow these steps:

1. Open "platformio.ini", a project configuration file located in the root of PlatformIO project.

2. Add the following line to the `lib_deps` option of `[env:]` section:
`ronny-antoon/MultiPrinterLogger@^1.0.0`

3. Build a project, PlatformIO will automatically install dependencies.

**Method 2**:
To use the **MultiPrinterLogger** library in your Arduino project, follow these steps:

1. Download the latest release from the [GitHub repository](https://github.com/ronny-antoon/MultiPrinterLogger).

2. In the Arduino IDE, click "Sketch" -> "Include Library" -> "Add .ZIP Library" and select the downloaded `.zip` file.

**IMPORTANT**:
If you want to enable color you need to add in "platformio.ini" file this line:
`monitor_raw = true`

## Example
Here's a basic example of how to use the MultiPrinterLogger library in your Arduino project:

```cpp
#include <MultiPrinterLogger.hpp>

void setup() {
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

void loop() {
  // Your main code here.
}
```

## API
`void log(LogLevel level, const char *tag, const char *format, ...)``: Log a formatted message at the specified log level.

`void addPrinter(Print *printer)``: Add a printer (output destination) for log messages.

`void setColorEnabled(bool enable)``: Enable or disable colored output for log messages.

**Log Levels**
`LogLevel::ERROR``: Indicates errors in the application.

`LogLevel::WARNING``: Warnings or important notifications.

`LogLevel::INFO``: General information messages.

`LogLevel::DEBUG``: Debug messages for detailed information.

## License
This library is open-source and distributed under the MIT License. Feel free to use, modify, and distribute it according to the terms of the license.

## Contributions
Contributions to the MultiPrinterLogger library are welcome. If you find any issues, have suggestions for improvements, or want to contribute code, please create a pull request on the GitHub repository.

## Author
This library was created by Ronny Antoon. You can contact me at [your-email@example.com] for any questions or feedback.

## platformio Registry

https://registry.platformio.org/libraries/ronny-antoon/MultiPrinterLogger