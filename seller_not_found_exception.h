#ifndef SELLER_NOT_FOUND_EXCEPTION
#define SELLER_NOT_FOUND_EXCEPTION

#include <stdexcept>

class SellerNotFoundException : public std::invalid_argument
{
    public:
        SellerNotFoundException(unsigned int id);
};

#endif
