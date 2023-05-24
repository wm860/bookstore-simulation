#include "client.h"
#include <iostream>
Client::Client() {}

Client::Client(unsigned int id, std::string name, std::string surname, Purpose purpose) : id(id), name(name), surname(surname), purpose(purpose)
{
    state = State::waiting;
}

unsigned int Client::get_id() const noexcept
{
    return id;
}

std::string Client::get_name() const noexcept
{
    return name;
}

std::string Client::get_surname() const noexcept
{
    return surname;
}

State Client::get_state() const noexcept
{
    return state;
}

Purpose Client::get_purpose() const noexcept
{
    return purpose;
}

unsigned int Client::get_seller_id() const noexcept
{
    return id_of_servicing_seller;
}

unsigned int Client::get_book_id() const noexcept
{
    return id_of_book;
}

std::string Client::get_activity() const noexcept
{
    return enumToString(purpose);
}

void Client::set_name(std::string new_name) noexcept
{
    name = new_name;
}

void Client::set_surname(std::string new_surname) noexcept
{
    surname = new_surname;
}

void Client::set_state(State new_state) noexcept
{
    state = new_state;
}

void Client::set_purpose(Purpose new_purpose) noexcept
{
    purpose = new_purpose;
}

void Client::set_seller(unsigned int new_seller_id) noexcept
{
    id_of_servicing_seller = new_seller_id;
}

void Client::set_id_of_book(unsigned int new_book_id) noexcept
{
    id_of_book = new_book_id;
}

bool Client::operator==(const Client &second_client) const
{
    if (id == second_client.get_id())
    {
        return true;
    }
    return false;
}
void Client::set_actual_state() noexcept
{
    if (int(get_state()) < 4)
    {
        State state = get_state();
        int new_state = int(state);
        new_state++;
        set_state(State(new_state));
    }
}
