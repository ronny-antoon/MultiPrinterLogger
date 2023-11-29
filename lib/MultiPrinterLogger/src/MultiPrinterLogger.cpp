#include "MultiPrinterLogger.hpp"

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
    char tmp[2];
    va_list args;
    va_start(args, format);
    int messageLength = vsnprintf(tmp, sizeof(tmp), format, args);

    // Check if the message is too long or if there was an error formatting the message.
    if (messageLength < 0 || messageLength > 4096)
    {
        va_end(args);
        return;
    }

    // Allocate memory for the message.
    char *message = (char *)malloc(messageLength + 1);
    if (message == NULL)
    {
        va_end(args);
        return;
    }

    // Format the message.
    vsnprintf(message, messageLength + 1, format, args);
    va_end(args);

    // Log the message to all registered printers.
    for (Print *printer : printers)
    {
        logToPrinter(printer, level, message);
    }

    // Free the memory for the message.
    free(message);
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
        case LogLevel::VERBOSE:
            printer->print(verboseColor);
            break;
        }
    }

    // Log the message.
    if (colorEnable)
        printer->printf("%s%s\r\n", message, resetColor);
    else
        printer->printf("%s\r\n", message);
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
