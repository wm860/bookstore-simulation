#include "ebook.h"
#include <iostream>

Ebook::Ebook(std::string new_author, std::string new_title, uint new_isbn, std::string new_genre, double new_price, std::string new_state, std::string format) : Book(author, title, isbn, genre, base_price, state), format(format) {}

std::string Ebook::get_format()
{
    return format;
}
void Ebook::set_format(std::string m)
{
    format = m;
}

void Ebook::print() const
{
    std::cout << "ISBN identificator: " << isbn << ", Title: " << title << ", Author: " << author << "Genre :" << genre << ", Base price: " << base_price << ", State: " << state << ",  Format: " << format << std::endl;
}
std::ostream &operator<<(std::ostream &os, const Ebook &mag)
{
    os << "ISBN identificator: " << mag.isbn << "Title: " << mag.title << ", Author: " << mag.author << "Genre :" << mag.genre << ", Base price: " << mag.base_price << ", State: " << mag.state << ", Format: " << mag.format << std::endl;
    return os;
}

double Ebook::calculate_price() const
{
    return 0.75 * base_price;
}
