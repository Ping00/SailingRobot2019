#include "IO.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
IO::IO()
{

}

IO::~IO()
{

}

std::vector<std::string> IO::read_file(std::string file)
{
    std::vector<std::string> file_data;

    std::ifstream instream(file);
    if(instream.fail())
    {
        std::cout << "Failed to open file: " << file << std::endl;
        return std::vector<std::string>();
    }

    std::cout << "Opened File: " << file << std::endl;

    std::string text_line;
    while (std::getline(instream, text_line))
    {
        file_data.push_back(text_line);
    }

    std::vector<std::string> cleaned = remove_comments(file_data);

    return cleaned;
}

void IO::write_file()
{

}

std::vector<std::string> IO::remove_comments(std::vector<std::string> data)
{
    int iterations = data.size();
    std::vector<std::string> parsed_data;


    for(int i = 0; i < iterations; i++)
    {
        if(data[i][0] != '#')
        {
            parsed_data.push_back(data[i]);
        }
    }

    return parsed_data;
}

std::vector<std::string> IO::split_string(std::string line, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(line);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

