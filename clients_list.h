#ifndef CLIENTS_LIST
#define CLIENTS_LIST
#include "client.h"
#include <list>
#include <memory>

class ClientsList
{
    private:
        std::list<std::unique_ptr<Client>> clients;
    public:
        void add_client(unsigned int id, std::string name, std::string surname, Purpose purpose);
        Client find_client_by_id(unsigned int id) const;
};

#endif
