#ifndef MULTI_PRINTER_LOGGER_HPP
#define MULTI_PRINTER_LOGGER_HPP

/**
 * @file MultiPrinterLogger.hpp
 * @brief A simple logging library for Arduino that logs messages to multiple output destinations.
 * @author Ronny Antoon
 */

#include "Print.h"
#include <vector>

/**
 * Enumeration representing log levels.
 */
enum class LogLevel : uint8_t
{
    ERROR,   // Indicates errors in the application.
    WARNING, // Warnings or important notifications.
    INFO,    // General information messages.
    DEBUG    // Debug messages for detailed information.
};

/**
 * @brief MultiPrinterLogger - class for logging messages to multiple output destinations.
 *
 * This class is a Singleton, meaning that only one instance of it can exist at a time.
 * To get the instance of the class, use the `getInstance()` method.
 */
class MultiPrinterLogger
{
public:
    /**
     * @brief Get the instance of the MultiPrinterLogger class.
     *
     * @return MultiPrinterLogger& - the instance of the MultiPrinterLogger class.
     */
    static MultiPrinterLogger &getInstance();

    /**
     * @brief Log a message to all registered printers.
     *
     * @param level - the log level of the message.
     * @param tag - the tag of the message.
     * @param message - the message to log. formated as a printf string.
     *
     */
    void log(LogLevel level, const char *tag, const char *format, ...);

    /**
     * @brief Add a printer to the list of registered printers.
     *
     * @param printer - the printer to add.
     *
     * @note The printer must be a subclass of the `Print` class.
     */
    void addPrinter(Print *printer);

    /**
     * @brief Enable or disable colored output.
     *
     * @param enable - true to enable colored output, false to disable it.
     *
     * @note Colored output is disabled by default.
     * @warning You need to add 'monitor_raw = true' to your platformio.ini file to see colored output in the PlatformIO terminal.
     */
    void setColorEnabled(bool enable);

private:
    /**
     * @brief Construct a new MultiPrinterLogger object.
     *
     * @note This is a private constructor because this class is a Singleton.
     */
    MultiPrinterLogger() {}

    std::vector<Print *> printers; // Stores the registered printers
    bool colorEnable = false;      // Indicates whether colored output is enabled

    /**
     * @brief Log a message to a specific printer.
     *
     * @param printer - the printer to log to.
     * @param level - the log level of the message.
     * @param tag - the tag of the message.
     * @param message - the message to log.
     *
     * @note This method is private because it is only used internally.
     */
    void logToPrinter(Print *printer, LogLevel level, const char *tag, const char *message);
};

#endif // MULTI_PRINTER_LOGGER_HPP
