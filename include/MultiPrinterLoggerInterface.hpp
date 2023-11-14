#ifndef MULTI_PRINTER_LOGGER_INTERFACE_HPP
#define MULTI_PRINTER_LOGGER_INTERFACE_HPP

/**
 * @file MultiPrinterLoggerInterface.hpp
 * @brief Defines the MultiPrinterLoggerInterface class
 * @details Header file declaring the abstract interface for a multi-level logger
 * @author Ronny Antoon.
 * @copyright MetaHouse LTD.
 */

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
    enum LogLevel
    {
        ERROR,   /**< Indicates errors in the application. */
        WARNING, /**< Warnings or important notifications. */
        INFO,    /**< General information messages. */
        DEBUG    /**< Debug messages for detailed information. */
    };

    /**
     * @brief Log a message with the specified log level.
     *
     * @param level The log level of the message.
     * @param format The format string for the log message.
     * @param ... Additional arguments for the format string.
     */
    virtual void log(LogLevel level, const char *format, ...) = 0;

    /**
     * @brief Virtual destructor for MultiPrinterLoggerInterface.
     */
    virtual ~MultiPrinterLoggerInterface() = default;
};

/**
 * @brief Macros for logging messages.
 */
#define Log_Error(myLogger, format, ...) myLogger->log(MultiPrinterLoggerInterface::LogLevel::ERROR, "[%s:%u][E] %s(): " format, __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#define Log_Warning(myLogger, format, ...) myLogger->log(MultiPrinterLoggerInterface::LogLevel::WARNING, "[%s:%u][W] %s(): " format, __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#define Log_Info(myLogger, format, ...) myLogger->log(MultiPrinterLoggerInterface::LogLevel::INFO, "[%s:%u][I] %s(): " format, __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#define Log_Debug(myLogger, format, ...) myLogger->log(MultiPrinterLoggerInterface::LogLevel::DEBUG, "[%s:%u][D] %s(): " format, __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)

#endif // MULTI_PRINTER_LOGGER_INTERFACE_HPP