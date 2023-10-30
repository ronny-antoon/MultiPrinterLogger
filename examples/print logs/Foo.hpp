#ifndef FOO_HPP
#define FOO_HPP

#include "API_MultiPrinterLogger.hpp"

// i dont knowe MultiPrinterLogger.
// i know only the API of MultiPrinterLogger(API_MultiPrinterLogger), and the Interface of MultiPrinterLogger(I_MultiPrinterLogger).

class Foo
{
public:
    Foo(){};
    ~Foo(){};

    void doSomething()
    {
        Log_Error("TAG", "This is an error message.");
        Log_Warning("TAG", "This is a warning message.");
        Log_Info("TAG", "This is an info message.");
        Log_Debug("TAG", "This is a debug message.");
    }
};

#endif // FOO_HPP