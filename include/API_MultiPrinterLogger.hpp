#ifndef API_MULTI_PRINTER_LOGGER_HPP
#define API_MULTI_PRINTER_LOGGER_HPP

#include <Print.h>

#include "I_MultiPrinterLogger.hpp"

namespace API_MultiPrinterLogger
{
    void begin(I_MultiPrinterLogger *logger);
    void addPrinter(Print *printer);
    void log(LogLevel level, const char *tag, const char *format, ...);
    void setColorEnabled(bool enable);
}
// Macro for Logging messages
#define Log_Error(tag, format, ...) API_MultiPrinterLogger::log(LogLevel::ERROR, tag, format, ##__VA_ARGS__)
#define Log_Warning(tag, format, ...) API_MultiPrinterLogger::log(LogLevel::WARNING, tag, format, ##__VA_ARGS__)
#define Log_Info(tag, format, ...) API_MultiPrinterLogger::log(LogLevel::INFO, tag, format, ##__VA_ARGS__)
#define Log_Debug(tag, format, ...) API_MultiPrinterLogger::log(LogLevel::DEBUG, tag, format, ##__VA_ARGS__)

#endif // API_MULTI_PRINTER_LOGGER_HPP