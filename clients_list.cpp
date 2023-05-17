#include "clients_list.h"
#include "client_not_found_exception.h"
#include "already_existing_client_exception.h"

void ClientsList::add_client(Client client)
{
    for(const auto& client_ptr : clients)
    {
        if(client_ptr -> get_id() == client.get_id())
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
    for(const auto& client_ptr : clients)
    {
        if(client_ptr -> get_id() == id)
        {
            return *client_ptr;
        }
    }
    throw ClientNotFoundException(id);
}
