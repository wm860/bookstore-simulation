#ifndef CLIENTS_LIST
#define CLIENTS_LIST
#include "client.h"
#include <list>
#include <memory>
#include <string>

class ClientsList
{
private:
    std::list<std::shared_ptr<Client>> clients;

public:
    void add_client(Client);
    std::list<std::shared_ptr<Client>> get_clients();
    Client find_client_by_id(unsigned int id) const;
    void make_list(int number_of_clients);
    void print_list() noexcept;
    unsigned int return_first_client() noexcept;
    Client find_client_by_id(unsigned int id);

    void set_actual_state_list(unsigned int id);
    void simulation_step(unsigned int id, std::string availability);
    std::string activity(unsigned int id);
    std::string get_state(unsigned int id);
};

#endif
