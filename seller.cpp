#include "seller.h"
#include <iostream>

Seller::Seller(){}

Seller::Seller(unsigned int id, std::string name, std::string surname, Accessibility accessibility) :
id(id), name(name), surname(surname), accessibility(accessibility)
{}

unsigned int Seller::get_id() const noexcept
{
    return id;
}

std::string Seller::get_name() const noexcept
{
    return name;
}

std::string Seller::get_surname() const noexcept
{
    return surname;
}

Accessibility Seller::get_accessibility() const noexcept
{
    return accessibility;
}

void Seller::set_name(std::string new_name) noexcept
{
    name = new_name;
}

void Seller::set_surname(std::string new_surname) noexcept
{
    surname = new_surname;
}

void Seller::set_accessibility(Accessibility new_accessibility) noexcept
{
    accessibility = new_accessibility;
}

bool Seller::operator==(const Seller& second_seller) const
{
    if(id == second_seller.get_id())
    {
        return true;
    }
    return false;
}

void Seller::answer_question(Book book)
{
    std::cout << "Seller no " << id  << " answers: " <<
    book.get_author() << " '" << book.get_title() <<"' costs " << book.get_base_price() << " zl\n\n";
    set_accessibility(Accessibility::accessible);
}

void Seller::bill_presentation(Book book, Purpose purpose)
{
    if(purpose == Purpose::buy)
    {
        std::cout << "Seller no " << id << " present the bill for buying " << book.get_author() << ": " << book.get_title() <<
        "sum " << book.get_base_price() << " zl\n\n";
    }
    else
    {
        std::cout << "Seller no " << id << " present the bill for oredering " << book.get_author() << ": " << book.get_title() <<
        "sum " << book.get_base_price() << " zl\n\n";
    }
    set_accessibility(Accessibility::accessible);
}
