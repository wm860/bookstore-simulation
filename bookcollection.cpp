#include "bookcollection.h"
#include "book.h"
#include "magazine.h"
#include "ebook.h"
#include "book_not_found_exception.h"
#include <iostream>

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
    // books.push_back(std::move(added_fiction));
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
    // books.push_back(std::move(added_bio));
    if (!check_book_by_isbn(b.get_isbn()))
        books.push_back(std::move(added_ebook));
    else
        std::cout << "You wanted add book, which is already on the shell - type bio\n";
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