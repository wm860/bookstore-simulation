#ifndef CLIENTS_LIST
#define CLIENTS_LIST
#include "client.h"
#include <list>
#include <memory>

class ClientsList
{
    private:
        std::list<std::shared_ptr<Client>> clients;
    public:
        void add_client(Client);
        std::list<std::shared_ptr<Client>> get_clients();
        Client find_client_by_id(unsigned int id) const;
};

#endif
