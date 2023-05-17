#include "client.h"

Client::Client(){}

Client::Client(unsigned int id, std::string name, std::string surname, Purpose purpose) :
id(id), name(name), surname(surname), purpose(purpose)
{
    state = State::waiting;
}

unsigned int Client::get_id() const
{
    return id;
}

std::string Client::get_name() const
{
    return name;
}

std::string Client::get_surname() const
{
    return surname;
}

State Client::get_state() const
{
    return state;
}

Purpose Client::get_purpose() const
{
    return purpose;
}

void Client::set_name(std::string new_name)
{
    name = new_name;
}

void Client::set_surname(std::string new_surname)
{
    surname = new_surname;
}

void Client::set_state(State new_state)
{
    state = new_state;
}

void Client::set_purpose(Purpose new_purpose)
{
    purpose = new_purpose;
}
