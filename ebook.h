#ifndef EBOOK_H
#define EBOOK_H

#include "book.h"

class Ebook : public Book
{
private:
    std::string format;

public:
    Ebook(std::string new_author, std::string new_title, uint new_isbn, std::string new_genre, double new_price, std::string new_state, std::string format);

    std::string get_format();

    void set_format(std::string ge);

    void print() const;

    friend std::ostream &operator<<(std::ostream &os, const Ebook &ebook);

    double calculate_price() const override;
};

std::ostream &operator<<(std::ostream &os, const Ebook &ebook);

#endif