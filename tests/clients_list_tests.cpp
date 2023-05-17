#include "catch_amalgamated.hpp"
#include "../clients_list.h"
#include "../client_not_found_exception.h"
#include "../already_existing_client_exception.h"

TEST_CASE("clients list simple tests", "[clients_list]")
{
    ClientsList clients_list;

    SECTION("add client")
    {
        Client client(7, "Jacek", "Placek", Purpose::ask);
        clients_list.add_client(client);
        CHECK(clients_list.find_client_by_id(7) == client);
    }

    SECTION("invalid find no client with that id")
    {
        REQUIRE_THROWS_AS(clients_list.find_client_by_id(7), ClientNotFoundException);
    }

    SECTION("invalid add already is client with that id")
    {
        Client client(7, "Jacek", "Placek", Purpose::ask);
        clients_list.add_client(client);
        REQUIRE_THROWS_AS(clients_list.add_client(client), AlreadyExistingClientException);
    }
}
