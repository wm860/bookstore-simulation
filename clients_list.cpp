#include "clients_list.h"
#include "client_not_found_exception.h"
#include "already_existing_client_exception.h"
#include <iostream>
#include <string>
#include <map>

std::string enumToString(Purpose purpose)
{
    static const std::map<Purpose, std::string> enumStrings{
        {Purpose::ask, "ask"},
        {Purpose::buy, "buy"},
        {Purpose::order, "order"}};
    auto it = enumStrings.find(purpose);
    if (it != enumStrings.end())
    {
        return it->second;
    }
    return "Unknown";
}
std::string enumToString(State state)
{
    static const std::map<State, std::string> enumStrings{
        {State::waiting, "waiting"},
        {State::servicing1, "servicing1"},
        {State::servicing2, "servicing2"},
        {State::servicing3, "servicing3"},
        {State::serviced, "serviced"}};
    auto it = enumStrings.find(state);
    if (it != enumStrings.end())
    {
        return it->second;
    }

    return "Unknown";
}

void ClientsList::add_client(Client client)
{
    for (const auto &client_ptr : clients)
    {
        if (client_ptr->get_id() == client.get_id())
        {
            throw AlreadyExistingClientException(client.get_id());
        }
    }
    std::shared_ptr<Client> added_client = std::make_shared<Client>(client);
    clients.push_back(std::move(added_client));
}

std::list<std::shared_ptr<Client>> ClientsList::get_clients()
{
    return clients;
}

Client ClientsList::find_client_by_id(unsigned int id) const
{
    for (const auto &client_ptr : clients)
    {
        if (client_ptr->get_id() == id)
        {
            return *client_ptr;
        }
    }
    throw ClientNotFoundException(id);
}

void ClientsList::make_list(int n)
{
    for (int i = 0; i < n; i++)
    {
        unsigned int id = i + 1;
        std::string name = "Name" + std::to_string(id);
        std::string surname = "Surname" + std::to_string(id);
        Purpose purpose = Purpose(std::rand() % 3);
        Client client(id, name, surname, purpose);
        add_client(client);
    }
}
void ClientsList::print_list() noexcept
{
    std::cout << "\nClients list:\n";
    for (const auto &client_ptr : clients)
    {
        std::cout << "Client ID: " << client_ptr->get_id() << std::endl;
        // std::cout << "Name:" << client_ptr->get_name() << std::endl;
        // std::cout << "Surname:" << client_ptr->get_surname() << std::endl;
        std::cout << "State:" << enumToString(client_ptr->get_state()) << std::endl;
        std::cout << "Purpose: " << enumToString(client_ptr->get_purpose())
                  // static_cast<int>(client_ptr->get_purpose()))
                  << std::endl
                  << std::endl;
    }
}
unsigned int ClientsList::return_first_client() noexcept
{
    for (const auto &client_ptr : clients)
    {
        if (enumToString(client_ptr->get_state()) != "serviced")
        {
            // std::cout << "state : " << enumToString(client_ptr->get_state()) << " ";
            return client_ptr->get_id();
        }
        /*if (client_ptr->get_state() == State::serviced)
        {
            std::cout << "state : " << enumToString(client_ptr->get_state());
            return (client_ptr->get_id()) + 1;
        }*/
    }
    return 33;
}

Client ClientsList::find_client_by_id(unsigned int id)
{
    for (const auto &client_ptr : clients)
    {
        if (client_ptr->get_id() == id)
        {
            return *client_ptr;
        }
    }
    throw ClientNotFoundException(id);
}

void ClientsList::set_actual_state_list(unsigned int id)
{
    for (const auto &client_ptr : clients)
    {
        if (enumToString(client_ptr->get_state()) != "serviced")
        {
            if (client_ptr->get_id() == id)
            {
                client_ptr->set_actual_state();
            }
        }
    }
}
void ClientsList::simulation_step(unsigned int id, std::string availability)
{
    for (const auto &client_ptr : clients)
    {
        if (client_ptr->get_id() == id)
        {
            if (client_ptr->get_purpose() == Purpose::ask)
            {
                if (client_ptr->get_state() < State(3))
                    client_ptr->set_state(State(3));
                else
                    client_ptr->set_actual_state();
            }
            else if (client_ptr->get_purpose() == Purpose::buy)
            {
                if (client_ptr->get_state() < State(2))
                    client_ptr->set_state(State(2));
                else
                    client_ptr->set_actual_state();
            }
            else if (client_ptr->get_purpose() == Purpose::order)
            {
                client_ptr->set_actual_state();
            }

            if (availability == "unavailable")
            {
                std::cout << "o";
                // client_ptr->set_state(State(4));
            }
        }
    }
}
std::string ClientsList::activity(unsigned int id)
{
    for (const auto &client_ptr : clients)
    {
        if (client_ptr->get_id() == id)
        {
            return enumToString(client_ptr->get_purpose());
        }
    }
    return "error in activity";
}
std::string ClientsList::get_state(unsigned int id)
{
    for (const auto &client_ptr : clients)
    {
        if (client_ptr->get_id() == id)
        {
            return enumToString(client_ptr->get_state());
        }
    }
    return "error in state";
}