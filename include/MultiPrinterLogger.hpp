#ifndef MULTI_PRINTER_LOGGER_HPP
#define MULTI_PRINTER_LOGGER_HPP

#include <Print.h>
#include <vector>

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
    MultiPrinterLogger(){};

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
    void log(LogLevel level, const char *format, ...) override;

    /**
     * @brief Set the log level for the logger.
     *
     * @param level The log level to set.
     */
    void setLogLevel(LogLevel level);

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
     */
    void setColorEnabled(bool enable);

private:
    LogLevel logLevel = LogLevel::ERROR;   /**< The current log level. */
    std::vector<Print *> printers;         /**< Stores the registered printers. */
    bool colorEnable = false;              /**< Indicates whether colored output is enabled. */
    const char errorColor[6] = "\e[31m";   /**< ANSI color code for error messages. */
    const char infoColor[6] = "\e[32m";    /**< ANSI color code for info messages. */
    const char warningColor[6] = "\e[33m"; /**< ANSI color code for warning messages. */
    const char debugColor[6] = "\e[36m";   /**< ANSI color code for debug messages. */
    const char resetColor[5] = "\e[0m";    /**< ANSI color code to reset color. */

    /**
     * @brief Log a message to a specific printer.
     *
     * @param printer The printer to log to.
     * @param level The log level of the message.
     * @param message The message to log.
     *
     * @note This method is private because it is only used internally.
     */
    void logToPrinter(Print *printer, LogLevel level, const char *message);
};

#endif // MULTI_PRINTER_LOGGER_HPP
