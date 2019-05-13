#ifndef __IO_HPP__
#define __IO_HPP__
#include <vector>
#include <string>
class IO
{
private:


public:
    IO();
    ~IO();

    std::vector<std::string> read_file(std::string filepath);
    std::vector<std::string> remove_comments(std::vector<std::string> data);
    std::vector<std::string> split_string(std::string line, char delimiter);
    void write_file();


};
#endif//__IO_HPP__
