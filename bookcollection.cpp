#include "bookcollection.h"
#include "book.h"
#include "magazine.h"
#include "ebook.h"
#include "book_not_found_exception.h"
#include "already_existing_ebook_exception.h"
#include <iostream>
#include <fstream>

bool Bookcollection::check_book_by_isbn(uint isbn)
{
    for (const auto &book_ptr : books)
    {
        if (book_ptr->get_isbn() == isbn)
        {
            return true;
        }
    }
    // throw BookNotFoundException(isbn);
    return false;
}

void Bookcollection::add_book(std::string author, std::string title, uint isbn, std::string genre, double price, std::string state)
{
    /*bool a = check_book_by_isbn(isbn);
    if (a == true)
    {
        throw AlreadyExistingEbookException(isbn);
    }*/
    std::unique_ptr<Book> added_book = std::make_unique<Book>(author, title, isbn, genre, price, state);
    books.push_back(std::move(added_book));
}

void Bookcollection::add_book(Book b)
{
    std::unique_ptr<Book> added_book;
    added_book = std::make_unique<Book>(b.get_author(), b.get_title(), b.get_isbn(), b.get_genre(), b.get_base_price(), b.get_state());
    if (!check_book_by_isbn(b.get_isbn()))
        books.push_back(std::move(added_book));
    else
        std::cout << "You wanted add book, which is already on the shell - type book\n";
}
void Bookcollection::delete_book2(Book &b)
{
    std::list<std::unique_ptr<Book>>::iterator it = books.begin();
    while (it != books.end())
    {
        if (**it == b)
        {
            // Transfer ownership of the pointer to a temporary pointer
            std::unique_ptr<Book> temp = std::move(*it);

            // Remove the pointer from the list
            it = books.erase(it);

            // Delete the temporary pointer
            temp.reset();

            break;
        }
        ++it;
    }
}
void Bookcollection::add_magazine(std::string author, std::string title, uint isbn, std::string genre, double price, std::string state, uint month, std::string year)
{
    std::unique_ptr<Magazine> added_magazine = std::make_unique<Magazine>(author, title, isbn, genre, price, state, month, year);
    books.push_back(std::move(added_magazine));
}
void Bookcollection::add_magazine(Magazine f)
{
    std::unique_ptr<Magazine> added_magazine = std::make_unique<Magazine>(f.get_author(), f.get_title(), f.get_isbn(), f.get_genre(), f.get_base_price(), f.get_state(), f.get_month(), f.get_year());
    if (!check_book_by_isbn(f.get_isbn()))
        books.push_back(std::move(added_magazine));
    else
        std::cout << "You wanted add book, which is already in the list - type magazine\n";
}
void Bookcollection::add_ebook(std::string author, std::string title, uint isbn, std::string genre, double price, std::string state, std::string format)
{
    std::unique_ptr<Ebook> added_ebook = std::make_unique<Ebook>(author, title, isbn, genre, price, state, format);
    books.push_back(std::move(added_ebook));
}
void Bookcollection::add_ebook(Ebook b)
{
    std::unique_ptr<Ebook> added_ebook = std::make_unique<Ebook>(b.get_author(), b.get_title(), b.get_isbn(), b.get_genre(), b.get_base_price(), b.get_state(), b.get_format());
    if (!check_book_by_isbn(b.get_isbn()))
        books.push_back(std::move(added_ebook));
    else
    {
        std::cout << "You wanted add book, which is already on the shell - type ebook\n";
        // throw AlreadyExistingEbookException(b.get_isbn());
    }
}

void Bookcollection::make_list_from_file(std::vector<std::vector<std::string>> M)
{
    for (int i = 0; i < (int)M.size(); ++i)
    {
        if (std::stoi(M[i][0]) == 1) // add_book
        {
            Book b(M[i][1], M[i][2], std::stoi(M[i][3]), M[i][4], std::stod(M[i][5]), M[i][6]);
            add_book(b);
        }
        if (std::stoi(M[i][0]) == 2) // add_magazine
        {
            Magazine mag(M[i][1], M[i][2], std::stoi(M[i][3]), M[i][4], std::stod(M[i][5]), M[i][6], std::stoi(M[i][7]), M[i][8]);
            add_magazine(mag);
        }
        if (std::stoi(M[i][0]) == 3) // add_ebook
        {
            Ebook e(M[i][1], M[i][2], std::stoi(M[i][3]), M[i][4], std::stod(M[i][5]), M[i][6], M[i][7]);
            add_ebook(e);
        }
    }
}
void Bookcollection::change_availability(uint isbn, uint action)
{
    for (auto it = books.begin(); it != books.end(); ++it)
    {
        if ((*it)->get_isbn() == isbn && (*it)->get_state() == "available")
        {
            // std::cout << "tytul wylosowanej ksiazki: " << (*it)->get_title() << "\n";
            if (action == 0)
            {
                (*it)->set_state("asked for");
            }
            if (action == 1)
            {
                (*it)->set_state("ordered");
            }
            if (action == 2)
            {
                (*it)->set_state("bought");
            }
        }
        /*
        if ((*it)->get_isbn() == isbn && (*it)->get_state() == "asked for")
        {
            if (action == 1)
            {
                (*it)->set_state("bought");
            }
        }*/
    }
}
std::string Bookcollection::print_title(uint isbn)
{
    isbn++;
    for (auto it = books.begin(); it != books.end(); ++it)
    {
        if ((*it)->get_isbn() == isbn)
        {
            return (*it)->get_title();
        }
    }
    return "error";
}

double Bookcollection::calculate_total_price() const noexcept
{
    double total_price = 0.0;
    for (const auto &book_ptr : books)
    {
        total_price += book_ptr->calculate_price(); // calculate_price jest metodą wirtualną, więc przy odwołaniu przez wskaźnik wywoła się wersja właściwa dla dynamicznego typu obiektu
    }
    return total_price;
}

void Bookcollection::print_list() const noexcept
{
    for (const auto &book_ptr : books)
    {
        book_ptr->print();
    }
}

Book Bookcollection::find_book_by_isbn(uint isbn) const
{
    for (const auto &book_ptr : books)
    {
        if (book_ptr->get_isbn() == isbn)
        {
            return *book_ptr;
        }
    }
    throw BookNotFoundException(isbn);
}

int Bookcollection::size()
{
    int count = 0;
    for (auto it = books.begin(); it != books.end(); ++it)
    {
        if (*it)
        {
            ++count;
        }
    }
    return count;
}

std::string Bookcollection::get_state(uint isbn)
{
    for (const auto &book_ptr : books)
    {
        if (book_ptr->get_isbn() == isbn)
        {
            return book_ptr->get_state();
        }
    }
    return "error";
}

double Bookcollection::calculate_book_price(uint isbn) const noexcept
{
    for (const auto &book_ptr : books)
    {
        if (book_ptr->get_isbn() == isbn)
        {
            return book_ptr->get_base_price();
        }
    }
    return 0.0;
}
void Bookcollection::print_list_to_file(std::ostream *f) noexcept
{
    for (const auto &book_ptr : books)
    {
        *f << book_ptr->get_state() << "\t" << book_ptr->get_title() << "\n";
    }
}