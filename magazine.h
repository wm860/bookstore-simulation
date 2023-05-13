#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "book.h"

class Magazine : public Book
{
private:
    uint month;
    std::string year;

public:
    Magazine(std::string new_author, std::string new_title, uint new_isbn, std::string new_genre, double new_price, std::string new_state, uint month, std::string year);

    uint get_month();
    std::string get_year();

    void set_month(uint ge);
    void set_year(std::string ge);

    void print() const;

    friend std::ostream &operator<<(std::ostream &os, const Magazine &mag);

    double calculate_price() const override;
};

std::ostream &operator<<(std::ostream &os, const Magazine &mag);

#endif