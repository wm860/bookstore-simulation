#include "already_existing_ebook_exception.h"

AlreadyExistingEbookException::AlreadyExistingEbookException(unsigned int isbn)
    : std::invalid_argument("There ebook is already added: " + isbn)
{
}