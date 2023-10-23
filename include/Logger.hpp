#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <Arduino.h>

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
 * Logger interface for logging messages to multiple output destinations.
 */
class Logger
{
public:
    /**
     * Log a formatted message at the specified log level.
     *
     * @param level    The log level (ERROR, WARNING, INFO, DEBUG).
     * @param tag      A tag associated with the log message.
     * @param format   A printf-style format string for the log message.
     * @param ...      Variable arguments to format the log message.
     */
    virtual void log(LogLevel level, const char *tag, const char *format, ...) = 0;

    virtual ~Logger() {}
};

#endif // LOGGER_HPP
