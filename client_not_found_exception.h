#ifndef CLIENT_NOT_FOUND_EXCEPTION
#define CLIENT_NOT_FOUND_EXCEPTION

#include <stdexcept>

class ClientNotFoundException : public std::invalid_argument
{
    public:
        ClientNotFoundException(unsigned int id);
};

#endif
