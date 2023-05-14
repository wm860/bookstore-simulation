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
std::vector<std::vector<std::string>> File_operation::open_book_file(std::string filename)
{
    std::ifstream f;
    f.open(filename);
    std::vector<std::vector<std::string>> content;
    std::vector<std::string> row;
    std::string line, word;
    if (f.is_open())
    {
        while (getline(f, line))
        {
            row.clear();
            std::stringstream str(line);
            while (std::getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else
    {
        std::cout << "can't open given file";
        exit(0);
    }
    f.close();
    return content;
}

void File_operation::check_book_file(std::vector<std::vector<std::string>> M) // checking matrix of data to makes proper objects from file
{
    for (int i = 0; i < int(M.size()); i++)
    {
        if (M[i].size() < 5)
        {
            std::cout << "given wrong data file/wrong number of columns in programs\n";
            exit(0);
        }
    }
}
void File_operation::print_book_file(std::vector<std::vector<std::string>> M) // checking matrix of data to makes proper objects from file
{
    for (int j = 0; j < (int)M.size(); ++j)
    {
        for (int i = 0; i < (int)M[j].size(); ++i)
        {
            std::cout << M[j][i] << "\t";
        }
        std::cout << "\n";
    }
}