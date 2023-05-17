#ifndef CLIENT_H
#define CLIENT_H
#include <string>

enum class State
{
    serviced,
    waiting
};

enum class Purpose
{
    buy,
    ask,
    order
};

class Client
{
    private:
        unsigned int id;
        std::string name;
        std::string surname;
        State state;
        Purpose purpose;
    public:
        Client(unsigned int id, std::string name, std::string surname, Purpose purpose);
        Client();

        // getters
        unsigned int get_id() const noexcept;
        std::string get_name() const noexcept;
        std::string get_surname() const noexcept;
        State get_state() const noexcept;
        Purpose get_purpose() const noexcept;

        //setters
        void set_name(std::string new_name) noexcept;
        void set_surname(std::string new_surname) noexcept;
        void set_state(State new_state);
        void set_purpose(Purpose new_purpose);

        void ask();
        void buy();
        void order();
};

#endif
