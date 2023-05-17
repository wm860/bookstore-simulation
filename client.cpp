#include "client.h"

Client::Client(){}

Client::Client(unsigned int id, std::string name, std::string surname, Purpose purpose) :
id(id), name(name), surname(surname), purpose(purpose)
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

bool Client::operator==(const Client& second_client) const
{
    if(id == second_client.get_id())
    {
        return true;
    }
    return false;
}
