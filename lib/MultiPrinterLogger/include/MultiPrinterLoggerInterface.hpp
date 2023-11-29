#ifndef MULTI_PRINTER_LOGGER_INTERFACE_HPP
#define MULTI_PRINTER_LOGGER_INTERFACE_HPP

/**
 * @file MultiPrinterLoggerInterface.hpp
 * @brief Defines the MultiPrinterLoggerInterface class
 * @details Header file declaring the abstract interface for a multi-level logger
 * @author Ronny Antoon.
 * @copyright MetaHouse LTD.
 */

#include <stdint.h>

/**
 * @brief Interface for a multi-level logger.
 *
 * This abstract class defines the interface for a logger that supports multiple log levels.
 */
class MultiPrinterLoggerInterface
{
public:
    /**
     * @brief Enumeration representing log levels.
     */
    enum LogLevel : uint8_t
    {
        ERROR,   /**< Indicates errors in the application. */
        WARNING, /**< Warnings or important notifications. */
        INFO,    /**< General information messages. */
        DEBUG,   /**< Debug messages for detailed information. */
        VERBOSE  /**< Verbose messages for very detailed information. */
    };

    /**
     * @brief Log a message with the specified log level.
     *
     * @param level The log level of the message.
     * @param format The format string for the log message.
     * @param ... Additional arguments for the format string.
     */
    virtual void log(const LogLevel level, const char *format, ...) = 0;

    /**
     * @brief Virtual destructor for MultiPrinterLoggerInterface.
     */
    virtual ~MultiPrinterLoggerInterface() = default;
};

#define FMT_LOG_M(LV, format) "[%s:%u][%c] %s(): " format, __FILE__, __LINE__, LV, __FUNCTION__
#define ENDIF_LOG_M else {};
#define LEVEL_LOG_M(level) MultiPrinterLoggerInterface::LogLevel::level

/**
 * @brief Macros for logging messages.
 */
#define Log_Error(myLogger, format, ...)                                          \
    if (myLogger)                                                                 \
        myLogger->log(LEVEL_LOG_M(ERROR), FMT_LOG_M('E', format), ##__VA_ARGS__); \
    ENDIF_LOG_M

#define Log_Warning(myLogger, format, ...)                                          \
    if (myLogger)                                                                   \
        myLogger->log(LEVEL_LOG_M(WARNING), FMT_LOG_M('W', format), ##__VA_ARGS__); \
    ENDIF_LOG_M

#define Log_Info(myLogger, format, ...)                                          \
    if (myLogger)                                                                \
        myLogger->log(LEVEL_LOG_M(INFO), FMT_LOG_M('I', format), ##__VA_ARGS__); \
    ENDIF_LOG_M

#define Log_Debug(myLogger, format, ...)                                          \
    if (myLogger)                                                                 \
        myLogger->log(LEVEL_LOG_M(DEBUG), FMT_LOG_M('D', format), ##__VA_ARGS__); \
    ENDIF_LOG_M

#define Log_Verbose(myLogger, format, ...)                                          \
    if (myLogger)                                                                   \
        myLogger->log(LEVEL_LOG_M(VERBOSE), FMT_LOG_M('V', format), ##__VA_ARGS__); \
    ENDIF_LOG_M

#endif // MULTI_PRINTER_LOGGER_INTERFACE_HPP
