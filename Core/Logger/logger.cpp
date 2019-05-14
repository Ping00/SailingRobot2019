#include "logger.hpp"
#include <string>
Logger::Logger(std::string path)
{
    m_entries = 0;
    m_file_path = path;
}

void Logger::log_data(LOG packet)
{

}

void Logger::publish()
{

}