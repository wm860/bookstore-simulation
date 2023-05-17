#include "client_not_found_exception.h"

ClientNotFoundException::ClientNotFoundException(unsigned int id)
: std::invalid_argument("There is not client with id: " + id)
{}
