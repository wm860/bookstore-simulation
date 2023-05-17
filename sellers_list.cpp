#include "sellers_list.h"
#include "seller_not_found_exception.h"
#include "already_existing_seller_exception.h"

void SellersList::add_seller(Seller seller)
{
    for(const auto& seller_ptr : sellers)
    {
        if(seller_ptr -> get_id() == seller.get_id())
        {
            throw AlreadyExistingSellerException(seller.get_id());
        }
    }
    std::shared_ptr<Seller> added_seller = std::make_shared<Seller>(seller);
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

std::list<std::shared_ptr<Seller>> SellersList::get_sellers()
{
    return sellers;
}
