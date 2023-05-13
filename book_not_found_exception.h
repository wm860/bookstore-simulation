#ifndef BOOK_NOT_FOUND_EXCEPTION_H
#define BOOK_NOT_FOUND_EXCEPTION_H

#include <stdexcept>

class BookNotFoundException : public std::invalid_argument
{
public:
    BookNotFoundException(uint isbn);
};

#endif