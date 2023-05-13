#include "book_not_found_exception.h"

BookNotFoundException::BookNotFoundException(uint isbn) : std::invalid_argument("Book having the following ISBN not found: " + isbn) {}