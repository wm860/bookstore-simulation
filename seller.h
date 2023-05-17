#ifndef SELLER_H
#define SEELER_H
#include <string>

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
    public:
        Seller(unsigned int id, std::string name, std::string surname, Accessibility Accessibility);
        Seller();

        //getters
        unsigned int get_id() const noexcept;
        std::string get_name()const noexcept;
        std::string get_surname() const noexcept;
        Accessibility get_accessibility() const noexcept;

        //setters
        void set_accessibility(Accessibility new_accessibility) noexcept;
        void set_name(std::string new_name) noexcept;
        void set_surname(std::string new_surname) noexcept;

        bool operator==(const Seller& second_seller) const;
        void answer_question();
        void bill_presentation();
};


#endif
