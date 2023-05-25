#include <iostream>
#include <sstream>
#include <fstream> //write to file
#include <chrono>
#include <list>
#include <thread>
#include <vector>
#include "file_operation.h"
#include "simulation.h"
#include "magazine.h"

#include "clients_list.h"

int main(int argc, char *argv[])
{
    std::cout << "WELCOME TO OUR PROGRAM\n";

    if (argc != 5) // arguments when program is called in terminal
    {
        std::cerr
            << "Incorrect number of command line arguments - expected 4, got "
            << argc << std::endl;
        return 1;
    }
    std::string time_max = "10";
    std::string number_of_sellers = "1";
    std::string number_of_clients = "1";
    std::string name_of_book_list = "books.txt";
    std::vector<std::string> parameters;
    std::stringstream stream;
    stream << argv[1];
    stream >> time_max;
    parameters.push_back(time_max);
    stream.clear();
    stream << argv[2];
    stream >> number_of_sellers;
    parameters.push_back(number_of_sellers);
    stream.clear();
    stream << argv[3];
    stream >> number_of_clients;
    parameters.push_back(number_of_clients);
    stream.clear();
    stream << argv[4];
    stream >> name_of_book_list;
    parameters.push_back(name_of_book_list);
    stream.clear();

    Simulation S;
    S.do_simulation(parameters);
    return 0;
}
