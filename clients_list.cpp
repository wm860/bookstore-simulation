#include "clients_list.h"
#include "client_not_found_exception.h"
#include "already_existing_client_exception.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <random>

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

void ClientsList::add_client_as_ptr(std::shared_ptr<Client> client)
{
    clients.push_back(std::move(client));
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
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(0, 2);
        unsigned int id = i + 1;
        std::string name = "Name" + std::to_string(id);
        std::string surname = "Surname" + std::to_string(id);
        Purpose purpose = Purpose(dist(gen));
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

unsigned int ClientsList::get_size() const noexcept
{
    return clients.size();
}

void ClientsList::delete_client(unsigned int id)
{
    bool exist = false;
    for (const auto &clinet_ptr : clients)
    {
        if (id == clinet_ptr->get_id())
        {
            exist = true;
            clients.remove(std::move(clinet_ptr));
            break;
        }
    }
    if (exist == false)
    {
        throw ClientNotFoundException(id);
    }
}

ClientsList ClientsList::pass_client_to_queue(ClientsList list_of_clients, unsigned int amount, SellersList list_of_sellers)
{
    unsigned int i = 1;
    for (const auto &client_ptr : list_of_clients.get_clients())
    {
        if (i > amount)
        {
            break;
        }
        unsigned int new_id = client_ptr->get_id();
        std::string new_name = client_ptr->get_name();
        std::string new_surname = client_ptr->get_surname();
        Purpose new_purpose = client_ptr->get_purpose();
        Client new_client(new_id, new_name, new_surname, new_purpose);
        unsigned int book_id = client_ptr->get_book_id();
        new_client.set_id_of_book(book_id);
        new_client.set_seller(i);
        if (new_purpose == Purpose::ask)
        {
            new_client.set_state(State::servicing3);
        }
        else if (new_purpose == Purpose::order)
        {
            new_client.set_state(State::servicing2);
        }
        else if (new_purpose == Purpose::buy)
        {
            new_client.set_state(State::servicing1);
        }
        this->add_client(new_client);
        list_of_clients.delete_client(new_id);
        i++;
    }
    i = 1;
    for (auto &seller_ptr : list_of_sellers.get_sellers())
    {
        if (i > amount)
        {
            break;
        }
        seller_ptr->set_accessibility(Accessibility::inaccessible);
        i++;
    }
    return list_of_clients;
}
void ClientsList::print_list_to_file(std::ofstream f) noexcept
{
    f << "\nClients list:\n";
    for (const auto &client_ptr : clients)
    {
        f << "Client ID: " << client_ptr->get_id() << "\n";
        f << "Name:" << client_ptr->get_name() << "\n";
        f << "Surname:" << client_ptr->get_surname() << "\n";
        f << "State:" << enumToString(client_ptr->get_state()) << "\n";
        f << "Purpose: " << enumToString(client_ptr->get_purpose())
          << "\n\n";
    }
}
