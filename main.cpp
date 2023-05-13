#include <iostream>
#include <sstream>
#include <fstream> //write to file
#include <chrono>
#include <list>
#include <thread>
#include <vector>
#include "file_operation.h"
#include "simulation.h"

int main(int argc, char *argv[])
{
    std::cout << "hello\n";

    if (argc != 5) // arguments when program is called in terminal
    {
        std::cerr
            << "Incorrect number of command line arguments - expected 5, got "
            << argc << std::endl;
        return 1;
    }
    std::string time_max = "10";
    std::string number_of_sellers = "1";
    std::string number_of_clients = "1";
    std::string number_of_books = "5";
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
    stream >> number_of_books;
    parameters.push_back(number_of_books);
    stream.clear();

    Simulation S;
    S.do_simulation(parameters);

    // small change
    /*
        unsigned short int time_max = 10;

        std::stringstream stream;
        stream << argv[1];
        stream >> time_max;
        stream.clear();
        std::cout << argv[1] << std::endl;

        File_operation file_in("simulation_start.txt"); // read from file_in
        std::vector<std::string> start_table = file_in.open_file("simulation_start.txt");
        time_max = std::stoi(start_table[0]);
        // std::cout << "time max \t" << time_max << std::endl;

        std::ofstream file; // write to file
        file.open("simulation_results.txt", std::ios::out);
        file << "Simulation results: " << std::endl;

        int time = 0;
        while (time < time_max) // simulation loop
        {

            std::cout << "TIME[s]: " << time << std::endl; // print in terminal simulation results
            file << time << std::endl;                     // save to file simulation result
            std::this_thread::sleep_for(std::chrono::seconds(1));
            time++;
        }
        file.close();
    */
    return 0;
}
