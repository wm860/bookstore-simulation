#include "sellers_list.h"
#include "seller_not_found_exception.h"
#include "already_existing_seller_exception.h"
#include <iostream>

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

void SellersList::make_list(unsigned int number_of_sellers)
{
    for(unsigned int i = 0; i < number_of_sellers; i++)
    {
        unsigned int id = i + 1;
        std::string name = "Seller" + std::to_string(id);
        std::string surname = "Surname" + std::to_string(id);
        Accessibility accessibility = Accessibility::accessible;
        Seller seller(id, name, surname, accessibility);
        add_seller(seller);
    }
}

void SellersList::print_list() noexcept
{
    std::cout << "\nSellers list:\n";
    for(const auto &seller_ptr : sellers)
    {
        std::cout << "Seller ID: " << seller_ptr -> get_id() << "\n";
        std::cout << "Name: " << seller_ptr -> get_name() << "\n";
        std::cout << "Surname: " << seller_ptr -> get_surname() << "\n\n";
    }
}
