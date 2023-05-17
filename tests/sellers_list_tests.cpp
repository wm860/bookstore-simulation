#include "catch_amalgamated.hpp"
#include "../sellers_list.h"
#include "../already_existing_seller_exception.h"
#include "../seller_not_found_exception.h"

TEST_CASE("sellers list simple tests", "[sellers_list]")
{
    SellersList sellers_list;

    SECTION("add seller")
    {
        Seller seller(7, "Jacek", "Placek", Accessibility::accessible);
        sellers_list.add_seller(seller);
        CHECK(sellers_list.find_seller_by_id(7) == seller);
    }

    SECTION("invalid find no seller with that id")
    {
        REQUIRE_THROWS_AS(sellers_list.find_seller_by_id(7), SellerNotFoundException);
    }

    SECTION("invalid add already is client with that id")
    {
        Seller seller(7, "Jacek", "Placek", Accessibility::accessible);
        sellers_list.add_seller(seller);
        REQUIRE_THROWS_AS(sellers_list.add_seller(seller), AlreadyExistingSellerException);
    }
}
