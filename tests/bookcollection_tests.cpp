#include "catch_amalgamated.hpp"

#include <sstream>
#include <cmath>
#include <iostream>
#include "../book.h"
#include "../ebook.h"
#include "../magazine.h"
#include "../bookcollection.h"

TEST_CASE("tests for class bookcollection", "[bookcollectiontests]")
{
    Bookcollection bc;
    Book b("Joanne K. Rowling", "Harry Potter and the Philosopher's Stone", 1, "novel", 202.91, "available");
    Ebook e("Stieg Larsson", "The Girl with the Dragon Tattoo", 2, "fiction", 22.01, "available", "pdf");
    Magazine m("George Orwell", "Animal Farm", 3, "novel", 35.41, "available", 11, "2022");

    SECTION("add book")
    {
        bc.add_book(b);
        CHECK(bc.check_book_by_isbn(1));
    }
}
