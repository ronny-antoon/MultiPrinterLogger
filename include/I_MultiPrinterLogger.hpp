#ifndef I_MULTI_PRINTER_LOGGER_HPP
#define I_MULTI_PRINTER_LOGGER_HPP

#include <Print.h>

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
 * @brief Abstract class, Interface for the MultiPrinterLogger class.
 *
 * @note This interface is not intended to be used directly.
 */
class I_MultiPrinterLogger
{
public:
    I_MultiPrinterLogger() = default;

    /**
     * @brief Log a message to all registered printers.
     *
     * @param level - the log level of the message.
     * @param tag - the tag of the message.
     * @param message - the message to log. formated as a printf string.
     *
     */
    virtual void log(LogLevel level, const char *tag, const char *message) = 0;

    /**
     * @brief Add a printer to the list of registered printers.
     *
     * @param printer - the printer to add.
     *
     * @note The printer must be a subclass of the `Print` class.
     */
    virtual void addPrinter(Print *printer) = 0;

    /**
     * @brief Enable or disable colored output.
     *
     * @param enable - true to enable colored output, false to disable it.
     *
     * @note Colored output is disabled by default.
     * @warning You need to add 'monitor_raw = true' to your platformio.ini file to see colored output in the PlatformIO terminal.
     */
    virtual void setColorEnabled(bool enable) = 0;

    virtual ~I_MultiPrinterLogger() = default;
};

#endif // I_MULTI_PRINTER_LOGGER_HPP