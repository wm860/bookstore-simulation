#include "catch_amalgamated.hpp"
#include "../seller.h"

TEST_CASE("seller simple tests", "[seller]")
{
    Seller seller(7, "Jacek", "Placek", Accessibility::accessible);

    CHECK(seller.get_name() == "Jacek");
    CHECK(seller.get_surname() == "Placek");
    CHECK(seller.get_id() == 7);
    CHECK(seller.get_accessibility() == Accessibility::accessible);

    SECTION("modification of name")
    {
        seller.set_name("Juzio");
        CHECK(seller.get_name() == "Juzio");
    }

    SECTION("modification of surname")
    {
        seller.set_surname("Dyzio");
        CHECK(seller.get_surname() == "Dyzio");
    }

    SECTION("modification of accessibility")
    {
        seller.set_accessibility(Accessibility::inaccessible);
        CHECK(seller.get_accessibility() == Accessibility::inaccessible);
    }
}
