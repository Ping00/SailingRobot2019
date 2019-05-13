#include <iostream>
#include "../Core/IO/IO.hpp"
#include <vector>

int main(void)
{
    std::cout << "Beginning Logger Test" << std::endl;

    IO io;

    std::vector<std::string> testing = io.read_file("test.txt");

    std::cout << "SIZE OF FILE (NO COMMENTS (1)) : " << testing.size() << std::endl;

    std::vector<std::string> split = io.split_string(testing[0], ',');

    std::cout << "SIZE OF FILE (SPLIT (2)) : " << split.size() << std::endl;


    return 0;
}
