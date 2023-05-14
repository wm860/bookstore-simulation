#include "magazine.h"
#include <iostream>

Magazine::Magazine(std::string new_author, std::string new_title, uint new_isbn, std::string new_genre, double new_price, std::string new_state, uint month, std::string year) : Book(author, title, isbn, genre, base_price, state), month(month), year(year) {}

std::string Magazine::get_year()
{
    return year;
}
uint Magazine::get_month()
{
    return month;
}

void Magazine::set_month(uint m)
{
    month = m;
}
void Magazine::set_year(std::string m)
{
    year = m;
}

void Magazine::print() const
{
    std::cout << "ISBN identificator: " << isbn << ", Title: " << title << ", Author: " << author << "Genre :" << genre << ", Base price: " << base_price << ", State: " << state << ", Month: " << month << ",  Year: " << year << std::endl;
}
std::ostream &operator<<(std::ostream &os, const Magazine &mag)
{
    os << "ISBN identificator: " << mag.isbn << ", Title: " << mag.title << ", Author: " << mag.author << "Genre :" << mag.genre << ", Base price: " << mag.base_price << ", State: " << mag.state << ", Month: " << mag.month << ",  Year: " << mag.year << std::endl;
    return os;
}

double Magazine::calculate_price() const
{
    return 1.2 * base_price;
}
