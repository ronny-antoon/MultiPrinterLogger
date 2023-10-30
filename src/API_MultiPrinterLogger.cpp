#include <stdarg.h>
#include <stdio.h>
#include <Print.h>

#include "API_MultiPrinterLogger.hpp"

static I_MultiPrinterLogger *_logger = nullptr;

void API_MultiPrinterLogger::begin(I_MultiPrinterLogger *logger)
{
    _logger = logger;
}

void API_MultiPrinterLogger::addPrinter(Print *printer)
{
    if (_logger == nullptr)
    {
        return;
    }

    _logger->addPrinter(printer);
}

void API_MultiPrinterLogger::log(LogLevel level, const char *tag, const char *format, ...)
{
    if (_logger == nullptr)
    {
        return;
    }

    char buffer[256];
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    _logger->log(level, tag, buffer);
}

void API_MultiPrinterLogger::setColorEnabled(bool enable)
{
    if (_logger == nullptr)
    {
        return;
    }

    _logger->setColorEnabled(enable);
}
