#ifndef SELLERS_LIST_H
#define SELLERS_LIST_H
#include "seller.h"
#include <list>
#include <memory>


class SellersList
{
    private:
        std::list<std::unique_ptr<Seller>> sellers;
    public:
        void add_seller(unsigned int id, std::string name, std::string surname, Accessibility);
        Seller find_seller_by_id(unsigned int id) const;
};

#endif
