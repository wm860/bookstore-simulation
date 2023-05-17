#include "already_existing_seller_exception.h"

AlreadyExistingSellerException::AlreadyExistingSellerException(unsigned int id)
: std::invalid_argument("There is already seller with that id: " + id)
{}
