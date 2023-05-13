#pragma once
#include <string>
#include <vector>
#include <fstream>

class Simulation
{
public:
    Simulation();
    void do_simulation(std::vector<std::string> input_parameters);
};