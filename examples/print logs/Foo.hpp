#ifndef FOO_HPP
#define FOO_HPP

#include "MultiPrinterLoggerInterface.hpp"

/**
 * @brief Foo class.
 *
 * This class demonstrates the usage of MultiPrinterLoggerInterface for logging messages.
 */
class Foo
{
    MultiPrinterLoggerInterface *_mylogger; ///< Pointer to the MultiPrinterLoggerInterface instance.

public:
    /**
     * @brief Constructor for Foo class.
     *
     * @param mylogger Pointer to the MultiPrinterLoggerInterface instance.
     */
    Foo(MultiPrinterLoggerInterface *mylogger);

    /**
     * @brief Destructor for Foo class.
     */
    ~Foo();

    /**
     * @brief Perform some action and log messages using MultiPrinterLoggerInterface.
     */
    void doSomething();
};

#endif // FOO_HPP
