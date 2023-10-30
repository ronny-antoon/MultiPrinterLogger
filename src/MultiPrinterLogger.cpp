#include <Print.h>
#include <vector>

#include "MultiPrinterLogger.hpp"

/**
 * Log a formatted message at the specified log level to all registered printers.
 */
void MultiPrinterLogger::log(LogLevel level, const char *tag, const char *message)
{
    for (Print *printer : printers)
    {
        logToPrinter(printer, level, tag, message);
    }
}

/**
 * Add a printer as an output destination for log messages.
 */
void MultiPrinterLogger::addPrinter(Print *printer)
{
    printers.push_back(printer);
}

/**
 * Log a message to a specific printer.
 */
void MultiPrinterLogger::logToPrinter(Print *printer, LogLevel level, const char *tag, const char *message)
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

    // Add tag.
    printer->print("[");
    printer->print(tag);
    printer->print("] ");

    // Add LogLevel.
    switch (level)
    {
    case LogLevel::ERROR:
        printer->print("ERROR: ");
        break;
    case LogLevel::WARNING:
        printer->print("WARNING: ");
        break;
    case LogLevel::INFO:
        printer->print("INFO: ");
        break;
    case LogLevel::DEBUG:
        printer->print("DEBUG: ");
        break;
    }

    // Add message.
    printer->print(message);
    if (colorEnable)
    {
        printer->print(resetColor);
    }
    printer->println();
}

/**
 * Enable or disable colored output for log messages.
 */
void MultiPrinterLogger::setColorEnabled(bool enable)
{
    colorEnable = enable;
}
