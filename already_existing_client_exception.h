#ifndef ALREADY_EXISTING_CLIENT_EXCEPTION
#define ALREADY_EXISTING_CLIENT_EXCEPTION

#include <stdexcept>

class AlreadyExistingClientException : public std::invalid_argument
{
    public:
        AlreadyExistingClientException(unsigned int id);
};


#endif
