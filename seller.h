#ifndef SELLER_H
#define SEELER_H
#include <string>
#include "client.h"
#include "book.h"

enum class Accessibility
{
    accessible,
    inaccessible
};

class Seller
{
    private:
        unsigned int id;
        std::string name;
        std::string surname;
        Accessibility accessibility;
        unsigned int serviced_client_id = 0;
    public:
        Seller(unsigned int id, std::string name, std::string surname, Accessibility Accessibility);
        Seller();

        //getters
        unsigned int get_id() const noexcept;
        std::string get_name()const noexcept;
        std::string get_surname() const noexcept;
        Accessibility get_accessibility() const noexcept;
        unsigned int get_serviced__client_id() const;

        //setters
        void set_accessibility(Accessibility new_accessibility) noexcept;
        void set_name(std::string new_name) noexcept;
        void set_surname(std::string new_surname) noexcept;

        bool operator==(const Seller& second_seller) const;
        void answer_question(Book book);
        void bill_presentation(Book book, Purpose purpose);
};


#endif
