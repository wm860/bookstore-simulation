#include "catch_amalgamated.hpp"

#include <sstream>
#include <cmath>
#include <iostream>
#include "../book.h"

TEST_CASE("tests for class book", "[books]")
{
    Book b("Joanne K. Rowling", "Harry Potter and the Philosopher's Stone", 5, "novel", 202.91, "available");

    CHECK(b.get_title() == "Harry Potter and the Philosopher's Stone");
    CHECK(b.get_author() == "Joanne K. Rowling");
    CHECK(b.get_genre() == "novel");
    CHECK((b.get_base_price() - 202.91) < 0.1);

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
}
