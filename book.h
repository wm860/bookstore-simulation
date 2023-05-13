#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <vector>

class Book
{
protected:
    std::string author;
    std::string title;
    uint isbn; // this number will be identificator and for this project isbn number will be shorten and simplified
    std::string genre;
    double base_price;
    std::string state; // whether book is available to buy or not

public:
    Book(std::string new_author, std::string new_title, uint new_isbn, std::string new_genre, double new_price, std::string new_state);

    virtual void print() const;
    friend std::ostream &operator<<(std::ostream &os, const Book &boo);

    virtual double calculate_price() const;

    virtual ~Book();

    bool operator==(const Book &b) const;

    // getters
    std::string get_author() const;
    std::string get_title() const;
    uint get_isbn() const;
    std::string get_genre();
    double get_base_price() const;
    std::string get_state();

    // setters
    void set_author(std::string a);
    void set_title(std::string t);
    void set_isbn(uint i);
    void set_genre(std::string t);
    void set_base_price(double b);
    void set_state(std::string s);
};

std::ostream &operator<<(std::ostream &os, const Book &boo);

#endif
