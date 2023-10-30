#ifndef API_MULTI_PRINTER_LOGGER_HPP
#define API_MULTI_PRINTER_LOGGER_HPP

#include <Print.h>

#include "I_MultiPrinterLogger.hpp"

/**
 * @brief API for the MultiPrinterLogger class.
 */
namespace API_MultiPrinterLogger
{
    /**
     * @brief To start loging you need to call begin first in stup().
     *
     * @param logger - the logger.
     *
     */
    void begin(I_MultiPrinterLogger *logger);

    /**
     * @brief Add a printer to the list of registered printers.
     *
     * @param printer - the printer to add.
     */
    void addPrinter(Print *printer);

    /**
     * @brief Log a message to all registered printers.
     *
     * @param level - the log level of the message.
     * @param tag - the tag of the message.
     * @param format - the message to log. formated as a printf string.
     * @param ... - the arguments to the format string.
     *
     * @note This method is not intended to be used directly.
     * @note Use Macros instead.
     *
     * @warning The message is limited to 256 characters.
     */
    void log(LogLevel level, const char *tag, const char *format, ...);

    /**
     * @brief Enable or disable colored output.
     *
     * @param enable - true to enable colored output, false to disable it.
     */
    void setColorEnabled(bool enable);
}

// Macros for logging messages.
#define Log_Error(tag, format, ...) API_MultiPrinterLogger::log(LogLevel::ERROR, tag, format, ##__VA_ARGS__)
#define Log_Warning(tag, format, ...) API_MultiPrinterLogger::log(LogLevel::WARNING, tag, format, ##__VA_ARGS__)
#define Log_Info(tag, format, ...) API_MultiPrinterLogger::log(LogLevel::INFO, tag, format, ##__VA_ARGS__)
#define Log_Debug(tag, format, ...) API_MultiPrinterLogger::log(LogLevel::DEBUG, tag, format, ##__VA_ARGS__)

#endif // API_MULTI_PRINTER_LOGGER_HPP