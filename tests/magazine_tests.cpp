#include "catch_amalgamated.hpp"

#include <sstream>
#include <cmath>
#include <iostream>
#include "../magazine.h"

TEST_CASE("tests for class magazine", "[magazines]")
{
    Magazine b("Joanne K. Rowling", "Harry Potter and the Philosopher's Stone", 5, "novel", 202.91, "available", 11, "2022");

    CHECK(b.get_title() == "Harry Potter and the Philosopher's Stone");
    CHECK(b.get_author() == "Joanne K. Rowling");
    CHECK(b.get_genre() == "novel");
    CHECK((b.get_base_price() - 202.91) < 0.1);
    CHECK(b.get_month() == 11);
    CHECK(b.get_year() == "2022");

    SECTION("change title")
    {
        b.set_title("different title");
        CHECK(b.get_title() == "different title");
    }

    SECTION("change author")
    {
        b.set_author("new author");
        CHECK(b.get_author() == "new author");
    }

    SECTION("change genre")
    {
        b.set_genre("novel");
        CHECK(b.get_genre() == "novel");
    }
    SECTION("change state")
    {
        b.set_state("serviced");
        CHECK(b.get_state() == "serviced");
    }
    SECTION("change month")
    {
        b.set_month(5);
        CHECK(b.get_month() == 5);
    }
    SECTION("change year")
    {
        b.set_year("2020");
        CHECK(b.get_year() == "2020");
    }
}
