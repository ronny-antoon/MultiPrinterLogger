#ifndef MULTI_PRINTER_LOGGER_HPP
#define MULTI_PRINTER_LOGGER_HPP

#include <Print.h>
#include <vector>
#include <stdarg.h>
#include <stdio.h>

#include "MultiPrinterLoggerInterface.hpp"

/**
 * @file MultiPrinterLogger.hpp
 * @brief Defines the MultiPrinterLogger class
 * @details Header file declaring the implementation of the MultiPrinterLogger class
 * @author Ronny Antoon.
 * @copyright MetaHouse LTD.
 */

/**
 * @brief Class for logging messages to multiple printers.
 *
 * @note This class is not intended to be used directly.
 */
class MultiPrinterLogger : public MultiPrinterLoggerInterface
{
public:
    /**
     * @brief Default constructor for MultiPrinterLogger.
     */
    MultiPrinterLogger() = default;

    /**
     * @brief Virtual destructor for MultiPrinterLogger.
     */
    ~MultiPrinterLogger() override = default;

    /**
     * @brief Log a message with the specified log level.
     *
     * @param level The log level of the message.
     * @param format The format string for the log message.
     * @param ... Additional arguments for the format string.
     */
    void log(const LogLevel level, const char *format, ...) override;

    /**
     * @brief Set the log level for the logger.
     *
     * @param level The log level to set.
     */
    void setLogLevel(const LogLevel level);

    /**
     * @brief Add a printer to the list of printers.
     *
     * @param printer The printer to add.
     */
    void addPrinter(Print *printer);

    /**
     * @brief Enable or disable colored output.
     *
     * @param enable True to enable colored output, false to disable.
     *
     * @note To use colored output, You need to Add "monitor_raw = true" to your platformio.ini file.
     *
     */
    void setColorEnabled(const bool enable);

private:
    LogLevel logLevel = LogLevel::WARNING; /**< The current log level. */
    std::vector<Print *> printers;         /**< Stores the registered printers. */
    bool colorEnable = false;              /**< Indicates whether colored output is enabled. */
    const char errorColor = '1';           /**< ANSI color code for error messages. */
    const char infoColor = '2';            /**< ANSI color code for info messages. */
    const char warningColor = '3';         /**< ANSI color code for warning messages. */
    const char debugColor = '6';           /**< ANSI color code for debug messages. */
    const char verboseColor = '5';         /**< ANSI color code for verbose messages. */

    /**
     * @brief Log a message to a specific printer.
     *
     * @param printer The printer to log to.
     * @param level The log level of the message.
     * @param message The message to log.
     *
     * @note This method is private because it is only used internally.
     */
    void logToPrinter(Print *printer, const LogLevel level, const char *message);
};

#endif // MULTI_PRINTER_LOGGER_HPP
