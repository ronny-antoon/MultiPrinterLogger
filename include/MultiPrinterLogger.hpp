#ifndef MULTI_PRINTER_LOGGER_HPP
#define MULTI_PRINTER_LOGGER_HPP

#include <Print.h>
#include <vector>

#include "I_MultiPrinterLogger.hpp"

class MultiPrinterLogger : public I_MultiPrinterLogger
{
public:
    MultiPrinterLogger(){};

    void log(LogLevel level, const char *tag, const char *message) override;

    void addPrinter(Print *printer) override;

    void setColorEnabled(bool enable) override;

private:
    std::vector<Print *> printers; // Stores the registered printers
    bool colorEnable = false;      // Indicates whether colored output is enabled
    const char errorColor[6] = "\e[31m";
    const char infoColor[6] = "\e[32m";
    const char warningColor[6] = "\e[33m";
    const char debugColor[6] = "\e[36m";
    const char resetColor[5] = "\e[0m";

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
