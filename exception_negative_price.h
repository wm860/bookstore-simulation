#ifndef NEGATIVE_PRICE_EXCEPTION_H
#define NEGATIVE_PRICE_EXCEPTION_H
#include <stdexcept>

class NegativePriceException : public std::invalid_argument
{
public:
    NegativePriceException(double wrong_price);
};

#endif