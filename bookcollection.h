#ifndef BOOKCOLLECTION_H
#define BOOKCOLLECTION_H
#include "book.h"
#include "ebook.h"
#include "magazine.h"
#include <list>   //needed to use std::list
#include <memory> //needed to use std::unique_pointer

class Bookcollection
{
private:
    std::list<std::unique_ptr<Book>> books;

public:
    void add_book(std::string author, std::string title, uint isbn, std::string genre, double price, std::string state);
    void add_book(Book b);
    // void delete_book(Book b);
    void delete_book2(Book &b);
    void add_magazine(std::string new_author, std::string new_title, uint new_isbn, std::string new_genre, double new_price, std::string new_state, uint month, std::string year);
    void add_magazine(Magazine m);
    void add_ebook(std::string new_author, std::string new_title, uint new_isbn, std::string new_genre, double new_price, std::string new_state, std::string format);
    void add_ebook(Ebook e);

    void make_list_from_file(std::vector<std::vector<std::string>> M);
    void change_availability(uint isbn, uint action);
    std::string print_title(uint isbn);

    double calculate_total_price() const noexcept;
    void print_list() const noexcept;
    Book find_book_by_isbn(uint isbn) const;
    bool check_book_by_isbn(uint isbn);
    int size();

    std::string get_state(uint isbn);
    double calculate_book_price(uint isbn) const noexcept;
    void print_list_to_file(std::ostream *f) noexcept;
};

#endif