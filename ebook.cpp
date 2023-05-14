#include "ebook.h"
#include <iostream>

Ebook::Ebook(std::string author, std::string title, uint isbn, std::string genre, double price, std::string state, std::string format) : Book(author, title, isbn, genre, price, state), format(format) {}

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
