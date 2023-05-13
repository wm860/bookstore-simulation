#include "simulation.h"
#include "file_operation.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <chrono>
#include <list>
#include <thread>
#include <vector>

Simulation::Simulation() {}

void Simulation::do_simulation(std::vector<std::string> parameters)
{
    /*
    File_operation file_in("simulation_start.txt"); // read from file_in
    std::vector<std::string> start_table = file_in.open_file("simulation_start.txt");
    int time_max = std::stoi(start_table[0]);
    // std::cout << "time max \t" << time_max << std::endl;
    */

    std::ofstream file; // write to file
    file.open("simulation_results.txt", std::ios::out);
    file << "Simulation results: " << std::endl;

    int time = 0;
    int time_max = std::stoi(parameters[0]);
    while (time < time_max) // simulation loop
    {

        std::cout << "TIME[s]: " << time << std::endl; // print in terminal simulation results
        file << time << std::endl;                     // save to file simulation result
        std::this_thread::sleep_for(std::chrono::seconds(1));
        time++;
    }
    file.close();
}