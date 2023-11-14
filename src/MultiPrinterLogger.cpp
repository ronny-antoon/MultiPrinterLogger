#include "MultiPrinterLogger.hpp"

#include <stdarg.h>
#include <stdio.h>

/**
 * @brief Log a formatted message at the specified log level to all registered printers.
 *
 * @param level The log level of the message.
 * @param format The format string for the log message.
 * @param ... Additional arguments for the format string.
 */
void MultiPrinterLogger::log(LogLevel level, const char *format, ...)
{
    // Check if the message should be logged.
    if (level > logLevel)
    {
        return;
    }

    // Format the message.
    char message[256];
    va_list args;
    va_start(args, format);
    vsnprintf(message, sizeof(message), format, args);
    va_end(args);

    // Log the message to all registered printers.
    for (Print *printer : printers)
    {
        logToPrinter(printer, level, message);
    }
}

/**
 * @brief Set the log level for the logger.
 *
 * @param level The log level to set.
 */
void MultiPrinterLogger::setLogLevel(LogLevel level)
{
    logLevel = level;
}

/**
 * @brief Add a printer as an output destination for log messages.
 *
 * @param printer The printer to add.
 */
void MultiPrinterLogger::addPrinter(Print *printer)
{
    printers.push_back(printer);
}

/**
 * @brief Log a message to a specific printer.
 *
 * @param printer The printer to log to.
 * @param level The log level of the message.
 * @param message The message to log.
 */
void MultiPrinterLogger::logToPrinter(Print *printer, LogLevel level, const char *message)
{
    // Add color to the message if colored output is enabled.
    if (colorEnable)
    {
        switch (level)
        {
        case LogLevel::ERROR:
            printer->print(errorColor);
            break;
        case LogLevel::WARNING:
            printer->print(warningColor);
            break;
        case LogLevel::INFO:
            printer->print(infoColor);
            break;
        case LogLevel::DEBUG:
            printer->print(debugColor);
            break;
        }
    }

    // Add message.
    printer->print(message);

    // Reset color if colored output is enabled.
    if (colorEnable)
    {
        printer->print(resetColor);
    }

    // Move to the next line.
    printer->println();
}

/**
 * @brief Enable or disable colored output for log messages.
 *
 * @param enable True to enable colored output, false to disable.
 */
void MultiPrinterLogger::setColorEnabled(bool enable)
{
    colorEnable = enable;
}
