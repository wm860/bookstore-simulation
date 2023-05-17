#ifndef SELLERS_LIST_H
#define SELLERS_LIST_H
#include "seller.h"
#include <list>
#include <memory>


class SellersList
{
    private:
        std::list<std::shared_ptr<Seller>> sellers;
    public:
        void add_seller(Seller seller);
        std::list<std::shared_ptr<Seller>> get_sellers();
        Seller find_seller_by_id(unsigned int id) const;
};

#endif
