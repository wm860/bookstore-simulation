#include "already_existing_client_exception.h"

AlreadyExistingClientException::AlreadyExistingClientException(unsigned int id)
: std::invalid_argument("There is already client with id: " + id)
{}