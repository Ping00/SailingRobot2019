#include <iostream>
#include "../Core/IO/IO.hpp"
#include <vector>

int main(void)
{
    std::cout << "Beginning Logger Test" << std::endl;

    IO io;

    io.write_file("THIS IS JUST A TEST");

    return 0;
}
