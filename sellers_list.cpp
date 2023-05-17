#include "sellers_list.h"
#include "seller_not_found_exception.h"
#include "already_existing_seller_exception.h"

void SellersList::add_seller(unsigned int id, std::string name, std::string surname, Accessibility accessibility)
{
    for(const auto& seller_ptr : sellers)
    {
        if(seller_ptr -> get_id() == id)
        {
            throw AlreadyExistingSellerException(id);
        }
    }
    std::unique_ptr<Seller> added_seller = std::make_unique<Seller>(id, name, surname, accessibility);
    sellers.push_back(std::move(added_seller));
}

Seller SellersList::find_seller_by_id(unsigned int id) const
{
    for(const auto& seller_ptr : sellers)
    {
        if(seller_ptr -> get_id() == id)
        {
            return *seller_ptr;
        }
    }
    throw SellerNotFoundException(id);
}
