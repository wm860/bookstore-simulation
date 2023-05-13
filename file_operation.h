#pragma once
#include <string>
#include <vector>
#include <fstream>

class File_operation
{
private:
  std::string filename;

public:
  File_operation(std::string filename);
  std::vector<std::string> open_file(std::string filename);
  std::vector<std::string> open_book_file(std::string filename);
};
