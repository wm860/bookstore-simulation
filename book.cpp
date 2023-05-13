#include "book.h"
#include "exception_negative_price.h"
#include <iostream>

Book::Book(std::string new_author, std::string new_title, uint new_isbn, std::string new_genre, double new_price, std::string new_state) : author(new_author), title(new_title), isbn(new_isbn), genre(new_genre), state(new_state)
{
    if (new_price < 0)
    {
        throw NegativePriceException(new_price);
    }
    base_price = new_price;
}

void Book::print() const
{
    std::cout << "ISBN identificator: " << isbn << "Title: " << title << ", Author: " << author << "Genre :" << genre << ", Base price: " << base_price << ", State: " << state << std::endl;
}
std::ostream &operator<<(std::ostream &os, const Book &boo)
{
    os << "ISBN identificator: " << boo.isbn << "Title: " << boo.title << ", Author: " << boo.author << "Genre :" << boo.genre << ", Base price: " << boo.base_price << ", State: " << boo.state << std::endl;
    return os;
}

double Book::calculate_price() const
{
    return base_price;
}

bool Book::operator==(const Book &b) const
{
    return author == b.author && title == b.title;
}

Book::~Book() {}
std::string Book::get_author() const
{
    return author;
}
std::string Book::get_title() const
{
    return title;
}
uint Book::get_isbn() const
{
    return isbn;
}
std::string Book::get_genre()
{
    return genre;
}
double Book::get_base_price() const
{
    return base_price;
}
std::string Book::get_state()
{
    return state;
}

void Book::set_author(std::string a)
{
    author = a;
}
void Book::set_title(std::string t)
{
    title = t;
}
void Book::set_isbn(uint i)
{
    isbn = i;
}
void Book::set_genre(std::string a)
{
    genre = a;
}
void Book::set_state(std::string s)
{
    state = s;
}