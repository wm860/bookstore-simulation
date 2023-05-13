#include <iostream>
#include <sstream>
#include <fstream> //write to file
#include <chrono>
#include <list>
#include <thread>
#include <vector>
#include "file_operation.h"

int main(int argc, char *argv[])
{
    std::cout << "hello\n";

    if (argc != 2) // arguments when program is called in terminal
    {
        std::cerr
            << "Incorrect number of command line arguments - expected 2, got "
            << argc << std::endl;
        return 1;
    }

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
    return 0;
}
