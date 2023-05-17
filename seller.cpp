#include "seller.h"

Seller::Seller(){}

Seller::Seller(unsigned int id, std::string name, std::string surname, Accessibility accessibility) : 
id(id), name(name), surname(surname), accessibility(accessibility)
{}

unsigned int Seller::get_id() const
{
    return id;
}

std::string Seller::get_name() const
{
    return name;
}

std::string Seller::get_surname() const
{
    return surname;
}

Accessibility Seller::get_accessibility() const
{
    return accessibility;
}

void Seller::set_name(std::string new_name)
{
    name = new_name;
}

void Seller::set_surname(std::string new_surname)
{
    surname = new_surname;
}

void Seller::set_accessibility(Accessibility new_accessibility)
{
    accessibility = new_accessibility;
}
