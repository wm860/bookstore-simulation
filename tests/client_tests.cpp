#include "catch_amalgamated.hpp"
#include "../client.h"

TEST_CASE("client simple tests", "[client]")
{
    Client client(7, "Jacek", "Placek", Purpose::ask);

    CHECK(client.get_id() == 7);
    CHECK(client.get_name() == "Jacek");
    CHECK(client.get_surname() == "Placek");
    CHECK(client.get_state() == State::waiting);
    CHECK(client.get_purpose() == Purpose::ask);

    SECTION("modification of name")
    {
        client.set_name("Juzio");
        CHECK(client.get_name() == "Juzio");
    }

    SECTION("modification of surname")
    {
        client.set_surname("Dyzio");
        CHECK(client.get_surname() == "Dyzio");
    }

    SECTION("modification of state")
    {
        client.set_state(State::serviced);
        CHECK(client.get_state() == State::serviced);
    }

    SECTION("modification of purpose")
    {
        client.set_purpose(Purpose::buy);
        CHECK(client.get_purpose() == Purpose::buy);
    }
}
