#include "file_operation.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

File_operation::File_operation(std::string filename) {}
std::vector<std::string> File_operation::open_file(std::string filename)
{
    std::ifstream f;
    f.open(filename);
    std::vector<std::string> row;
    std::string line;
    if (f.is_open())
    {
        while (getline(f, line))
        {
            row.push_back(line);
        }
    }
    else
    {
        std::cout << "can't open given file";
    }
    f.close();
    for (auto &element : row)
    {
        std::cout << element << std::endl;
    }
    return row;
}
