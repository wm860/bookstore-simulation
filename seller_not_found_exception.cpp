#include "seller_not_found_exception.h"

SellerNotFoundException::SellerNotFoundException(unsigned int id)
: std::invalid_argument("There is not seller with id: " + id)
{}
