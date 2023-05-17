#include "clients_list.h"
#include "client_not_found_exception.h"
#include "already_existing_client_exception.h"

void ClientsList::add_client(unsigned int id, std::string name, std::string surname, Purpose purpose)
{
    for(const auto& client_ptr : clients)
    {
        if(client_ptr -> get_id() == id)
        {
            throw AlreadyExistingClientException(id);
        }
    }
    std::unique_ptr<Client> added_client = std::make_unique<Client>(id, name, surname, purpose);
    clients.push_back(std::move(added_client));
}

Client ClientsList::find_client_by_id(unsigned int id) const
{
    for(const auto& client_ptr : clients)
    {
        if(client_ptr -> get_id() == id)
        {
            return *client_ptr;
        }
    }
    throw ClientNotFoundException(id);
}
