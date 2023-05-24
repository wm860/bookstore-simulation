#ifndef CLIENT_H
#define CLIENT_H
#include <string>

enum class State
{
    waiting,
    servicing1,
    servicing2,
    servicing3,
    serviced
};

enum class Purpose
{
    ask,
    buy,
    order
};
std::string enumToString(Purpose purpose);
std::string enumToString(State state);
class Client
{
private:
    unsigned int id;
    std::string name;
    std::string surname;
    State state;
    Purpose purpose;
    unsigned int id_of_servicing_seller = 0;
    unsigned int id_of_book = 0;
public:
    Client(unsigned int id, std::string name, std::string surname, Purpose purpose);
    Client();

    // getters
    unsigned int get_id() const noexcept;
    std::string get_name() const noexcept;
    std::string get_surname() const noexcept;
    State get_state() const noexcept;
    Purpose get_purpose() const noexcept;
    unsigned int get_seller_id() const noexcept;
    unsigned int get_book_id() const noexcept;
    std::string get_activity() const noexcept;

    // setters
    void set_name(std::string new_name) noexcept;
    void set_surname(std::string new_surname) noexcept;
    void set_state(State new_state) noexcept;
    void set_purpose(Purpose new_purpose) noexcept;
    void set_seller(unsigned int new_id) noexcept;
    void set_id_of_book(unsigned int new_id) noexcept;

    bool operator==(const Client &second_client) const;
    bool ask(unsigned int book_id) const;
    void buy(unsigned int book_id);
    void order(unsigned int book_id);

    void set_actual_state() noexcept;
};

#endif
