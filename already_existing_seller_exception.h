#ifndef ALREADY_EXISTING_SELLER_EXCEPTION
#define ALREADY_EXISTING_SELLER_EXCEPTION

#include <stdexcept>

class AlreadyExistingSellerException : public std::invalid_argument
{
    public:
        AlreadyExistingSellerException(unsigned int id);
};

#endif
