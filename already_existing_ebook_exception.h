#ifndef ALREADY_EXISTING_EBOOK_EXCEPTION
#define ALREADY_EXISTING_EBOOK_EXCEPTION

#include <stdexcept>

class AlreadyExistingEbookException : public std::invalid_argument
{
public:
    AlreadyExistingEbookException(unsigned int isbn);
};

#endif
