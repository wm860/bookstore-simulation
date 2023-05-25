#ifndef CLIENTS_LIST
#define CLIENTS_LIST
#include "client.h"
#include "sellers_list.h"
#include <list>
#include <memory>
#include <string>

class ClientsList
{
private:
    std::list<std::shared_ptr<Client>> clients;

public:
    void add_client(Client);
    void add_client_as_ptr(std::shared_ptr<Client> client);
    std::list<std::shared_ptr<Client>> get_clients();
    Client find_client_by_id(unsigned int id) const;
    void make_list(int number_of_clients);
    void print_list() noexcept;
    void print_list_to_file(std::ofstream f) noexcept;
    unsigned int return_first_client() noexcept;
    void delete_client(unsigned int id);
    ClientsList pass_client_to_queue(ClientsList first, unsigned int amount, SellersList list_of_sellers);

    void set_actual_state_list(unsigned int id);
    void simulation_step(unsigned int id, std::string availability);
    std::string activity(unsigned int id);
    std::string get_state(unsigned int id);
    unsigned int get_size() const noexcept;
};

#endif
