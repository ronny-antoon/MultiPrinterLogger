#ifndef MULTI_PRINTER_LOGGER_HPP
#define MULTI_PRINTER_LOGGER_HPP

#include "Logger.hpp"
#include <vector>

/**
 * MultiPrinterLogger: An implementation of the Logger interface that logs messages to multiple output destinations.
 */
class MultiPrinterLogger : public Logger
{
public:
    /**
     * Get the Singleton instance of the MultiPrinterLogger.
     *
     * @return A reference to the Singleton instance of MultiPrinterLogger.
     */
    static MultiPrinterLogger &getInstance();

    /**
     * Log a formatted message at the specified log level to all registered printers.
     *
     * @param level    The log level (ERROR, WARNING, INFO, DEBUG).
     * @param tag      A tag associated with the log message.
     * @param format   A printf-style format string for the log message.
     * @param ...      Variable arguments to format the log message.
     */
    void log(LogLevel level, const char *tag, const char *format, ...) override;

    /**
     * Add a printer as an output destination for log messages.
     *
     * @param printer  The printer (e.g., Serial) to add for log output.
     */
    void addPrinter(Print *printer);

    /**
     * Enable or disable colored output for log messages.
     *
     * @param enable   Set to `true` to enable colored output, or `false` to disable it.
     */
    void setColorEnabled(bool enable);

private:
    /**
     * Private constructor to enforce Singleton pattern.
     */
    MultiPrinterLogger() {}

    std::vector<Print *> printers; // Stores the registered printers
    bool colorEnable = false;      // Indicates whether colored output is enabled

    /**
     * Log a message to a specific printer.
     *
     * @param printer  The printer (e.g., Serial) to log to.
     * @param level    The log level (ERROR, WARNING, INFO, DEBUG).
     * @param tag      A tag associated with the log message.
     * @param message  The message to log.
     */
    void logToPrinter(Print *printer, LogLevel level, const char *tag, const char *message);
};

#endif // MULTI_PRINTER_LOGGER_HPP
