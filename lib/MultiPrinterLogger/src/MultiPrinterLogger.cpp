#include "MultiPrinterLogger.hpp"

/**
 * @brief Log a formatted message at the specified log level to all registered printers.
 *
 * @param level The log level of the message.
 * @param format The format string for the log message.
 * @param ... Additional arguments for the format string.
 */
void MultiPrinterLogger::log(const LogLevel level, const char *format, ...)
{
    // Check if the message should be logged.
    if (level > logLevel)
    {
        return;
    }

    // Format the message.
    va_list args;
    va_start(args, format);
    int messageLength = vsnprintf(nullptr, 0, format, args);

    // Check if the message is too long or if there was an error formatting the message.
    if (messageLength < 0 || messageLength > 4096)
    {
        va_end(args);
        return;
    }

    char *message = new char[messageLength + 1];

    // Format the message.
    vsnprintf(message, messageLength + 1, format, args);
    va_end(args);

    // Log the message to all registered printers.
    for (Print *printer : printers)
    {
        logToPrinter(printer, level, message);
    }

    delete[] message;
}

/**
 * @brief Set the log level for the logger.
 *
 * @param level The log level to set.
 */
void MultiPrinterLogger::setLogLevel(const LogLevel level)
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
void MultiPrinterLogger::logToPrinter(Print *printer, const LogLevel level, const char *message)
{
    // Add color to the message if colored output is enabled.
    if (colorEnable)
    {
        char color;
        switch (level)
        {
        case LogLevel::ERROR:
            printer->printf("\e[31m%s\e[0m\r\n", message);
            break;
        case LogLevel::INFO:
            printer->printf("\e[32m%s\e[0m\r\n", message);
            break;
        case LogLevel::WARNING:
            printer->printf("\e[33m%s\e[0m\r\n", message);
            break;
        case LogLevel::DEBUG:
            printer->printf("\e[36m%s\e[0m\r\n", message);
            break;
        default:
            printer->printf("\e[35m%s\e[0m\r\n", message);
            break;
        }
    }
    else
        printer->printf("%s\r\n", message);
}

/**
 * @brief Enable or disable colored output for log messages.
 *
 * @param enable True to enable colored output, false to disable.
 */
void MultiPrinterLogger::setColorEnabled(const bool enable)
{
    colorEnable = enable;
}
